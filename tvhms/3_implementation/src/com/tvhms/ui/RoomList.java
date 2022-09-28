package com.tvhms.ui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.util.List;
import java.util.Vector;

import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JProgressBar;
import javax.swing.ListCellRenderer;

import com.tvhms.Constants;
import com.tvhms.entity.Entity;
import com.tvhms.entity.Reserve;
import com.tvhms.entity.Reserve.Status;
import com.tvhms.entity.Room;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class RoomList extends JList<Room> {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 */
	public RoomList() {
		setCellRenderer(new RoomCellRenderer());
		update();
	}
	
	
	@SuppressWarnings("unchecked")
	public void update() {
		Vector<Room> roomList = new Vector<>((List<Room>)Entity.load("from Room"));
		
		setListData(roomList);
	}
	
	
}



/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
class RoomCellRenderer extends JPanel implements ListCellRenderer<Room> {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 */
	private JLabel lbInfo = null;
	
	
	/**
	 * 
	 */
	private JProgressBar prgPaid = null;
	
	
	public RoomCellRenderer() {
		setLayout(new BorderLayout());
        
        lbInfo = new JLabel();
        lbInfo.setVerticalTextPosition(JLabel.TOP);
        lbInfo.setVerticalAlignment(JLabel.TOP);
		add(lbInfo, BorderLayout.CENTER);
		
		prgPaid = new JProgressBar(0, 100);
		add(prgPaid, BorderLayout.SOUTH);
	}
	
	
	@Override
	public Component getListCellRendererComponent(JList<? extends Room> list,
			Room value, int index, boolean isSelected, boolean cellHasFocus) {
		// TODO Auto-generated method stub
        ImageIcon roomIcon = new ImageIcon(
    			getClass().getResource(Constants.IMAGES_DIRECTORY + "room.jpg"));
		
		lbInfo.setText(value.toString());
		lbInfo.setIcon(roomIcon);
		lbInfo.setEnabled(list.isEnabled());
		lbInfo.setFont(list.getFont());
		lbInfo.setOpaque(true);
		lbInfo.setBackground(Color.blue);
		
		prgPaid.setValue(0);
		prgPaid.setVisible(false);
		Reserve current = value.currentReserve();
		if (current != null) {
			Status status = current.getStatus();
			if (status == Status.available) {
				lbInfo.setBackground(Color.blue);
				prgPaid.setValue(0);
				prgPaid.setVisible(false);
			}
			else {
				lbInfo.setBackground(Color.red);
				
				int percent = (int) ((float)current.getPaid() / (float)current.getTotalPayment() + 0.5 );
				percent = Math.min(100, percent);
				prgPaid.setValue(percent);
				prgPaid.setVisible(true);
			}
			
		}
		
        if (isSelected) {
        	setBackground(list.getSelectionBackground());
        	setForeground(list.getSelectionForeground());
        }
        else {
        	setBackground(list.getBackground());
        	setForeground(list.getForeground());
        }
        
		return this;
	}
	
}