package com.tvhms.ui;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Vector;

import com.tvhms.entity.Entity;
import com.tvhms.entity.Room;
import com.tvhms.entity.Service;
import com.tvhms.entity.ServiceExtras;

/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class SrvExtTableModel extends SortableTableModel {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 */
	private List<ServiceExtras> srvExtList =  new ArrayList<>();

	
	/**
	 * 
	 */
	public SrvExtTableModel() {
		
	}
	
	
	/**
	 * 
	 * @return
	 */
	private Vector<String> createColumns() {
		Vector<String> columns = new Vector<>();
		
		columns.add("No");
		columns.add("Room");
		columns.add("Service");
		columns.add("Price (VND)");
		columns.add("Quantity");
		columns.add("Total price (VND)");
		
		return columns;
	}
	

	/**
	 * 
	 * @param startDate
	 * @param endDate
	 * @param r
	 */
	@SuppressWarnings("unchecked")
	public void update(Date startDate, Date endDate, Room r) {
		
		List<Room> roomList = new ArrayList<>();
		if (r != null)
			roomList.add(r);
		else
			roomList = (List<Room>) Entity.load("from Room");
		
		srvExtList.clear();
		int i = 0;
		Vector<Vector<Object>> data = new Vector<Vector<Object>>();
		for (Room room : roomList) {
			List<ServiceExtras> extList = room.queryServiceExtras(startDate, endDate);
			
			srvExtList.addAll(extList);
			
			for (ServiceExtras ext : extList) {
				Vector<Object> row = new Vector<>();
				
				Service service = ext.getService();
				
		        row.add(i + 1);
				row.add(room.getRoomName());
				row.add(service.getServiceName());
				row.add(service.getPrice());
				row.add(ext.getQuantity());
				row.add(ext.getTotalPrice());
				
				data.add(row);
				i++;
			}
		}
		
		setDataVector(data, createColumns());
	}



	/**
	 * 
	 */
	public void clear() {
		Vector<String> columns = createColumns();
		Vector<Vector<Object>> data = new Vector<Vector<Object>>();
		setDataVector(data, columns);
		
		srvExtList.clear();
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
	

}
