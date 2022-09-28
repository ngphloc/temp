package com.tvhms.ui;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

import com.tvhms.entity.Room;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class RoomPane extends JPanel {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 */
	private RoomTable tblRoom = null;
	
	
	/**
	 * 
	 */
	private RoomInfoPane paneRoomInfo = null;
	
	
	/**
	 * 
	 */
	public RoomPane() {
		setLayout(new BorderLayout());
		
		JPanel header = new JPanel(new FlowLayout(FlowLayout.RIGHT));
		add(header, BorderLayout.NORTH);
		
		JButton refresh = new JButton("Refresh");
		refresh.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				refresh();
			}
		});
		header.add(refresh);
		
		JPanel body = new JPanel(new BorderLayout());
		add(body, BorderLayout.CENTER);
		
		tblRoom = new RoomTable();
		body.add(new JScrollPane(tblRoom), BorderLayout.CENTER);
		
		JPanel footer = new JPanel(new BorderLayout());
		add(footer, BorderLayout.SOUTH);
		
		paneRoomInfo = new RoomInfoPane();
		footer.add(paneRoomInfo, BorderLayout.NORTH);
		
		tblRoom.addMouseListener(new MouseAdapter() {

			@Override
			public void mouseClicked(MouseEvent e) {
				// TODO Auto-generated method stub
				Room room = tblRoom.getSelectedRoom();
				if (room != null)
					paneRoomInfo.update(room);
			}
			
		});
		
	}
	
	
	/**
	 * 
	 */
	public void refresh() {
		tblRoom.update();
		tblRoom.clearSelection();
		paneRoomInfo.clear();
	}
	
	
}
