#if !defined(AFX_PROVIDERDLG_H__96BD75A3_A817_11D4_A3E4_D92EBED10908__INCLUDED_)
#define AFX_PROVIDERDLG_H__96BD75A3_A817_11D4_A3E4_D92EBED10908__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProviderDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProviderDlg dialog

class CProviderDlg : public CDialog
{
// Construction
public:
	CProviderDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProviderDlg)
	enum { IDD = IDD_PROVIDER_DIALOG };
	CString	m_szProgID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProviderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProviderDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROVIDERDLG_H__96BD75A3_A817_11D4_A3E4_D92EBED10908__INCLUDED_)
