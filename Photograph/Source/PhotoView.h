// PhotoView.h : interface of the CPhotoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PHOTOVIEW_H__FC889329_76C9_11D4_A3E4_FDB243694D6A__INCLUDED_)
#define AFX_PHOTOVIEW_H__FC889329_76C9_11D4_A3E4_FDB243694D6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define		DISPLAY_NORMAL		1
#define		DISPLAY_CENTER		2
#define		DISPLAY_STRETCH		4

class CPhotoView : public CScrollView
{
protected: // create from serialization only
	CPhotoView();
	DECLARE_DYNCREATE(CPhotoView)

// Attributes
protected:
	DWORD	m_dwDisplayMode;
	BOOL	m_bMouseDown;
	CPoint	m_ptCursorCurPos;
	CPoint	m_ptCursorOldPos;
	BOOL	m_bScroll;
public:
	CPhotoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPhotoView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPhotoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//##ModelId=3A06208B0319
	BOOL RealizePalette(BOOL bForceBkgnd);
	//{{AFX_MSG(CPhotoView)
	afx_msg void OnUpdateFileSendMail(CCmdUI* pCmdUI);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaletteChanged(CWnd* pFocusWnd);
	afx_msg BOOL OnQueryNewPalette();
	afx_msg void OnUpdateImageNormal(CCmdUI* pCmdUI);
	afx_msg void OnImageNormal();
	afx_msg void OnUpdateImageCenter(CCmdUI* pCmdUI);
	afx_msg void OnImageCenter();
	afx_msg void OnUpdateImageStretch(CCmdUI* pCmdUI);
	afx_msg void OnImageStretch();
	afx_msg void OnToolsOperatorAdd();
	afx_msg void OnToolsOperatorSub();
	afx_msg void OnToolsOperatorMul();
	afx_msg void OnToolsOperatorDiv();
	afx_msg void OnToolsOperatorNot();
	afx_msg void OnToolsOperatorAnd();
	afx_msg void OnToolsOperatorOr();
	afx_msg void OnToolsOperatorXor();
	afx_msg void OnToolsOperatorMin();
	afx_msg void OnToolsOperatorMax();
	afx_msg void OnToolsOperatorAbs();
	afx_msg void OnImageInformation();
	afx_msg void OnImageGrayScale();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnEnhanceHistogramEqualization();
	afx_msg void OnImageCut();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnScrollButton();
	afx_msg void OnUpdateScrollButton(CCmdUI* pCmdUI);
	afx_msg void OnUpdateImageSaveimagesarray(CCmdUI* pCmdUI);
	afx_msg void OnImageSaveimagesarray();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PhotoView.cpp
inline CPhotoDoc* CPhotoView::GetDocument()
   { return (CPhotoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PHOTOVIEW_H__FC889329_76C9_11D4_A3E4_FDB243694D6A__INCLUDED_)
