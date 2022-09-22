// OperatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Photo.h"
#include "OperatorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COperatorDlg dialog


COperatorDlg::COperatorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COperatorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COperatorDlg)
	m_bReversed = FALSE;
	//}}AFX_DATA_INIT
}


void COperatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COperatorDlg)
	DDX_Check(pDX, IDC_REVERSED_CHECK, m_bReversed);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COperatorDlg, CDialog)
	//{{AFX_MSG_MAP(COperatorDlg)
	ON_BN_CLICKED(IDC_INTEGER_RADIO, OnIntergerRadio)
	ON_BN_CLICKED(IDC_FILE_RADIO, OnFileRadio)
	ON_BN_CLICKED(IDC_BROWSE_BUTTON, OnBrowseButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COperatorDlg message handlers

BOOL COperatorDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	m_szFilePath.Empty();
	m_bFlag=TRUE;
	
	SetWindowText((LPCTSTR)m_szNameDlg);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void COperatorDlg::OnIntergerRadio() 
{
	// TODO: Add your control notification handler code here
	CString	 szText;
	CEdit*   pEdit=(CEdit*)GetDlgItem(IDC_INTEGER_EDIT);
	CButton* pButton=(CButton*)GetDlgItem(IDC_BROWSE_BUTTON);
	CButton* pCheck=(CButton*)GetDlgItem(IDC_REVERSED_CHECK);

	pEdit->EnableWindow(TRUE);
	pEdit->SetFocus();
	pButton->EnableWindow(FALSE);
	pCheck->EnableWindow(TRUE);

	m_szFilePath.Empty();
	m_bFlag=TRUE;

	GetWindowText(szText);
	SetWindowText(szText+" Integer");
}

void COperatorDlg::OnFileRadio() 
{
	// TODO: Add your control notification handler code here
	CEdit*   pEdit=(CEdit*)GetDlgItem(IDC_INTEGER_EDIT);
	CButton* pButton=(CButton*)GetDlgItem(IDC_BROWSE_BUTTON);
	CButton* pCheck=(CButton*)GetDlgItem(IDC_REVERSED_CHECK);

	pEdit->SetWindowText("");
	pEdit->EnableWindow(FALSE);

	pButton->EnableWindow(TRUE);
	pButton->SetFocus();

	pCheck->EnableWindow(TRUE);

	m_dwValue=0;
	m_bFlag=FALSE;
}

void COperatorDlg::OnBrowseButton() 
{
	// TODO: Add your control notification handler code here
	static char BASED_CODE szFilter[] = "Image Files (*.bmp)|*.bmp||";
	CFileDialog dlgFile(TRUE,"bmp",NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
				szFilter,this);
		
	dlgFile.m_ofn.lpstrInitialDir="DATA";
	if(dlgFile.DoModal()==IDOK)
		m_szFilePath=dlgFile.GetPathName();
	else
		m_szFilePath.Empty();
}

void COperatorDlg::OnOK() 
{
	// TODO: Add extra validation here
	if(m_bFlag)
	{
		CString  szText;
		CEdit*   pEdit=(CEdit*)GetDlgItem(IDC_INTEGER_EDIT);
		pEdit->GetWindowText(szText);
		if(szText.IsEmpty())
		{
			MessageBox("Warning: Do not enter Edit Box","Warning",
						MB_OK|MB_ICONEXCLAMATION);
			pEdit->SetFocus();
			return;
		}
		m_dwValue=(DWORD)atoi((LPCTSTR)szText);
	}
	else if(m_szFilePath.IsEmpty())
	{
		MessageBox("Warning: Do not Open File","Warning",
					MB_OK|MB_ICONEXCLAMATION);
		CButton* pButton=(CButton*)GetDlgItem(IDC_BROWSE_BUTTON);
		pButton->SetFocus();
		return;
	}
	UpdateData(TRUE);//Cap nhat o check box
	CDialog::OnOK();
}
