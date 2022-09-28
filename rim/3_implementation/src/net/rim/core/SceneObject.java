package net.rim.core;

import javax.vecmath.Vector3d;


/**
 * @author Administrator2
 * @version 1.0
 * @created 04-Sep-2012 10:23:28 AM
 */
public interface SceneObject {
	
	/**
	 * 
	 * @param child
	 */
	void addSceneChild(SceneObject child);
	
	
	/**
	 * 
	 * @param child
	 */
	void removeSceneChild(SceneObject child);
	
	
	/**
	 * 
	 * @param index
	 */
	void removeSceneChild(int index);

	
	/**
	 * 
	 */
	void removeAllSceneChildren();

	
	/**
	 * 
	 * @param index
	 * @return
	 */
	SceneObject getSceneChild(int index);
	
	
	/**
	 * 
	 * @return
	 */
	int getSceneChildCount();

	
	/**
	 * 
	 * @param property
	 */
	void setProperty(SceneObjectProperty property);
	
	
	/**
	 * 
	 * @return
	 */
	SceneObjectProperty getProperty();
	
	
	/**
	 * 
	 * @param angle
	 */
	void rotate(Vector3d angle, boolean update);
	
	
	/**
	 * 
	 * @param trans
	 */
	void translate(Vector3d trans, boolean update);
	
	
}