#if !defined(AFX_CHOOSENAMEDLG_H__B3C138DF_8C68_4C7D_BC4C_00D977D27A16__INCLUDED_)
#define AFX_CHOOSENAMEDLG_H__B3C138DF_8C68_4C7D_BC4C_00D977D27A16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChooseNameDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChooseNameDlg dialog

class CChooseNameDlg : public CDialog
{
// Construction
public:
	CString GetDir();
	CString GetName();
	CChooseNameDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChooseNameDlg)
	enum { IDD = IDD_CHOOSE_NAME_DIALOG };
	CString	m_Name;
	CString	m_Dir;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChooseNameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChooseNameDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHOOSENAMEDLG_H__B3C138DF_8C68_4C7D_BC4C_00D977D27A16__INCLUDED_)
