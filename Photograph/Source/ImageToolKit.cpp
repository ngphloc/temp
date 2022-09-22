// ImageToolKit.cpp: implementation of the CImageToolKit class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Photo.h"
#include "ImageToolKit.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CImageToolKit::CImageToolKit()
{

}

CImageToolKit::~CImageToolKit()
{

}
BOOL CImageToolKit::CombineTwoImages(CImage& Img1, CImage& Img2,CImage& RetImg, float ratio1,float ratio2, BOOL check)
{
	DWORD	n,m,h,len;
	int		i=0;
	CSize	size,common,tail;
	CPoint	ptStart;
	LPBYTE	lpImgBuf1 ,lpImgBuf2,lpRetBuf;
	LPBYTE	lpBuf1,lpBuf2,lpBuf3,lpTmpBuf;

	if(check)
	{
		if(!Img1.IsValid()||!Img2.IsValid())
			return FALSE;
		if(!Img1.IsFit(Img2))
			return FALSE;
	}

	ptStart=Img1.m_ptOrg-Img2.m_ptOrg;

	if(ptStart.y<0)
	{
		if(Img1.m_info.bmpInfo->bmiHeader.biHeight-ptStart.y<Img2.m_info.bmpInfo->\
				bmiHeader.biHeight)
		{
			size.cy=Img2.m_info.bmpInfo->bmiHeader.biHeight;
			common.cy=Img1.m_info.bmpInfo->bmiHeader.biHeight;
			tail.cy=size.cy-common.cy+ptStart.y;
		}
		else
		{
			size.cy=Img1.m_info.bmpInfo->bmiHeader.biHeight-ptStart.y;
			common.cy=Img2.m_info.bmpInfo->bmiHeader.biHeight+ptStart.y;
			tail.cy=-size.cy+Img2.m_info.bmpInfo->bmiHeader.biHeight;
		}
	}
	else
	{
		if(Img2.m_info.bmpInfo->bmiHeader.biHeight+ptStart.y<Img1.m_info.bmpInfo->\
				bmiHeader.biHeight)
		{
			size.cy=Img1.m_info.bmpInfo->bmiHeader.biHeight;
			common.cy=Img2.m_info.bmpInfo->bmiHeader.biHeight;
			tail.cy=-size.cy+common.cy+ptStart.y;
		}
		else
		{
			size.cy=Img2.m_info.bmpInfo->bmiHeader.biHeight+ptStart.y;
			common.cy=Img1.m_info.bmpInfo->bmiHeader.biHeight-ptStart.y;
			tail.cy=size.cy-Img1.m_info.bmpInfo->bmiHeader.biHeight;
		}
	}

	if(ptStart.x<0)
	{
		if(Img1.m_info.bmpInfo->bmiHeader.biWidth-ptStart.x<Img2.m_info.bmpInfo->\
				bmiHeader.biWidth)
		{
			size.cx=Img2.m_info.bmpInfo->bmiHeader.biWidth;
			common.cx=Img1.m_info.bmpInfo->bmiHeader.biWidth;
			tail.cx=size.cx-common.cx+ptStart.x;
		}
		else
		{
			size.cx=Img1.m_info.bmpInfo->bmiHeader.biWidth-ptStart.x;
			common.cx=Img2.m_info.bmpInfo->bmiHeader.biWidth+ptStart.x;
			tail.cx=-size.cx+Img2.m_info.bmpInfo->bmiHeader.biWidth;
		}
	}
	else
	{
		if(Img2.m_info.bmpInfo->bmiHeader.biWidth+ptStart.x<Img1.m_info.bmpInfo->\
				bmiHeader.biWidth)
		{
			size.cx=Img1.m_info.bmpInfo->bmiHeader.biWidth;
			common.cx=Img2.m_info.bmpInfo->bmiHeader.biWidth;
			tail.cx=-size.cx+common.cx+ptStart.x;
		}
		else
		{
			size.cx=Img2.m_info.bmpInfo->bmiHeader.biWidth+ptStart.x;
			common.cx=Img1.m_info.bmpInfo->bmiHeader.biWidth-ptStart.x;
			tail.cx=size.cx-Img1.m_info.bmpInfo->bmiHeader.biWidth;
		}
	}
	if(size.cx<=0||size.cy<=0)
		return FALSE;
	RetImg.SetImage(&Img1);
	RetImg.SetSize(size.cx,size.cy);
	RetImg.Blank();
	if(!RetImg.IsValid())
		return FALSE;

	lpImgBuf1=(LPBYTE)GlobalLock(Img1.hBuf);
	lpImgBuf2=(LPBYTE)GlobalLock(Img2.hBuf);
	lpRetBuf=(LPBYTE)GlobalLock(RetImg.hBuf);
	if(lpImgBuf1==NULL||lpImgBuf2==NULL||lpRetBuf==NULL)
		return FALSE;
	lpImgBuf1+=(Img1.m_info.bmpInfo->bmiHeader.biHeight-1)*Img1.m_info.bmpBytesPerScanLine;
	lpImgBuf2+=(Img2.m_info.bmpInfo->bmiHeader.biHeight-1)*Img2.m_info.\
							bmpBytesPerScanLine;
	lpRetBuf+=(RetImg.m_info.bmpInfo->bmiHeader.biHeight-1)*RetImg.m_info.\
							bmpBytesPerScanLine;
	n=Img1.m_info.bmpInfo->bmiHeader.biBitCount;
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
				memcpy(lpRetBuf,lpImgBuf2,Img2.m_info.bmpBytesPerScanLine);
				lpImgBuf2 -=Img2.m_info.bmpBytesPerScanLine;
				lpRetBuf -=RetImg.m_info.bmpBytesPerScanLine;
			}
			for(i=0;i<common.cy;i++)
			{
				lpBuf1=lpImgBuf1,lpBuf2=lpImgBuf2,lpBuf3=lpRetBuf,lpTmpBuf;
				memcpy(lpBuf3,lpBuf2,-ptStart.x);
				lpBuf2-=ptStart.x;
				lpBuf3-=ptStart.x;
				Img1.m_info.bmpInfo->bmiHeader.biBitCount;
				switch(Img1.m_info.bmpInfo->bmiHeader.biBitCount)
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
								tmp=(WORD)(((*lpBuf1)*ratio1+(*lpBuf2)*ratio2)/(ratio1+ratio2));
								tmp=tmp>(WORD)Img1.m_info.bmpColors ?(WORD)Img1.m_info.bmpColors:tmp;
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
								tmp=(DWORD)(((*lpBuf4)*ratio1+(*lpBuf5)*ratio2)/(ratio1+ratio2));
								tmp=tmp>Img2.m_info.bmpColors ?Img2.m_info.bmpColors:tmp;
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
								tmp=(WORD)(((*lpBuf1)*ratio1+(*lpBuf2)*ratio2)/(ratio1+ratio2));
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
						GlobalUnlock(Img1.hBuf);
						GlobalUnlock(Img2.hBuf);
						GlobalUnlock(RetImg.hBuf);
						return FALSE;
				}
				n=(DWORD)((tail.cx>0)?tail.cx:-tail.cx);
				lpTmpBuf=(tail.cx>0)?lpBuf2:lpBuf1;
				memcpy(lpBuf3,lpTmpBuf,n);

				lpImgBuf1    -=Img1.m_info.bmpBytesPerScanLine;
				lpImgBuf2 -=Img2.m_info.bmpBytesPerScanLine;
				lpRetBuf -=RetImg.m_info.bmpBytesPerScanLine;
			}
			if(tail.cy>0)
			{
				lpTmpBuf=lpImgBuf2;
				m=tail.cy;
				n=Img2.m_info.bmpBytesPerScanLine;
			}
			else
			{
				lpTmpBuf=lpImgBuf1;
				m=-tail.cy;
				n=Img1.m_info.bmpBytesPerScanLine;
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
				memcpy(lpBuf3,lpImgBuf2,Img2.m_info.bmpBytesPerScanLine);
				lpImgBuf2 -=Img2.m_info.bmpBytesPerScanLine;
				lpRetBuf -=RetImg.m_info.bmpBytesPerScanLine;
			}
			for(i=0;i<common.cy;i++)
			{
				lpBuf1=lpImgBuf1,lpBuf2=lpImgBuf2,lpBuf3=lpRetBuf,lpTmpBuf;
				memcpy(lpBuf3,lpBuf1,ptStart.x);
				lpBuf1+=ptStart.x;
				lpBuf3+=ptStart.x;
				Img1.m_info.bmpInfo->bmiHeader.biBitCount;
				switch(Img1.m_info.bmpInfo->bmiHeader.biBitCount)
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
								tmp=(WORD)(((*lpBuf1)*ratio1+(*lpBuf2)*ratio2)/(ratio1+ratio2));
								tmp=tmp>(WORD)Img1.m_info.bmpColors ?(WORD)Img1.m_info.bmpColors:tmp;
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
								tmp=(DWORD)(((*lpBuf4)*ratio1+(*lpBuf5)*ratio2)/(ratio1+ratio2));
								tmp=tmp>Img2.m_info.bmpColors ?Img2.m_info.bmpColors:tmp;
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
								tmp=(WORD)(((*lpBuf1)*ratio1+(*lpBuf2)*ratio2)/(ratio1+ratio2));
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
						GlobalUnlock(Img1.hBuf);
						GlobalUnlock(Img2.hBuf);
						GlobalUnlock(RetImg.hBuf);
						return FALSE;
				}
				n=(DWORD)((tail.cx>0)?tail.cx:-tail.cx);
				lpTmpBuf=(tail.cx>0)?lpBuf2:lpBuf1;
				memcpy(lpBuf3,lpTmpBuf,n);

				lpImgBuf1    -=Img1.m_info.bmpBytesPerScanLine;
				lpImgBuf2 -=Img2.m_info.bmpBytesPerScanLine;
				lpRetBuf -=RetImg.m_info.bmpBytesPerScanLine;
			}
			if(tail.cy>0)
			{
				lpTmpBuf=lpImgBuf2;
				m=tail.cy;
				n=Img2.m_info.bmpBytesPerScanLine;
			}
			else
			{
				lpTmpBuf=lpImgBuf1;
				m=-tail.cy;
				n=Img1.m_info.bmpBytesPerScanLine;
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
				memcpy(lpBuf3,lpImgBuf1,Img1.m_info.bmpBytesPerScanLine);
				lpImgBuf1 -=Img1.m_info.bmpBytesPerScanLine;
				lpRetBuf -=RetImg.m_info.bmpBytesPerScanLine;
			}
			for(i=0;i<common.cy;i++)
			{
				lpBuf1=lpImgBuf1,lpBuf2=lpImgBuf2,lpBuf3=lpRetBuf,lpTmpBuf;
				memcpy(lpBuf3,lpBuf2,-ptStart.x);
				lpBuf2-=ptStart.x;
				lpBuf3-=ptStart.x;
				Img1.m_info.bmpInfo->bmiHeader.biBitCount;
				switch(Img1.m_info.bmpInfo->bmiHeader.biBitCount)
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
								tmp=(WORD)(((*lpBuf1)*ratio1+(*lpBuf2)*ratio2)/(ratio1+ratio2));
								tmp=tmp>(WORD)Img1.m_info.bmpColors ?(WORD)Img1.m_info.bmpColors:tmp;
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
								tmp=(DWORD)(((*lpBuf4)*ratio1+(*lpBuf5)*ratio2)/(ratio1+ratio2));
								tmp=tmp>Img2.m_info.bmpColors ?Img2.m_info.bmpColors:tmp;
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
								tmp=(WORD)(((*lpBuf1)*ratio1+(*lpBuf2)*ratio2)/(ratio1+ratio2));
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
						GlobalUnlock(Img1.hBuf);
						GlobalUnlock(Img2.hBuf);
						GlobalUnlock(RetImg.hBuf);
						return FALSE;
				}
				n=(DWORD)((tail.cx>0)?tail.cx:-tail.cx);
				lpTmpBuf=(tail.cx>0)?lpBuf2:lpBuf1;
				memcpy(lpBuf3,lpTmpBuf,n);

				lpImgBuf1    -=Img1.m_info.bmpBytesPerScanLine;
				lpImgBuf2 -=Img2.m_info.bmpBytesPerScanLine;
				lpRetBuf -=RetImg.m_info.bmpBytesPerScanLine;
			}
			if(tail.cy>0)
			{
				lpTmpBuf=lpImgBuf2;
				m=tail.cy;
				n=Img2.m_info.bmpBytesPerScanLine;
			}
			else
			{
				lpTmpBuf=lpImgBuf1;
				m=-tail.cy;
				n=Img1.m_info.bmpBytesPerScanLine;
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
				memcpy(lpRetBuf,lpImgBuf1,Img1.m_info.bmpBytesPerScanLine);
				lpImgBuf1 -=Img1.m_info.bmpBytesPerScanLine;
				lpRetBuf -=RetImg.m_info.bmpBytesPerScanLine;
			}
			for(i=0;i<common.cy;i++)
			{
				lpBuf1=lpImgBuf1,lpBuf2=lpImgBuf2,lpBuf3=lpRetBuf,lpTmpBuf;
				memcpy(lpBuf3,lpBuf1,ptStart.x);
				lpBuf1+=ptStart.x;
				lpBuf3+=ptStart.x;
				Img1.m_info.bmpInfo->bmiHeader.biBitCount;
				switch(Img1.m_info.bmpInfo->bmiHeader.biBitCount)
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
								tmp=(WORD)(((*lpBuf1)*ratio1+(*lpBuf2)*ratio2)/(ratio1+ratio2));
								tmp=tmp>(WORD)Img1.m_info.bmpColors ?(WORD)Img1.m_info.bmpColors:tmp;
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
								tmp=(DWORD)(((*lpBuf4)*ratio1+(*lpBuf5)*ratio2)/(ratio1+ratio2));
								tmp=tmp>Img2.m_info.bmpColors ?Img2.m_info.bmpColors:tmp;
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
								tmp=(WORD)(((*lpBuf1)*ratio1+(*lpBuf2)*ratio2)/(ratio1+ratio2));
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
						GlobalUnlock(Img1.hBuf);
						GlobalUnlock(Img2.hBuf);
						GlobalUnlock(RetImg.hBuf);
						return FALSE;
				}
				n=(DWORD)((tail.cx>0)?tail.cx:-tail.cx);
				lpTmpBuf=(tail.cx>0)?lpBuf2:lpBuf1;
				memcpy(lpBuf3,lpTmpBuf,n);

				lpImgBuf1    -=Img1.m_info.bmpBytesPerScanLine;
				lpImgBuf2 -=Img2.m_info.bmpBytesPerScanLine;
				lpRetBuf -=RetImg.m_info.bmpBytesPerScanLine;
			}
			if(tail.cy>0)
			{
				lpTmpBuf=lpImgBuf2;
				m=tail.cy;
				n=Img2.m_info.bmpBytesPerScanLine;
			}
			else
			{
				lpTmpBuf=lpImgBuf1;
				m=-tail.cy;
				n=Img1.m_info.bmpBytesPerScanLine;
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


	GlobalUnlock(Img1.hBuf);
	GlobalUnlock(Img2.hBuf);
	GlobalUnlock(RetImg.hBuf);
	return TRUE;

}

