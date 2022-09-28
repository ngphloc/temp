package com.tvhms.entity;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Id;
import javax.persistence.OneToMany;
import javax.persistence.Table;


/**
 * 
 * @author Administrator2
 * @verion 1.0
 *
 */
@javax.persistence.Entity
@Table(name = "RoomType")
public class RoomType extends Entity {

	
	/**
	 * 
	 */
	private String roomTypeName = "";
	
	
	/**
	 * 
	 */
	private float price = 0;
	
	
	/**
	 * 
	 */
	private List<Room> roomList = new ArrayList<>();
	
	
	/**
	 * 
	 */
	public RoomType() {
		super();
	}
	
	
	
	/**
	 * 
	 * @param roomTypeName
	 * @param price
	 */
	public RoomType(String roomTypeName, float price) {
		super();
		
		this.roomTypeName = roomTypeName;
		this.price = price;
	}
	
	
	
	@Override
	public Serializable queryId() {
		// TODO Auto-generated method stub
		return new Integer(getRoomTypeName());
	}
	
	
	
	@Id
	@Column (name = "RoomTypeName")
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
	@Column(name = "Price")
	public float getPrice() {
		return price;
	}
	
	
	/**
	 * 
	 * @param price
	 */
	public void setPrice(float price) {
		this.price = price;
	}
	
	
	@OneToMany (mappedBy = "roomType", cascade = CascadeType.ALL)
	public List<Room> getRoomList() {
		return roomList;
	}
	
	
	
	/**
	 * 
	 * @param roomList
	 */
	public void setRoomList(List<Room> roomList) {
		this.roomList = roomList;
	}
	
	
	
	@Override
	public String toString() {
		return "RoomType (" + 
				getRoomTypeName() + ", " + 
				getPrice() + ")";
	}
	
	
	
}
