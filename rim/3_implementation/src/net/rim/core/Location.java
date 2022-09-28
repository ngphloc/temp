package net.rim.core;

import javax.vecmath.Point3d;

/**
 * @author Administrator2
 * @version 1.0
 * @created 04-Sep-2012 10:23:22 AM
 */
public class Location {

	/**
	 * 
	 */
	public Point3d Pos;
	
	
	/**
	 * 
	 */
	public double Time;
	
	
	/**
	 * 
	 */
	public double Velocity;

	
	/**
	 * 
	 */
	public double Accel;
	
	

	
	/**
	 * 
	 */
	public Location() {

	}


	/**
	 * 
	 * @param pos
	 * @param time
	 * @param velocity
	 * @param accel
	 */
	public Location(
			Point3d pos, double time, double velocity, double accel) {
		this.Pos = pos;
		this.Time = time;
		this.Velocity = velocity;
		this.Accel = accel;
	}

	
	
}