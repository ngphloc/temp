package net.rim.core;

public class ViewParam {

	/**
	 * 
	 * @author Administrator2
	 * @version 1.0
	 *
	 */
	public static enum Mode { bone, muscle, body }
	
	
	/**
	 * 
	 */
	public final static int SHOW_AXISES = 1;

	
	/**
	 * 
	 */
	protected Mode mode = Mode.body;
	
	
	/**
	 * 
	 */
	protected int flags = 0;
	
	
	/**
	 * 
	 * @param mode
	 * @param flags
	 */
	public ViewParam(Mode mode, int flags) {
		this.mode = mode;
		this.flags = flags;
	}
	
	
	/**
	 * 
	 * @return
	 */
	public Mode getMode() {
		return mode;
	}
	
	
	/**
	 * 
	 * @return
	 */
	public int getFlags() {
		return flags;
	}
}
