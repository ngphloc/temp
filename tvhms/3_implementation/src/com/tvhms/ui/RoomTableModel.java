package com.tvhms.ui;

import java.util.ArrayList;
import java.util.List;
import java.util.Vector;

import com.tvhms.entity.Entity;
import com.tvhms.entity.Reserve;
import com.tvhms.entity.Reserve.Status;
import com.tvhms.entity.Room;

public class RoomTableModel extends SortableTableModel {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 */
	private List<Room> roomList = new ArrayList<>();
	
	
	/**
	 * 
	 */
	public RoomTableModel() {
		super();
		
		update();
	}
	
	
	/**
	 * 
	 * @return
	 */
	private Vector<String> createColumns() {
		Vector<String> columns = new Vector<>();
		
		columns.add("No");
		columns.add("Floor");
		columns.add("Room");
		columns.add("Status");
		columns.add("Paid (VND)");
		columns.add("Remaining days");
		columns.add("Customer");
		columns.add("Number persons");
		
		return columns;
	}

	
	@SuppressWarnings("unchecked")
	public void update() {
		Vector<String> columns = createColumns();
		
		Vector<Vector<Object>> data = new Vector<Vector<Object>>();
		roomList = (List<Room>)Entity.load("from Room");
		for (int i = 0; i < roomList.size(); i++) {
			Room room = roomList.get(i);
			
	        Vector<Object> row = new Vector<>();
	        
			row.add(i + 1);
	        row.add(room.getRoomFloor());
			row.add(room.getRoomName());
			
			Reserve current = room.currentReserve();
			if (current == null)
				row.add(Status.available);
			else {
				Status status = current.getStatus();
				row.add(status);
			}
			
			if (current == null) {
				row.add(new PrgValue(0, 0));
				row.add(0);
				row.add(" ");
				row.add(0);
			}
			else {
				PrgValue value = new PrgValue(current.getTotalPayment(), current.getPaid());
				row.add(value);
				
				row.add(current.getTotalDays() - current.getLivedDays());
				row.add(current.getCustomer().queryCustomerNameIntel());
				row.add(current.getNumberPersons());
			}
			
			
			data.add(row);
		}
		
		setDataVector(data, columns);
	}
	
	
	/**
	 * 
	 * @param row
	 * @param column
	 * @return
	 */
	public Class<?> getColumnClass(int row, int column) {
		Object value = getValueAt(row, column);
		
		return value.getClass();
	}
	
	
	@Override
	public boolean isCellEditable(int row, int column) {
		// TODO Auto-generated method stub
		
		return false;
	}


	@Override
	public boolean isSortable(int column) {
		// TODO Auto-generated method stub
		return true;
	}
	
	
	
	/**
	 * 
	 * @param row
	 * @return
	 */
	public Room getRoom(int row) {
		String roomName = (String)getValueAt(row, 2);
		
		for (Room room : roomList) {
			if (room.getRoomName().equals(roomName))
				return room;
		}
		
		return null;
	}
	
	
}
