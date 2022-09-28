package net.rim.adapter.java3d;

import net.rim.core.Tool;
import net.rim.core.ToolMuscle;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class ToolMuscleImpl extends BoneMuscleImpl implements ToolMuscle {

	
	/**
	 * 
	 * @param tool
	 * @param updateLocalSystem
	 */
	public ToolMuscleImpl(Tool tool, boolean updateLocalSystem) {
		super(tool, updateLocalSystem);
		// TODO Auto-generated constructor stub
	}


	/**
	 * 
	 * @param tool
	 */
	public ToolMuscleImpl(Tool tool) {
		super(tool);
		// TODO Auto-generated constructor stub
	}
	
	
	
	@Override
	public Tool getTool() {
		// TODO Auto-generated method stub
		return (Tool)bone;
	}

	
	
	/**
	 * 
	 * @param tool
	 * @param updateLocalSystem
	 */
	public void setTool(Tool tool, boolean updateLocalSystem) {
		setBone(tool, updateLocalSystem);
	}

	
	
}
