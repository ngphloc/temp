package com.tvhms.ui;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

import javax.swing.JFormattedTextField.AbstractFormatter;

import com.tvhms.Constants;

public class DateFormatter extends AbstractFormatter {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 */
	private DateFormat format;
	
	
	/**
	 * 
	 */
	public DateFormatter(){
		format = new SimpleDateFormat(Constants.DATE_FORMAT);
	}
	
	
	
	@Override
	public String valueToString(Object value) throws ParseException {
		Calendar cal = (Calendar)value;
		if (cal == null) {
			return "";
		}
		return format.format(cal.getTime());
	}
	
	
	
	@Override
	public Object stringToValue(String text) throws ParseException {
		if (text == null || text.equals("")) {
			return null;
		}
		
		Date date = format.parse(text);
		Calendar calendar = Calendar.getInstance();
		calendar.setTime(date);
		return calendar;
	}

	
	
}
