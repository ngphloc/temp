package net.rim.core;

import javax.vecmath.Matrix4d;

/**
 * @author Administrator2
 * @version 1.0
 * @created 04-Sep-2012 10:23:30 AM
 */
public abstract class Tool extends Bone {

	/**
	 * 
	 */
	protected Link link = null;
	
	
	/**
	 * 
	 * @param link
	 * @param matrix
	 */
	public Tool(Link link, Matrix4d matrix) {
		super(matrix);
		this.matrix = matrix;
		this.link = link;
	}

	
	@Override
	public Matrix4d getAbsCoordSystem() {
		Matrix4d m = link.getAbsCoordSystem();
		m.mul(matrix);
		
		return m;
	}

	
	@Override
	public Matrix4d getCoordSystem() {
		return link.getMatrix();
	}

	
	/**
	 * 
	 * @return
	 */
	public Link getLink() {
		return link;
	}

	
}