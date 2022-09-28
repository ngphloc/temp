package net.rim.adapter.java3d;

import javax.media.j3d.BoundingSphere;
import javax.media.j3d.BranchGroup;
import javax.media.j3d.Canvas3D;
import javax.media.j3d.Group;
import javax.media.j3d.TransformGroup;
import javax.vecmath.Point3d;

import net.rim.core.Scene;
import net.rim.core.SceneObject;

import com.sun.j3d.utils.behaviors.keyboard.KeyNavigatorBehavior;
import com.sun.j3d.utils.universe.SimpleUniverse;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class SceneImpl extends SimpleUniverse implements Scene {

	
	/**
	 * 
	 */
	protected BranchGroup sceneGroup = null;
	
	
	/**
	 * 
	 */
	protected Group behaviorGroup = null;
	
	
	/**
	 * 
	 */
	protected BranchGroup objGroup = null;

	
	/**
	 * 
	 * @param canvas
	 */
	public SceneImpl(Canvas3D canvas) {
		super(canvas);
		
		getViewingPlatform().setNominalViewingTransform();
		//getViewer().getView().setMinimumFrameCycleTime(5);

		sceneGroup = new BranchGroup();
		sceneGroup.setCapability(Group.ALLOW_CHILDREN_READ);
		sceneGroup.setCapability(Group.ALLOW_CHILDREN_WRITE);
		sceneGroup.setCapability(Group.ALLOW_CHILDREN_EXTEND);
		
		behaviorGroup = new Group();
		PickHolderImpl pickHolder = new PickHolderImpl(
				sceneGroup, canvas, new BoundingSphere(new Point3d(), 100));
		behaviorGroup.addChild(pickHolder);
		
		//PickRotator pickRotator = new PickRotator(
		//		sceneGroup, canvas, new BoundingSphere());
		//behaviorGroup.addChild(pickRotator);
		//
		//PickTranslater pickTranslator = new PickTranslater(
		//		sceneGroup, canvas, new BoundingSphere());
		//behaviorGroup.addChild(pickTranslator);
		//
		//PickZoomer pickZoomer = new PickZoomer(
		//		sceneGroup, canvas, new BoundingSphere());
		//behaviorGroup.addChild(pickZoomer);
		//
		//PickProperty pickProperty = new PickProperty(
		//		sceneGroup, canvas, new BoundingSphere());
		//behaviorGroup.addChild(pickProperty);
		//
		//PickScaler pickScaler = new PickScaler(
		//		sceneGroup, canvas, new BoundingSphere());
		//behaviorGroup.addChild(pickScaler);
		//
		TransformGroup tgView = getViewingPlatform().getViewPlatformTransform();
		KeyNavigatorBehavior keyBehavior = new KeyNavigatorBehavior(tgView);
		keyBehavior.setSchedulingBounds(new BoundingSphere(new Point3d(), 1000));
		behaviorGroup.addChild(keyBehavior);
		//
		sceneGroup.addChild(behaviorGroup);
		
		objGroup = new BranchGroup();
		objGroup.setCapability(Group.ALLOW_CHILDREN_READ);
		objGroup.setCapability(Group.ALLOW_CHILDREN_WRITE);
		objGroup.setCapability(Group.ALLOW_CHILDREN_EXTEND);
		sceneGroup.addChild(objGroup);
		
		sceneGroup.compile();
		addBranchGraph(sceneGroup);
	}
	
	
	@Override
	public void addSceneObject(SceneObject object) {
		// TODO Auto-generated method stub
		objGroup.addChild((SceneObjectImpl)object);
	}

	
	@Override
	public int getSceneObjectCount() {
		// TODO Auto-generated method stub
		return objGroup.numChildren();
	}

	
	@Override
	public void removeSceneObject(int index) {
		// TODO Auto-generated method stub
		objGroup.removeChild(index);
	}

	
	@Override
	public void removeSceneObject(SceneObject object) {
		// TODO Auto-generated method stub
		
		for (int i = 0; i < getSceneObjectCount(); i++) {
			SceneObject o = getSceneObject(i);
			if (o == object) {
				removeSceneObject(i);
				return;
			}
				
		}
	}


	@Override
	public SceneObject getSceneObject(int index) {
		return (SceneObject)objGroup.getChild(index);
	}
	
	
	
	
	
	
}
