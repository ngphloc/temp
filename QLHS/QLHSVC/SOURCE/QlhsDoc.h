// QlhsDoc.h : interface of the CQlhsDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_QLHSDOC_H__7921BDCE_9FAD_11D4_A3E4_B017BF6D810E__INCLUDED_)
#define AFX_QLHSDOC_H__7921BDCE_9FAD_11D4_A3E4_B017BF6D810E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DBDeclare.h"

class CQlhsSrvrItem;

class CQlhsDoc : public COleServerDoc
{
protected: // create from serialization only
	CQlhsDoc();
	DECLARE_DYNCREATE(CQlhsDoc)

// Attributes
public:
	CQlhsSrvrItem* GetEmbeddedItem()
		{ return (CQlhsSrvrItem*)COleServerDoc::GetEmbeddedItem(); }

	CHocSinh	m_HocSinhSet;			
	DWORD		m_HocSinhUse;   
	BOOL		m_bHSFirst,m_bHSLast;
	BOOL		m_bHSNew;

	CLop		m_LopSet;				
	DWORD		m_LopUse;       
	BOOL		m_bLopFirst,m_bLopLast;     
	BOOL		m_bLopNew;

	CMonHoc		m_MonHocSet;	
	DWORD		m_MonHocUse;    
	BOOL		m_bMHFirst,m_bMHLast;          
	BOOL		m_bMHNew;

	CGiaoVien	m_GiaoVienSet;	
	DWORD		m_GiaoVienUse;  
	BOOL		m_bGVFirst,m_bGVLast;           
	BOOL		m_bGVNew;
                                                                    
	CKhoiLop	m_KhoiLopSet;	
	DWORD		m_KhoiLopUse;   
	BOOL		m_bKLFirst,m_bKLLast;       
	BOOL		m_bKLNew;

	CNienKhoa	m_NienKhoaSet;	
	DWORD		m_NienKhoaUse;  
	BOOL		m_bNKFirst,m_bNKLast;      
	BOOL		m_bNKNew;

	CHocKy		m_HocKySet;		
	DWORD		m_HocKyUse;     
	BOOL		m_bHKFirst,m_bHKLast;    
	BOOL		m_bHKNew;

	CPhong		m_PhongSet;		
	DWORD		m_PhongUse;     
	BOOL		m_bPFirst,m_bPLast;
	BOOL		m_bPNew;

	CHinhThucKT	m_HinhThucKTSet;
	DWORD		m_HinhThucKTUse;
	BOOL		m_bKTFirst,m_bKTLast;       
	BOOL		m_bKTNew;

public:
	DWORD		m_Index;
	DWORD		m_Access,m_CurAccess;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQlhsDoc)
	protected:
	virtual COleServerItem* OnGetEmbeddedItem();
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CQlhsDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CQlhsDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CQlhsDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QLHSDOC_H__7921BDCE_9FAD_11D4_A3E4_B017BF6D810E__INCLUDED_)
