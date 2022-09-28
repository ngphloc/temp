package com.tvhms.entity;

import java.io.Serializable;

import javax.persistence.Column;
import javax.persistence.Id;
import javax.persistence.Table;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
@javax.persistence.Entity
@Table (name = "Config")
public class Config extends Entity {

	
	/**
	 * 
	 */
	private String configAttribute;
	
	
	/**
	 * 
	 */
	private String configValue;
	
	
	
	/**
	 * 
	 */
	public Config() {
		super();
	}
	
	
	
	/**
	 * 
	 * @param configAttribute
	 * @param configValue
	 */
	public Config(String configAttribute, String configValue) {
		this();
		this.configAttribute = configAttribute;
		this.configValue = configValue;
	}
	
	
	@Id
	@Column (name = "ConfigAttribute")
	public String getConfigAttribute() {
		return configAttribute;
	}
	
	
	
	/**
	 * 
	 * @param configAttribute
	 */
	public void setConfigAttribute(String configAttribute) {
		this.configAttribute = configAttribute;
	}
	
	
	@Column (name = "ConfigValue")
	public String getConfigValue() {
		return configValue;
	}
	
	
	
	/**
	 * 
	 * @param configValue
	 */
	public void setConfigValue(String configValue) {
		this.configValue = configValue;
	}
	
	
	@Override
	public Serializable queryId() {
		// TODO Auto-generated method stub
		return getConfigAttribute();
	}

	
	
}
