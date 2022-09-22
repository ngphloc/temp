// QlhsView.cpp : implementation of the CQlhsView class
//

#include "stdafx.h"
#include "Qlhs.h"

#include "QlhsView.h"
#include "MainFrm.h"
#include "Tool.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQlhsView

IMPLEMENT_DYNCREATE(CQlhsView, CFormView)

BEGIN_MESSAGE_MAP(CQlhsView, CFormView)
	//{{AFX_MSG_MAP(CQlhsView)
	ON_COMMAND(ID_CANCEL_EDIT_SRVR, OnCancelEditSrvr)
	ON_NOTIFY(TCN_SELCHANGE, IDC_QLHS_TAB, OnSelchangeQlhsTab)
	ON_NOTIFY(TCN_SELCHANGING, IDC_QLHS_TAB, OnSelchangingQlhsTab)
	ON_UPDATE_COMMAND_UI(ID_RECORD_NEXT, OnUpdateRecordNext)
	ON_UPDATE_COMMAND_UI(ID_RECORD_PREV, OnUpdateRecordPrev)
	ON_UPDATE_COMMAND_UI(ID_RECORD_FIRST, OnUpdateRecordFirst)
	ON_UPDATE_COMMAND_UI(ID_RECORD_LAST, OnUpdateRecordLast)
	ON_BN_CLICKED(IDC_ADD_BUTTON, OnAddButton)
	ON_BN_CLICKED(IDC_DELETE_BUTTON, OnDeleteButton)
	ON_BN_CLICKED(IDC_UPDATE_BUTTON, OnUpdateButton)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND_EX(ID_RECORD_NEXT,OnMove)
	ON_COMMAND_EX(ID_RECORD_PREV,OnMove)
	ON_COMMAND_EX(ID_RECORD_FIRST,OnMove)
	ON_COMMAND_EX(ID_RECORD_LAST,OnMove)
	
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQlhsView construction/destruction

CQlhsView::CQlhsView()
	: CFormView(CQlhsView::IDD)
{
	//{{AFX_DATA_INIT(CQlhsView)
	m_DiaChiHS = _T("");
	m_DienHS = _T("");
	m_HoTenHS = _T("");
	m_MaHS = _T("");
	m_NgaySinhHS = _T("");
	m_SoNgayVang = _T("");
	m_DiaChiGV = _T("");
	m_GhiChuGV = _T("");
	m_HoTenGV = _T("");
	m_MaGV = _T("");
	m_NgaySinhGV = _T("");
	m_GhiChuLop = _T("");
	m_GhiChuMH = _T("");
	m_HeSo = _T("");
	m_MaLop = _T("");
	m_MaMH = _T("");
	m_SiSo = _T("");
	m_SoTiet = _T("");
	m_TenLop = _T("");
	m_TenMH = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CQlhsView::~CQlhsView()
{
}

void CQlhsView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQlhsView)
	DDX_Control(pDX, IDC_NAMGV_CHECK, m_NamGV);
	DDX_Control(pDX, IDC_NAMHS_CHECK, m_NamHS);
	DDX_Text(pDX, IDC_DIACHIHS_EDIT, m_DiaChiHS);
	DDX_Text(pDX, IDC_DIENHS_EDIT, m_DienHS);
	DDX_Text(pDX, IDC_HOTENHS_EDIT, m_HoTenHS);
	DDX_Text(pDX, IDC_MAHS_EDIT, m_MaHS);
	DDX_Text(pDX, IDC_NGAYSINHHS_EDIT, m_NgaySinhHS);
	DDX_Text(pDX, IDC_SONGAYVANG_EDIT, m_SoNgayVang);
	DDX_Text(pDX, IDC_DIACHIGV_EDIT, m_DiaChiGV);
	DDX_Text(pDX, IDC_GHICHUGV_EDIT, m_GhiChuGV);
	DDX_Text(pDX, IDC_HOTENGV_EDIT, m_HoTenGV);
	DDX_Text(pDX, IDC_MAGV_EDIT, m_MaGV);
	DDX_Text(pDX, IDC_NGAYSINHGV_EDIT, m_NgaySinhGV);
	DDX_Text(pDX, IDC_GHICHULOP_EDIT, m_GhiChuLop);
	DDX_Text(pDX, IDC_GHICHUMH_EDIT, m_GhiChuMH);
	DDX_Text(pDX, IDC_HESO_EDIT, m_HeSo);
	DDX_Text(pDX, IDC_MALOP_EDIT, m_MaLop);
	DDX_Text(pDX, IDC_MAMH_EDIT, m_MaMH);
	DDX_Text(pDX, IDC_SISO_EDIT, m_SiSo);
	DDX_Text(pDX, IDC_SOTIET_EDIT, m_SoTiet);
	DDX_Text(pDX, IDC_TENLOP_EDIT, m_TenLop);
	DDX_Text(pDX, IDC_TENMH_EDIT, m_TenMH);
	//}}AFX_DATA_MAP
}

