package net.rim.core;

/**
 * @author Administrator2
 * @version 1.0
 * @created 04-Sep-2012 10:23:24 AM
 */
public abstract class Engine {

	
	/**
	 * 
	 * @author Administrator2
	 * @version 1.0
	 *
	 */
	public static enum EngineType { }
	
	
	/**
	 * 
	 */
	protected InputEngineParam input = null;
	
	
	/**
	 * 
	 */
	protected OutputEngineParam output = null;

	
	/**
	 * 
	 * @return
	 */
	public abstract EngineType getEngineType();
	
	

	/**
	 * 
	 * @return
	 */
	public OutputEngineParam getOutputParam() {
		return output;
	}

	
	/**
	 * 
	 * @return
	 */
	public InputEngineParam getInputParam() {
		return input;
	}
	
}