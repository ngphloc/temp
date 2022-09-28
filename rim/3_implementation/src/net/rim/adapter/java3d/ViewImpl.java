package net.rim.adapter.java3d;

import net.rim.core.Model;
import net.rim.core.View;
import net.rim.core.ViewParam;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public abstract class ViewImpl extends SceneObjectImpl implements View {

	
	/**
	 * 
	 */
	protected Model model = null;
	
	
	/**
	 * 
	 */
	protected ViewParam viewParam = null;

	
	/**
	 * 
	 */
	public ViewImpl(Model model) {
		super();
		// TODO Auto-generated constructor stub
		this.model = model;
	}



	@Override
	public Model getModel() {
		// TODO Auto-generated method stub
		return model;
	}

	
	@Override
	public ViewParam getViewParam() {
		// TODO Auto-generated method stub
		return viewParam;
	}

	
	@Override
	public void setViewParam(ViewParam viewParam) {
		// TODO Auto-generated method stub
		this.viewParam = viewParam;
	}

	
}
