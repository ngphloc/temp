package net.rim.core;

import java.util.ArrayList;
import java.util.List;

import net.rim.core.KineticParam.JointType;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class KineticParamList {
	
	
	/**
	 * 
	 */
	protected List<KineticParam> list = new ArrayList<KineticParam>();
	
	
	/**
	 * 
	 */
	public KineticParamList() {
		
	}
	
	
	/**
	 * 
	 * @param index
	 * @return
	 */
	public KineticParam get(int index) {
		return list.get(index);
	}
	
	
	/**
	 * 
	 * @return
	 */
	public int size() {
		return list.size();
	}
	
	
	/**
	 * 
	 * @param param
	 */
	public void add(KineticParam param) {
		list.add(param);
	}
	
	
	/**
	 * 
	 * @param jointType
	 * @param variable
	 */
	public void add(JointType jointType, double variable) {
		list.add(new KineticParam(jointType, variable));
	}

	
	/**
	 * 
	 * @param jointType
	 * @param a
	 * @param alpha
	 * @param d
	 * @param theta
	 */
	public void add(
			JointType jointType, double a, double alpha, double d, double theta) {
		list.add(KineticParam.create(jointType, a, alpha, d, theta));
	}

	
	/**
	 * 
	 * @param high
	 */
	public void add(double high) {
		list.add(KineticParam.create(high));
	}
	
	
	/**
	 * 
	 * @param index
	 * @param param
	 */
	public void set(int index, KineticParam param) {
		list.set(index, param);
	}
	
	
	
	/**
	 * 
	 * @param index
	 */
	public void remove(int index) {
		list.remove(index);
	}
	
}
