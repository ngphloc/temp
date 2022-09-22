#if !defined(AFX_OPERATORDLG_H__FC889351_76C9_11D4_A3E4_FDB243694D6A__INCLUDED_)
#define AFX_OPERATORDLG_H__FC889351_76C9_11D4_A3E4_FDB243694D6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OperatorDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COperatorDlg dialog

class CPhotoView;

class COperatorDlg : public CDialog
{
//Atribute
protected:
	DWORD   m_dwValue;
	CString m_szFilePath;
	BOOL	m_bFlag;      //TRUE :chon so nguyen
						 //FALSE:chon File
	CString	m_szNameDlg;
// Construction
public:
	COperatorDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COperatorDlg)
	enum { IDD = IDD_OPERATOR_CHOOSE_DIALOG };
	BOOL	m_bReversed;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COperatorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COperatorDlg)
	afx_msg void OnIntergerRadio();
	afx_msg void OnFileRadio();
	afx_msg void OnBrowseButton();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	friend CPhotoView;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPERATORDLG_H__FC889351_76C9_11D4_A3E4_FDB243694D6A__INCLUDED_)
