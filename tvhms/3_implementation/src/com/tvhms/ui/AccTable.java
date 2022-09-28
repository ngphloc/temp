package com.tvhms.ui;

import javax.swing.ListSelectionModel;

import com.tvhms.entity.Account;

public class AccTable extends SortableTable {

	
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;



	/**
	 * 
	 */
	public AccTable() {
		super(new AccTableModel());
		this.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
	}
	
	
	/**
	 * 
	 * @return
	 */
	public AccTableModel getAccTableModel() {
		return (AccTableModel)this.getModel();
		
	}
	
	
	
	@Override
	protected void init() {
		// TODO Auto-generated method stub
		super.init();
		
	}


	/**
	 * 
	 */
	public void update() {
		getAccTableModel().update();
		init();
	}
	
	
	
	
	/**
	 * 
	 * @return
	 */
	public Account getSelectedAccount() {
		int row = getSelectedRow();
		if (row == -1)
			return null;
		
		return getAccTableModel().getAccount(row);
	}


	
	/**
	 * 
	 * @param accId
	 */
	public void selectAccount(String accId) {
		int n = getRowCount();
		int selected = -1;
		for (int i = 0; i < n; i++) {
			String id = (String)getValueAt(i, 0);
			if (id.equals(accId)) {
				selected = i;
				break;
			}
		}
		
		if (selected != -1)
			this.getSelectionModel().addSelectionInterval(selected, selected);
	}
	
	
	
	
}
