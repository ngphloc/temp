// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Photo.h"

#include "PhotoDoc.h"
#include "MainFrm.h"
#include "ChildFrm.h"
#include "Splash.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define		ID_STATUSTIME_TIMER		1000

/////////////////////////////////////////////////////////////////////////////
// CMainFrame
extern "C" {
	void CALLBACK TimerClockProc(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime);
}


IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_INITMENU()
	ON_WM_DESTROY()
	ON_WM_PALETTECHANGED()
	ON_WM_MENUSELECT()
	ON_UPDATE_COMMAND_UI(ID_VIEW_OPERATOR_TOOLBAR, OnUpdateViewOperatorToolbar)
	ON_COMMAND(ID_VIEW_OPERATOR_TOOLBAR, OnViewOperatorToolbar)
	//}}AFX_MSG_MAP
	// Global help commands
	ON_COMMAND(ID_HELP_FINDER, CMDIFrameWnd::OnHelpFinder)
	ON_COMMAND(ID_HELP, CMDIFrameWnd::OnHelp)
	ON_COMMAND(ID_CONTEXT_HELP, CMDIFrameWnd::OnContextHelp)
	ON_COMMAND(ID_DEFAULT_HELP, CMDIFrameWnd::OnHelpFinder)
	//Indicator commands
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_CLOCK, OnUpdateIndicatorTime)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
	ID_INDICATOR_CLOCK
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	m_szTimeFormat="HH:mm:ss tt";
	m_szDateFormat="ddd,MMM yyyy";
	m_wndStatusBar.m_nPaneID=ID_INDICATOR_CLOCK;

	m_nIDStatusTime=0;
	m_bOperatorBar=FALSE;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
		
	if(!m_MDIClient.SubclassWindow(m_hWndMDIClient))
	{
		TRACE0("Failed to Subclass MDI Client Window\n");
		return -1;      // fail to create
	}
	
	if (!m_wndToolBar.CreateEx(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	/*	
	if (!m_wndDlgBar.Create(this, IDR_MAINFRAME, 
		CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR))
	{
		TRACE0("Failed to create dialogbar\n");
		return -1;		// fail to create
	}
	*/

	if (!m_wndReBar.Create(this) ||
		!m_wndReBar.AddBar(&m_wndToolBar)/*||
		!m_wndReBar.AddBar(&m_wndDlgBar)*/)
	{
		TRACE0("Failed to create rebar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Remove this if you don't want tool tips
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);

//My Status Bar
	m_nIDStatusTime=m_wndStatusBar.SetTimer(ID_STATUSTIME_TIMER,1000,
												&TimerClockProc);

//My Toolbars
	if (!m_wndOperatorToolBar.CreateEx(this) ||
		!m_wndOperatorToolBar.LoadToolBar(IDR_OPERATOR_TOOLBAR))
	{
		TRACE0("Failed to create operastor toolbar\n");
		return -1;      // fail to create
	}
	m_wndOperatorToolBar.SetBarStyle(m_wndOperatorToolBar.GetBarStyle() |
		CBRS_ALIGN_LEFT | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);
	m_wndOperatorToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndOperatorToolBar,AFX_IDW_DOCKBAR_LEFT);
	ShowControlBar(&m_wndOperatorToolBar,FALSE,TRUE);

	// CG: The following line was added by the Splash Screen component.
	CSplashWnd::ShowSplashScreen(this);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnInitMenu(CMenu* pMenu)
{
   CMDIFrameWnd::OnInitMenu(pMenu);
  
	// CG: This block added by 'Tip of the Day' component.
	{
		// TODO: This code adds the "Tip of the Day" menu item
		// on the fly.  It may be removed after adding the menu
		// item to all applicable menu items using the resource
		// editor.

		// Add Tip of the Day menu item on the fly!
		static CMenu* pSubMenu = NULL;

		CString strHelp; strHelp.LoadString(CG_IDS_TIPOFTHEDAYHELP);
		CString strMenu;
		int nMenuCount = pMenu->GetMenuItemCount();
		BOOL bFound = FALSE;
		for (int i=0; i < nMenuCount; i++) 
		{
			pMenu->GetMenuString(i, strMenu, MF_BYPOSITION);
			if (strMenu == strHelp)
			{ 
				pSubMenu = pMenu->GetSubMenu(i);
				bFound = TRUE;
				ASSERT(pSubMenu != NULL);
			}
		}

		CString strTipMenu;
		strTipMenu.LoadString(CG_IDS_TIPOFTHEDAYMENU);
		if (!bFound)
		{
			// Help menu is not available. Please add it!
			if (pSubMenu == NULL) 
			{
				// The same pop-up menu is shared between mainfrm and frame 
				// with the doc.
				static CMenu popUpMenu;
				pSubMenu = &popUpMenu;
				pSubMenu->CreatePopupMenu();
				pSubMenu->InsertMenu(0, MF_STRING|MF_BYPOSITION, 
					CG_IDS_TIPOFTHEDAY, strTipMenu);
			} 
			pMenu->AppendMenu(MF_STRING|MF_BYPOSITION|MF_ENABLED|MF_POPUP, 
				(UINT)pSubMenu->m_hMenu, strHelp);
			DrawMenuBar();
		} 
		else
		{      
			// Check to see if the Tip of the Day menu has already been added.
			pSubMenu->GetMenuString(0, strMenu, MF_BYPOSITION);

			if (strMenu != strTipMenu) 
			{
				// Tip of the Day submenu has not been added to the 
				// first position, so add it.
				pSubMenu->InsertMenu(0, MF_BYPOSITION);  // Separator
				pSubMenu->InsertMenu(0, MF_STRING|MF_BYPOSITION, 
					CG_IDS_TIPOFTHEDAY, strTipMenu);
			}
		}
	}

	HICON	hIcon=AfxGetApp()->LoadIcon(IDI_PICTURE_ICON);
	AfxGetMainWnd()->SendMessage(WM_SETICON,ICON_SMALL,(LPARAM)hIcon);
}

void CMainFrame::OnPaletteChanged(CWnd* pFocusWnd) 
{
	// TODO: Add your message handler code here
	SendMessageToDescendants(WM_PALETTECHANGED,(WPARAM)(pFocusWnd->GetSafeHwnd()));

	CMDIFrameWnd::OnPaletteChanged(pFocusWnd);
}

void CALLBACK EXPORT TimerClockProc(HWND hWnd, 
									UINT nMsg, 
									UINT nIDEvent, 
									DWORD dwTime)
{
	AfxGetApp()->OnIdle(0);
}

void CMainFrame::OnUpdateIndicatorTime(CCmdUI* pCmdUI)
{
	TCHAR	buf[256];
	LCID	lcid=GetUserDefaultLCID();

	if(m_wndStatusBar.m_bPaneOn)
		VERIFY(GetTimeFormat(lcid,0,NULL,m_szTimeFormat,buf,256));
	else
		VERIFY(GetDateFormat(lcid,0,NULL,m_szDateFormat,buf,256));

	UINT	nID,nStyle;
	int		cxWidth,nIndex=m_wndStatusBar.CommandToIndex(ID_INDICATOR_CLOCK);

	CClientDC dc(this);
	CFont*	pOldFont=dc.SelectObject(m_wndStatusBar.GetFont());
	CSize	szExtent=dc.GetTextExtent(buf,lstrlen(buf));
	dc.SelectObject(pOldFont);

	m_wndStatusBar.GetPaneInfo(nIndex,nID,nStyle,cxWidth);
	m_wndStatusBar.SetPaneInfo(nIndex,nID,nStyle,szExtent.cx);
	m_wndStatusBar.SetPaneText(nIndex,buf);	

	pCmdUI->Enable();
}
void CMainFrame::OnDestroy() 
{
	CMDIFrameWnd::OnDestroy();
	
	// TODO: Add your message handler code here
	m_MDIClient.UnsubclassWindow();
}



void CMainFrame::OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu) 
{
	CMDIFrameWnd::OnMenuSelect(nItemID, nFlags, hSysMenu);
	
	// TODO: Add your message handler code here
	if(nFlags==0xFFFF && hSysMenu==NULL)
	{
		HICON	hIcon=AfxGetApp()->LoadIcon(IDR_MAINFRAME);
		AfxGetMainWnd()->SendMessage(WM_SETICON,ICON_SMALL,(LPARAM)hIcon);
	}
}


void CMainFrame::OnUpdateViewOperatorToolbar(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_bOperatorBar)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
	
}

void CMainFrame::OnViewOperatorToolbar() 
{
	// TODO: Add your command handler code here
	if(!m_bOperatorBar)
	{
		DockControlBar(&m_wndOperatorToolBar);
		ShowControlBar(&m_wndOperatorToolBar,TRUE,FALSE);
	}
	else
		ShowControlBar(&m_wndOperatorToolBar,FALSE,TRUE);
	m_bOperatorBar=!m_bOperatorBar;
}


