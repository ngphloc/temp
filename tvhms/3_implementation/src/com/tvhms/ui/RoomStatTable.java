package com.tvhms.ui;

import java.util.Date;

import javax.swing.table.TableCellRenderer;
import javax.swing.table.TableColumnModel;

import com.tvhms.entity.Room_RoomStat;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class RoomStatTable extends SortableTable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 */
	public RoomStatTable() {
		super(new RoomStatTableModel());
	}
	
	
	/**
	 * 
	 * @return
	 */
	public RoomStatTableModel getRoomStatTableModel() {
		return (RoomStatTableModel)this.getModel();
	}
	

	
	@Override
	protected void init() {
		// TODO Auto-generated method stub
		super.init();
		
		TableColumnModel tcm = getColumnModel();
		if (tcm.getColumnCount() > 0)
			tcm.getColumn(0).setPreferredWidth(5);
	}


	/**
	 * 
	 * @param startDate
	 * @param endDate
	 */
	public void update(Date startDate, Date endDate) {
		getRoomStatTableModel().update(startDate, endDate);
		init();
	}
	
	
	@Override
	public TableCellRenderer getCellRenderer(int row, int column) {
		RoomStatTableModel model = getRoomStatTableModel();
		TableCellRenderer renderer = getDefaultRenderer(
				model.getColumnClass(row, column));
		if(renderer == null) return super.getCellRenderer(row, column);
		
		return renderer;
	}

	
	
	/**
	 * 
	 * @return
	 */
	public Room_RoomStat getSelectedRoomStat() {
		int selected = getSelectedRow();
		if (selected != -1)
			return getRoomStatTableModel().getRoomStat(selected);
		else
			return null;
	}
	
	
	
	
}
