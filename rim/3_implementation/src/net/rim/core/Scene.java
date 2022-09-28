package net.rim.core;

import java.awt.Canvas;


/**
 * @author Administrator2
 * @version 1.0
 * @created 04-Sep-2012 10:23:29 AM
 */
public interface Scene {
	
	/**
	 * 
	 * @param object
	 */
	void addSceneObject(SceneObject object);
	
	
	/**
	 * 
	 * @return
	 */
	int getSceneObjectCount();
	
	
	/**
	 * 
	 * @param index
	 */
	void removeSceneObject(int index);
	
	
	/**
	 * 
	 * @param object
	 */
	void removeSceneObject(SceneObject object);

	
	/**
	 * 
	 * @param index
	 * @return
	 */
	SceneObject getSceneObject(int index);

	
	/**
	 * 
	 * @return
	 */
	Canvas getCanvas();
	
	
	/**
	 * 
	 */
	void cleanup();
}