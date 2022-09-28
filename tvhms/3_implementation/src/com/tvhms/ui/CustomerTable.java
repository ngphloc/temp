package com.tvhms.ui;

import javax.swing.ListSelectionModel;
import javax.swing.table.TableColumnModel;

import com.tvhms.entity.Customer;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class CustomerTable extends SortableTable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 */
	public CustomerTable() {
		super(new CustomerTableModel());
		this.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
	}
	
	
	/**
	 * 
	 * @return
	 */
	public CustomerTableModel getCustomerTableModel() {
		return (CustomerTableModel)this.getModel();
		
	}
	
	
	
	@Override
	protected void init() {
		// TODO Auto-generated method stub
		super.init();
		
		TableColumnModel tcm = getColumnModel();
		if (tcm.getColumnCount() > 1) {
			tcm.getColumn(0).setMaxWidth(0);
			tcm.getColumn(0).setMinWidth(0);
			tcm.getColumn(0).setWidth(0);
			tcm.getColumn(0).setPreferredWidth(0);
			tcm.getColumn(1).setPreferredWidth(5);
	
			getCustomerTableModel().sortByColumn(1, true);
		}
	}


	/**
	 * 
	 */
	public void update() {
		getCustomerTableModel().update();
		init();
	}
	
	
	
	
	/**
	 * 
	 * @return
	 */
	public Customer getSelectedCustomer() {
		int row = getSelectedRow();
		if (row == -1)
			return null;
		
		return getCustomerTableModel().getCustomer(row);
	}


	
	/**
	 * 
	 * @param customerId
	 */
	public void selectCustomer(int customerId) {
		int n = getRowCount();
		int selected = -1;
		for (int i = 0; i < n; i++) {
			int id = (Integer)getValueAt(i, 0);
			if (id == customerId) {
				selected = i;
				break;
			}
		}
		
		if (selected != -1)
			this.getSelectionModel().addSelectionInterval(selected, selected);
	}

	
	
}