BOOL CImageToolKit::CutImages(CImage* pImg, LONG *pHeight, UINT m, LONG* pWidth, UINT n, 
		CArray< CPtrArray, CPtrArray& >& imgA)
{
	DWORD i=0,j=0, k=0;
	LONG  biWidth, biHeight;
	LONG  sumWidth=0, sumHeight=0; 
	LONG  h,w;
	LPBYTE	lpBuf=NULL, lpTmpBuf=NULL;
	LPBYTE*	alpTmpBuf; 
	WORD	tmp=0;
	float	z=0;

	if(!pImg->IsValid() || m<1|| n<1|| pWidth==NULL || pHeight==NULL)
		return FALSE;
	biWidth=pImg->m_info.bmpInfo->bmiHeader.biWidth;
	biHeight=pImg->m_info.bmpInfo->bmiHeader.biHeight;
	for(i=0;i<m;i++)
	{
		if(pHeight[i]==0)
			return FALSE;
		sumHeight +=abs(pHeight[i]);
		if(sumHeight>abs(biHeight))
			return FALSE;
	}
	for(j=0;j<n;j++)
	{
		if(pWidth[j]==0)
			return FALSE;
		sumWidth +=abs(pWidth[j]);
		if(sumWidth>abs(biWidth))
			return FALSE;
	}
	
	imgA.SetSize(m);
	for(i=0;i<m;i++)
		imgA[i].SetSize(n);
	
	for(i=0;i<m;i++)
	{
		h=pHeight[i];
		for(j=0;j<n;j++)
		{
			w=pWidth[j];
			imgA[i][j]=(LPVOID)new CImage;

			if(!((CImage*)( imgA[i][j] ))->SetInfo(pImg))
				goto error;				
			if(((CImage*)(imgA[i][j]))->SetSize(w,h)==0)
				goto error;
		}
	}

	i=0;
	h=pHeight[i];
	k=0;
	switch(pImg->m_info.bmpInfo->bmiHeader.biBitCount)
	{
		case 1:
			z=1/8;
			break;
		case 4:
			z=1/2;
			break;
		case 8:
			z=1;
			break;
		case 16:
			z=2;
			break;
		case 24:
			z=3;
			break;
		case 32:
			z=3;
			break;
	}
	if((lpBuf=(LPBYTE)GlobalLock(pImg->hBuf))==NULL)
		goto error;
	lpTmpBuf=lpBuf;
	alpTmpBuf=(LPBYTE*)new LPBYTE[n];
	for(j=0;j<n;j++)
		if((alpTmpBuf[j]=(LPBYTE)GlobalLock(((CImage*)(imgA[i][j]))->hBuf))==NULL)
			goto error;
	j=0;
	while(1)
	{
		for(j=0;j<n;j++)
		{
			tmp=(WORD)(pWidth[j]*z);
			memcpy(alpTmpBuf[j],lpTmpBuf,tmp);
			alpTmpBuf[j] +=((CImage*)(imgA[i][j]))->m_info.bmpBytesPerScanLine ;
			lpTmpBuf +=tmp;
		}
		lpBuf +=pImg->m_info.bmpBytesPerScanLine;
		lpTmpBuf=lpBuf;
		k++;
		if(k==(DWORD)abs(h))
		{
			for(j=0;j<n;j++)
				GlobalUnlock(alpTmpBuf[j]);

			i++;
			if(i>=m)
				break;
			h=pHeight[i];
			k=0;
			for(j=0;j<n;j++)
				if((alpTmpBuf[j]=(LPBYTE)GlobalLock(((CImage*)(imgA[i][j]))->hBuf))==NULL)
					goto error;
		}

	}
	GlobalUnlock(pImg->hBuf);
	delete alpTmpBuf;
	return TRUE;

error:
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			((CImage*)(imgA[i][j]))->Delete();
	for(i=0;i<m;i++)
		imgA[i].SetSize(0);
	imgA.SetSize(0);
	GlobalUnlock(pImg->hBuf);
	if(alpTmpBuf!=NULL)
		delete alpTmpBuf;
	return FALSE;
}


