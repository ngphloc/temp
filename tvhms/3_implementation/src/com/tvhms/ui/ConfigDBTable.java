package com.tvhms.ui;

import java.sql.SQLException;
import java.util.Properties;

import org.hibernate.cfg.Configuration;

import quick.dbtable.DBTable;

public class ConfigDBTable extends DBTable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	
	/**
	 * 
	 */
	public ConfigDBTable() {
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
			
			String selectSql = "select * from Config";
			setSelectSql(selectSql);
			
			String insertSql = "insert into Config (ConfigAttribute, ConfigValue) values (?, ?)";
			clearAllInsertSql();
			addInsertSql(insertSql, "1,2");
			
			String updateSql = "update Config" +
					" set ConfigValue = ? where ConfigAttribute = ?";
			clearAllUpdateSql();
			addUpdateSql(updateSql, "2,1");
			
			String deleteSql = "delete from Config where ConfigAttribute = ?";
			clearAllDeleteSql();
			addDeleteSql(deleteSql, "1");
			
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
