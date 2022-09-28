package net.rim.adapter.java3d;

import javax.media.j3d.Transform3D;
import javax.vecmath.Matrix4d;

import net.rim.core.Tool;
import net.rim.core.ViewParam;
import net.rim.core.ViewParam.Mode;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class ToolView extends ViewImpl {
	
	
	/**
	 * 
	 * @param tool
	 */
	public ToolView(Tool tool) {
		super(tool);
		// TODO Auto-generated constructor stub
		
		this.model = tool;
		
	}

	
	/**
	 * 
	 * @param tool
	 * @param viewParam
	 */
	public ToolView(Tool tool, ViewParam viewParam) {
		this(tool);
		// TODO Auto-generated constructor stub
		setViewParam(viewParam);
		compiling();
	}

	
	@Override
	public void setTransform(Matrix4d matrix, boolean update) {
		// TODO Auto-generated method stub
		super.setTransform(matrix, update);
		
		if (update)
			getTool().setMatrix(tg.getMatrix());
	}
	
	
	@Override
	public void setTransform(Transform3D tf, boolean update) {
		// TODO Auto-generated method stub
		super.setTransform(tf, update);
		
		if (update)
			getTool().setMatrix(tg.getMatrix());
	}


	@Override
	public void compiling() {
		// TODO Auto-generated method stub
		removeAllSceneChildren();
		
		if (viewParam.getMode() == Mode.bone) {
			setMoveable(true);
			
			for (int i = 0; i < getTool().getMuscleCount(); i++) {
				MuscleImpl muscle = (MuscleImpl) getTool().getMuscle(i);
				muscle.setMoveable(false);
				addSceneChild(muscle);
			}
		}
		else if (viewParam.getMode() == Mode.muscle) {
			setMoveable(false);
			
			for (int i = 0; i < getTool().getMuscleCount(); i++) {
				MuscleImpl muscle = (MuscleImpl) getTool().getMuscle(i);
				muscle.setMoveable(true);
				addSceneChild(muscle);
			}
		}
		else if (viewParam.getMode() == Mode.body) {
			setMoveable(true);
			
			for (int i = 0; i < getTool().getMuscleCount(); i++) {
				MuscleImpl muscle = (MuscleImpl) getTool().getMuscle(i);
				muscle.setMoveable(false);
				addSceneChild(muscle);
			}
		}
		
		Matrix4d matrix = getTool().getMatrix();
		setTransform(matrix, false);
		
	}


	/**
	 * 
	 * @return
	 */
	protected Tool getTool() {
		return (Tool)model;
	}
	


}
