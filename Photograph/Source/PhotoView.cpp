// PhotoView.cpp : implementation of the CPhotoView class
//

#include "stdafx.h"
#include "Photo.h"

#include "PhotoDoc.h"
#include "PhotoView.h"

#include "Image.h"
#include "ImageToolKit.h"
#include "OperatorDlg.h"
#include "InfoDlg.h"
#include "CutDlg.h"
#include "ChooseNameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPhotoView

IMPLEMENT_DYNCREATE(CPhotoView, CScrollView)

BEGIN_MESSAGE_MAP(CPhotoView, CScrollView)
	//{{AFX_MSG_MAP(CPhotoView)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, OnUpdateFileSendMail)
	ON_WM_ERASEBKGND()
	ON_WM_PALETTECHANGED()
	ON_WM_QUERYNEWPALETTE()
	ON_UPDATE_COMMAND_UI(ID_IMAGE_NORMAL, OnUpdateImageNormal)
	ON_COMMAND(ID_IMAGE_NORMAL, OnImageNormal)
	ON_UPDATE_COMMAND_UI(ID_IMAGE_CENTER, OnUpdateImageCenter)
	ON_COMMAND(ID_IMAGE_CENTER, OnImageCenter)
	ON_UPDATE_COMMAND_UI(ID_IMAGE_STRETCH, OnUpdateImageStretch)
	ON_COMMAND(ID_IMAGE_STRETCH, OnImageStretch)
	ON_COMMAND(ID_TOOLS_OPERATOR_ADD, OnToolsOperatorAdd)
	ON_COMMAND(ID_TOOLS_OPERATOR_SUB, OnToolsOperatorSub)
	ON_COMMAND(ID_TOOLS_OPERATOR_MUL, OnToolsOperatorMul)
	ON_COMMAND(ID_TOOLS_OPERATOR_DIV, OnToolsOperatorDiv)
	ON_COMMAND(ID_TOOLS_OPERATOR_NOT, OnToolsOperatorNot)
	ON_COMMAND(ID_TOOLS_OPERATOR_AND, OnToolsOperatorAnd)
	ON_COMMAND(ID_TOOLS_OPERATOR_OR, OnToolsOperatorOr)
	ON_COMMAND(ID_TOOLS_OPERATOR_XOR, OnToolsOperatorXor)
	ON_COMMAND(ID_TOOLS_OPERATOR_MIN, OnToolsOperatorMin)
	ON_COMMAND(ID_TOOLS_OPERATOR_MAX, OnToolsOperatorMax)
	ON_COMMAND(ID_TOOLS_OPERATOR_ABS, OnToolsOperatorAbs)
	ON_COMMAND(ID_IMAGE_INFORMATION, OnImageInformation)
	ON_COMMAND(ID_IMAGE_GRAYSCALE, OnImageGrayScale)
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_ENHANCE_HISTOGRAMEQUALIZATION, OnEnhanceHistogramEqualization)
	ON_COMMAND(ID_IMAGE_CUT, OnImageCut)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_SCROLL_BUTTON, OnScrollButton)
	ON_UPDATE_COMMAND_UI(ID_SCROLL_BUTTON, OnUpdateScrollButton)
	ON_UPDATE_COMMAND_UI(ID_IMAGE_SAVEIMAGESARRAY, OnUpdateImageSaveimagesarray)
	ON_COMMAND(ID_IMAGE_SAVEIMAGESARRAY, OnImageSaveimagesarray)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPhotoView construction/destruction

CPhotoView::CPhotoView()
{
	// TODO: add construction code here
	m_dwDisplayMode=DISPLAY_NORMAL;
	m_bMouseDown=FALSE;
	m_bScroll=FALSE;
}

CPhotoView::~CPhotoView()
{
}

BOOL CPhotoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPhotoView drawing

