// Image.cpp: implementation of the CImage class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Photo.h"
#include "Image.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#define Round(x)	(x+0.5)

CImage::CImage()
{
	memset((IMGINFO*)&m_info,0,sizeof(IMGINFO));
	m_ptOrg=CPoint(0,0);
	dwBufLength=0;
	hBuf=NULL;
}

CImage::CImage(CImage& Img)
{
	memset((IMGINFO*)&m_info,0,sizeof(IMGINFO));
	m_ptOrg=CPoint(0,0);
	dwBufLength=0;
	hBuf=NULL;
	SetImage(&Img);
}
CImage::~CImage()
{
	Delete();
}

void	CImage::Serialize(CArchive& ar)
{
	DWORD	n=sizeof(BITMAPFILEHEADER);
	LPBYTE	lpBuf;
	DWORD	dwCount=0,cl=0/*,WidthBytes*/;
	CString szFilePath;
	DWORD	bits=0;
	int		inc=1;
	DWORD	OldBytesPerScanLine=0;
	DWORD	pad=0;   //pad la so byte can them vao
	BYTE    extra=0;//pad la so byte can them vao

	if(ar.IsLoading())
	{
		if(ar.Read(&m_info.bmpFileHeader,n) !=n)
			goto errorLoad;
		if(m_info.bmpFileHeader.bfType!=0x4D42)
			goto errorLoad;
	
		if(m_info.bmpInfo!=NULL)
		{
			delete m_info.bmpInfo;
			m_info.bmpInfo=NULL;
		}
		n=m_info.bmpFileHeader.bfOffBits-n;
		if((m_info.bmpInfo=(BITMAPINFO*)new BYTE[n])==NULL)
			goto errorLoad;
		if(ar.Read(m_info.bmpInfo,n)!=n)
			goto errorLoad;
		switch(m_info.bmpInfo->bmiHeader.biCompression)
		{
			case BI_RGB:
				break;
			case BI_BITFIELDS:
				break;
			case BI_RLE8:
				goto errorLoad;
			case BI_RLE4:
				goto errorLoad;
			default:
				goto errorLoad;
		}
		bits=m_info.bmpInfo->bmiHeader.biBitCount;
		m_info.bmpBytesPerScanLine=m_info.bmpInfo->bmiHeader.biWidth*bits/8;		
		dwBufLength=m_info.bmpBytesPerScanLine*abs(m_info.bmpInfo->bmiHeader.\
													biHeight);

		m_info.bmpColors=(m_info.bmpFileHeader.bfOffBits-sizeof(BITMAPFILEHEADER)
				-sizeof(BITMAPINFOHEADER))/sizeof(PALETTEENTRY);
		
		//hieu chinh lai bien m_info.bmpInfo->bmiHeader.biSizeImage
		if(m_info.bmpInfo->bmiHeader.biSizeImage==0)
			m_info.bmpInfo->bmiHeader.biSizeImage=dwBufLength;
	
		OldBytesPerScanLine=m_info.bmpBytesPerScanLine;
		if(OldBytesPerScanLine%4!=0)
		{	
			DWORD widthBytes;
			if(bits!=24)
				widthBytes=(OldBytesPerScanLine/4)*4+4;
			else
				widthBytes=(OldBytesPerScanLine/12)*12+12;
			m_info.bmpInfo->bmiHeader.biWidth=widthBytes/(bits/8);

			m_info.bmpBytesPerScanLine=widthBytes;
			dwBufLength=widthBytes * abs(m_info.bmpInfo->bmiHeader.biHeight);
			m_info.bmpFileHeader.bfSize=dwBufLength+m_info.bmpFileHeader.bfOffBits;
			m_info.bmpInfo->bmiHeader.biSizeImage=dwBufLength;

		}

		if(hBuf==NULL)
			hBuf=GlobalAlloc(GMEM_MOVEABLE|GMEM_ZEROINIT,dwBufLength);
		else
			GlobalReAlloc(hBuf,dwBufLength,GMEM_MOVEABLE|GMEM_ZEROINIT);
		if(!IsValid())
			goto errorLoad;
		if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
			goto errorLoad;

		cl=(DWORD)abs(m_info.bmpInfo->bmiHeader.biHeight);
		if(cl==0)
			goto errorLoad;
		if(m_info.bmpInfo->bmiHeader.biHeight>0)
		{
			lpBuf+=(cl-1)*m_info.bmpBytesPerScanLine;
			inc=-1;
		}
		else
			inc=1;
		do
		{
			n=ar.Read(lpBuf,OldBytesPerScanLine);
			if(n!=OldBytesPerScanLine)
			{
				GlobalUnlock(hBuf);
				goto errorLoad;
			}
			lpBuf +=inc*(int)(m_info.bmpBytesPerScanLine);
			dwCount++;
		} while(dwCount<cl);

		m_ptOrg=CPoint(0,0);
		GlobalUnlock(hBuf);
		return;

	errorLoad:
		Delete();
		return;	
	}
	else
	{
		pad=0;//pad la so byte can them vao
		extra=0;
		DWORD	OldLength, OldWidth, OldSize;
		bits=m_info.bmpInfo->bmiHeader.biBitCount;

		switch(m_info.bmpInfo->bmiHeader.biCompression)
		{
			case BI_RGB:
				break;
			case BI_BITFIELDS:
				break;
			case BI_RLE8:
				goto errorWrite;
			case BI_RLE4:
				goto errorWrite;
			default:
				goto errorWrite;
		}

		OldBytesPerScanLine=m_info.bmpBytesPerScanLine;
		OldLength=dwBufLength;
		OldWidth=m_info.bmpInfo->bmiHeader.biWidth;
		OldSize=m_info.bmpFileHeader.bfSize;


		if(OldBytesPerScanLine%4!=0)
		{
			DWORD widthBytes;
			if(bits!=24)
				widthBytes=(OldBytesPerScanLine/4)*4+4;
			else
				widthBytes=(OldBytesPerScanLine/12)*12+12;
			m_info.bmpInfo->bmiHeader.biWidth=widthBytes/(bits/8);

			m_info.bmpBytesPerScanLine=widthBytes;
			dwBufLength=widthBytes * abs(m_info.bmpInfo->bmiHeader.biHeight);
			m_info.bmpFileHeader.bfSize=dwBufLength+m_info.bmpFileHeader.bfOffBits;
			pad=widthBytes-OldBytesPerScanLine;
		}
		if(!IsValid())
			goto errorWrite;

		if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
			goto errorWrite;

		ar.Write(&m_info.bmpFileHeader,n);
		if(m_info.bmpInfo==NULL)
			goto errorWrite;
		
		if(m_info.bmpInfo->bmiHeader.biCompression==BI_RGB)
			m_info.bmpInfo->bmiHeader.biSizeImage=0;
		n=m_info.bmpFileHeader.bfOffBits-n;
		ar.Write(m_info.bmpInfo,n);

		cl=(DWORD)abs(m_info.bmpInfo->bmiHeader.biHeight);
		if(cl==0)
			goto errorWrite;
		if(m_info.bmpInfo->bmiHeader.biHeight>0)
		{
			lpBuf+=(cl-1)*m_info.bmpBytesPerScanLine;
			inc=-1;
		}
		else
			inc=1;
		do
		{
			ar.Write(lpBuf,OldBytesPerScanLine);
			for(DWORD i=0;i<pad;i++)
				ar.Write(&extra,1);
			lpBuf+=inc*(int)OldBytesPerScanLine;
			dwCount++;
		} while(dwCount<cl);

		GlobalUnlock(hBuf);
		m_info.bmpBytesPerScanLine=OldBytesPerScanLine;
		dwBufLength=OldLength;
		m_info.bmpInfo->bmiHeader.biWidth=OldWidth;
		m_info.bmpFileHeader.bfSize=OldSize;
		return;

	errorWrite:
		m_info.bmpInfo->bmiHeader.biSizeImage=dwBufLength;
		szFilePath=ar.GetFile()->GetFilePath();
		ar.Close();
		CFile::Remove((LPCTSTR)szFilePath);
	}
}

BOOL	CImage::LoadFromFile(CString szFilePath)
{
	DWORD	n=sizeof(BITMAPFILEHEADER);
	LPBYTE	lpBuf;
	DWORD	dwCount=0,cl=0/*,WidthBytes*/;
	DWORD	bits=0;
	CFile	f;
	int		inc=1;

	DWORD	OldBytesPerScanLine=0;
	DWORD	pad=0;

	if(!f.Open((LPCTSTR)szFilePath,CFile::modeRead,NULL))
		goto errorLoad;

	if(f.Read(&m_info.bmpFileHeader,n) !=n)
		goto errorLoad;
	if(m_info.bmpFileHeader.bfType!=0x4D42)
		goto errorLoad;
	
	if(m_info.bmpInfo!=NULL)
	{
		delete m_info.bmpInfo;
		m_info.bmpInfo=NULL;
	}
	n=m_info.bmpFileHeader.bfOffBits-n;
	if(m_info.bmpInfo==NULL)
		if((m_info.bmpInfo=(BITMAPINFO*)new BYTE[n])==NULL)
			goto errorLoad;
	if(f.Read(m_info.bmpInfo,n)!=n)
		goto errorLoad;

	switch(m_info.bmpInfo->bmiHeader.biCompression)
	{
		case BI_RGB:
			break;
		case BI_BITFIELDS:
			break;
		case BI_RLE8:
			goto errorLoad;
		case BI_RLE4:
			goto errorLoad;
		default:
			goto errorLoad;
	}
	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	m_info.bmpBytesPerScanLine=m_info.bmpInfo->bmiHeader.biWidth*bits/8;		
	dwBufLength=m_info.bmpBytesPerScanLine*abs(m_info.bmpInfo->bmiHeader.\
												biHeight);

	m_info.bmpColors=(m_info.bmpFileHeader.bfOffBits-sizeof(BITMAPFILEHEADER)
				-sizeof(BITMAPINFOHEADER))/sizeof(PALETTEENTRY);

	OldBytesPerScanLine=m_info.bmpBytesPerScanLine;
	if(OldBytesPerScanLine%4!=0)
	{	
		DWORD widthBytes;
		if(bits!=24)
			widthBytes=(OldBytesPerScanLine/4)*4+4;
		else
			widthBytes=(OldBytesPerScanLine/12)*12+12;
		m_info.bmpInfo->bmiHeader.biWidth=widthBytes/(bits/8);

		m_info.bmpBytesPerScanLine=widthBytes;
		dwBufLength=widthBytes * abs(m_info.bmpInfo->bmiHeader.biHeight);
		m_info.bmpFileHeader.bfSize=dwBufLength+m_info.bmpFileHeader.bfOffBits;
		pad=widthBytes-OldBytesPerScanLine;
	}

	if(hBuf==NULL)
		hBuf=GlobalAlloc(GMEM_MOVEABLE|GMEM_ZEROINIT,dwBufLength);
	else
		GlobalReAlloc(hBuf,dwBufLength,GMEM_MOVEABLE|GMEM_ZEROINIT);
	if(!IsValid())
		goto errorLoad;
	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
		goto errorLoad;

	cl=(DWORD)abs(m_info.bmpInfo->bmiHeader.biHeight);
	if(cl==0)
		goto errorLoad;
	if(m_info.bmpInfo->bmiHeader.biHeight>0)
	{
		lpBuf+=(cl-1)*m_info.bmpBytesPerScanLine;
		inc=-1;
	}
	else
		inc=1;
	do
	{
		n=f.Read(lpBuf,OldBytesPerScanLine);
		if(n!=(DWORD)OldBytesPerScanLine)
		{
			GlobalUnlock(hBuf);
			goto errorLoad;
		}
		lpBuf +=inc*(int)m_info.bmpBytesPerScanLine;
		dwCount++;
	} while(dwCount<cl);

	m_ptOrg=CPoint(0,0);
	GlobalUnlock(hBuf);
	return TRUE;

errorLoad:
	Delete();
	return FALSE;
}

BOOL	CImage::WriteToFile(CString szFilePath)
{
	DWORD	n=sizeof(BITMAPFILEHEADER);
	LPBYTE	lpBuf;
	DWORD	dwCount=0,cl=0;
	DWORD	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	CFile	f;
	int		inc=1;
	DWORD pad=0;//pad la so byte can them vao
	BYTE  extra=0;
	DWORD OldBytesPerScanLine,OldLength, OldWidth, OldSize;

	if(!f.Open((LPCTSTR)szFilePath,CFile::modeCreate | CFile::modeWrite ,NULL))
		goto errorWrite;

	switch(m_info.bmpInfo->bmiHeader.biCompression)
	{
		case BI_RGB:
			break;
		case BI_BITFIELDS:
			break;
		case BI_RLE8:
			goto errorWrite;
		case BI_RLE4:
			goto errorWrite;
		default:
			goto errorWrite;
	}

	OldBytesPerScanLine=m_info.bmpBytesPerScanLine;
	OldLength=dwBufLength;
	OldWidth=m_info.bmpInfo->bmiHeader.biWidth;
	OldSize=m_info.bmpFileHeader.bfSize;

	if(OldBytesPerScanLine%4!=0)
	{
		DWORD widthBytes;
		if(bits!=24)
			widthBytes=(OldBytesPerScanLine/4)*4+4;
		else
			widthBytes=(OldBytesPerScanLine/12)*12+12;
		m_info.bmpInfo->bmiHeader.biWidth=widthBytes/(bits/8);

		m_info.bmpBytesPerScanLine=widthBytes;
		dwBufLength=widthBytes * abs(m_info.bmpInfo->bmiHeader.biHeight);
		m_info.bmpFileHeader.bfSize=dwBufLength+m_info.bmpFileHeader.bfOffBits;
		pad=widthBytes-OldBytesPerScanLine;
	}
	if(!IsValid())
		goto errorWrite;

	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
		goto errorWrite;

	f.Write(&m_info.bmpFileHeader,n);
	if(m_info.bmpInfo==NULL)
		goto errorWrite;
	
	if(m_info.bmpInfo->bmiHeader.biCompression==BI_RGB)
		m_info.bmpInfo->bmiHeader.biSizeImage=0;
	n=m_info.bmpFileHeader.bfOffBits-n;
	f.Write(m_info.bmpInfo,n);

	cl=(DWORD)abs(m_info.bmpInfo->bmiHeader.biHeight);
	if(cl==0)
		goto errorWrite;
	if(m_info.bmpInfo->bmiHeader.biHeight>0)
	{
		lpBuf+=(cl-1)*m_info.bmpBytesPerScanLine;
		inc=-1;
	}
	else
		inc=1;
	do
	{
		f.Write(lpBuf,OldBytesPerScanLine);
		for(DWORD i=0;i<pad;i++)
			f.Write(&extra,1);
		lpBuf+=inc*(int)OldBytesPerScanLine;
		dwCount++;
	} while(dwCount<cl);

	GlobalUnlock(hBuf);
	m_info.bmpBytesPerScanLine=OldBytesPerScanLine;
	dwBufLength=OldLength;
	m_info.bmpInfo->bmiHeader.biWidth=OldWidth;
	m_info.bmpFileHeader.bfSize=OldSize;
	return TRUE;

errorWrite:
	m_info.bmpInfo->bmiHeader.biSizeImage=dwBufLength;
	f.Close();
	f.Remove((LPCTSTR)szFilePath);
	return FALSE;
}