BOOL CQlhsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CQlhsView::OnInitialUpdate()
{

	CQlhsDoc*	pDoc=(CQlhsDoc*)GetDocument();
	CMainFrame*		pMainFrm=(CMainFrame*)GetParentFrame();
	
	if(pDoc->m_GiaoVienUse==DBCLOSED &&
	   pDoc->m_HinhThucKTUse==DBCLOSED &&
	   pDoc->m_HocKyUse==DBCLOSED &&
	   pDoc->m_HocSinhUse==DBCLOSED &&
	   pDoc->m_KhoiLopUse==DBCLOSED &&
	   pDoc->m_LopUse==DBCLOSED &&
	   pDoc->m_MonHocUse==DBCLOSED &&
	   pDoc->m_NienKhoaUse==DBCLOSED &&
	   pDoc->m_PhongUse==DBCLOSED )
	{
		m_pHocSinhSet=&pDoc->m_HocSinhSet;
		m_pLopSet=&pDoc->m_LopSet;
		m_pMonHocSet=&pDoc->m_MonHocSet;
		m_pGiaoVienSet=&pDoc->m_GiaoVienSet;

		m_pKhoiLopSet=&pDoc->m_KhoiLopSet;
		m_pNienKhoaSet=&pDoc->m_NienKhoaSet;
		m_pHocKySet=&pDoc->m_HocKySet;
		m_pPhongSet=&pDoc->m_PhongSet;
		m_pHinhThucKTSet=&pDoc->m_HinhThucKTSet;

		if(m_pHocSinhSet->Open()==S_OK &&
		   m_pLopSet->Open()==S_OK &&
		   m_pMonHocSet->Open()==S_OK &&
		   m_pGiaoVienSet->Open()==S_OK &&
		   m_pKhoiLopSet->Open()==S_OK &&
		   m_pNienKhoaSet->Open()==S_OK &&
		   m_pHocKySet->Open()==S_OK &&
		   m_pPhongSet->Open()==S_OK &&
		   m_pHinhThucKTSet->Open()==S_OK)
		{
			if(m_pHocSinhSet->MoveNext() != S_OK)
				pDoc->m_HocSinhUse=DBEMPTY;
			else
				pDoc->m_HocSinhUse=DBOPEN;
			
			if(m_pLopSet->MoveNext()!=S_OK)
				pDoc->m_LopUse=DBEMPTY;
			else
				pDoc->m_LopUse=DBOPEN;
			
			if(m_pMonHocSet->MoveNext()!=S_OK)
				pDoc->m_MonHocUse=DBEMPTY;
			else
				pDoc->m_MonHocUse=DBOPEN;
			
			if(m_pGiaoVienSet->MoveNext()!=S_OK)
				pDoc->m_GiaoVienUse=DBEMPTY;
			else
				pDoc->m_GiaoVienUse=DBOPEN;
			
			if(m_pKhoiLopSet->MoveNext()!=S_OK)
				pDoc->m_KhoiLopUse=DBEMPTY;
			else
				pDoc->m_KhoiLopUse=DBOPEN;

			if(m_pNienKhoaSet->MoveNext()!=S_OK)
				pDoc->m_NienKhoaUse=DBEMPTY;
			else
				pDoc->m_NienKhoaUse=DBOPEN;

			if(m_pHocKySet->MoveNext()!=S_OK)
				pDoc->m_HocKyUse=DBEMPTY;
			else
				pDoc->m_HocKyUse=DBOPEN;

			if(m_pPhongSet->MoveNext()!=S_OK)
				pDoc->m_PhongUse=DBEMPTY;
			else
				pDoc->m_PhongUse=DBOPEN;

			if(m_pHinhThucKTSet->MoveNext()!=S_OK )
				pDoc->m_HinhThucKTUse=DBEMPTY;
			else
				pDoc->m_HinhThucKTUse=DBOPEN;
			
			pDoc->m_Index=IDX_HOCSINH;
			pDoc->m_Access=ACCESS_HOCSINH|ACCESS_LOP|ACCESS_MONHOC|ACCESS_GIAOVIEN|
						   ACCESS_KHOILOP|ACCESS_NIENKHOA|ACCESS_HOCKY|ACCESS_PHONG|
						   ACCESS_HINHTHUCKT;
			pDoc->m_CurAccess=ACCESS_HOCSINH;

			pDoc->m_bHSFirst=TRUE; pDoc->m_bHSLast=FALSE; pDoc->m_bHSNew=FALSE;           
			pDoc->m_bLopFirst=TRUE;pDoc->m_bLopLast=FALSE;pDoc->m_bLopNew=FALSE;
			pDoc->m_bMHFirst=TRUE; pDoc->m_bMHLast=FALSE; pDoc->m_bMHNew=FALSE;         
			pDoc->m_bGVFirst=TRUE; pDoc->m_bGVLast=FALSE; pDoc->m_bGVNew=FALSE;          
                                                    
			pDoc->m_bKLFirst=TRUE; pDoc->m_bKLLast=FALSE; pDoc->m_bKLNew=FALSE;      
			pDoc->m_bNKFirst=TRUE; pDoc->m_bNKLast=FALSE; pDoc->m_bNKNew=FALSE;     
			pDoc->m_bHKFirst=TRUE; pDoc->m_bHKLast=FALSE; pDoc->m_bHKNew=FALSE;   
			pDoc->m_bPFirst=TRUE;  pDoc->m_bPLast=FALSE;  pDoc->m_bPNew=FALSE;
			pDoc->m_bKTFirst=TRUE; pDoc->m_bKTLast=FALSE; pDoc->m_bKTNew=FALSE;      
		}
		else
		{
			MessageBox("Error ! Can't open Rowset","Error",MB_OK|MB_ICONSTOP);

			pDoc->m_GiaoVienUse=DBERROR;
			pDoc->m_HinhThucKTUse=DBERROR;
			pDoc->m_HocKyUse=DBERROR;
			pDoc->m_HocSinhUse=DBERROR;
			pDoc->m_KhoiLopUse=DBERROR;
			pDoc->m_LopUse=DBERROR;
			pDoc->m_MonHocUse=DBERROR;
			pDoc->m_NienKhoaUse=DBERROR;
			pDoc->m_PhongUse=DBERROR;

			pDoc->m_Index=IDX_ERROR;
			pDoc->m_Access=ACCESS_ERROR;
			pDoc->m_CurAccess=ACCESS_ERROR;

			pMainFrm->PostMessage(WM_CLOSE);
		}

	}

	CFormView::OnInitialUpdate();
	CTabCtrl* pTabCtrl=(CTabCtrl*)GetDlgItem(IDC_QLHS_TAB);
	pTabCtrl->InsertItem(0,"Hoc Sinh");
	pTabCtrl->InsertItem(1,"Lop");
	pTabCtrl->InsertItem(2,"Mon Hoc");
	pTabCtrl->InsertItem(3,"Giao Vien");
	pTabCtrl->SetCurSel(0);

	pMainFrm->RecalcLayout();
	pMainFrm->GetToolBar()->EnableWindow(pDoc->m_HocSinhUse==DBOPEN);
	ResizeParentToFit();

}

