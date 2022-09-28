package net.rim.adapter.java3d;

import javax.media.j3d.BranchGroup;
import javax.media.j3d.Group;
import javax.media.j3d.Transform3D;
import javax.media.j3d.TransformGroup;
import javax.vecmath.Matrix4d;
import javax.vecmath.Vector3d;

import net.rim.core.SceneObject;
import net.rim.core.SceneObjectProperty;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class SceneObjectImpl extends BranchGroup implements SceneObject {

	/**
	 * 
	 */
	protected TransformGroup2 tg = null;
	
	
	/**
	 * 
	 */
	protected SceneObjectProperty property = new SceneObjectProperty();
	
	
	/**
	 * 
	 */
	public SceneObjectImpl() {
		this.setCapability(Group.ALLOW_CHILDREN_READ);
		this.setCapability(Group.ALLOW_CHILDREN_WRITE);
		this.setCapability(Group.ALLOW_CHILDREN_EXTEND);
		
		tg = new TransformGroup2(this);
		this.addChild(tg);
	}
	
	
	@Override
	public void addSceneChild(SceneObject child) {
		tg.addChild((SceneObjectImpl)child);
	}
	

	@Override
	public void removeSceneChild(SceneObject child) {
		tg.removeChild((SceneObjectImpl)child);
	}
	
	
	@Override
	public void removeSceneChild(int index) {
		// TODO Auto-generated method stub
		tg.removeChild(index);
	}

	
	@Override
	public void removeAllSceneChildren() {
		// TODO Auto-generated method stub
		tg.removeAllChildren();
	}
	
	
	@Override
	public SceneObject getSceneChild(int index) {
		return (SceneObject)tg.getChild(index);
	}
	
	
	@Override
	public int getSceneChildCount() {
		// TODO Auto-generated method stub
		return tg.numChildren();
	}


	
	@Override
	public void setProperty(SceneObjectProperty property) {
		// TODO Auto-generated method stub
		this.property = property;
	}


	@Override
	public SceneObjectProperty getProperty() {
		// TODO Auto-generated method stub
		return property;
	}


	/**
	 * 
	 * @return
	 */
	public boolean isMoveable() {
		return property.Moveable;
	}
	
	
	/**
	 * 
	 * @param moveable
	 */
	public void setMoveable(boolean moveable) {
		property.Moveable = moveable;
	}
	
	
	
	/**
	 * 
	 * @param tf
	 */
	public void setTransform(Transform3D tf, boolean update) {
		tg.setTransform2(tf);
	}
	
	
	/**
	 * 
	 * @param matrix
	 */
	public void setTransform(Matrix4d matrix, boolean update) {
		setTransform(new Transform3D(matrix), update);
	}

	
	/**
	 * 
	 * @return
	 */
	public Matrix4d getTransformMatrix() {
		return tg.getMatrix();
	}
	
	
	/**
	 * 
	 * @param tf
	 */
	public void getTransform(Transform3D tf) {
		tg.getTransform(tf);
	}

	
	/**
	 * 
	 * @return
	 */
	public TransformGroup getTransformGroup() {
		return tg;
	}
	
	
	@Override
	public void rotate(Vector3d angle, boolean update) {
		Transform3D tfX = new Transform3D(); 
		tfX.rotX(angle.x);
		
		Transform3D tfY = new Transform3D(); 
		tfY.rotY(angle.y);
		
		Transform3D tfZ = new Transform3D(); 
		tfZ.rotZ(angle.z);

		Matrix4d matrix = getTransformMatrix();
		Transform3D current = new Transform3D(matrix);
		current.setTranslation(new Vector3d(0.0, 0.0, 0.0));
		current.mul(tfX, current);
		current.mul(tfY, current);
		current.mul(tfZ, current);

		Vector3d translation = new 
				Vector3d(matrix.m03, matrix.m13, matrix.m23);
		current.setTranslation(translation);
		
		this.setTransform(current, update);
	}
	
	
	@Override
	public void translate(Vector3d trans, boolean update) {
		Transform3D tf = new Transform3D();
		tf.setTranslation(trans);
		
		Transform3D current = new Transform3D();
		getTransform(current);
		current.mul(tf, current);
		
		this.setTransform(current, update);
	}
	
	
	
}
