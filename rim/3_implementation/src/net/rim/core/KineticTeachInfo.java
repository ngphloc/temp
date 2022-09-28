package net.rim.core;

import javax.vecmath.Point3d;

/**
 * @author Administrator2
 * @version 1.0
 * @created 04-Sep-2012 10:23:26 AM
 */
public class KineticTeachInfo {

	/**
	 * 
	 */
	protected Point3d[] knots = new Point3d[0];
	
	
	/**
	 * 
	 */
	protected double[] timeIntervals = new double[0];

	
	/**
	 * 
	 */
	public KineticTeachInfo() {

	}


	/**
	 * 
	 * @param knots
	 * @param timeIntervals
	 */
	public KineticTeachInfo(Point3d[] knots, double[] timeIntervals){
		setup(knots, timeIntervals);
	}

	
	
	/**
	 * 
	 * @param knots
	 * @param timeIntervals
	 */
	public void setup(Point3d[] knots, double[] timeIntervals){
		if (knots.length < 2 || timeIntervals.length != knots.length - 1)
			throw new RuntimeException("Invalid parameters");
		
		this.knots = knots;
		this.timeIntervals = timeIntervals;
	}
	
	
	public Point3d[] getKnots() {
		return knots;
	}
	
	
	/**
	 * 
	 * @return
	 */
	public double[] getTimeIntervals() {
		return timeIntervals;
	}
	
	
}