package net.rim.core;

import net.rim.core.Engine.EngineType;

/**
 * @author Administrator2
 * @version 1.0
 * @created 04-Sep-2012 10:23:21 AM
 */
public abstract class Dynamic {

	/**
	 * 
	 */
	protected Orbit orbit = null;
	
	
	/**
	 * 
	 */
	protected Robot robot = null;

	
	/**
	 * 
	 */
	public Dynamic() {

	}


	/**
	 * 
	 * @param robot
	 * @param orbit
	 */
	public Dynamic(Robot robot, Orbit orbit){
		setup(robot, orbit);
	}

	
	/**
	 * 
	 * @param robot
	 * @param orbit
	 */
	public void setup(Robot robot, Orbit orbit){
		this.robot = robot;
		this.orbit = orbit;
	}

	
	/**
	 * 
	 * @param linkIndex
	 * @param beginPosIndex
	 * @param endPosIndex
	 */
	public abstract double calcLinkEnergy(
			int linkIndex, int beginPosIndex, int endPosIndex);

	
	
	/**
	 * 
	 * @param linkIndex
	 */
	public abstract double calcLinkEnergy(int linkIndex);

	
	
	/**
	 * 
	 * @param linkIndex
	 * @param beginPosIndex
	 * @param endPosIndex
	 */
	public abstract double calcLinkForce(
			int linkIndex, int beginPosIndex, int endPosIndex);
	
	

	/**
	 * 
	 * @param linkIndex
	 */
	public abstract double calcLinkForce(int linkIndex);

	
	/**
	 * 
	 * @return
	 */
	public abstract double calcTotalEnergy();
	

	/**
	 * 
	 * @param linkIndex
	 * @param engineType
	 */
	public abstract Engine queryEngine(int linkIndex, EngineType engineType);

}