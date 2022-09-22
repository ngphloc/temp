// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__FC889323_76C9_11D4_A3E4_FDB243694D6A__INCLUDED_)
#define AFX_MAINFRM_H__FC889323_76C9_11D4_A3E4_FDB243694D6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MDIClient.h"
#include "ToggleBar.h"

class CMainFrame : public CMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	void ControlMenuBar(CMenu* pMenu);
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CToggleBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;
	CReBar      m_wndReBar;
	CDialogBar  m_wndDlgBar;

	CToolBar	m_wndOperatorToolBar;

	CMDIClient  m_MDIClient;

	CString		m_szTimeFormat;
	CString		m_szDateFormat;
	UINT		m_nIDStatusTime;
	BOOL		m_bOperatorBar;
// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnInitMenu(CMenu* pMenu);
	afx_msg void OnDestroy();
	afx_msg void OnPaletteChanged(CWnd* pFocusWnd);
	afx_msg void OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu);
	afx_msg void OnUpdateViewOperatorToolbar(CCmdUI* pCmdUI);
	afx_msg void OnViewOperatorToolbar();
	//}}AFX_MSG
	afx_msg void OnUpdateIndicatorTime(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__FC889323_76C9_11D4_A3E4_FDB243694D6A__INCLUDED_)
