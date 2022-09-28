package com.tvhms.ui;

import java.text.SimpleDateFormat;
import java.util.List;
import java.util.Vector;

import com.tvhms.Constants;
import com.tvhms.entity.Customer;
import com.tvhms.entity.CustomerExtras;
import com.tvhms.entity.CustomerExtrasId;
import com.tvhms.entity.Entity;
import com.tvhms.entity.Reserve;

public class CustomerExtrasTableModel extends SortableTableModel {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	
	/**
	 * 
	 */
	public CustomerExtrasTableModel() {
		
	}
	
	
	/**
	 * 
	 * @return
	 */
	private Vector<String> createColumns() {
		Vector<String> columns = new Vector<>();
		
		columns.add("ReserveId");
		columns.add("CustomerId");
		columns.add("No");
		columns.add("Customer");
		columns.add("Room");
		columns.add("Status");
		columns.add("Begin date");
		columns.add("Total days");
		
		return columns;
	}

	
	/**
	 * 
	 * @param reserveId
	 */
	@SuppressWarnings("unchecked")
	public void update(int reserveId) {
		Vector<String> columns = createColumns();
		
		Vector<Vector<Object>> data = new Vector<Vector<Object>>();
		List<CustomerExtras> extrasList = (List<CustomerExtras>) Entity.load(
				"from CustomerExtras c where c.customerExtrasId.reserveId = " + reserveId);
		
		for (int i = 0; i < extrasList.size(); i++) {
			CustomerExtras extras = extrasList.get(i);
			Vector<Object> row = new Vector<Object>();
			
			row.add(reserveId);
			
			Customer customer = extras.getCustomer();
			row.add(customer.getCustomerId());
			row.add(i + 1);
			row.add(customer.getFullName());
			
			Reserve reserve = extras.getReserve();
			row.add(reserve.getRoom().getRoomName());
			row.add(reserve.getStatus());
			
			SimpleDateFormat df = new SimpleDateFormat(Constants.DATE_FORMAT);
			row.add(df.format(reserve.getBeginDate()));
			
			row.add(reserve.getTotalDays());
			
			data.add(row);
		}
		
		setDataVector(data, columns);
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

	
	
	/**
	 * 
	 * @param row
	 * @return
	 */
	public Customer getCustomer(int row) {
		int customerId = (Integer)getValueAt(row, 1);
		return (Customer)Entity.load(Customer.class, customerId);
	}
	
	
	
	/**
	 * 
	 * @param row
	 * @return
	 */
	public CustomerExtras getCustomerExtras(int row) {
		int reserveId = (Integer)getValueAt(row, 0);
		int customerId = (Integer)getValueAt(row, 1);
		CustomerExtrasId id = new CustomerExtrasId(reserveId, customerId);
		
		return (CustomerExtras)Entity.load(CustomerExtras.class, id);
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
