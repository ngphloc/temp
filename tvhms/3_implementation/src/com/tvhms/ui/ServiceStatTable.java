package com.tvhms.ui;

import java.util.Calendar;
import java.util.Date;

import javax.swing.ListSelectionModel;

import com.tvhms.entity.Service;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class ServiceStatTable extends SortableTable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 */
	public ServiceStatTable() {
		super(new ServiceStatTableModel());
		this.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		
		Calendar start = Calendar.getInstance();
		start.add(Calendar.DATE, -30);
		Date end = new Date();
		
		update(start.getTime(), end);
	}
	
	
	/**
	 * 
	 * @return
	 */
	public ServiceStatTableModel getServiceTableModel() {
		return (ServiceStatTableModel)this.getModel();
		
	}
	
	
	
	@Override
	protected void init() {
		// TODO Auto-generated method stub
		super.init();
		
	}


	/**
	 * 
	 */
	public void update(Date startDate, Date endDate) {
		getServiceTableModel().update(startDate, endDate);
		init();
	}
	
	
	
	
	/**
	 * 
	 * @return
	 */
	public Service getSelectedService() {
		int row = getSelectedRow();
		if (row == -1)
			return null;
		
		return getServiceTableModel().getService(row);
	}


	
	/**
	 * 
	 * @param serviceName
	 */
	public void selectService(String serviceName) {
		int n = getRowCount();
		int selected = -1;
		for (int i = 0; i < n; i++) {
			String name = (String)getValueAt(i, 1);
			if (name.equals(serviceName)) {
				selected = i;
				break;
			}
		}
		
		if (selected != -1)
			this.getSelectionModel().addSelectionInterval(selected, selected);
	}
	
	
	
	
}
