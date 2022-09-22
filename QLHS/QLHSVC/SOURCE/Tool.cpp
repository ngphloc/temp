#include "Tool.h"
#include "stdafx.h"

void SplitString(CString szS,TCHAR ch, CStringArray& aszR)
{
	aszR.RemoveAll();
	szS.TrimLeft(ch);
	szS.TrimLeft();
	szS.TrimRight(ch);
	szS.TrimRight();
	while(!szS.IsEmpty())
	{
		int index = szS.Find(ch);
		if(index == -1)		
		{
			aszR.Add(szS);
			break;
		}
		CString tempS = szS.Left(index);
		tempS.TrimRight();
		if(!tempS.IsEmpty())
			aszR.Add(tempS);
		szS.TrimLeft((LPCTSTR)tempS);
		szS.TrimLeft(ch);
		szS.TrimLeft();
	}
}
void SplitString(CString szS,LPCTSTR lpszS, CStringArray& aszR)
{
	aszR.RemoveAll();
	szS.TrimLeft(lpszS);
	szS.TrimLeft();
	szS.TrimRight(lpszS);
	szS.TrimRight();
	while(!szS.IsEmpty())
	{
		int index = szS.Find(lpszS);
		if(index == -1)		
		{
			aszR.Add(szS);
			break;
		}
		CString tempS = szS.Left(index);
		tempS.TrimRight();
		if(!tempS.IsEmpty())
			aszR.Add(tempS);
		szS.TrimLeft((LPCTSTR)tempS);
		szS.TrimLeft(lpszS);
		szS.TrimLeft();
	}
}

void StringArrayToString(CStringArray& aszX, CString& szY)
{
	szY.Empty();
	if(aszX.GetSize()==0)	return;
	for(int i=0;i<aszX.GetSize()-1;i++)
	{
		szY += aszX[i];
		szY +=',';
	}
	szY +=aszX[i];

}
