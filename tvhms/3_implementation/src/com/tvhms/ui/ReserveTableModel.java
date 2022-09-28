package com.tvhms.ui;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Vector;

import com.tvhms.Constants;
import com.tvhms.entity.Entity;
import com.tvhms.entity.Reserve;
import com.tvhms.entity.Room;
import com.tvhms.entity.Service;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class ReserveTableModel extends SortableTableModel {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	
	/**
	 * 
	 */
	private List<Reserve> reserveList =  new ArrayList<>();
	
	
	public ReserveTableModel() {
		super();
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	private Vector<String> createColumns() {
		Vector<String> columns = new Vector<>();
		
		columns.add("ReserveId");
		columns.add("No");
		columns.add("Room");
		columns.add("Status");
		columns.add("Customer");
		columns.add("Begin date");
		columns.add("Total days");
		columns.add("Lived days");
		columns.add("Total payment (VND)");
		columns.add("Paid (VND)");
		columns.add("Number persons");
		
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
		Vector<String> columns = createColumns();
		
		List<Room> roomList = new ArrayList<>();
		if (r != null)
			roomList.add(r);
		else
			roomList = (List<Room>)Entity.load("from Room");
		
		Vector<Vector<Object>> data = new Vector<Vector<Object>>();
		reserveList.clear();
		int k = 0;
		for (int i = 0; i < roomList.size(); i++) {
			Room room = roomList.get(i);
			
			List<Reserve> list = room.queryReserveList(startDate, endDate);
			reserveList.addAll(list);
			for (int j = 0; j < list.size(); j++, k++) {
				Reserve reserve = list.get(j);
		        Vector<Object> row = new Vector<>();
		        
		        row.add(reserve.getReserveId());
		        row.add(k + 1);
				row.add(room.getRoomName());
				row.add(reserve.getStatus());
				
				row.add(reserve.getCustomer().queryCustomerNameIntel());
				
				SimpleDateFormat df = new SimpleDateFormat(Constants.DATE_FORMAT);
				row.add(df.format(reserve.getBeginDate()));
				
				row.add(reserve.getTotalDays());
				row.add(reserve.getLivedDays());
				row.add(reserve.getTotalPayment());
				
				PrgValue paidValue = new PrgValue(reserve.getTotalPayment(), reserve.getPaid());
				row.add(paidValue);
				row.add(reserve.getNumberPersons());
				
				data.add(row);
			}
			
		}
		
		setDataVector(data, columns);
	}
	
	
	
	@SuppressWarnings("unchecked")
	public void update(Date startDate, Date endDate, Service s) {
		Vector<String> columns = createColumns();
		
		List<Service> serviceList = new ArrayList<>();
		if (s != null)
			serviceList.add(s);
		else
			serviceList = (List<Service>)Entity.load("from Service");
		
		Vector<Vector<Object>> data = new Vector<Vector<Object>>();
		reserveList.clear();
		int k = 0;
		for (int i = 0; i < serviceList.size(); i++) {
			Service service = serviceList.get(i);
			
			List<Reserve> list = service.queryReserveList(startDate, endDate);
			reserveList.addAll(list);
			for (int j = 0; j < list.size(); j++, k++) {
				Reserve reserve = list.get(j);
		        Vector<Object> row = new Vector<>();
		        
		        row.add(reserve.getReserveId());
		        row.add(k + 1);
				row.add(reserve.getRoomName());
				row.add(reserve.getStatus());
				
				row.add(reserve.getCustomer().queryCustomerNameIntel());
				
				SimpleDateFormat df = new SimpleDateFormat(Constants.DATE_FORMAT);
				row.add(df.format(reserve.getBeginDate()));
				
				row.add(reserve.getTotalDays());
				row.add(reserve.getLivedDays());
				row.add(reserve.getTotalPayment());
				row.add(reserve.getPaid());
				row.add(reserve.getNumberPersons());
				
				data.add(row);
			}
			
		}
		
		setDataVector(data, columns);
	}

	
	/**
	 * 
	 */
	public void clear() {
		Vector<String> columns = createColumns();
		Vector<Vector<Object>> data = new Vector<Vector<Object>>();
		setDataVector(data, columns);
		
		reserveList.clear();
	}

	
	/**
	 * 
	 * @param row
	 * @return
	 */
	public Reserve getReserve(int row) {
		int reserveId = (Integer)getValueAt(row, 0);
		return (Reserve)Entity.load(Reserve.class, reserveId);
		
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
	 * @param column
	 * @return
	 */
	public Class<?> getColumnClass(int row, int column) {
		Object value = getValueAt(row, column);
		
		return value.getClass();
	}
	
	
}
