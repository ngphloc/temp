// CheckDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Check.h"
#include "CheckDlg.h"
#include "MSFlexGrid.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

//Cac bien toan cung

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCheckDlg dialog

CCheckDlg::CCheckDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCheckDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCheckDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	Flag = FALSE;
	PlayStatus = TRUE;
	Ignore = FALSE;

	WinCount = 5;
	Rows = 14;
	Cols = 14;
	UINT n = Rows*Cols;
	if(n>1000)
	{
		n=1000;
		Rows = 50;
		Cols = 20; 
	}
	aCheck.SetSize(n);

	for(UINT i=0;i<n;i++)
		aCheck.SetAt(i,BLANK);
}

void CCheckDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCheckDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCheckDlg, CDialog)
	//{{AFX_MSG_MAP(CCheckDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RESET_BUTTON, OnResetButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCheckDlg message handlers

BOOL CCheckDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	CMSFlexGrid* pGrid=(CMSFlexGrid*)GetDlgItem(IDC_CHECK_MSFLEXGRID);

	pGrid->SetCols(Cols);
	pGrid->SetRows(Rows);
	for(UINT i=0;i<Rows;i++)
		pGrid->SetRowHeight(i,300);
	for(i=0;i<Cols;i++)
		pGrid->SetColWidth(i,300);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCheckDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCheckDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCheckDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BEGIN_EVENTSINK_MAP(CCheckDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CCheckDlg)
	ON_EVENT(CCheckDlg, IDC_CHECK_MSFLEXGRID, -600 /* Click */, OnClickCheckMsflexgrid, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CCheckDlg::OnClickCheckMsflexgrid() 
{
	// TODO: Add your control notification handler code here
	if(PlayStatus)
	{
		if(!Flag)
		{
			CMSFlexGrid* pGrid=(CMSFlexGrid*)GetDlgItem(IDC_CHECK_MSFLEXGRID);
			UINT row=pGrid->GetRowSel();
			UINT col=pGrid->GetColSel();
			int n = row*Cols + col;
			UINT tempValue;
	
			if(aCheck[n]!=BLANK)
				return;
	
			pGrid->SetCellForeColor(RGB(255,0,128));
			pGrid->SetRow(row);
			pGrid->SetCol(col);
			pGrid->SetText(" X");
	
			aCheck.SetAt(n,YOURS);
			if(IsCanWin(aCheck,Rows,Cols,YOURS,n,tempValue)==WIN)
			{
				CEdit* pEdit = (CEdit*)GetDlgItem(IDC_WINNER_EDIT);
				pEdit->SetWindowText("You are Winner");
				PlayStatus = FALSE;
				return;
			}
			
			if(!Ignore)
			{
				UINT i,j;
				UINT row_begin,col_begin;
				UINT row_end,col_end;
				UINT tempRows,tempCols;
				CUIntArray tempCheck;
				UINT tempMove=0;	
				for(i=0;i<Rows;i++)
				{
					for(j=0;j<Cols;j++)
						if(aCheck[i*Cols+j]!=BLANK)
							break;
					if(j<Cols)
						break;
				}
				row_begin=i>1 ? i-2:0; 
				for(j=0;j<Cols;j++)
				{
					for(i=0;i<Rows;i++)
						if(aCheck[i*Cols+j]!=BLANK)
							break;
					if(i<Rows)
						break;
				}
				col_begin=j>1 ? j-2:0; 


				for(i=Rows-1;i<=0;i--)
				{
					for(j=Cols-1;j<=0;j--)
						if(aCheck[i*Cols+j]!=BLANK)
							break;
					if(j<=0)
						break;
				}
				row_end=i<Rows-2 ? i+2:Rows-1; 
				for(j=Cols-1;j<=0;j--)
				{
					for(i=Rows-1;i<=0;i--)
						if(aCheck[i*Cols+j]!=BLANK)
							break;
					if(i<=0)
						break;
				}
				col_end=j<Cols-2 ? j+2:Cols-1; 
	
				tempRows=row_end-row_begin+1;
				tempCols=col_end-col_begin+1;
				n=tempRows*tempCols;
				if(n<=0)
					return;
				if(n==(int)Rows*(int)Cols)
					Ignore=TRUE;
				tempCheck.SetSize(n);
				for(i=0;i<tempRows;i++)
					for(j=0;j<tempCols;j++)
					{
						UINT n=i*tempCols+j;
						UINT m=(i+row_begin)*Cols+(j+col_begin);
						tempCheck[n]=aCheck[m];
					}
				
				Flag = TRUE;
				if(ChooseMyMove(tempCheck,tempRows,tempCols,tempMove))
				{
					row = tempMove/tempCols+row_begin;
					col = tempMove%tempCols+col_begin;
	
					pGrid->SetCellForeColor(RGB(255,0,255));
					pGrid->SetRow(row);
					pGrid->SetCol(col);
					pGrid->SetText(" O");
	
					UINT MyMove = row*Cols + col;
					aCheck[MyMove]=MINE;
					if(IsCanWin(aCheck,Rows,Cols,MINE,MyMove,tempValue)==WIN)
					{
						CEdit* pEdit = (CEdit*)GetDlgItem(IDC_WINNER_EDIT);
						pEdit->SetWindowText("I am Winner");
						PlayStatus = FALSE;
						return;
					}
					Flag = FALSE;
				}
			}
			else
			{
				Flag = TRUE;
				UINT MyMove=0;
				if(ChooseMyMove(aCheck,Rows,Cols,MyMove))
				{
	
					row = MyMove / Cols;
					col = MyMove % Cols;
					pGrid->SetCellForeColor(RGB(255,0,255));
					pGrid->SetRow(row);
					pGrid->SetCol(col);
					pGrid->SetText(" O");
	
					aCheck[MyMove]=MINE;
					if(IsCanWin(aCheck,Rows,Cols,MINE,MyMove,tempValue)==WIN)
					{
						CEdit* pEdit = (CEdit*)GetDlgItem(IDC_WINNER_EDIT);
						pEdit->SetWindowText("I am Winner");
						PlayStatus = FALSE;
						return;
					}
					Flag = FALSE;
				}
			
			}
		}
	}
}

BOOL CCheckDlg::ChooseMyMove(CUIntArray& aCheck,UINT Rows,UINT Cols,UINT &MyMove)
{
	UINT i,j,n,temp;
	n=Rows*Cols;
	int  max=INT_MIN;
	CUIntArray aCanWin,aResult;
	CUIntArray aCanWinValue,aResultValue;
	UINT Value;

	for(i=0;i<n;i++)
	{
		if(aCheck[i] == BLANK)
		{
			aCheck[i] = MINE;
			UINT ret = IsCanWin(aCheck,Rows,Cols,MINE,i,Value);
			if(ret==WIN)
			{
				MyMove = i;
				return TRUE;
			}
			else if(ret==CANWIN)
			{
				max = INT_MAX;
				aCanWin.Add(i);
				aCanWinValue.Add(Value);
			}

			int min = INT_MAX;
			for(j=0;j<n;j++)
			{
				if(aCheck[j] == BLANK)
				{
					
					aCheck[j]=YOURS;
					UINT ret = IsCanWin(aCheck,Rows,Cols,YOURS,j,Value);
					if(ret==WIN)
					{
						MyMove = j;
						aCheck[i] = BLANK;
						return TRUE;
					}
					else if(ret==CANWIN)
					{
						min  = INT_MIN;
						temp = j;
						aCheck[j]=BLANK;	
						break;
					}
					int value = Estimate(aCheck,Rows,Cols);
					if(min>value)
						min = value;
					aCheck[j]=BLANK;	
				}
			}
			if(min==INT_MAX)
			{
				MyMove = i;
				return TRUE;
			}
			else if(min==INT_MIN)
				max = min+1;
			else if(max<min)
			{
				max = min;
				aResult.RemoveAll();
				aResult.Add(i);
				aResultValue.RemoveAll();
				aResultValue.Add(Value);
			}
			else  if(max==min)
			{
				aResult.Add(i);
				aResultValue.Add(Value);
			}

			aCheck[i] = BLANK;
		}
	}
	if(max == INT_MIN+1)
	{
		MyMove = temp;
		return TRUE;
	}
	else if(max==INT_MIN)
		return FALSE;
	else
	{
		CUIntArray aTemp;
		if(aCanWin.GetSize())
		{
			max=INT_MIN;
			for(i=0;i<(UINT)aCanWin.GetSize();i++)
			{
				if(max<(int)aCanWinValue[i])
				{
					max = aCanWinValue[i];
					aTemp.RemoveAll();
					aTemp.Add(aCanWin[i]);
				}
				else if(max==(int)aCanWinValue[i])
					aTemp.Add(aCanWin[i]);
			}
			
		}
		else
		{
			max=INT_MIN;
			for(i=0;i<(UINT)aResult.GetSize();i++)
			{
				if(max<(int)aResultValue[i])
				{
					max = aResultValue[i];
					aTemp.RemoveAll();
					aTemp.Add(aResult[i]);
				}
				else if(max==(int)aResultValue[i])
					aTemp.Add(aResult[i]);
			}
		}
		max=INT_MIN;
		for(i=0;i<(UINT)aTemp.GetSize();i++)
		{
			UINT Value;
			aCheck[aTemp[i]]=YOURS;
			IsCanWin(aCheck,Rows,Cols,YOURS,aTemp[i],Value);
			aCheck[aTemp[i]]=BLANK;

			if(max<(int)Value)
			{
				max =Value; 
				MyMove = aTemp[i];
			}
		}

		return TRUE;
	}
}

int CCheckDlg::Estimate(CUIntArray& aCheck,UINT Rows,UINT Cols,UINT User)
{
	if(User!=MINE && User!=YOURS)
		return 0;
	int Value;
	UINT i,j,count;

	Value = 0;	

	for(i=0;i<Rows;i++)
	{
		count = 0;
		for(j=0;j<Cols;j++)
		{
			UINT n;
			n=i*Cols+j;

			if(aCheck[n]!=User && aCheck[n]!=BLANK)
				count = 0;
			else
				count++;
			if(count==WinCount)
			{
				Value++;
				break;
			}
		}	
	}
	for(j=0;j<Cols;j++)
	{
		count = 0;
		for(i=0;i<Rows;i++)
		{
			UINT n;
			n=i*Cols+j;
			if(aCheck[n]!=User && aCheck[n]!=BLANK)
				count = 0;
			else
				count++;
			if(count==WinCount)
			{
				Value++;
				break;
			}
		}	
	}
	//Duong cheo xuoi
	for(i=0;i<Rows+Cols-1;i++)
	{
		UINT begin,end;
		begin = (i<Cols) ? (Cols-1-i):((i+1-Cols)*Cols);  
		end   = (i<Rows) ? (i*Cols+Cols-1):((Rows-1)*Cols + Rows+Cols-2-i);  

		count=0;
		for(j=begin;j<=end;j+=Cols+1)
		{
			if(aCheck[j]!=User && aCheck[j]!=BLANK)
				count = 0;
			else
				count++;
			if(count==WinCount)
			{
				Value++;
				break;
			}
		}

	}
	//Duong cheo nguoc
	for(i=0;i<Rows+Cols-1;i++)
	{
		UINT begin,end;
		begin = (i<Rows) ? (i*Cols):((Rows-1)*Cols + i+1-Rows);  
		end   = (i<Cols) ? (i):((i+1-Cols)*Cols + Cols-1);  

		count=0;
		for(j=end;j<=begin;j-=Cols-1)
		{
			if(aCheck[j]!=User && aCheck[j]!=BLANK)
				count = 0;
			else
				count++;
			if(count==WinCount)
			{
				Value++;
				break;
			}
		}

	}
	return Value;
}

int CCheckDlg::Estimate(CUIntArray& aCheck,UINT Rows,UINT Cols)
{
	return (Estimate(aCheck,Rows,Cols,MINE) - Estimate(aCheck,Rows,Cols,YOURS));
}


UINT CCheckDlg::IsCanWin(CUIntArray& aCheck,UINT Rows,UINT Cols,UINT User,UINT Move,UINT& Value)
{
	if(User!=MINE && User!=YOURS)
		return NOTWIN;
	UINT  row,col;
	int   begin,end;
	int   i;
	UINT  count;
	UINT  n=WinCount;
	BOOL  BeginFlag,EndFlag;
	BOOL  Space;
	row = Move / Cols;
	col = Move % Cols;
	Value = 0;
	//Dong
	begin = row*Cols;
	end   = row*Cols+Cols-1;
	count = 1;
	if(count >= WinCount)
		return WIN;
	Space = FALSE;
	BeginFlag  = FALSE;
	for(i=Move+1;i<=end;i++)
	{
		if(aCheck[i]==User)
			count++;
		else if(aCheck[i]==BLANK)
		{
			if(!Space)
			{
				if(i<end&&aCheck[i+1]==User)
				{
					i++;
					count++;
					BeginFlag = FALSE;
					Space=TRUE;
					continue;
				}
				BeginFlag = TRUE;//co gap khoan trang
				break;
			}

			BeginFlag = TRUE;//co gap khoan trang
			break;
		}
		else
		{
			BeginFlag=FALSE;
			break;
		}
	}

	EndFlag = FALSE;
	for(i=Move-1;i>=begin;i--)
	{
		if(aCheck[i]==User)
			count++;
		else if(aCheck[i]==BLANK )
		{
			if(!Space)
			{	
				if(i>begin&&aCheck[i-1]==User)
				{
					i--;
					count++;
					EndFlag = FALSE;
					Space = TRUE;
					continue;
				}
				EndFlag = TRUE;
				break;
			}
			EndFlag=TRUE;
			break;
		}
		else
		{
			EndFlag = FALSE;
			break;
		}
	}
	Value +=count;
	if(BeginFlag&&EndFlag)
	{
		if(!Space)
		{
			if(count>=WinCount)
				return WIN;
			if(count>=n-1)
				return CANWIN;
			if(count>=n-2)
				n--;
		}
		else 
		{
			if(count>=n)
				return CANWIN;
			if(count>=n-2)
				n--;
		}
	}
	if(!BeginFlag||!EndFlag)
	{
		if(!Space)
		{
			if(count>=WinCount)
				return WIN;
			if(count>=n)
				return CANWIN;
			if(count>=n-1)
				n--;
		}
	}
		
	//Cot
	begin = col;
	end   = (Rows-1)*Cols+col;
	count = 1;
	if(count >= WinCount)
		return WIN;
	Space = FALSE;
	BeginFlag  = FALSE;
	for(i=Move+Cols;i<=end;i+=Cols)
	{
		if(aCheck[i]==User)
			count++;
		else if(aCheck[i]==BLANK)
		{
			if(!Space)
			{
				if(i<end&&aCheck[i+Cols]==User)
				{
					i+=Cols;
					count++;
					BeginFlag = FALSE;
					Space=TRUE;
					continue;
				}
				BeginFlag = TRUE;//co gap khoan trang
				break;
			}

			BeginFlag = TRUE;//co gap khoan trang
			break;
		}
		else
		{
			BeginFlag=FALSE;
			break;
		}
	}
	EndFlag = FALSE;
	for(i=Move-Cols;i>=begin;i-=Cols)
	{
		if(aCheck[i]==User)
			count++;
		else if(aCheck[i]==BLANK )
		{
			if(!Space)
			{	
				if(i>begin&&aCheck[i-Cols]==User)
				{
					i-=Cols;
					count++;
					EndFlag = FALSE;
					Space = TRUE;
					continue;
				}
				EndFlag=TRUE;
				break;
			}
			EndFlag = TRUE;
			break;
		}
		else
		{
			EndFlag = FALSE;
			break;
		}
	}
	Value +=count;
	if(BeginFlag&&EndFlag)
	{
		if(!Space)
		{
			if(count>=WinCount)
				return WIN;
			if(count>=n-1)
				return CANWIN;
			if(count>=n-2)
				n--;
		}
		else 
		{
			if(count>=n)
				return CANWIN;
			if(count>=n-2)
				n--;
		}
	}
	if(!BeginFlag||!EndFlag)
	{
		if(!Space)
		{
			if(count>=WinCount)
				return WIN;
			if(count>=n)
				return CANWIN;
			if(count>=n-1)
				n--;
		}
	}

	
	UINT index;

	//Duong Cheo xuoi
	index = row-col+Cols-1;
	begin = (index<Cols) ? (Cols-1-index):((index+1-Cols)*Cols);  
	end   = (index<Rows) ? (index*Cols+Cols-1):((Rows-1)*Cols + Rows+Cols-2-index);  
	BeginFlag  = FALSE;
	Space=FALSE;
	count = 1;
	if(count >= WinCount)
		return WIN;
	for(i=Move+Cols+1;i<=end;i+=Cols+1)
	{
		if(aCheck[i]==User)
			count++;
		else if(aCheck[i]==BLANK)
		{
			if(!Space)
			{
				if(i<end&&aCheck[i+Cols+1]==User)
				{
					i+=Cols+1;
					count++;
					BeginFlag = FALSE;
					Space=TRUE;
					continue;
				}
				BeginFlag = TRUE;//co gap khoan trang
				break;
			}

			BeginFlag = TRUE;//co gap khoan trang
			break;
		}
		else
		{
			BeginFlag=FALSE;
			break;
		}
	}
	EndFlag = FALSE;
	for(i=Move-(Cols+1);i>=begin;i-=(Cols+1))
	{
		if(aCheck[i]==User)
			count++;
		else if(aCheck[i]==BLANK )
		{
			if(!Space)
			{	
				if(i>begin&&aCheck[i-(Cols+1)]==User)
				{
					i-=(Cols+1);
					count++;
					EndFlag = FALSE;
					Space = TRUE;
					continue;
				}
				EndFlag=TRUE;
				break;
			}
			EndFlag = TRUE;
			break;
		}
		else
		{
			EndFlag = FALSE;
			break;
		}
	}
	Value +=count;
	if(BeginFlag&&EndFlag)
	{
		if(!Space)
		{
			if(count>=WinCount)
				return WIN;
			if(count>=n-1)
				return CANWIN;
			if(count>=n-2)
				n--;
		}
		else 
		{
			if(count>=n)
				return CANWIN;
			if(count>=n-2)
				n--;
		}
	}
	if(!BeginFlag||!EndFlag)
	{
		if(!Space)
		{
			if(count>=WinCount)
				return WIN;
			if(count>=n)
				return CANWIN;
			if(count>=n-1)
				n--;
		}
	}


	//Duong cheo nguoc
	index = row+col;
	begin = (index<Rows) ? (index*Cols):((Rows-1)*Cols + index+1-Rows);  
	end   = (index<Cols) ? (index):((index+1-Cols)*Cols + Cols-1);  
	BeginFlag  = FALSE;
	Space = FALSE;
	count = 1;
	if(count >= WinCount)
		return WIN;
	for(i=Move+Cols-1;i<=begin;i+=Cols-1)
	{
		if(aCheck[i]==User)
			count++;
		else if(aCheck[i]==BLANK)
		{
			if(!Space)
			{
				if(i<begin&&aCheck[i+Cols-1]==User)
				{
					i+=Cols-1;
					count++;
					BeginFlag = FALSE;
					Space=TRUE;
					continue;
				}
				BeginFlag = TRUE;//co gap khoan trang
				break;
			}

			BeginFlag = TRUE;//co gap khoan trang
			break;
		}
		else
		{
			BeginFlag=FALSE;
			break;
		}
	}
	EndFlag = FALSE;
	for(i=Move-(Cols-1);i>=end;i-=(Cols-1))
	{
		if(aCheck[i]==User)
			count++;
		else if(aCheck[i]==BLANK )
		{
			if(!Space)
			{	
				if(i>end&&aCheck[i-(Cols-1)]==User)
				{
					i-=(Cols-1);
					count++;
					EndFlag = FALSE;
					Space = TRUE;
					continue;
				}
				EndFlag=TRUE;
				break;
			}
			EndFlag = TRUE;
			break;
		}
		else
		{
			EndFlag = FALSE;
			break;
		}
	}
	Value +=count;
	if(BeginFlag&&EndFlag)
	{
		if(!Space)
		{
			if(count>=WinCount)
				return WIN;
			if(count>=n-1)
				return CANWIN;
			if(count>=n-2)
				n--;
		}
		else 
		{
			if(count>=n)
				return CANWIN;
			if(count>=n-2)
				n--;
		}
	}
	if(!BeginFlag||!EndFlag)
	{
		if(!Space)
		{
			if(count>=WinCount)
				return WIN;
			if(count>=n)
				return CANWIN;
			if(count>=n-1)
				n--;
		}
	}

	return NOTWIN;
}

void CCheckDlg::OnResetButton() 
{
	// TODO: Add your control notification handler code here
	CMSFlexGrid* pGrid=(CMSFlexGrid*)GetDlgItem(IDC_CHECK_MSFLEXGRID);
	Flag = FALSE;
	PlayStatus = TRUE;
	Ignore = FALSE;
	UINT n = Rows*Cols;

	for(UINT i=0;i<n;i++)
		aCheck.SetAt(i,BLANK);
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_WINNER_EDIT);
	pEdit->SetWindowText("");

	pGrid->Clear();	
}
