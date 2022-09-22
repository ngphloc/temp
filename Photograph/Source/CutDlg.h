#if !defined(AFX_CUTDLG_H__7263B3AE_11F1_490D_9D19_2E00FB7265BC__INCLUDED_)
#define AFX_CUTDLG_H__7263B3AE_11F1_490D_9D19_2E00FB7265BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CutDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCutDlg dialog
class CPhotoView;

class CCutDlg : public CDialog
{
// Construction
public:
	CCutDlg(CWnd* pParent = NULL);   // standard constructor

protected:
// Dialog Data
	//{{AFX_DATA(CCutDlg)
	enum { IDD = IDD_CUT_DIALOG };
	UINT	m;
	UINT	vm;
	UINT	n;
	UINT	vn;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	friend CPhotoView;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUTDLG_H__7263B3AE_11F1_490D_9D19_2E00FB7265BC__INCLUDED_)