BOOL	CImage::Delete()
{
	if(m_info.bmpInfo!=NULL)
		delete m_info.bmpInfo;
	if(hBuf!=NULL)
		GlobalFree(hBuf);

	memset((IMGINFO*)&m_info,0,sizeof(IMGINFO));
	m_ptOrg=CPoint(0,0);
	dwBufLength=0;
	hBuf=NULL;
	return TRUE;
}
BOOL	CImage::IsValid()
{
	return (hBuf!=NULL && dwBufLength>0);
}
BOOL	CImage::IsFit(CImage& Img)
{
	if(m_info.bmpFileHeader.bfType!=Img.m_info.bmpFileHeader.bfType||
	   m_info.bmpFileHeader.bfOffBits!=Img.m_info.bmpFileHeader.bfOffBits)
	   return FALSE;

	if(m_info.bmpInfo->bmiHeader.biSize!=Img.m_info.bmpInfo->bmiHeader.biSize||
	   m_info.bmpInfo->bmiHeader.biPlanes!=Img.m_info.bmpInfo->bmiHeader.biPlanes||
	   m_info.bmpInfo->bmiHeader.biBitCount!=Img.m_info.bmpInfo->bmiHeader.\
					biBitCount||
	   m_info.bmpInfo->bmiHeader.biCompression!=Img.m_info.bmpInfo->bmiHeader.\
					biCompression /*||
	   m_info.bmpInfo->bmiHeader.biXPelsPerMeter!=Img.m_info.bmpInfo->bmiHeader.\
					biXPelsPerMeter||
	   m_info.bmpInfo->bmiHeader.biYPelsPerMeter!=Img.m_info.bmpInfo->bmiHeader.\
					biYPelsPerMeter*/)
		return FALSE;

	DWORD numColors1=m_info.bmpColors;
	DWORD numColors2=Img.m_info.bmpColors;
	if(numColors1!=numColors2)
		return FALSE;
	if(numColors1==0)
		return TRUE;

	for(DWORD i=0;i<numColors1;i++)
		if(m_info.bmpInfo->bmiColors[i].rgbRed!=Img.m_info.bmpInfo->\
					bmiColors[i].rgbRed||
		   m_info.bmpInfo->bmiColors[i].rgbGreen!=Img.m_info.bmpInfo->\
					bmiColors[i].rgbGreen||
		   m_info.bmpInfo->bmiColors[i].rgbBlue!=Img.m_info.bmpInfo->\
					bmiColors[i].rgbBlue)
			return FALSE;

	return TRUE;
		
}

DWORD	CImage::FindArea(CPoint pt)
{
	CPoint c,rp;
	
	c.x=GetWidth()/2;
	c.y=abs(GetHeight()/2);
	rp=m_ptOrg+pt;

	if(c.x==0 || c.y==0 || rp.x<0 || rp.y<0 || rp.x>=GetWidth() || rp.y>=abs(GetHeight()))
		return 0;

	if(rp.x<=c.x)
	{
		if(rp.y<=c.y)
			return LEFTTOP;
		else
			return LEFTBOTTOM;
	}
	else
	{
		if(rp.y<=c.y)
			return RIGHTTOP;
		else
			return RIGHTBOTTOM;
	}
}

DWORD	CImage::FindArea(DWORD x, DWORD y)
{
	return FindArea(CPoint((int)x,(int)y));
}
BOOL	CImage::GetInfo(BITMAPINFOHEADER* pInfo)
{

	if(memcpy(pInfo,(const BITMAPINFOHEADER*)&\
		(m_info.bmpInfo->bmiHeader),sizeof(BITMAPINFOHEADER))==NULL)
		return FALSE;
	return TRUE;
}
BOOL	CImage::GetFileHeader(BITMAPFILEHEADER& fileHeader)
{
	if(memcpy((BITMAPFILEHEADER*)&fileHeader,(const BITMAPFILEHEADER*)&\
		(m_info.bmpFileHeader),sizeof(BITMAPFILEHEADER))==NULL)
		return FALSE;
	return TRUE;
}
DWORD	CImage::GetPalette(CPalette* pPal)
{
	DWORD			nBits,n;
	LPLOGPALETTE	pLogPal;

	nBits=m_info.bmpInfo->bmiHeader.biBitCount;
	if(nBits>=24)
		return 0;

	if(m_info.bmpColors==0)
		return 0;
	n=sizeof(LOGPALETTE)+(m_info.bmpColors-1)*sizeof(PALETTEENTRY);
	
	pLogPal=(LPLOGPALETTE)new BYTE[n];
	pLogPal->palVersion=0x300;
	pLogPal->palNumEntries=(WORD)m_info.bmpColors;
	for(DWORD i=0;i<m_info.bmpColors;i++)
	{
		pLogPal->palPalEntry[i].peRed=m_info.bmpInfo->bmiColors[i].rgbRed;
		pLogPal->palPalEntry[i].peGreen=m_info.bmpInfo->bmiColors[i].rgbGreen;
		pLogPal->palPalEntry[i].peBlue=m_info.bmpInfo->bmiColors[i].rgbBlue;
		pLogPal->palPalEntry[i].peFlags=m_info.bmpInfo->bmiColors[i].rgbReserved;
	}
	pPal->CreatePalette(pLogPal);
	delete pLogPal;

	return m_info.bmpColors;
}
DWORD	CImage::GetBits(LPBYTE  lpBits,DWORD dwCount,DWORD dwReverse)
{
	LPBYTE   lpBuf;
	DWORD	 cLines=0,numLines=0,modeBytes=0;
	int		 inc=1;

	if(!IsValid())
		return 0;
	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
		return 0;
	if(dwCount==0||dwCount>dwBufLength)
		numLines=m_info.bmpInfo->bmiHeader.biHeight;
	else
	{
		numLines=dwCount/m_info.bmpBytesPerScanLine;
		modeBytes=dwCount%m_info.bmpBytesPerScanLine;
	}
	if(numLines==0)
		return 0;
	if(dwReverse)
	{
		lpBuf+=(numLines-1)*m_info.bmpBytesPerScanLine;
		inc=-1;
	}
	else
		inc=1;
	do
	{
		memcpy(lpBits,lpBuf,m_info.bmpBytesPerScanLine);
		lpBuf +=(inc*m_info.bmpBytesPerScanLine);
		lpBits+=m_info.bmpBytesPerScanLine;
		cLines++;
	} while(cLines<numLines);
	//memcpy(lpBits,lpBuf,modeBytes);

	GlobalUnlock(hBuf);
	return numLines;
}
CPoint  CImage::GetPtOrg()
{
	return m_ptOrg;
}
DWORD	CImage::GetPixel(CPoint pt)
{
	if(!IsValid())
		return 0xFFFFFFFF;
	LPBYTE	lpBuf;

	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
		return 0xFFFFFFFF;

	register BYTE*	adr;
	CPoint			ptReal = pt+m_ptOrg;
	DWORD			v,lines;

	if ((ptReal.x<0)||(ptReal.x>=m_info.bmpInfo->bmiHeader.biWidth)||
		(ptReal.y<0)||(ptReal.y>=m_info.bmpInfo->bmiHeader.biHeight))
		return 0xFFFFFFFF;
	//if(m_info.bmpInfo->bmiHeader.biHeight>=0)
		//lines=m_info.bmpInfo->bmiHeader.biHeight-ptReal.y-1;
	//else
		lines=ptReal.y;
	switch(m_info.bmpInfo->bmiHeader.biBitCount) 
	{
		case 1:
			adr = lpBuf+lines*m_info.bmpBytesPerScanLine+(ptReal.x>>3);
			v=(((*adr)&(0x80>>(ptReal.x&0x7)))!=0);
		case 4:
			BYTE tmp;
			adr = lpBuf+lines*m_info.bmpBytesPerScanLine+(ptReal.x>>1);
			tmp=*adr;
			v=(ptReal.x%2==0?tmp>>4:tmp&0x0F);
			break;
		case 8:
			adr = lpBuf+lines*m_info.bmpBytesPerScanLine+ptReal.x;
			v= (*adr)&0xFF;
			break;
		case 16:
			adr = lpBuf+lines*m_info.bmpBytesPerScanLine+2*ptReal.x;
			v=(*(WORD*)adr)&0xFFFF;
			break;
		case 24:
			adr = lpBuf+lines*m_info.bmpInfo->bmiHeader.biWidth+3*ptReal.x;
			v=(*(DWORD*)adr)&0xFFFFFF;
			break;
		default:
			return 0xFFFFFFFF;
	}
	return v;
}

DWORD	CImage::GetPixel(int x, int y)
{
	CPoint pt(x,y);
	return GetPixel(pt);

}
DWORD	CImage::GetPixel(int num)
{
	CPoint pt;
	pt.x=num%m_info.bmpBytesPerScanLine;
	pt.y=num/m_info.bmpBytesPerScanLine;
	return GetPixel(pt);
}

LONG	CImage::GetWidth()
{
	return m_info.bmpInfo->bmiHeader.biWidth ;
}
LONG	CImage::GetHeight()
{
	return m_info.bmpInfo->bmiHeader.biHeight ;
}


DWORD	CImage::SetBits(const LPBYTE lpBits,DWORD dwCount,DWORD dwReverse)
{
	LPBYTE   lpBuf,lpTemp;
	DWORD	 cLines=0,numLines=0,modeBytes=0;
	int		 inc=1;

	if(dwCount==0||dwCount>dwBufLength)
		numLines=m_info.bmpInfo->bmiHeader.biHeight;
	else
	{
		numLines=dwCount/m_info.bmpBytesPerScanLine;
		modeBytes=dwCount%m_info.bmpBytesPerScanLine;
	}
	if(numLines==0)
		return 0;

	lpTemp=lpBits;
	if(dwReverse)
	{
		lpTemp+=(numLines-1)*m_info.bmpBytesPerScanLine;
		inc=-1;
	}
	else
		inc=1;

	if(!IsValid())	return 0;
	if(GlobalReAlloc(hBuf,numLines*m_info.bmpBytesPerScanLine,GMEM_MOVEABLE)==NULL)
		return 0;
	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
		return 0;
	do
	{
		memcpy(lpBuf,lpTemp,m_info.bmpBytesPerScanLine);
		lpTemp +=(inc*m_info.bmpBytesPerScanLine);
		lpBuf+=m_info.bmpBytesPerScanLine;
		cLines++;
	} while(cLines<numLines);
	//memcpy(lpBuf,lpTemp,modeBytes);
	m_info.bmpFileHeader.bfSize-=(dwBufLength-numLines*m_info.bmpBytesPerScanLine);
	dwBufLength=numLines*m_info.bmpBytesPerScanLine;
	if(m_info.bmpInfo->bmiHeader.biSizeImage==0&&m_info.bmpInfo->bmiHeader.\
					biCompression==BI_RGB)
		m_info.bmpInfo->bmiHeader.biSizeImage=dwBufLength;
	m_info.bmpInfo->bmiHeader.biHeight=numLines;

	GlobalUnlock(hBuf);
	return numLines;
}
BOOL	CImage::SetInfo(CImage* pImg)
{
	DWORD n=0;
	if(!pImg->IsValid())	
		goto end;
	n=sizeof(BITMAPFILEHEADER);
	
	if(memcpy((BITMAPFILEHEADER*)&m_info.bmpFileHeader,
		(const BITMAPFILEHEADER*)&pImg->m_info.bmpFileHeader,n)==NULL)
		goto end;
	

	if(m_info.bmpInfo!=NULL)
	{
		delete m_info.bmpInfo;
		m_info.bmpInfo=NULL;
	}
	n=pImg->m_info.bmpFileHeader.bfOffBits-n;
	if((m_info.bmpInfo=(BITMAPINFO*)new BYTE[n])==NULL)
		goto end;
	if(memcpy(m_info.bmpInfo,pImg->m_info.bmpInfo,n)==NULL)
		goto end;

	m_info.bmpInfo->bmiHeader.biWidth=0;
	m_info.bmpInfo->bmiHeader.biHeight=0;
	m_info.bmpBytesPerScanLine=0;
	m_info.bmpInfo->bmiHeader.biSizeImage=0;
	m_info.bmpColors=pImg->m_info.bmpColors;
	m_info.bmpFileHeader.bfSize=m_info.bmpFileHeader.bfOffBits;

	dwBufLength=0;
	hBuf=NULL;
	m_ptOrg=CPoint(0,0);

	return TRUE;
end:
	Delete();
	return FALSE;
}
BOOL	CImage::SetImage(CImage* pImg)
{
	if(!SetInfo(pImg))
		goto end;

	if(hBuf==NULL)
		hBuf=GlobalAlloc(GMEM_MOVEABLE|GMEM_ZEROINIT,pImg->dwBufLength);
	else
		GlobalReAlloc(hBuf,pImg->dwBufLength,GMEM_MOVEABLE|GMEM_ZEROINIT);
	if(hBuf==NULL)
		goto end;
	LPBYTE lpSrc,lpDst;
	if((lpSrc=(LPBYTE)GlobalLock(pImg->hBuf))==NULL
		||(lpDst=(LPBYTE)GlobalLock(hBuf))==NULL)
		goto end;
	
	if(memcpy(lpDst,lpSrc,pImg->dwBufLength)==NULL)
	{
		GlobalUnlock(hBuf);
		GlobalUnlock(pImg->hBuf);
		goto end;
	}

	m_info.bmpInfo->bmiHeader.biWidth =pImg->m_info.bmpInfo->bmiHeader.biWidth;
	m_info.bmpInfo->bmiHeader.biHeight=pImg->m_info.bmpInfo->bmiHeader.biHeight;
	m_info.bmpBytesPerScanLine=pImg->m_info.bmpBytesPerScanLine;
	m_info.bmpInfo->bmiHeader.biSizeImage=dwBufLength;
	dwBufLength=pImg->dwBufLength;
	m_info.bmpFileHeader.bfSize=pImg->m_info.bmpFileHeader.bfSize;

	m_ptOrg=pImg->m_ptOrg;
	GlobalUnlock(hBuf);
	GlobalUnlock(pImg->hBuf);
	
	return TRUE;
end:
	Delete();
	return FALSE;
}

CPoint  CImage::SetPtOrg(CPoint ptOrg)
{
	CPoint  OldOrg=m_ptOrg;
	LONG	Width,Height;
	Width=m_info.bmpInfo->bmiHeader.biWidth;
	Height=abs(m_info.bmpInfo->bmiHeader.biHeight);

	m_ptOrg=ptOrg;
	m_ptOrg.x=(m_ptOrg.x<0)?0:m_ptOrg.x;
	m_ptOrg.y=(m_ptOrg.y<0)?0:m_ptOrg.y;
	m_ptOrg.x=(m_ptOrg.x>=Width)?Width-1:m_ptOrg.x;
	m_ptOrg.y=(m_ptOrg.y>=Height)?Height-1:m_ptOrg.y;
	return OldOrg;
}
CPoint  CImage::SetPtOrg(int x,int y)
{
	CPoint OldOrg=m_ptOrg;
	LONG  Width, Height;
	Width=m_info.bmpInfo->bmiHeader.biWidth;
	Height=abs(m_info.bmpInfo->bmiHeader.biHeight);

	x=(x<0)?0:x;
	y=(y<0)?0:y;
	x=(x>=Width)?Width-1:x;
	y=(y>=Height)?Height-1:y;
	m_ptOrg.x=x;m_ptOrg.y=y;
	return OldOrg;
}
CPoint  CImage::SetPtOrgCenter()
{
	CPoint OldOrg=m_ptOrg;
	m_ptOrg.x=m_info.bmpInfo->bmiHeader.biWidth/2;
	m_ptOrg.y=abs(m_info.bmpInfo->bmiHeader.biHeight/2);
	return OldOrg;
}
CPoint  CImage::SetPtOrgLeftTop()
{
	CPoint OldOrg=m_ptOrg;
	m_ptOrg.x=0;
	m_ptOrg.y=0;
	return OldOrg;
}
CPoint  CImage::SetPtOrgLeftBottom()
{
	CPoint OldOrg=m_ptOrg;
	m_ptOrg.x=0;
	m_ptOrg.y=abs(m_info.bmpInfo->bmiHeader.biHeight)-1;
	m_ptOrg.y=(m_ptOrg.y<0)?0:m_ptOrg.y;
	return OldOrg;
}
CPoint  CImage::SetPtOrgRightBottom()
{
	CPoint OldOrg=m_ptOrg;
	m_ptOrg.x=m_info.bmpInfo->bmiHeader.biWidth-1;
	m_ptOrg.y=abs(m_info.bmpInfo->bmiHeader.biHeight)-1;
	m_ptOrg.x=(m_ptOrg.x<0)?0:m_ptOrg.x;
	m_ptOrg.y=(m_ptOrg.y<0)?0:m_ptOrg.y;
	return OldOrg;
}
CPoint  CImage::SetPtOrgRightTop()
{
	CPoint OldOrg=m_ptOrg;
	m_ptOrg.x=m_info.bmpInfo->bmiHeader.biWidth-1;
	m_ptOrg.y=0;
	m_ptOrg.x=(m_ptOrg.x<0)?0:m_ptOrg.x;
	return OldOrg;
}

