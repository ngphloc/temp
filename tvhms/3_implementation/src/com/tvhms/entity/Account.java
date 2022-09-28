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
@Table (name = "Account")
public class Account extends Entity {
	
	/**
	 * 
	 */
	public final static int OFFICER = 1;

	
	/**
	 * 
	 */
	public final static int MANAGER = 3;
	
	
	/**
	 * 
	 */
	private String accountId;
	
	
	/**
	 * 
	 */
	private String accountPassword;
	
	
	/**
	 * 
	 */
	private String fullName;
	
	
	/**
	 * 
	 */
	private int accountRight;
	
	
	
	/**
	 * 
	 * @param accountId
	 * @param accountPassword
	 * @param fullName
	 * @param accountRight
	 */
	public Account(
			String accountId, 
			String accountPassword, 
			String fullName, 
			int accountRight) {
		this.accountId = accountId;
		this.accountPassword = accountPassword;
		this.fullName = fullName;
		this.accountRight = accountRight;
	}
	
	
	/**
	 * 
	 */
	public Account() {
		
	}

	
	@Id
	@Column (name = "AccountId")
	public String getAccountId() {
		return accountId;
	}
	
	
	/**
	 * 
	 * @param accountId
	 */
	public void setAccountId(String accountId) {
		this.accountId = accountId;
	}
	
	
	
	@Column (name = "AccountPassword")
	public String getAccountPassword() {
		return accountPassword;
	}
	
	
	/**
	 * 
	 * @param accountPassword
	 */
	public void setAccountPassword(String accountPassword) {
		this.accountPassword = accountPassword;
	}
	
	
	@Column (name = "FullName")
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
	
	
	@Column (name = "AccountRight")
	public int getAccountRight() {
		return accountRight;
	}
	
	
	/**
	 * 
	 * @param accountRight
	 */
	public void setAccountRight(int accountRight) {
		this.accountRight = accountRight;
	}
	
	
	
	
	@Override
	public Serializable queryId() {
		// TODO Auto-generated method stub
		return getAccountId();
	}

	/**
	 * 
	 * @return
	 */
	public Account save2() {
		Serializable accountId = super.save();
		if (accountId == null)
			return null;
		
		return (Account)load(this.getClass(), accountId);
	}
	
}
