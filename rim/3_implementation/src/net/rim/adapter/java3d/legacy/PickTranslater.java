package net.rim.adapter.java3d.legacy;

import javax.media.j3d.Bounds;
import javax.media.j3d.BranchGroup;
import javax.media.j3d.Canvas3D;

import net.rim.adapter.java3d.SceneObjectImpl;

import com.sun.j3d.utils.behaviors.mouse.MouseRotate;
import com.sun.j3d.utils.picking.PickResult;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class PickTranslater extends PickBehavior {

	
	/**
	 * 
	 * @param root
	 * @param canvas
	 * @param bounds
	 */
	public PickTranslater(BranchGroup root, Canvas3D canvas, Bounds bounds) {
		super(root, canvas, bounds);
	}

	
	/**
	 * 
	 * @param root
	 * @param canvas
	 * @param bounds
	 * @param pickMode
	 */
	public PickTranslater(BranchGroup root, Canvas3D canvas, Bounds bounds, 
			int pickMode){
		super(root, canvas, bounds, pickMode);
	}


	@Override
	protected MouseBehavior createMouseBehavior() {
		// TODO Auto-generated method stub
		return new MouseTranslater(MouseRotate.MANUAL_WAKEUP);
	}


	@Override
	public void updateScene(int xpos, int ypos){
		if (mevent.isMetaDown() && !mevent.isAltDown()) {
	      
			pickCanvas.setShapeLocation(xpos, ypos);
			PickResult pr = pickCanvas.pickClosest();
			SceneObjectImpl transformGroup = null;
			if (pr != null &&
					(transformGroup = getMoveableSceneObject(pr)) != null ) {
				
				drag.setTransformGroup(transformGroup);
				drag.wakeup();
			} 
		}
	}

	
	
}
