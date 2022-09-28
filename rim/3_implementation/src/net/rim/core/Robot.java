package net.rim.core;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

import javax.vecmath.Matrix4d;

/**
 * @author Administrator2
 * @version 1.0
 * @created 04-Sep-2012 10:23:29 AM
 */
public abstract class Robot extends Skeleton {
	
	/**
	 * 
	 */
	protected String id = "";
	
	
	/**
	 * 
	 */
	public Robot() {
		super();
		matrix.rotX(- Math.PI / 2);
	}

	
	/**
	 * 
	 * @return
	 */
	public int getDOF() {
		return getBoneCount() - 1;
	}

	
	/**
	 * 
	 * @return
	 */
	public String getId() {
		return "";
	}

	
	/**
	 * 
	 * @param id
	 */
	public void setId(String id) {
		this.id = id;
	}
	
	
	/**
	 * 
	 * @param link
	 */
	public void addLink(Link link) {
		Link lastLink = getLastLink();
		
		if (lastLink == null) {
			base = link;
			link.joint = null;
		}
		else {
			if (lastLink.getTool() != null)
				lastLink.setTool(null);
			lastLink.addChildBone(link);
			link.joint = lastLink;
		}
		
		link.robot = this;
	}

	
	/**
	 * 
	 * @param linkIndex
	 */
	public void removeLink(int linkIndex) {
		Link link = getLink(linkIndex);
		if (link == null)
			return;
		
		Link joint = (Link)link.joint;
		if (link.getChildBoneCount() == 0) {
			link.joint = null;
			joint.removeChildBone(link);
		}
		else {
			link.joint = null;
			
			Link nextLink = (Link) link.getChildBone(0);
			joint.addChildBone(nextLink);
		}
			
	}
	
	
	/**
	 * 
	 * @return
	 */
	public int getLinkCount() {
		return getBoneCount();
	}
	
	
	/**
	 * 
	 * @param linkIndex
	 * @return
	 */
	public Link getLink(int linkIndex) {
		int linkCount = getLinkCount();
		if (linkIndex < 0 || linkIndex >= linkCount)
			return null;
		
		Link link = (Link)base;
		int index = 0;
		while (index < linkIndex) {
			if (link.getChildBoneCount() == 0)
				return null;
			
			index ++;
			link = (Link)link.getChildBone(0);
		}
		
		return link;
	}

	
	/**
	 * 
	 * @return
	 */
	public List<Link> getLinks() {
		List<Link> links = new ArrayList<Link>();
		
		Link link = (Link)base;
		links.add(link);
		while (link.getChildBoneCount() > 0) {
			Link childLink = (Link) link.getChildBone(0);
			links.add(childLink);
			
			link = childLink;
		}
		return links;
	}
	
	
	/**
	 * 
	 * @return
	 */
	public Link getBaseLink() {
		return (Link)base;
	}
	
	
	/**
	 * 
	 * @return
	 */
	public Link getExecuteLink() {
		int linkCount = getLinkCount();
		if (linkCount < 2)
			return null;
		
		return getLink(linkCount - 1);
	}

	
	/**
	 * 
	 * @return
	 */
	public Link getLastLink() {
		int linkCount = getLinkCount();
		if (linkCount == 0)
			return null;
		
		return getLink(linkCount - 1);
	}
	
	
	/**
	 * 
	 * @param includeBaseMatrix
	 * @param includeToolMatrix
	 * @return
	 */
	public Matrix4d getLinkMatrix(
			boolean includeBaseMatrix, boolean includeToolMatrix) {
		Matrix4d m = new Matrix4d();
		m.setIdentity();
		List<Link> links = getLinks();
		for (Link link : links) {
			if (link.isBaseLink()) {
				if (includeBaseMatrix)
					m.mul(link.getMatrix());
			}
			else if (link.isExecuteLink()) {
				if (includeToolMatrix)
					m.mul(link.getWholeMatrix());
				else
					m.mul(link.getMatrix());
			}
			else
				m.mul(link.getMatrix());
				
		}
		
		return m;
	}

	
	/**
	 * 
	 * @param params
	 */
	public void setKineticParams(KineticParam[] params) {
		List<Link> links = getLinks();
		for (int i = 0; i < params.length; i++) {
			Link link = links.get(i);
			link.setKineticParam(params[i]);
		}
		
	}

	
	/**
	 * 
	 * @param variables
	 */
	public void setKineticParams(double[] variables) {
		List<Link> links = getLinks();
		for (int i = 0; i < variables.length; i++) {
			Link link = links.get(i);
			link.setKineticParam(variables[i]);
		}
		
	}
	
	
	/**
	 * 
	 */
	public void resetKineticParams() {
		List<Link> links = getLinks();
		for (int i = 0; i < links.size(); i++) {
			Link link = links.get(i);
			link.resetKineticParam();
		}
	}

	
	
	/**
	 * 
	 * @param file
	 */
	public void load(File file) {
		// TODO Auto-generated method stub
		
	}

	
	/**
	 * 
	 * @param file
	 */
	public void save(File file) {
		// TODO Auto-generated method stub
		
	}

}