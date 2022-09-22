// CutDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Photo.h"
#include "CutDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCutDlg dialog

CCutDlg::CCutDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCutDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCutDlg)
	m = 16;
	vm = 0;
	n = 16;
	vn = 0;
	//}}AFX_DATA_INIT
}


void CCutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCutDlg)
	DDX_Text(pDX, IDC_MEDIT, m);
	DDX_Text(pDX, IDC_MVIEWEDIT, vm);
	DDX_Text(pDX, IDC_NEDIT, n);
	DDX_Text(pDX, IDC_NVIEWEDIT, vn);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCutDlg, CDialog)
	//{{AFX_MSG_MAP(CCutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCutDlg message handlers


