package net.rim.adapter.java3d;

import javax.media.j3d.Transform3D;
import javax.media.j3d.TransformGroup;
import javax.vecmath.Matrix4d;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class TransformGroup2 extends TransformGroup {
	
	
	/**
	 * 
	 */
	protected SceneObjectImpl sceneObject = null;
	
	
	/**
	 * 
	 */
	public TransformGroup2(SceneObjectImpl sceneObject) {
		super();
		// TODO Auto-generated constructor stub
		
		this.sceneObject = sceneObject;
		setup();
	}

	
	/**
	 * 
	 * @param t1
	 */
	public TransformGroup2(SceneObjectImpl sceneObject, Transform3D t1) {
		super(t1);
		// TODO Auto-generated constructor stub
		
		this.sceneObject = sceneObject;
		setup();
	}

	
	/**
	 * 
	 */
	protected void setup() {
		setCapability(ALLOW_TRANSFORM_READ);
		setCapability(ALLOW_TRANSFORM_WRITE);
		setCapability(ALLOW_CHILDREN_READ);
		setCapability(ALLOW_CHILDREN_WRITE);
		setCapability(ALLOW_CHILDREN_EXTEND);
		setCapability(ENABLE_PICK_REPORTING);
		
	}
	
	
	/**
	 * 
	 * @return
	 */
	public boolean isMoveable() {
		return sceneObject.isMoveable();
	}

	
	/**
	 * 
	 * @return
	 */
	public Matrix4d getMatrix() {
		Transform3D tf = new Transform3D();
		getTransform(tf);
		Matrix4d matrix = new Matrix4d();
		tf.get(matrix);
		
		return matrix;
	}

	
	/**
	 * 
	 * @param tf
	 */
	protected void setTransform2(Transform3D tf) {
		super.setTransform(tf);
	}
	
	
	@Override
	public void setTransform(Transform3D tf) {
		// TODO Auto-generated method stub
		sceneObject.setTransform(tf, true);
	}
	
	
	/**
	 * 
	 * @return
	 */
	public SceneObjectImpl getSceneObject() {
		return sceneObject;
	}
	
}
