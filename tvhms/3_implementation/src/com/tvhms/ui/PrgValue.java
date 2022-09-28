package com.tvhms.ui;

public class PrgValue implements Comparable<Float> {

	/**
	 * 
	 */
	public float TotalValue = 0;
	
	
	/**
	 * 
	 */
	public float Value = 0;
	
	
	/**
	 * 
	 */
	public PrgValue() {
		
	}
	
	
	
	/**
	 * 
	 * @param totalValue
	 * @param value
	 */
	public PrgValue(float totalValue, float value) {
		this.TotalValue = totalValue;
		this.Value = value;
	}

	
	@Override
	public int compareTo(Float v) {
		// TODO Auto-generated method stub
		if (Value < v)
			return -1;
		else if (Value == v)
			return 0;
		else
			return 1;
	}

	
	@Override
	public String toString() {
		return String.valueOf(Value);
	}


	@Override
	public boolean equals(Object obj) {
		// TODO Auto-generated method stub
		return Value == ((PrgValue)obj).Value;
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	public int percent() {
		if (TotalValue == 0)
			return 100;
		else
			return (int)(Value / TotalValue * 100.0 + 0.5);
	}
	
	
}