void CQlhsView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	DWORD	Idx=(DWORD)lHint;
	DWORD	FlagUse;
	ShowControls(Idx);	
	CQlhsDoc*	pDoc=(CQlhsDoc*)GetDocument();

	CButton*  pAddButton=(CButton*)GetDlgItem(IDC_ADD_BUTTON);
	CButton*  pDeleteButton=(CButton*)GetDlgItem(IDC_DELETE_BUTTON);
	CButton*  pUpdateButton=(CButton*)GetDlgItem(IDC_UPDATE_BUTTON);
	CButton*  pFindButton=(CButton*)GetDlgItem(IDC_FIND_BUTTON);
		
	switch(Idx)
	{
		case IDX_HOCSINH:
			FlagUse=pDoc->m_HocSinhUse;
			if(FlagUse==DBOPEN)
			{
				m_MaHS = m_pHocSinhSet->m_MaHS;
				if(m_pHocSinhSet->m_Nam)
					m_NamHS.SetCheck(1);
				else
					m_NamHS.SetCheck(0);
				m_HoTenHS = m_pHocSinhSet->m_HoTenHS;
				m_DiaChiHS = m_pHocSinhSet->m_DiaChiHS;
				m_DienHS.Format("%lu",m_pHocSinhSet->m_DienHS);
				CTime	tmpTime(m_pHocSinhSet->m_NgaySinhHS.year,
								m_pHocSinhSet->m_NgaySinhHS.month,
								m_pHocSinhSet->m_NgaySinhHS.day,
								0,0,0);
				m_NgaySinhHS=tmpTime.Format("%m/%d/%y");
				m_SoNgayVang.Format("%lu",m_pHocSinhSet->m_SoNgayVang);
			}
			else
			{
				m_MaHS = _T("");
				m_NamHS.SetCheck(0);
				m_HoTenHS = _T("");
				m_DiaChiHS = _T("");
				m_DienHS = _T("");
				m_NgaySinhHS = _T("");
				m_SoNgayVang = _T("");
			}
			break;
		case IDX_LOP:
			FlagUse=pDoc->m_LopUse;
			if(FlagUse==DBOPEN)
			{
				m_MaLop=m_pLopSet->m_MaLop;
				m_TenLop=m_pLopSet->m_TenLop;
				//Cac Fields
				m_GhiChuLop=m_pLopSet->m_GhiChu;
			}
			else
			{
				m_MaLop=_T("");
				m_TenLop=_T("");
				//Cac Fields
				m_GhiChuLop=_T("");
			}
			break;
		case IDX_MONHOC:
			FlagUse=pDoc->m_MonHocUse;
			if(FlagUse==DBOPEN)
			{
				m_MaMH=m_pMonHocSet->m_MaMH;
				m_TenMH=m_pMonHocSet->m_TenMH;
				m_HeSo.Format("%lu",m_pMonHocSet->m_HeSo);
				m_SoTiet.Format("%lu",m_pMonHocSet->m_SoTiet);
				m_GhiChuMH=m_pMonHocSet->m_GhiChu;
			}
			else
			{
				m_MaMH=_T("");
				m_TenMH=_T("");
				m_HeSo=_T("");
				m_SoTiet=_T("");
				m_GhiChuMH=_T("");
			}
			break;
		case IDX_GIAOVIEN:
			FlagUse=pDoc->m_GiaoVienUse;
			if(FlagUse==DBOPEN)
			{
				m_MaGV = m_pGiaoVienSet->m_MaGV;
				if(m_pGiaoVienSet->m_Nam)
					m_NamGV.SetCheck(1);
				else
					m_NamGV.SetCheck(0);
				m_HoTenGV = m_pGiaoVienSet->m_HoTenGV;
				m_DiaChiGV = m_pGiaoVienSet->m_DiaChiGV;
				CTime	tmpTime(m_pGiaoVienSet->m_NgaySinhGV.year,
								m_pGiaoVienSet->m_NgaySinhGV.month,
								m_pGiaoVienSet->m_NgaySinhGV.day,
								0,0,0);
				m_NgaySinhGV=tmpTime.Format("%m/%d/%y");
				m_GhiChuGV = m_pGiaoVienSet->m_Ghichu;
			}
			else
			{
				m_MaGV = _T("");
				m_NamGV.SetCheck(0);
				m_HoTenGV = _T("");
				m_DiaChiGV = _T("");
				m_NgaySinhGV = _T("");
				m_GhiChuGV = _T("");
			}
			break;
		default:
			MessageBox("Error! Index is not valid","Error",MB_OK|MB_ICONSTOP);
			return;

	}
	UpdateData(FALSE);
	if(FlagUse==DBOPEN)
	{
		pAddButton->EnableWindow(TRUE);
		pDeleteButton->EnableWindow(TRUE);
		pUpdateButton->EnableWindow(TRUE);
		pFindButton->EnableWindow(TRUE);
	}
	else if(FlagUse==DBEMPTY)
	{
		pAddButton->EnableWindow(TRUE);
		pDeleteButton->EnableWindow(FALSE);
		pUpdateButton->EnableWindow(FALSE);
		pFindButton->EnableWindow(FALSE);
	}
	else
	{
		pAddButton->EnableWindow(FALSE);
		pDeleteButton->EnableWindow(FALSE);
		pUpdateButton->EnableWindow(FALSE);
		pFindButton->EnableWindow(FALSE);
	}

}
/////////////////////////////////////////////////////////////////////////////
// CQlhsView printing

BOOL CQlhsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CQlhsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CQlhsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CQlhsView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// OLE Server support

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the server (not the container) causes the deactivation.
void CQlhsView::OnCancelEditSrvr()
{
	GetDocument()->OnDeactivateUI(FALSE);
}

/////////////////////////////////////////////////////////////////////////////
// CQlhsView diagnostics

#ifdef _DEBUG
void CQlhsView::AssertValid() const
{
	CFormView::AssertValid();
}

