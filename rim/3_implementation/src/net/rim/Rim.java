package net.rim;

import net.rim.cad.CadPlus;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class Rim {

	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		java.awt.EventQueue.invokeLater(new Runnable() {
			
        	public void run() {
            	new CadPlus().setVisible(true);
            }
        });	
	}

}
