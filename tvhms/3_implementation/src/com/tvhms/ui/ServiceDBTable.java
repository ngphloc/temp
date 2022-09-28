package com.tvhms.ui;

import java.sql.SQLException;
import java.util.Properties;

import org.hibernate.cfg.Configuration;

import quick.dbtable.DBTable;
import quick.dbtable.DatabaseChangeListener;

public class ServiceDBTable extends DBTable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 */
	public ServiceDBTable() {
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
			
			String selectSql = "select * from Service";
			setSelectSql(selectSql);
			
			String insertSql = "insert into Service " +
					"(ServiceName, ServiceType, Price, Unit, Description) values (?, ?, ?, ?, ?)";
			clearAllInsertSql();
			addInsertSql(insertSql, "1,2,3,4,5");
			
			String updateSql = "update Service " +
					"set ServiceType = ?, " +
					"Price = ?, " +
					"Unit = ?, " +
					"Description = ? " +
					"where ServiceName = ?";
			clearAllUpdateSql();
			addUpdateSql(updateSql, "2,3,4,5,1");
			
			String deleteSql = "delete from Service where ServiceName = ?";
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
