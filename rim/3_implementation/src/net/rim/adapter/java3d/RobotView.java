package net.rim.adapter.java3d;

import javax.media.j3d.Transform3D;
import javax.vecmath.Matrix4d;

import net.rim.core.Link;
import net.rim.core.Robot;
import net.rim.core.SceneObject;
import net.rim.core.ViewParam;
import net.rim.core.ViewParam.Mode;

/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class RobotView extends ViewImpl {

	
	/**
	 * 
	 * @param robot
	 */
	public RobotView(Robot robot) {
		super(robot);
		// TODO Auto-generated constructor stub
		
	}

	
	/**
	 * 
	 * @param robot
	 * @param viewParam
	 */
	public RobotView(Robot robot, ViewParam viewParam) {
		this(robot);
		this.viewParam = viewParam;
		compiling();
	}
	
	
	
	@Override
	public void compiling() {
		// TODO Auto-generated method stub
		
		removeAllSceneChildren();
		
		if (viewParam.getMode() == Mode.bone)
			setMoveable(true);
		else if (viewParam.getMode() == Mode.muscle)
			setMoveable(false);
		else if (viewParam.getMode() == Mode.body)
			setMoveable(true);
		
		int n = getRobot().getLinkCount();
		if (n > 0) {
			SceneObject base = this;
			for (int i = 0; i < n; i++) {
				Link link = getRobot().getLink(i);
				LinkView linkView = new LinkView(link, viewParam); 
				base.addSceneChild(linkView);
				
				base = linkView;
			}
		}
		
		setTransform(getRobot().getMatrix(), false);
	}


	/**
	 * 
	 * @return
	 */
	protected Robot getRobot() {
		return (Robot)model;
	}


	@Override
	public void setTransform(Matrix4d matrix, boolean update) {
		// TODO Auto-generated method stub
		super.setTransform(matrix, update);
		
		if (update)
			getRobot().setMatrix(tg.getMatrix());
	}
	
	
	
	@Override
	public void setTransform(Transform3D tf, boolean update) {
		// TODO Auto-generated method stub
		super.setTransform(tf, update);
		
		if (update)
			getRobot().setMatrix(tg.getMatrix());
	}


	
	
}