DWORD	CImage::SetSize(LONG  Width, LONG Height, BOOL blank)//Width,Height:Pixel
{
	DWORD	bits;
	DWORD	widthBytes, widthBits;;
	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	if(bits<8)
	{
		widthBits=Width*bits;
		if(widthBits%8!=0)
			widthBits=(widthBits/8)*8+8;
		widthBytes=widthBits/8;
	}
	else
		widthBytes=Width*(bits/8);

	if(widthBytes%4!=0)
	{
		if(bits!=24)
			widthBytes=(widthBytes/4)*4 + 4;
		else
			widthBytes =(widthBytes/12)*12 + 12;
	}
	m_info.bmpInfo->bmiHeader.biWidth =widthBytes/(bits/8);

	m_info.bmpInfo->bmiHeader.biHeight=Height;
	m_info.bmpBytesPerScanLine=widthBytes;
	dwBufLength=widthBytes*abs(Height);
	m_info.bmpInfo->bmiHeader.biSizeImage=dwBufLength;
	m_info.bmpFileHeader.bfSize=dwBufLength+m_info.bmpFileHeader.bfOffBits;


	m_ptOrg=CSize(0,0);

	if(!IsValid())
		hBuf=GlobalAlloc(GMEM_MOVEABLE|GMEM_ZEROINIT,dwBufLength);
	else
		GlobalReAlloc(hBuf,dwBufLength,GMEM_MOVEABLE|GMEM_ZEROINIT);
	if(!IsValid())
	{
		Delete();
		return 0;
	}
	if(blank)
		Blank();

	return dwBufLength;
}
BOOL	CImage::SetPixel(CPoint pt, DWORD value)
{
	if(!IsValid())
		return FALSE;
	LPBYTE	lpBuf;

	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
		return FALSE;

	register BYTE*	adr;
	register DWORD	pixnum;
	CPoint			ptReal = pt+m_ptOrg;
	DWORD			lines;
	BYTE			tmp;

	if ((ptReal.x<0)||(ptReal.x>=m_info.bmpInfo->bmiHeader.biWidth)||
		(ptReal.y<0)||(ptReal.y>=m_info.bmpInfo->bmiHeader.biHeight))
		return FALSE;

	//if(m_info.bmpInfo->bmiHeader.biHeight>=0)
		//lines=m_info.bmpInfo->bmiHeader.biHeight-ptReal.y-1;
	//else
		lines=ptReal.y;
	switch(m_info.bmpInfo->bmiHeader.biBitCount) 
	{
		case 1:
			adr = lpBuf+lines*m_info.bmpBytesPerScanLine+(ptReal.x>>3);
			pixnum = ptReal.x & 0x7;
			value ? (*adr |= (0x80>>pixnum)) : (*adr &= (0xff7f>>pixnum));
			break;
		case 4:
			tmp=(BYTE)value;
			adr = lpBuf+lines*m_info.bmpBytesPerScanLine+(ptReal.x>>1);
			ptReal.x%2==0? *adr|=(tmp<<4):*adr|=(tmp&0x0F);
			break;
		case 8:
			adr = lpBuf+lines*m_info.bmpBytesPerScanLine+ptReal.x;
			*adr = (BYTE)value;
			break;
		case 16:
			adr = lpBuf+lines*m_info.bmpBytesPerScanLine+2*ptReal.x;
			*((WORD*)adr)=(WORD)value;
			break;
		case 24:
			adr = lpBuf+lines*m_info.bmpBytesPerScanLine+3*ptReal.x;
			*((DWORD*)adr) = ((*((DWORD*)adr)) & 0xff000000) | (value & 0x00ffffff);
			break;
		default:
			return FALSE;
		}
	return TRUE;
}
BOOL	CImage::SetPixel(int x, int y, DWORD value)
{
	CPoint pt(x,y);
	return SetPixel(pt,value);
}
BOOL	CImage::SetPixel(int num, DWORD value)
{
	CPoint pt;
	pt.x=num%m_info.bmpBytesPerScanLine;
	pt.y=num/m_info.bmpBytesPerScanLine;
	return SetPixel(pt,value);
}
void	CImage::Blank()
{
	LPBYTE	lpBuf;
	lpBuf=(LPBYTE)GlobalLock(hBuf);
	memset(lpBuf,0xFF,dwBufLength);
	GlobalUnlock(hBuf);
}

BOOL	CImage::Draw(CDC* pDC,CPoint dstPoint,CSize dstSize,CPoint srcOffset,
					CSize srcSize,DWORD dwRop)
{
	LPBYTE		lpBuf;
	BOOL		ret;
	DWORD		nEntry;
	CPoint		ptDst;
	HBITMAP		hBmp,hOldBmp;
	CPalette	*pPal,*pOldPal;
	HDC			hMemDC;

	if(!IsValid())
		return FALSE;
	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
		return FALSE;

	pPal=new CPalette;
	nEntry=GetPalette(pPal);
	if(nEntry!=0)
	{
		pOldPal=pDC->SelectPalette(pPal,FALSE);
		pDC->RealizePalette();
	}

	LONG Height=m_info.bmpInfo->bmiHeader.biHeight;
	if(Height>0)
		m_info.bmpInfo->bmiHeader.biHeight=-Height;

	hBmp=::CreateDIBitmap(pDC->GetSafeHdc(),(BITMAPINFOHEADER*)&(m_info.bmpInfo\
			->bmiHeader),CBM_INIT,lpBuf,(BITMAPINFO*)m_info.bmpInfo,DIB_RGB_COLORS);
	hMemDC=::CreateCompatibleDC(pDC->GetSafeHdc());
	hOldBmp=(HBITMAP)::SelectObject(hMemDC,hBmp);

	ptDst=dstPoint-m_ptOrg;
	ptDst.x=(ptDst.x<0)?0:ptDst.x;
	ptDst.y=(ptDst.y<0)?0:ptDst.y;
	if(dstSize.cx==0||dstSize.cy==0)
	{
		dstSize.cx=m_info.bmpInfo->bmiHeader.biWidth;
		dstSize.cy=Height;
	}
	if(srcSize.cx==0||srcSize.cy==0)
	{
		srcSize.cx=m_info.bmpInfo->bmiHeader.biWidth;
		srcSize.cy=Height;
	}

	ret=StretchBlt(pDC->GetSafeHdc(),
				   ptDst.x,ptDst.y,
				   dstSize.cx,dstSize.cy,
				   hMemDC,
				   srcOffset.x,srcOffset.y,
				   srcSize.cx,srcSize.cy,
				   dwRop);

	if(nEntry!=0)
		pDC->SelectPalette(pOldPal,FALSE);
	SelectObject(hMemDC,hOldBmp);

	delete pPal;
	::DeleteObject(hBmp);
	::DeleteDC(hMemDC);

	GlobalUnlock(hBuf);
	m_info.bmpInfo->bmiHeader.biHeight=Height;
	return ret;
			
}
BOOL	CImage::DrawEnhanced(CDC* pDC,CPoint dstPoint,CSize dstSize,CPoint srcOffset,
					CSize srcSize,DWORD dwFlags)
{
	HDRAWDIB hDrawDIB;
	LPBYTE   lpBuf, lpDrawBuf=NULL;
	BOOL	 ret;
	CPoint	 ptDst;
	
	if(!IsValid())
		return FALSE;
	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
		return FALSE;

	LONG	Height=m_info.bmpInfo->bmiHeader.biHeight;
	if(Height>0)
	{
		lpDrawBuf=(LPBYTE)new BYTE[dwBufLength];
		if(lpDrawBuf==NULL)
			goto error;
		if(GetBits(lpDrawBuf,0,TRUE)==0)
			goto error;
		lpBuf=lpDrawBuf;
	}
	if(!(hDrawDIB=DrawDibOpen()))
		goto error;

	ptDst=dstPoint-m_ptOrg;
	ptDst.x=(ptDst.x<0)?0:ptDst.x;
	ptDst.y=(ptDst.y<0)?0:ptDst.y;

	if(dstSize.cx==0||dstSize.cy==0)
	{
		dstSize.cx=m_info.bmpInfo->bmiHeader.biWidth;
		dstSize.cy=m_info.bmpInfo->bmiHeader.biHeight;
	}
	if(srcSize.cx==0||srcSize.cy==0)
	{
		srcSize.cx=m_info.bmpInfo->bmiHeader.biWidth;
		srcSize.cy=m_info.bmpInfo->bmiHeader.biHeight;
	}
	
	DrawDibRealize(hDrawDIB,pDC->GetSafeHdc(),TRUE);	
	ret=DrawDibDraw(hDrawDIB,pDC->GetSafeHdc(),
	                ptDst.x,ptDst.y,
					dstSize.cx,dstSize.cy,
					(LPBITMAPINFOHEADER)&m_info.bmpInfo->bmiHeader,lpBuf,
					 srcOffset.x,srcOffset.y,
					 srcSize.cx,srcSize.cy,
					 dwFlags);

	DrawDibClose(hDrawDIB);
	m_info.bmpInfo->bmiHeader.biHeight=Height;
	GlobalUnlock(hBuf);
	return ret;
error:
	GlobalUnlock(hBuf);
	if(lpDrawBuf!=NULL)
		delete lpDrawBuf;
	return FALSE;
}
BOOL	CImage::ConvertToGrayScale()
{
	if(m_info.bmpColors==0)
		return FALSE;
	LPDWORD		Gray,lpTmpBuf;
	DWORD		i;

	Gray=new DWORD[m_info.bmpColors];
	lpTmpBuf=Gray;
	i=m_info.bmpColors;
	while(i--)
	{
		*Gray=(DWORD)(Round(m_info.bmpInfo->bmiColors[i].rgbRed*0.299
				   +m_info.bmpInfo->bmiColors[i].rgbGreen*0.587
				   +m_info.bmpInfo->bmiColors[i].rgbBlue*0.114));
		Gray++;
	}

	LookupTable(Gray);
	delete lpTmpBuf;
	return TRUE;
}


CImage&	CImage::operator =  (CImage& Img)
{
	this->SetImage(&Img);
	return *this;
}

