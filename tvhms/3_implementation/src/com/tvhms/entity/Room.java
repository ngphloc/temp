package com.tvhms.entity;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.OneToMany;
import javax.persistence.Table;

import org.hibernate.Session;
import org.hibernate.annotations.Filter;
import org.hibernate.annotations.FilterDef;
import org.hibernate.annotations.FilterDefs;
import org.hibernate.annotations.Filters;
import org.hibernate.annotations.ParamDef;

import com.tvhms.Service;
import com.tvhms.entity.Reserve.Status;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
@javax.persistence.Entity
@Table (name = "Room")
@FilterDefs ({
	@FilterDef (name = "startDateFilter", parameters = @ParamDef(name = "startDate", type = "java.util.Date")), 
	@FilterDef (name = "endDateFilter", parameters = @ParamDef(name = "endDate", type = "java.util.Date"))}) 
public class Room extends Entity {
	
	/**
	 * 
	 */
	private String roomName = "";
	
	
	/**
	 * 
	 */
	private String roomTypeName = "";
	
	
	/**
	 * 
	 */
	private int roomFloor = 0;
	
	
	/**
	 * 
	 */
	private List<Reserve> reserveList = new ArrayList<>();
	
	
	/**
	 * 
	 */
	private RoomType roomType = null;
	
	
	
	/**
	 * 
	 */
	public Room() {
		
	}
	
	
	
	/**
	 * 
	 * @param roomName
	 * @param roomTypeName
	 * @param roomFloor
	 */
	public Room(String roomName, String roomTypeName, int roomFloor) {
		this.roomName = roomName;
		this.roomTypeName = roomTypeName;
		this.roomFloor = roomFloor;
	}

	
	