void CPhotoView::OnDraw(CDC* pDC)
{
	CPhotoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	CClientDC	dc(this);
	CRect		rc;
	CImage*		pImg=pDoc->GetImage();
	HINSTANCE	hInstance;
	HCURSOR		hOldCursor,hCursor;

	BITMAPINFOHEADER	Info;
	CPoint	OldPoint;//Old Origin Point

	CSize	docSize;
	CSize	pageSize(rc.Width(),rc.Height());
	CSize	lineSize(16,16);

	CPoint	dstPoint=CPoint(0,0);
	CSize	dstSize=CSize(0,0);
	CPoint	srcOffset=CPoint(0,0);
	CSize	srcSize=CSize(0,0);

	GetClientRect(&rc);
	if(!pImg->IsValid())
		goto error;

	if(!pImg->GetInfo(&Info))
	{
		delete pImg;
		goto error;
	}

	switch(m_dwDisplayMode)
	{
		case DISPLAY_NORMAL:
			OldPoint=pImg->GetPtOrg();
		
			docSize.cx=Info.biWidth;
			docSize.cy=Info.biHeight;
			break;
		case DISPLAY_CENTER:
			OldPoint=pImg->SetPtOrgCenter();
	
			dstPoint.x=rc.Width()/2;
			dstPoint.y=rc.Height()/2;

			docSize.cx=Info.biWidth;
			docSize.cy=Info.biHeight;
			break;
		case DISPLAY_STRETCH:
			OldPoint=pImg->SetPtOrgLeftTop();

			dstSize.cx=rc.Width();
			dstSize.cy=rc.Height();

			docSize=dstSize;
			break;
	}


	hInstance=AfxGetInstanceHandle();
	hCursor=::LoadCursor(hInstance,IDC_WAIT);
	hOldCursor=::SetCursor(hCursor);
	if(!pImg->Draw(pDC,dstPoint,dstSize,srcOffset,srcSize))
	{
		delete pImg;
		pImg->SetPtOrg(OldPoint);
		::SetCursor(hOldCursor);
		goto error;
	}
	::SetCursor(hOldCursor);
	pImg->SetPtOrg(OldPoint);
	
	SetScrollSizes(MM_TEXT,docSize,pageSize,lineSize);
	//m_bScroll=(docSize.cx>rc.Width()||docSize.cy>rc.Height())?TRUE:FALSE;
	//m_bScroll=TRUE;
	return;
error:
	m_bScroll=FALSE;
	return;
}

void CPhotoView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CPhotoView Palette Function

BOOL CPhotoView::RealizePalette(BOOL bForceBkgnd)
{
	UINT	nColorsChanged;
	{
		CClientDC	dc(this);
		HDRAWDIB	hdd;

		hdd=DrawDibOpen();
		nColorsChanged=DrawDibRealize(hdd,dc.GetSafeHdc(),bForceBkgnd);
		DrawDibClose(hdd);
	}
	if(nColorsChanged||bForceBkgnd)
		Invalidate(TRUE);
	return (BOOL)nColorsChanged;
}
void CPhotoView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(bActivate)
		RealizePalette(FALSE);

	CScrollView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}
void CPhotoView::OnPaletteChanged(CWnd* pFocusWnd)
{
	if(pFocusWnd==this||IsChild(pFocusWnd))
		return;
	RealizePalette(TRUE);

}
BOOL CPhotoView::OnQueryNewPalette()
{
	return RealizePalette(FALSE);
}
/////////////////////////////////////////////////////////////////////////////
// CPhotoView printing

BOOL CPhotoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPhotoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPhotoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPhotoView diagnostics

#ifdef _DEBUG
void CPhotoView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CPhotoView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CPhotoDoc* CPhotoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPhotoDoc)));
	return (CPhotoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPhotoView message handlers

BOOL CPhotoView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	CBrush	*pBrush,*pOldBrush;
	CRect	rc;
	BOOL	ret;

	pBrush=new CBrush;
	pDC->GetClipBox(&rc);
	pBrush->CreateSolidBrush(RGB(128,128,128));
	pOldBrush=pDC->SelectObject(pBrush);
	ret=pDC->PatBlt(rc.left,rc.top,rc.Width(),rc.Height(),PATCOPY);
	pDC->SelectObject(pOldBrush);
	delete pBrush;

	return ret;
}

BOOL CPhotoView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	if(nHitTest!=HTCLIENT||!m_bScroll)
		return CScrollView::OnSetCursor(pWnd, nHitTest, message);
	HCURSOR	hCursor;

	if(m_bMouseDown)
		hCursor=AfxGetApp()->LoadCursor(IDC_HANDGRAB_CURSOR);
	else
		hCursor=AfxGetApp()->LoadCursor(IDC_HANDFLAT_CURSOR);

	::SetCursor(hCursor);
	return TRUE;

	return CScrollView::OnSetCursor(pWnd, nHitTest, message);
}
void CPhotoView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(!m_bScroll)
	{
		CScrollView::OnLButtonDown(nFlags, point);
		return;
	}
	WPARAM wParam;
	LPARAM lParam;

	m_bMouseDown=TRUE;
	wParam=(WPARAM)GetSafeHwnd();
	lParam=WM_LBUTTONDOWN;
	lParam=(lParam<<16)|HTCLIENT;
	SendMessage(WM_SETCURSOR,wParam,lParam);
	
	GetCursorPos(&m_ptCursorCurPos);
	m_ptCursorOldPos=m_ptCursorCurPos;
	SetCapture();
	CScrollView::OnLButtonDown(nFlags, point);
}


