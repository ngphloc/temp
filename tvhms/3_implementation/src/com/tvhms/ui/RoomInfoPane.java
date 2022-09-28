package com.tvhms.ui;

import java.awt.BorderLayout;
import java.awt.GridLayout;

import javax.swing.JLabel;
import javax.swing.JPanel;

import com.tvhms.entity.Room;

public class RoomInfoPane extends JPanel {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	private JLabel lbRoom = new JLabel();
	
	private JLabel lbFloor = new JLabel();
	
	private JLabel lbType = new JLabel();

	private JLabel lbPrice = new JLabel();

	/**
	 * 
	 */
	public RoomInfoPane() {
		setLayout(new BorderLayout());
		
		JPanel left = new JPanel(new GridLayout(0, 1));
		add(left, BorderLayout.WEST);
		
		left.add(new JLabel("Room:  "));
		left.add(new JLabel("Floor:  "));
		left.add(new JLabel("Type:  "));
		left.add(new JLabel("Price:  "));
		
		JPanel right = new JPanel(new GridLayout(0, 1));
		add(right, BorderLayout.CENTER);
		
		right.add(lbRoom);
		right.add(lbFloor);
		right.add(lbType);
		right.add(lbPrice);
		
	}
	
	
	/**
	 * 
	 * @param stat
	 */
	public void update(Room room) {
		lbRoom.setText(room.getRoomName());
		lbFloor.setText("" + room.getRoomFloor());
		lbType.setText("" + room.getRoomTypeName());
		lbPrice.setText("" + room.getRoomType().getPrice() + " VND");
	}
	
	
	
	
	
	
	/**
	 * 
	 */
	public void clear() {
		lbRoom.setText("");
		lbFloor.setText("");
		lbType.setText("");
		lbPrice.setText("");
	}
	
	
	
}
