package com.tvhms.ui;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JScrollPane;
import javax.swing.JTextField;

import com.tvhms.entity.Account;
import com.tvhms.util.Util;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class AccountPane extends JPanel {

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
	private AccTable tblAcc = null;
	
	
	/**
	 * 
	 */
	private JButton btnRefresh = null;
	
	
	/**
	 * 
	 */
	private JTextField txtAccId = null;

	
	/**
	 * 
	 */
	private JPasswordField txtPwd = null;

	
	/**
	 * 
	 */
	private JTextField txtFullName = null;
	
	
	/**
	 * 
	 */
	private JComboBox<String> cmbRight = null;
	
	
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
	private Mode mode = Mode.update;

	
	/**
	 * 
	 */
	public AccountPane() {
		super(new BorderLayout());
		
		JPanel header = new JPanel(new FlowLayout(FlowLayout.RIGHT));
		add(header, BorderLayout.NORTH);
		btnRefresh = new JButton("Refresh");
		btnRefresh.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				refresh();
			}
		});
		header.add(btnRefresh);
		
		JPanel body = new JPanel(new BorderLayout());
		add(body, BorderLayout.CENTER);

		tblAcc = new AccTable();
		body.add(new JScrollPane(tblAcc), BorderLayout.CENTER);
		
		JPanel paneEnter = new JPanel(new BorderLayout());
		body.add(paneEnter, BorderLayout.SOUTH);
		
		JPanel data = new JPanel(new GridLayout(1, 0));
		paneEnter.add(data, BorderLayout.NORTH);
		
		JPanel col1 = new JPanel(new BorderLayout());
		data.add(col1);
		
		JPanel left1 = new JPanel(new GridLayout(0, 1));
		col1.add(left1, BorderLayout.WEST);
		
		left1.add(new JLabel("Account (*): "));
		left1.add(new JLabel("Password: (*)"));
		left1.add(new JLabel("Full name: (*)"));
		left1.add(new JLabel("Right: (*)"));
		
		JPanel right1 = new JPanel(new GridLayout(0, 1));
		col1.add(right1, BorderLayout.CENTER);
		
		txtAccId = new JTextField();
		right1.add(txtAccId);

		txtPwd = new JPasswordField();
		right1.add(txtPwd);
		txtFullName = new JTextField();
		right1.add(txtFullName);
		
		cmbRight = new JComboBox<String>(new String[] { "manager", "officer"});
		right1.add(cmbRight);

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

		
		tblAcc.addMouseListener(new MouseAdapter() {

			@Override
			public void mouseClicked(MouseEvent e) {
				// TODO Auto-generated method stub
				updateEnterControls();
				
			}
			
		});
		
		tblAcc.addKeyListener(new KeyAdapter() {

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
		
		tblAcc.update();
		if (tblAcc.getRowCount() > 0)
			tblAcc.getSelectionModel().addSelectionInterval(0, 0);

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
		
		Account acc = tblAcc.getSelectedAccount();
		if (mode == Mode.update) {
			if (acc != null) {
				txtAccId.setText(acc.getAccountId());
				txtPwd.setText(acc.getAccountPassword());
				txtFullName.setText(acc.getFullName());
				
				int right = acc.getAccountRight();
				if ((right & Account.MANAGER) == Account.MANAGER)
					cmbRight.setSelectedItem("manager");
				else if ((right & Account.OFFICER) == Account.OFFICER)
					cmbRight.setSelectedItem("officer");
			}
			else if (tblAcc.getRowCount() > 0)
				changeMode(Mode.addnew);
		}
	}

	
	
	/**
	 * 
	 */
	private void clearEnterControls() {
		txtAccId.setText("");
		txtPwd.setText("");
		txtFullName.setText("");
	}

	
	
	/**
	 * 
	 * @param flag
	 */
	private void setVisibleControls(boolean flag) {
		btnRefresh.setVisible(flag);
		tblAcc.setVisible(flag);
		txtAccId.setVisible(flag);
		txtPwd.setVisible(flag);
		txtFullName.setVisible(flag);
		cmbRight.setVisible(flag);
		btnAddNew.setVisible(flag);
		btnSave.setVisible(flag);
		btnCancel.setVisible(flag);
	}

	
	/**
	 * 
	 * @return
	 */
	private boolean validateData() {
		String accId = getAccId();
		if (accId.isEmpty()) {
			JOptionPane.showMessageDialog(
					this, "Account not allow empty", "Account empty", JOptionPane.ERROR_MESSAGE);
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
		
		String md5Pwd = getPwd().isEmpty() ? getPwd() : Util.md5Encrypt(getPwd());
		Account acc = null;
		if (mode == Mode.addnew) {
			acc = new Account(getAccId(), md5Pwd, getFullName(), getRight());
			acc = acc.save2();
			result = (acc != null);
		}
		else {
			acc = tblAcc.getSelectedAccount();
			acc.setAccountId(getAccId());
			acc.setAccountPassword(md5Pwd);
			acc.setFullName(getFullName());
			acc.setAccountRight(getRight());
			
			result = acc.update();
		}
		
		if (result) {
			tblAcc.update();
			tblAcc.selectAccount(acc.getAccountId());
			
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
		
		int selected = tblAcc.getSelectedRow();
		Account acc = tblAcc.getSelectedAccount();
		if (acc == null)
			return false;
		
		boolean result = acc.delete();
		
		tblAcc.update();
		if (selected != -1 && selected < tblAcc.getRowCount())
			tblAcc.getSelectionModel().addSelectionInterval(selected, selected);
		
		updateEnterControls();
		return result;
	}

	
	/**
	 * 
	 * @return
	 */
	private String getAccId() {
		return txtAccId.getText().trim();
	}

	
	
	/**
	 * 
	 * @return
	 */
	@SuppressWarnings("deprecation")
	private String getPwd() {
		return txtPwd.getText();
	}
	
	
	/**
	 * 
	 * @return
	 */
	private String getFullName() {
		return txtFullName.getText().trim();
	}
	
	
	/**
	 * 
	 * @return
	 */
	private int getRight() {
		String sright = (String)cmbRight.getSelectedItem();
		if (sright.equals("manager"))
			return Account.MANAGER;
		else
			return Account.OFFICER;
	}
	
	
	/**
	 * 
	 */
	public void refresh() {
		Account acc = tblAcc.getSelectedAccount();
		tblAcc.update();
		
		if (acc != null)
			tblAcc.selectAccount(acc.getAccountId());
	}
	
	
}
