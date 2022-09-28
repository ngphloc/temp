package com.tvhms.entity;

import java.io.Serializable;
import java.util.Date;

import javax.persistence.Column;
import javax.persistence.EmbeddedId;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Table;


/**
 * 
 * @author Administrator2
 *
 */
@javax.persistence.Entity
@Table(name = "CustomerExtras")
public class CustomerExtras extends Entity {

	
	/**
	 * 
	 */
	private CustomerExtrasId customerExtrasId;
	
	
	/**
	 * 
	 */
	private Date beginDate;
	
	
	/**
	 * 
	 */
	private Reserve reserve;
	
	
	/**
	 * 
	 */
	private Customer customer;

	
	@Override
	public Serializable queryId() {
		// TODO Auto-generated method stub
		return getCustomerExtrasId();
	}

	
	
	@EmbeddedId
	public CustomerExtrasId getCustomerExtrasId() {
		return customerExtrasId;
	}

	
	
	/**
	 * 
	 * @param id
	 */
	public void setCustomerExtrasId(CustomerExtrasId id) {
		this.customerExtrasId = id;
	}
	
	
	@Column( name = "BeginDate")
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
	
	
	@ManyToOne
	@JoinColumn (name = "ReserveId", insertable = false, updatable = false)
	public Reserve getReserve() {
		return reserve;
	}
	
	
	/**
	 * 
	 * @param reserve
	 */
	public void setReserve(Reserve reserve) {
		this.reserve = reserve;
	}
	
	
	
	/**
	 * 
	 * @return
	 */
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
	
	
	
}




