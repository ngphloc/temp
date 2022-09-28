package net.rim.core;

import javax.vecmath.Matrix4d;
import javax.vecmath.Point2i;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public abstract class Skeleton implements Model {
	
	
	/**
	 * 
	 * @author Administrator2
	 * @version 1.0
	 *
	 */
	public static interface BoneProcessor {
		void process(Bone bone);
	}
	
	
	/**
	 * 
	 */
	protected Matrix4d matrix = new Matrix4d();
	
	
	/**
	 * 
	 */
	protected Bone base = null;
	
	
	/**
	 * 
	 */
	public Skeleton() {
		matrix.setIdentity();
	}

	
	/**
	 * 
	 * @param processor
	 */
	protected void process(BoneProcessor processor) {
		process(base, processor);
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	public Bone getBaseBone() {
		return base;
	}
	
	
	
	/**
	 * 
	 * @param base
	 */
	public void setBaseBone(Bone base) {
		this.base = base;
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	public int getBoneCount() {
		final Point2i size = new Point2i(0, 0);
		
		BoneProcessor processor = new BoneProcessor() {
			
			@Override
			public void process(Bone bone) {
				// TODO Auto-generated method stub
				if (bone != null)
					size.x ++;
			}
		};
		
		process(processor);
		return size.x;
	}
	
	
	/**
	 * 
	 * @param base
	 * @param processor
	 */
	private void process(Bone base, BoneProcessor processor) {
		if (base == null)
			return;
		
		processor.process(base);
		for (Bone child : base.childBones) {
			process(child, processor);
		}
		
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
	
	
	
	
}
