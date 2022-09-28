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

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextField;

import com.tvhms.entity.Customer;
import com.tvhms.util.Util;


/**
 * 
 * @author Administrator2
 *
 */
public class CustomerChooser extends JDialog {

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
	private CustomerTable tblCustomer = null;
	
	
	/**
	 * 
	 */
	private JButton btnRefresh = null;
	
	
	/**
	 * 
	 */
	private CustomerTextField txtCustomer = null;

	
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
	 */
	private Customer selectedCustomer = null;
	
	
	/**
	 * 
	 * @param comp
	 */
	public CustomerChooser(Component comp) {
		super(Util.getFrameForComponent(comp), "Customer adding / selecting", true);
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		setSize(600, 400);
		setLayout(new BorderLayout());
		
		
		JPanel header = new JPanel(new FlowLayout(FlowLayout.RIGHT));
		add(header, BorderLayout.NORTH);
		btnRefresh = new JButton("Refresh");
		btnRefresh.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				Customer customer = tblCustomer.getSelectedCustomer();
				tblCustomer.update();
				
				if (customer != null)
					tblCustomer.selectCustomer(customer.getCustomerId());
			}
		});
		header.add(btnRefresh);
		
		JPanel body = new JPanel(new BorderLayout());
		add(body, BorderLayout.CENTER);

		tblCustomer = new CustomerTable();
		body.add(new JScrollPane(tblCustomer), BorderLayout.CENTER);
		
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
		
		txtCustomer = new CustomerTextField();
		right1.add(txtCustomer);

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
				selectCustomer();
			}
		});
		
		
		tblCustomer.addMouseListener(new MouseAdapter() {

			@Override
			public void mouseClicked(MouseEvent e) {
				// TODO Auto-generated method stub
				updateEnterControls();
				
				if (e.getClickCount() >= 2)
					selectCustomer();
			}
			
		});
		
		tblCustomer.addKeyListener(new KeyAdapter() {

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
		
		tblCustomer.update();
		if (tblCustomer.getRowCount() > 0)
			tblCustomer.getSelectionModel().addSelectionInterval(0, 0);

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
		
		Customer customer = tblCustomer.getSelectedCustomer();
		if (mode == Mode.update) {
			if (customer != null) {
				txtCustomer.setCustomer(customer);
				txtPersonalId.setText(customer.getPersonalId());
				txtVehicleNumber.setText(customer.getVehicleNumber());
			}
			else if (tblCustomer.getRowCount() > 0)
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
		tblCustomer.setVisible(flag);
		txtCustomer.setVisible(flag);
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
		
		boolean result = false;
		Customer customer = txtCustomer.getCustomer();
		if (customer == null) {
			customer = new Customer(getCustomerName(), getPersonalId(), getVehicleNumber());
			customer = customer.save2();
			result = (customer != null);
		}
		else {
			customer.setFullName(getCustomerName());
			customer.setPersonalId(getPersonalId());
			customer.setVehicleNumber(getVehicleNumber());
			result = customer.update();
		}
		
		
		if (result) {
			tblCustomer.update();
			tblCustomer.selectCustomer(customer.getCustomerId());
			
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
		
		int selected = tblCustomer.getSelectedRow();
		Customer customer = tblCustomer.getSelectedCustomer();
		if (customer == null)
			return false;
		
		boolean result = customer.delete();
		
		tblCustomer.update();
		if (selected != -1 && selected < tblCustomer.getRowCount())
			tblCustomer.getSelectionModel().addSelectionInterval(selected, selected);
		
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
	public Customer getSelectedCustomer() {
		return selectedCustomer;
	}
	
	
	/**
	 * 
	 */
	private void selectCustomer() {
		Customer customer = tblCustomer.getSelectedCustomer();
		if (customer == null) {
			JOptionPane.showMessageDialog(
					null, 
					"Please select one customer", 
					"No customer selected", JOptionPane.ERROR_MESSAGE);
			return;
		}
		selectedCustomer = customer;
		dispose();
	}
	
	
	
}
