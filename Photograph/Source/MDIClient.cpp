// MDIClient.cpp : implementation file
//

#include "stdafx.h"
#include "Photo.h"
#include "MDIClient.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMDIClient

IMPLEMENT_DYNCREATE(CMDIClient, CFrameWnd)

CMDIClient::CMDIClient()
{
	EnableAutomation();

	VERIFY(m_bmp.LoadBitmap(IDB_BKGRD_BITMAP));
}

CMDIClient::~CMDIClient()
{
}

void CMDIClient::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CFrameWnd::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CMDIClient, CFrameWnd)
	//{{AFX_MSG_MAP(CMDIClient)
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMDIClient, CFrameWnd)
	//{{AFX_DISPATCH_MAP(CMDIClient)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IMDIClient to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {FC88935B-76C9-11D4-A3E4-FDB243694D6A}
static const IID IID_IMDIClient =
{ 0xfc88935b, 0x76c9, 0x11d4, { 0xa3, 0xe4, 0xfd, 0xb2, 0x43, 0x69, 0x4d, 0x6a } };

BEGIN_INTERFACE_MAP(CMDIClient, CFrameWnd)
	INTERFACE_PART(CMDIClient, IID_IMDIClient, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMDIClient message handlers

BOOL CMDIClient::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default

	BITMAP		bm;
	int			nWidth,nHeight;
	CRect		rc;
	CBitmap*	pOldBitmap;
	CDC			memDC;
	VERIFY(m_bmp.GetObject(sizeof(BITMAP),&bm));

	memDC.CreateCompatibleDC(pDC);
	pOldBitmap=memDC.SelectObject(&m_bmp);

	GetClientRect(rc);
	nWidth=(rc.Width()<bm.bmWidth)?rc.Width():bm.bmWidth;
	nHeight=(rc.Height()<bm.bmHeight)?rc.Height():bm.bmHeight;
	BOOL ret=pDC->BitBlt((rc.Width()-nWidth)/2,(rc.Height()-nHeight)/2,
				nWidth,nHeight,
				&memDC,
				0,0,
				SRCCOPY);
	
	memDC.SelectObject(pOldBitmap);
	return ret;
}

void CMDIClient::OnSize(UINT nType, int cx, int cy) 
{
	CFrameWnd::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	RedrawWindow(NULL,NULL,RDW_INVALIDATE|RDW_ERASE|RDW_ERASENOW|RDW_ALLCHILDREN);
}