void CPhotoView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(!m_bMouseDown)
	{
		CScrollView::OnLButtonUp(nFlags, point);
		return;
	}
	CSize	d;
	CPoint	ptScrollPos;

	GetCursorPos(&m_ptCursorCurPos);
	d=m_ptCursorOldPos-m_ptCursorCurPos;
	ptScrollPos=GetScrollPosition();
	ptScrollPos.x +=d.cx;
	ptScrollPos.y +=d.cy;
	
	ScrollToPosition(ptScrollPos);

	m_ptCursorOldPos=m_ptCursorCurPos;

	CScrollView::OnMouseMove(nFlags, point);
}
void CPhotoView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(!m_bMouseDown)
	{
		CScrollView::OnLButtonUp(nFlags, point);
		return;
	}
	WPARAM wParam;
	LPARAM lParam;

	m_bMouseDown=FALSE;
	wParam=(WPARAM)GetSafeHwnd();
	lParam=WM_LBUTTONUP;
	lParam=(lParam<<16)|HTCLIENT;
	SendMessage(WM_SETCURSOR,wParam,lParam);
	
	::ReleaseCapture();
	CScrollView::OnLButtonUp(nFlags, point);
}


void CPhotoView::OnUpdateFileSendMail(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	CPhotoDoc* pDoc=GetDocument();
	if(!pDoc->GetImage()->IsValid())
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// CPhotoView Image Menu

void CPhotoView::OnUpdateImageNormal(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_dwDisplayMode==DISPLAY_NORMAL)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void CPhotoView::OnImageNormal() 
{
	// TODO: Add your command handler code here
	m_dwDisplayMode=DISPLAY_NORMAL;
	Invalidate(TRUE);
}

void CPhotoView::OnUpdateImageCenter(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_dwDisplayMode==DISPLAY_CENTER)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
	
}

void CPhotoView::OnImageCenter() 
{
	// TODO: Add your command handler code here
	m_dwDisplayMode=DISPLAY_CENTER;
	Invalidate(TRUE);
}

void CPhotoView::OnUpdateImageStretch(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_dwDisplayMode==DISPLAY_STRETCH)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
	
}

void CPhotoView::OnImageStretch() 
{
	// TODO: Add your command handler code here
	m_dwDisplayMode=DISPLAY_STRETCH;
	Invalidate(TRUE);
}
void CPhotoView::OnImageGrayScale() 
{
	// TODO: Add your command handler code here
	CPhotoDoc*  pDoc=GetDocument();
	CImage* pImg=pDoc->GetImage();

	if(!pImg->IsValid())
	{
		MessageBox("Error:Image is not load or invalid","Error",
					MB_OK|MB_ICONSTOP);
		return;
	}
	if(pImg->ConvertToGrayScale())
	{
		pDoc->SetModifiedFlag(TRUE);//Co thay doi 
		Invalidate(TRUE);
	}
	else
		MessageBox("Can't convert to GrayScal","Error",MB_OK|MB_ICONSTOP);
}

void CPhotoView::OnImageInformation() 
{
	// TODO: Add your command handler code here
	CPhotoDoc*  pDoc=GetDocument();
	if(!pDoc->GetImage()->IsValid())
	{
		MessageBox("Error:Image is not load or invalid","Error",
					MB_OK|MB_ICONSTOP);
		return;
	}

	
	CInfoDlg dlgInfo(this);
	dlgInfo.DoModal();
	
}

/////////////////////////////////////////////////////////////////////////////
// CPhotoView Tools Menu

