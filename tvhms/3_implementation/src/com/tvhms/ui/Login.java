package com.tvhms.ui;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

import com.tvhms.entity.Account;
import com.tvhms.entity.Entity;
import com.tvhms.util.Util;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class Login extends JDialog {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	
	/**
	 * 
	 */
	private JTextField txtAccount = null;
	
	
	/**
	 * 
	 */
	private JPasswordField txtPwd = null;
	
	
	/**
	 * 
	 */
	private JComboBox<String> cmbLoginAs = null;
	
	
	/**
	 * 
	 */
	public Login() {
		super((JFrame)null, "Login", true);
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		setSize(300, 200);
		setLayout(new BorderLayout());
		
		JPanel main = new JPanel(new BorderLayout());
		add(main, BorderLayout.NORTH);
		
		JPanel header = new JPanel();
		main.add(header, BorderLayout.NORTH);
		header.add(new JLabel("Login information"));
		
		JPanel body = new JPanel(new BorderLayout());
		main.add(body, BorderLayout.CENTER);
		
		JPanel left = new JPanel(new GridLayout(0, 1));
		body.add(left, BorderLayout.WEST);
		
		left.add(new JLabel("Account: "));
		left.add(new JLabel("Password: "));
		left.add(new JLabel("Login as: "));

		JPanel right = new JPanel(new GridLayout(0, 1));
		body.add(right, BorderLayout.CENTER);
		
		txtAccount = new JTextField("manager");
		right.add(txtAccount);
		
		txtPwd = new JPasswordField();
		right.add(txtPwd);

		cmbLoginAs = new JComboBox<>(new String[] {"manager", "officer"} );
		right.add(cmbLoginAs);
		
		JPanel footer = new JPanel();
		main.add(footer, BorderLayout.SOUTH);
		
		JButton btnLogin = new JButton("Login");
		footer.add(btnLogin);
		btnLogin.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(!login())
					return;
				
				String loginAs = cmbLoginAs.getSelectedItem().toString().trim().toLowerCase();
				dispose();
				
				if (loginAs.equals("manager"))
					new Manager();
				else
					new Officer();
			}
		});
		
		setLocationRelativeTo(null);
		setVisible(true);
	}
	
	
	@SuppressWarnings("deprecation")
	private boolean login() {
		String accountName = txtAccount.getText().trim();
		String pwd = txtPwd.getText();
		String loginAs = cmbLoginAs.getSelectedItem().toString().trim().toLowerCase();
		
		Account account = (Account)Entity.load(Account.class, accountName);
		if (account == null) {
			JOptionPane.showMessageDialog(
					this, 
					"There is no such account", 
					"No account", 
					JOptionPane.ERROR_MESSAGE);
			
			return false;
		}
		
		String md5Pwd = account.getAccountPassword();
		if (md5Pwd != null && !md5Pwd.isEmpty()) {
			if (!Util.md5Encrypt(pwd).equals(md5Pwd)) {
				JOptionPane.showMessageDialog(
						this, 
						"Password invalid", 
						"Password invalid", 
						JOptionPane.ERROR_MESSAGE);
				return false;
			}
		}
		
		int right = account.getAccountRight();
		if (loginAs.equals("manager")) {
			if ( (right & Account.MANAGER) != Account.MANAGER ) {
				JOptionPane.showMessageDialog(
						this, 
						"Right invalid", 
						"Right invalid", 
						JOptionPane.ERROR_MESSAGE);
				return false;
			}
		}
		else if (loginAs.equals("officer")) {
			if ( (right & Account.OFFICER) != Account.OFFICER ) {
				JOptionPane.showMessageDialog(
						this, 
						"Right invalid", 
						"Right invalid", 
						JOptionPane.ERROR_MESSAGE);
				return false;
			}
		}
		else {
			JOptionPane.showMessageDialog(
					this, 
					"Right invalid", 
					"Right invalid", 
					JOptionPane.ERROR_MESSAGE);
			return false;
		}
		
		return true;
		
	}
	
	
	
}
