// ProviderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "qlhs.h"
#include "ProviderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProviderDlg dialog


CProviderDlg::CProviderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProviderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProviderDlg)
	m_szProgID = _T("");
	//}}AFX_DATA_INIT
}


void CProviderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProviderDlg)
	DDX_Text(pDX, IDC_PROVIDER_EDIT, m_szProgID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProviderDlg, CDialog)
	//{{AFX_MSG_MAP(CProviderDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProviderDlg message handlers

void CProviderDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_szProgID.IsEmpty())
	{
		MessageBox("Error! You didn't enter Provider ID","Error",MB_OK|MB_ICONSTOP);
		return;
	}
	CDialog::OnOK();
}
