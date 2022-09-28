package com.tvhms.ui;

import java.sql.SQLException;
import java.util.Properties;

import org.hibernate.cfg.Configuration;

import quick.dbtable.Column;
import quick.dbtable.DBTable;
import quick.dbtable.DatabaseChangeListener;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class SrvExtDBTable extends DBTable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * 
	 */
	private int reserveId = -1;
	
	
	/**
	 * 
	 */
	public SrvExtDBTable() {
		init();
		update(-1);
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
			addDatabaseChangeListener(new DatabaseChangeListener() {

				@Override
				public boolean beforeDelete(int row) {
					// TODO Auto-generated method stub
					if (reserveId == -1)
						return false;
					else
						return super.beforeDelete(row);
				}

				@Override
				public boolean beforeInsert(int row) {
					// TODO Auto-generated method stub
					if (reserveId == -1)
						return false;
					else
						return super.beforeInsert(row);
				}

				@Override
				public boolean beforeUpdate(int row) {
					// TODO Auto-generated method stub
					if (reserveId == -1)
						return false;
					else
						return super.beforeUpdate(row);
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
	 */
	public void update(int reserveId) {
		this.reserveId = reserveId;
		
		String selectSql = "select ServiceName, Quantity, TotalPrice from ServiceExtras where ReserveId = " + reserveId;
		setSelectSql(selectSql);
		
		String insertSql = "insert into ServiceExtras " +
				"(ReserveId, ServiceName, Quantity, TotalPrice) values " +
				"(" + reserveId + ", ?, ?, ?)";
		clearAllInsertSql();
		addInsertSql(insertSql, "1,2,3");
		
		String updateSql = "update ServiceExtras" +
				" set Quantity = ?, TotalPrice = ?" +
				" where ReserveId = " + reserveId + " and ServiceName = ?";
		clearAllUpdateSql();
		addUpdateSql(updateSql, "2,3,1");
		
		String deleteSql = "delete from ServiceExtras where ReserveId = " + 
				reserveId + " and ServiceName = ?";
		clearAllDeleteSql();
		addDeleteSql(deleteSql, "1");
		
		try {
			refresh();
			
			Column srvColumn = getColumnByDatabaseName("ServiceName");
			if (srvColumn != null)
				srvColumn.setBoundSql("select ServiceName from Service");
			
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
