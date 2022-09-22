// QlhsView.h : interface of the CQlhsView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_QLHSVIEW_H__7921BDD0_9FAD_11D4_A3E4_B017BF6D810E__INCLUDED_)
#define AFX_QLHSVIEW_H__7921BDD0_9FAD_11D4_A3E4_B017BF6D810E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QlhsDoc.h"

class CQlhsView : public CFormView
{
protected: // create from serialization only
	CQlhsView();
	DECLARE_DYNCREATE(CQlhsView)

public:
	//{{AFX_DATA(CQlhsView)
	enum { IDD = IDD_QLHS_FORM };
	CButton	m_NamGV;
	CButton	m_NamHS;
	CString	m_DiaChiHS;
	CString	m_DienHS;
	CString	m_HoTenHS;
	CString	m_MaHS;
	CString	m_NgaySinhHS;
	CString	m_SoNgayVang;
	CString	m_DiaChiGV;
	CString	m_GhiChuGV;
	CString	m_HoTenGV;
	CString	m_MaGV;
	CString	m_NgaySinhGV;
	CString	m_GhiChuLop;
	CString	m_GhiChuMH;
	CString	m_HeSo;
	CString	m_MaLop;
	CString	m_MaMH;
	CString	m_SiSo;
	CString	m_SoTiet;
	CString	m_TenLop;
	CString	m_TenMH;
	//}}AFX_DATA

// Attributes
public:
	CQlhsDoc* GetDocument();

	//template <class TRowset> TRowset*  OnGetRowset();
	CCommand* OnGetRowset();

	CHocSinh*		m_pHocSinhSet;
	CLop*			m_pLopSet;
	CMonHoc*		m_pMonHocSet;
	CGiaoVien*		m_pGiaoVienSet;

	CKhoiLop*		m_pKhoiLopSet;
	CNienKhoa*		m_pNienKhoaSet;
	CHocKy*			m_pHocKySet;
	CPhong*			m_pPhongSet;
	CHinhThucKT*	m_pHinhThucKTSet;

// Operations
public:
	virtual	void OnMove(UINT nIDMoveCommand);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQlhsView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	void DisplayControls(DWORD Idx, DWORD cmdShow);
	void ShowControls(DWORD Idx);
	virtual ~CQlhsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CQlhsView)
	afx_msg void OnCancelEditSrvr();
	afx_msg void OnSelchangeQlhsTab(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangingQlhsTab(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnUpdateRecordNext(CCmdUI* pCmdUI);
	afx_msg void OnUpdateRecordPrev(CCmdUI* pCmdUI);
	afx_msg void OnUpdateRecordFirst(CCmdUI* pCmdUI);
	afx_msg void OnUpdateRecordLast(CCmdUI* pCmdUI);
	afx_msg void OnAddButton();
	afx_msg void OnDeleteButton();
	afx_msg void OnUpdateButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in QlhsView.cpp
inline CQlhsDoc* CQlhsView::GetDocument()
   { return (CQlhsDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QLHSVIEW_H__7921BDD0_9FAD_11D4_A3E4_B017BF6D810E__INCLUDED_)