	/**
	 * 
	 */
	public Serializable queryId() {
		return new Integer(getRoomName());
	}
	
	
	/**
	 * 
	 * @return
	 */
	@Column(name = "RoomTypeName")
	public String getRoomTypeName() {
		return roomTypeName;
	}
	
	
	/**
	 * 
	 * @param roomTypeName
	 */
	public void setRoomTypeName(String roomTypeName) {
		this.roomTypeName = roomTypeName;
	}
	
	
	/**
	 * 
	 * @return
	 */
	@Id
	@Column(name = "RoomName")
	public String getRoomName() {
		return roomName;
	}
	
	
	/**
	 * 
	 * @param roomName
	 */
	public void setRoomName(String roomName) {
		this.roomName = roomName;
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	@Column(name = "RoomFloor")
	public int getRoomFloor() {
		return roomFloor;
	}
	
	
	
	/**
	 * 
	 * @param floor
	 */
	public void setRoomFloor(int roomFloor) {
		this.roomFloor = roomFloor;
	}
	
	
	
	@OneToMany (mappedBy = "room", cascade = CascadeType.ALL)
	@org.hibernate.annotations.OrderBy (clause = "BeginDate ASC")
	@Filters ({
		@Filter(name = "startDateFilter", condition = ":startDate <= BeginDate"),
		@Filter(name = "endDateFilter", condition = "BeginDate <= :endDate")})
	public List<Reserve> getReserveList() {
		return reserveList;
	}
	
	
	
	/**
	 * 
	 * @param startDate
	 * @param endDate
	 * @return
	 */
	public List<Reserve> queryReserveList(Date startDate, Date endDate) {
		List<Reserve> result = new ArrayList<>();
		
		try {
			Session session = Service.getSessionFactory().openSession();
			
			session.beginTransaction();
			if (startDate != null) {
				org.hibernate.Filter filter = session.enableFilter("startDateFilter");
				filter.setParameter("startDate", startDate);
			}
			
			if (endDate != null) {
				org.hibernate.Filter filter = session.enableFilter("endDateFilter");
				filter.setParameter("endDate", endDate);
			}

			Room room = (Room) session.get(this.getClass(), getRoomName());
			List<Reserve> reserveList = room.getReserveList();
			for (Reserve reserve : reserveList)
				result.add(reserve);
			
			session.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}	
		
		return result;
	}
	
	
	
	/**
	 * 
	 * @param startDate
	 * @param endDate
	 * @return
	 */
	public RoomStat queryRoomStat(Date startDate, Date endDate) {
		RoomStat stat = new RoomStat();
		List<Reserve> reserveList = queryReserveList(startDate, endDate);
		if (reserveList.size() == 0)
			return stat;
		
		int totalDays = 0;
		if (reserveList.size() == 1)
			totalDays = 1;
		else {
			startDate = reserveList.get(0).getBeginDate();
			endDate = reserveList.get(reserveList.size() - 1).getBeginDate();
			int interval = (int) (endDate.getTime() - startDate.getTime()) / 1000 / 60 / 60 / 24;
			totalDays = interval + reserveList.get(reserveList.size() - 1).getLivedDays();
		}
		
		int livedDays = 0;
		float paid = 0;
		for (Reserve reserve : reserveList) {
			livedDays += reserve.getLivedDays();
			paid += reserve.getPaid();
		}
		
		stat.LivedDays = livedDays;
		stat.Productivity = livedDays / totalDays;
		stat.Turns = reserveList.size();
		stat.Revenue = paid;
		
		float service = 0;
		List<ServiceExtras> extras = queryServiceExtras(startDate, endDate);
		for (ServiceExtras extra : extras) {
			service += extra.getTotalPrice();
		}
		stat.Service = service;
		
		
		return stat;
	}
	
	
	
	/**
	 * 
	 * @param reserveList
	 */
	public void setReserveList(List<Reserve> reserveList) {
		this.reserveList = reserveList;
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	@SuppressWarnings("unchecked")
	public Reserve currentReserve() {
		Reserve result = null;
		
		try {
			Session session = Service.getSessionFactory().openSession();
			
			session.beginTransaction();
			List<Reserve> list = session.
					createQuery("from Reserve r where r.roomName = :roomName order by r.beginDate").
					setString("roomName", getRoomName()).
					list();
			
			if (list.size() > 0)
				result = list.get(list.size() - 1);
			
			session.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}	
		
		return result;
	}
	
	
	@ManyToOne
	@JoinColumn (name = "RoomTypeName", insertable = false, updatable = false)
	public RoomType getRoomType() {
		return roomType;
	}
	
	
	
	/**
	 * 
	 * @param roomType
	 */
	public void setRoomType(RoomType roomType) {
		this.roomType = roomType;
	}
	
	
	/**
	 * 
	 * @return
	 */
	public Status currentStatus() {
		Reserve lastReserve = currentReserve();
		if (lastReserve == null)
			return Status.available;
		else
			return lastReserve.getStatus();
	}

	
	
	/**
	 * 
	 * @param status
	 * @return
	 */
	@SuppressWarnings("unchecked")
	public static List<Room> queryRoomList(Status status) {
		List<Room> result = new ArrayList<>();
		List<Room> roomList = (List<Room>)load("from Room");
		
		for (Room room : roomList) {
			if (room.currentStatus() == status)
				result.add(room);
		}
		
		return result;
	}
	
	
	
	/**
	 * 
	 * @param startDate
	 * @param endDate
	 * @return
	 */
	public List<ServiceExtras> queryServiceExtras(Date startDate, Date endDate) {
		List<ServiceExtras> serviceExtras = new ArrayList<>();
		List<Reserve> reserveList = queryReserveList(startDate, endDate);
		if (reserveList.size() == 0)
			return serviceExtras;
		
		for (Reserve reserve : reserveList) {
			serviceExtras.addAll(reserve.queryServiceExtrasList());
		}
		
		return serviceExtras;
	}
	
	
	
	@Override
	public String toString() {
		return getRoomName();
	}
	
	
	@Override
	public boolean equals(Object obj) {
		// TODO Auto-generated method stub
		return this.roomName.equals( ((Room)obj).getRoomName() );
	}



	/**
	 * 
	 * @return
	 */
	public String toText() {
		String roomName = getRoomName();
		String roomTypeName = getRoomTypeName();
		String roomFloor = "Floor " + getRoomFloor();
		String price = "Price " + getRoomType().getPrice();
		String status = "" + currentStatus();
		
		return "Room \"" + roomName + "\", " + roomTypeName + ", " + 
				roomFloor + ", " + price + ": " + status;
	}
	
	
	
}
