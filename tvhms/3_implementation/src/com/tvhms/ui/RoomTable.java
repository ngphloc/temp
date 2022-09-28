package com.tvhms.ui;

import javax.swing.table.TableCellRenderer;
import javax.swing.table.TableColumnModel;

import com.tvhms.entity.Reserve.Status;
import com.tvhms.entity.Room;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class RoomTable extends SortableTable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	
	/**
	 * 
	 */
	public RoomTable() {
		super(new RoomTableModel());
		setDefaultRenderer(Status.class, new StatusRenderer());
		setDefaultRenderer(PrgValue.class, new ProgressBarRenderer());
	}
	
	
	/**
	 * 
	 * @return
	 */
	public RoomTableModel getRoomTableModel() {
		return (RoomTableModel)this.getModel();
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
	 */
	public void update() {
		getRoomTableModel().update();
		init();
	}
	
	
	@Override
	public TableCellRenderer getCellRenderer(int row, int column) {
		RoomTableModel model = getRoomTableModel();
		TableCellRenderer renderer = getDefaultRenderer(
				model.getColumnClass(row, column));
		if(renderer == null) return super.getCellRenderer(row, column);
		
		return renderer;
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	public Room getSelectedRoom() {
		int selected = getSelectedRow();
		if (selected == -1)
			return null;
		else
			return getRoomTableModel().getRoom(selected);
	}
	
	
	
	
    
    
}
