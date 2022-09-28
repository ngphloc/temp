package net.rim.adapter.java3d;

import javax.media.j3d.Appearance;
import javax.media.j3d.Node;
import javax.media.j3d.Shape3D;

import net.rim.core.Muscle;
import net.rim.core.SceneObject;

import com.sun.j3d.utils.geometry.Primitive;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class MuscleImpl extends SceneObjectImpl implements Muscle {
	
	/**
	 * 
	 */
	protected Node shape = null;
	
	
	/**
	 * 
	 */
	public MuscleImpl() {
		super();
		// TODO Auto-generated constructor stub
	}

	
	/**
	 * 
	 * @param shape
	 */
	public MuscleImpl(Node shape) {
		super();
		// TODO Auto-generated constructor stub
		setShape(shape);
	}

	

	
	/**
	 * 
	 * @return
	 */
	public Node getShape() {
		return shape;
	}
	
	
	/**
	 * 
	 * @param shape
	 */
	public void setShape(Node shape) {
		if (!(shape instanceof Shape3D) && !(shape instanceof Primitive))
			throw new RuntimeException("Invalid parameter");
		else {
			this.shape = shape;
			tg.removeAllChildren();
			tg.addChild(shape);
		}
	}
	
	
	
	@Override
	public void addSceneChild(SceneObject child) {
		// TODO Auto-generated method stub
		throw new RuntimeException("Not support this method");
	}


	@Override
	public void removeSceneChild(SceneObject child) {
		// TODO Auto-generated method stub
		throw new RuntimeException("Not support this method");
	}


	@Override
	public void removeSceneChild(int index) {
		// TODO Auto-generated method stub
		throw new RuntimeException("Not support this method");
	}


	@Override
	public void removeAllSceneChildren() {
		// TODO Auto-generated method stub
		throw new RuntimeException("Not support this method");
	}


	@Override
	public SceneObject getSceneChild(int index) {
		// TODO Auto-generated method stub
		throw new RuntimeException("Not support this method");
	}


	@Override
	public int getSceneChildCount() {
		// TODO Auto-generated method stub
		throw new RuntimeException("Not support this method");
	}


	/**
	 * 
	 * @return
	 */
	public Appearance getAppearence() {
		if (shape instanceof Shape3D)
			return ((Shape3D)shape).getAppearance();
		else if (shape instanceof Primitive)
			return ((Primitive)shape).getAppearance();
		else
			return null;
	}
	
	
	/**
	 * 
	 * @param appearence
	 */
	public void setAppearence(Appearance appearence) {
		if (shape instanceof Shape3D)
			((Shape3D)shape).setAppearance(appearence);
		else if (shape instanceof Primitive)
			((Primitive)shape).setAppearance(appearence);
	}


	
}
