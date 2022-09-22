// Image.h: interface for the CImage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGE_H__FC889357_76C9_11D4_A3E4_FDB243694D6A__INCLUDED_)
#define AFX_IMAGE_H__FC889357_76C9_11D4_A3E4_FDB243694D6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LIB\\vfw.h"
#pragma comment(lib,"LIB\\vfw32.lib")

#define	HISTOGRAM_MONO		1
#define	HISTOGRAM_4BITS		2
#define	HISTOGRAM_8BITS		4
#define	HISTOGRAM_16BITS	8
#define	HISTOGRAM_24BITS	16
#define	HISTOGRAM_32BITS	32

#define	BOUNDARY_STACK		1
#define	CENTER_STACK		2

#define	LEFTTOP				1
#define	RIGHTTOP			2
#define	LEFTBOTTOM			3
#define	RIGHTBOTTOM			4

typedef	DWORD	HISTOGRAM;
typedef	LPDWORD	LPHISTOGRAM;

class CImageToolKit;
class CImage : public CObject  
{
public:
	typedef struct	tagIMGINFO
	{
		BITMAPFILEHEADER	bmpFileHeader;
		BITMAPINFO*			bmpInfo;
		DWORD				bmpBytesPerScanLine;
		DWORD				bmpColors;
	} IMGINFO;
protected:
	IMGINFO		m_info;

	CPoint		m_ptOrg;

	HGLOBAL		hBuf;
	DWORD		dwBufLength;
public:
	CImage();
	CImage(CImage& Img);
	virtual ~CImage();
	virtual void Serialize(CArchive& ar);

//Essential Methodes
protected:
	WORD	RGB16(BYTE r,BYTE g,BYTE b)
	{ 
		return (((WORD)(UINT)(((int)(UINT)(r) >> 3) << 10)| 
							 (((int)(UINT)(g) >> 3) << 5)| 
							 (((int)(UINT)(b) >> 3) << 0))); 
	}

public:
	BOOL	Delete();
	BOOL	IsValid();
	BOOL	IsFit(CImage& Img);

	DWORD	FindArea(CPoint pt);
	DWORD	FindArea(DWORD x, DWORD y);

	BOOL	LoadFromFile(CString szFilePath);
	BOOL	WriteToFile(CString szFilePath);

	BOOL	GetInfo(BITMAPINFOHEADER* pInfo);
	BOOL	GetFileHeader(BITMAPFILEHEADER& fileHeader);
	DWORD	GetPalette(CPalette* pPal);
	DWORD	GetBits(LPBYTE  lpBits,DWORD dwCount=0,DWORD dwReverse=FALSE);
	DWORD	SetBits(const LPBYTE lpBits,DWORD dwCount=0,DWORD dwReverse=FALSE);
	CPoint  GetPtOrg();
	DWORD	GetPixel(CPoint pt);
	DWORD	GetPixel(int x, int y);
	DWORD	GetPixel(int num);
	LONG	GetWidth();
	LONG	GetHeight();

	CPoint  SetPtOrg(CPoint ptOrg);
	CPoint  SetPtOrg(int x,int y);
	CPoint  SetPtOrgCenter();
	CPoint  SetPtOrgLeftTop();
	CPoint  SetPtOrgLeftBottom();
	CPoint  SetPtOrgRightBottom();
	CPoint  SetPtOrgRightTop();
	DWORD	SetSize(LONG  Width, LONG Height, BOOL blank=FALSE);//Width,Height:Pixel
	BOOL	SetInfo(CImage* pImg);
	BOOL	SetImage(CImage* pImg);
	BOOL	SetPixel(CPoint pt, DWORD value);
	BOOL	SetPixel(int x, int y, DWORD value);
	BOOL	SetPixel(int num, DWORD value);
	void	Blank();

	BOOL	Draw(CDC* pDC,
				 CPoint dstPoint=CPoint(0,0),CSize dstSize=CSize(0,0),
				 CPoint srcOffset=CPoint(0,0),CSize srcSize=CSize(0,0),
				 DWORD dwFlags=SRCCOPY);

	BOOL	DrawEnhanced(CDC* pDC,
				 CPoint dstPoint=CPoint(0,0),CSize dstSize=CSize(0,0),
				 CPoint srcOffset=CPoint(0,0),CSize srcSize=CSize(0,0),
				 DWORD dwFlags=DDF_BACKGROUNDPAL);
	

	BOOL	ConvertToGrayScale();
//Operator:
public:
	CImage&		  operator =  (CImage& Img);

	CImage		  operator +  (DWORD k);
	friend CImage operator +  (DWORD k,CImage& Img);
	CImage        operator +  (CImage& Img);
	CImage&		  operator += (DWORD k);
	CImage&       operator += (CImage& Img);

	CImage		  operator -  (DWORD k);
	friend CImage operator -  (DWORD k,CImage& Img);
	CImage        operator -  (CImage& Img);
	CImage&		  operator -= (DWORD k);
	CImage&       operator -= (CImage& Img);

	CImage		  operator *  (DWORD k);
	friend CImage operator *  (DWORD k,CImage& Img);
	CImage        operator *  (CImage& Img);
	CImage&		  operator *= (DWORD k);
	CImage&       operator *= (CImage& Img);

	CImage		  operator /  (DWORD k);
	friend CImage operator /  (DWORD k,CImage& Img);
	CImage        operator /  (CImage& Img);
	CImage&		  operator /=  (DWORD k);
	CImage&       operator /= (CImage& Img);

	CImage&		  operator ~  ();

	CImage		  operator &  (DWORD k);
	friend CImage operator &  (DWORD k,CImage& Img);
	CImage        operator &  (CImage& Img);
	CImage&		  operator &= (DWORD k);
	CImage&       operator &= (CImage& Img);

	CImage		  operator |  (DWORD k);
	friend CImage operator |  (DWORD k,CImage& Img);
	CImage        operator |  (CImage& Img);
	CImage&		  operator |= (DWORD k);
	CImage&       operator |= (CImage& Img);

	CImage		  operator ^  (DWORD k);
	friend CImage operator ^  (DWORD k,CImage& Img);
	CImage        operator ^  (CImage& Img);
	CImage&		  operator ^= (DWORD k);
	CImage&       operator ^= (CImage& Img);

	friend CImage Min(CImage& Img,DWORD k);
	friend CImage Min(CImage& Img1,CImage& Img2);
	friend CImage Max(CImage& Img,DWORD k);
	friend CImage Max(CImage& Img1,CImage& Img2);
	friend CImage Abs(CImage& Img,DWORD k);
	friend CImage Abs(CImage& Img1,CImage& Img2);

//Scale
public:
	void	Scale(DWORD Width,DWORD Height);
//Table Look up 
	BOOL	LookupTable(const LPDWORD Lut);

//Histogram:
	DWORD	Histogram(LPHISTOGRAM& Hist);
	BOOL	HistEq();

//Tich chap
	BOOL	Tichchap(LPINT* H, INT w, DWORD Flag=CENTER_STACK);

//Filter
	BOOL	CImage::LinearFilter(LPINT* H, INT w, INT Div=0, INT startRow=0, INT startCol=0,
							 INT nWidth=0, INT nHeight=0);
	BOOL	MediumSoften();
	BOOL	AlotSoften();
	BOOL	LowSharpen();
	BOOL	MediumSharpen();
	BOOL	DiagonalShatter();
	BOOL	HorizontalBlur();
	BOOL	FireFilter();

	friend  CImageToolKit;
};

#endif // !defined(AFX_IMAGE_H__FC889357_76C9_11D4_A3E4_FDB243694D6A__INCLUDED_)
