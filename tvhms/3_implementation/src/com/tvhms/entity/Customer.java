package com.tvhms.entity;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.OneToMany;
import javax.persistence.Table;

import org.hibernate.annotations.GenericGenerator;



/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
@javax.persistence.Entity
@Table(name = "Customer")
public class Customer extends Entity {

	
	/**
	 * 
	 */
	private int customerId = 0;
	
	
	/**
	 * 
	 */
	private String personalId = "";
	
	
	/**
	 * 
	 */
	private String fullName = "";
	
	
	/**
	 * 
	 */
	private String vehicleNumber = "";
	
	
	/**
	 * 
	 */
	private List<Reserve> reserveList = new ArrayList<>();

	
	/**
	 * 
	 */
	private List<CustomerExtras> customerExtrasList = new ArrayList<CustomerExtras>();

	
	/**
	 * 
	 */
	public Customer() {
		
	}
	
	
	
	/**
	 * 
	 * @param fullName
	 * @param personalId
	 * @param vehicleNumber
	 */
	public Customer(String fullName, String personalId, String vehicleNumber) {
		this.fullName = fullName;
		this.personalId = personalId;
		this.vehicleNumber = vehicleNumber; 
	}
	
	
	
	@Override
	public Serializable queryId() {
		// TODO Auto-generated method stub
		return getCustomerId();
	}

	
	
	/**
	 * 
	 * @return
	 */
	@Id
	@GeneratedValue(generator="increment")
	@GenericGenerator(name="increment", strategy = "increment")
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
	@Column (name = "PersonalId")
	public String getPersonalId() {
		return personalId;
	}

	
	
	/**
	 * 
	 * @param personalId
	 */
	public void setPersonalId(String personalId) {
		this.personalId = personalId;
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	@Column(name = "FullName")
	public String getFullName() {
		return fullName;
	}
	
	
	/**
	 * 
	 * @param fullName
	 */
	public void setFullName(String fullName) {
		this.fullName = fullName;
	}
	
	
	@Column(name = "VehicleNumber")
	public String getVehicleNumber() {
		return vehicleNumber;
	}
	
	
	
	/**
	 * 
	 * @param vehicleNumber
	 */
	public void setVehicleNumber(String vehicleNumber) {
		this.vehicleNumber = vehicleNumber; 
	}
	
	
	@OneToMany (mappedBy = "customer", cascade = CascadeType.ALL)
	public List<Reserve> getReserveList() {
		return reserveList;
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
	@OneToMany (mappedBy = "customer", cascade = CascadeType.ALL)
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
	public String queryCustomerNameIntel() {
		String name = getFullName();
		if (name == null || name.isEmpty())
			return getCustomerId() + "";
		else
			return name;
	}
	

	
	/**
	 * 
	 * @return
	 */
	public Customer save2() {
		Serializable customerId = super.save();
		if (customerId == null)
			return null;
		
		return (Customer)load(this.getClass(), customerId);
	}
	
	
}
