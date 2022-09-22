// InfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Photo.h"
#include "InfoDlg.h"
#include "MSFlexGrid.h"
#include "Image.h"
#include "MainFrm.h"
#include "ChildFrm.h"
#include "PhotoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInfoDlg dialog


CInfoDlg::CInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInfoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInfoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CInfoDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInfoDlg message handlers

BOOL CInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CMSFlexGrid* pGrid;
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER Info;
	CMainFrame*		 pMainWnd;
	CChildFrame*	 pChildWnd;
	CPhotoDoc*		 pDoc;
	CImage*			 pImg;
	char s[256];

	pMainWnd=(CMainFrame*)AfxGetMainWnd();
	pChildWnd=(CChildFrame*)pMainWnd->MDIGetActive();
	pDoc=(CPhotoDoc*)pChildWnd->GetActiveDocument();
	pImg=(CImage*)pDoc->GetImage();
	if(!pImg->IsValid())
	{
		MessageBox("Error:Image is not load or invalid","Error",
					MB_OK|MB_ICONSTOP);
		return FALSE;
	}

					/***********************/
	pGrid=(CMSFlexGrid*)GetDlgItem(IDC_BITMAPFILEHEADER_MSFLEXGRID);
	if(!pImg->GetFileHeader(fileHeader))
	{
		MessageBox("Error: Not Read BITMAPFLEHEADER","Error",
					MB_OK|MB_ICONSTOP);
		return FALSE;
	}

	pGrid->SetFixedRows(1);
	pGrid->SetFixedCols(1);

	pGrid->SetRows(6);
	pGrid->SetCols(3);

	pGrid->SetColWidth(0,1400);
	pGrid->SetColWidth(1,1000);
	pGrid->SetColWidth(2,2000);

	pGrid->SetRow(0);
	pGrid->SetCol(0);pGrid->SetText("Field Name");
	pGrid->SetCol(1);pGrid->SetText("Size");
	pGrid->SetCol(2);pGrid->SetText("Value");

	pGrid->SetRow(1);
	pGrid->SetCol(0);pGrid->SetText("bfType");
	pGrid->SetCol(1);pGrid->SetText("WORD");
	pGrid->SetCol(2);pGrid->SetText(" BM");

	pGrid->SetRow(2);
	pGrid->SetCol(0);pGrid->SetText("bfSize");
	pGrid->SetCol(1);pGrid->SetText("DWORD");
	wsprintf(s," %lu bytes",fileHeader.bfSize);
	pGrid->SetCol(2);pGrid->SetText(s);

	pGrid->SetRow(3);
	pGrid->SetCol(0);pGrid->SetText("bfReserved1");
	pGrid->SetCol(1);pGrid->SetText("WORD");
	wsprintf(s," %u",fileHeader.bfReserved1);
	pGrid->SetCol(2);pGrid->SetText(s);

	pGrid->SetRow(4);
	pGrid->SetCol(0);pGrid->SetText("bfReserved2");
	pGrid->SetCol(1);pGrid->SetText("WORD");
	wsprintf(s," %u",fileHeader.bfReserved2);
	pGrid->SetCol(2);pGrid->SetText(s);

	pGrid->SetRow(5);
	pGrid->SetCol(0);pGrid->SetText("bfOffBits");
	pGrid->SetCol(1);pGrid->SetText("DWORD");
	wsprintf(s," %lu",fileHeader.bfOffBits);
	pGrid->SetCol(2);pGrid->SetText(s);

					/***********************/
	pGrid=(CMSFlexGrid*)GetDlgItem(IDC_BITMAPINFOHEADER_MSFLEXGRID);
	if(!pImg->GetInfo(&Info))
	{
		MessageBox("Error: Not Read BITMAPINFOHEADER","Error",
					MB_OK|MB_ICONSTOP);
		return FALSE;
	}

	pGrid->SetFixedRows(1);
	pGrid->SetFixedCols(1);

	pGrid->SetRows(12);
	pGrid->SetCols(3);

	pGrid->SetColWidth(0,1400);
	pGrid->SetColWidth(1,1000);
	pGrid->SetColWidth(2,2000);

	pGrid->SetRow(0);
	pGrid->SetCol(0);pGrid->SetText("Field Name");
	pGrid->SetCol(1);pGrid->SetText("Size");
	pGrid->SetCol(2);pGrid->SetText("Value");

	pGrid->SetRow(1);
	pGrid->SetCol(0);pGrid->SetText("biSize");
	pGrid->SetCol(1);pGrid->SetText("DWORD");
	wsprintf(s," %lu bytes",Info.biSize);
	pGrid->SetCol(2);pGrid->SetText(s);

	pGrid->SetRow(2);
	pGrid->SetCol(0);pGrid->SetText("biWidth");
	pGrid->SetCol(1);pGrid->SetText("LONG");
	wsprintf(s," %ld pixels",Info.biWidth);
	pGrid->SetCol(2);pGrid->SetText(s);

	pGrid->SetRow(3);
	pGrid->SetCol(0);pGrid->SetText("biHeight");
	pGrid->SetCol(1);pGrid->SetText("LONG");
	wsprintf(s," %ld pixels",Info.biHeight);
	pGrid->SetCol(2);pGrid->SetText(s);

	pGrid->SetRow(4);
	pGrid->SetCol(0);pGrid->SetText("biPlanes");
	pGrid->SetCol(1);pGrid->SetText("WORD");
	wsprintf(s," %u",Info.biPlanes);
	pGrid->SetCol(2);pGrid->SetText(s);

	pGrid->SetRow(5);
	pGrid->SetCol(0);pGrid->SetText("biBitCount");
	pGrid->SetCol(1);pGrid->SetText("WORD");
	wsprintf(s," %u bits",Info.biBitCount);
	pGrid->SetCol(2);pGrid->SetText(s);

	pGrid->SetRow(6);
	pGrid->SetCol(0);pGrid->SetText("biCompression");
	pGrid->SetCol(1);pGrid->SetText("DWORD");
	switch(Info.biCompression)
	{
		case BI_RGB:
			wsprintf(s," BI_RGB");
			break;
		case BI_RLE4:
			wsprintf(s," BI_RLE4");
			break;
		case BI_RLE8:
			wsprintf(s," BI_RLE8");
			break;
		default:
			wsprintf(s," UNKNOWED");
			break;
	}
	pGrid->SetCol(2);pGrid->SetText(s);

	pGrid->SetRow(7);
	pGrid->SetCol(0);pGrid->SetText("biSizeImage");
	pGrid->SetCol(1);pGrid->SetText("DWORD");
	wsprintf(s," %lu bytes",Info.biSizeImage);
	pGrid->SetCol(2);pGrid->SetText(s);

	pGrid->SetRow(8);
	pGrid->SetCol(0);pGrid->SetText("biXPelsPerMeter");
	pGrid->SetCol(1);pGrid->SetText("LONG");
	wsprintf(s," %ld DPI/m",Info.biXPelsPerMeter);
	pGrid->SetCol(2);pGrid->SetText(s);

	pGrid->SetRow(9);
	pGrid->SetCol(0);pGrid->SetText("biYPelsPerMeter");
	pGrid->SetCol(1);pGrid->SetText("LONG");
	wsprintf(s," %ld DPI/m",Info.biYPelsPerMeter);
	pGrid->SetCol(2);pGrid->SetText(s);

	pGrid->SetRow(10);
	pGrid->SetCol(0);pGrid->SetText("biClrUsed");
	pGrid->SetCol(1);pGrid->SetText("DWORD");
	wsprintf(s," %lu",Info.biClrUsed);
	pGrid->SetCol(2);pGrid->SetText(s);

	pGrid->SetRow(11);
	pGrid->SetCol(0);pGrid->SetText("biClrImportant");
	pGrid->SetCol(1);pGrid->SetText("DWORD");
	wsprintf(s," %lu",Info.biClrImportant);
	pGrid->SetCol(2);pGrid->SetText(s);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/////////////////////////////////////////////////////////////////////////////
// CInfoDlg message handlers
