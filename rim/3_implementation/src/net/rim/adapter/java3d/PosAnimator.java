package net.rim.adapter.java3d;

import java.util.Enumeration;

import javax.media.j3d.Interpolator;
import javax.media.j3d.RotPosPathInterpolator;
import javax.media.j3d.Transform3D;
import javax.vecmath.Point3f;
import javax.vecmath.Quat4f;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class PosAnimator extends AnimatorImpl {
	

	/**
	 * 
	 */
	protected Point3f[] path = new Point3f[0];
	
	
	/**
	 * 
	 * @param sceneObject
	 * @param path
	 * @param msElapse
	 */
	public PosAnimator(
			SceneObjectImpl sceneObject, 
			Point3f[] path, 
			long msElapse) {
		super(sceneObject, msElapse);
		this.path = path;
	}
	
	
	
	@Override
	protected Interpolator createInterpolator() {
		// TODO Auto-generated method stub
		
		float deviate = 1 / (path.length - 1);
		float[] knots = new float[path.length];
		Quat4f[] rots = new Quat4f[path.length];
		for (int i = 0; i < path.length; i++) {
			knots[i] = i * deviate;
			rots[i] = new Quat4f();
		}
		
		SceneObjectImpl obj = (SceneObjectImpl)target;
		return new RotPosPathInterpolator(
			null, 
			obj.getTransformGroup(), 
			new Transform3D(), 
			knots, 
			rots, 
			path) {

				@SuppressWarnings("rawtypes")
				@Override
				public void processStimulus(Enumeration criteria) {
					// TODO Auto-generated method stub
					super.processStimulus(criteria);
					transformChanged();
				}
			
		};
	}


	
	
	

	
}
