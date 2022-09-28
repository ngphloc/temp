package com.tvhms.entity;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.JoinTable;
import javax.persistence.ManyToMany;
import javax.persistence.ManyToOne;
import javax.persistence.OneToMany;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;

import org.hibernate.Session;
import org.hibernate.annotations.GenericGenerator;



@javax.persistence.Entity
@Table(name = "Reserve")
public class Reserve extends Entity {
	
	
	/**
	 * 
	 * @author Administrator2
	 * @version 1.0
	 *
	 */
	public static enum Status { living, deposit, reserve, available }
	
	
	
	
	/**
	 * 
	 */
	private int reserveId;
	
	
	/**
	 * 
	 */
	private String roomName;

	
	/**
	 * 
	 */
	private int customerId;
	
	
	/**
	 * 
	 */
	private transient String tempoCustomerName = null;
	
	
	/**
	 * 
	 */
	private Status status;

	
	/**
	 * 
	 */
	private Date beginDate;

	
	/**
	 * 
	 */
	private int totalDays;
	
	
	/**
	 * 
	 */
	private int livedDays;
	
	
	/**
	 * 
	 */
	private float totalPayment;
	
	
	/**
	 * 
	 */
	private float paid;
	
	
	/**
	 * 
	 */
	private int numberPersons;
	
	
	/**
	 * 
	 */
	private Room room;
	
	
	/**
	 * 
	 */
	private Customer customer;

	
	/**
	 * 
	 */
	private List<Service> serviceList = new ArrayList<Service>();
	
	
	/**
	 * 
	 */
	private List<ServiceExtras> serviceExtrasList = new ArrayList<ServiceExtras>();
	
	
	/**
	 * 
	 */
	private List<CustomerExtras> customerExtrasList = new ArrayList<CustomerExtras>();

	
	/**
	 * 
	 */
	public Reserve() {
		
	}
	
	
	
	/**
	 * 
	 * @param roomName
	 * @param customerId
	 * @param totalDays
	 */
	public Reserve(String roomName, int customerId, int totalDays) {
		this.roomName = roomName;
		this.customerId = customerId;
		this.tempoCustomerName = null;
		this.status = Status.living;
		this.beginDate = new Date();
		this.totalDays = Math.max(1, totalDays);
		this.livedDays = 1;
		
		Room room = (Room)Entity.load(Room.class, roomName);
		this.totalPayment = room.getRoomType().getPrice() * totalDays;
		this.paid = 0;
		
		this.numberPersons = 1;
	}
	
	
	/**
	 * 
	 * @param roomName
	 * @param tempoCustomerName
	 * @param totalDays
	 */
	public Reserve(String roomName, String tempoCustomerName, int totalDays) {
		this(roomName, 0, totalDays);
		this.tempoCustomerName = tempoCustomerName;
	}
	
	
	/**
	 * 
	 * @return
	 */
	public Reserve save2() {
		// TODO Auto-generated method stub
		
		if (tempoCustomerName != null) {
			Customer customer = new Customer(tempoCustomerName, null, null);
			customer.save();
			setCustomerId(customer.getCustomerId());
			
			tempoCustomerName = null;
		}
		
		Serializable reserveId = super.save();
		if (reserveId == null)
			return null;
		
		return (Reserve)load(this.getClass(), reserveId);
	}

	
	@Override
	public boolean update() {
		if (tempoCustomerName != null) {
			Customer customer = new Customer(tempoCustomerName, null, null);
			customer.save();
			setCustomerId(customer.getCustomerId());
			
			tempoCustomerName = null;
		}
		
		return super.update();
	}
	
	

	@Override
	public Serializable queryId() {
		// TODO Auto-generated method stub
		return new Integer(getReserveId());
	}



	/**
	 * 
	 * @return
	 */
	@Id
	@GeneratedValue(generator="increment")
	@GenericGenerator(name="increment", strategy = "increment")
	@Column(name = "ReserveId")
	public int getReserveId() {
		return reserveId;
	}
	
	
	
	/**
	 * 
	 * @param reserveId
	 */
	public void setReserveId(int reserveId) {
		this.reserveId = reserveId;
	}
	
	
	
	/**
	 * 
	 * @return
	 */
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
	@Column(name = "CustomerId")
	public int getCustomerId() {
		return customerId;
	}
	
	
	
	/**
	 * 
	 * @param customerId
	 */
	public void setCustomerId(int customerId) {
		this.customerId = customerId;
	}
	
	
	
	
	
