// PhotoDoc.h : interface of the CPhotoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PHOTODOC_H__FC889327_76C9_11D4_A3E4_FDB243694D6A__INCLUDED_)
#define AFX_PHOTODOC_H__FC889327_76C9_11D4_A3E4_FDB243694D6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Image.h"
#include "Afxtempl.h"

class CPhotoDoc : public CDocument
{
protected: // create from serialization only
	CPhotoDoc();
	DECLARE_DYNCREATE(CPhotoDoc)

// Attributes
protected:
	CImage*		m_pImage;
	CPoint		m_pos4NeighbourImage;
	CArray< CPtrArray, CPtrArray& > m_ImgA;



public:
	CImage*		GetImage()
		{ return m_pImage;}
	CArray< CPtrArray, CPtrArray& >& GetImgArray()
		{ return m_ImgA;}
	CPoint*		GetImagePos()
		{ return &m_pos4NeighbourImage;}
	BOOL	IsImageArrayValid();
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPhotoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	void DeleteImgArray();
	virtual ~CPhotoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPhotoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CPhotoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PHOTODOC_H__FC889327_76C9_11D4_A3E4_FDB243694D6A__INCLUDED_)
