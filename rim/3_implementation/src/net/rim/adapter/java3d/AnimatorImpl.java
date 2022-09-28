package net.rim.adapter.java3d;

import javax.media.j3d.Alpha;
import javax.media.j3d.Interpolator;

import net.rim.core.Animator;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public abstract class AnimatorImpl extends Animator {

	/**
	 * 
	 */
	protected Interpolator interpolator = null;

	
	/**
	 * 
	 * @param target
	 * @param msElapse
	 */
	public AnimatorImpl(SceneObjectImpl target, long msElapse) {
		super(target, msElapse);
	}
	
	
	/**
	 * 
	 */
	public synchronized void start() {
		if (isStarted())
			return;
		
		SceneObjectImpl obj = (SceneObjectImpl)target;
		
		interpolator = createInterpolator();
		interpolator.setBounds(obj.getBounds());
		interpolator.setAlpha(new Alpha(1, msElapse));
		
		obj.addChild(interpolator);
	}
	
	
	/**
	 * 
	 * @return
	 */
	protected abstract Interpolator createInterpolator();
	
	
	/**
	 * 
	 */
	public synchronized void stop() {
		if (!isStarted())
			return;

		SceneObjectImpl obj = (SceneObjectImpl)target;

		interpolator.setAlpha(null);
		interpolator.setEnable(false);
		obj.removeChild(interpolator);
		interpolator = null;
	}

	
	/**
	 * 
	 */
	protected synchronized void transformChanged() {
		if (!isStarted())
			return;
		
		Alpha alpha = interpolator.getAlpha();
		if (alpha == null || alpha.finished())
			stop();
	}
	
	
	/**
	 * 
	 */
	public synchronized void pause() {
		if (!isRunning())
			return;
		
		Alpha alpha = interpolator.getAlpha();
		if (alpha != null && !alpha.finished())
			alpha.pause();
	}
	
	
	/**
	 * 
	 */
	public synchronized void resume() {
		if (isRunning())
			return;
		
		Alpha alpha = interpolator.getAlpha();
		if (alpha != null && !alpha.finished())
			alpha.resume();
	}

	
	/**
	 * 
	 * @return
	 */
	public synchronized boolean isStarted() {
		return interpolator != null;
	}
	
	
	/**
	 * 
	 * @return
	 */
	public synchronized boolean isRunning() {
		return isStarted() && 
				interpolator.getAlpha() != null &&
				!interpolator.getAlpha().finished() &&
				!interpolator.getAlpha().isPaused();
	}



}
