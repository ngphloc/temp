package net.rim.adapter.java3d.legacy;

import javax.media.j3d.Bounds;
import javax.media.j3d.BranchGroup;
import javax.media.j3d.Canvas3D;
import javax.media.j3d.Group;
import javax.media.j3d.Node;
import javax.media.j3d.TransformGroup;

import net.rim.adapter.java3d.SceneObjectImpl;

import com.sun.j3d.utils.picking.PickResult;
import com.sun.j3d.utils.picking.behaviors.PickMouseBehavior;


/**
 * 
 * @author Administrator2
 * @vesion 1.0
 *
 */
public abstract class PickBehavior extends PickMouseBehavior {

	
	/**
	 * 
	 */
	protected MouseBehavior drag = null;
	
	
	/**
	 * 
	 * @param canvas
	 * @param root
	 * @param bounds
	 */
	public PickBehavior(BranchGroup root, Canvas3D canvas, Bounds bounds) {
		super(canvas, root, bounds);
		// TODO Auto-generated constructor stub
		drag = createMouseBehavior();
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
	public PickBehavior(BranchGroup root, Canvas3D canvas, Bounds bounds, 
			int pickMode){
		this(root, canvas, bounds);
		this.setMode(pickMode);
	}

	
	/**
	 * 
	 */
	public abstract void updateScene(int xpos, int ypos);

	
	/**
	 * 
	 * @return
	 */
	protected abstract MouseBehavior createMouseBehavior();
	
	
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
