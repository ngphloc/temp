package com.tvhms.entity;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Id;
import javax.persistence.ManyToMany;
import javax.persistence.OneToMany;
import javax.persistence.Table;

import org.hibernate.Session;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
@javax.persistence.Entity
@Table(name = "Service")
public class Service extends Entity {

	
	/**
	 * 
	 */
	private String serviceName;

	
	/**
	 * 
	 */
	private String serviceType;
	

	/**
	 * 
	 */
	private float price;
	
	
	/**
	 * 
	 */
	private String unit;
	
	
	/**
	 * 
	 */
	private String description;
	
	
	/**
	 * 
	 */
	private List<Reserve> reserveList = new ArrayList<>();
	
	
	/**
	 * 
	 */
	private List<ServiceExtras> serviceExtrasList = new ArrayList<ServiceExtras>();

	
	@Override
	public Serializable queryId() {
		// TODO Auto-generated method stub
		return getServiceName();
	}

	
	/**
	 * 
	 * @return
	 */
	@Id
	@Column(name = "ServiceName")
	public String getServiceName() {
		return serviceName;
	}
	
	
	
	/**
	 * 
	 * @param name
	 */
	public void setServiceName(String serviceName) {
		this.serviceName = serviceName;
	}
	
	
	/**
	 * 
	 * @return
	 */
	@Column(name = "ServiceType")
	public String getServiceType() {
		return serviceType;
	}
	
	
	
	/**
	 * 
	 * @param serviceType
	 */
	public void setServiceType(String serviceType) {
		this.serviceType = serviceType;
	}
	
	
	
	
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
	
	
	@Column(name = "Unit")
	public String getUnit() {
		return unit;
	}
	
	
	/**
	 * 
	 * @param unit
	 */
	public void setUnit(String unit) {
		this.unit = unit;
	}
	
	
	
	@Column(name = "description")
	public String getDescription() {
		return description;
	}
	
	
	
	/**
	 * 
	 * @param description
	 */
	public void setDescription(String description) {
		this.description = description;
	}
	
	
	@ManyToMany(cascade = {CascadeType.PERSIST, CascadeType.MERGE},
		mappedBy = "serviceList", targetEntity = Reserve.class)
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
	 * @param startDate
	 * @param endDate
	 * @return
	 */
	public List<Reserve> queryReserveList(Date startDate, Date endDate) {
		List<Reserve> result = new ArrayList<>();
		
		try {
			Session session = com.tvhms.Service.getSessionFactory().openSession();
			
			session.beginTransaction();

			Service service = (Service) session.get(this.getClass(), getServiceName());
			List<Reserve> reserveList = service.getReserveList();
			for (Reserve reserve : reserveList) {
				Date beginDate = reserve.getBeginDate();
				
				if (beginDate != null) {
					if (startDate != null && beginDate.before(startDate))
						continue;
					if (endDate != null && beginDate.after(endDate))
						continue;
				}
				
				result.add(reserve);
			}
			
			session.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}	
		
		return result;
	}
	
	
	@OneToMany (mappedBy = "service", cascade = CascadeType.ALL)
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
	 * @param startDate
	 * @param endDate
	 * @return
	 */
	public List<ServiceExtras> queryServiceExtrasList(Date startDate, Date endDate) {
		List<ServiceExtras> result = new ArrayList<>();
		
		try {
			Session session = com.tvhms.Service.getSessionFactory().openSession();
			
			session.beginTransaction();

			Service service = (Service) session.get(this.getClass(), getServiceName());
			List<ServiceExtras> extrasList = service.getServiceExtrasList();
			for (ServiceExtras extras : extrasList) {
				Reserve reserve = extras.getReserve();
				Date beginDate = reserve.getBeginDate();
				
				if (beginDate != null) {
					if (startDate != null && beginDate.before(startDate))
						continue;
					if (endDate != null && beginDate.after(endDate))
						continue;
				}
				
				result.add(extras);
			}
			
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
	public ServiceStat queryServiceStat(Date startDate, Date endDate) {
		ServiceStat stat = new ServiceStat();
		
		int totalDays = (int) (endDate.getTime() - startDate.getTime()) / 1000 / 60 / 60 / 24;
		stat.TotalDays = totalDays;
		
		float service = 0;
		List<ServiceExtras> extras = queryServiceExtrasList(startDate, endDate);
		for (ServiceExtras extra : extras) {
			service += extra.getTotalPrice();
		}
		stat.TotalMoney = service;
		
		
		return stat;
	}
	
	
}
