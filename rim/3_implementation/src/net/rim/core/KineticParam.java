package net.rim.core;

import javax.vecmath.AxisAngle4d;
import javax.vecmath.Matrix4d;

/**
 * @author Administrator2
 * @version 1.0
 * @created 04-Sep-2012 10:23:17 AM
 */
public class KineticParam implements Cloneable {

	/**
	 * 
	 * @author Administrator2
	 * @version 1.0
	 *
	 */
	public static enum JointType { trans, rot }
	
	
	/**
	 * 
	 */
	public double A = 0;
	
	
	/**
	 * 
	 */
	public double Alpha = 0;
	
	
	/**
	 * 
	 */
	public double D = 0;
	
	
	/**
	 * 
	 */
	public double Theta = 0;


	/**
	 * 
	 */
	protected JointType jointType = JointType.trans;
	

	/**
	 * 
	 */
	protected KineticConstraint constraint = null;
	
	
	/**
	 * 
	 */
	public KineticParam(JointType jointType, double variable) {
		this.jointType = jointType;
		
		switch (jointType) {
		case trans:
			constraint = new MinMaxKineticConstraint(0, variable);
			break;
		case rot:
			constraint = new MinMaxKineticConstraint(0, 2 * Math.PI);
			break;
		}
		
		setVariable(variable);
	}

	

	
	/**
	 * 
	 * @return
	 */
	public JointType getJointType(){
		return jointType;
	}

	
	/**
	 * 
	 * @return
	 */
	public KineticConstraint getConstraint() {
		return constraint;
	}
	
	
	/**
	 * 
	 * @param constraint
	 */
	public void setKineticConstraint(KineticConstraint constraint) {
		this.constraint = constraint;
	}
	
	
	/**
	 * 
	 * @return
	 */
	public double getVariable() {
		switch (jointType) {
		case trans:
			return D;
		case rot:
			return Theta;
		}
		
		return A;
	}
	
	
	/**
	 * 
	 * @param variable
	 */
	public void setVariable(double variable) {
		variable = constraint.fixValue(variable);
		
		switch (jointType) {
		case trans:
			D = variable;
			break;
		case rot:
			Theta = variable;
			break;
		}
	}


	/**
	 * 
	 * @param matrix
	 */
	public void setVariable(Matrix4d matrix) {
		double variable = 0;
		
		switch (jointType) {
		case trans:
			variable = matrix.m23;
			break;
		case rot:
			AxisAngle4d axis = new AxisAngle4d();
			axis.set(matrix);
			variable = axis.getAngle();
			break;
		}
		
		setVariable(variable);
	}
	
	
	
	@Override
	public Object clone() {
		KineticParam param = new KineticParam(this.jointType, getVariable());
		param.A = this.A;
		param.Alpha = this.Alpha;
		param.D = this.D;
		param.Theta = this.Theta;
		param.constraint = (KineticConstraint) this.constraint.clone();
		
		return param;
	}
	
	
	/**
	 * 
	 * @return
	 */
	public Matrix4d createMatrix(){
		Matrix4d matrix = new Matrix4d();
	
		matrix.m00 = Math.cos(Theta);
		matrix.m01 = -Math.sin(Theta) * Math.cos(Alpha);
		matrix.m02 = Math.sin(Theta) * Math.sin(Alpha);
		matrix.m03 = A * Math.cos(Theta);
		
		matrix.m10 = Math.sin(Theta);
		matrix.m11 = Math.cos(Theta) * Math.cos(Alpha);
		matrix.m12 = -Math.cos(Theta) * Math.sin(Alpha);
		matrix.m13 = A * Math.sin(Theta);

		matrix.m20 = 0;
		matrix.m21 = Math.sin(Alpha);
		matrix.m22 = Math.cos(Alpha);
		matrix.m23 = D;

		matrix.m30 = 0;
		matrix.m31 = 0;
		matrix.m32 = 0;
		matrix.m33 = 1;

		return matrix;
	}

	
	
	/**
	 * 
	 * @param high
	 * @return
	 */
	public static KineticParam create(double high) {
		KineticParam param = new KineticParam(JointType.trans, high);
		
		return param;
	}
	

	
	/**
	 * 
	 * @param jointType
	 * @param a
	 * @param alpha
	 * @param d
	 * @param theta
	 */
	public static KineticParam create(
			JointType jointType, double a, double alpha, double d, double theta) {
		
		KineticParam param = null;
		switch (jointType) {
		case trans:
			param = new KineticParam(jointType, d);
			break;
		case rot:
			param = new KineticParam(jointType, theta);
			break;
		}
		
		param.A = a;
		param.Alpha = alpha;
		param.D = d;
		param.Theta = theta;
		
		return param;
	}

	
	
}