void CPhotoView::OnToolsOperatorAdd() 
{
	// TODO: Add your command handler code here
	CPhotoDoc*  pDoc=GetDocument();
	CImage* pImg=pDoc->GetImage();

	if(!pImg->IsValid())
	{
		MessageBox("Error:Image is not load or invalid","Error",
					MB_OK|MB_ICONSTOP);
		return;
	}

	COperatorDlg dlgOperator(this);
	dlgOperator.m_szNameDlg="Operator Add";
	if(dlgOperator.DoModal()==IDOK)
	{
		if(dlgOperator.m_bFlag)
			*pImg +=dlgOperator.m_dwValue;
		else
		{
			CImage img;
			if(!img.LoadFromFile(dlgOperator.m_szFilePath))
			{
				MessageBox("Error : Load File Fail","Error",MB_ICONSTOP);
				return;
			}
			*pImg =*pImg+img;
		}
		pDoc->SetModifiedFlag(TRUE);//Co thay doi 
		Invalidate(TRUE);
	}
}

void CPhotoView::OnToolsOperatorSub() 
{
	// TODO: Add your command handler code here
	CPhotoDoc*  pDoc=GetDocument();
	CImage* pImg=pDoc->GetImage();

	if(!pImg->IsValid())
	{
		MessageBox("Error:Image is not load or invalid","Error",
					MB_OK|MB_ICONSTOP);
		return;
	}

	COperatorDlg dlgOperator(this);
	dlgOperator.m_szNameDlg="Operator Sub";
	if(dlgOperator.DoModal()==IDOK)
	{
		if(dlgOperator.m_bFlag)
		{
			if(!dlgOperator.m_bReversed)
				*pImg -=dlgOperator.m_dwValue;
			else
				*pImg =dlgOperator.m_dwValue-(*pImg);
		}
		else
		{
			CImage img;
			if(!img.LoadFromFile(dlgOperator.m_szFilePath))
			{
				MessageBox("Error : Load File Fail","Error",MB_ICONSTOP);
				return;
			}
			if(!dlgOperator.m_bReversed)
				*pImg -=img;
			else
				*pImg =img-*pImg ;
		}
		pDoc->SetModifiedFlag(TRUE);//Co thay doi 
		Invalidate(TRUE);
	}
}

void CPhotoView::OnToolsOperatorMul() 
{
	// TODO: Add your command handler code here
	CPhotoDoc*  pDoc=GetDocument();
	CImage* pImg=pDoc->GetImage();

	if(!pImg->IsValid())
	{
		MessageBox("Error:Image is not load or invalid","Error",
					MB_OK|MB_ICONSTOP);
		return;
	}

	COperatorDlg dlgOperator(this);
	dlgOperator.m_szNameDlg="Operator Multiple";
	if(dlgOperator.DoModal()==IDOK)
	{
		if(dlgOperator.m_bFlag)
			*pImg *=dlgOperator.m_dwValue;
		else
		{
			CImage img;
			if(!img.LoadFromFile(dlgOperator.m_szFilePath))
			{
				MessageBox("Error : Load File Fail","Error",MB_ICONSTOP);
				return;
			}
			*pImg *=img;
		}
		pDoc->SetModifiedFlag(TRUE);//Co thay doi 
		Invalidate(TRUE);
	}
	
}

void CPhotoView::OnToolsOperatorDiv() 
{
	// TODO: Add your command handler code here
	CPhotoDoc*  pDoc=GetDocument();
	CImage* pImg=pDoc->GetImage();

	if(!pImg->IsValid())
	{
		MessageBox("Error:Image is not load or invalid","Error",
					MB_OK|MB_ICONSTOP);
		return;
	}

	COperatorDlg dlgOperator(this);
	dlgOperator.m_szNameDlg="Operator Divide";
	if(dlgOperator.DoModal()==IDOK)
	{
		if(dlgOperator.m_bFlag)
		{
			if(!dlgOperator.m_bReversed)
				*pImg /=dlgOperator.m_dwValue;
			else
				*pImg =dlgOperator.m_dwValue/(*pImg);
		}
		else
		{
			CImage img;
			if(!img.LoadFromFile(dlgOperator.m_szFilePath))
			{
				MessageBox("Error : Load File Fail","Error",MB_ICONSTOP);
				return;
			}
			if(!dlgOperator.m_bReversed)
				*pImg /=img;
			else
				*pImg =img/(*pImg);
		}
		pDoc->SetModifiedFlag(TRUE);//Co thay doi 
		Invalidate(TRUE);
	}
}

