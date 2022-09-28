package com.tvhms.ui;

import java.util.List;
import java.util.Vector;

import com.tvhms.entity.Account;
import com.tvhms.entity.Entity;

public class AccTableModel extends SortableTableModel {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	
	/**
	 * 
	 */
	public AccTableModel() {
		super();
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	private Vector<String> createColumns() {
		Vector<String> columns = new Vector<>();
		
		columns.add("Account");
		columns.add("Password");
		columns.add("Full name");
		columns.add("Right");
		
		return columns;
	}
	
	
	/**
	 * 
	 */
	@SuppressWarnings("unchecked")
	public void update() {
		Vector<String> columns = createColumns();
		
		Vector<Vector<Object>> data = new Vector<Vector<Object>>();
		List<Account> accList = (List<Account>) Entity.load("from Account");
		for (int i = 0; i < accList.size(); i++) {
			Account acc = accList.get(i);
			
			Vector<Object> row = new Vector<>();
			
			row.add(acc.getAccountId());
			row.add(acc.getAccountPassword());
			row.add(acc.getFullName());
			int right = acc.getAccountRight();
			if ( (right & Account.MANAGER) == Account.MANAGER)
				row.add("manager");
			else if ((right & Account.OFFICER) == Account.MANAGER)
				row.add("officer");
			else
				row.add("");
				
			data.add(row);
		}
		
		setDataVector(data, columns);
	}
	
	
	
	/**
	 * 
	 * @param row
	 * @return
	 */
	public Account getAccount(int row) {
		String accId = (String)getValueAt(row, 0);
		return (Account)Entity.load(Account.class, accId);
		
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
