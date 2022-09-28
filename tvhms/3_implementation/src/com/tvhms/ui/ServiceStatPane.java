package com.tvhms.ui;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

import org.freixas.jcalendar.JCalendar;
import org.freixas.jcalendar.JCalendarCombo;

import com.tvhms.Constants;
import com.tvhms.entity.Service;

public class ServiceStatPane extends JPanel {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 */
	private JCalendarCombo startDateCtl = null;
	
	
	/**
	 * 
	 */
	private JCalendarCombo endDateCtl = null;
	
	
	/**
	 * 
	 */
	private HotelStatPane paneHotelStat = null;
	
	
	/**
	 * 
	 */
	private ServiceStatTable tblServiceStat = null;

	
	/**
	 * 
	 */
	private ReserveTable tblReserve = null;
	
	

	/**
	 * 
	 */
	public ServiceStatPane() {
		setLayout(new BorderLayout());
		
		JPanel header = new JPanel();
		add(header, BorderLayout.NORTH);
		
		JPanel date = new JPanel();
		header.add(date);
		
		JPanel start = new JPanel();
		date.add(start);
		
		Calendar before = Calendar.getInstance();
		before.add(Calendar.DATE, -30);
		start.add(new JLabel("Start date:"));
		startDateCtl = new JCalendarCombo(
				JCalendar.DISPLAY_DATE | JCalendar.DISPLAY_TIME, true);
		startDateCtl.setDateFormat(new SimpleDateFormat(Constants.DATE_FORMAT));
		startDateCtl.setDate(before.getTime());
		start.add(startDateCtl);
		
		JPanel end = new JPanel();
		date.add(end);
		
		end.add(new JLabel("End date:"));
		endDateCtl = new JCalendarCombo(
				JCalendar.DISPLAY_DATE | JCalendar.DISPLAY_TIME, true);
		endDateCtl.setDateFormat(new SimpleDateFormat(Constants.DATE_FORMAT));
		endDateCtl.setDate(new Date());
		end.add(endDateCtl);

		JButton refresh = new JButton("Refresh");
		header.add(refresh);
		
		JPanel body = new JPanel(new BorderLayout());
		add(body, BorderLayout.CENTER);
		
		paneHotelStat = new HotelStatPane();
		body.add(paneHotelStat, BorderLayout.NORTH);
		
		tblServiceStat = new ServiceStatTable();
		body.add(new JScrollPane(tblServiceStat), BorderLayout.CENTER);
		
		JPanel footer = new JPanel(new BorderLayout());
		add(footer, BorderLayout.SOUTH);
		
		JPanel info = new JPanel(new GridLayout(0, 1));
		footer.add(info, BorderLayout.CENTER);
		
		JPanel reserve = new JPanel(new BorderLayout());
		info.add(reserve);
		reserve.add(new JLabel("Reservation list"), BorderLayout.NORTH);
		
		tblReserve = new ReserveTable();
		tblReserve.setPreferredScrollableViewportSize(new Dimension(400, 100));
		reserve.add(new JScrollPane(tblReserve), BorderLayout.CENTER);
		

		refresh.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				
				refresh();
			}
		});
		
		
		tblServiceStat.addMouseListener(new MouseAdapter() {

			@Override
			public void mouseClicked(MouseEvent e) {
				// TODO Auto-generated method stub
				
				Service service = tblServiceStat.getSelectedService();
				if (service == null)
					return;
				
				Date startDate = getStartDate();
				Date endDate = getEndDate();
				
				tblReserve.update(startDate, endDate, service);
			}
			
		});
		
		Date startDate = getStartDate();
		Date endDate = getEndDate();
		paneHotelStat.update(startDate, endDate);
	}
	
	
	/**
	 * 
	 * @return
	 */
	private Date getStartDate() {
		return startDateCtl.getDate();
	}
		
	

	
	/**
	 * 
	 * @return
	 */
	private Date getEndDate() {
		return endDateCtl.getDate();
	}
	
	
	/**
	 * 
	 */
	public void refresh() {
		Date startDate = getStartDate();
		Date endDate = getEndDate();
		
		paneHotelStat.update(startDate, endDate);
		tblServiceStat.update(startDate, endDate);
		tblReserve.clear();
	}


}