void CPhotoView::OnToolsOperatorNot() 
{
	// TODO: Add your command handler code here
	CPhotoDoc*  pDoc=GetDocument();
	CImage* pImg=pDoc->GetImage();

	if(!pImg->IsValid())
	{
		MessageBox("Error:Image is not load or invalid","Error",
					MB_OK|MB_ICONSTOP);
		return;
	}

	~(*pImg);
	pDoc->SetModifiedFlag(TRUE);//Co thay doi 
	Invalidate(TRUE);
}

void CPhotoView::OnToolsOperatorAnd() 
{
	// TODO: Add your command handler code here
	CPhotoDoc*  pDoc=GetDocument();
	CImage* pImg=pDoc->GetImage();

	if(!pImg->IsValid())
	{
		MessageBox("Error:Image is not load or invalid","Error",
					MB_OK|MB_ICONSTOP);
		return;
	}

	COperatorDlg dlgOperator(this);
	dlgOperator.m_szNameDlg="Operator And";
	if(dlgOperator.DoModal()==IDOK)
	{
		if(dlgOperator.m_bFlag)
			*pImg &=dlgOperator.m_dwValue;
		else
		{
			CImage img;
			if(!img.LoadFromFile(dlgOperator.m_szFilePath))
			{
				MessageBox("Error : Load File Fail","Error",MB_ICONSTOP);
				return;
			}
			*pImg &=img;
		}
		pDoc->SetModifiedFlag(TRUE);//Co thay doi 
		Invalidate(TRUE);
	}
}

void CPhotoView::OnToolsOperatorOr() 
{
	// TODO: Add your command handler code here
	CPhotoDoc*  pDoc=GetDocument();
	CImage* pImg=pDoc->GetImage();

	if(!pImg->IsValid())
	{
		MessageBox("Error:Image is not load or invalid","Error",
					MB_OK|MB_ICONSTOP);
		return;
	}

	COperatorDlg dlgOperator(this);
	dlgOperator.m_szNameDlg="Operator Or";
	if(dlgOperator.DoModal()==IDOK)
	{
		if(dlgOperator.m_bFlag)
			*pImg |=dlgOperator.m_dwValue;
		else
		{
			CImage img;
			if(!img.LoadFromFile(dlgOperator.m_szFilePath))
			{
				MessageBox("Error : Load File Fail","Error",MB_ICONSTOP);
				return;
			}
			*pImg |=img;
		}
		pDoc->SetModifiedFlag(TRUE);//Co thay doi 
		Invalidate(TRUE);
	}
}

void CPhotoView::OnToolsOperatorXor() 
{
	// TODO: Add your command handler code here
	CPhotoDoc*  pDoc=GetDocument();
	CImage* pImg=pDoc->GetImage();

	if(!pImg->IsValid())
	{
		MessageBox("Error:Image is not load or invalid","Error",
					MB_OK|MB_ICONSTOP);
		return;
	}

	COperatorDlg dlgOperator(this);
	dlgOperator.m_szNameDlg="Operator Xor";
	if(dlgOperator.DoModal()==IDOK)
	{
		if(dlgOperator.m_bFlag)
			*pImg ^=dlgOperator.m_dwValue;
		else
		{
			CImage img;
			if(!img.LoadFromFile(dlgOperator.m_szFilePath))
			{
				MessageBox("Error : Load File Fail","Error",MB_ICONSTOP);
				return;
			}
			*pImg ^=img;
		}
		pDoc->SetModifiedFlag(TRUE);//Co thay doi 
		Invalidate(TRUE);
	}
}

void CPhotoView::OnToolsOperatorMin() 
{
	// TODO: Add your command handler code here
	CPhotoDoc*  pDoc=GetDocument();
	CImage* pImg=pDoc->GetImage();

	if(!pImg->IsValid())
	{
		MessageBox("Error:Image is not load or invalid","Error",
					MB_OK|MB_ICONSTOP);
		return;
	}

	COperatorDlg dlgOperator(this);
	dlgOperator.m_szNameDlg="Operator Min";
	if(dlgOperator.DoModal()==IDOK)
	{
		if(dlgOperator.m_bFlag)
			*pImg=Min(*pImg,dlgOperator.m_dwValue);
		else
		{
			CImage img;
			if(!img.LoadFromFile(dlgOperator.m_szFilePath))
			{
				MessageBox("Error : Load File Fail","Error",MB_ICONSTOP);
				return;
			}
			*pImg=Min(*pImg,img);
		}
		pDoc->SetModifiedFlag(TRUE);//Co thay doi 
		Invalidate(TRUE);
	}
}