void CQlhsView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CQlhsDoc* CQlhsView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CQlhsDoc)));
	return (CQlhsDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CQlhsView message handlers

void CQlhsView::ShowControls(DWORD Idx)
{
	switch(Idx)
	{
		case IDX_HOCSINH:
			DisplayControls(IDX_HOCSINH,SW_SHOW);
			DisplayControls(IDX_LOP,SW_HIDE);
			DisplayControls(IDX_MONHOC,SW_HIDE);
			DisplayControls(IDX_GIAOVIEN,SW_HIDE);
			break;
		case IDX_LOP:
			DisplayControls(IDX_HOCSINH,SW_HIDE);
			DisplayControls(IDX_LOP,SW_SHOW);
			DisplayControls(IDX_MONHOC,SW_HIDE);
			DisplayControls(IDX_GIAOVIEN,SW_HIDE);
			break;
		case IDX_MONHOC:
			DisplayControls(IDX_HOCSINH,SW_HIDE);
			DisplayControls(IDX_LOP,SW_HIDE);
			DisplayControls(IDX_MONHOC,SW_SHOW);
			DisplayControls(IDX_GIAOVIEN,SW_HIDE);
			break;
		case IDX_GIAOVIEN:
			DisplayControls(IDX_HOCSINH,SW_HIDE);
			DisplayControls(IDX_LOP,SW_HIDE);
			DisplayControls(IDX_MONHOC,SW_HIDE);
			DisplayControls(IDX_GIAOVIEN,SW_SHOW);
			break;
		default:
			DisplayControls(IDX_HOCSINH,SW_HIDE);
			DisplayControls(IDX_LOP,SW_HIDE);
			DisplayControls(IDX_MONHOC,SW_HIDE);
			DisplayControls(IDX_GIAOVIEN,SW_HIDE);
			MessageBox("Error! Index is not valid","Error",MB_OK|MB_ICONSTOP);
			return;
	}
}

void CQlhsView::DisplayControls(DWORD Idx, DWORD nCmdShow)
{
	switch(Idx)
	{
		case IDX_HOCSINH:
		{
			CStatic*	pMaHSStatic=(CStatic*)GetDlgItem(IDC_MAHS_STATIC);
			CStatic*	pHoTenHSStatic=(CStatic*)GetDlgItem(IDC_HOTENHS_STATIC);
			CStatic*	pNgaySinhHSStatic=(CStatic*)GetDlgItem(IDC_NGAYSINHHS_STATIC);
			CStatic*	pDiaChiHSStatic=(CStatic*)GetDlgItem(IDC_DIACHIHS_STATIC);
			CStatic*	pDienHSStatic=(CStatic*)GetDlgItem(IDC_DIENHS_STATIC);
			CStatic*	pSoNgayVangStatic=(CStatic*)GetDlgItem(IDC_SONGAYVANG_STATIC);

			CEdit*		pMaHSEdit=(CEdit*)GetDlgItem(IDC_MAHS_EDIT);
			CEdit*		pHoTenHSEdit=(CEdit*)GetDlgItem(IDC_HOTENHS_EDIT);
			CEdit*		pNgaySinhHSEdit=(CEdit*)GetDlgItem(IDC_NGAYSINHHS_EDIT);
			CEdit*		pDiaChiHSEdit=(CEdit*)GetDlgItem(IDC_DIACHIHS_EDIT);
			CEdit*		pDienHSEdit=(CEdit*)GetDlgItem(IDC_DIENHS_EDIT);
			CEdit*		pSoNgayVangEdit=(CEdit*)GetDlgItem(IDC_SONGAYVANG_EDIT);

			CButton*	pNamHSButton=(CButton*)GetDlgItem(IDC_NAMHS_CHECK);			

			CListCtrl*	pHocSinhListCtrl=(CListCtrl*)GetDlgItem(IDC_HOCSINH_LIST);
								///////////
			pMaHSStatic->ShowWindow(nCmdShow);
			pHoTenHSStatic->ShowWindow(nCmdShow);
			pNgaySinhHSStatic->ShowWindow(nCmdShow);
			pDiaChiHSStatic->ShowWindow(nCmdShow);
			pDienHSStatic->ShowWindow(nCmdShow);
			pSoNgayVangStatic->ShowWindow(nCmdShow);

			pMaHSEdit->ShowWindow(nCmdShow);
			pHoTenHSEdit->ShowWindow(nCmdShow);
			pNgaySinhHSEdit->ShowWindow(nCmdShow);
			pDiaChiHSEdit->ShowWindow(nCmdShow);
			pDienHSEdit->ShowWindow(nCmdShow);
			pSoNgayVangEdit->ShowWindow(nCmdShow);

			pNamHSButton->ShowWindow(nCmdShow);

			pHocSinhListCtrl->ShowWindow(nCmdShow);
		}
			break;
		case IDX_LOP:
		{
			CStatic*	pMaLopStatic=(CStatic*)GetDlgItem(IDC_MALOP_STATIC);
			CStatic*	pTenLopStatic=(CStatic*)GetDlgItem(IDC_TENLOP_STATIC);
			CStatic*	pKhoiLopStatic=(CStatic*)GetDlgItem(IDC_KHOILOP_STATIC);
			CStatic*	pNienKhoaStatic=(CStatic*)GetDlgItem(IDC_NIENKHOA_STATIC);
			CStatic*	pPhongStatic=(CStatic*)GetDlgItem(IDC_PHONG_STATIC);
			CStatic*	pSiSoStatic=(CStatic*)GetDlgItem(IDC_SISO_STATIC);
			CStatic*	pGhiChuLopStatic=(CStatic*)GetDlgItem(IDC_GHICHULOP_STATIC);

			CEdit*		pMaLopEdit=(CEdit*)GetDlgItem(IDC_MALOP_EDIT);
			CEdit*		pTenLopEdit=(CEdit*)GetDlgItem(IDC_TENLOP_EDIT);
			CComboBox*	pKhoiLopCombo=(CComboBox*)GetDlgItem(IDC_KHOILOP_COMBO);
			CComboBox*	pNienKhoaEdit=(CComboBox*)GetDlgItem(IDC_NIENKHOA_COMBO);
			CComboBox*	pPhongEdit=(CComboBox*)GetDlgItem(IDC_PHONG_COMBO);
			CEdit*		pSiSoEdit=(CEdit*)GetDlgItem(IDC_SISO_EDIT);
			CEdit*		pGhiChuLopEdit=(CEdit*)GetDlgItem(IDC_GHICHULOP_EDIT);

			CListCtrl*	pLopListCtrl=(CListCtrl*)GetDlgItem(IDC_LOP_LIST);
								///////////
			pMaLopStatic->ShowWindow(nCmdShow);
			pTenLopStatic->ShowWindow(nCmdShow);
			pKhoiLopStatic->ShowWindow(nCmdShow);
			pNienKhoaStatic->ShowWindow(nCmdShow);
			pPhongStatic->ShowWindow(nCmdShow);
			pSiSoStatic->ShowWindow(nCmdShow);
			pGhiChuLopStatic->ShowWindow(nCmdShow);

			pMaLopEdit->ShowWindow(nCmdShow);
			pTenLopEdit->ShowWindow(nCmdShow);
			pKhoiLopCombo->ShowWindow(nCmdShow);
			pNienKhoaEdit->ShowWindow(nCmdShow);
			pPhongEdit->ShowWindow(nCmdShow);
			pSiSoEdit->ShowWindow(nCmdShow);
			pGhiChuLopEdit->ShowWindow(nCmdShow);

			pLopListCtrl->ShowWindow(nCmdShow);
		}
			break;
		case IDX_MONHOC:
		{
			CStatic*	pMaMHStatic=(CStatic*)GetDlgItem(IDC_MAMH_STATIC);
			CStatic*	pTenMHStatic=(CStatic*)GetDlgItem(IDC_TENMH_STATIC);
			CStatic*	pSoTietStatic=(CStatic*)GetDlgItem(IDC_SOTIET_STATIC);
			CStatic*	pHeSoStatic=(CStatic*)GetDlgItem(IDC_HESO_STATIC);
			CStatic*	pGhiChuMHStatic=(CStatic*)GetDlgItem(IDC_GHICHUMH_STATIC);

			CEdit*		pMaMHEdit=(CEdit*)GetDlgItem(IDC_MAMH_EDIT);
			CEdit*		pTenMHEdit=(CEdit*)GetDlgItem(IDC_TENMH_EDIT);
			CEdit*		pSoTietEdit=(CEdit*)GetDlgItem(IDC_SOTIET_EDIT);
			CEdit*		pHeSoEdit=(CEdit*)GetDlgItem(IDC_HESO_EDIT);
			CEdit*		pGhiChuMHEdit=(CEdit*)GetDlgItem(IDC_GHICHUMH_EDIT);

			CListCtrl*	pMonHocListCtrl=(CListCtrl*)GetDlgItem(IDC_MONHOC_LIST);
								///////////
			pMaMHStatic->ShowWindow(nCmdShow);
			pTenMHStatic->ShowWindow(nCmdShow);
			pSoTietStatic->ShowWindow(nCmdShow);
			pHeSoStatic->ShowWindow(nCmdShow);
			pGhiChuMHStatic->ShowWindow(nCmdShow);

			pMaMHEdit->ShowWindow(nCmdShow);
			pTenMHEdit->ShowWindow(nCmdShow);
			pSoTietEdit->ShowWindow(nCmdShow);
			pHeSoEdit->ShowWindow(nCmdShow);
			pGhiChuMHEdit->ShowWindow(nCmdShow);

			pMonHocListCtrl->ShowWindow(nCmdShow);
		}
			break;
		case IDX_GIAOVIEN:
		{
			CStatic*	pMaGVStatic=(CStatic*)GetDlgItem(IDC_MAGV_STATIC);
			CStatic*	pHoTenGVStatic=(CStatic*)GetDlgItem(IDC_HOTENGV_STATIC);
			CStatic*	pNgaySinhGVStatic=(CStatic*)GetDlgItem(IDC_NGAYSINHGV_STATIC);
			CStatic*	pDiaChiGVStatic=(CStatic*)GetDlgItem(IDC_DIACHIGV_STATIC);
			CStatic*	pGhiChuGVStatic=(CStatic*)GetDlgItem(IDC_GHICHUGV_STATIC);

			CEdit*		pMaGVEdit=(CEdit*)GetDlgItem(IDC_MAGV_EDIT);
			CEdit*		pHoTenGVEdit=(CEdit*)GetDlgItem(IDC_HOTENGV_EDIT);
			CEdit*		pNgaySinhGVEdit=(CEdit*)GetDlgItem(IDC_NGAYSINHGV_EDIT);
			CEdit*		pDiaChiGVEdit=(CEdit*)GetDlgItem(IDC_DIACHIGV_EDIT);
			CEdit*		pGhiChuGVEdit=(CEdit*)GetDlgItem(IDC_GHICHUGV_EDIT);

			CButton*	pNamGVButton=(CButton*)GetDlgItem(IDC_NAMGV_CHECK);			

			CListCtrl*	pGiaoVienListCtrl=(CListCtrl*)GetDlgItem(IDC_GIAOVIEN_LIST);
								///////////
			pMaGVStatic->ShowWindow(nCmdShow);
			pHoTenGVStatic->ShowWindow(nCmdShow);
			pNgaySinhGVStatic->ShowWindow(nCmdShow);
			pDiaChiGVStatic->ShowWindow(nCmdShow);
			pGhiChuGVStatic->ShowWindow(nCmdShow);

			pMaGVEdit->ShowWindow(nCmdShow);
			pHoTenGVEdit->ShowWindow(nCmdShow);
			pNgaySinhGVEdit->ShowWindow(nCmdShow);
			pDiaChiGVEdit->ShowWindow(nCmdShow);
			pGhiChuGVEdit->ShowWindow(nCmdShow);

			pNamGVButton->ShowWindow(nCmdShow);

			pGiaoVienListCtrl->ShowWindow(nCmdShow);
		}
			break;
		default:
			MessageBox("Error! Index is not valid","Error",MB_OK|MB_ICONSTOP);
			return;
	}

}

void CQlhsView::OnSelchangeQlhsTab(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CTabCtrl*	pTabCtrl=(CTabCtrl*)GetDlgItem(pNMHDR->idFrom);
	CQlhsDoc*	pDoc=(CQlhsDoc*)GetDocument();

	DWORD		Idx=(DWORD)pTabCtrl->GetCurSel();
	switch(Idx)
	{
		case IDX_HOCSINH:
			pDoc->m_Access|=ACCESS_HOCSINH;
			pDoc->m_CurAccess=ACCESS_HOCSINH;
			break;
		case IDX_LOP:
			pDoc->m_Access|=ACCESS_LOP;
			pDoc->m_CurAccess=ACCESS_LOP;
			break;
		case IDX_MONHOC:
			pDoc->m_Access|=ACCESS_MONHOC;
			pDoc->m_CurAccess=ACCESS_MONHOC;
			break;
		case IDX_GIAOVIEN:
			pDoc->m_Access|=ACCESS_GIAOVIEN;
			pDoc->m_CurAccess=ACCESS_GIAOVIEN;
			break;
		default:
			MessageBox("Error! Index is not valid","Error",MB_OK|MB_ICONSTOP);

			*pResult = 1;
			return;
	}

	pDoc->m_Index=Idx;
	pDoc->UpdateAllViews(NULL,(LPARAM)Idx);
	*pResult = 0;
}

void CQlhsView::OnSelchangingQlhsTab(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
		
	*pResult = 0;
}
void CQlhsView::OnUpdateRecordPrev(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CQlhsDoc*	pDoc=(CQlhsDoc*)GetDocument();
	switch(pDoc->m_CurAccess)
	{
		case ACCESS_HOCSINH:
			pCmdUI->Enable(!pDoc->m_bHSFirst&&pDoc->m_HocSinhUse==DBOPEN);
			break;
		case ACCESS_LOP:
			pCmdUI->Enable(!pDoc->m_bLopFirst&&pDoc->m_LopUse==DBOPEN);
			break;
		case ACCESS_MONHOC:
			pCmdUI->Enable(!pDoc->m_bMHFirst&&pDoc->m_MonHocUse==DBOPEN);
			break;
		case ACCESS_GIAOVIEN:
			pCmdUI->Enable(!pDoc->m_bGVFirst&&pDoc->m_GiaoVienUse==DBOPEN);
			break;
	}
}
void CQlhsView::OnUpdateRecordNext(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CQlhsDoc*	pDoc=(CQlhsDoc*)GetDocument();
	switch(pDoc->m_CurAccess)
	{
		case ACCESS_HOCSINH:
			pCmdUI->Enable(!pDoc->m_bHSLast&&pDoc->m_HocSinhUse==DBOPEN);
			break;
		case ACCESS_LOP:
			pCmdUI->Enable(!pDoc->m_bLopLast&&pDoc->m_LopUse==DBOPEN);
			break;
		case ACCESS_MONHOC:
			pCmdUI->Enable(!pDoc->m_bMHLast&&pDoc->m_MonHocUse==DBOPEN);
			break;
		case ACCESS_GIAOVIEN:
			pCmdUI->Enable(!pDoc->m_bGVLast&&pDoc->m_GiaoVienUse==DBOPEN);
			break;
	}
}


void CQlhsView::OnUpdateRecordFirst(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CQlhsDoc*	pDoc=(CQlhsDoc*)GetDocument();
	switch(pDoc->m_CurAccess)
	{
		case ACCESS_HOCSINH:
			pCmdUI->Enable(!pDoc->m_bHSFirst&&pDoc->m_HocSinhUse==DBOPEN);
			break;
		case ACCESS_LOP:
			pCmdUI->Enable(!pDoc->m_bLopFirst&&pDoc->m_LopUse==DBOPEN);
			break;
		case ACCESS_MONHOC:
			pCmdUI->Enable(!pDoc->m_bMHFirst&&pDoc->m_MonHocUse==DBOPEN);
			break;
		case ACCESS_GIAOVIEN:
			pCmdUI->Enable(!pDoc->m_bGVFirst&&pDoc->m_GiaoVienUse==DBOPEN);
			break;
	}
}

void CQlhsView::OnUpdateRecordLast(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CQlhsDoc*	pDoc=(CQlhsDoc*)GetDocument();
	switch(pDoc->m_CurAccess)
	{
		case ACCESS_HOCSINH:
			pCmdUI->Enable(!pDoc->m_bHSLast&&pDoc->m_HocSinhUse==DBOPEN);
			break;
		case ACCESS_LOP:
			pCmdUI->Enable(!pDoc->m_bLopLast&&pDoc->m_LopUse==DBOPEN);
			break;
		case ACCESS_MONHOC:
			pCmdUI->Enable(!pDoc->m_bMHLast&&pDoc->m_MonHocUse==DBOPEN);
			break;
		case ACCESS_GIAOVIEN:
			pCmdUI->Enable(!pDoc->m_bGVLast&&pDoc->m_GiaoVienUse==DBOPEN);
			break;
	}
}
void CQlhsView::OnMove(UINT nIDMoveCommand)
{
	if(!UpdateData())
		return ;

	CQlhsDoc*	pDoc=(CQlhsDoc*)GetDocument();
	HRESULT		hr = E_UNEXPECTED;
	DWORD		Idx=0;
	switch(pDoc->m_CurAccess)
	{
		case ACCESS_HOCSINH:
			if(pDoc->m_HocSinhUse==DBERROR)
				goto err;
			//hr=m_pHocSinhSet->SetData();
			//ASSERT(hr==S_OK);
			switch(nIDMoveCommand)
			{
				case ID_RECORD_PREV:
					hr=m_pHocSinhSet->MovePrev();
					if(hr!=S_OK)
					{
						if(hr==DB_S_ENDOFROWSET || hr==DB_E_BADSTARTPOSITION)
							SendMessage(WM_COMMAND,ID_RECORD_FIRST);
						else
							MessageBox("Error in file","Error",MB_OK|MB_ICONSTOP);
					}
					else
						pDoc->m_bHSLast=FALSE;

					break;
				case ID_RECORD_NEXT:
					hr=m_pHocSinhSet->MoveNext();
					if(hr!=S_OK)
					{
						if(hr==DB_S_ENDOFROWSET || hr==DB_E_BADSTARTPOSITION)
							SendMessage(WM_COMMAND,ID_RECORD_LAST);
						else
							MessageBox("Error in file","Error",MB_OK|MB_ICONSTOP);
					}
					else
						pDoc->m_bHSFirst=FALSE;
					break;
				case ID_RECORD_FIRST:
					hr=m_pHocSinhSet->MoveFirst();
					if(hr!=S_OK)
						pDoc->m_HocSinhUse=DBEMPTY;
					else
					{
						pDoc->m_bHSFirst=TRUE;
						pDoc->m_bHSLast=FALSE;
					}

					break;
				case ID_RECORD_LAST:
					hr=m_pHocSinhSet->MoveLast();
					if(!SUCCEEDED(hr))
					{
						MessageBox("Last Record has been deleted","Warning",MB_OK|
									MB_ICONWARNING);
						m_MaHS = _T("");
						m_NamHS.SetCheck(0);
						m_HoTenHS = _T("");
						m_DiaChiHS = _T("");
						m_DienHS = _T("");
						m_NgaySinhHS = _T("");
						m_SoNgayVang = _T("");
						UpdateData(FALSE);
						return;
					}
					else
					{
						pDoc->m_bHSFirst=FALSE;
						pDoc->m_bHSLast=TRUE;
					}
					break;
				default:
					goto err;
			}

			Idx=IDX_HOCSINH;
			break;
		case ACCESS_LOP:
			if(pDoc->m_LopUse==DBERROR)
				goto err;
			//hr=m_pLopSet->SetData();
			//ASSERT(hr==S_OK);
			switch(nIDMoveCommand)
			{
				case ID_RECORD_PREV:
					hr=m_pLopSet->MovePrev();
					if(hr!=S_OK)
					{
						if(hr==DB_S_ENDOFROWSET || hr==DB_E_BADSTARTPOSITION)
							SendMessage(WM_COMMAND,ID_RECORD_FIRST);
						else
							MessageBox("Error in file","Error",MB_OK|MB_ICONSTOP);
					}
					else
						pDoc->m_bLopLast=FALSE;

					break;
				case ID_RECORD_NEXT:
					hr=m_pLopSet->MoveNext();
					if(hr!=S_OK)
					{
						if(hr==DB_S_ENDOFROWSET || hr==DB_E_BADSTARTPOSITION)
							SendMessage(WM_COMMAND,ID_RECORD_LAST);
						else
							MessageBox("Error in file","Error",MB_OK|MB_ICONSTOP);
					}
					else
						pDoc->m_bLopFirst=FALSE;
					break;
				case ID_RECORD_FIRST:
					hr=m_pLopSet->MoveFirst();
					if(hr!=S_OK)
						pDoc->m_LopUse=DBEMPTY;
					else
					{
						pDoc->m_bLopFirst=TRUE;
						pDoc->m_bLopLast=FALSE;
					}

					break;
				case ID_RECORD_LAST:
					hr=m_pLopSet->MoveLast();
					if(!SUCCEEDED(hr))
					{
						MessageBox("Last Record has been deleted","Warning",MB_OK|
									MB_ICONWARNING);
						m_MaLop=_T("");
						m_TenLop=_T("");
						//Cac fields
						m_GhiChuLop=_T("");
						UpdateData(FALSE);
						return;
					}
					else
					{
						pDoc->m_bLopFirst=FALSE;
						pDoc->m_bLopLast=TRUE;
					}
					break;
				default:
					goto err;
			}

			Idx=IDX_LOP;
			break;
		case ACCESS_MONHOC:
			if(pDoc->m_MonHocUse==DBERROR)
				goto err;
			//hr=m_pMonHocSet->SetData();
			//ASSERT(hr==S_OK);
			switch(nIDMoveCommand)
			{
				case ID_RECORD_PREV:
					hr=m_pMonHocSet->MovePrev();
					if(hr!=S_OK)
					{
						if(hr==DB_S_ENDOFROWSET || hr==DB_E_BADSTARTPOSITION)
							SendMessage(WM_COMMAND,ID_RECORD_FIRST);
						else
							MessageBox("Error in file","Error",MB_OK|MB_ICONSTOP);
					}
					else
						pDoc->m_bMHLast=FALSE;

					break;
				case ID_RECORD_NEXT:
					hr=m_pMonHocSet->MoveNext();
					if(hr!=S_OK)
					{
						if(hr==DB_S_ENDOFROWSET || hr==DB_E_BADSTARTPOSITION)
							SendMessage(WM_COMMAND,ID_RECORD_LAST);
						else
							MessageBox("Error in file","Error",MB_OK|MB_ICONSTOP);
					}
					else
						pDoc->m_bMHFirst=FALSE;
					break;
				case ID_RECORD_FIRST:
					hr=m_pMonHocSet->MoveFirst();
					if(hr!=S_OK)
						pDoc->m_MonHocUse=DBEMPTY;
					else
					{
						pDoc->m_bMHFirst=TRUE;
						pDoc->m_bMHLast=FALSE;
					}

					break;
				case ID_RECORD_LAST:
					hr=m_pMonHocSet->MoveLast();
					if(!SUCCEEDED(hr))
					{
						MessageBox("Last Record has been deleted","Warning",MB_OK|
									MB_ICONWARNING);
						m_MaMH=_T("");
						m_TenMH=_T("");
						m_HeSo=_T("");
						m_SoTiet=_T("");
						m_GhiChuMH=_T("");
						UpdateData(FALSE);
						return;
					}
					else
					{
						pDoc->m_bMHFirst=FALSE;
						pDoc->m_bMHLast=TRUE;
					}
					break;
				default:
					goto err;
			}

			Idx=IDX_MONHOC;
			break;
		case ACCESS_GIAOVIEN:
			if(pDoc->m_HocSinhUse==DBERROR)
				goto err;
			//hr=m_pGiaoVienSet->SetData();
			//ASSERT(hr==S_OK);
			switch(nIDMoveCommand)
			{
				case ID_RECORD_PREV:
					hr=m_pGiaoVienSet->MovePrev();
					if(hr!=S_OK)
					{
						if(hr==DB_S_ENDOFROWSET || hr==DB_E_BADSTARTPOSITION)
							SendMessage(WM_COMMAND,ID_RECORD_FIRST);
						else
							MessageBox("Error in file","Error",MB_OK|MB_ICONSTOP);
					}
					else
						pDoc->m_bGVLast=FALSE;

					break;
				case ID_RECORD_NEXT:
					hr=m_pGiaoVienSet->MoveNext();
					if(hr!=S_OK)
					{
						if(hr==DB_S_ENDOFROWSET || hr==DB_E_BADSTARTPOSITION)
							SendMessage(WM_COMMAND,ID_RECORD_LAST);
						else
							MessageBox("Error in file","Error",MB_OK|MB_ICONSTOP);
					}
					else
						pDoc->m_bGVFirst=FALSE;
					break;
				case ID_RECORD_FIRST:
					hr=m_pGiaoVienSet->MoveFirst();
					if(hr!=S_OK)
						pDoc->m_GiaoVienUse=DBEMPTY;
					else
					{
						pDoc->m_bGVFirst=TRUE;
						pDoc->m_bGVLast=FALSE;
					}

					break;
				case ID_RECORD_LAST:
					hr=m_pGiaoVienSet->MoveLast();
					if(!SUCCEEDED(hr))
					{
						MessageBox("Last Record has been deleted","Warning",MB_OK|
									MB_ICONWARNING);
						m_MaGV = _T("");
						m_NamGV.SetCheck(0);
						m_HoTenGV = _T("");
						m_DiaChiGV = _T("");
						m_NgaySinhGV = _T("");
						m_GhiChuGV = _T("");
						UpdateData(FALSE);
						return;
					}
					else
					{
						pDoc->m_bGVFirst=FALSE;
						pDoc->m_bGVLast=TRUE;
					}
					break;
				default:
					goto err;
			}

			Idx=IDX_GIAOVIEN;
			break;
		default:
			goto err;
	}
	pDoc->UpdateAllViews(NULL,(LPARAM)Idx);
	return;
err:
	ASSERT(FALSE);
}


void CQlhsView::OnAddButton() 
{
	// TODO: Add your control notification handler code here
	CQlhsDoc*	pDoc=(CQlhsDoc*)GetDocument();
	CEdit*		pEdit;
	switch(pDoc->m_CurAccess)
	{
		case ACCESS_HOCSINH:
			m_MaHS = _T("");
			m_NamHS.SetCheck(0);
			m_HoTenHS = _T("");
			m_DiaChiHS = _T("");
			m_DienHS = _T("");
			m_NgaySinhHS = _T("");
			m_SoNgayVang = _T("");

			pDoc->m_bHSNew=TRUE;
			pEdit=(CEdit*)GetDlgItem(IDC_MAHS_EDIT);
			pEdit->SetFocus();
			break;
		case ACCESS_LOP:
			m_MaLop=_T("");
			m_TenLop=_T("");
			//Cac fields
			m_GhiChuLop=_T("");

			pDoc->m_bLopNew=TRUE;
			pEdit=(CEdit*)GetDlgItem(IDC_MALOP_EDIT);
			pEdit->SetFocus();
			break;
		case ACCESS_MONHOC:
			m_MaMH=_T("");
			m_TenMH=_T("");
			m_HeSo=_T("");
			m_SoTiet=_T("");
			m_GhiChuMH=_T("");

			pDoc->m_bMHNew=TRUE;
			pEdit=(CEdit*)GetDlgItem(IDC_MAMH_EDIT);
			pEdit->SetFocus();
			break;
		case ACCESS_GIAOVIEN:
			m_MaGV = _T("");
			m_NamGV.SetCheck(0);
			m_HoTenGV = _T("");
			m_DiaChiGV = _T("");
			m_NgaySinhGV = _T("");
			m_GhiChuGV = _T("");

			pDoc->m_bGVNew=TRUE;
			pEdit=(CEdit*)GetDlgItem(IDC_MAGV_EDIT);
			pEdit->SetFocus();
			break;
	}
	UpdateData(FALSE);
	
}

void CQlhsView::OnDeleteButton() 
{
	// TODO: Add your control notification handler code here
	if(MessageBox("This record will be deleted !\nAre you sure ?",
		"Remind",MB_YESNO|MB_ICONQUESTION)!=IDYES)
		return;
	CQlhsDoc*	pDoc=(CQlhsDoc*)GetDocument();
	HRESULT		hr;
	switch(pDoc->m_CurAccess)
	{
		case ACCESS_HOCSINH:
			hr=m_pHocSinhSet->Delete();
			break;
		case ACCESS_LOP:
			hr=m_pLopSet->Delete();
			break;
		case ACCESS_MONHOC:
			hr=m_pMonHocSet->Delete();
			break;
		case ACCESS_GIAOVIEN:
			hr=m_pGiaoVienSet->Delete();
			break;
	}
	if(FAILED(hr))
	{
		MessageBox("Can't delete this record");
		return;
	}
	SendMessage(WM_COMMAND,ID_RECORD_FIRST);
}

void CQlhsView::OnUpdateButton() 
{
	// TODO: Add your control notification handler code here
	CQlhsDoc*		pDoc=(CQlhsDoc*)GetDocument();
	HRESULT			hr;
	DWORD			Idx;
	int				year,month,day;
	CStringArray	aszS;

	UpdateData(TRUE);
	switch(pDoc->m_CurAccess)
	{
		case ACCESS_HOCSINH:
			if(pDoc->m_bHSNew)
				m_pHocSinhSet->ClearRecord();

			lstrcpy(m_pHocSinhSet->m_MaHS,m_MaHS.GetBuffer(51));
			lstrcpy(m_pHocSinhSet->m_HoTenHS,m_HoTenHS.GetBuffer(51));
			if(m_NamHS.GetCheck()==1)
				m_pHocSinhSet->m_Nam=TRUE;
			else
				m_pHocSinhSet->m_Nam=FALSE;
			lstrcpy(m_pHocSinhSet->m_DiaChiHS,m_DiaChiHS.GetBuffer(256));
			m_pHocSinhSet->m_DienHS=(LONG)atoi(m_DienHS);
			SplitString(m_NgaySinhGV,'/',aszS);
			if(aszS.GetSize()!=3)
				goto errHS;
			year=atoi(aszS[2]);
			month=atoi(aszS[0]);
			day=atoi(aszS[1]);
			if(year<70||year>99||month<1||month>12||day<1||day>31)
				goto errHS;
			goto HS;
		errHS:
			MessageBox("Error! Invalid date","Error",MB_OK|MB_ICONSTOP);
			return;
		HS:

			m_pHocSinhSet->m_NgaySinhHS.year=year;
			m_pHocSinhSet->m_NgaySinhHS.month=month;
			m_pHocSinhSet->m_NgaySinhHS.day=day;
			m_pHocSinhSet->m_NgaySinhHS.hour=0;
			m_pHocSinhSet->m_NgaySinhHS.minute=0;
			m_pHocSinhSet->m_NgaySinhHS.second=0;

			m_pHocSinhSet->m_SoNgayVang=(LONG)atoi(m_SoNgayVang);

			if(pDoc->m_bHSNew)
			{
				hr=m_pHocSinhSet->Insert();
				if(FAILED(hr))
				{
					MessageBox("Error! Failed Insert ","Error",MB_OK|MB_ICONSTOP);
					pDoc->m_bHSNew=FALSE;
					return;
				}	
				pDoc->m_bHSNew=FALSE;
				pDoc->m_HocSinhUse=DBOPEN;
			}
			else
			{
				hr=m_pHocSinhSet->SetData();
				if(FAILED(hr))
				{
					MessageBox("Error! Failed Update","Error",MB_OK|MB_ICONSTOP);
					return;
				}
			}	
			Idx=IDX_HOCSINH;
			break;
		case ACCESS_LOP:
			if(pDoc->m_bLopNew)
				m_pLopSet->ClearRecord();

			//Cap nhat Fileds o day

			if(pDoc->m_bLopNew)
			{
				hr=m_pLopSet->Insert();
				if(FAILED(hr))
				{
					MessageBox("Error! Failed Insert ","Error",MB_OK|MB_ICONSTOP);
					pDoc->m_bLopNew=FALSE;
					return;
				}	
				pDoc->m_bLopNew=FALSE;
				pDoc->m_LopUse=DBOPEN;
			}
			else
			{
				hr=m_pLopSet->SetData();
				if(FAILED(hr))
				{
					MessageBox("Error! Failed Update","Error",MB_OK|MB_ICONSTOP);
					return;
				}
			}	
			Idx=IDX_LOP;
			break;
		case ACCESS_MONHOC:
			if(pDoc->m_bMHNew)
				m_pMonHocSet->ClearRecord();

			//Cap nhat Fileds o day

			if(pDoc->m_bMHNew)
			{
				hr=m_pMonHocSet->Insert();
				if(FAILED(hr))
				{
					MessageBox("Error! Failed Insert ","Error",MB_OK|MB_ICONSTOP);
					pDoc->m_bMHNew=FALSE;
					return;
				}	
				pDoc->m_bMHNew=FALSE;
				pDoc->m_MonHocUse=DBOPEN;
			}
			else
			{
				hr=m_pMonHocSet->SetData();
				if(FAILED(hr))
				{
					MessageBox("Error! Failed Update","Error",MB_OK|MB_ICONSTOP);
					return;
				}
			}	
			Idx=IDX_MONHOC;
			break;
		case ACCESS_GIAOVIEN:
			if(pDoc->m_bGVNew)
				m_pGiaoVienSet->ClearRecord();

			lstrcpy(m_pGiaoVienSet->m_MaGV,m_MaGV.GetBuffer(51));
			lstrcpy(m_pGiaoVienSet->m_HoTenGV,m_HoTenGV.GetBuffer(51));
			if(m_NamGV.GetCheck()==1)
				m_pGiaoVienSet->m_Nam=TRUE;
			else
				m_pGiaoVienSet->m_Nam=FALSE;
			lstrcpy(m_pGiaoVienSet->m_DiaChiGV,m_DiaChiGV.GetBuffer(256));
			//m_pGiaoVienSet->m_NgaySinhGV=m_NgaySinhGV;
			lstrcpy(m_pGiaoVienSet->m_Ghichu,m_GhiChuGV.GetBuffer(51));

			if(pDoc->m_bGVNew)
			{
				hr=m_pGiaoVienSet->Insert();
				if(FAILED(hr))
				{
					MessageBox("Error! Failed Insert ","Error",MB_OK|MB_ICONSTOP);
					pDoc->m_bGVNew=FALSE;
					return;
				}	
				pDoc->m_bGVNew=FALSE;
				pDoc->m_GiaoVienUse=DBOPEN;
			}
			else
			{
				hr=m_pGiaoVienSet->SetData();
				if(FAILED(hr))
				{
					MessageBox("Error! Failed Update","Error",MB_OK|MB_ICONSTOP);
					return;
				}
			}	
			Idx=IDX_GIAOVIEN;
			break;
	}
	pDoc->UpdateAllViews(NULL,(LPARAM)Idx);
}
