package com.tvhms.util;

import java.awt.Component;
import java.awt.Dialog;
import java.awt.Frame;
import java.awt.Window;
import java.awt.event.ActionListener;
import java.net.URL;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JMenuItem;


/**
 * 
 * @author Admin
 * @version 2.0
 */
public final class Util {

	
	/**
	 * 
	 * @param iconURL
	 * @param cmd
	 * @param tooltip
	 * @param alt
	 * @param listener
	 * @return
	 */
	public static JButton makeIconButton(URL iconURL, String cmd, String tooltip, String alt, 
			ActionListener listener) {
		JButton button = new JButton();
	    button.setActionCommand(cmd);
	    button.setToolTipText(tooltip);
	    button.addActionListener(listener);
	
	    if (iconURL != null) {
	        button.setIcon(new ImageIcon(iconURL, alt));
	    }
	    else {  //no image found
	        button.setText(alt);
	    }
	
	    return button;
	}

	
	
	/**
	 * 
	 * @param iconURL
	 * @param text
	 * @param listener
	 * @return
	 */
	public static JMenuItem makeMenuItem(URL iconURL, String text, ActionListener listener) {
		JMenuItem item = new JMenuItem(text);
		item.addActionListener(listener);
		
	    if (iconURL != null) {
	        item.setIcon(new ImageIcon(iconURL, text));
	    }
	
	    return item;
	}

	
	
	/**
	 * 
	 * @param comp
	 * @return
	 */
	public static Window getWindowForComponent(Component comp) {
	    if (comp == null)
	        return null;
	    if (comp instanceof Frame || comp instanceof Dialog)
	        return (Window)comp;
	    return getWindowForComponent(comp.getParent());
	}

	
	
	/**
	 * 
	 * @param comp
	 * @return
	 */
	public static Frame getFrameForComponent(Component comp) {
	    if (comp == null)
	        return null;
	    if (comp instanceof Frame)
	        return (Frame)comp;
	    return getFrameForComponent(comp.getParent());
	}

	

	/**
	 * 
	 * @param text
	 * @return
	 */
	public static String md5Encrypt(String text) {
		try {
			MessageDigest md = MessageDigest.getInstance("MD5");
			byte[] digest = md.digest(text.getBytes());
			StringBuffer buffer = new StringBuffer();
			for (Byte c : digest)
				buffer.append(c.toString());
			
			return buffer.toString();
		} 
		catch (NoSuchAlgorithmException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return null;
	}
	

}