void CPhotoView::OnToolsOperatorMax() 
{
	// TODO: Add your command handler code here
	CPhotoDoc*  pDoc=GetDocument();
	CImage* pImg=pDoc->GetImage();

	if(!pImg->IsValid())
	{
		MessageBox("Error:Image is not load or invalid","Error",
					MB_OK|MB_ICONSTOP);
		return;
	}

	COperatorDlg dlgOperator(this);
	dlgOperator.m_szNameDlg="Operator Max";
	if(dlgOperator.DoModal()==IDOK)
	{
		if(dlgOperator.m_bFlag)
			*pImg=Max(*pImg,dlgOperator.m_dwValue);
		else
		{
			CImage img;
			if(!img.LoadFromFile(dlgOperator.m_szFilePath))
			{
				MessageBox("Error : Load File Fail","Error",MB_ICONSTOP);
				return;
			}
			*pImg=Max(*pImg,img);
		}
		pDoc->SetModifiedFlag(TRUE);//Co thay doi 
		Invalidate(TRUE);
	}
	
}

void CPhotoView::OnToolsOperatorAbs() 
{
	// TODO: Add your command handler code here
	CPhotoDoc*  pDoc=GetDocument();
	CImage* pImg=pDoc->GetImage();

	if(!pImg->IsValid())
	{
		MessageBox("Error:Image is not load or invalid","Error",
					MB_OK|MB_ICONSTOP);
		return;
	}

	COperatorDlg dlgOperator(this);
	dlgOperator.m_szNameDlg="Operator Abs";
	if(dlgOperator.DoModal()==IDOK)
	{
		if(dlgOperator.m_bFlag)
			*pImg=Abs(*pImg,dlgOperator.m_dwValue);
		else
		{
			CImage img;
			if(!img.LoadFromFile(dlgOperator.m_szFilePath))
			{
				MessageBox("Error : Load File Fail","Error",MB_ICONSTOP);
				return;
			}
			*pImg=Abs(*pImg,img);
		}
		pDoc->SetModifiedFlag(TRUE);//Co thay doi 
		Invalidate(TRUE);
	}
}

void CPhotoView::OnEnhanceHistogramEqualization() 
{
	// TODO: Add your command handler code here
	CPhotoDoc*  pDoc=GetDocument();
	CImage* pImg=pDoc->GetImage();

	if(!pImg->IsValid())
	{
		MessageBox("Error:Image is not load or invalid","Error",
					MB_OK|MB_ICONSTOP);
		return;
	}
	pImg->HistEq();
	pDoc->SetModifiedFlag(TRUE);//Co thay doi 
	Invalidate(TRUE);
}

void CPhotoView::OnImageCut() 
{
	// TODO: Add your command handler code here

	CCutDlg*  pCut=new CCutDlg(this);
	if(pCut->DoModal()==IDOK)
	{
		WORD m,n,vm,vn;
		CPhotoDoc* pDoc=GetDocument();
		CImage* pImg=pDoc->GetImage();
		CArray< CPtrArray, CPtrArray& >& ImgA=pDoc->GetImgArray();
		CPoint *pImgPos;
		

		m=pCut->m; 
		vm=pCut->vm; 
		n=pCut->n; 
		vn=pCut->vn; 
		pDoc->DeleteImgArray();
		
		if(!CImageToolKit::CutImages(pImg,m,n,ImgA))
		{
			MessageBox("Khong cat duoc");
			return;
		}

		pImgPos=pDoc->GetImagePos();
		if(!CImageToolKit::Find4Neighbour(ImgA,vm,vn,0,0,pImg,pImgPos))
			return;


		pDoc->SetModifiedFlag(TRUE);//Co thay doi 
		Invalidate();
	}
	delete pCut;
}

