package com.tvhms.ui;

import java.util.Date;

import javax.swing.ListSelectionModel;
import javax.swing.table.TableCellRenderer;
import javax.swing.table.TableColumnModel;

import com.tvhms.entity.Reserve;
import com.tvhms.entity.Room;
import com.tvhms.entity.Service;
import com.tvhms.entity.Reserve.Status;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class ReserveTable extends SortableTable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;


	
	/**
	 * 
	 */
	public ReserveTable() {
		super(new ReserveTableModel());
		this.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		setDefaultRenderer(Status.class, new StatusRenderer());
		setDefaultRenderer(PrgValue.class, new ProgressBarRenderer());
	}
	
	
	/**
	 * 
	 * @return
	 */
	public ReserveTableModel getReserveTableModel() {
		return (ReserveTableModel)this.getModel();
		
	}
	
	
	
	@Override
	protected void init() {
		// TODO Auto-generated method stub
		super.init();
		
		TableColumnModel tcm = this.getColumnModel();
		if (tcm.getColumnCount() > 0) {
			tcm.getColumn(0).setMaxWidth(0);
			tcm.getColumn(0).setMinWidth(0);
			tcm.getColumn(0).setPreferredWidth(0);
			
			getReserveTableModel().sortByColumn(1, false);
		}
	}


	/**
	 * 
	 * @param startDate
	 * @param endDate
	 * @param room
	 */
	public void update(Date startDate, Date endDate, Room room) {
		getReserveTableModel().update(startDate, endDate, room);
		init();
	}
	
	
	
	/**
	 * 
	 * @param startDate
	 * @param endDate
	 * @param service
	 */
	public void update(Date startDate, Date endDate, Service service) {
		getReserveTableModel().update(startDate, endDate, service);
		init();
	}

	
	
	/**
	 * 
	 * @param startDate
	 * @param endDate
	 */
	public void update(Date startDate, Date endDate) {
		getReserveTableModel().update(startDate, endDate, (Room)null);
		init();
	}
	
	
	
	/**
	 * 
	 */
	public void clear() {
		getReserveTableModel().clear();
	}
	
	
	/**
	 * 
	 * @return
	 */
	public Reserve getSelectedReserve() {
		int row = getSelectedRow();
		if (row == -1)
			return null;
		
		return getReserveTableModel().getReserve(row);
	}
	
	
	/**
	 * 
	 * @param reserveId
	 */
	public void selectReserveId(int reserveId) {
		int n = getRowCount();
		int selected = -1;
		for (int i = 0; i < n; i++) {
			int id = (Integer)getValueAt(i, 0);
			if (id == reserveId) {
				selected = i;
				break;
			}
		}
		
		if (selected != -1)
			this.getSelectionModel().addSelectionInterval(selected, selected);
	}
	
	
	
	@Override
	public TableCellRenderer getCellRenderer(int row, int column) {
		ReserveTableModel model = getReserveTableModel();
		TableCellRenderer renderer = getDefaultRenderer(
				model.getColumnClass(row, column));
		if(renderer == null) return super.getCellRenderer(row, column);
		
		return renderer;
	}
	
	
	
}
