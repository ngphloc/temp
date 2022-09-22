// CheckDlg.h : header file
//

#if !defined(AFX_CHECKDLG_H__8CC1C167_2E95_11D4_A3E3_D5FB84E78949__INCLUDED_)
#define AFX_CHECKDLG_H__8CC1C167_2E95_11D4_A3E3_D5FB84E78949__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCheckDlg dialog
#define		BLANK	0
#define		MINE	1
#define		YOURS	2

#define		NOTWIN	0
#define		CANWIN	1
#define		WIN		2

class CCheckDlg : public CDialog
{
// Construction
public:
	CCheckDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCheckDlg)
	enum { IDD = IDD_CHECK_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCheckDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	BOOL Flag;
	BOOL PlayStatus;
	BOOL Ignore;

	UINT WinCount;
	UINT Rows,Cols;
	CUIntArray aCheck;//Ban co

protected:
	UINT IsCanWin(CUIntArray& aCheck,UINT Rows,UINT Cols,UINT User,UINT Move,UINT& Value);
	int  Estimate(CUIntArray& aCheck,UINT Rows,UINT Cols);
	int  Estimate(CUIntArray& aCheck,UINT Rows,UINT Cols,UINT User);
	BOOL ChooseMyMove(CUIntArray& aCheck,UINT Rows,UINT Cols,UINT& MyMove);
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCheckDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClickCheckMsflexgrid();
	afx_msg void OnResetButton();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHECKDLG_H__8CC1C167_2E95_11D4_A3E3_D5FB84E78949__INCLUDED_)