void CPhotoView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bScroll)
	{
		CScrollView::OnRButtonDown(nFlags, point);
		return;
	}
	
	CRect rc,imgRc;
	GetClientRect(&rc);
	CPhotoDoc* pDoc=GetDocument();
	CImage* pImg=pDoc->GetImage();
	CPoint pt,scrollPos;
	LONG   Width=pImg->GetWidth(), Height=pImg->GetHeight();	
	CArray< CPtrArray, CPtrArray& >& ImgA=pDoc->GetImgArray();

	scrollPos=GetScrollPosition();

	int k;
	DWORD x,y;
	CPoint* pImgPos;
	float w=1,h=1;

	pt=point;
	switch(m_dwDisplayMode)
	{
		case DISPLAY_NORMAL:
			break;
		case DISPLAY_CENTER:
			if(rc.Width()>=Width)
				pt.x -=(rc.Width()/2-Width/2);
			if(rc.Height()>=Height)
				pt.y -=(rc.Height()/2-Height/2);
			break;
		case DISPLAY_STRETCH:
			w=((float)rc.Width())/((float)Width);
			h=((float)rc.Height())/((float)Height);
			break;
	}

	imgRc.left =scrollPos.x;
	imgRc.top =scrollPos.y;
	
	imgRc.right=imgRc.left+ rc.Width() ;
	imgRc.bottom=imgRc.top+rc.Height();
	LONG W,H;
	W=(LONG)(w*(float)(Width-1));
	if(imgRc.right>W)
		imgRc.right=W;

	H=(LONG)(h*(float)(Height-1));
	if(imgRc.bottom>H)
		imgRc.bottom=H;

	pt +=scrollPos;
	CRect iRc[4];
	if(!imgRc.PtInRect(pt))
		goto end;
	pt.x=(LONG)((float)pt.x/w);
	pt.y=(LONG)((float)pt.y/h);

	iRc[0].left=0;iRc[0].top=0;iRc[0].right=Width/2;iRc[0].bottom=Height/2;
	iRc[1].left=Width/2+1;iRc[1].top=0;iRc[1].right=Width;iRc[1].bottom=Height/2;
	iRc[2].left=0;iRc[2].top=Height/2+1;iRc[2].right=Width/2;iRc[2].bottom=Height;
	iRc[3].left=Width/2+1;iRc[3].top=Height/2+1;iRc[3].right=Width;iRc[3].bottom=Height;

	for(k=0;k<4;k++)
		if(iRc[k].PtInRect(pt))
			break;
	if(k==4)
		goto end;
	x=pt.x-iRc[k].left;
	y=pt.y-iRc[k].top;
	pImgPos=pDoc->GetImagePos();
	if(k!=0)
	{
		switch(k)
		{
			case 1:		
				pImgPos->x =pImgPos->x + 1;
				break;
			case 2:		
				pImgPos->y =pImgPos->y + 1;
				break;
			case 3:		
				pImgPos->x =pImgPos->x + 1;
				pImgPos->y =pImgPos->y + 1;
				break;
		}
	}

	CImageToolKit::Find4Neighbour(ImgA,pImgPos->y,pImgPos->x,x,y,pImg,pImgPos);
	Invalidate();
	
end:
	
	CScrollView::OnRButtonDown(nFlags, point);
}

void CPhotoView::OnScrollButton() 
{
	// TODO: Add your command handler code here
	m_bScroll=!m_bScroll;
}

void CPhotoView::OnUpdateScrollButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CPhotoDoc* pDoc=GetDocument();
	CImage*		pImg=pDoc->GetImage();
	LONG	Width=pImg->GetWidth(),Height=pImg->GetHeight();
	CRect	rc;
	GetClientRect(&rc);
	if(m_dwDisplayMode==DISPLAY_STRETCH || 
		(rc.Width()==Width && rc.Height()==Height))
	{
		pCmdUI->SetCheck(1);
		m_bScroll=FALSE;
		pCmdUI->Enable(FALSE);
		return;
	}
	pCmdUI->Enable(TRUE);
	if(m_bScroll)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void CPhotoView::OnUpdateImageSaveimagesarray(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CPhotoDoc* pDoc=GetDocument();
	BOOL access=TRUE;
	CArray< CPtrArray, CPtrArray& >& imgA=pDoc->GetImgArray();
	if(imgA.GetSize()<=0)
		access=FALSE;

	if(access)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CPhotoView::OnImageSaveimagesarray() 
{
	// TODO: Add your command handler code here
	CPhotoDoc* pDoc=GetDocument();
	CArray< CPtrArray, CPtrArray& >& imgA=pDoc->GetImgArray();
	if(imgA.GetSize()<=0)
		return;
	CChooseNameDlg dlgChoose(this);
	if(dlgChoose.DoModal()==IDOK)
	{
		CString name,dir;
		dir=dlgChoose.GetDir();
		name=dlgChoose.GetName();
		CImageToolKit::WriteImagesArray(imgA,name,dir);
	}
}