	/**
	 * 
	 * @return
	 */
	@Column(name = "Status")
	public Status getStatus() {
		return status;
	}
	
	
	/**
	 * 
	 * @param status
	 */
	public void setStatus(Status status) {
		this.status = status;
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	@Temporal(TemporalType.TIMESTAMP)
	@Column(name = "BeginDate")
	public Date getBeginDate() {
		return beginDate;
	}
	
	
	
	/**
	 * 
	 * @param beginDate
	 */
	public void setBeginDate(Date beginDate) {
		this.beginDate = beginDate;
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	@Column(name = "TotalDays")
	public int getTotalDays() {
		return totalDays;
	}
	
	
	
	/**
	 * 
	 * @param totalDays
	 */
	public void setTotalDays(int totalDays) {
		this.totalDays = totalDays;
	}
	
	
	/**
	 * 
	 * @return
	 */
	@Column(name = "LivedDays")
	public int getLivedDays() {
		return livedDays;
	}
	
	
	
	/**
	 * 
	 * @param livedDays
	 */
	public void setLivedDays(int livedDays) {
		this.livedDays = livedDays;
	}


	
	/**
	 * 
	 * @return
	 */
	@Column(name = "TotalPayment")
	public float getTotalPayment() {
		return totalPayment;
	}

	
	
	/**
	 * 
	 * @param totaPayment
	 */
	public void setTotalPayment(float totaPayment) {
		this.totalPayment = totaPayment;
	}

	
	
	/**
	 * 
	 * @return
	 */
	@Column(name = "Paid")
	public float getPaid() {
		return paid;
	}
	
	
	
	/**
	 * 
	 * @param paid
	 */
	public void setPaid(float paid) {
		this.paid = paid;
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	@Column(name = "NumberPersons")
	public int getNumberPersons() {
		return numberPersons;
	}
	
	
	
	/**
	 * 
	 * @param numberPersons
	 */
	public void setNumberPersons(int numberPersons) {
		this.numberPersons = numberPersons;
	}
	
	
	@ManyToOne
	@JoinColumn (name = "RoomName", insertable = false, updatable = false)
	public Room getRoom() {
		return room;
	}
	
	
	
	/**
	 * 
	 * @param room
	 */
	public void setRoom(Room room) {
		this.room = room;
	}
	
	
	@ManyToOne
	@JoinColumn (name = "CustomerId", insertable = false, updatable = false)
	public Customer getCustomer() {
		return customer;
	}
	
	
	
	/**
	 * 
	 * @param customer
	 */
	public void setCustomer(Customer customer) {
		this.customer = customer;
	}

	
	
	
	
	@ManyToMany (targetEntity = Service.class, 
		cascade={CascadeType.PERSIST, CascadeType.MERGE})
	@JoinTable (name = "ServiceExtras", 
		joinColumns = @JoinColumn(name = "ReserveId"),
		inverseJoinColumns = @JoinColumn(name = "ServiceName"))
	public List<Service> getServiceList() {
		return serviceList;
	}
	
	
	/**
	 * 
	 * @param serviceList
	 */
	public void setServiceList(List<Service> serviceList) {
		this.serviceList = serviceList;
	}
	
	
	
	@OneToMany (mappedBy = "reserve", cascade = CascadeType.ALL)
	public List<ServiceExtras> getServiceExtrasList() {
		return serviceExtrasList;
	}
	
	
	/**
	 * 
	 * @param serviceExtrasList
	 */
	public void setServiceExtrasList(List<ServiceExtras> serviceExtrasList) {
		this.serviceExtrasList = serviceExtrasList;
	}
	
	
	/**
	 * 
	 * @return
	 */
	public List<ServiceExtras> queryServiceExtrasList() {
		List<ServiceExtras> result = new ArrayList<ServiceExtras>();
		Session session = null;
		
		try {
			session = com.tvhms.Service.getSessionFactory().openSession();
			
			session.beginTransaction();

			Reserve reserve = (Reserve) session.get(this.getClass(), getReserveId());
			List<ServiceExtras> list = reserve.getServiceExtrasList();
			for (ServiceExtras ext : list)
				result.add(ext);
			
			session.close();
		}
		catch (Exception e) {
			e.printStackTrace();
			
			if (session != null)
				session.close();
		}	
		
		return result;
	}
	
	
	@OneToMany (mappedBy = "reserve", cascade = CascadeType.ALL)
	public List<CustomerExtras> getCustomerExtrasList() {
		return customerExtrasList;
	}
	
	
	/**
	 * 
	 * @param customerExtrasList
	 */
	public void setCustomerExtrasList(List<CustomerExtras> customerExtrasList) {
		this.customerExtrasList = customerExtrasList;
	}

	
	/**
	 * 
	 * @return
	 */
	public static List<Status> queryStatusList() {
		List<Status> statusList = new ArrayList<Reserve.Status>();
		
		statusList.add(Status.living);
		statusList.add(Status.deposit);
		statusList.add(Status.reserve);
		statusList.add(Status.available);
		
		return statusList;
	}

}
