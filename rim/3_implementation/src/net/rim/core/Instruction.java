package net.rim.core;

/**
 * @author Administrator2
 * @version 1.0
 * @created 04-Sep-2012 10:23:24 AM
 */
public abstract class Instruction {
	
	/**
	 * 
	 */
	protected String robotId;

	
	/**
	 * 
	 * @param robotId
	 */
	public Instruction(String robotId){
		this.robotId = robotId;
	}

	
	
	/**
	 * 
	 * @param text
	 */
	public abstract void parse(String text);
	
	
	@Override
	public abstract String toString();
	

}