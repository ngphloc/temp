package com.tvhms.ui;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.util.Date;

import javax.swing.JLabel;
import javax.swing.JPanel;

import com.tvhms.entity.HotelStat;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class HotelStatPane extends JPanel {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	private JLabel lbLivedDays = new JLabel();
	
	private JLabel lbTurns = new JLabel();

	private JLabel lbRevenue = new JLabel();
	
	private JLabel lbService = new JLabel();
	
	
	
	/**
	 * 
	 */
	public HotelStatPane() {
		setLayout(new BorderLayout());
		
		JPanel left = new JPanel(new GridLayout(0, 1));
		add(left, BorderLayout.WEST);
		
		left.add(new JLabel("Lived days:  "));
		left.add(new JLabel("Turns:  "));
		left.add(new JLabel("Revenue:  "));
		left.add(new JLabel("Service:  "));
		
		JPanel right = new JPanel(new GridLayout(0, 1));
		add(right, BorderLayout.CENTER);
		
		right.add(lbLivedDays);
		right.add(lbTurns);
		right.add(lbRevenue);
		right.add(lbService);
		
	}
	
	
	/**
	 * 
	 * @param stat
	 */
	public void update(HotelStat stat) {
		lbLivedDays.setText("" + stat.LivedDays + " days");
		lbTurns.setText("" + stat.Turns + " turns");
		lbRevenue.setText("" + stat.Revenue + " VND");
		lbService.setText("" + stat.Service + " VND");
	}
	
	
	
	/**
	 * 
	 * @param startDate
	 * @param endDate
	 */
	public void update(Date startDate, Date endDate) {
		clear();
		HotelStat stat = HotelStat.queryHotelStat(startDate, endDate);
		if (stat != null)
			update(stat);
	}
	
	
	
	/**
	 * 
	 */
	public void clear() {
		lbLivedDays.setText("");
		lbTurns.setText("");
		lbRevenue.setText("");
		lbService.setText("");
	}
	
	
	
	
}
