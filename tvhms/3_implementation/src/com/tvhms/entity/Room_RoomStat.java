package com.tvhms.entity;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import org.hibernate.Session;

import com.tvhms.Service;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class Room_RoomStat {
	
	
	/**
	 * 
	 */
	public Room Room = null;
	
	
	/**
	 * 
	 */
	public RoomStat RoomStat = null;
	
	
	/**
	 * 
	 * @param room
	 * @param roomStat
	 */
	public Room_RoomStat(Room room, RoomStat roomStat) {
		this.Room = room;
		this.RoomStat = roomStat;
	}
	
	
	/**
	 * 
	 * @param startDate
	 * @param endDate
	 * @return
	 */
	@SuppressWarnings("unchecked")
	public static List<Room_RoomStat> load(Date startDate, Date endDate) {
		List<Room_RoomStat> statList = new ArrayList<Room_RoomStat>();
		
		try {
			Session session = Service.getSessionFactory().openSession();
			session.beginTransaction();
			
			List<Room> roomList = session.createQuery("from Room").list();
			for (Room room : roomList) {
				RoomStat stat = room.queryRoomStat(startDate, endDate);
				
				Room_RoomStat roomStat = new Room_RoomStat(room, stat);
				statList.add(roomStat);
			}
			 
			session.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}	
		
		return statList;
	}
	
	
}