BOOL CImageToolKit::CutImages(CImage* pImg, UINT m, UINT n, 
		CArray< CPtrArray, CPtrArray& >& imgA)
{
	DWORD	i=0,j=0,k,bits;
	LONG	biWidth, biHeight;
	LONG	o;

	BOOL	ret;
	if(!pImg->IsValid() || m<1 || n<1)
		return FALSE;

	biWidth=pImg->m_info.bmpInfo->bmiHeader.biWidth;
	biHeight=pImg->m_info.bmpInfo->bmiHeader.biHeight;
	bits=pImg->m_info.bmpInfo->bmiHeader.biBitCount;
	k=bits/8;

	LONG h, *pHeight=new LONG[m];
	if(pHeight==NULL)
		return FALSE;
	LONG w, *pWidth=new LONG[n];
	if(pWidth==NULL)
		return FALSE;

	h=abs(biHeight/(LONG)m);
	if(h==0)
		goto error;
	if(biHeight>0)
	{
		for(i=0;i<m-1;i++)
			pHeight[i]=h;
		pHeight[i]=h+biHeight%m;
	}
	else
	{
		for(i=0;i<m-1;i++)
			pHeight[i]=-h;
		pHeight[i]=-h-biHeight%m;
	}

	
	w=biWidth/n;
	if(w==0)
		goto error;
	o=w*k;
	if(o%4==0)
	{
		for(j=0;j<n-1;j++)
			pWidth[j]=w;
		pWidth[j]=w+biWidth%n;
	}
	
	else
	{
		if(bits!=24)
			w=((o/4)*4)/k;
		else
			w=((o/12)*12)/k;
		if(w==0)
			goto error;
		for(j=0;j<n-1;j++)
			pWidth[j]=w;
		pWidth[j]=biWidth-(LONG)(n-1)*w;
		if(pWidth[j]==0)
			goto error;
	}

	ret=CutImages(pImg,pHeight,m,pWidth,n,imgA);

	delete pHeight;
	delete pWidth;
	return ret;
error:
	if(pHeight!=NULL)
		delete pHeight;
	if(pWidth!=NULL)
		delete pWidth;
	return FALSE;
}

