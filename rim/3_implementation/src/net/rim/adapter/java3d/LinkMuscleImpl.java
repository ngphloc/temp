package net.rim.adapter.java3d;

import net.rim.core.Link;
import net.rim.core.LinkMuscle;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class LinkMuscleImpl extends BoneMuscleImpl implements LinkMuscle {

	/**
	 * 
	 * @param link
	 */
	public LinkMuscleImpl(Link link) {
		super(link);
		// TODO Auto-generated constructor stub
	}

	
	/**
	 * 
	 * @param link
	 * @param updateLocalSystem
	 */
	public LinkMuscleImpl(Link link, boolean updateLocalSystem) {
		super(link, updateLocalSystem);
		// TODO Auto-generated constructor stub
	}

	
	
	@Override
	public Link getLink() {
		// TODO Auto-generated method stub
		return (Link)bone;
	}

	
	/**
	 * 
	 * @param link
	 * @param updateLocalSystem
	 */
	public void setLink(Link link, boolean updateLocalSystem) {
		setBone(link, updateLocalSystem);
	}

	
	
}
