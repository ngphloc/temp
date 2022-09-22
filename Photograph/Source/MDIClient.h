#if !defined(AFX_MDICLIENT_H__FC88935C_76C9_11D4_A3E4_FDB243694D6A__INCLUDED_)
#define AFX_MDICLIENT_H__FC88935C_76C9_11D4_A3E4_FDB243694D6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MDIClient.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMDIClient frame

class CMainFrame;

class CMDIClient : public CFrameWnd
{
	DECLARE_DYNCREATE(CMDIClient)

protected:
	CMDIClient();           // protected constructor used by dynamic creation

// Attributes
protected:
	CBitmap	m_bmp;
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDIClient)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMDIClient();

	// Generated message map functions
	//{{AFX_MSG(CMDIClient)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CMDIClient)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	friend class CMainFrame;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDICLIENT_H__FC88935C_76C9_11D4_A3E4_FDB243694D6A__INCLUDED_)
