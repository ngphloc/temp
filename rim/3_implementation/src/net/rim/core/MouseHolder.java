package net.rim.core;

import java.awt.event.MouseEvent;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public interface MouseHolder {
	
	/**
	 * 
	 */
	void wakeup();
	
	
	/**
	 * 
	 * @param evt
	 */
	void doProcess(MouseEvent evt);
	
	
	/**
	 * 
	 * @return
	 */
	SceneObject getTarget();
	
	
	/**
	 * 
	 * @param target
	 */
	void setTarget(SceneObject target);
}
