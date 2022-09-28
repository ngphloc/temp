package net.rim.core;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class SceneObjectProperty implements Cloneable {
	
	/**
	 * 
	 */
	public boolean Moveable = true;

	
	@Override
	public Object clone() {
		// TODO Auto-generated method stub
		SceneObjectProperty property = new SceneObjectProperty();
		property.Moveable = this.Moveable;
		return property;
	}
	
	
}
