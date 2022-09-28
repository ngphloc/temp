package com.tvhms.ui;

import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.List;
import java.util.Vector;

import javax.swing.BoxLayout;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFormattedTextField;
import javax.swing.JLabel;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;
import javax.swing.JScrollPane;
import javax.swing.SwingUtilities;
import javax.swing.text.NumberFormatter;

import org.freixas.jcalendar.JCalendar;
import org.freixas.jcalendar.JCalendarCombo;

import com.tvhms.Constants;
import com.tvhms.entity.Customer;
import com.tvhms.entity.CustomerExtras;
import com.tvhms.entity.Entity;
import com.tvhms.entity.Reserve;
import com.tvhms.entity.Reserve.Status;
import com.tvhms.entity.Room;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class EnterReservePane extends JPanel {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 * @author Administrator2
	 * @version 1.0
	 *
	 */
	private enum Mode {addnew, update};
	
	
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
	private JButton btnRefresh = null;
	
	/**
	 * 
	 */
	private ReserveTable tblReserve = null;
	
	/**
	 * 
	 */
	private JPanel paneEnter = null;
	
	
	/**
	 * 
	 */
	private JComboBox<Room> cmbRoom = null;
	
	
	/**
	 * 
	 */
	private CustomerTextField txtCustomer = null;
	
	
	/**
	 * 
	 */
	private JButton btnCustomer = null;
	
	
	/**
	 * 
	 */
	private JComboBox<Status> cmbStatus = null;
	
	
	/**
	 * 
	 */
	private JCalendarCombo txtBeginDate = null;
	
	/**
	 * 
	 */
	private JFormattedTextField txtTotalDays = null;
	
	/**
	 * 
	 */
	private JFormattedTextField txtLivedDays = null;
	
	/**
	 * 
	 */
	private JFormattedTextField txtTotalPayment = null;
	
	/**
	 * 
	 */
	private JFormattedTextField txtPaid = null;

	/**
	 * 
	 */
	private JFormattedTextField txtNumberPersons = null;

	
	/**
	 * 
	 */
	private JButton btnCustomerExtras = null;
	
	
	/**
	 * 
	 */
	private JButton btnAddNew = null;
	
	
	/**
	 * 
	 */
	private JButton btnSave = null;

	
	/**
	 * 
	 */
	private JButton btnPaid = null;

	
	/**
	 * 
	 */
	private JButton btnCancel = null;
	
	
	/**
	 * 
	 */
	private SrvExtDBTable tblSrvExt = null;
	
	
	/**
	 * 
	 */
	private Mode mode = Mode.update;
	
	
	/**
	 * 
	 */
	public EnterReservePane() {
		super();
		setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
		
		JPanel date = new JPanel();
		add(date);
		
		JPanel start = new JPanel();
		date.add(start);
		
		Calendar before = Calendar.getInstance();
		before.add(Calendar.DATE, -10);
		start.add(new JLabel("Start date: "));
		startDateCtl = new JCalendarCombo(
				JCalendar.DISPLAY_DATE | JCalendar.DISPLAY_TIME, true);
		startDateCtl.setDateFormat(new SimpleDateFormat(Constants.DATE_FORMAT));
		startDateCtl.setDate(before.getTime());
		start.add(startDateCtl);
		
		JPanel end = new JPanel();
		date.add(end);
		
		Calendar now = Calendar.getInstance();
		end.add(new JLabel("End date: "));
		endDateCtl = new JCalendarCombo(JCalendar.DISPLAY_DATE | JCalendar.DISPLAY_TIME, true);
		endDateCtl.setDateFormat(new SimpleDateFormat(Constants.DATE_FORMAT));
		endDateCtl.setDate(now.getTime());
		end.add(endDateCtl);

		btnRefresh = new JButton("Refresh");
		date.add(btnRefresh);
		
		tblReserve = new ReserveTable();
		tblReserve.setPreferredScrollableViewportSize(new Dimension(800, 600));
		add(new JScrollPane(tblReserve));
		add(new JLabel(" "));

		paneEnter = new JPanel(new BorderLayout());
		add(paneEnter);
		
		JPanel data = new JPanel(new GridLayout(1, 0));
		paneEnter.add(data, BorderLayout.NORTH);
		
		JPanel col1 = new JPanel(new BorderLayout());
		data.add(col1);
		
		JPanel left1 = new JPanel(new GridLayout(0, 1));
		col1.add(left1, BorderLayout.WEST);
		
		left1.add(new JLabel("Room (*): "));
		left1.add(new JLabel("Customer (*): "));
		left1.add(new JLabel("Status (*): "));
		left1.add(new JLabel("Begin date (*): "));
		left1.add(new JLabel("Total days (*): "));
		
		JPanel right1 = new JPanel(new GridLayout(0, 1));
		col1.add(right1, BorderLayout.CENTER);
		
		cmbRoom = new JComboBox<>();
		right1.add(cmbRoom);
		
		JPanel cust = new JPanel(new BorderLayout());
		right1.add(cust);
		txtCustomer = new CustomerTextField();
		cust.add(txtCustomer, BorderLayout.CENTER);
		btnCustomer = new JButton("...");
		cust.add(btnCustomer, BorderLayout.EAST);
		btnCustomer.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				CustomerChooser chooser = new CustomerChooser(btnCustomer);
				Customer selectedCustomer = chooser.getSelectedCustomer();
				if (selectedCustomer != null)
					txtCustomer.setCustomer(selectedCustomer);
			}
		});
		
		cmbStatus = new JComboBox<Reserve.Status>(new Vector<>(Reserve.queryStatusList()));
		right1.add(cmbStatus);

		txtBeginDate = new JCalendarCombo(JCalendar.DISPLAY_DATE | JCalendar.DISPLAY_TIME, true);
		txtBeginDate.setDateFormat(new SimpleDateFormat(Constants.DATE_FORMAT));
		right1.add(txtBeginDate);
		
		txtTotalDays = new JFormattedTextField(new NumberFormatter());
		right1.add(txtTotalDays);
		
		data.add(new JLabel(""));
		
		JPanel col2 = new JPanel(new BorderLayout());
		data.add(col2);

		JPanel left2 = new JPanel(new GridLayout(0, 1));
		col2.add(left2, BorderLayout.WEST);
		
		left2.add(new JLabel("Lived days: "));
		left2.add(new JLabel("Total payment: "));
		left2.add(new JLabel("Paid: "));
		left2.add(new JLabel("Number persons: "));

		JPanel right2 = new JPanel(new GridLayout(0, 1));
		col2.add(right2, BorderLayout.CENTER);
		
		txtLivedDays = new JFormattedTextField(new NumberFormatter());
		right2.add(txtLivedDays);
		
		txtTotalPayment = new JFormattedTextField(new NumberFormatter());
		right2.add(txtTotalPayment);
		
		txtPaid = new JFormattedTextField(new NumberFormatter());
		right2.add(txtPaid);
		
		JPanel custExtras = new JPanel(new BorderLayout());
		right2.add(custExtras);
		txtNumberPersons = new JFormattedTextField(new NumberFormatter());
		custExtras.add(txtNumberPersons, BorderLayout.CENTER);
		btnCustomerExtras = new JButton("...");
		custExtras.add(btnCustomerExtras, BorderLayout.EAST);
		btnCustomerExtras.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				Reserve reserve = getReserve();
				if (reserve == null) {
					JOptionPane.showMessageDialog(
						null, "No reservation", "No reservation", JOptionPane.INFORMATION_MESSAGE);
					return;
				}
				
				CustomerExtrasChooser chooser = new CustomerExtrasChooser(
						btnCustomerExtras, reserve.getReserveId());
				
				List<CustomerExtras> list = chooser.getCustomerExtrasList();
				txtNumberPersons.setValue(1 + list.size());
			}
		});

		
		JPanel buttons = new JPanel();
		paneEnter.add(buttons, BorderLayout.SOUTH);
		btnAddNew = new JButton("Add new");
		buttons.add(btnAddNew);
		btnSave = new JButton("Save");
		buttons.add(btnSave);
		btnPaid = new JButton("Paid");
		buttons.add(btnPaid);
		btnCancel = new JButton("Cancel");
		buttons.add(btnCancel);
		
		JPanel srvExt = new JPanel(new BorderLayout());
		add(srvExt, BorderLayout.CENTER);
		
		srvExt.add(new JLabel("Service list"), BorderLayout.NORTH);
		tblSrvExt = new SrvExtDBTable();
		tblSrvExt.createControlPanel();
		srvExt.add(tblSrvExt, BorderLayout.CENTER);
		
		tblReserve.addMouseListener(new MouseAdapter() {

			@Override
			public void mouseClicked(MouseEvent e) {
				// TODO Auto-generated method stub
				updateEnterControls();
				
				if(SwingUtilities.isRightMouseButton(e) ) {
					JPopupMenu contextMenu = createReserveCtxMenu();
					if(contextMenu != null) 
						contextMenu.show((Component)e.getSource(), e.getX(), e.getY());
				}
			}
			
		});
		
		tblReserve.addKeyListener(new KeyAdapter() {

			@Override
			public void keyPressed(KeyEvent e) {
				// TODO Auto-generated method stub
				if (e.getKeyCode() == KeyEvent.VK_DELETE) {
					int confirm = JOptionPane.showConfirmDialog(
							null, 
							"Are you sure to remove this reservation?", 
							"Remove reservation", JOptionPane.OK_CANCEL_OPTION, 
							JOptionPane.QUESTION_MESSAGE);
					if (confirm == JOptionPane.OK_OPTION)
						remove();
				}
				
			}
			
		});
		
		
		btnAddNew.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				changeMode(Mode.addnew);
			}
		});
		
		
		btnSave.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if (save()) {
					JOptionPane.showMessageDialog(
						null, 
						"Update data successfully", 
						"Update data successfully", 
						JOptionPane.INFORMATION_MESSAGE);
					
					return;
				}
				else {
					JOptionPane.showMessageDialog(
							null, 
							"Update data fail", 
							"Update data fail", 
							JOptionPane.ERROR_MESSAGE);
				}
				
			}
		});
		
		btnPaid.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				paid();
			}
		});
		
		btnCancel.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				changeMode(Mode.update);
			}
		});

		btnRefresh.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				Date startDate = getStartDate();
				Date endDate = getEndDate();
				
				tblReserve.update(startDate, endDate);
				changeMode(Mode.update);
			}
		});
		
		Date startDate = getStartDate();
		Date endDate = getEndDate();
		tblReserve.update(startDate, endDate);
		if (tblReserve.getRowCount() > 0)
			tblReserve.getSelectionModel().addSelectionInterval(0, 0);
		
		changeMode(Mode.update);
	}
	
	
	
	/**
	 * 
	 * @param mode
	 */
	private void changeMode(Mode mode) {
		setVisibleControls(true);
		
		if (mode == Mode.addnew) {
			btnAddNew.setVisible(false);
			btnPaid.setVisible(false);
			tblSrvExt.setVisible(false);
			btnCancel.setVisible(true);
			
			btnSave.setText("Save");
		}
		else if (mode == Mode.update) {
			btnAddNew.setVisible(true);
			btnPaid.setVisible(true);
			tblSrvExt.setVisible(true);
			btnCancel.setVisible(false);
			
			btnSave.setText("Update");
		}
		
		this.mode = mode;
		updateEnterControls();
	}
	
	
	/**
	 * 
	 */
	private void updateEnterControls() {
		clearEnterControls();
		List<Room> avRoomList = Room.queryRoomList(Status.available);
		cmbRoom.setModel(new DefaultComboBoxModel<Room>(new Vector<Room>(avRoomList)));
		btnAddNew.setVisible(mode == Mode.update && avRoomList.size() > 0);
		
		Reserve reserve = getReserve();
		tblSrvExt.setVisible(mode == Mode.update && reserve != null);
		btnPaid.setVisible(mode == Mode.update && reserve != null && reserve.getStatus() == Status.living);
		
		if (mode == Mode.update) {
			if (reserve != null) {
				Room room = reserve.getRoom();
				if (!avRoomList.contains(room))
					cmbRoom.addItem(room);
				
				updateEnterControls(reserve);
			}
			else if (tblReserve.getRowCount() == 0)
				changeMode(Mode.addnew);
		}
	}
	
	
	
	/**
	 * 
	 * @param reserve
	 */
	private void updateEnterControls(Reserve reserve) {
		cmbRoom.setSelectedItem(reserve.getRoom());
		txtCustomer.setCustomer(reserve.getCustomer());
		cmbStatus.setSelectedItem(reserve.getStatus());
		
		txtBeginDate.setDate(reserve.getBeginDate());
		
		txtTotalDays.setValue(reserve.getTotalDays());
		txtLivedDays.setValue(reserve.getLivedDays());
		txtTotalPayment.setValue(reserve.getTotalPayment());
		txtPaid.setValue(reserve.getPaid());
		txtNumberPersons.setValue(reserve.getNumberPersons());
		
		tblSrvExt.update(reserve.getReserveId());
	}
	
	
	/**
	 * 
	 */
	private void clearEnterControls() {
		if (cmbRoom.getItemCount() > 0)
			cmbRoom.setSelectedIndex(0);
		txtCustomer.setCustomer(null);
		cmbStatus.setSelectedItem(Status.living);
		txtBeginDate.setDate(new Date());
		txtTotalDays.setValue(0);
		txtLivedDays.setValue(0);
		txtTotalPayment.setValue(0);
		txtPaid.setValue(0);
		txtNumberPersons.setValue(1);
		
		tblSrvExt.update(-1);
	}
	
	

	
	/**
	 * 
	 * @return
	 */
	private JPopupMenu createReserveCtxMenu() {
		Reserve reserve = getReserve();
		if (reserve == null)
			return null;
		
		JPopupMenu ctxMenu = new JPopupMenu();
		
		JMenuItem mniPaid = null;
		if (reserve.getStatus() != Status.available) {
			mniPaid = new JMenuItem("Paid");
			mniPaid.addActionListener(new ActionListener() {
				
				@Override
				public void actionPerformed(ActionEvent e) {
					// TODO Auto-generated method stub
					paid();
				}
			});
			ctxMenu.add(mniPaid);
		}
		
		
		JMenuItem mniRemove = null;
		if (mniPaid != null)
			ctxMenu.addSeparator();
		mniRemove = new JMenuItem("Remove");
		mniRemove.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				int confirm = JOptionPane.showConfirmDialog(
						null, 
						"Are you sure to remove this reservation?", 
						"Remove reservation", JOptionPane.OK_CANCEL_OPTION, 
						JOptionPane.QUESTION_MESSAGE);
				if (confirm == JOptionPane.OK_OPTION)
					remove();
			}
		});
		ctxMenu.add(mniRemove);
		
		
		return ctxMenu;
		
	}
	
	
	
	/**
	 * 
	 */
	private void paid() {
		if (mode == Mode.addnew) {
			JOptionPane.showMessageDialog(
					this, 
					"In add new mode", 
					"In add new mode", JOptionPane.INFORMATION_MESSAGE);
			return;
		}
		
		Reserve reserve = getReserve();
		if (reserve == null) {
			JOptionPane.showMessageDialog(
					this, 
					"No reserve to be paid", 
					"No reserve to be paid", JOptionPane.INFORMATION_MESSAGE);
			return;
		}
		
		if (reserve.getStatus() == Status.available) {
			JOptionPane.showMessageDialog(
					this, 
					"Room available", 
					"Room available", JOptionPane.INFORMATION_MESSAGE);
			return;
		}
		
		reserve.setStatus(Status.available);
		reserve.setLivedDays(reserve.getTotalDays());
		reserve.setPaid(reserve.getTotalPayment());
		reserve.update();
		
		Date now = new Date();
		this.endDateCtl.setDate(now);
		tblReserve.update(getStartDate(), now);
		tblReserve.selectReserveId(reserve.getReserveId());
		
		updateEnterControls();
	}
	
	
	
	
	/**
	 * 
	 * @return
	 */
	private Reserve getReserve() {
		return tblReserve.getSelectedReserve();
	}
	
	
	/**
	 * 
	 * @return
	 */
	private Room getRoom() {
		return (Room)cmbRoom.getSelectedItem();
	}
	
	
	/**
	 * 
	 * @return
	 */
	private String getCustomerName() {
		return txtCustomer.getText().trim();
	}

	
	/**
	 * 
	 * @return
	 */
	private Status getStatus() {
		return (Status)cmbStatus.getSelectedItem();
	}
	
	
	/**
	 * 
	 * @return
	 */
	private int getTotalDays() {
		Object totalDays = txtTotalDays.getValue();
		if (totalDays == null || !(totalDays instanceof Number) )
			return 0;
		
		Number nTotalDays = (Number)totalDays;
		if (Float.isNaN(nTotalDays.floatValue()))
			return 0;
		
		if (nTotalDays.intValue() <= 0)
			return 0;
		
		return nTotalDays.intValue();
	}
	
	
	/**
	 * 
	 * @return
	 */
	private int getLivedDays() {
		Object livedDays = txtLivedDays.getValue();
		if (livedDays == null || !(livedDays instanceof Number) )
			return 0;
		
		Number nLivedDays = (Number)livedDays;
		if (Float.isNaN(nLivedDays.floatValue()))
			return 0;
		
		if (nLivedDays.intValue() <= 0)
			return 0;
		
		return nLivedDays.intValue();
	}

	
	/**
	 * 
	 * @return
	 */
	private float getTotalPayment() {
		Object payment = txtTotalPayment.getValue();
		if (payment == null || !(payment instanceof Number) )
			return 0;
		
		Number nPayment = (Number)payment;
		if (Float.isNaN(nPayment.floatValue()))
			return 0;
		
		if (nPayment.intValue() <= 0)
			return 0;
		
		return nPayment.floatValue();
	}
	
	
	/**
	 * 
	 * @return
	 */
	private float getPaid() {
		Object paid = txtPaid.getValue();
		if (paid == null || !(paid instanceof Number) )
			return 0;
		
		Number nPaid = (Number)paid;
		if (Float.isNaN(nPaid.floatValue()))
			return 0;
		
		if (nPaid.intValue() <= 0)
			return 0;
		
		return nPaid.floatValue();
	}

	
	/**
	 * 
	 * @return
	 */
	private int getNumberPersons() {
		Object numberPersons = txtNumberPersons.getValue();
		if (numberPersons == null || !(numberPersons instanceof Number) )
			return 0;
		
		Number nNumberPersons = (Number)numberPersons;
		if (Float.isNaN(nNumberPersons.floatValue()))
			return 0;
		
		if (nNumberPersons.intValue() <= 0)
			return 0;
		
		return nNumberPersons.intValue();
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	private boolean validateData() {
		Room room = getRoom();
		if (room == null) {
			JOptionPane.showMessageDialog(
					this, "Room not allow empty", "Empty room", JOptionPane.ERROR_MESSAGE);
			return false;
		}
		
		String customerName = getCustomerName();
		if (customerName.isEmpty()) {
			JOptionPane.showMessageDialog(
					this, "Customer not allow empty", "Customer empty", JOptionPane.ERROR_MESSAGE);
			return false;
		}

		Date beginDate = getBeginDate();
		if (beginDate == null) {
			JOptionPane.showMessageDialog(
					this, "Begin date not allow empty", "Begin date empty", JOptionPane.ERROR_MESSAGE);
			return false;
		}
		
		int totalDays = getTotalDays();
		if (totalDays == 0) {
			JOptionPane.showMessageDialog(
					this, "Invalid total days", "Invalid total days", JOptionPane.ERROR_MESSAGE);
			return false;
		}
		
		int livedDays = getLivedDays();
		if (livedDays > totalDays) {
			JOptionPane.showMessageDialog(
					this, "Invalid lived days", "Invalid lived days", JOptionPane.ERROR_MESSAGE);
			return false;
		}
		
		float totalPayment = getTotalPayment();
		float paid = getPaid();
		if (paid > totalPayment) {
			JOptionPane.showMessageDialog(
					this, "Invalid payment", "Invalid payment", JOptionPane.ERROR_MESSAGE);
			return false;
		}
		
		int numberPersons = getNumberPersons();
		if (numberPersons == 0) {
			JOptionPane.showMessageDialog(
					this, "Number persons must be greater than 0", "Zero number persons", JOptionPane.ERROR_MESSAGE);
			return false;
		}
		
		return true;
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	private boolean save() {
		if (!validateData())
			return false;
		
		Reserve reserve = null;
		Customer customer = txtCustomer.getCustomer();
		String customerName = getCustomerName();
		if (customer == null)
			reserve = new Reserve(getRoom().getRoomName(), customerName, getTotalDays());
		else {
			if (customer.queryCustomerNameIntel().equals(customerName))
				reserve = new Reserve(getRoom().getRoomName(), customer.getCustomerId(), getTotalDays());
			else
				reserve = new Reserve(getRoom().getRoomName(), customerName, getTotalDays());
		}
		
		reserve.setStatus(getStatus());
		reserve.setBeginDate(getBeginDate());
		reserve.setLivedDays(getLivedDays());
		float totalPayment = getTotalPayment();
		if (totalPayment == 0) {
			totalPayment = reserve.getTotalPayment();
			txtTotalPayment.setValue(totalPayment);
		}
		
		reserve.setPaid(getPaid());
		reserve.setNumberPersons(getNumberPersons());
		
		boolean result = false;
		boolean addnew = false;
		if (mode == Mode.addnew) {
			reserve = reserve.save2();
			result = (reserve != null);
			addnew = true;
		}
		else {
			int reserveId = getReserve().getReserveId();
			reserve.setReserveId(reserveId);
			result = reserve.update();
			if (result)
				reserve = (Reserve)Entity.load(Reserve.class, reserveId);
			result = (reserve != null);
		}
		
		if (result) {
			Date now = new Date();
			this.endDateCtl.setDate(now);
			
			tblReserve.update(getStartDate(), now);
			tblReserve.selectReserveId(reserve.getReserveId());
			try {
				tblSrvExt.refresh();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			if (addnew)
				changeMode(Mode.update);
			else
				updateEnterControls();
		}
		
		return result;
	}
	
	
	/**
	 * 
	 * @return
	 */
	private boolean remove() {
		if (mode == Mode.addnew)
			return false;
		
		int selected = tblReserve.getSelectedRow();
		Reserve reserve = getReserve();
		boolean result = reserve.delete();
		
		Date now = new Date();
		this.endDateCtl.setDate(now);
		tblReserve.update(getStartDate(), now);
		if (selected != -1 && selected < tblReserve.getRowCount())
			tblReserve.getSelectionModel().addSelectionInterval(selected, selected);
		
		updateEnterControls();
		return result;
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
	private Date getBeginDate() {
		return txtBeginDate.getDate();
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
	 * @param flag
	 */
	@SuppressWarnings("unused")
	private void enableControls(boolean flag) {
		startDateCtl.setEnabled(flag);
		endDateCtl.setEnabled(flag);
		btnRefresh.setEnabled(flag);
		tblReserve.setEnabled(flag);
		paneEnter.setEnabled(flag);
		cmbRoom.setEnabled(flag);
		txtCustomer.setEnabled(flag);
		btnCustomer.setEnabled(flag);
		txtBeginDate.setEnabled(flag);
		txtTotalDays.setEnabled(flag);
		txtLivedDays.setEnabled(flag);
		txtTotalPayment.setEnabled(flag);
		txtPaid.setEnabled(flag);
		txtNumberPersons.setEnabled(flag);
		btnCustomerExtras.setEnabled(flag);
		btnAddNew.setEnabled(flag);
		btnSave.setEnabled(flag);
		btnPaid.setEnabled(flag);
		btnCancel.setEnabled(flag);
		tblSrvExt.setEnabled(flag);
	}
	
	
	
	/**
	 * 
	 * @param flag
	 */
	private void setVisibleControls(boolean flag) {
		startDateCtl.setVisible(flag);
		endDateCtl.setVisible(flag);
		btnRefresh.setVisible(flag);
		tblReserve.setVisible(flag);
		paneEnter.setVisible(flag);
		cmbRoom.setVisible(flag);
		txtCustomer.setVisible(flag);
		btnCustomer.setVisible(flag);
		txtBeginDate.setVisible(flag);
		txtTotalDays.setVisible(flag);
		txtLivedDays.setVisible(flag);
		txtTotalPayment.setVisible(flag);
		txtPaid.setVisible(flag);
		txtNumberPersons.setVisible(flag);
		btnCustomerExtras.setVisible(flag);
		btnAddNew.setVisible(flag);
		btnSave.setVisible(flag);
		btnPaid.setVisible(flag);
		btnCancel.setVisible(flag);
		tblSrvExt.setVisible(flag);
	}
	
	
	
	/**
	 * 
	 */
	public void clear() {
		if (tblReserve != null) {
			tblReserve.clear();
		}

	
		if (tblSrvExt != null) {
			tblSrvExt.clear();
			tblSrvExt.cleanup();
			try {
				tblSrvExt.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			tblSrvExt = null;
		}
	}
	
	
}
