// HistView.cpp : implementation file
//

#include "stdafx.h"
#include "Photo.h"
#include "HistView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHistView

IMPLEMENT_DYNCREATE(CHistView, CScrollView)

CHistView::CHistView()
{
}

CHistView::~CHistView()
{
}


BEGIN_MESSAGE_MAP(CHistView, CScrollView)
	//{{AFX_MSG_MAP(CHistView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHistView drawing

void CHistView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CHistView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CHistView diagnostics

#ifdef _DEBUG
void CHistView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CHistView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHistView message handlers
