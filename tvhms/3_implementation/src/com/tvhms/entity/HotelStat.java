package com.tvhms.entity;

import java.util.Date;
import java.util.List;

import org.hibernate.Session;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class HotelStat {

	/**
	 * 
	 */
	public int LivedDays = 0;
	
	
	/**
	 * 
	 */
	public int Turns = 0;
	
	
	/**
	 * 
	 */
	public float Revenue = 0;
	
	
	/**
	 * 
	 */
	public float Service = 0;
	
	
	/**
	 * 
	 */
	public float Cost = 0;
	
	
	/**
	 * 
	 * @param startDate
	 * @param endDate
	 * @return
	 */
	@SuppressWarnings("unchecked")
	public static HotelStat queryHotelStat(Date startDate, Date endDate) {
		HotelStat stat = null;
		
		try {
			Session session = com.tvhms.Service.getSessionFactory().openSession();
			session.beginTransaction();
			
			List<Room> roomList = session.createQuery("from Room").list();
			stat = new HotelStat();
			for (Room room : roomList) {
				RoomStat roomStat = room.queryRoomStat(startDate, endDate);
				
				stat.LivedDays += roomStat.LivedDays;
				stat.Turns += roomStat.Turns;
				stat.Revenue += roomStat.Revenue;
				stat.Service += roomStat.Service;
			}
			 
			session.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}	
		
		return stat;
	}
	
	
}
