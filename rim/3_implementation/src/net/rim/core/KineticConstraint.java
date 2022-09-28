package net.rim.core;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public interface KineticConstraint extends Cloneable {
	
	/**
	 * 
	 * @param value
	 * @return
	 */
	double fixValue(double value);
	
	
	
	
	/**
	 * 
	 * @return
	 */
	public Object clone();
}
