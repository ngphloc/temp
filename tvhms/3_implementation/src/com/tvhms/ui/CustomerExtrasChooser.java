package com.tvhms.ui;

import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.List;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextField;

import com.tvhms.entity.Customer;
import com.tvhms.entity.CustomerExtras;
import com.tvhms.entity.CustomerExtrasId;
import com.tvhms.entity.Entity;
import com.tvhms.util.Util;


/**
 * 
 * @author Administrator2
 *
 */
public class CustomerExtrasChooser extends JDialog {

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
	private int reserveId = -1;
	
	
	/**
	 * 
	 */
	private JButton btnRefresh = null;

	
	/**
	 * 
	 */
	private CustomerExtrasTable tblCustExtras = null;
	
	
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
	private JTextField txtPersonalId = null;

	
	/**
	 * 
	 */
	private JTextField txtVehicleNumber = null;
	
	
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
	private JButton btnCancel = null;

	
	/**
	 * 
	 */
	private JButton btnClose = null;

	
	/**
	 * 
	 */
	private Mode mode = Mode.update;

	
	/**
	 * 
	 * @param comp
	 * @param reserveId
	 */
	public CustomerExtrasChooser(Component comp, final int reserveId) {
		super(Util.getFrameForComponent(comp), "Adding extra customer", true);
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		setSize(600, 400);
		setLayout(new BorderLayout());
		
		this.reserveId = reserveId;
		
		JPanel header = new JPanel(new FlowLayout(FlowLayout.RIGHT));
		add(header, BorderLayout.NORTH);
		btnRefresh = new JButton("Refresh");
		btnRefresh.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				Customer customer = tblCustExtras.getSelectedCustomer();
				tblCustExtras.update(reserveId);
				
				if (customer != null && reserveId != -1)
					tblCustExtras.select(reserveId, customer.getCustomerId());
			}
		});
		header.add(btnRefresh);
		
		JPanel body = new JPanel(new BorderLayout());
		add(body, BorderLayout.CENTER);

		tblCustExtras = new CustomerExtrasTable();
		body.add(new JScrollPane(tblCustExtras), BorderLayout.CENTER);
		
		JPanel paneEnter = new JPanel(new BorderLayout());
		body.add(paneEnter, BorderLayout.SOUTH);
		
		JPanel data = new JPanel(new GridLayout(1, 0));
		paneEnter.add(data, BorderLayout.NORTH);
		
		JPanel col1 = new JPanel(new BorderLayout());
		data.add(col1);
		
		JPanel left1 = new JPanel(new GridLayout(0, 1));
		col1.add(left1, BorderLayout.WEST);
		
		left1.add(new JLabel("Full name (*): "));
		left1.add(new JLabel("Id card: "));
		left1.add(new JLabel("Vehicle number: "));
		
		JPanel right1 = new JPanel(new GridLayout(0, 1));
		col1.add(right1, BorderLayout.CENTER);
		
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
				if (mode == Mode.update) {
					JOptionPane.showMessageDialog(
							null, "In update mode", "In update mode", JOptionPane.INFORMATION_MESSAGE);
					return;
				}
				
				CustomerChooser chooser = new CustomerChooser(btnCustomer);
				Customer selectedCustomer = chooser.getSelectedCustomer();
				if (selectedCustomer == null)
					return;
				
				CustomerExtrasId id = new CustomerExtrasId(reserveId, selectedCustomer.getCustomerId());
				CustomerExtras extras = (CustomerExtras)Entity.load(
						CustomerExtras.class, id);
				if (extras != null) {
					JOptionPane.showMessageDialog(null, "Customer exists", "Customer exists", JOptionPane.INFORMATION_MESSAGE);
					return;
				}
				
				txtCustomer.setCustomer(selectedCustomer);
				txtPersonalId.setText(selectedCustomer.getPersonalId());
				txtVehicleNumber.setText(selectedCustomer.getVehicleNumber());
			}
		});

		txtPersonalId = new JTextField();
		right1.add(txtPersonalId);
		txtVehicleNumber = new JTextField();
		right1.add(txtVehicleNumber);

		JPanel footer = new JPanel(new BorderLayout());
		add(footer, BorderLayout.SOUTH);
		
		JPanel toolbar1 = new JPanel();
		footer.add(toolbar1, BorderLayout.NORTH);
		
		btnAddNew = new JButton("Add new");
		toolbar1.add(btnAddNew);
		btnAddNew.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				changeMode(Mode.addnew);
			}
		});
		
		btnSave = new JButton("Save");
		toolbar1.add(btnSave);
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
		
		btnCancel = new JButton("Cancel");
		toolbar1.add(btnCancel);
		btnCancel.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				changeMode(Mode.update);
			}
		});

		
		JPanel toolbar2 = new JPanel();
		footer.add(toolbar2, BorderLayout.SOUTH);
		
		btnClose = new JButton("Close");
		toolbar2.add(btnClose);
		btnClose.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				dispose();
			}
		});
		
		
		tblCustExtras.addMouseListener(new MouseAdapter() {

			@Override
			public void mouseClicked(MouseEvent e) {
				// TODO Auto-generated method stub
				updateEnterControls();
			}
			
		});
		
		tblCustExtras.addKeyListener(new KeyAdapter() {

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
		
		tblCustExtras.update(reserveId);
		if (tblCustExtras.getRowCount() > 0)
			tblCustExtras.getSelectionModel().addSelectionInterval(0, 0);

		changeMode(Mode.update);
		
		setVisible(true);
	}
	
	
	/**
	 * 
	 * @param mode
	 */
	private void changeMode(Mode mode) {
		setVisibleControls(true);
		
		if (mode == Mode.addnew) {
			btnAddNew.setVisible(false);
			btnCancel.setVisible(true);
			
			btnSave.setText("Save");
		}
		else if (mode == Mode.update) {
			btnAddNew.setVisible(true);
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
		
		Customer customer = tblCustExtras.getSelectedCustomer();
		if (mode == Mode.update) {
			if (customer != null) {
				txtCustomer.setCustomer(customer);
				txtPersonalId.setText(customer.getPersonalId());
				txtVehicleNumber.setText(customer.getVehicleNumber());
			}
			else if (tblCustExtras.getRowCount() > 0)
				changeMode(Mode.addnew);
		}
	}

	
	
	/**
	 * 
	 */
	private void clearEnterControls() {
		txtCustomer.setCustomer(null);
		txtPersonalId.setText("");
		txtVehicleNumber.setText("");
	}

	
	
	/**
	 * 
	 * @param flag
	 */
	private void setVisibleControls(boolean flag) {
		btnRefresh.setVisible(flag);
		tblCustExtras.setVisible(flag);
		txtCustomer.setVisible(flag);
		btnCustomer.setVisible(flag);
		txtPersonalId.setVisible(flag);
		txtVehicleNumber.setVisible(flag);
		btnAddNew.setVisible(flag);
		btnSave.setVisible(flag);
		btnCancel.setVisible(flag);
		btnClose.setVisible(flag);
	}

	
	/**
	 * 
	 * @return
	 */
	private boolean validateData() {
		String customerName = getCustomerName();
		if (customerName.isEmpty()) {
			JOptionPane.showMessageDialog(
					this, "Customer not allow empty", "Customer empty", JOptionPane.ERROR_MESSAGE);
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
		
		Customer customer = txtCustomer.getCustomer();
		if (customer == null) {
			customer = new Customer(getCustomerName(), getPersonalId(), getVehicleNumber());
			customer = customer.save2();
			if (customer == null)
				return false;
		}
		else {
			customer.setFullName(getCustomerName());
			customer.setPersonalId(getPersonalId());
			customer.setVehicleNumber(getVehicleNumber());
			if (!customer.update())
				return false;
		}
		
		CustomerExtras extras = null;
		boolean result = false;
		if (mode == Mode.update) {
			extras = tblCustExtras.getSelectedCustomerExtras();
			if (extras == null)
				return false;
			
			extras.setCustomerExtrasId(
					new CustomerExtrasId(reserveId, customer.getCustomerId()));
			result = extras.update();
		}
		else if (mode == Mode.addnew) {
			extras = new CustomerExtras();
			
			extras.setCustomerExtrasId(
					new CustomerExtrasId(reserveId, customer.getCustomerId()));
			result = extras.save() != null;
		}
		
		if (result) {
			tblCustExtras.update(reserveId);
			tblCustExtras.select(reserveId, customer.getCustomerId());
			
			if (mode == Mode.addnew)
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
		
		int selected = tblCustExtras.getSelectedRow();
		CustomerExtras extras = tblCustExtras.getSelectedCustomerExtras();
		if (extras == null)
			return false;
		
		boolean result = extras.delete();
		
		tblCustExtras.update(reserveId);
		if (selected != -1 && selected < tblCustExtras.getRowCount())
			tblCustExtras.getSelectionModel().addSelectionInterval(selected, selected);
		
		updateEnterControls();
		return result;
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
	private String getPersonalId() {
		return txtPersonalId.getText().trim();
	}
	
	
	/**
	 * 
	 * @return
	 */
	private String getVehicleNumber() {
		return txtVehicleNumber.getText().trim();
	}

	
	/**
	 * 
	 * @return
	 */
	@SuppressWarnings("unchecked")
	public List<CustomerExtras> getCustomerExtrasList() {
		return (List<CustomerExtras>) Entity.load(
				"from CustomerExtras c where c.customerExtrasId.reserveId = " + reserveId);
	}
	
	
}
