package com.tvhms.ui;

import java.sql.SQLException;
import java.util.Properties;

import org.hibernate.cfg.Configuration;

import quick.dbtable.Column;
import quick.dbtable.DBTable;
import quick.dbtable.DatabaseChangeListener;

public class RoomDBTable extends DBTable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * 
	 */
	public RoomDBTable() {
		super();
		init();
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
			
			String selectSql = "select * from Room";
			setSelectSql(selectSql);
			
			String insertSql = "insert into Room (RoomName, RoomTypeName, RoomFloor) values (?, ?, ?)";
			clearAllInsertSql();
			addInsertSql(insertSql, "1,2,3");
			
			String updateSql = "update Room" +
					" set RoomTypeName = ?, RoomFloor = ? where RoomName = ?";
			clearAllUpdateSql();
			addUpdateSql(updateSql, "2,3,1");
			
			String deleteSql = "delete from Room where RoomName = ?";
			clearAllDeleteSql();
			addDeleteSql(deleteSql, "1");
			
			addDatabaseChangeListener(new DatabaseChangeListener() {

				@Override
				public void afterDelete(int row) {
					// TODO Auto-generated method stub
					super.afterDelete(row);
					
					
				}
			});
			
			refresh();
			
			Column roomTypeColumn = getColumn(1);
			if (roomTypeColumn != null)
				roomTypeColumn.setBoundSql("select RoomTypeName from RoomType");
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	
	/**
	 * 
	 */
	public void update() {
		try {
			refresh();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
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
