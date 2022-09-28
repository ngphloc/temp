package net.rim.adapter.java3d;

import java.awt.Color;

import javax.media.j3d.Transform3D;
import javax.vecmath.Color3f;
import javax.vecmath.Matrix4d;
import javax.vecmath.Point3d;
import javax.vecmath.Vector3d;

import net.rim.Sys;
import net.rim.core.KineticConstraint;
import net.rim.core.KineticParam.JointType;
import net.rim.core.Link;
import net.rim.core.Tool;
import net.rim.core.ViewParam;
import net.rim.core.ViewParam.Mode;

/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class LinkView extends ViewImpl {
	
	
	/**
	 * 
	 * @param link
	 */
	public LinkView(Link link) {
		super(link);
		// TODO Auto-generated constructor stub
		this.model = link;
	}

	
	/**
	 * 
	 * @param link
	 * @param viewParam
	 */
	public LinkView(Link link, ViewParam viewParam) {
		this(link);
		// TODO Auto-generated constructor stub
		setViewParam(viewParam);
		compiling();
	}

	
	@Override
	public void compiling() {
		removeAllSceneChildren();
		
		Matrix4d matrix = getLink().getMatrix();
		setMoveable(false);

		if ((viewParam.getFlags() & ViewParam.SHOW_AXISES) != 0) {
			Axises axises = new Axises();
			axises.setMoveable(false);
			addSceneChild(axises);
		}
		
		
		Point3d begin = new Point3d(0, 0, 0);
		Point3d end = new Point3d(0, 0, 0);
		//
		Matrix4d invert = new Matrix4d(matrix);
		invert.invert();
		invert.transform(begin);
		//
		SceneObjectImpl bone = (SceneObjectImpl) Sys.AdapterFactory.createBar(
				begin, end, 4, new Color3f(Color.red));
		bone.setMoveable(false);
		addSceneChild(bone);
		
		
		if (viewParam.getMode() == Mode.bone) {
			if (!getLink().isBaseLink())
				setMoveable(true);
			
		}
		else if (viewParam.getMode() == Mode.muscle) {
			
			for (int i = 0; i < getLink().getMuscleCount(); i++) {
				MuscleImpl muscle = (MuscleImpl) getLink().getMuscle(i);
				muscle.setMoveable(true);
				addSceneChild(muscle);
			}
		}
		else if (viewParam.getMode() == Mode.body) {
			if (!getLink().isBaseLink())
				setMoveable(true);
			
			for (int i = 0; i < getLink().getMuscleCount(); i++) {
				MuscleImpl muscle = (MuscleImpl) getLink().getMuscle(i);
				muscle.setMoveable(false);
				addSceneChild(muscle);
			}
		}
		
		
		if (getLink().getTool() != null) {
			Tool tool = getLink().getTool();
			ToolView toolView = new ToolView(tool, viewParam);
			addSceneChild(toolView);
		}
		
		
		setTransform(matrix, false);
	}
	
	
	/**
	 * 
	 * @return
	 */
	protected Link getLink() {
		return (Link)model;
	}
	
	
	@Override
	public void setTransform(Transform3D tf, boolean update) {
		// TODO Auto-generated method stub
		super.setTransform(tf, update);
		
		if (update)
			getLink().setKineticParam(tg.getMatrix());
	}


	@Override
	public void setTransform(Matrix4d matrix, boolean update) {
		// TODO Auto-generated method stub
		super.setTransform(matrix, update);
		
		if (update)
			getLink().setKineticParam(tg.getMatrix());
	}



	/**
	 * 
	 * @return
	 */
	public KineticConstraint getConstraint() {
		return getLink().getKineticParam().getConstraint();
	}

	
	/**
	 * 
	 * @return
	 */
	public double getKineticParam() {
		return getLink().getKineticParam().getVariable();
	}
	
	
	/**
	 * 
	 * @param variable
	 */
	public void setKineticParam(double variable) {
		getLink().setKineticParam(variable);
	}
	
	
	/**
	 * 
	 * @return
	 */
	public JointType getJointType() {
		return getLink().getKineticParam().getJointType();
	}



	@Override
	public void rotate(Vector3d angle, boolean update) {
		if (getJointType() != JointType.rot)
			return;
		
		if (angle.z == 0)
			angle.z = angle.x;
		angle.x = 0;
		angle.y = 0;
		
		double variable = getKineticParam();
		double fixValue = getConstraint().fixValue(variable + angle.z);
		angle.z = fixValue - variable; 
		
		super.rotate(angle, false);
		if (update)
			setKineticParam(variable + angle.z);
	}


	@Override
	public void translate(Vector3d trans, boolean update) {
		// TODO Auto-generated method stub
		if (getJointType() != JointType.trans)
			return;
		
		if (trans.z == 0)
			trans.z = trans.x;
		trans.x = 0;
		trans.y = 0;
		
		double variable = getKineticParam();
		double fixValue = getConstraint().fixValue(variable + trans.z);
		trans.z = fixValue - variable; 

		super.translate(trans, false);
		if (update)
			setKineticParam(variable + trans.z);
	}


}
