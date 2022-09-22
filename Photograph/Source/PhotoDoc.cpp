// PhotoDoc.cpp : implementation of the CPhotoDoc class
//

#include "stdafx.h"
#include "Photo.h"

#include "PhotoDoc.h"
#include "MainFrm.h"
#include "ChildFrm.h"
#include "Image.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPhotoDoc

IMPLEMENT_DYNCREATE(CPhotoDoc, CDocument)

BEGIN_MESSAGE_MAP(CPhotoDoc, CDocument)
	//{{AFX_MSG_MAP(CPhotoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_SEND_MAIL, OnFileSendMail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, OnUpdateFileSendMail)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CPhotoDoc, CDocument)
	//{{AFX_DISPATCH_MAP(CPhotoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//      DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IPhoto to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {FC88931B-76C9-11D4-A3E4-FDB243694D6A}
static const IID IID_IPhoto =
{ 0xfc88931b, 0x76c9, 0x11d4, { 0xa3, 0xe4, 0xfd, 0xb2, 0x43, 0x69, 0x4d, 0x6a } };

BEGIN_INTERFACE_MAP(CPhotoDoc, CDocument)
	INTERFACE_PART(CPhotoDoc, IID_IPhoto, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPhotoDoc construction/destruction

CPhotoDoc::CPhotoDoc()
{
	// TODO: add one-time construction code here

	EnableAutomation();

	AfxOleLockApp();

	m_pImage=new CImage;
	m_pos4NeighbourImage=CPoint(0,0);
	m_ImgA.SetSize(0);
}

CPhotoDoc::~CPhotoDoc()
{
	AfxOleUnlockApp();

	if(m_pImage!=NULL)
		delete m_pImage;
	DeleteImgArray();
}

BOOL CPhotoDoc::OnNewDocument()
{
	if(!((CPhotoApp*)AfxGetApp())->m_bFirstRun)
	{
		((CPhotoApp*)AfxGetApp())->m_bFirstRun=TRUE;
		return FALSE;
	}

	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	m_pImage->Delete();

	if(!m_pImage->IsValid())
	{
		MessageBox(NULL,"Warning : Not image File or invalid","Warning",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;
	}
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPhotoDoc serialization

void CPhotoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}

	m_pImage->Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CPhotoDoc diagnostics

#ifdef _DEBUG
void CPhotoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPhotoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPhotoDoc commands

BOOL CPhotoDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	if(!m_pImage->IsValid())
	{
		MessageBox(NULL,"Warning : Not image File or invalid","Warning",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;
	}
	UpdateAllViews(NULL);
	return TRUE;
}

BOOL CPhotoDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDocument::OnSaveDocument(lpszPathName);
}

void CPhotoDoc::DeleteImgArray()
{
	
	int m,n;
	int i,j;
	m=m_ImgA.GetSize();
	if(m>0)
	{
		for(i=0;i<m;i++)
		{
			n=m_ImgA[i].GetSize();
			if(n>0)
			{
				for(j=0;j<n;j++)
					((CImage*)(m_ImgA[i][j]))->Delete();
				m_ImgA[i].SetSize(0);
			}
		}
	}
	m_ImgA.SetSize(0);

}
BOOL CPhotoDoc::IsImageArrayValid()
{
	int m,n;
	int i,j;
	m=m_ImgA.GetSize();
	if(m<=0)
		return FALSE;
	if(m>0)
	{
		for(i=0;i<m;i++)
		{
			n=m_ImgA[i].GetSize();
			if(n<=0)
				return FALSE;
			for(j=0;j<n;j++)
				if( !((CImage*)(m_ImgA[i][j]))->IsValid() )
					return FALSE;
		}
	}
	return TRUE;
}
