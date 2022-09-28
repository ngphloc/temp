package net.rim.adapter.java3d;

import java.awt.AWTEvent;
import java.awt.Event;
import java.awt.event.MouseEvent;
import java.util.Enumeration;

import javax.media.j3d.Behavior;
import javax.media.j3d.Bounds;
import javax.media.j3d.BranchGroup;
import javax.media.j3d.Canvas3D;
import javax.media.j3d.Group;
import javax.media.j3d.Node;
import javax.media.j3d.TransformGroup;
import javax.media.j3d.WakeupCondition;
import javax.media.j3d.WakeupCriterion;
import javax.media.j3d.WakeupOnAWTEvent;
import javax.media.j3d.WakeupOr;

import net.rim.core.PickHolder;

import com.sun.j3d.utils.picking.PickCanvas;
import com.sun.j3d.utils.picking.PickResult;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class PickHolderImpl extends Behavior implements PickHolder {

	protected PickCanvas pickCanvas;

	protected WakeupCondition wakeupCondition = null;
	  
	protected boolean buttonPress = false;

	protected MouseHolderImpl drag = null;

	
	
	/**
	 * 
	 * @param root
	 * @param canvas
	 * @param bounds
	 */
	public PickHolderImpl(BranchGroup root, Canvas3D canvas, Bounds bounds){
		super();
		TransformGroup currGrp = new TransformGroup();
		currGrp.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
		currGrp.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
		root.addChild(currGrp);
		pickCanvas = new PickCanvas(canvas, root);
		
		drag = new MouseHolderImpl();
		currGrp.addChild(drag);
		drag.setSchedulingBounds(bounds);
		this.setSchedulingBounds(bounds);
	}

	
	/**
	 * 
	 * @param root
	 * @param canvas
	 * @param bounds
	 * @param pickMode
	 */
	public PickHolderImpl(BranchGroup root, Canvas3D canvas, Bounds bounds, 
			int pickMode){
		this(root, canvas, bounds);
		this.setMode(pickMode);
	}
	
	
	
	/**
	 * 
	 * @param pickMode
	 */
	public void setMode(int pickMode) {
		pickCanvas.setMode(pickMode);
	}

	
	/**
	 * 
	 * @return
	 */
	public int getMode() {
		return pickCanvas.getMode();
	}

	
	/**
	 * 
	 * @param tolerance
	 */
	public void setTolerance(float tolerance) {
		pickCanvas.setTolerance(tolerance);
	}
	
	
	@Override
	public void initialize() {
		// TODO Auto-generated method stub

    	WakeupCriterion[] mouseEvents = new WakeupCriterion[2];
    	mouseEvents[0] = new WakeupOnAWTEvent(Event.MOUSE_MOVE);
    	mouseEvents[1] = new WakeupOnAWTEvent(Event.MOUSE_DOWN);
	    wakeupCondition = new WakeupOr(mouseEvents);

	    wakeupOn(wakeupCondition);
	}

	
	@SuppressWarnings("rawtypes")
	@Override
	public void processStimulus(Enumeration criteria) {
		// TODO Auto-generated method stub
		AWTEvent[] evt = null;

		while(criteria.hasMoreElements()) {
			WakeupCriterion wakeup = (WakeupCriterion)criteria.nextElement();
			if (wakeup instanceof WakeupOnAWTEvent)
				evt = ((WakeupOnAWTEvent)wakeup).getAWTEvent();
		}
	    
		if (evt != null && evt[0] instanceof MouseEvent)
			doProcess((MouseEvent)evt[0]);
			
	    wakeupOn(wakeupCondition);
	}


	@Override
	public void doProcess(MouseEvent evt) {
		// TODO Auto-generated method stub
		buttonPress = false;

	    if (evt.getID() == MouseEvent.MOUSE_PRESSED | evt.getID() == MouseEvent.MOUSE_CLICKED)
	    	buttonPress = true;
	    if (!buttonPress)
	    	return;
	    	
		int xpos = evt.getPoint().x;
		int ypos = evt.getPoint().y;
		
		pickCanvas.setShapeLocation(xpos, ypos);
		PickResult pr = pickCanvas.pickClosest();
		SceneObjectImpl target = null;
		if (pr != null &&
				(target = getMoveableSceneObject(pr)) != null ) {
			
			drag.setTarget(target);
			drag.wakeup();
		}
	}

	
	/**
	 * 
	 * @param pickResult
	 * @return
	 */
	protected static SceneObjectImpl getMoveableSceneObject(PickResult pickResult) {
		TransformGroup tg = (TransformGroup)
				pickResult.getNode(PickResult.TRANSFORM_GROUP);
		
		return getMoveableSceneObject(tg);
	}
	
	
	/**
	 * 
	 * @param group
	 * @return
	 */
	private static SceneObjectImpl getMoveableSceneObject(Node group) {
		if (group == null || !(group instanceof Group))
			return null;
		
		if (group instanceof SceneObjectImpl) {
			SceneObjectImpl sceneObject = (SceneObjectImpl)group;
			if (sceneObject.isMoveable())
				return sceneObject;
		}
		
		return getMoveableSceneObject(group.getParent());
	}
	
	
}
