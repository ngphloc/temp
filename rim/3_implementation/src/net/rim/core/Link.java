package net.rim.core;


import javax.vecmath.Matrix4d;

/**
 * @author Administrator2
 * @version 1.0
 * @created 04-Sep-2012 10:23:20 AM
 */
public abstract class Link extends Bone {

	/**
	 * 
	 */
	protected KineticParam defaultKineticParam = null;
	
	
	/**
	 * 
	 */
	protected KineticParam kineticParam = null;
	
	
	/**
	 * 
	 */
	protected DynamicParam dynamicParam = new DynamicParam();

	
	/**
	 * 
	 */
	protected Robot robot = null;
	
	
	/**
	 * 
	 */
	protected Tool tool = null;

	
	/**
	 * 
	 * @param kineticParam
	 */
	public Link(KineticParam kineticParam) {
		this.defaultKineticParam = (KineticParam)kineticParam.clone();
		this.kineticParam = kineticParam;
		this.matrix = kineticParam.createMatrix();
	}

	
	/**
	 * 
	 * @param high
	 */
	public Link(double high) {
		this(KineticParam.create(high));
		// TODO Auto-generated constructor stub
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	public int getIndex() {
		return getLevel();
	}

	
	/**
	 * 
	 * @return
	 */
	public KineticParam getKineticParam() {
		return kineticParam;
	}

	
	/**
	 * 
	 * @param kineticParam
	 */
	public void setKineticParam(KineticParam kineticParam) {
		this.kineticParam = kineticParam;
		this.matrix = kineticParam.createMatrix();
	}

	
	/**
	 * 
	 * @param variable
	 */
	public void setKineticParam(double variable) {
		this.kineticParam.setVariable(variable);
		this.matrix = kineticParam.createMatrix();
	}

	
	/**
	 * 
	 * @param matrix
	 */
	public void setKineticParam(Matrix4d matrix) {
		this.kineticParam.setVariable(matrix);
		this.matrix = kineticParam.createMatrix();
	}

	
	/**
	 * 
	 * @return
	 */
	public KineticParam getDefaultKineticParam() {
		return defaultKineticParam;
	}

	
	/**
	 * 
	 */
	public void resetKineticParam() {
		setKineticParam(defaultKineticParam);
	}
	
	
	/**
	 * 
	 * @return
	 */
	public Matrix4d getMatrixFromBase() {
		if (robot == null)
			return matrix;
		
		Matrix4d m = new Matrix4d(robot.getLink(0).getMatrix());
		int index = getIndex();
		for (int i = 1; i <= index; i++) {
			m.mul(robot.getLink(i).getMatrix());
		}
		
		return m;
	}

	
	
	/**
	 * 
	 * @param otherLinkIndex
	 */
	public Matrix4d getMatrix(int otherLinkIndex) {
		if (robot == null)
			return matrix;
		
		int index = getIndex();
		int min = Math.min(index, otherLinkIndex);
		int max = Math.max(index, otherLinkIndex);
		Matrix4d m = new Matrix4d();
		m.setIdentity();
		if (min == max)
			return m;
		
		for (int i = min + 1; i <= max; i++)
			m.mul(robot.getLink(i).getMatrix());
		return null;
	}


	/**
	 * @return
	 */
	public Matrix4d getWholeMatrix() {
		Matrix4d m = new Matrix4d(matrix);
		if (tool != null)
			m.mul(tool.getMatrix());
		
		return m;
	}

	
	/**
	 * 
	 * @return
	 */
	public Matrix4d getWholeMatrixFromBase() {
		Matrix4d m = getMatrixFromBase();
		if (tool != null)
			m.mul(tool.getMatrix());
		
		return m;
	}


	/**
	 * 
	 * @return
	 */
	public int getMuscleCount() {
		return muscles.size();
	}

	
	/**
	 * 
	 * @return
	 */
	public Link getNextLink() {
		if (robot == null || isExecuteLink())
			return null;
		
		int index = getIndex();
		return robot.getLink(index + 1);
	}

	
	/**
	 * 
	 * @return
	 */
	public Link getPreLink() {
		int index = getIndex();
		if (robot == null || index == 0)
			return null;
		
		return robot.getLink(index - 1);
	}

	
	/**
	 * 
	 * @return
	 */
	public Tool getTool() {
		return tool;
	}

	
	/**
	 * 
	 * @param tool
	 */
	public void setTool(Tool tool) {
		this.tool = null;
	}

	
	/**
	 * 
	 * @return
	 */
	public Matrix4d getToolMatrix() {
		Matrix4d m = new Matrix4d();
		m.setIdentity();
		if (tool != null) 
			m = tool.getMatrix();
		
		return m;
	}

	
	/**
	 * 
	 * @return
	 */
	public Robot getRobot() {
		return robot;
	}
	
	
	/**
	 * 
	 * @return
	 */
	public boolean isExecuteLink() {
		if (robot == null)
			return tool != null;
		else {
			int linkCount = robot.getLinkCount();
			if (linkCount < 2)
				return false;
			else
				return getIndex() == linkCount - 1;
		}
	}

	
	/**
	 * 
	 * @return
	 */
	public boolean isBaseLink() {
		return getIndex() == 0 && tool == null;
	}
	
	
	@Override
	public Matrix4d getCoordSystem() {
		if (robot == null) {
			Matrix4d m = new Matrix4d();
			m.setIdentity();
			return m;
		}
		
		int index = getIndex();
		if (index == 0)
			return robot.getMatrix();
		else
			return robot.getLink(index - 1).getMatrix();
	}
	
	
	
	@Override
	public Matrix4d getAbsCoordSystem() {
		Matrix4d m = new Matrix4d();
		m.setIdentity();
		if (robot != null)
			m.mul(robot.getMatrix());
		
		m.mul(getMatrixFromBase());
		
		return m;
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	public DynamicParam getDynamicParam() {
		return dynamicParam;
	}

	
	/**
	 * 
	 * @param dynamicParam
	 */
	public void setDynamicParam(DynamicParam dynamicParam) {
		this.dynamicParam = dynamicParam;
	}
	
	
	
}