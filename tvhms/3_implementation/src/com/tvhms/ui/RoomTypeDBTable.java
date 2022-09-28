package com.tvhms.ui;

import java.sql.SQLException;
import java.util.Properties;

import org.hibernate.cfg.Configuration;

import quick.dbtable.DBTable;
import quick.dbtable.DatabaseChangeListener;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class RoomTypeDBTable extends DBTable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 */
	public RoomTypeDBTable() {
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
			
			String selectSql = "select * from RoomType";
			setSelectSql(selectSql);
			
			String insertSql = "insert into RoomType (RoomTypeName, Price) values (?, ?)";
			clearAllInsertSql();
			addInsertSql(insertSql, "1,2");
			
			String updateSql = "update RoomType" +
					" set Price = ? where RoomTypeName = ?";
			clearAllUpdateSql();
			addUpdateSql(updateSql, "2,1");
			
			String deleteSql = "delete from RoomType where RoomTypeName = ?";
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
