package net.rim.core;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

/**
 * @author Administrator2
 * @version 1.0
 * @created 04-Sep-2012 10:23:25 AM
 */
public abstract class Program {

	
	/**
	 * 
	 */
	protected List<Instruction> instructions = new ArrayList<Instruction>();


	/**
	 * 
	 */
	public Program() {

	}

	
	/**
	 * 
	 * @param instruction
	 */
	public void addInstruction(Instruction instruction) {
		instructions.add(instruction);
	}

	
	/**
	 * 
	 * @return
	 */
	public int getInstructionCount(){
		return instructions.size();
	}

	
	
	/**
	 * 
	 * @param file
	 */
	public abstract void load(File file);

	
	
	/**
	 * 
	 * @param instructionIndex
	 */
	public void removeInstruction(int instructionIndex) {
		instructions.remove(instructionIndex);
	}

	
	/**
	 * 
	 * @param file
	 */
	public abstract void save(File file);
	

}