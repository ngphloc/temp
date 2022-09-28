package com.tvhms.ui;

import com.tvhms.entity.Customer;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class CustomerTextField extends TagTextField {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 */
	public CustomerTextField() {
		super();
	}
	
	
	/**
	 * 
	 * @param customer
	 */
	public void setCustomer(Customer customer) {
		if (customer == null) {
			this.tag_ = null;
			this.setText("");
		}
		else {
			this.tag_ = customer;
			super.setText(customer.queryCustomerNameIntel());
		}
	}
	
	
	/**
	 * 
	 * @return
	 */
	public Customer getCustomer() {
		return (Customer)tag_;
	}
	
	
	
}
