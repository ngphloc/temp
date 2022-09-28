package com.tvhms.ui;

import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;

import com.tvhms.util.Util;

public class ConfigDlg extends JDialog {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	
	/**
	 * 
	 */
	ConfigDBTable tblConfig = null;
	
	
	/**
	 * 
	 */
	RoomTypeDBTable tblRoomType = null;

	
	
	/**
	 * 
	 */
	RoomDBTable tblRoom = null;

	
	/**
	 * 
	 */
	ServiceDBTable tblService = null;

	
	
	/**
	 * 
	 */
	public ConfigDlg(Component comp) {
		super(Util.getFrameForComponent(comp), "Configuration", true);
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		setSize(600, 400);
		addWindowListener(new WindowAdapter() {

			@Override
			public void windowClosed(WindowEvent e) {
				// TODO Auto-generated method stub
				try {
					if (tblConfig != null)
						tblConfig.close();
					
					if (tblRoomType != null)
						tblRoomType.close();
					
					if (tblService != null)
						tblService.close();
				} 
				catch (Exception ex) {
					// TODO Auto-generated catch block
					ex.printStackTrace();
				}
			}
			
		});
		setLayout(new BorderLayout());
		
		JPanel header = new JPanel(new FlowLayout(FlowLayout.RIGHT));
		add(header, BorderLayout.NORTH);
		JButton refresh = new JButton("Refresh");
		header.add(refresh);
		refresh.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				tblConfig.update();
				tblRoomType.update();
				tblRoom.update();
				tblService.update();
			}
		});
		
		JTabbedPane body = new JTabbedPane();
		add(body, BorderLayout.CENTER);
		
		body.add("Configuration", createConfigPane());
		body.add("Room type", createRoomTypePane());
		body.add("Room", createRoomPane());
		body.add("Service", createServicePane());
		
		setVisible(true);
	}
	
	
	/**
	 * 
	 * @return
	 */
	private JPanel createConfigPane() {
		JPanel main = new JPanel(new BorderLayout());
		
		JPanel body = new JPanel(new BorderLayout());
		main.add(body, BorderLayout.CENTER);
		
		tblConfig = new ConfigDBTable();
		tblConfig.createControlPanel();
		body.add(tblConfig, BorderLayout.CENTER);
		return main;
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	private JPanel createRoomTypePane() {
		JPanel main = new JPanel(new BorderLayout());
		
		JPanel body = new JPanel(new BorderLayout());
		main.add(body, BorderLayout.CENTER);
		
		tblRoomType = new RoomTypeDBTable();
		tblRoomType.createControlPanel();
		body.add(tblRoomType, BorderLayout.CENTER);
		return main;
	}
	
	
	/**
	 * 
	 * @return
	 */
	private JPanel createRoomPane() {
		JPanel main = new JPanel(new BorderLayout());
		
		JPanel body = new JPanel(new BorderLayout());
		main.add(body, BorderLayout.CENTER);
		
		tblRoom = new RoomDBTable();
		tblRoom.createControlPanel();
		body.add(tblRoom, BorderLayout.CENTER);
		return main;
	}

	
	/**
	 * 
	 * @return
	 */
	private JPanel createServicePane() {
		JPanel main = new JPanel(new BorderLayout());
		
		JPanel body = new JPanel(new BorderLayout());
		main.add(body, BorderLayout.CENTER);
		
		tblService = new ServiceDBTable();
		tblService.createControlPanel();
		body.add(tblService, BorderLayout.CENTER);
		return main;
	}


}
