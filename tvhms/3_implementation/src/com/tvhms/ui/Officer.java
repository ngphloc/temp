package com.tvhms.ui;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JFrame;
import javax.swing.JTabbedPane;

public class Officer extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 */
	private EnterReservePane paneEnterReserve = null;
	
	
	/**
	 * 
	 */
	public Officer() {
		super("Entering data");
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		setSize(800, 700);
		addWindowListener(new WindowAdapter() {

			@Override
			public void windowClosing(WindowEvent e) {
				// TODO Auto-generated method stub
				if (paneEnterReserve != null)
					paneEnterReserve.clear();
			}

			@Override
			public void windowClosed(WindowEvent e) {
				// TODO Auto-generated method stub
				new Login();
			}
			
		});
		
		Container content = getContentPane();
		content.setLayout(new BorderLayout(2, 2));
		
		JTabbedPane body = new JTabbedPane();
		content.add(body, BorderLayout.CENTER);
		
		paneEnterReserve = new EnterReservePane();
		body.add("Reservation", paneEnterReserve);
		
		setLocationRelativeTo(null);
		setVisible(true);
	}
	
	
}
