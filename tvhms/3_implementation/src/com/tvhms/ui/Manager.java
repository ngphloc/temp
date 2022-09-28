package com.tvhms.ui;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JTabbedPane;
import javax.swing.KeyStroke;

public class Manager extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	
	/**
	 * 
	 */
	private RoomPane roomPane = null;
	
	
	/**
	 * 
	 */
	private RoomStatPane roomStatPane = null;

	
	/**
	 * 
	 */
	private ServiceStatPane serviceStatPane = null;

	
	/**
	 * 
	 */
	private AccountPane accPane = null;

	
	/**
	 * 
	 */
	public Manager() {
		super("Hotel Manager");
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		setSize(800, 600);
		addWindowListener(new WindowAdapter() {

			@Override
			public void windowClosed(WindowEvent e) {
				// TODO Auto-generated method stub
				new Login();
			}
			
		});
		setJMenuBar(createMenuBar());
		
		Container content = getContentPane();
		content.setLayout(new BorderLayout(2, 2));
		
		JTabbedPane body = new JTabbedPane();
		content.add(body, BorderLayout.CENTER);
		
		roomPane = new RoomPane();
		body.add("Room", roomPane);
		
		roomStatPane = new RoomStatPane();
		body.add("Room statistic", roomStatPane);
		
		serviceStatPane = new ServiceStatPane();
		body.add("Service statistic", serviceStatPane);

		accPane = new AccountPane();
		body.add("Account", accPane);

		setLocationRelativeTo(null);
		setVisible(true);
	}
	
	
	/**
	 * 
	 * @return
	 */
	private JMenuBar createMenuBar() {
		JMenuBar mnuBar = new JMenuBar();
		
		JMenu mnuTool = new JMenu("Tool");
		mnuTool.setMnemonic('T');
		mnuBar.add(mnuTool);
		
		JMenuItem mniConfig = new JMenuItem("Configure");
		mniConfig.setMnemonic('C');
		mniConfig.setAccelerator(KeyStroke.getKeyStroke(
				KeyEvent.VK_C, InputEvent.CTRL_DOWN_MASK));
		mniConfig.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				new ConfigDlg(getThis());
				refresh();
			}
		});
		mnuTool.add(mniConfig);
		
		return mnuBar;
	}


	/**
	 * 
	 * @return
	 */
	private Manager getThis() {
		return this;
	}
	
	
	/**
	 * 
	 */
	public void refresh() {
		if (roomPane != null)
			roomPane.refresh();
		
		if (roomStatPane != null)
			roomStatPane.refresh();
		
		if (serviceStatPane != null)
			serviceStatPane.refresh();

		if (accPane != null)
			accPane.refresh();
	}
	
}
