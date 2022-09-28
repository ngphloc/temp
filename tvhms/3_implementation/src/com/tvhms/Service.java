package com.tvhms;

import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
@SuppressWarnings("deprecation")
public class Service {
	
	
	/**
	 * 
	 */
	private static SessionFactory factory = null;
	
	
	/**
	 * 
	 */
	static {
		try {
			Class.forName("com.mysql.jdbc.Driver");
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		factory = 
				new Configuration().configure().buildSessionFactory();
		
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	public static SessionFactory getSessionFactory() {
		return factory;
	}
	
	
}
