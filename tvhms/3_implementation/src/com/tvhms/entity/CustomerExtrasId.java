package com.tvhms.entity;

import java.io.Serializable;

import javax.persistence.Column;
import javax.persistence.Embeddable;

/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
@Embeddable
public class CustomerExtrasId implements Serializable {


	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 */
	private int reserveId;
	
	
	/**
	 * 
	 */
	private int customerId;

	
	/**
	 * 
	 */
	public CustomerExtrasId() {
		
	}
	
	
	
	/**
	 * 
	 * @param reserveId
	 * @param customerId
	 */
	public CustomerExtrasId(int reserveId, int customerId) {
		this.reserveId = reserveId;
		this.customerId = customerId;
	}

	
	
	/**
	 * 
	 * @return
	 */
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


	@Override
	public boolean equals(Object obj) {
		// TODO Auto-generated method stub
		CustomerExtrasId id = (CustomerExtrasId)obj;
		return this.customerId == id.customerId && this.reserveId == id.reserveId;
	}
	
	
}
