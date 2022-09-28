package com.tvhms.entity;

import java.io.Serializable;

import javax.persistence.Column;
import javax.persistence.Embeddable;
import javax.persistence.EmbeddedId;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Table;

@javax.persistence.Entity
@Table(name = "ServiceExtras")
public class ServiceExtras extends Entity {

	/**
	 * 
	 */
	private ServiceExtrasId serviceExtrasId;
	
	
	/**
	 * 
	 */
	private int quantity;
	
	
	/**
	 * 
	 */
	private float totalPrice;
	
	
	/**
	 * 
	 */
	private Reserve reserve;
	
	
	/**
	 * 
	 */
	private Service service;

	
	@Override
	public Serializable queryId() {
		// TODO Auto-generated method stub
		return getServiceExtrasId();
	}

	
	
	/**
	 * 
	 * @return
	 */
	@EmbeddedId
	public ServiceExtrasId getServiceExtrasId() {
		return serviceExtrasId;
	}
	
	
	
	/**
	 * 
	 * @param serviceExtrasId
	 */
	public void setServiceExtrasId(ServiceExtrasId serviceExtrasId) {
		this.serviceExtrasId = serviceExtrasId;
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	@Column (name = "Quantity")
	public int getQuantity() {
		return quantity;
	}
	
	
	/**
	 * 
	 * @param quantity
	 */
	public void setQuantity(int quantity) {
		this.quantity = quantity;
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	@Column (name = "TotalPrice")
	public float getTotalPrice() {
		return totalPrice;
	}
	
	
	
	/**
	 * 
	 * @param totalPrice
	 */
	public void setTotalPrice(float totalPrice) {
		this.totalPrice = totalPrice;
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
	@JoinColumn (name = "ServiceName", insertable = false, updatable = false)
	public Service getService() {
		return service;
	}
	
	
	
	/**
	 * 
	 * @param service
	 */
	public void setService(Service service) {
		this.service = service;
	}


}


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
@Embeddable
class ServiceExtrasId implements Serializable {

	/**
	 * 
	 */
	private int reserveId;
	
	
	/**
	 * 
	 */
	private String serviceName;

	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	
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
	 * @param reservationId
	 */
	public void setReserveId(int reservationId) {
		this.reserveId = reservationId;
	}
	
	
	/**
	 * 
	 * @return
	 */
	@Column(name = "ServiceName")
	public String getServiceName() {
		return serviceName;
	}
	
	
	
	/**
	 * 
	 * @param serviceName
	 */
	public void setServiceName(String serviceName) {
		this.serviceName = serviceName;
	}


	@Override
	public boolean equals(Object obj) {
		// TODO Auto-generated method stub
		ServiceExtrasId id = (ServiceExtrasId)obj;
		return this.serviceName.equals(id.serviceName) && this.reserveId == id.reserveId;
	}
	
	
}
