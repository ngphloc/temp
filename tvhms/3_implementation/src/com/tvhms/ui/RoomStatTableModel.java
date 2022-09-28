package com.tvhms.ui;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Vector;

import com.tvhms.entity.Room_RoomStat;

public class RoomStatTableModel extends SortableTableModel {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 */
	private List<Room_RoomStat> roomStatList = new ArrayList<>();
	
	
	/**
	 * 
	 */
	public RoomStatTableModel() {
		super();
		
		update(null, new Date());
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
		columns.add("Type");
		columns.add("Lived days");
		columns.add("Productivity (%)");
		columns.add("Turns");
		columns.add("Revenue (VND)");
		columns.add("Service (VND)");
		
		return columns;
	}

	
	/**
	 * 
	 * @param startDate
	 * @param endDate
	 */
	public void update(Date startDate, Date endDate) {
		Vector<String> columns = createColumns();
		
		Vector<Vector<Object>> data = new Vector<Vector<Object>>();
		roomStatList = Room_RoomStat.load(startDate, endDate);
		for (int i = 0; i < roomStatList.size(); i++) {
			Room_RoomStat roomStat = roomStatList.get(i);
			
	        Vector<Object> row = new Vector<>();
	        
			row.add(i + 1);
	        row.add(roomStat.Room.getRoomFloor());
			row.add(roomStat.Room.getRoomName());
			row.add(roomStat.Room.getRoomTypeName());
			
			row.add(roomStat.RoomStat.LivedDays);
			row.add(roomStat.RoomStat.Productivity * 100);
			row.add(roomStat.RoomStat.Turns);
			row.add(roomStat.RoomStat.Revenue);
			row.add(roomStat.RoomStat.Service);
			
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
	public Room_RoomStat getRoomStat(int row) {
		String roomName = (String)getValueAt(row, 2);
		
		for (Room_RoomStat roomStat : roomStatList) {
			if (roomStat.Room.getRoomName().equals(roomName))
				return roomStat;
		}
		
		return null;
	}
	
	
	
	
}
