package com.tvhms.ui;

import java.util.Date;

import javax.swing.table.TableColumnModel;

import com.tvhms.entity.Room;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class SrvExtTable extends SortableTable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * 
	 */
	public SrvExtTable() {
		super(new SrvExtTableModel());
	}
	
	
	/**
	 * 
	 * @return
	 */
	public SrvExtTableModel getSrvExtTableModel() {
		return (SrvExtTableModel)this.getModel();
		
	}
	
	
	
	@Override
	protected void init() {
		// TODO Auto-generated method stub
		super.init();
		
		TableColumnModel tcm = getColumnModel();
		if (tcm.getColumnCount() > 0) {
			tcm.getColumn(0).setPreferredWidth(5);
			
			getSrvExtTableModel().sortByColumn(0, false);
		}
	}


	/**
	 * 
	 * @param startDate
	 * @param endDate
	 * @param room
	 */
	public void update(Date startDate, Date endDate, Room room) {
		getSrvExtTableModel().update(startDate, endDate, room);
		init();
	}
	
	
	
	/**
	 * 
	 * @param startDate
	 * @param endDate
	 */
	public void update(Date startDate, Date endDate) {
		getSrvExtTableModel().update(startDate, endDate, null);
		init();
	}
	
	
	
	/**
	 * 
	 */
	public void clear() {
		getSrvExtTableModel().clear();
	}
	
	
	
}
