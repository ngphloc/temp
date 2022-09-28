package net.rim.core;

import javax.vecmath.Point3d;

/**
 * @author Administrator2
 * @version 1.0
 * @created 04-Sep-2012 10:23:21 AM
 */
public abstract class Kinetic {

	
	/**
	 * 
	 */
	protected Point3d[] knots = new Point3d[0];
	
	
	/**
	 * 
	 */
	protected Robot robot = null;
	
	
	/**
	 * 
	 */
	protected double[] timeIntervals = new double[0];
	
	
	/**
	 * 
	 */
	protected Orbit orbit = null;
	
	
	/**
	 * 
	 */
	protected KineticParam[] kineticParams = new KineticParam[0];
	
	
	/**
	 * 
	 */
	public Kinetic() {

	}


	/**
	 * 
	 * @param knots
	 * @param robot
	 * @param timeIntervals
	 */
	public Kinetic(
		Point3d[] knots, Robot robot, double[] timeIntervals) {
		setup(knots, robot, timeIntervals);
	}
	
	
	/**
	 * 
	 * @param knots
	 * @param robot
	 * @param timeIntervals
	 */
	public void setup(
			Point3d[] knots, Robot robot, double[] timeIntervals) {
		if (knots.length < 2 || timeIntervals.length != knots.length - 1)
			throw new RuntimeException("Invalid parameters");
		
		this.knots = knots;
		this.robot = robot;
		this.timeIntervals = timeIntervals;
		this.orbit = null;
		this.kineticParams = new KineticParam[0];
	}
	
	
	/**
	 * 
	 */
	public abstract void calcOrbit();
	

	/**
	 * 
	 */
	public abstract void calcParams();
	
	
	/**
	 * 
	 * @return
	 */
	public Orbit getOrbit() {
		if (orbit == null)
			calcOrbit();
		
		return orbit;
	}
	
	
	/**
	 * 
	 * @return
	 */
	public KineticParam[] getKineticParams() {
		if (kineticParams.length == 0)
			calcParams();
		
		return kineticParams;
	}

	
	/**
	 * 
	 * @return
	 */
	public double[] getKineticVariables() {
		if (kineticParams.length == 0)
			calcParams();
		
		double[] variables = new double[kineticParams.length];
		for (int i = 0; i < variables.length; i++)
			variables[i] = kineticParams[i].getVariable();
		
		return variables;
	}
	
}