#if !defined(AFX_TOGGLEBAR_H__68881524_80E2_11D4_A3E4_FAB68865E16C__INCLUDED_)
#define AFX_TOGGLEBAR_H__68881524_80E2_11D4_A3E4_FAB68865E16C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ToggleBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CToggleBar window

class CToggleBar : public CStatusBar
{
// Construction
public:
	CToggleBar();

// Attributes
protected:
	DWORD	m_nPaneID;
	BOOL	m_bPaneOn;
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToggleBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CToggleBar();

	// Generated message map functions
protected:
	//{{AFX_MSG(CToggleBar)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	friend class CMainFrame;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOGGLEBAR_H__68881524_80E2_11D4_A3E4_FAB68865E16C__INCLUDED_)
