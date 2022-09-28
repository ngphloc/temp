package net.rim.core;

/**
 * @author Administrator2
 * @version 1.0
 * @created 04-Sep-2012 10:23:26 AM
 */
public abstract class Controller {

	/**
	 * 
	 */
	protected Scene scene = null;
	

	/**
	 * 
	 * @param scene
	 */
	public Controller(Scene scene){
		this.scene = scene;
	}

	
	/**
	 * 
	 * @param designer
	 */
	public abstract Robot createRobot(RobotDesigner designer);
	
	

	/**
	 * 
	 * @param program
	 */
	public abstract void execute(Program program);
	
	
	/**
	 * 
	 * @param instruction
	 */
	public abstract void execute(Instruction instruction);
	
	
	
	/**
	 * 
	 * @param program
	 */
	public abstract Dynamic[] getDynamicList(Program program);
	
	

	/**
	 * 
	 * @param program
	 */
	public abstract Kinetic[] getKineticList(Program program);
	

	/**
	 * 
	 * @param robotId
	 */
	public abstract Robot getRobot(String robotId);

	
	/**
	 * 
	 * @return
	 */
	public abstract Robot[] getRobots();
	

	
	/**
	 * 
	 * @param robot
	 * @param pendant
	 */
	public abstract Program teachRobot(Robot robot, TeachPendant pendant);
	
	
	
	/**
	 * 
	 * @param robots
	 * @param pendant
	 */
	public abstract Program teachRobots(Robot[] robots, TeachPendant pendant);

	
	/**
	 * 
	 * @param robot
	 * @param teachInfo
	 */
	public abstract Program teachRobot(Robot robot, TeachInfo teachInfo);
	
	

}