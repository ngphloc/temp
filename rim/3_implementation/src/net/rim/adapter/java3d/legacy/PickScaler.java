package net.rim.adapter.java3d.legacy;

import javax.media.j3d.Bounds;
import javax.media.j3d.BranchGroup;
import javax.media.j3d.Canvas3D;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public abstract class PickScaler extends PickBehavior {

	/**
	 * 
	 * @param root
	 * @param canvas
	 * @param bounds
	 */
	public PickScaler(BranchGroup root, Canvas3D canvas, Bounds bounds){
		super(root, canvas, bounds);
	}

	
	/**
	 * 
	 * @param root
	 * @param canvas
	 * @param bounds
	 * @param pickMode
	 */
	public PickScaler(BranchGroup root, Canvas3D canvas, Bounds bounds, 
			int pickMode) {
		super(root, canvas, bounds, pickMode);
	}

	

	
	
}
