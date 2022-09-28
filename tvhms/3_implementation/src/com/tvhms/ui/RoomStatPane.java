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
import com.tvhms.entity.Room_RoomStat;

public class RoomStatPane extends JPanel {

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
	private RoomStatTable tblRoomStat = null;

	
	/**
	 * 
	 */
	private ReserveTable tblReserve = null;
	
	
	/**
	 * 
	 */
	private SrvExtTable tblSrvExt = null;

	
	
	/**
	 * 
	 */
	public RoomStatPane() {
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
		
		tblRoomStat = new RoomStatTable();
		body.add(new JScrollPane(tblRoomStat), BorderLayout.CENTER);
		
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
		
		JPanel extra = new JPanel(new BorderLayout());
		info.add(extra);
		extra.add(new JLabel("Service list"), BorderLayout.NORTH);

		tblSrvExt = new SrvExtTable();
		tblSrvExt.setPreferredScrollableViewportSize(new Dimension(400, 100));
		extra.add(new JScrollPane(tblSrvExt), BorderLayout.CENTER);

		refresh.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				
				refresh();
			}
		});
		
		
		tblRoomStat.addMouseListener(new MouseAdapter() {

			@Override
			public void mouseClicked(MouseEvent e) {
				// TODO Auto-generated method stub
				
				Room_RoomStat roomStat = tblRoomStat.getSelectedRoomStat();
				if (roomStat == null)
					return;
				
				Date startDate = getStartDate();
				Date endDate = getEndDate();
				
				tblReserve.update(startDate, endDate, roomStat.Room);
				tblSrvExt.update(startDate, endDate, roomStat.Room);
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
		tblRoomStat.update(startDate, endDate);
		tblReserve.clear();
		tblSrvExt.clear();
	}
}