BOOL CImageToolKit::CatImages(CArray< CPtrArray, CPtrArray& >& imgA, CImage* pImg)
{
	DWORD m,n,i,j,k;
	LONG w,h;
	LPBYTE	lpBuf=NULL, lpTmpBuf=NULL;
	LPBYTE*	alpTmpBuf; 
	WORD	tmp=0;
	float	z=0;

	m=(DWORD)imgA.GetSize();
	if(m==0)
		return FALSE;
	n=imgA[0].GetSize();
	if(n==0)
		return FALSE;

	LONG *pHeight=new LONG[m];
	if(pHeight==NULL)
		return FALSE;
	LONG *pWidth=new LONG[n];
	if(pWidth==NULL)
		return FALSE;

	for(i=0;i<m;i++)
		pHeight[i]=((CImage*)(imgA[i][0]))->GetHeight();
	for(j=0;j<n;j++)
		pWidth[j]= ((CImage*)(imgA[0][j]))->GetWidth();

	h=0;
	w=0;
	for(i=0;i<m;i++)
		h+=pHeight[i];
	if(h==0)
		goto error;

	for(j=0;j<n;j++)
		w+=pWidth[j];
	if(w==0)
		goto error;

	pImg->SetInfo((CImage*)(imgA[0][0]));
	pImg->SetSize(w,h);

	i=0;
	h=pHeight[i];
	k=0;
	switch(pImg->m_info.bmpInfo->bmiHeader.biBitCount)
	{
		case 1:
			z=1/8;
			break;
		case 4:
			z=1/2;
			break;
		case 8:
			z=1;
			break;
		case 16:
			z=2;
			break;
		case 24:
			z=3;
			break;
		case 32:
			z=3;
			break;
	}
	if((lpBuf=(LPBYTE)GlobalLock(pImg->hBuf))==NULL)
		goto error;
	lpTmpBuf=lpBuf;
	alpTmpBuf=(LPBYTE*)new LPBYTE[n];
	for(j=0;j<n;j++)
		if((alpTmpBuf[j]=(LPBYTE)GlobalLock(((CImage*)(imgA[i][j]))->hBuf))==NULL)
			goto error;
	j=0;
	while(1)
	{
		for(j=0;j<n;j++)
		{
			tmp=(WORD)(pWidth[j]*z);
			memcpy(lpTmpBuf,alpTmpBuf[j],tmp);
			alpTmpBuf[j] +=((CImage*)(imgA[i][j]))->m_info.bmpBytesPerScanLine ;
			lpTmpBuf +=tmp;
		}
		lpBuf +=pImg->m_info.bmpBytesPerScanLine;
		lpTmpBuf=lpBuf;
		k++;
		if(k==(DWORD)abs(h))
		{
			for(j=0;j<n;j++)
				GlobalUnlock(alpTmpBuf[j]);

			i++;
			if(i>=m)
				break;
			h=pHeight[i];
			k=0;
			for(j=0;j<n;j++)
				if((alpTmpBuf[j]=(LPBYTE)GlobalLock(((CImage*)(imgA[i][j]))->hBuf))==NULL)
					goto error;
		}

	}

	GlobalUnlock(pImg->hBuf);
	delete alpTmpBuf;
	delete pHeight;
	delete pWidth;
	return TRUE;

error:
	if(pHeight!=NULL)
		delete pHeight ;
	if(pWidth!=NULL)
		delete pWidth;
	if(alpTmpBuf!=NULL)
		delete alpTmpBuf;
	GlobalUnlock(pImg->hBuf);
}

