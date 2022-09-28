package net.rim.core;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public interface View extends SceneObject {

	
	/**
	 * 
	 */
	void compiling();

	
	/**
	 * 
	 * @return
	 */
	Model getModel();
	
	
	/**
	 * 
	 * @return
	 */
	ViewParam getViewParam();
	
	
	/**
	 *
	 */
	void setViewParam(ViewParam viewParam);
	
}
