package net.rim.core;

import java.awt.Font;

import javax.vecmath.Color3f;
import javax.vecmath.Point3d;

import com.sun.j3d.utils.geometry.Primitive;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public abstract class AdapterFactory {
	
	/**
	 * 
	 */
	protected final static int PRIM_FLAGS = 
		Primitive.GENERATE_NORMALS | 
		Primitive.GENERATE_TEXTURE_COORDS |
		Primitive.ENABLE_APPEARANCE_MODIFY;
	
	
	/**
	 * 
	 * @return
	 */
	public abstract Scene createScene();
	
	
	/**
	 * 
	 * @return
	 */
	public abstract Muscle createEmpty();
	
	
	/**
	 * 
	 * @param begin
	 * @param end
	 * @param color
	 * @return
	 */
	public abstract Muscle createLine(
			Point3d begin, Point3d end, Color3f color);

	
	/**
	 * 
	 * @param begin
	 * @param end
	 * @param width
	 * @param color
	 * @return
	 */
	public abstract Muscle createBar(
			Point3d begin, Point3d end, double width, Color3f color);

	
	/**
	 * 
	 * @param dx
	 * @param dy
	 * @param dz
	 * @return
	 */
	public abstract Muscle createBox(double dx, double dy, double dz);
	

	/**
	 * 
	 * @param scale
	 * @return
	 */
	public abstract Muscle createCube(double scale);
	
	
	/**
	 * 
	 * @param radius
	 * @param height
	 * @return
	 */
	public abstract Muscle createCone(double radius, double height);
	
	
	/**
	 * 
	 * @param radius
	 * @param height
	 * @return
	 */
	public abstract Muscle createCylinder(double radius, double height);
	
	
	/**
	 * 
	 * @param radius
	 * @return
	 */
	public abstract Muscle createSphere(double radius);
	

	/**
	 * 
	 * @param text
	 * @param color
	 * @param fontName
	 * @param fontSize
	 * @param fontStyle
	 * @return
	 */
	public abstract Muscle createText2d(
			String text, 
			Color3f color, 
			String fontName, 
			int fontSize, 
			int fontStyle);
	
	
	/**
	 * 
	 * @param text
	 * @param font
	 * @return
	 */
	public abstract Muscle createText3d(String text, Font font);
	
	
	/**
	 * 
	 * @param paramList
	 * @return
	 */
	public abstract Robot createRobot(KineticParamList paramList);
}
