// LogonDlg.cpp : implementation file
//

#include "stdafx.h"
#include "qlhs.h"
#include "LogonDlg.h"
#include "ProviderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogonDlg dialog


CLogonDlg::CLogonDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLogonDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogonDlg)
	m_szDataBase = _T("QLHS");
	m_szLoginName = _T("sa");
	m_szProgID = _T("SQLOLEDB.1");
	m_szServer = _T("");
	m_szPassword = _T("");
	//}}AFX_DATA_INIT
}


void CLogonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogonDlg)
	DDX_Text(pDX, IDC_DATABASE_EDIT, m_szDataBase);
	DDX_Text(pDX, IDC_LOGINNAME_EDIT, m_szLoginName);
	DDX_Text(pDX, IDC_PROGID_EDIT, m_szProgID);
	DDX_Text(pDX, IDC_SERVER_EDIT, m_szServer);
	DDX_Text(pDX, IDC_PASSWORD_EDIT, m_szPassword);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogonDlg, CDialog)
	//{{AFX_MSG_MAP(CLogonDlg)
	ON_EN_CHANGE(IDC_SERVER_EDIT, OnChangeServerEdit)
	ON_BN_CLICKED(IDC_SQL_RADIO, OnSqlRadio)
	ON_BN_CLICKED(IDC_WINNT_RADIO, OnWinntRadio)
	ON_BN_CLICKED(IDC_CHANGE_BUTTON, OnChangeButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogonDlg message handlers

BOOL CLogonDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CEdit*		pServerEdit=(CEdit*)GetDlgItem(IDC_SERVER_EDIT);
	CButton*	pSQLRadio=(CButton*)GetDlgItem(IDC_SQL_RADIO);
	CButton*	pOKButton=(CButton*)GetDlgItem(IDOK);

	pSQLRadio->SetCheck(1);
	pOKButton->EnableWindow(FALSE);
	pServerEdit->SetFocus();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLogonDlg::OnChangeServerEdit() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData();
	CButton*	pOKButton=(CButton*)GetDlgItem(IDOK);
	if(pOKButton->IsWindowEnabled())
	{
		if(m_szServer.IsEmpty())
			pOKButton->EnableWindow(FALSE);
	}
	else
	{
		if(!m_szServer.IsEmpty())
			pOKButton->EnableWindow(TRUE);
	}

}
void CLogonDlg::OnSqlRadio() 
{
	// TODO: Add your control notification handler code here
	CEdit*  pLoginEdit=(CEdit*)GetDlgItem(IDC_LOGINNAME_EDIT);
	CEdit*  pPasswordEdit=(CEdit*)GetDlgItem(IDC_PASSWORD_EDIT);
	if(!pLoginEdit->IsWindowEnabled())
		pLoginEdit->EnableWindow(TRUE);
	if(!pPasswordEdit->IsWindowEnabled())
		pPasswordEdit->EnableWindow(TRUE);
	
}

void CLogonDlg::OnWinntRadio() 
{
	// TODO: Add your control notification handler code here
	CEdit*  pLoginEdit=(CEdit*)GetDlgItem(IDC_LOGINNAME_EDIT);
	CEdit*  pPasswordEdit=(CEdit*)GetDlgItem(IDC_PASSWORD_EDIT);
	if(pLoginEdit->IsWindowEnabled())
		pLoginEdit->EnableWindow(FALSE);
	if(pPasswordEdit->IsWindowEnabled())
		pPasswordEdit->EnableWindow(FALSE);
}

void CLogonDlg::OnChangeButton() 
{
	// TODO: Add your control notification handler code here
	CProviderDlg	dlgProvider(this);
	if(dlgProvider.DoModal()==IDOK)
	{
		m_szProgID=dlgProvider.m_szProgID;
		UpdateData(FALSE);
	}
}
