/**
 * 
 */
package com.tvhms.ui;

import javax.swing.JTextField;

/**
 * @author Administrator2
 * @version 3.0
 *
 */
public class TagTextField extends JTextField {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 */
	protected Object tag_ = null;
	
	
	/**
	 * 
	 */
	public TagTextField() {
		super();
	}
	
	
	/**
	 * 
	 * @return
	 */
	public Object getTag() {
		return tag_;
	}
	
	
	/**
	 * 
	 * @param tag
	 */
	public void setTag(Object tag) {
		this.tag_ = tag;
		this.setTag(tag.toString());
	}
	
	
//	/**
//	 * 
//	 * @param text
//	 * @param tag
//	 */
//	public void setText(String text, Object tag) {
//		super.setText(text);
//		this.tag_ = tag;
//	}
	
	
	
}
