package com.tvhms.ui;

import javax.swing.table.TableColumnModel;

import com.tvhms.entity.Customer;
import com.tvhms.entity.CustomerExtras;

public class CustomerExtrasTable extends SortableTable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 */
	public CustomerExtrasTable() {
		super(new CustomerExtrasTableModel());
		update(-1);
	}
	
	
	@Override
	protected void init() {
		// TODO Auto-generated method stub
		super.init();
		
		TableColumnModel tcm = getColumnModel();
		if (tcm.getColumnCount() > 2) {
			tcm.getColumn(0).setMaxWidth(0);
			tcm.getColumn(0).setMinWidth(0);
			tcm.getColumn(0).setWidth(0);
			tcm.getColumn(0).setPreferredWidth(0);
			
			tcm.getColumn(1).setMaxWidth(0);
			tcm.getColumn(1).setMinWidth(0);
			tcm.getColumn(1).setWidth(0);
			tcm.getColumn(1).setPreferredWidth(0);
			
			tcm.getColumn(2).setPreferredWidth(5);
		}
	}


	/**
	 * 
	 * @param reserveId
	 */
	public void update(int reserveId) {
		getExtrasModel().update(reserveId);
		init();
	}
	
	
	/**
	 * 
	 * @return
	 */
	public CustomerExtrasTableModel getExtrasModel() {
		return (CustomerExtrasTableModel)getModel();
	}
	
	
	/**
	 * 
	 * @return
	 */
	public CustomerExtras getSelectedCustomerExtras() {
		int selected = getSelectedRow();
		if (selected == -1)
			return null;
		
		return getExtrasModel().getCustomerExtras(selected);
	}

	
	
	/**
	 * 
	 * @return
	 */
	public Customer getSelectedCustomer() {
		int selected = getSelectedRow();
		if (selected == -1)
			return null;
		
		return getExtrasModel().getCustomer(selected);
	}


	
	/**
	 * 
	 * @param reserveId
	 * @param customerId
	 */
	public void select(int reserveId, int customerId) {
		int n = getRowCount();
		int selected = -1;
		for (int i = 0; i < n; i++) {
			int rId = (Integer)getValueAt(i, 0);
			int cId = (Integer)getValueAt(i, 1);
			if (rId == reserveId && cId == customerId) {
				selected = i;
				break;
			}
		}
		
		if (selected != -1)
			this.getSelectionModel().addSelectionInterval(selected, selected);
	}
	
	
	
}
