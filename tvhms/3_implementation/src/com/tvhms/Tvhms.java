package com.tvhms;

import java.util.Date;
import java.util.List;

import com.tvhms.entity.Entity;
import com.tvhms.entity.Reserve;
import com.tvhms.entity.Room;
import com.tvhms.entity.RoomType;
import com.tvhms.ui.Login;

public class Tvhms {

	
	/**
	 * 
	 * @param agrs
	 * @throws Exception
	 */
	public static void main(String[] agrs) throws Exception {
		new Login();
	}
	
	
	@SuppressWarnings("unchecked")
	public static void main2(String[] agrs) throws Exception {
		new RoomType("Type 1", 250000).delete();
		new RoomType("Type 1", 250000).save();
		
		new RoomType("Type 2", 300000).delete();
		new RoomType("Type 2", 300000).save();
		
		new RoomType("Type 3", 480000).delete();
		new RoomType("Type 3", 480000).save();
		
		new RoomType("Type 4", 600000).delete();
		new RoomType("Type 4", 600000).save();

		Room room = new Room("sdhglsd", "Type 1", 1);
		room.delete();
		room.save();
		
        List<Room> roomList = (List<Room>) Entity.load("from Room");
		for (Room r : roomList) {
			System.out.println( "Room (" + 
					r.getRoomName() + ", " + 
					r.getRoomTypeName() + ", " + 
					r.getRoomType().getPrice() + ", " + 
					r.getRoomFloor() + ")" );
		}
		
		Reserve reserve = new Reserve("sdhglsd", "sfgsag", 6);
		reserve.save();
		reserve.save();
		reserve.save();
		reserve.save();
		
		room = (Room)Entity.load(Room.class, "sdhglsd");
		List<Reserve> rList = room.queryReserveList(new Date(), null);
		for (Reserve res : rList) {
			System.out.println(res.getBeginDate());
		}
		
		Reserve last = room.currentReserve();
		System.out.println(last.getBeginDate());
	}
	
	
	
}
