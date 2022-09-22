// QlhsDoc.cpp : implementation of the CQlhsDoc class
//

#include "stdafx.h"
#include "Qlhs.h"

#include "QlhsDoc.h"
#include "SrvrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQlhsDoc

IMPLEMENT_DYNCREATE(CQlhsDoc, COleServerDoc)

BEGIN_MESSAGE_MAP(CQlhsDoc, COleServerDoc)
	//{{AFX_MSG_MAP(CQlhsDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_SEND_MAIL, OnFileSendMail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, OnUpdateFileSendMail)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CQlhsDoc, COleServerDoc)
	//{{AFX_DISPATCH_MAP(CQlhsDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//      DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IQlhs to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {7921BDC4-9FAD-11D4-A3E4-B017BF6D810E}
static const IID IID_IQlhs =
{ 0x7921bdc4, 0x9fad, 0x11d4, { 0xa3, 0xe4, 0xb0, 0x17, 0xbf, 0x6d, 0x81, 0xe } };

BEGIN_INTERFACE_MAP(CQlhsDoc, COleServerDoc)
	INTERFACE_PART(CQlhsDoc, IID_IQlhs, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQlhsDoc construction/destruction

CQlhsDoc::CQlhsDoc()
{
	// Use OLE compound files
	EnableCompoundFile();

	// TODO: add one-time construction code here

	EnableAutomation();

	AfxOleLockApp();

	m_HocSinhUse=DBCLOSED;
	m_LopUse=DBCLOSED;
	m_MonHocUse=DBCLOSED;
	m_GiaoVienUse=DBCLOSED;

	m_KhoiLopUse=DBCLOSED;
	m_NienKhoaUse=DBCLOSED;
	m_HocKyUse=DBCLOSED;
	m_PhongUse=DBCLOSED;
	m_HinhThucKTUse=DBCLOSED;

}

CQlhsDoc::~CQlhsDoc()
{
	AfxOleUnlockApp();

	m_HocSinhSet.Close();
	m_LopSet.Close();
	m_MonHocSet.Close();
	m_GiaoVienSet.Close();

	m_KhoiLopSet.Close();
	m_NienKhoaSet.Close();
	m_HocKySet.Close();
	m_PhongSet.Close();
	m_HinhThucKTSet.Close();
}

BOOL CQlhsDoc::OnNewDocument()
{
	if (!COleServerDoc::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CQlhsDoc server implementation

COleServerItem* CQlhsDoc::OnGetEmbeddedItem()
{
	// OnGetEmbeddedItem is called by the framework to get the COleServerItem
	//  that is associated with the document.  It is only called when necessary.

	CQlhsSrvrItem* pItem = new CQlhsSrvrItem(this);
	ASSERT_VALID(pItem);
	return pItem;
}



/////////////////////////////////////////////////////////////////////////////
// CQlhsDoc serialization

void CQlhsDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CQlhsDoc diagnostics

#ifdef _DEBUG
void CQlhsDoc::AssertValid() const
{
	COleServerDoc::AssertValid();
}

void CQlhsDoc::Dump(CDumpContext& dc) const
{
	COleServerDoc::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CQlhsDoc commands
