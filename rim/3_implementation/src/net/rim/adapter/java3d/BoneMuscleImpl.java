package net.rim.adapter.java3d;

import javax.vecmath.Matrix4d;

import net.rim.core.Bone;
import net.rim.core.BoneMuscle;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class BoneMuscleImpl extends MuscleImpl implements BoneMuscle {

	/**
	 * 
	 */
	protected Bone bone = null;
	
	
	
	/**
	 * 
	 * @param updateLocalSystem
	 */
	public BoneMuscleImpl(Bone bone) {
		super();
		// TODO Auto-generated constructor stub
		
		setBone(bone, true);
	}

	/**
	 * 
	 * @param bone
	 * @param updateLocalSystem
	 */
	public BoneMuscleImpl(Bone bone, boolean updateLocalSystem) {
		super();
		// TODO Auto-generated constructor stub
		
		setBone(bone, updateLocalSystem);
	}

	
	@Override
	public Bone getBone() {
		// TODO Auto-generated method stub
		return bone;
	}

	
	@Override
	public void setBone(Bone bone, boolean updateLocalSystem) {
		// TODO Auto-generated method stub
		Bone preBone = this.bone;
		this.bone = bone;
		if (!updateLocalSystem)
			return;
		
		if (preBone == null) {
			if (bone != null) {
				Matrix4d absCoordSystem = bone.getAbsCoordSystem();
				absCoordSystem.invert();
				absCoordSystem.mul(this.getTransformMatrix());
				this.setTransform(absCoordSystem, true);
			}
		}
		else {
			Matrix4d preAbsCoordSystem = preBone.getAbsCoordSystem();
			preAbsCoordSystem.mul(this.getTransformMatrix());
			
			if (bone != null) {
				Matrix4d absCoordSystem = bone.getAbsCoordSystem();
				absCoordSystem.invert();
				absCoordSystem.mul(preAbsCoordSystem);
				this.setTransform(absCoordSystem, true);
			}
			else
				this.setTransform(preAbsCoordSystem, true);
				
		}
	}

	
	
}
