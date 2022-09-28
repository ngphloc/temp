package net.rim.adapter.java3d;

import java.awt.AWTEvent;
import java.awt.event.MouseEvent;
import java.util.Enumeration;

import javax.media.j3d.Behavior;
import javax.media.j3d.WakeupCondition;
import javax.media.j3d.WakeupCriterion;
import javax.media.j3d.WakeupOnAWTEvent;
import javax.media.j3d.WakeupOr;
import javax.vecmath.Vector3d;

import net.rim.core.MouseHolder;
import net.rim.core.SceneObject;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class MouseHolderImpl extends Behavior implements MouseHolder {

    public static final int MANUAL_WAKEUP = 0x1;
    
    protected WakeupCondition wakeupCondition = null;
    
    protected int x = 0, y = 0;
    
    protected int x_last = 0, y_last = 0;
    
    protected SceneObjectImpl target = null;
    
    protected boolean buttonPress = false;
    
    protected boolean reset = false;
    
    protected boolean wakeUp = false;
    
    protected int flags = 0;

    protected double x_factor = .01;
    
    protected double y_factor = .01;

    
    
    @Override
	public void initialize() {
		// TODO Auto-generated method stub
    	WakeupCriterion[] mouseEvents = new WakeupCriterion[4];

    	mouseEvents[0] = new WakeupOnAWTEvent(MouseEvent.MOUSE_DRAGGED);
    	mouseEvents[1] = new WakeupOnAWTEvent(MouseEvent.MOUSE_PRESSED);
    	mouseEvents[2] = new WakeupOnAWTEvent(MouseEvent.MOUSE_RELEASED);
    	mouseEvents[3] = new WakeupOnAWTEvent(MouseEvent.MOUSE_WHEEL);

    	wakeupCondition = new WakeupOr(mouseEvents);
		wakeupOn(wakeupCondition);
		
	}

    
	@SuppressWarnings("rawtypes")
	@Override
	public void processStimulus(Enumeration criteria) {
		// TODO Auto-generated method stub
    	while (criteria.hasMoreElements()) {
    		WakeupCriterion wakeup = (WakeupCriterion) criteria.nextElement();
    		if (wakeup instanceof WakeupOnAWTEvent) {
    			AWTEvent[] events = ((WakeupOnAWTEvent)wakeup).getAWTEvent();
    			if (events.length > 0) {
    				MouseEvent evt = (MouseEvent) events[events.length-1];
    				doProcess(evt);
    			}
    		}
    	}
    	wakeupOn (wakeupCondition);
	}

	
	@Override
	public void wakeup() {
		// TODO Auto-generated method stub
		wakeUp = true;
	}

	
	
	@Override
	public void doProcess(MouseEvent evt) {
		// TODO Auto-generated method stub
    	if (evt.getID() == MouseEvent.MOUSE_PRESSED) {
    		buttonPress = true;
    	}
    	else if (evt.getID() == MouseEvent.MOUSE_RELEASED){
    		buttonPress = false;
    		wakeUp = false;
    	}
    	
    	boolean condition = ((buttonPress)&&((flags & MANUAL_WAKEUP) == 0)) ||
    			((wakeUp)&&((flags & MANUAL_WAKEUP) != 0));
    	if (!condition)
    		return;
    	
		if (evt.getID() == MouseEvent.MOUSE_PRESSED) {
			x_last = evt.getX();
			y_last = evt.getY();
		}
		else if (evt.getID() == MouseEvent.MOUSE_DRAGGED) {
			x = evt.getX();
			y = evt.getY();
			if (reset) {
				x_last = x;
				y_last = y;
				reset = false;
				return;
			}
			
			if (!evt.isMetaDown() && !evt.isAltDown())
				onMouseRotate(evt);
			else if (evt.isMetaDown() && !evt.isAltDown())
				onMouseTranslate(evt);
			else if (!evt.isMetaDown() && evt.isAltDown())
				onMouseZoom(evt);
			
		}
    	
	}

	
	/**
	 * 
	 * @param evt
	 */
	protected void onMouseRotate(MouseEvent evt) {
		int dx = x - x_last;
		int dy = y - y_last;

		Vector3d rot = new Vector3d();
		rot.x = dy * y_factor;
		rot.y = dx * x_factor;
		target.rotate(rot, true);
	}
	

	/**
	 * 
	 * @param evt
	 */
	protected void onMouseTranslate(MouseEvent evt) {
		int dx = x - x_last;
		int dy = y - y_last;
		
		Vector3d trans = new Vector3d();
	    trans.x = dx * x_factor; 
	    trans.y = -dy * y_factor;
		target.translate(trans, true);
	}

	
	/**
	 * 
	 * @param evt
	 */
	protected void onMouseZoom(MouseEvent evt) {
		int dy = y - y_last;
		
		Vector3d trans = new Vector3d();
	    trans.z = dy * y_factor;
		target.translate(trans, true);
	}

	
	@Override
	public SceneObject getTarget() {
		// TODO Auto-generated method stub
		return target;
	}

	
	@Override
	public void setTarget(SceneObject target) {
		// TODO Auto-generated method stub
		this.target = (SceneObjectImpl)target;
		reset = true;
	}


}
