package net.rim.adapter.java3d;

import java.awt.Color;

import javax.media.j3d.LineArray;
import javax.media.j3d.Shape3D;
import javax.vecmath.Color3f;
import javax.vecmath.Point3f;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class Axises extends MuscleImpl {

	
	/**
	 * 
	 */
	public Axises() {
		super();
		// TODO Auto-generated constructor stub
		
		init();
	}



	
	/**
	 * 
	 */
	private void init() {
		LineArray lines = new LineArray(6, 
				LineArray.COORDINATES | LineArray.COLOR_3);
		
		lines.setCoordinate(0, new Point3f(0, 0, 0));
		lines.setColor(0, new Color3f(Color.red));
		lines.setCoordinate(1, new Point3f(0.05f, 0, 0));
		lines.setColor(1, new Color3f(Color.red));
		
		lines.setCoordinate(2, new Point3f(0, 0, 0));
		lines.setColor(2, new Color3f(Color.green));
		lines.setCoordinate(3, new Point3f(0, 0.05f, 0));
		lines.setColor(3, new Color3f(Color.green));
		
		lines.setCoordinate(4, new Point3f(0, 0, 0));
		lines.setColor(4, new Color3f(Color.blue));
		lines.setCoordinate(5, new Point3f(0, 0, 0.05f));
		lines.setColor(5, new Color3f(Color.blue));
		
		setShape(new Shape3D(lines));
	}
	
	
	
}
