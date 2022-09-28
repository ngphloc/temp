package com.tvhms.ui;

import java.util.List;
import java.util.Vector;

import com.tvhms.entity.Customer;
import com.tvhms.entity.Entity;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class CustomerTableModel extends SortableTableModel {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	
	/**
	 * 
	 */
	public CustomerTableModel() {
		super();
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	private Vector<String> createColumns() {
		Vector<String> columns = new Vector<>();
		
		columns.add("CustomerId");
		columns.add("No");
		columns.add("Full name");
		columns.add("Personal Id");
		columns.add("Vehicle number");
		
		return columns;
	}
	
	
	/**
	 * 
	 */
	@SuppressWarnings("unchecked")
	public void update() {
		Vector<String> columns = createColumns();
		
		Vector<Vector<Object>> data = new Vector<Vector<Object>>();
		List<Customer> customerList = (List<Customer>) Entity.load("from Customer");
		for (int i = 0; i < customerList.size(); i++) {
			Customer customer = customerList.get(i);
			
			Vector<Object> row = new Vector<>();
			
			row.add(customer.getCustomerId());
			row.add(i + 1);
			row.add(customer.getFullName());
			row.add(customer.getPersonalId());
			row.add(customer.getVehicleNumber());
			
			data.add(row);
		}
		
		setDataVector(data, columns);
	}
	
	
	
	/**
	 * 
	 * @param row
	 * @return
	 */
	public Customer getCustomer(int row) {
		int customerId = (Integer)getValueAt(row, 0);
		return (Customer)Entity.load(Customer.class, customerId);
		
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
