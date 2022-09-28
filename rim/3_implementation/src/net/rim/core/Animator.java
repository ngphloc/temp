package net.rim.core;


public abstract class Animator {

	/**
	 * 
	 */
	protected SceneObject target = null;
	
	
	/**
	 * 
	 */
	protected long msElapse = 0;

	
	/**
	 * 
	 * @param target
	 * @param msElapse
	 */
	public Animator(SceneObject target, 
			long msElapse) {
		this.target = target;
		this.msElapse = msElapse;
	}
	
	
	/**
	 * 
	 */
	public abstract void start();
	
	
	/**
	 * 
	 */
	public abstract void stop();
	
	
	
	/**
	 * 
	 */
	protected abstract void transformChanged();
	
	
	/**
	 * 
	 */
	public abstract void pause();
	
	
	/**
	 * 
	 */
	public abstract void resume();

	
	/**
	 * 
	 * @return
	 */
	public abstract boolean isStarted();
	
	
	/**
	 * 
	 * @return
	 */
	public abstract boolean isRunning();


}
