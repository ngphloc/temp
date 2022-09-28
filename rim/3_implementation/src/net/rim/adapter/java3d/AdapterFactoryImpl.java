package net.rim.adapter.java3d;

import java.awt.Font;
import java.awt.GraphicsConfiguration;

import javax.media.j3d.Canvas3D;
import javax.media.j3d.Font3D;
import javax.media.j3d.FontExtrusion;
import javax.media.j3d.GeometryArray;
import javax.media.j3d.LineArray;
import javax.media.j3d.Shape3D;
import javax.media.j3d.Text3D;
import javax.vecmath.Color3f;
import javax.vecmath.Point3d;

import net.rim.core.AdapterFactory;
import net.rim.core.KineticParam;
import net.rim.core.KineticParamList;
import net.rim.core.Muscle;
import net.rim.core.Robot;
import net.rim.core.Scene;

import com.sun.j3d.utils.geometry.Box;
import com.sun.j3d.utils.geometry.ColorCube;
import com.sun.j3d.utils.geometry.Cone;
import com.sun.j3d.utils.geometry.Cylinder;
import com.sun.j3d.utils.geometry.Sphere;
import com.sun.j3d.utils.geometry.Text2D;
import com.sun.j3d.utils.universe.SimpleUniverse;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class AdapterFactoryImpl extends AdapterFactory {

	
	@Override
	public Scene createScene() {
		// TODO Auto-generated method stub
		
		GraphicsConfiguration config = SimpleUniverse.getPreferredConfiguration();
		Canvas3D canvas = new Canvas3D(config);		
		
		return new SceneImpl(canvas);
	}

	
	
	@Override
	public Muscle createLine(Point3d begin, Point3d end, Color3f color) {
		// TODO Auto-generated method stub
		LineArray lineArray = new LineArray(
				2, GeometryArray.COORDINATES | GeometryArray.COLOR_3);
		
		lineArray.setCoordinate(0, begin);
		lineArray.setColor(0, color);
		lineArray.setCoordinate(1, end);
		lineArray.setColor(1, color);
		
		MuscleImpl muscle = new MuscleImpl(new Shape3D(lineArray));
		return muscle;
	}



	@Override
	public Muscle createBar(Point3d begin, Point3d end, double width,
			Color3f color) {
		// TODO Auto-generated method stub
		return createLine(begin, end, color);
	}



	@Override
	public Muscle createEmpty() {
		MuscleImpl muscle = new MuscleImpl();
		return muscle;
	}
	
	
	@Override
	public Muscle createBox(double dx, double dy, double dz) {
		// TODO Auto-generated method stub
		
		MuscleImpl muscle = new MuscleImpl(
				new Box((float)dx, (float)dy, (float)dz, PRIM_FLAGS, null));
		return muscle;
	}

	
	
	@Override
	public Muscle createCube(double scale) {
		// TODO Auto-generated method stub
		
		MuscleImpl muscle = new MuscleImpl(
				new ColorCube(scale));
		return muscle;
	}

	
	@Override
	public Muscle createCone(double radius, double height) {
		// TODO Auto-generated method stub
		
		MuscleImpl muscle = new MuscleImpl(
				new Cone((float)radius, (float)height, PRIM_FLAGS, null));
		return muscle;
	}

	
	@Override
	public Muscle createCylinder(double radius, double height) {
		// TODO Auto-generated method stub
		
		MuscleImpl muscle = new MuscleImpl(
				new Cylinder((float)radius, (float)height, PRIM_FLAGS, null));
		return muscle;
	}

	
	
	@Override
	public Muscle createSphere(double radius) {
		// TODO Auto-generated method stub
		
		MuscleImpl muscle = new MuscleImpl(
				new Sphere((float)radius, PRIM_FLAGS, null));
		return muscle;
	}

	
	@Override
	public Muscle createText2d(
			String text, 
			Color3f color, 
			String fontName, 
			int fontSize, 
			int fontStyle) {
		
		// TODO Auto-generated method stub
		Text2D text2d = new Text2D(
				text, color, fontName, fontSize, fontStyle);
		
		MuscleImpl muscle = new MuscleImpl(text2d);
		return muscle;
	}

	
	
	@Override
	public Muscle createText3d(String text, Font font) {
		// TODO Auto-generated method stub
		Font3D font3d = new Font3D(font, new FontExtrusion());
		Text3D text3d = new Text3D(font3d, text);
		
		MuscleImpl muscle = new MuscleImpl(new Shape3D(text3d));
		return muscle;
	}

	
	@Override
	public Robot createRobot(KineticParamList paramList) {
		RobotImpl robot = new RobotImpl();
		for (int i = 0; i < paramList.size(); i++) {
			KineticParam kineticParam = paramList.get(i);
			LinkImpl link = new LinkImpl(kineticParam);
			robot.addLink(link);
		}
		
		return robot;
	}

	
}
