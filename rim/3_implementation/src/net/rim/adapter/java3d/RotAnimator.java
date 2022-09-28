package net.rim.adapter.java3d;

import java.util.Enumeration;

import javax.media.j3d.Interpolator;
import javax.media.j3d.RotationInterpolator;
import javax.media.j3d.Transform3D;
import javax.vecmath.AxisAngle4f;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class RotAnimator extends AnimatorImpl {

	
	/**
	 * 
	 */
	protected AxisAngle4f axis = new AxisAngle4f(0, 0, 1, 0);
	
	
	/**
	 * 
	 */
	protected double minAngle = 0;
	
	
	/**
	 * 
	 */
	protected double maxAngle = (double) (2 * Math.PI);
	
	
	/**
	 * 
	 * @param target
	 * @param msElapse
	 * @param minAngle
	 * @param maxAngle
	 */
	public RotAnimator(
			SceneObjectImpl target, 
			long msElapse,
			double minAngle,
			double maxAngle) {
		super(target, msElapse);
		// TODO Auto-generated constructor stub
		
		this.minAngle = minAngle;
		this.maxAngle = maxAngle;
	}

	
	@Override
	protected Interpolator createInterpolator() {
		// TODO Auto-generated method stub
		Transform3D tf = new Transform3D();
		tf.set(axis);
		
		SceneObjectImpl obj = (SceneObjectImpl)target;
		return new RotationInterpolator(
			null, 
			obj.getTransformGroup(), 
			tf, 
			(float)minAngle, (float)maxAngle) {

				@SuppressWarnings("rawtypes")
				@Override
				public void processStimulus(Enumeration criterion) {
					// TODO Auto-generated method stub
					super.processStimulus(criterion);
					transformChanged();
				}
			
		};
	}



	
	
	
}
