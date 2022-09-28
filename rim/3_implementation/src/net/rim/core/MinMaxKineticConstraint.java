package net.rim.core;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public final class MinMaxKineticConstraint implements KineticConstraint {
	
	/**
	 * 
	 */
	protected double minValue = 0;
	
	
	/**
	 * 
	 */
	protected double maxValue = 0;
	
	
	/**
	 * 
	 * @param minValue
	 * @param maxValue
	 */
	public MinMaxKineticConstraint(double minValue, double maxValue) {
		this.minValue = minValue;
		this.maxValue = maxValue;
	}
	
	
	public double getMinValue() {
		return minValue;
	}
	
	
	/**
	 * 
	 * @return
	 */
	public double getMaxValue() {
		return maxValue;
	}
	
	
	@Override
	public double fixValue(double value) {
		value = Math.max(minValue, value);
		value = Math.min(maxValue, value);
		
		return value;
	}


	@Override
	public Object clone() {
		// TODO Auto-generated method stub
		return new MinMaxKineticConstraint(minValue, maxValue);
	}
	
	
}
