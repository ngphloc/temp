package net.rim.core;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public interface BoneMuscle extends Muscle {
	
	/**
	 * 
	 * @return
	 */
	Bone getBone();
	
	
	/**
	 * 
	 * @param bone
	 * @param updateLocalSystem
	 */
	void setBone(Bone bone, boolean updateLocalSystem);
}
