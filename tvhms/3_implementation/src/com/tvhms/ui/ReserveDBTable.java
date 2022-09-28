package com.tvhms.ui;

import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Properties;

import org.hibernate.cfg.Configuration;

import quick.dbtable.Column;
import quick.dbtable.DBTable;
import quick.dbtable.DBTableCellListener;

import com.tvhms.Constants;
import com.tvhms.entity.Customer;
import com.tvhms.entity.Entity;
import com.tvhms.entity.Reserve;
import com.tvhms.entity.Reserve.Status;
import com.tvhms.entity.Room;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class ReserveDBTable extends DBTable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 */
	public ReserveDBTable() {
		init();
		
		Date startDate = new Date();
		
		Calendar cal = Calendar.getInstance();
		cal.add(Calendar.DATE, -1);
		Date endDate = cal.getTime();
		
		update(startDate, endDate);
	}
	
	
	
	/**
	 * 
	 */
	private void init() {
		Properties props = new Configuration().configure().getProperties();
		String driver = props.getProperty("connection.driver_class");
		String url = props.getProperty("connection.url");
		String username = props.getProperty("connection.username");
		String password = props.getProperty("connection.password");

		try {
			connectDatabase(driver, url, username, password);
			
			String insertSql = "insert into Reserve " +
					"(RoomName, CustomerId, Status, BeginDate, " +
					"TotalDays, LivedDays, TotalPayment, Paid, NumberPersons) values " +
					"(?, ?, ?, ?, ?, ?, ?, ?, ?)";
			clearAllInsertSql();
			addInsertSql(insertSql, "2,3,4,5,6,7,8,9,10");
			
			String updateSql = "update Reserve" +
					" set RoomName = ?, CustomerId = ?, Status = ?, BeginDate = ?, " +
					" TotalDays = ?, LivedDays = ?, TotalPayment = ?, " +
					" Paid = ?, NumberPersons = ?" +
					" where ReserveId = ?";
			clearAllUpdateSql();
			addUpdateSql(updateSql, "2,3,4,5,6,7,8,9,10,1");
			
			String deleteSql = "delete from Reserve where ReserveId = ?";
			clearAllDeleteSql();
			addDeleteSql(deleteSql, "1");
			
			addTableCellListener(new DBTableCellListener() {
				
				@Override
				public Object cellValueChanged(int row, int col, Object oldValue,
						Object newValue) {
					
					if (col != 2)
						return newValue;
					
					Reserve reserve = getCurrentReserve(row);
					if (reserve == null)
						return null;
					
					String newRoomName = newValue.toString();
					Room newRoom = (Room)Entity.load(Room.class, newRoomName);
					if (newRoom == null)
						return null;
					
					Reserve newReserve = newRoom.currentReserve();
					if (newReserve == null || 
							newReserve.getReserveId() == reserve.getReserveId())
						return newValue;
					else if (newReserve.getStatus() == Status.available) 
						return newValue;
					else
						return null;
				}
				
			});
			
			
		} 
		catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	
	
	/**
	 * 
	 * @param startDate
	 * @param endDate
	 */
	public void update(Date startDate, Date endDate) {
		SimpleDateFormat df = new SimpleDateFormat(Constants.DATE_FORMAT);
		String where = "";
		
		if (startDate != null)
			where += " BeginDate >= '" + df.format(startDate) + "' ";
		if (endDate != null) {
			if (startDate != null)
				where += " and ";
			where += " BeginDate <= '" + df.format(endDate) + "'";
		}
		
		String selectSql = "";
		if (!where.isEmpty())
			selectSql = "select * from Reserve where " + where;
		else
			selectSql = "select * from Reserve";
		selectSql += " order by BeginDate DESC";
		setSelectSql(selectSql);
		
		try {
			refresh();
			
			Column reserveColumn = getColumnByDatabaseName("ReserveId");
			if (reserveColumn != null)
				reserveColumn.setVisible(false);

			Column roomColumn = getColumnByDatabaseName("RoomName");
			if (roomColumn != null)
				roomColumn.setBoundSql("select RoomName from Room");
			
			Column customerColumn = getColumnByDatabaseName("CustomerId");
			if (customerColumn != null)
				customerColumn.setBoundSql("select CustomerId from Customer");
			
			Column paymentColumn = getColumnByDatabaseName("TotalPayment");
			if (paymentColumn != null)
				paymentColumn.setPrecision(20);
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	
	/**
	 * 
	 * @return
	 */
	protected Reserve getCurrentReserve(int row) {
		
		int reserveId = Integer.parseInt(getValueAt(row, 0).toString());
		return (Reserve)Entity.load(Reserve.class, reserveId);
	}
	
	
	/**
	 * 
	 * @return
	 */
	protected Room getCurrentRoom(int row) {
		String roomName = getValueAt(row, 1).toString();
		return (Room)Entity.load(Room.class, roomName);
	}
	
	
	/**
	 * 
	 * @return
	 */
	protected Customer getCurrentCustomer(int row) {
		int custId = Integer.parseInt(getValueAt(row, 2).toString());
		return (Customer)Entity.load(Customer.class, custId);
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
			selectCell(selected, 0, true);
	}
	
	
	/**
	 * 
	 */
	public void clear() {
		clearAllDeleteSql();
		clearAllInsertSql();
		clearAllUpdateSql();
		removeAllRows();
	}
	
	
	
}
