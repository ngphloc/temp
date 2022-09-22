#if !defined(AFX_LOGONDLG_H__EA885AE1_9FC7_11D4_A3E4_B017BF6D810E__INCLUDED_)
#define AFX_LOGONDLG_H__EA885AE1_9FC7_11D4_A3E4_B017BF6D810E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LogonDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogonDlg dialog

class CLogonDlg : public CDialog
{
// Construction
public:
	CLogonDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLogonDlg)
	enum { IDD = IDD_LOGON_DIALOG };
	CString	m_szDataBase;
	CString	m_szLoginName;
	CString	m_szProgID;
	CString	m_szServer;
	CString	m_szPassword;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLogonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeServerEdit();
	afx_msg void OnSqlRadio();
	afx_msg void OnWinntRadio();
	afx_msg void OnChangeButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGONDLG_H__EA885AE1_9FC7_11D4_A3E4_B017BF6D810E__INCLUDED_)
