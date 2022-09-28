package net.rim.core;

import java.util.ArrayList;
import java.util.List;

import javax.vecmath.Matrix4d;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public abstract class Bone implements Model {

	/**
	 * 
	 */
	protected Matrix4d matrix = new Matrix4d();
	
	
	/**
	 * 
	 */
	protected List<Muscle> muscles = new ArrayList<>();

	
	/**
	 * 
	 */
	protected Bone joint = null;
	
	
	/**
	 * 
	 */
	protected List<Bone> childBones = new ArrayList<>();
	
	
	/**
	 * 
	 */
	public Bone() {
		matrix.setIdentity();
	}
	
	
	/**
	 * 
	 * @param matrix
	 */
	public Bone(Matrix4d matrix) {
		this.matrix = matrix;
	}

	
	/**
	 * 
	 * @return
	 */
	public Matrix4d getMatrix() {
		return matrix;
	}

	
	/**
	 * 
	 * @param matrix
	 */
	public void setMatrix(Matrix4d matrix) {
		this.matrix = matrix;
	}
	
	
	/**
	 * 
	 * @return
	 */
	public int getMuscleCount() {
		return muscles.size();
	}

	
	/**
	 * 
	 * @param index
	 * @return
	 */
	public Muscle getMuscle(int index) {
		return muscles.get(index);
	}
	
	
	/**
	 * 
	 * @param muscle
	 */
	public void addMuscle(Muscle muscle) {
		muscles.add(muscle);
	}

	
	/**
	 * 
	 * @param muscleIndex
	 */
	public void removeMuscle(int muscleIndex) {
		muscles.remove(muscleIndex);
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	public Bone getJoint() {
		return joint;
	}
	
	
	/**
	 * 
	 * @param joint
	 */
	public void setJoint(Bone joint) {
		this.joint = joint;
	}
	
	
	/**
	 * 
	 * @return
	 */
	public int getChildBoneCount() {
		return childBones.size();
	}
	
	
	/**
	 * 
	 * @param index
	 * @return
	 */
	public Bone getChildBone(int index) {
		return childBones.get(index);
	}
	
	
	/**
	 * 
	 * @param bone
	 */
	public void addChildBone(Bone bone) {
		childBones.add(bone);
	}
	
	
	/**
	 * 
	 * @param bone
	 */
	public void removeChildBone(Bone bone) {
		childBones.remove(bone);
	}
	
	
	/**
	 * 
	 * @param index
	 */
	public void removeChildBone(int index) {
		childBones.remove(index);
	}

	
	/**
	 * 
	 * @return
	 */
	public Bone getHeadBone() {
		Bone head = this;
		while (head.joint != null)
			head = head.joint;
		
		return head;
	}
	
	
	/**
	 * 
	 * @return
	 */
	public int getLevel() {
		return getLevel0(getHeadBone(), 0);
	}

	
	/**
	 * 
	 * @param base
	 * @param level
	 * @return
	 */
	private int getLevel0(Bone base, int level) {
		if (base == this)
			return level;
		
		for (Bone bone : base.childBones) {
			return getLevel0(bone, level + 1);
		}
		return -1;
	}
	
	
	/**
	 * 
	 * @return
	 */
	public abstract Matrix4d getCoordSystem();

	
	
	/**
	 * 
	 * @return
	 */
	public abstract Matrix4d getAbsCoordSystem();
	
	
}
