// ChooseNameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Photo.h"
#include "ChooseNameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChooseNameDlg dialog


CChooseNameDlg::CChooseNameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChooseNameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChooseNameDlg)
	m_Name = _T("");
	m_Dir = _T("");
	//}}AFX_DATA_INIT
}


void CChooseNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChooseNameDlg)
	DDX_Text(pDX, IDC_NAME, m_Name);
	DDX_Text(pDX, IDC_DIR, m_Dir);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChooseNameDlg, CDialog)
	//{{AFX_MSG_MAP(CChooseNameDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChooseNameDlg message handlers

CString CChooseNameDlg::GetName()
{
	return m_Name;
}

CString CChooseNameDlg::GetDir()
{
	return m_Dir;
}
