// ToggleBar.cpp : implementation file
//

#include "stdafx.h"
#include "Photo.h"
#include "ToggleBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToggleBar

CToggleBar::CToggleBar()
{
	m_nPaneID=0;
	m_bPaneOn=TRUE;
}

CToggleBar::~CToggleBar()
{
}


BEGIN_MESSAGE_MAP(CToggleBar, CStatusBar)
	//{{AFX_MSG_MAP(CToggleBar)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CToggleBar message handlers

void CToggleBar::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_nPaneID==0)
		return;

	CRect	rc;
	int		idx=0;
	ASSERT((idx=CommandToIndex(m_nPaneID))!=-1);
	GetItemRect(idx,&rc);
	
	if(rc.PtInRect(point))
		m_bPaneOn=!m_bPaneOn;

	CStatusBar::OnLButtonDown(nFlags, point);
}