BOOL CImageToolKit::Find4Neighbour(CArray< CPtrArray, CPtrArray& >& imgA,
		DWORD i, DWORD j, DWORD x, DWORD y, CImage* pImg, CPoint* pImgPos)
{
	DWORD m,n;
	DWORD area;
	CArray< CPtrArray, CPtrArray& > imgB;
	int k;
	
	m=imgA.GetSize();
	if(m==0)
		return FALSE;
	n=imgA[0].GetSize();
	if(n==0)
		return FALSE;
	if(i<0 || i>=m || j<0 || j>=n)
		return FALSE;

	area=((CImage*)(imgA[i][j]))->FindArea(x,y);
	if(area==0)
		return FALSE;

	imgB.SetSize(2);
	for(k=0;k<2;k++)
		imgB[k].SetSize(2);

	BOOL	common=FALSE;
	BYTE	label=0xFF;	
	if(i==0)
	{

		if(j==0)
			label=0;
		else if(j==n-1)
			label =1;
		else if(area==RIGHTTOP || area==RIGHTBOTTOM)
			label=0;
		else
			label=1;
	}
	else if(i==m-1)
	{
		if(j==0)
			label=2;
		else if(j==n-1)
			label=3;
		else if (area==RIGHTTOP || area==RIGHTBOTTOM)
			label=2;
		else
			label =3;
	}
	else
	{
		if(j==0)
		{
			if(area==LEFTTOP ||area==RIGHTTOP )
				label=2;
			else
				label=0;
		}
		else if(j==n-1)
		{
			if(area==LEFTTOP ||area==RIGHTTOP )
				label=3;
			else
				label=1;
		}
		else
			common=TRUE;
	}
	if(common)
	{
		switch(area)
		{
			case LEFTTOP:
				label=3;
				break;
			case RIGHTTOP:
				label=2;
				break;
			case LEFTBOTTOM:
				label=1;
				break;
			case RIGHTBOTTOM:
				label=0;
				break;
		}
	}

	switch(label)
	{
		case 0:
			imgB[0][0]=imgA[i][j];  imgB[0][1]=imgA[i][j+1];
			imgB[1][0]=imgA[i+1][j];	imgB[1][1]=imgA[i+1][j+1]; 
			pImgPos->y=i;pImgPos->x=j;
			break;
		case 1:
			imgB[0][0]=imgA[i][j-1];  imgB[0][1]=imgA[i][j];
			imgB[1][0]=imgA[i+1][j-1];	imgB[1][1]=imgA[i+1][j]; 
			pImgPos->y=i;pImgPos->x=j-1;
			break;
		case 2:
			imgB[0][0]=imgA[i-1][j];  imgB[0][1]=imgA[i-1][j+1];
			imgB[1][0]=imgA[i][j];	imgB[1][1]=imgA[i][j+1]; 
			pImgPos->y=i-1;pImgPos->x=j;
			break;
		case 3:
			imgB[0][0]=imgA[i-1][j-1];  imgB[0][1]=imgA[i-1][j];
			imgB[1][0]=imgA[i][j-1];	imgB[1][1]=imgA[i][j]; 
			pImgPos->y=i-1;pImgPos->x=j-1;
			break;
		default:
			return FALSE;
	}
	
	if(!CatImages(imgB,pImg))
		return FALSE;

	return TRUE;
}
BOOL CImageToolKit::WriteImagesArray(CArray< CPtrArray, CPtrArray& >& imgA, CString name, CString dir, CString type)
{
	DWORD m,n,i,j;
	CString FilePath;

	m=imgA.GetSize();
	if(m==0)
		return FALSE;
	n=imgA[0].GetSize();
	if(n==0)
		return FALSE;

	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			char s1[8],s2[8];
			itoa(i,s1,10);
			itoa(j,s2,10);
			FilePath=dir+"\\"+name+s1+"_"+s2+"."+type;
			if(!((CImage*)(imgA[i][j]))->WriteToFile(FilePath))
				return FALSE;
		}
	return TRUE;
}