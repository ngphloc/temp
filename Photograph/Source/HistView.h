#if !defined(AFX_HISTVIEW_H__54581F61_7ACE_11D4_A3E4_CFD2D15B2069__INCLUDED_)
#define AFX_HISTVIEW_H__54581F61_7ACE_11D4_A3E4_CFD2D15B2069__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HistView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHistView view

class CHistView : public CScrollView
{
protected:
	CHistView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CHistView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHistView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CHistView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CHistView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTVIEW_H__54581F61_7ACE_11D4_A3E4_CFD2D15B2069__INCLUDED_)
