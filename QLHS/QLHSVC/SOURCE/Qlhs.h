// Qlhs.h : main header file for the QLHS application
//

#if !defined(AFX_QLHS_H__7921BDC7_9FAD_11D4_A3E4_B017BF6D810E__INCLUDED_)
#define AFX_QLHS_H__7921BDC7_9FAD_11D4_A3E4_B017BF6D810E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "Qlhs_i.h"

/////////////////////////////////////////////////////////////////////////////
// CQlhsApp:
// See Qlhs.cpp for the implementation of this class
//

class CQlhsApp : public CWinApp
{
public:
	CQlhsApp();

//Attributes:
	CString	m_szDataBase;
	CString	m_szLoginName;
	CString	m_szPassword;
	CString	m_szProgID;
	CString	m_szServer;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQlhsApp)
	public:
	virtual BOOL InitInstance();
		virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	COleTemplateServer m_server;
		// Server object for document creation
	//{{AFX_MSG(CQlhsApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bATLInited;
private:
	BOOL InitATL();

	int ShowLogonAtStartup();
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QLHS_H__7921BDC7_9FAD_11D4_A3E4_B017BF6D810E__INCLUDED_)