CImage	CImage::operator +  (DWORD k)
{
	CImage RetImg;
	if(((m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!IsValid()))
		return RetImg;

	DWORD	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=dwBufLength;
	LPBYTE	lpRetBuf;

	if(!RetImg.SetImage(this))
		return RetImg;

	if((lpRetBuf=(LPBYTE)GlobalLock(RetImg.hBuf))==NULL)
		return RetImg;
	k=k>m_info.bmpColors?m_info.bmpColors:k;

	if(bits==1)
	{
		if(k>=1)
			memset(lpRetBuf,0xFF,len);
	}
	else if(bits==4)
	{
		BYTE    value,tmp;

		while(len--)
		{
			value=*lpRetBuf;
			*lpRetBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp=(BYTE)(tmp+k);
			tmp =(tmp>(BYTE)m_info.bmpColors)?(BYTE)m_info.bmpColors:tmp;
			*lpRetBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp =(BYTE)(tmp+k);
			tmp =(tmp>(BYTE)m_info.bmpColors)?(BYTE)m_info.bmpColors:tmp;
			tmp =tmp<<4;
			*lpRetBuf=(*lpRetBuf)|tmp;

			lpRetBuf++;
		}
	}
	else if(bits==8)
	{
		WORD	tmp;
		
		while(len--)
		{
			tmp=(WORD)(*lpRetBuf);
			tmp =(WORD)(tmp+k);
			tmp=tmp>(WORD)m_info.bmpColors ?(WORD)m_info.bmpColors:tmp;
			*lpRetBuf=(BYTE)tmp;

			lpRetBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD lpTmpBuf=(LPWORD)lpRetBuf;
		DWORD	   tmp;

		len/=2;
		while(len--)
		{
			tmp=(DWORD)(*lpTmpBuf);
			tmp =(DWORD)(tmp+k);
			tmp=tmp>m_info.bmpColors ?m_info.bmpColors:tmp;
			*lpTmpBuf=(WORD)tmp;

			lpTmpBuf++;

		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);       
		WORD	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpRetBuf++; 
			G = *lpRetBuf++; 
			R = *lpRetBuf++; 

			R=(WORD)(R+Red);R=R>0xFF?0xFF:R;
			G=(WORD)(G+Green);G=G>0xFF?0xFF:G;
			B=(WORD)(B+Blue);B=B>0xFF?0xFF:B;

			*(lpRetBuf-1)=(BYTE)R;
			*(lpRetBuf-2)=(BYTE)G;
			*(lpRetBuf-3)=(BYTE)B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(RetImg.hBuf);
	return RetImg;
}
CImage	operator +  (DWORD k,CImage& Img)
{
	CImage RetImg;
	if(((Img.m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!Img.IsValid()))
		return RetImg;

	DWORD	bits=Img.m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=Img.dwBufLength;
	LPBYTE	lpRetBuf;

	if(!RetImg.SetImage(&Img))
		return RetImg;

	if((lpRetBuf=(LPBYTE)GlobalLock(RetImg.hBuf))==NULL)
		return RetImg;

	k=k>Img.m_info.bmpColors?Img.m_info.bmpColors:k;
	if(bits==1)
	{
		if(k>=1)
			memset(lpRetBuf,0xFF,len);
	}
	else if(bits==4)
	{
		BYTE    value,tmp;
	
		while(len--)
		{
			value=*lpRetBuf;
			*lpRetBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp =(BYTE)(tmp+k);
			tmp =(tmp>(BYTE)Img.m_info.bmpColors)?(BYTE)Img.m_info.bmpColors:tmp;
			*lpRetBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp =(BYTE)(tmp+k);
			tmp =(tmp>(BYTE)Img.m_info.bmpColors)?(BYTE)Img.m_info.bmpColors:tmp;
			tmp =tmp<<4;
			*lpRetBuf=(*lpRetBuf)|tmp;

			lpRetBuf++;
		}
	}
	else if(bits==8)
	{
		WORD	tmp;

		while(len--)
		{
			tmp=(WORD)(*lpRetBuf);
			tmp =(WORD)(tmp+k);
			tmp=tmp>(WORD)Img.m_info.bmpColors ?(WORD)Img.m_info.bmpColors:tmp;
			*lpRetBuf=(BYTE)tmp;

			lpRetBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD lpTmpBuf=(LPWORD)lpRetBuf;
		DWORD	   tmp;

		len/=2;
		while(len--)
		{
			tmp=(DWORD)(*lpTmpBuf);
			tmp =(DWORD)(tmp+k);
			tmp=tmp>Img.m_info.bmpColors ?Img.m_info.bmpColors:tmp;
			*lpTmpBuf=(WORD)tmp;

			lpTmpBuf++;

		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);       
		WORD	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpRetBuf++; 
			G = *lpRetBuf++; 
			R = *lpRetBuf++; 

			R=(WORD)(R+Red);R=R>0xFF?0xFF:R;
			G=(WORD)(G+Green);G=G>0xFF?0xFF:G;
			B=(WORD)(B+Blue);B=B>0xFF?0xFF:B;

			*(lpRetBuf-1)=(BYTE)R;
			*(lpRetBuf-2)=(BYTE)G;
			*(lpRetBuf-3)=(BYTE)B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(RetImg.hBuf);
	return RetImg;
}
CImage	CImage::operator +  (CImage& Img)
{
	DWORD	n,m,h,len;
	int		i=0;
	CImage	RetImg;
	CSize	size,common,tail;
	CPoint	ptStart;
	LPBYTE	lpBuf ,lpImgBuf,lpRetBuf;
	LPBYTE	lpBuf1,lpBuf2,lpBuf3,lpTmpBuf;

	if(!this->IsValid()||!Img.IsValid())
		return RetImg;
	if(!IsFit(Img))
		return RetImg;

	ptStart=m_ptOrg-Img.m_ptOrg;

	if(ptStart.y<0)
	{
		if(m_info.bmpInfo->bmiHeader.biHeight-ptStart.y<Img.m_info.bmpInfo->\
				bmiHeader.biHeight)
		{
			size.cy=Img.m_info.bmpInfo->bmiHeader.biHeight;
			common.cy=m_info.bmpInfo->bmiHeader.biHeight;
			tail.cy=size.cy-common.cy+ptStart.y;
		}
		else
		{
			size.cy=m_info.bmpInfo->bmiHeader.biHeight-ptStart.y;
			common.cy=Img.m_info.bmpInfo->bmiHeader.biHeight+ptStart.y;
			tail.cy=-size.cy+Img.m_info.bmpInfo->bmiHeader.biHeight;
		}
	}
	else
	{
		if(Img.m_info.bmpInfo->bmiHeader.biHeight+ptStart.y<m_info.bmpInfo->\
				bmiHeader.biHeight)
		{
			size.cy=m_info.bmpInfo->bmiHeader.biHeight;
			common.cy=Img.m_info.bmpInfo->bmiHeader.biHeight;
			tail.cy=-size.cy+common.cy+ptStart.y;
		}
		else
		{
			size.cy=Img.m_info.bmpInfo->bmiHeader.biHeight+ptStart.y;
			common.cy=m_info.bmpInfo->bmiHeader.biHeight-ptStart.y;
			tail.cy=size.cy-m_info.bmpInfo->bmiHeader.biHeight;
		}
	}

	if(ptStart.x<0)
	{
		if(m_info.bmpInfo->bmiHeader.biWidth-ptStart.x<Img.m_info.bmpInfo->\
				bmiHeader.biWidth)
		{
			size.cx=Img.m_info.bmpInfo->bmiHeader.biWidth;
			common.cx=m_info.bmpInfo->bmiHeader.biWidth;
			tail.cx=size.cx-common.cx+ptStart.x;
		}
		else
		{
			size.cx=m_info.bmpInfo->bmiHeader.biWidth-ptStart.x;
			common.cx=Img.m_info.bmpInfo->bmiHeader.biWidth+ptStart.x;
			tail.cx=-size.cx+Img.m_info.bmpInfo->bmiHeader.biWidth;
		}
	}
	else
	{
		if(Img.m_info.bmpInfo->bmiHeader.biWidth+ptStart.x<m_info.bmpInfo->\
				bmiHeader.biWidth)
		{
			size.cx=m_info.bmpInfo->bmiHeader.biWidth;
			common.cx=Img.m_info.bmpInfo->bmiHeader.biWidth;
			tail.cx=-size.cx+common.cx+ptStart.x;
		}
		else
		{
			size.cx=Img.m_info.bmpInfo->bmiHeader.biWidth+ptStart.x;
			common.cx=m_info.bmpInfo->bmiHeader.biWidth-ptStart.x;
			tail.cx=size.cx-m_info.bmpInfo->bmiHeader.biWidth;
		}
	}
	if(size.cx<=0||size.cy<=0)
		return RetImg;
	RetImg.SetInfo(this);
	RetImg.SetSize(size.cx+12,size.cy);
	RetImg.Blank();
	if(!RetImg.IsValid())
		return RetImg;
	char s1[20],s2[20];
	wsprintf(s1,"common.cx=%lu",common.cx);
	wsprintf(s2,"common.cy=%lu",common.cy);
	CString s;
	s=s1;
	s=s+s2;
	AfxMessageBox(s,MB_OK,0);

	lpBuf=(LPBYTE)GlobalLock(hBuf);
	lpImgBuf=(LPBYTE)GlobalLock(Img.hBuf);
	lpRetBuf=(LPBYTE)GlobalLock(RetImg.hBuf);
	if(lpBuf==NULL||lpImgBuf==NULL||lpRetBuf==NULL)
		return RetImg;
	lpBuf+=(m_info.bmpInfo->bmiHeader.biHeight-1)*m_info.bmpBytesPerScanLine;
	lpImgBuf+=(Img.m_info.bmpInfo->bmiHeader.biHeight-1)*Img.m_info.\
							bmpBytesPerScanLine;
	lpRetBuf+=(RetImg.m_info.bmpInfo->bmiHeader.biHeight-1)*RetImg.m_info.\
							bmpBytesPerScanLine;
	n=m_info.bmpInfo->bmiHeader.biBitCount;
	if(n==1||n==4||n==8)
		h=1;
	else if(n==16)
		h=2;
	else if(n==24)
		h=3;
	else if(n==32)
		h=4;
	ptStart.x *=h;
	size.cx *=h;
	common.cx *=h;
	tail.cx *=h;

	if(ptStart.y<0)
	{
		if(ptStart.x<0)
		{
			i=ptStart.y;
			while(i++)
			{
				memcpy(lpRetBuf,lpImgBuf,Img.m_info.bmpBytesPerScanLine);
				lpImgBuf -=Img.m_info.bmpBytesPerScanLine;
				lpRetBuf -=RetImg.m_info.bmpBytesPerScanLine;
			}
			for(i=0;i<common.cy;i++)
			{
				lpBuf1=lpBuf,lpBuf2=lpImgBuf,lpBuf3=lpRetBuf,lpTmpBuf;
				memcpy(lpBuf3,lpBuf2,-ptStart.x);
				lpBuf2-=ptStart.x;
				lpBuf3-=ptStart.x;
				m_info.bmpInfo->bmiHeader.biBitCount;
				switch(m_info.bmpInfo->bmiHeader.biBitCount)
				{
					case 1:
						break;
					case 4:
						break;
					case 8:
						{
							WORD	tmp;
							len=common.cx;
							while(len--)
							{
								tmp=(WORD)(*lpBuf1+*lpBuf2);
								tmp=tmp>(WORD)m_info.bmpColors ?(WORD)m_info.bmpColors:tmp;
								*lpBuf3=(BYTE)tmp;
	
								lpBuf1++;
								lpBuf2++;
								lpBuf3++;
							}
						}
						break;
					case 16:
						{
							DWORD	tmp;
							LPWORD	lpBuf4=(LPWORD)lpBuf1,
									lpBuf5=(LPWORD)lpBuf2,
									lpBuf6=(LPWORD)lpBuf3;

							len=common.cx/h;
							while(len--)
							{
								tmp=(DWORD)(*lpBuf4+*lpBuf5);
								tmp=tmp>Img.m_info.bmpColors ?Img.m_info.bmpColors:tmp;
								*lpBuf6=(WORD)tmp;
	
								lpBuf4++;
								lpBuf5++;
								lpBuf6++;
							}
							lpBuf1=(LPBYTE)lpBuf4;
							lpBuf2=(LPBYTE)lpBuf5;
							lpBuf3=(LPBYTE)lpBuf6;
						}
						break;
					case 24:
						{
							WORD	tmp;
							len=common.cx;
							while(len--)
							{
								tmp=(WORD)(*lpBuf1+*lpBuf2);
								tmp=tmp>0xFF?0xFF:tmp;
								*lpBuf3=(BYTE)tmp;
	
								lpBuf1++;
								lpBuf2++;
								lpBuf3++;
							}
						}
						break;
					case 32:
						break;
					default:
						GlobalUnlock(hBuf);
						GlobalUnlock(Img.hBuf);
						GlobalUnlock(RetImg.hBuf);
						return RetImg;
				}
				n=(DWORD)((tail.cx>0)?tail.cx:-tail.cx);
				lpTmpBuf=(tail.cx>0)?lpBuf2:lpBuf1;
				memcpy(lpBuf3,lpTmpBuf,n);

				lpBuf    -=m_info.bmpBytesPerScanLine;
				lpImgBuf -=Img.m_info.bmpBytesPerScanLine;
				lpRetBuf -=RetImg.m_info.bmpBytesPerScanLine;
			}
			if(tail.cy>0)
			{
				lpTmpBuf=lpImgBuf;
				m=tail.cy;
				n=Img.m_info.bmpBytesPerScanLine;
			}
			else
			{
				lpTmpBuf=lpBuf;
				m=-tail.cy;
				n=m_info.bmpBytesPerScanLine;
			}
			for(i=0;i<(int)m;i++)
			{
				lpBuf3=(tail.cy>0)?lpRetBuf:lpRetBuf-ptStart.x;
				memcpy(lpBuf3,lpTmpBuf,n);
				lpTmpBuf-=n;
				lpRetBuf-=RetImg.m_info.bmpBytesPerScanLine;
			}
		}
		else
		{
			i=ptStart.y;
			while(i++)
			{
				lpBuf3=lpRetBuf+ptStart.x;
				memcpy(lpBuf3,lpImgBuf,Img.m_info.bmpBytesPerScanLine);
				lpImgBuf -=Img.m_info.bmpBytesPerScanLine;
				lpRetBuf -=RetImg.m_info.bmpBytesPerScanLine;
			}
			for(i=0;i<common.cy;i++)
			{
				lpBuf1=lpBuf,lpBuf2=lpImgBuf,lpBuf3=lpRetBuf,lpTmpBuf;
				memcpy(lpBuf3,lpBuf1,ptStart.x);
				lpBuf1+=ptStart.x;
				lpBuf3+=ptStart.x;
				m_info.bmpInfo->bmiHeader.biBitCount;
				switch(m_info.bmpInfo->bmiHeader.biBitCount)
				{
					case 1:
						break;
					case 4:
						break;
					case 8:
						{
							WORD	tmp;
							len=common.cx;
							while(len--)
							{
								tmp=(WORD)(*lpBuf1+*lpBuf2);
								tmp=tmp>(WORD)m_info.bmpColors ?(WORD)m_info.bmpColors:tmp;
								*lpBuf3=(BYTE)tmp;
	
								lpBuf1++;
								lpBuf2++;
								lpBuf3++;
							}
						}
						break;
					case 16:
						{
							DWORD	tmp;
							LPWORD	lpBuf4=(LPWORD)lpBuf1,
									lpBuf5=(LPWORD)lpBuf2,
									lpBuf6=(LPWORD)lpBuf3;

							len=common.cx/h;
							while(len--)
							{
								tmp=(DWORD)(*lpBuf4+*lpBuf5);
								tmp=tmp>Img.m_info.bmpColors ?Img.m_info.bmpColors:tmp;
								*lpBuf6=(WORD)tmp;
	
								lpBuf4++;
								lpBuf5++;
								lpBuf6++;
							}
							lpBuf1=(LPBYTE)lpBuf4;
							lpBuf2=(LPBYTE)lpBuf5;
							lpBuf3=(LPBYTE)lpBuf6;
						}
						break;
					case 24:
						{
							WORD	tmp;
							len=common.cx;
							while(len--)
							{
								tmp=(WORD)(*lpBuf1+*lpBuf2);
								tmp=tmp>0xFF?0xFF:tmp;
								*lpBuf3=(BYTE)tmp;
	
								lpBuf1++;
								lpBuf2++;
								lpBuf3++;
							}
						}
						break;
					case 32:
						break;
					default:
						GlobalUnlock(hBuf);
						GlobalUnlock(Img.hBuf);
						GlobalUnlock(RetImg.hBuf);
						return RetImg;
				}
				n=(DWORD)((tail.cx>0)?tail.cx:-tail.cx);
				lpTmpBuf=(tail.cx>0)?lpBuf2:lpBuf1;
				memcpy(lpBuf3,lpTmpBuf,n);

				lpBuf    -=m_info.bmpBytesPerScanLine;
				lpImgBuf -=Img.m_info.bmpBytesPerScanLine;
				lpRetBuf -=RetImg.m_info.bmpBytesPerScanLine;
			}
			if(tail.cy>0)
			{
				lpTmpBuf=lpImgBuf;
				m=tail.cy;
				n=Img.m_info.bmpBytesPerScanLine;
			}
			else
			{
				lpTmpBuf=lpBuf;
				m=-tail.cy;
				n=m_info.bmpBytesPerScanLine;
			}
			for(i=0;i<(int)m;i++)
			{
				lpBuf3=(tail.cy>0)?lpRetBuf+ptStart.x:lpRetBuf;
				memcpy(lpBuf3,lpTmpBuf,n);
				lpTmpBuf-=n;
				lpRetBuf-=RetImg.m_info.bmpBytesPerScanLine;
			}
		}
	}
	else
	{
		if(ptStart.x<0)
		{
			i=ptStart.y;
			while(i--)
			{
				lpBuf3=lpRetBuf-ptStart.x;
				memcpy(lpBuf3,lpBuf,m_info.bmpBytesPerScanLine);
				lpBuf -=m_info.bmpBytesPerScanLine;
				lpRetBuf -=RetImg.m_info.bmpBytesPerScanLine;
			}
			for(i=0;i<common.cy;i++)
			{
				lpBuf1=lpBuf,lpBuf2=lpImgBuf,lpBuf3=lpRetBuf,lpTmpBuf;
				memcpy(lpBuf3,lpBuf2,-ptStart.x);
				lpBuf2-=ptStart.x;
				lpBuf3-=ptStart.x;
				m_info.bmpInfo->bmiHeader.biBitCount;
				switch(m_info.bmpInfo->bmiHeader.biBitCount)
				{
					case 1:
						break;
					case 4:
						break;
					case 8:
						{
							WORD	tmp;
							len=common.cx;
							while(len--)
							{
								tmp=(WORD)(*lpBuf1+*lpBuf2);
								tmp=tmp>(WORD)m_info.bmpColors ?(WORD)m_info.bmpColors:tmp;
								*lpBuf3=(BYTE)tmp;
	
								lpBuf1++;
								lpBuf2++;
								lpBuf3++;
							}
						}
						break;
					case 16:
						{
							DWORD	tmp;
							LPWORD	lpBuf4=(LPWORD)lpBuf1,
									lpBuf5=(LPWORD)lpBuf2,
									lpBuf6=(LPWORD)lpBuf3;

							len=common.cx/h;
							while(len--)
							{
								tmp=(DWORD)(*lpBuf4+*lpBuf5);
								tmp=tmp>Img.m_info.bmpColors ?Img.m_info.bmpColors:tmp;
								*lpBuf6=(WORD)tmp;
	
								lpBuf4++;
								lpBuf5++;
								lpBuf6++;
							}
							lpBuf1=(LPBYTE)lpBuf4;
							lpBuf2=(LPBYTE)lpBuf5;
							lpBuf3=(LPBYTE)lpBuf6;
						}
						break;
					case 24:
						{
							WORD	tmp;
							len=common.cx;
							while(len--)
							{
								tmp=(WORD)(*lpBuf1+*lpBuf2);
								tmp=tmp>0xFF?0xFF:tmp;
								*lpBuf3=(BYTE)tmp;
	
								lpBuf1++;
								lpBuf2++;
								lpBuf3++;
							}
						}
						break;
					case 32:
						break;
					default:
						GlobalUnlock(hBuf);
						GlobalUnlock(Img.hBuf);
						GlobalUnlock(RetImg.hBuf);
						return RetImg;
				}
				n=(DWORD)((tail.cx>0)?tail.cx:-tail.cx);
				lpTmpBuf=(tail.cx>0)?lpBuf2:lpBuf1;
				memcpy(lpBuf3,lpTmpBuf,n);

				lpBuf    -=m_info.bmpBytesPerScanLine;
				lpImgBuf -=Img.m_info.bmpBytesPerScanLine;
				lpRetBuf -=RetImg.m_info.bmpBytesPerScanLine;
			}
			if(tail.cy>0)
			{
				lpTmpBuf=lpImgBuf;
				m=tail.cy;
				n=Img.m_info.bmpBytesPerScanLine;
			}
			else
			{
				lpTmpBuf=lpBuf;
				m=-tail.cy;
				n=m_info.bmpBytesPerScanLine;
			}
			for(i=0;i<(int)m;i++)
			{
				lpBuf3=(tail.cy>0)?lpRetBuf:lpRetBuf-ptStart.x;
				memcpy(lpBuf3,lpTmpBuf,n);
				lpTmpBuf-=n;
				lpRetBuf-=RetImg.m_info.bmpBytesPerScanLine;
			}
		}
		else
		{
			i=ptStart.y;
			while(i--)
			{
				memcpy(lpRetBuf,lpBuf,m_info.bmpBytesPerScanLine);
				lpBuf -=m_info.bmpBytesPerScanLine;
				lpRetBuf -=RetImg.m_info.bmpBytesPerScanLine;
			}
			//common.cx=0;
			//common.cy=0;
			for(i=0;i<common.cy;i++)
			{
				lpBuf1=lpBuf,lpBuf2=lpImgBuf,lpBuf3=lpRetBuf,lpTmpBuf;
				memcpy(lpBuf3,lpBuf1,ptStart.x);
				lpBuf1+=ptStart.x;
				lpBuf3+=ptStart.x;
				
				switch(m_info.bmpInfo->bmiHeader.biBitCount)
				{
					case 1:
						break;
					case 4:
						break;
					case 8:
						{
							WORD	tmp;
							len=common.cx;
							while(len--)
							{
								tmp=(WORD)(*lpBuf1+*lpBuf2);
								tmp=tmp>(WORD)m_info.bmpColors ?(WORD)m_info.bmpColors:tmp;
								*lpBuf3=(BYTE)tmp;
	
								lpBuf1++;
								lpBuf2++;
								lpBuf3++;
							}
						}
						break;
					case 16:
						{
							DWORD	tmp;
							LPWORD	lpBuf4=(LPWORD)lpBuf1,
									lpBuf5=(LPWORD)lpBuf2,
									lpBuf6=(LPWORD)lpBuf3;

							len=common.cx/h;
							while(len--)
							{
								tmp=(DWORD)(*lpBuf4+*lpBuf5);
								tmp=tmp>Img.m_info.bmpColors ?Img.m_info.bmpColors:tmp;
								*lpBuf6=(WORD)tmp;
	
								lpBuf4++;
								lpBuf5++;
								lpBuf6++;
							}
							lpBuf1=(LPBYTE)lpBuf4;
							lpBuf2=(LPBYTE)lpBuf5;
							lpBuf3=(LPBYTE)lpBuf6;
						}
						break;
					case 24:
						{
							WORD	tmp;
							len=common.cx;
							while(len--)
							{
								tmp=(WORD)(*lpBuf1+*lpBuf2);
								tmp=tmp>0xFF?0xFF:tmp;
								*lpBuf3=(BYTE)tmp;
	
								lpBuf1++;
								lpBuf2++;
								lpBuf3++;
							}
						}
						break;
					case 32:
						break;
					default:
						GlobalUnlock(hBuf);
						GlobalUnlock(Img.hBuf);
						GlobalUnlock(RetImg.hBuf);
						return RetImg;
				}
				
				n=(DWORD)((tail.cx>0)?tail.cx:-tail.cx);
				lpTmpBuf=(tail.cx>0)?lpBuf2:lpBuf1;
				memcpy(lpBuf3,lpTmpBuf,n);
				/*
				lpTmpBuf=lpImgBuf;
				memcpy(lpRetBuf,lpImgBuf,Img.m_info.bmpBytesPerScanLine);
				*/
				lpBuf    -=m_info.bmpBytesPerScanLine;
				lpImgBuf -=Img.m_info.bmpBytesPerScanLine;
				lpRetBuf -=RetImg.m_info.bmpBytesPerScanLine;
			}
			if(tail.cy>0)
			{
				lpTmpBuf=lpImgBuf;
				m=tail.cy;
				n=Img.m_info.bmpBytesPerScanLine;
			}
			else
			{
				lpTmpBuf=lpBuf;
				m=-tail.cy;
				n=m_info.bmpBytesPerScanLine;
			}
			for(i=0;i<(int)m;i++)
			{
				lpBuf3=(tail.cy>0)?lpRetBuf+ptStart.x:lpRetBuf;
				memcpy(lpBuf3,lpTmpBuf,n);
				lpTmpBuf-=n;
				lpRetBuf-=RetImg.m_info.bmpBytesPerScanLine;
			}
		}
	}


	GlobalUnlock(hBuf);
	GlobalUnlock(Img.hBuf);
	GlobalUnlock(RetImg.hBuf);
	return RetImg;
}
CImage&	CImage::operator += (DWORD k)
{
	if(((m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!IsValid()))
		return *this;

	LPBYTE	lpBuf;
	DWORD	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=dwBufLength;

	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
		return *this;

	k=k>m_info.bmpColors ?m_info.bmpColors:k;
	if(bits==1)
	{
		if(k>=1)
			memset(lpBuf,0xFF,len);
	}
	else if(bits==4)
	{
		BYTE    value,tmp;

		while(len--)
		{
			value=*lpBuf;
			*lpBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp =(BYTE)(tmp+k);
			tmp =(tmp>(BYTE)m_info.bmpColors)?(BYTE)m_info.bmpColors:tmp;
			*lpBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp =(BYTE)(tmp+k);
			tmp =(tmp>(BYTE)m_info.bmpColors)?(BYTE)m_info.bmpColors:tmp;
			tmp =tmp<<4;
			*lpBuf|=tmp;

			lpBuf++;
		}
	}
	else if(bits==8)
	{
		WORD	tmp;

		while(len--)
		{
			tmp=(WORD)(*lpBuf);
			tmp =(WORD)(tmp+k);
			tmp=tmp>(WORD)m_info.bmpColors ?(WORD)m_info.bmpColors:tmp;
			*lpBuf=(BYTE)tmp;

			lpBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD lpTmpBuf=(LPWORD)lpBuf;
		DWORD	   tmp;

		len/=2;
		while(len--)
		{
			tmp=(DWORD)(*lpTmpBuf);
			tmp =(DWORD)(tmp+k);
			tmp=tmp>m_info.bmpColors ?m_info.bmpColors:tmp;
			*lpTmpBuf=(WORD)tmp;

			lpTmpBuf++;

		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);
		WORD	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpBuf++; 
			G = *lpBuf++; 
			R = *lpBuf++; 

			R=(WORD)(R+Red);R=R>0xFF?0xFF:R;
			G=(WORD)(G+Green);G=G>0xFF?0xFF:G;
			B=(WORD)(B+Blue);B=B>0xFF?0xFF:B;

			*(lpBuf-1)=(BYTE)R;
			*(lpBuf-2)=(BYTE)G;
			*(lpBuf-3)=(BYTE)B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(hBuf);
	return *this;

}
CImage& CImage::operator += (CImage& Img)
{
	return *this;

}

CImage	CImage::operator -  (DWORD k)
{
	CImage RetImg;
	if(((m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!IsValid()))
		return RetImg;

	DWORD	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=dwBufLength;
	LPBYTE	lpRetBuf;

	if(!RetImg.SetImage(this))
		return RetImg;
	if((lpRetBuf=(LPBYTE)GlobalLock(RetImg.hBuf))==NULL)
		return RetImg;

	k=k>m_info.bmpColors?m_info.bmpColors:k;
	if(bits==1)
	{
		if(k>=1)
			memset(lpRetBuf,0x00,len);
	}
	else if(bits==4)
	{
		BYTE    value,tmp;

		while(len--)
		{
			value=*lpRetBuf;
			*lpRetBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp =(tmp<(BYTE)k)?0:(BYTE)(tmp-k);
			*lpRetBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp =(tmp<(BYTE)k)?0:(BYTE)(tmp-k);
			tmp =tmp<<4;
			*lpRetBuf|=tmp;

			lpRetBuf++;
		}
	}
	else if(bits==8)
	{
		WORD	tmp;
		
		while(len--)
		{
			tmp=(WORD)(*lpRetBuf);
			tmp =(tmp<(WORD)k)?0:(WORD)(tmp-k);
			*lpRetBuf=(BYTE)tmp;

			lpRetBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD	lpTmpBuf=(LPWORD)lpRetBuf;
		DWORD	tmp;

		len/=2;
		while(len--)
		{
			tmp=(DWORD)(*lpTmpBuf);
			tmp =(tmp<k)?0:(tmp-k);
			*lpTmpBuf=(WORD)tmp;

			lpTmpBuf++;

		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);
		BYTE	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpRetBuf++; 
			G = *lpRetBuf++; 
			R = *lpRetBuf++; 

			R=R<Red?0:R-Red;
			G=G<Green?0:G-Green;
			B=B<Blue?0:B-Blue;

			*(lpRetBuf-1)=R;
			*(lpRetBuf-2)=G;
			*(lpRetBuf-3)=B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(RetImg.hBuf);
	return RetImg;

}
CImage operator -  (DWORD k,CImage& Img)
{
	CImage RetImg;
	if(((Img.m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!Img.IsValid()))
		return RetImg;

	DWORD	bits=Img.m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=Img.dwBufLength;
	LPBYTE	lpRetBuf;

	if(!RetImg.SetImage(&Img))
		return RetImg;
	if((lpRetBuf=(LPBYTE)GlobalLock(RetImg.hBuf))==NULL)
		return RetImg;

	if(bits==1)
	{
		if(k==0)
			memset(lpRetBuf,0x00,len);
		else
		{
			while(len--)
			{
				*lpRetBuf=(*lpRetBuf)^0xFF;
				lpRetBuf++;
			}

		}
	}
	else if(bits==4)
	{
		BYTE    value,tmp;
	
		k=k>0xFF?0xFF:k;
		while(len--)
		{
			value=*lpRetBuf;
			*lpRetBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp =((BYTE)k<tmp)?0:(BYTE)(k-tmp);
			tmp=(tmp>(BYTE)Img.m_info.bmpColors)?(BYTE)Img.m_info.bmpColors:tmp;
			*lpRetBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp =((BYTE)k<tmp)?0:(BYTE)(k-tmp);
			tmp=(tmp>(BYTE)Img.m_info.bmpColors)?(BYTE)Img.m_info.bmpColors:tmp;
			tmp =tmp<<4;
			*lpRetBuf|=tmp;

			lpRetBuf++;
		}
	}
	else if(bits==8)
	{
		WORD	tmp;
		
		k=k>0xFFFF?0xFFFF:k;
		while(len--)
		{
			tmp=(WORD)(*lpRetBuf);
			tmp =((WORD)k<tmp)?0:(WORD)(k-tmp);
			tmp=tmp>(WORD)Img.m_info.bmpColors ?(WORD)Img.m_info.bmpColors:tmp;
			*lpRetBuf=(BYTE)tmp;

			lpRetBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD lpTmpBuf=(LPWORD)lpRetBuf;
		DWORD	   tmp;

		k=k>0xFFFFFFFF?0xFFFFFFFF:k;
		len/=2;
		while(len--)
		{
			tmp=(DWORD)(*lpTmpBuf);
			tmp =(k<tmp)?0:(k-tmp);
			tmp=tmp>Img.m_info.bmpColors ?Img.m_info.bmpColors:tmp;
			*lpTmpBuf=(WORD)tmp;

			lpTmpBuf++;

		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);
		BYTE	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpRetBuf++; 
			G = *lpRetBuf++; 
			R = *lpRetBuf++; 

			R=R<Red?0:Red-R;
			G=G<Green?0:Green-G;
			B=B<Blue?0:Blue-B;

			*(lpRetBuf-1)=R;
			*(lpRetBuf-2)=G;
			*(lpRetBuf-3)=B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(RetImg.hBuf);
	return RetImg;

}
CImage CImage::operator -  (CImage& Img)
{
	CImage RetImg;
	return RetImg;

}
CImage&	CImage::operator -= (DWORD k)
{
	if(((m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!IsValid()))
		return *this;

	DWORD	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=dwBufLength;
	LPBYTE	lpBuf;
	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
		return *this;

	k=k>m_info.bmpColors?m_info.bmpColors:k;
	if(bits==1)
	{
		if(k>=1)
			memset(lpBuf,0x00,len);
	}
	else if(bits==4)
	{
		BYTE    value,tmp;

		while(len--)
		{
			value=*lpBuf;
			*lpBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp =(tmp<(BYTE)k)?0:(BYTE)(tmp-k);
			*lpBuf=value|tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp =(tmp<(BYTE)k)?0:(BYTE)(tmp-k);
			tmp =tmp<<4;
			*lpBuf|=tmp;

			lpBuf++;
		}
	}
	else if(bits==8)
	{
		WORD	tmp;

		while(len--)
		{
			tmp=(WORD)(*lpBuf);
			tmp =(tmp<(WORD)k)?0:(WORD)(tmp-k);
			*lpBuf=(BYTE)tmp;

			lpBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD	lpTmpBuf=(LPWORD)lpBuf;
		DWORD	tmp;

		len/=2;
		while(len--)
		{
			tmp=(DWORD)(*lpTmpBuf);
			tmp =(tmp<k)?0:(tmp-k);
			*lpTmpBuf=(WORD)tmp;

			lpTmpBuf++;
		}
	}
	else if(bits==24)
	{
		k=RGB(23,20,15);
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);       
		BYTE	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpBuf++; 
			G = *lpBuf++; 
			R = *lpBuf++; 

			R=R<Red?0:R-Red;
			G=G<Green?0:G-Green;
			B=B<Blue?0:B-Blue;

			*(lpBuf-1)=R;
			*(lpBuf-2)=G;
			*(lpBuf-3)=B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(hBuf);
	return *this;

}
CImage& CImage::operator -= (CImage& Img)
{
	return *this;

}

CImage	CImage::operator *  (DWORD k)
{
	CImage RetImg;
	if(((m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!IsValid()))
		return RetImg;

	DWORD	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=dwBufLength;
	LPBYTE	lpRetBuf;

	if(!RetImg.SetImage(this))
		return RetImg;
	if((lpRetBuf=(LPBYTE)GlobalLock(RetImg.hBuf))==NULL)
		return RetImg;

	k=k>m_info.bmpColors?m_info.bmpColors:k;
	if(bits==1)
	{
		if(k==0)
			memset(lpRetBuf,0x00,len);
	}
	else if(bits==4)
	{
		BYTE    value,tmp;
	
		while(len--)
		{
			value=*lpRetBuf;
			*lpRetBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp =(BYTE)(tmp*k);
			tmp =(tmp>(BYTE)m_info.bmpColors)?(tmp>>4):tmp;//Xu ly tran so
			*lpRetBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp =(BYTE)(tmp*k);
			tmp =(tmp>(BYTE)m_info.bmpColors)?(tmp>>4):tmp;//xu ly tran so
			tmp =tmp<<4;
			*lpRetBuf|=tmp;

			lpRetBuf++;
		}
	}
	else if(bits==8)
	{
		WORD	tmp;

		while(len--)
		{
			tmp=(WORD)(*lpRetBuf);
			tmp =(WORD)(tmp*k);
			tmp =(tmp>(WORD)m_info.bmpColors)?(tmp>>8):tmp;//Xu ly trn so
			*lpRetBuf=(BYTE)tmp;

			lpRetBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD lpTmpBuf=(LPWORD)lpRetBuf;
		DWORD	   tmp;

		len/=2;
		while(len--)
		{
			tmp=(DWORD)(*lpTmpBuf);
			tmp*=(DWORD)k;
			tmp =(tmp>m_info.bmpColors)?(tmp>>16):tmp;
			*lpTmpBuf=(WORD)tmp;

			lpTmpBuf++;

		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);       
		WORD	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpRetBuf++; 
			G = *lpRetBuf++; 
			R = *lpRetBuf++; 

			R=(WORD)(R*Red);R=R>0xFF?0xFF:R;
			G=(WORD)(G*Green);G=G>0xFF?0xFF:G;
			B=(WORD)(B*Blue);B=B>0xFF?0xFF:B;

			*(lpRetBuf-1)=(BYTE)R;
			*(lpRetBuf-2)=(BYTE)G;
			*(lpRetBuf-3)=(BYTE)B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(RetImg.hBuf);
	return RetImg;
}
CImage operator *  (DWORD k,CImage& Img)
{
	CImage RetImg;
	if(((Img.m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!Img.IsValid()))
		return RetImg;

	DWORD	bits=Img.m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=Img.dwBufLength;
	LPBYTE	lpRetBuf;

	if(!RetImg.SetImage(&Img))
		return RetImg;
	if((lpRetBuf=(LPBYTE)GlobalLock(RetImg.hBuf))==NULL)
		return RetImg;

	k=k>Img.m_info.bmpColors?Img.m_info.bmpColors:k;
	if(bits==1)
	{
		if(k==0)
			memset(lpRetBuf,0x00,len);
	}
	else if(bits==4)
	{
		BYTE    value,tmp;
	
		while(len--)
		{
			value=*lpRetBuf;
			*lpRetBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp =(BYTE)(tmp*k);
			tmp =(tmp>(BYTE)Img.m_info.bmpColors)?(tmp>>4):tmp;//Xu ly tran so
			*lpRetBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp =(BYTE)(tmp*k);
			tmp =(tmp>(BYTE)Img.m_info.bmpColors)?(tmp>>4):tmp;//xu ly tran so
			tmp =tmp<<4;
			*lpRetBuf|=tmp;

			lpRetBuf++;
		}
	}
	else if(bits==8)
	{
		WORD	tmp;
		
		while(len--)
		{
			tmp=(WORD)(*lpRetBuf);
			tmp =(WORD)(tmp*k);
			tmp =(tmp>(WORD)Img.m_info.bmpColors)?(tmp>>8):tmp;//Xu ly trn so
			*lpRetBuf=(BYTE)tmp;

			lpRetBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD	lpTmpBuf=(LPWORD)lpRetBuf;
		DWORD	tmp;

		len/=2;
		while(len--)
		{
			tmp=(DWORD)(*lpTmpBuf);
			tmp*=(DWORD)k;
			tmp =(tmp>Img.m_info.bmpColors)?(tmp>>16):tmp;
			*lpTmpBuf=(WORD)tmp;

			lpTmpBuf++;

		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);       
		WORD	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpRetBuf++; 
			G = *lpRetBuf++; 
			R = *lpRetBuf++; 

			R=(WORD)(R*Red);R=R>0xFF?0xFF:R;
			G=(WORD)(G*Green);G=G>0xFF?0xFF:G;
			B=(WORD)(B*Blue);B=B>0xFF?0xFF:B;

			*(lpRetBuf-1)=(BYTE)R;
			*(lpRetBuf-2)=(BYTE)G;
			*(lpRetBuf-3)=(BYTE)B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(RetImg.hBuf);
	return RetImg;

}
CImage CImage::operator *  (CImage& Img)
{
	CImage RetImg;
	return RetImg;

}
CImage&	CImage::operator *= (DWORD k)
{
	if(((m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!IsValid()))
		return *this;

	DWORD	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=dwBufLength;
	LPBYTE	lpBuf;

	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
		return *this;

	k=k>m_info.bmpColors?m_info.bmpColors:k;
	if(bits==1)
	{
		if(k==0)
			memset(lpBuf,0x00,len);
	}
	else if(bits==4)
	{
		BYTE    value,tmp;

		while(len--)
		{
			value=*lpBuf;
			*lpBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp =(BYTE)(tmp*k);
			tmp =(tmp>(BYTE)m_info.bmpColors)?(tmp>>4):tmp;//Xu ly tran so
			*lpBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp =(BYTE)(tmp*k);
			tmp =(tmp>(BYTE)m_info.bmpColors)?(tmp>>4):tmp;//xu ly tran so
			tmp =tmp<<4;
			*lpBuf|=tmp;

			lpBuf++;
		}
	}
	else if(bits==8)
	{
		WORD	tmp;
		
		while(len--)
		{
			tmp=(WORD)(*lpBuf);
			tmp =(WORD)(tmp*k);
			tmp =(tmp>(WORD)m_info.bmpColors)?(tmp>>8):tmp;//Xu ly trn so
			*lpBuf=(BYTE)tmp;

			lpBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD	lpTmpBuf=(LPWORD)lpBuf;
		DWORD	tmp;

		len/=2;
		while(len--)
		{
			tmp=(DWORD)(*lpTmpBuf);
			tmp=(DWORD)(tmp*k);
			tmp =(tmp>m_info.bmpColors)?(tmp>>16):tmp;
			*lpTmpBuf=(WORD)tmp;

			lpTmpBuf++;
		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);       
		WORD	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpBuf++; 
			G = *lpBuf++; 
			R = *lpBuf++; 

			R=(WORD)(R*Red);R=R>0xFF?0xFF:R;
			G=(WORD)(G*Green);G=G>0xFF?0xFF:G;
			B=(WORD)(B*Blue);B=B>0xFF?0xFF:B;

			*(lpBuf-1)=(BYTE)R;
			*(lpBuf-2)=(BYTE)G;
			*(lpBuf-3)=(BYTE)B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(hBuf);
	return *this;
}
CImage& CImage::operator *= (CImage& Img)
{
	return *this;

}

CImage	CImage::operator /  (DWORD k)
{
	CImage RetImg;
	if(((m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!IsValid())||(k==0))
		return RetImg;

	DWORD	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=dwBufLength;
	LPBYTE	lpRetBuf;

	if(!RetImg.SetImage(this))
		return RetImg;
	if((lpRetBuf=(LPBYTE)GlobalLock(RetImg.hBuf))==NULL)
		return RetImg;

	if(bits==1)
	{
		if(k>1)
			memset(lpRetBuf,0x00,len);
	}
	else if(bits==4)
	{
		BYTE    value,tmp;
	
		while(len--)
		{
			value=*lpRetBuf;
			*lpRetBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp =(BYTE)(tmp/k);
			*lpRetBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp =(BYTE)(tmp/k);
			tmp =tmp<<4;
			*lpRetBuf|=tmp;

			lpRetBuf++;
		}
	}
	else if(bits==8)
	{
		WORD	tmp;

		while(len--)
		{
			tmp=(WORD)(*lpRetBuf);
			tmp =(WORD)(tmp/k);
			*lpRetBuf=(BYTE)tmp;

			lpRetBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD	lpTmpBuf=(LPWORD)lpRetBuf;
		DWORD	tmp;

		len/=2;
		while(len--)
		{
			tmp=(DWORD)(*lpTmpBuf);
			tmp=(DWORD)(k/tmp);
			*lpTmpBuf=(WORD)tmp;

			lpTmpBuf++;
		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);       
		BYTE	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpRetBuf++; 
			G = *lpRetBuf++; 
			R = *lpRetBuf++; 

			R /=Red;
			G /=Green;
			B /=Blue;

			*(lpRetBuf-1)=R;
			*(lpRetBuf-2)=G;
			*(lpRetBuf-3)=B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(RetImg.hBuf);
	return RetImg;

}
CImage operator /  (DWORD k,CImage& Img)
{
	CImage RetImg;
	if(((Img.m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!Img.IsValid()))
		return RetImg;

	DWORD	bits=Img.m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=Img.dwBufLength;
	LPBYTE	lpRetBuf;

	if(!RetImg.SetImage(&Img))
		return RetImg;
	if((lpRetBuf=(LPBYTE)GlobalLock(RetImg.hBuf))==NULL)
		return RetImg;

	if(bits==1)
	{
		if(k==0)
			memset(lpRetBuf,0x00,len);
	}
	else if(bits==4)
	{
		BYTE    value,tmp;
	
		while(len--)
		{
			value=*lpRetBuf;
			*lpRetBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			if(tmp!=0)
			{
				tmp =(BYTE)(k/tmp);
				tmp =(tmp>(BYTE)Img.m_info.bmpColors)?(tmp>>4):tmp;//Xu ly tran so
			}
			*lpRetBuf|=tmp;

			tmp =value>>4;    //lap 4 bits cao
			if(tmp!=0)
			{
				tmp =(BYTE)(k/tmp);
				tmp =(tmp>(BYTE)Img.m_info.bmpColors)?(tmp>>4):tmp;//xu ly tran so
			}
			tmp =tmp<<4;
			*lpRetBuf|=tmp;

			lpRetBuf++;
		}
	}
	else if(bits==8)
	{
		WORD	tmp;

		while(len--)
		{
			tmp=(WORD)(*lpRetBuf);
			if(tmp!=0)
			{
				tmp =(WORD)(k/tmp);
				tmp =(tmp>(WORD)Img.m_info.bmpColors)?(tmp>>8):tmp;//Xu ly trn so
			}
			*lpRetBuf=(BYTE)tmp;

			lpRetBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD	lpTmpBuf=(LPWORD)lpRetBuf;
		DWORD	tmp;

		len/=2;
		while(len--)
		{
			tmp=(DWORD)(*lpTmpBuf);
			if(tmp!=0)
			{
				tmp=(DWORD)(k/tmp);
				tmp =(tmp>Img.m_info.bmpColors)?(tmp>>16):tmp;
			}
			*lpTmpBuf=(WORD)tmp;

			lpTmpBuf++;
		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);       
		BYTE	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpRetBuf++; 
			G = *lpRetBuf++; 
			R = *lpRetBuf++; 

			R =Red/R;
			G =Green/G;
			B =Blue/B;

			*(lpRetBuf-1)=R;
			*(lpRetBuf-2)=G;
			*(lpRetBuf-3)=B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(RetImg.hBuf);
	return RetImg;

}
CImage CImage::operator /  (CImage& Img)
{
	CImage RetImg;
	return RetImg;

}
CImage&	CImage::operator /= (DWORD k)
{
	if(((m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!IsValid())||(k==0))
		return *this;

	DWORD	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=dwBufLength;
	LPBYTE	lpBuf;
	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
		return *this;

	if(bits==1)
	{
		if(k>1)
			memset(lpBuf,0x00,len);
	}
	else if(bits==4)
	{
		BYTE    value,tmp;
	
		while(len--)
		{
			value=*lpBuf;
			*lpBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp =(BYTE)(tmp/k);
			*lpBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp =(BYTE)(tmp/k);
			tmp =tmp<<4;
			*lpBuf|=tmp;

			lpBuf++;
		}
	}
	else if(bits==8)
	{
		WORD	tmp;

		while(len--)
		{
			tmp=(WORD)(*lpBuf);
			tmp =(WORD)(tmp/k);
			*lpBuf=(BYTE)tmp;

			lpBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD lpTmpBuf=(LPWORD)lpBuf;
		DWORD  tmp;

		
		len/=2;
		while(len--)
		{
			tmp=(DWORD)(*lpTmpBuf);
			tmp=(DWORD)(tmp/k);
			*lpTmpBuf=(WORD)tmp;

			lpTmpBuf++;

		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);       
		BYTE	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpBuf++; 
			G = *lpBuf++; 
			R = *lpBuf++; 

			R /=Red;
			G /=Green;
			B /=Blue;

			*(lpBuf-1)=R;
			*(lpBuf-2)=G;
			*(lpBuf-3)=B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(hBuf);
	return *this;
}
CImage& CImage::operator /= (CImage& Img)
{
	return *this;
}

CImage&	CImage::operator ~  ()
{
	if(((m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!IsValid()))
		return *this;

	DWORD	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=dwBufLength;

	//if(bits==32)
		//return *this;

	LPBYTE lpBuf;
	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
			return *this;

	while(len--)
	{
		*lpBuf=~(*lpBuf);
		lpBuf++;
	}

	GlobalUnlock(hBuf);
	return *this;

}

CImage	CImage::operator &  (DWORD k)
{
	CImage RetImg;
	if(((m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!IsValid()))
		return RetImg;

	DWORD	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=dwBufLength;
	LPBYTE	lpRetBuf;

	if(!RetImg.SetImage(this))
		return RetImg;
	if((lpRetBuf=(LPBYTE)GlobalLock(RetImg.hBuf))==NULL)
		return RetImg;

	if(bits==1)
	{
		if(k==0)
			memset(lpRetBuf,0x00,len);

	}
	else if(bits==4)
	{
		BYTE    value,tmp;

		while(len--)
		{
			value=*lpRetBuf;
			*lpRetBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp &=(BYTE)k;
			tmp&=0x0F;
			*lpRetBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp &=(BYTE)k;
			tmp =tmp<<4;
			*lpRetBuf|=tmp;

			lpRetBuf++;
		}
	}
	else if(bits==8)
	{
		BYTE	tmp;

		while(len--)
		{
			tmp=*lpRetBuf;
			tmp &=(BYTE)k;
			*lpRetBuf=tmp;

			lpRetBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD	lpTmpBuf=(LPWORD)lpRetBuf;
		WORD    tmp;

		len/=2;
		while(len--)
		{
			tmp=*lpTmpBuf;
			tmp &=(WORD)k;
			*lpTmpBuf=tmp;

			lpTmpBuf++;
		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);       
		BYTE	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpRetBuf++; 
			G = *lpRetBuf++; 
			R = *lpRetBuf++; 

			R &=Red;
			G &=Green;
			B &=Blue;

			*(lpRetBuf-1)=R;
			*(lpRetBuf-2)=G;
			*(lpRetBuf-3)=B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(RetImg.hBuf);
	return RetImg;

}
CImage operator &  (DWORD k,CImage& Img)
{
	CImage RetImg;
	if(((Img.m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!Img.IsValid()))
		return RetImg;

	DWORD	bits=Img.m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=Img.dwBufLength;
	LPBYTE	lpRetBuf;

	if(!RetImg.SetImage(&Img))
		return RetImg;
	if((lpRetBuf=(LPBYTE)GlobalLock(RetImg.hBuf))==NULL)
		return RetImg;

	if(bits==1)
	{
		if(k==0)
			memset(lpRetBuf,0x00,len);
	}
	else if(bits==4)
	{
		BYTE    value,tmp;

		while(len--)
		{
			value=*lpRetBuf;
			*lpRetBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp =(BYTE)k&tmp;
			tmp&=0x0F;
			*lpRetBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp =(BYTE)k&tmp;
			tmp =tmp<<4;
			*lpRetBuf|=tmp;

			lpRetBuf++;
		}
	}
	else if(bits==8)
	{
		BYTE	tmp;

		while(len--)
		{
			tmp=*lpRetBuf;
			tmp =(BYTE)k&tmp;
			*lpRetBuf=tmp;

			lpRetBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD	lpTmpBuf=(LPWORD)lpRetBuf;
		WORD    tmp;

		len/=2;
		while(len--)
		{
			tmp=*lpTmpBuf;
			tmp =(WORD)k&tmp;
			*lpTmpBuf=tmp;

			lpTmpBuf++;
		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);       
		BYTE	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpRetBuf++; 
			G = *lpRetBuf++; 
			R = *lpRetBuf++; 

			R &=Red;
			G &=Green;
			B &=Blue;

			*(lpRetBuf-1)=R;
			*(lpRetBuf-2)=G;
			*(lpRetBuf-3)=B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(RetImg.hBuf);
	return RetImg;

}
CImage CImage::operator &  (CImage& Img)
{
	CImage RetImg;
	return RetImg;

}
CImage&	CImage::operator &= (DWORD k)
{
	if(((m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!IsValid()))
		return *this;

	DWORD	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=dwBufLength;
	LPBYTE	lpBuf;
	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
		return *this;

	if(bits==1)
	{
		if(k==0)
			memset(lpBuf,0x00,len);
	}
	else if(bits==4)
	{
		BYTE    value,tmp;
	
		while(len--)
		{
			value=*lpBuf;
			*lpBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp &=(BYTE)k;
			tmp&=0x0F;
			*lpBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp &=(BYTE)k;
			tmp =tmp<<4;
			*lpBuf|=tmp;

			lpBuf++;
		}
	}
	else if(bits==8)
	{
		BYTE	tmp;

		while(len--)
		{
			tmp=*lpBuf;
			tmp &=(BYTE)k;
			*lpBuf=tmp;

			lpBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD	lpTmpBuf=(LPWORD)lpBuf;
		WORD    tmp;

		len/=2;
		while(len--)
		{
			tmp=*lpTmpBuf;
			tmp &=(WORD)k;
			*lpTmpBuf=tmp;

			lpTmpBuf++;
		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);       
		BYTE	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpBuf++; 
			G = *lpBuf++; 
			R = *lpBuf++; 

			R &=Red;
			G &=Green;
			B &=Blue;

			*(lpBuf-1)=R;
			*(lpBuf-2)=G;
			*(lpBuf-3)=B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(hBuf);
	return *this;
}
CImage& CImage::operator &= (CImage& Img)
{
	return *this;
}

CImage	CImage::operator |  (DWORD k)
{
	CImage RetImg;
	if(((m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!IsValid()))
		return RetImg;

	DWORD	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=dwBufLength;
	LPBYTE	lpRetBuf;

	if(!RetImg.SetImage(this))
		return RetImg;
	if((lpRetBuf=(LPBYTE)GlobalLock(RetImg.hBuf))==NULL)
		return RetImg;

	if(bits==1)
	{
		if(k>=1)
			memset(lpRetBuf,0xFF,len);
	}
	else if(bits==4)
	{
		BYTE    value,tmp;

		while(len--)
		{
			value=*lpRetBuf;
			*lpRetBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp |=(BYTE)k;
			tmp&=0x0F;
			*lpRetBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp |=(BYTE)k;
			tmp =tmp<<4;
			*lpRetBuf|=tmp;

			lpRetBuf++;
		}
	}
	else if(bits==8)
	{
		BYTE	tmp;

		while(len--)
		{
			tmp=*lpRetBuf;
			tmp |=(BYTE)k;
			*lpRetBuf=tmp;

			lpRetBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD	lpTmpBuf=(LPWORD)lpRetBuf;
		WORD    tmp;

		len/=2;
		while(len--)
		{
			tmp=*lpTmpBuf;
			tmp |=(WORD)k;
			*lpTmpBuf=tmp;

			lpTmpBuf++;
		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);       
		BYTE	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpRetBuf++; 
			G = *lpRetBuf++; 
			R = *lpRetBuf++; 

			R |=Red;
			G |=Green;
			B |=Blue;

			*(lpRetBuf-1)=R;
			*(lpRetBuf-2)=G;
			*(lpRetBuf-3)=B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(RetImg.hBuf);
	return RetImg;

}
CImage operator |  (DWORD k,CImage& Img)
{
	CImage RetImg;
	if(((Img.m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!Img.IsValid()))
		return RetImg;

	DWORD	bits=Img.m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=Img.dwBufLength;
	LPBYTE	lpRetBuf;

	if(!RetImg.SetImage(&Img))
		return RetImg;
	if((lpRetBuf=(LPBYTE)GlobalLock(RetImg.hBuf))==NULL)
		return RetImg;

	if(bits==1)
	{
		if(k>=1)
			memset(lpRetBuf,0xFF,len);
	}
	else if(bits==4)
	{
		BYTE    value,tmp;

		while(len--)
		{
			value=*lpRetBuf;
			*lpRetBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp =(BYTE)k|tmp;
			tmp&=0x0F;
			*lpRetBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp =(BYTE)k|tmp;
			tmp =tmp<<4;
			*lpRetBuf|=tmp;

			lpRetBuf++;
		}
	}
	else if(bits==8)
	{
		BYTE	tmp;

		while(len--)
		{
			tmp=*lpRetBuf;
			tmp =(BYTE)k|tmp;
			*lpRetBuf=tmp;

			lpRetBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD	lpTmpBuf=(LPWORD)lpRetBuf;
		WORD    tmp;

		len/=2;
		while(len--)
		{
			tmp=*lpTmpBuf;
			tmp =(WORD)k|tmp;
			*lpTmpBuf=tmp;

			lpTmpBuf++;
		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);       
		BYTE	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpRetBuf++; 
			G = *lpRetBuf++; 
			R = *lpRetBuf++; 

			R |=Red;
			G |=Green;
			B |=Blue;

			*(lpRetBuf-1)=R;
			*(lpRetBuf-2)=G;
			*(lpRetBuf-3)=B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(RetImg.hBuf);
	return RetImg;

}
CImage CImage::operator |  (CImage& Img)
{
	CImage RetImg;
	return RetImg;

}
CImage&	CImage::operator |= (DWORD k)
{
	if(((m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!IsValid()))
		return *this;

	DWORD	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=dwBufLength;
	LPBYTE	lpBuf;
	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
		return *this;

	if(bits==1)
	{
		if(k==0)
			memset(lpBuf,0x00,len);
	}
	else if(bits==4)
	{
		BYTE    value,tmp;

		while(len--)
		{
			value=*lpBuf;
			*lpBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp |=(BYTE)k;
			tmp&=0x0F;
			*lpBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp |=(BYTE)k;
			tmp =tmp<<4;
			*lpBuf|=tmp;

			lpBuf++;
		}
	}
	else if(bits==8)
	{
		BYTE	tmp;

		while(len--)
		{
			tmp=*lpBuf;
			tmp |=(BYTE)k;
			*lpBuf=tmp;

			lpBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD	lpTmpBuf=(LPWORD)lpBuf;
		WORD    tmp;

		len/=2;
		while(len--)
		{
			tmp=*lpTmpBuf;
			tmp |=(WORD)k;
			*lpTmpBuf=tmp;

			lpTmpBuf++;
		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);       
		BYTE	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpBuf++; 
			G = *lpBuf++; 
			R = *lpBuf++; 

			R |=Red;
			G |=Green;
			B |=Blue;

			*(lpBuf-1)=R;
			*(lpBuf-2)=G;
			*(lpBuf-3)=B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(hBuf);
	return *this;
}
CImage& CImage::operator |= (CImage& Img)
{
	return *this;
}

CImage	CImage::operator ^  (DWORD k)
{
	CImage RetImg;
	if(((m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!IsValid()))
		return RetImg;

	DWORD	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=dwBufLength;
	LPBYTE	lpRetBuf;

	if(!RetImg.SetImage(this))
		return RetImg;
	if((lpRetBuf=(LPBYTE)GlobalLock(RetImg.hBuf))==NULL)
		return RetImg;

	if(bits==1)
	{
		if(k==0)
			return RetImg;
		while(len--)
		{
			*lpRetBuf=*lpRetBuf^0xFF;
			lpRetBuf++;
		}
	}
	else if(bits==4)
	{
		BYTE    value,tmp;

		while(len--)
		{
			value=*lpRetBuf;
			*lpRetBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp ^=(BYTE)k;
			tmp&=0x0F;
			*lpRetBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp ^=(BYTE)k;
			tmp =tmp<<4;
			*lpRetBuf|=tmp;

			lpRetBuf++;
		}
	}
	else if(bits==8)
	{
		BYTE	tmp;

		while(len--)
		{
			tmp=*lpRetBuf;
			tmp ^=(BYTE)k;
			*lpRetBuf=tmp;

			lpRetBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD	lpTmpBuf=NULL;
		WORD    tmp;

		len/=2;
		while(len--)
		{
			tmp=*lpTmpBuf;
			tmp ^=(WORD)k;
			*lpTmpBuf=tmp;

			lpTmpBuf++;
		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);       
		BYTE	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpRetBuf++; 
			G = *lpRetBuf++; 
			R = *lpRetBuf++; 

			R ^=Red;
			G ^=Green;
			B ^=Blue;

			*(lpRetBuf-1)=R;
			*(lpRetBuf-2)=G;
			*(lpRetBuf-3)=B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(RetImg.hBuf);
	return RetImg;
}
CImage operator ^  (DWORD k,CImage& Img)
{
	CImage RetImg;
	if(((Img.m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!Img.IsValid()))
		return RetImg;

	DWORD	bits=Img.m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=Img.dwBufLength;
	LPBYTE	lpRetBuf;

	if(!RetImg.SetImage(&Img))
		return RetImg;
	if((lpRetBuf=(LPBYTE)GlobalLock(RetImg.hBuf))==NULL)
		return RetImg;

	if(bits==1)
	{
		if(k==0)
			return RetImg;

		while(len--)
		{
			*lpRetBuf=0xFF^(*lpRetBuf);
			lpRetBuf++;
		}


	}
	else if(bits==4)
	{
		BYTE    value,tmp;

		while(len--)
		{
			value=*lpRetBuf;
			*lpRetBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp =(BYTE)k^tmp;
			tmp&=0x0F;
			*lpRetBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp =(BYTE)k^tmp;
			tmp =tmp<<4;
			*lpRetBuf|=tmp;

			lpRetBuf++;
		}
	}
	else if(bits==8)
	{
		BYTE	tmp;

		while(len--)
		{
			tmp=*lpRetBuf;
			tmp =(BYTE)k^tmp;
			*lpRetBuf=tmp;

			lpRetBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD	lpTmpBuf=(LPWORD)lpRetBuf;
		WORD    tmp;

		len/=2;
		while(len--)
		{
			tmp=*lpTmpBuf;
			tmp =(WORD)k^tmp;
			*lpTmpBuf=tmp;

			lpTmpBuf++;
		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);       
		BYTE	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpRetBuf++; 
			G = *lpRetBuf++; 
			R = *lpRetBuf++; 

			R ^=Red;
			G ^=Green;
			B ^=Blue;

			*(lpRetBuf-1)=R;
			*(lpRetBuf-2)=G;
			*(lpRetBuf-3)=B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(RetImg.hBuf);
	return RetImg;
}
CImage CImage::operator ^  (CImage& Img)
{
	CImage RetImg;
	return RetImg;

}
CImage&	CImage::operator ^= (DWORD k)
{
	if(((m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!IsValid()))
		return *this;

	DWORD	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=dwBufLength;
	LPBYTE	lpBuf;
	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
		return *this;

	if(bits==1)
	{
		if(k==0)
			return *this;
		while(len--)
		{
			*lpBuf=*lpBuf^0xFF;
			lpBuf++;
		}
	}
	else if(bits==4)
	{
		BYTE    value,tmp;

		while(len--)
		{
			value=*lpBuf;
			*lpBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp ^=(BYTE)k;
			tmp&=0x0F;
			*lpBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp ^=(BYTE)k;
			tmp =tmp<<4;
			*lpBuf|=tmp;

			lpBuf++;
		}
	}
	else if(bits==8)
	{
		BYTE	tmp;

		while(len--)
		{
			tmp=*lpBuf;
			tmp ^=(BYTE)k;
			*lpBuf=tmp;

			lpBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD	lpTmpBuf=(LPWORD)lpBuf;
		WORD    tmp;

		len/=2;
		while(len--)
		{
			tmp=*lpTmpBuf;
			tmp ^=(WORD)k;
			*lpTmpBuf=tmp;

			lpTmpBuf++;
		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);       
		BYTE	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpBuf++; 
			G = *lpBuf++; 
			R = *lpBuf++; 

			R ^=Red;
			G ^=Green;
			B ^=Blue;

			*(lpBuf-1)=R;
			*(lpBuf-2)=G;
			*(lpBuf-3)=B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(hBuf);
	return *this;
}
CImage& CImage::operator ^= (CImage& Img)
{
	return *this;
}

CImage	Min(CImage& Img,DWORD k)
{
	CImage RetImg;
	if(((Img.m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!Img.IsValid()))
		return RetImg;

	DWORD	bits=Img.m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=Img.dwBufLength;
	LPBYTE	lpRetBuf;

	if(!RetImg.SetImage(&Img))
		return RetImg;
	if((lpRetBuf=(LPBYTE)GlobalLock(RetImg.hBuf))==NULL)
		return RetImg;

	if(bits==1)
	{
		if(k==0)
			memset(lpRetBuf,0x00,len);
	}
	else if(bits==4)
	{
		BYTE    value,tmp;

		while(len--)
		{
			value=*lpRetBuf;
			*lpRetBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp=(BYTE)(((DWORD)tmp>k)?k:tmp);
			*lpRetBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp=(BYTE)(((DWORD)tmp>k)?k:tmp);
			tmp =tmp<<4;
			*lpRetBuf=(*lpRetBuf)|tmp;

			lpRetBuf++;
		}
	}
	else if(bits==8)
	{
		BYTE	tmp;

		while(len--)
		{
			tmp=*lpRetBuf;
			tmp=(BYTE)(((DWORD)tmp>k)?k:tmp);
			*lpRetBuf=tmp;

			lpRetBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD	lpTmpBuf=(LPWORD)lpRetBuf;
		WORD	tmp;

		len/=2;
		while(len--)
		{
			tmp=*lpTmpBuf;
			tmp=(WORD)(((DWORD)tmp>k)?k:tmp);
			*lpTmpBuf=tmp;

			lpTmpBuf++;
		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);       
		BYTE	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpRetBuf++; 
			G = *lpRetBuf++; 
			R = *lpRetBuf++; 

			R =R<Red?R:Red;
			G =G<Green?G:Green;
			B =B<Blue?B:Blue;

			*(lpRetBuf-1)=R;
			*(lpRetBuf-2)=G;
			*(lpRetBuf-3)=B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(RetImg.hBuf);
	return RetImg;
}
CImage Min(CImage& Img1,CImage& Img2)
{
	CImage RetImg;
	return RetImg;

}

CImage	Max(CImage& Img,DWORD k)
{
	CImage RetImg;
	if(((Img.m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!Img.IsValid()))
		return RetImg;

	DWORD	bits=Img.m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=Img.dwBufLength;
	LPBYTE	lpRetBuf;

	if(!RetImg.SetImage(&Img))
		return RetImg;
	if((lpRetBuf=(LPBYTE)GlobalLock(RetImg.hBuf))==NULL)
		return RetImg;

	k=k>Img.m_info.bmpColors?Img.m_info.bmpColors:k;
	if(bits==1)
	{
		if(k>=1)
			memset(lpRetBuf,0xFF,len);
	}
	else if(bits==4)
	{
		BYTE    value,tmp;

		while(len--)
		{
			value=*lpRetBuf;
			*lpRetBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp=(BYTE)(((DWORD)tmp<k)?k:tmp);
			*lpRetBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp=(BYTE)(((DWORD)tmp<k)?k:tmp);
			tmp =tmp<<4;
			*lpRetBuf=(*lpRetBuf)|tmp;

			lpRetBuf++;
		}
	}
	else if(bits==8)
	{
		BYTE	tmp;

		while(len--)
		{
			tmp=*lpRetBuf;
			tmp=(BYTE)(((DWORD)tmp<k)?k:tmp);
			*lpRetBuf=tmp;

			lpRetBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD	lpTmpBuf=(LPWORD)lpRetBuf;
		WORD	tmp;

		len/=2;
		while(len--)
		{
			tmp=*lpTmpBuf;
			tmp=(WORD)(((DWORD)tmp<k)?k:tmp);
			*lpTmpBuf=tmp;

			lpTmpBuf++;
		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);       
		BYTE	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpRetBuf++; 
			G = *lpRetBuf++; 
			R = *lpRetBuf++; 

			R =R>Red?R:Red;
			G =G>Green?G:Green;
			B =B>Blue?B:Blue;

			*(lpRetBuf-1)=R;
			*(lpRetBuf-2)=G;
			*(lpRetBuf-3)=B;
		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(RetImg.hBuf);
	return RetImg;

}
CImage Max(CImage& Img1,CImage& Img2)
{
	CImage RetImg;
	return RetImg;

}

CImage	Abs(CImage& Img,DWORD k)
{
	CImage RetImg;
	if(((Img.m_info.bmpInfo->bmiHeader.biCompression&(BI_RLE4|BI_RLE8))
		==(BI_RLE4|BI_RLE8))||(!Img.IsValid()))
		return RetImg;

	DWORD	bits=Img.m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=Img.dwBufLength;
	LPBYTE	lpRetBuf;

	if(!RetImg.SetImage(&Img))
		return RetImg;
	if((lpRetBuf=(LPBYTE)GlobalLock(RetImg.hBuf))==NULL)
		return RetImg;

	if(bits==1)
	{
		if(k==1)
		{
			while(len--)
			{
				*lpRetBuf=(*lpRetBuf)^0xFF;
				lpRetBuf++;
			}
		}
	}
	else if(bits==4)
	{
		BYTE    value,tmp;

		k=k>0xFF?0xFF:k;
		while(len--)
		{
			value=*lpRetBuf;
			*lpRetBuf=0;

			tmp=value&0x0F;//lay 4 bits thap
			tmp =(BYTE)abs(k-tmp);
			tmp=tmp>(BYTE)Img.m_info.bmpColors ?(BYTE)Img.m_info.bmpColors:tmp;
			*lpRetBuf|=tmp;

			tmp =value>>4;		  //lap 4 bits cao
			tmp =(BYTE)abs(k-tmp);
			tmp=tmp>(BYTE)Img.m_info.bmpColors ?(BYTE)Img.m_info.bmpColors:tmp;
			tmp =tmp<<4;
			*lpRetBuf|=tmp;

			lpRetBuf++;
		}
	}
	else if(bits==8)
	{
		WORD	tmp;

		k=k>0xFFFF?0xFFFF:k;
		while(len--)
		{
			tmp=(WORD)(*lpRetBuf);
			tmp =(WORD)abs(k-tmp);
			tmp=tmp>(WORD)Img.m_info.bmpColors ?(WORD)Img.m_info.bmpColors:tmp;
			*lpRetBuf=(BYTE)tmp;

			lpRetBuf++;
		}
	}
	else if(bits==16)
	{
		LPWORD	lpTmpBuf=(LPWORD)lpRetBuf;
		DWORD	tmp;

		k=k>0xFFFFFFFF?0xFFFFFFFF:k;
		len/=2;
		while(len--)
		{
			tmp=(DWORD)(*lpTmpBuf);
			tmp =(DWORD)abs(k-tmp);
			tmp=tmp>Img.m_info.bmpColors ?Img.m_info.bmpColors:tmp;
			*lpTmpBuf=(WORD)tmp;

			lpTmpBuf++;
		}
	}
	else if(bits==24)
	{
		BYTE	Red=GetRValue(k), Green=GetGValue(k), Blue=GetBValue(k);       
		BYTE	R,G,B;

		len/=3;
		while(len--)
		{
			B = *lpRetBuf++; 
			G = *lpRetBuf++; 
			R = *lpRetBuf++; 

			R=(BYTE)abs(R-Red);
			G=(BYTE)abs(G-Green);
			B=(BYTE)abs(B-Blue);

			*(lpRetBuf-1)=R;
			*(lpRetBuf-2)=G;
			*(lpRetBuf-3)=B;

		}
	}
	else if(bits==32)
	{
		;
	}
	
	GlobalUnlock(RetImg.hBuf);
	return RetImg;
}
CImage Abs(CImage& Img1,CImage& Img2)
{
	CImage RetImg;
	return RetImg;

}

void	CImage::Scale(DWORD Width,DWORD Height)
{
	DWORD	xs1=0,ys1=0,
			xs2=m_info.bmpInfo->bmiHeader.biWidth-1,
			ys2=m_info.bmpInfo->bmiHeader.biHeight-1;
	DWORD	xd1=0,yd1=0,
			xd2=Width-1,yd2=Height-1;

	DWORD	dx,dy,d,dx2;
    int		e,sx,sy;
	CImage	Img(*this);

	SetSize(Width,Height);

	dx=(DWORD)abs(yd2-yd1);		dy=(DWORD)abs(ys2-ys1);
    sx=(yd2>=yd1?1:-1);			sy=(ys2>=ys1?1:-1);
    e=(dy << 1)-dx;
    dx2=dx << 1;     dy=dy << 1;
    for(d=0;d<dx;d++) 
	{
		{
			DWORD	dx,dy,d,dx2;
			int		e,sx,sy;

			dx=(DWORD)abs(xd2-xd1);   dy=(DWORD)abs(xs2-xs1);
			sx=(xd2>=xd1?1:-1);		sy=(xs2>=xs1?1:-1);
			e=(dy << 1)-dx;
			dx2=dx << 1;     dy=dy << 1;
			for(d=0;d<dx;d++) 
			{
				SetPixel(xd1,yd1,Img.GetPixel(xs1,ys1));
				while(e>=0) 
				{
					xs1=xs1+sy; 
					e=e-dx2 ;
				}
				xd1=xd1+sx; e=e+dy;
			}
			
		}
        while(e>=0) 
		{
			ys1=ys1+sy; 
			e=e-dx2 ;
		}
		yd1=yd1+sx; e=e+dy;
	}

}

BOOL	CImage::LookupTable(const LPDWORD Lut)
{
	if(!IsValid())
		return FALSE;
	DWORD	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	len=dwBufLength;
	LPBYTE	lpBuf;
	LPWORD	lpTmpBuf;
	BYTE	b,w;
	WORD	idx;
	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
		return FALSE;
	switch(bits)
	{
		case 1:
			BYTE	i;
			while(len--) 
			{ 
				b =*lpBuf; 
 
				w=0;
				for (i=0; i<8; i++) 
				{ 
					w|=(((BYTE)(*(Lut+(b>>7))))<<(7-i));
					b<<=1; 
				} 
				*lpBuf=w;
				lpBuf++;
			} 
			break;
		case 4:
			while(len--)
			{
				b =*lpBuf;

				w=0;
				w=(BYTE)(*(Lut+(b>>4)));
				w<<=4;
				w|=(BYTE)(*(Lut+(b&0x0F)));
				*lpBuf=w;
				lpBuf++;
			}
			break;
		case 8:
			while(len--)
			{
				*lpBuf=(BYTE)(*(Lut+*lpBuf));
				lpBuf++;
			}
			break;
		case 16:
			len/=2;
			lpTmpBuf=(LPWORD)lpBuf;
			while(len--)
			{
				idx = *lpTmpBuf; 
				idx &= 0x7FFF; 
				*lpTmpBuf=(WORD)(*(Lut+idx));
				lpTmpBuf++;
			}
			break;
		case 24:
			BYTE	r,g,b ;

			len/=3;
			while(len--)
			{
				b = *lpBuf++; 
				g = *lpBuf++; 
				r = *lpBuf++; 
					
				r=(BYTE)(*(Lut+r));
				g=(BYTE)(*(Lut+256+g));
				b=(BYTE)(*(Lut+256+256+b));

				*(lpBuf-1)=r;
				*(lpBuf-2)=g;
				*(lpBuf-3)=b;
			}
			break;
		default:
			GlobalUnlock(hBuf);
			return FALSE;
	}
	GlobalUnlock(hBuf);
	return TRUE;
}
DWORD	CImage::Histogram(LPHISTOGRAM& Hist)
{
	if(!IsValid())
		return 0;
	DWORD	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD	numColors=m_info.bmpColors;
	DWORD	len=dwBufLength;
	LPBYTE	lpBuf;
	LPWORD	lpTmpBuf;
	BYTE	b; 
	WORD	idx; 
	DWORD	ret=0;

	if(bits>24)
		return 0;
	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
		return 0;
	if(bits==16)
		numColors=32768L;
	else if(bits==24)
		numColors=256+256+256;

	Hist=new HISTOGRAM[numColors];
	memset(Hist,0,numColors*sizeof(HISTOGRAM));

	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
		return 0;
	if(Hist==NULL)
	{
		GlobalUnlock(hBuf);
		return 0;
	}
	switch(bits)
	{
		case 1:
			while(len--) 
			{ 
				b = *lpBuf++; 
 
				BYTE	i; 
				for (i=0; i<8; i++) 
				{ 
					idx = b>>7; 
					Hist[idx]++;
					b<<=1; 
				} 
			} 
			ret=HISTOGRAM_MONO;
			break;
		case 4:
			while(len--)
			{
				b = *lpBuf++; 
 
				idx = b>>4; 
				Hist[idx]++;
 
				idx = b&0x0F; 
				Hist[idx]++;
			}
			
			ret=HISTOGRAM_4BITS;
			break;
		case 8:
			while(len--)
				Hist[*lpBuf++]++;

			ret=HISTOGRAM_8BITS;
			break;
		case 16:
			lpTmpBuf=(LPWORD)lpBuf;
			len/=2;
			while(len--)
			{
				idx = *lpTmpBuf; 
				idx &= 0x7FFF; 
				Hist[idx]++;
				lpTmpBuf++;
			}

			ret=HISTOGRAM_16BITS;
			break;
		case 24:
			BYTE r,g,b ;
			len/=3;
			while(len--)
			{
				b = *lpBuf++; 
				g = *lpBuf++; 
				r = *lpBuf++; 
				Hist[r]++;
				Hist[256+g]++;
				Hist[256+256+b]++;
			}

			ret=HISTOGRAM_24BITS;
			break;
		case 32:
			ret=HISTOGRAM_32BITS;
			break;
		default:
			GlobalUnlock(hBuf);
			return 0;

	}
	ret<<=24;
	ret|=numColors;

	GlobalUnlock(hBuf);
	return ret;
}
BOOL	CImage::HistEq()
{
	if(!IsValid())
		return FALSE;
	DWORD		bits=m_info.bmpInfo->bmiHeader.biBitCount;
	DWORD		numEntries,ret;
	LPHISTOGRAM	Hist;
	LPDWORD		T;
	DWORD		nPixels,i;
	
	ret=Histogram(Hist);
	if(ret==0||((ret>>24)&0xFF)==HISTOGRAM_32BITS)
		return FALSE;

	numEntries=ret&0x00FFFFFF;
	if((T=new DWORD[numEntries])==NULL)
		return FALSE;
	nPixels=(DWORD)(m_info.bmpInfo->bmiHeader.biWidth*abs(m_info.bmpInfo->bmiHeader.\
					biHeight));
	
	if(bits==1||bits==4||bits==8||bits==16)
	{
		DWORD	Sum=0;
		for(i=0;i<numEntries;i++)
		{
			Sum+=Hist[i];
			T[i]=(DWORD)(Sum*(numEntries-1)/nPixels);
		}
	}
	else if(bits==24)
	{
		DWORD	rSum=0,gSum=0,bSum=0;
		for(i=0;i<256;i++)
		{
			rSum+=Hist[i];
			T[i]=(DWORD)(rSum*255/nPixels);

			gSum+=Hist[256+i];
			T[256+i]=(DWORD)(gSum*255/nPixels);

			bSum+=Hist[256+256+i];
			T[256+256+i]=(DWORD)(bSum*255/nPixels);
		}
	}
	LookupTable(T);
	
	if(Hist!=NULL)
		delete Hist;
	if(T!=NULL)
		delete T;
	return TRUE;
}


//Tich chap
BOOL	CImage::Tichchap(LPINT* H, INT w, DWORD Flag)
{
	if(!IsValid()||m_info.bmpColors==0)
		return FALSE;

	WORD	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	LPBYTE	lpBuf,lpTmpBuf,lpTmpBufIn;
	LPBYTE*	lpBufIn;
	INT		Height,Width,WidthBytes,i,j,k,l,Lc,Col,Row;
	INT		Sum;
	BYTE	b,v;

	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL||w<1)
		return FALSE;

	Height=(DWORD)abs(m_info.bmpInfo->bmiHeader.biHeight);
	Width=(DWORD)m_info.bmpInfo->bmiHeader.biWidth;
	if(m_info.bmpColors==0)
		return FALSE;

	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
		return FALSE;

	Height=(INT)abs(m_info.bmpInfo->bmiHeader.biHeight);
	Width=(INT)m_info.bmpInfo->bmiHeader.biWidth;
	WidthBytes=(INT)m_info.bmpBytesPerScanLine;

	lpBufIn=new LPBYTE[Height];
	if((Flag&BOUNDARY_STACK)==BOUNDARY_STACK)
		Lc=0;
	else if((Flag&CENTER_STACK)==CENTER_STACK)
		Lc=(w+1)>>1;		

	switch(bits)
	{
		case 1:
			for(i=0;i<Height;i++)
			{
				lpBufIn[i]=new BYTE[Width];
				
				lpTmpBuf=lpBuf+i*WidthBytes;
				lpTmpBufIn=lpBufIn[i];
				while(WidthBytes--)
				{
					b=*lpTmpBuf++;
					for(i=0;i<8;i++)
					{ 
						v= b>>7; 
						*lpTmpBufIn=v;
						b<<=1; 
						lpTmpBufIn++;
					}
				}
			}
			break;
		case 4:
			for(i=0;i<Height;i++)
			{
				lpBufIn[i]=new BYTE[Width];

				lpTmpBuf=lpBuf+i*WidthBytes;
				lpTmpBufIn= lpBufIn[i];
				while(WidthBytes--)
				{
					b=*lpTmpBuf++;

					v = b>>4; 
					*lpTmpBufIn=v; 
					lpTmpBufIn++;

					v = b&0x0F; 
					*lpTmpBufIn=v;
					lpTmpBufIn++;
				}
			}
			break;
		case 8:
			for(i=0;i<Height;i++)
			{
				lpBufIn[i]=new BYTE[Width];
				memcpy(lpBufIn[i],lpBuf+i*Width,Width);
			}

			for(i=0;i<Height;i++)
				for(j=0;j<Width;j++)
				{
					Sum=0;
					for(k=0;k<w;k++)	
						for(l=0;l<w;l++)
						{
							Col=i-k+Lc;Row=j+l+Lc;
							if(Row>=0 && Row<Width && Col>=0 && Col<Height)
								Sum+=lpBufIn[Col][Row]*H[k][l];
						}
					lpBuf[i*WidthBytes+j]=(BYTE)Sum;
				}
			break;
		default:
			GlobalUnlock(hBuf);
			delete lpBufIn;
			return FALSE;

	}
	
	GlobalUnlock(hBuf);
	for(i=0;i<Height;i++)
		delete lpBufIn[i];
	delete lpBufIn;

	return TRUE;
}
BOOL	CImage::LinearFilter(LPINT* H, INT w, INT Div, INT startRow, INT startCol,
							 INT nWidth, INT nHeight)
{

	if(!IsValid()||m_info.bmpColors==0)
		return FALSE;

	WORD	bits=m_info.bmpInfo->bmiHeader.biBitCount;
	LPBYTE	lpBuf;
	INT		Height,Width,WidthBytes,i,j,Col,Row;
	INT		k,l,n;
	INT		Sum;
	BYTE	b=0,v=0;

	Height=(INT)abs(m_info.bmpInfo->bmiHeader.biHeight);
	Width=(INT)m_info.bmpInfo->bmiHeader.biWidth;
 	WidthBytes=(INT)m_info.bmpBytesPerScanLine;
	nWidth=(nWidth==0)?Width:nWidth;
	nHeight=(nHeight==0)?Height:nHeight;
	if(Div==0)
	{
		for(i=0;i<w;i++)
			for(j=0;j<w;j++)
				Div +=H[i][j];
	}

	if(startRow<0||startRow>=Height||startCol<0||startCol>=Width||w%2==0||w<3)
		return FALSE;
	Width=(startRow+nWidth>Width)?Width:startRow+nWidth;
	Height=(startCol+nHeight>Height)?Height:startCol+nHeight;

	if((lpBuf=(LPBYTE)GlobalLock(hBuf))==NULL)
		return FALSE;
	n=(w-1)>>1;
	switch(bits)
	{
		case 1:
			break;
		case 4:
			break;
		case 8:
			for(i=startRow;i<Height;i++)
				for(j=startCol;j<Width;j++)
				{
					Sum=0;
					for(k=-n;k<=n;k++)
						for(l=-n;l<=n;l++)
						{
							Row=i+k;Col=j+l;
							if(Row>=0 && Row<Height && Col>=0 && Col<Width)
								Sum+=H[k+n][l+n]*lpBuf[Row*Width+Col];
						}
					lpBuf[i*Width+j]=(BYTE)(Sum/Div);
				}

			break;
		default:
			GlobalUnlock(hBuf);
			return FALSE;

	}
	
	GlobalUnlock(hBuf);
	return TRUE;
}

BOOL	CImage::MediumSoften()
{
	BOOL ret;
	LPINT* H;

	H=new LPINT[3];
	for(int i=0;i<3;i++)
		H[i]=new INT[3];
	H[0][0]=1;H[0][1]=3;H[0][2]=1;
	H[1][0]=3;H[1][1]=9;H[1][2]=3;
	H[2][0]=1;H[2][1]=3;H[2][2]=1;
	
	ret=LinearFilter(H,3,25);

	for(i=0;i<3;i++)
		delete H[i];
	delete H;

	return ret;
}
BOOL	CImage::AlotSoften()
{
	BOOL ret;
	LPINT* H;

	H=new LPINT[3];
	for(int i=0;i<3;i++)
		H[i]=new INT[3];
	H[0][0]=1;H[0][1]=1;H[0][2]=1;
	H[1][0]=1;H[1][1]=1;H[1][2]=1;
	H[2][0]=1;H[2][1]=1;H[2][2]=1;
	
	ret=LinearFilter(H,3,9);

	for(i=0;i<3;i++)
		delete H[i];
	delete H;

	return ret;
}
BOOL	CImage::LowSharpen()
{
	BOOL ret;
	LPINT* H;

	H=new LPINT[3];
	for(int i=0;i<3;i++)
		H[i]=new INT[3];
	H[0][0]=-1;H[0][1]=-3;H[0][2]=-1;
	H[1][0]=-3;H[1][1]=41;H[1][2]=-3;
	H[2][0]=-1;H[2][1]=-3;H[2][2]=-1;
	
	ret=LinearFilter(H,3,25);

	for(i=0;i<3;i++)
		delete H[i];
	delete H;

	return ret;
}
BOOL	CImage::MediumSharpen()
{
	BOOL ret;
	LPINT* H;

	H=new LPINT[3];
	for(int i=0;i<3;i++)
		H[i]=new INT[3];
	H[0][0]=-1;H[0][1]=-1;H[0][2]=-1;
	H[1][0]=-1;H[1][1]=17;H[1][2]=-1;
	H[2][0]=-1;H[2][1]=-1;H[2][2]=-1;
	
	ret=LinearFilter(H,3,9);

	for(i=0;i<3;i++)
		delete H[i];
	delete H;

	return ret;

}
BOOL	CImage::DiagonalShatter()
{
	BOOL ret;
	LPINT* H;

	H=new LPINT[3];
	for(int i=0;i<3;i++)
		H[i]=new INT[3];
	H[0][0]=1;H[0][1]=0;H[0][2]=1;
	H[1][0]=0;H[1][1]=0;H[1][2]=0;
	H[2][0]=1;H[2][1]=0;H[2][2]=1;
	
	ret=LinearFilter(H,3,4);

	for(i=0;i<3;i++)
		delete H[i];
	delete H;

	return ret;
}
BOOL	CImage::HorizontalBlur()
{
	BOOL ret;
	LPINT* H;

	H=new LPINT[3];
	for(int i=0;i<3;i++)
		H[i]=new INT[3];
	H[0][0]=0;H[0][1]=0;H[0][2]=0;
	H[1][0]=1;H[1][1]=2;H[1][2]=1;
	H[2][0]=0;H[2][1]=0;H[2][2]=0;
	
	ret=LinearFilter(H,3,4);

	for(i=0;i<3;i++)
		delete H[i];
	delete H;

	return ret;

}
BOOL	CImage::FireFilter()
{
	BOOL ret;
	LPINT* H;

	H=new LPINT[3];
	for(int i=0;i<3;i++)
		H[i]=new INT[3];
	H[0][0]=0;H[0][1]=1;H[0][2]=0;
	H[1][0]=0;H[1][1]=1;H[1][2]=0;
	H[2][0]=1;H[2][1]=1;H[2][2]=1;
	
	ret=LinearFilter(H,3,5);

	for(i=0;i<3;i++)
		delete H[i];
	delete H;

	return ret;
}

