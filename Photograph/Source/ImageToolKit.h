// ImageToolKit.h: interface for the CImageToolKit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGETOOLKIT_H__D4B4C84F_98FC_4A6E_B101_F08B9CC9B8CB__INCLUDED_)
#define AFX_IMAGETOOLKIT_H__D4B4C84F_98FC_4A6E_B101_F08B9CC9B8CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "Image.h"
#include "Afxtempl.h"

class CImageToolKit : public CObject  
{
public:
	CImageToolKit();
	virtual ~CImageToolKit();

	static BOOL	CombineTwoImages(CImage& Img1, CImage& Img2, CImage& RetImg, float ratio1=1,float ratio2=0, BOOL check=FALSE);

	static BOOL CutImages(CImage* pImg, LONG *pHeight, UINT m, LONG* pWidth, UINT n, 
		CArray< CPtrArray, CPtrArray& >& imgA);
	static BOOL CutImages(CImage* pImg, UINT m, UINT n, 
		CArray< CPtrArray, CPtrArray& >& imgA);

	static BOOL CatImages(CArray< CPtrArray, CPtrArray& >& imgA, CImage* pImg);

	//x,y la toa do nam tren manh imgA[i][j]
	static BOOL Find4Neighbour(CArray< CPtrArray, CPtrArray& >& imgA,
		DWORD i, DWORD j, DWORD x, DWORD y, CImage* pImg, CPoint* pImgPos);
	static BOOL WriteImagesArray(CArray< CPtrArray, CPtrArray& >& imgA, CString name, CString dir, CString type="bmp");
	
};

#endif // !defined(AFX_IMAGETOOLKIT_H__D4B4C84F_98FC_4A6E_B101_F08B9CC9B8CB__INCLUDED_)
