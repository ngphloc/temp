// SrvrItem.h : interface of the CQlhsSrvrItem class
//

#if !defined(AFX_SRVRITEM_H__7921BDD3_9FAD_11D4_A3E4_B017BF6D810E__INCLUDED_)
#define AFX_SRVRITEM_H__7921BDD3_9FAD_11D4_A3E4_B017BF6D810E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CQlhsSrvrItem : public COleServerItem
{
	DECLARE_DYNAMIC(CQlhsSrvrItem)

// Constructors
public:
	CQlhsSrvrItem(CQlhsDoc* pContainerDoc);

// Attributes
	CQlhsDoc* GetDocument() const
		{ return (CQlhsDoc*)COleServerItem::GetDocument(); }

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQlhsSrvrItem)
	public:
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);
	//}}AFX_VIRTUAL

// Implementation
public:
	~CQlhsSrvrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SRVRITEM_H__7921BDD3_9FAD_11D4_A3E4_B017BF6D810E__INCLUDED_)
