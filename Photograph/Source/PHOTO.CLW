; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CChooseNameDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Photo.h"
ODLFile=Photo.odl
LastPage=0

ClassCount=14
Class1=CPhotoApp
Class2=CPhotoDoc
Class3=CPhotoView
Class4=CMainFrame

ResourceCount=9
Resource1=IDD_TIP
Resource2=IDD_INFO_DIALOG
Resource3=IDD_ABOUTBOX
Resource4=IDR_PHOTOTYPE
Class5=CChildFrame
Class6=CAboutDlg
Class7=COperatorDlg
Resource5=IDD_CUT_DIALOG
Class8=CInfoDlg
Class9=CMDIClient
Class10=CBitmapClient
Class11=CHistView
Class12=CToggleBar
Resource6=IDR_OPERATOR_TOOLBAR
Resource7=IDR_MAINFRAME
Class13=CCutDlg
Resource8=IDD_OPERATOR_CHOOSE_DIALOG
Class14=CChooseNameDlg
Resource9=IDD_CHOOSE_NAME_DIALOG

[CLS:CPhotoApp]
Type=0
HeaderFile=Photo.h
ImplementationFile=Photo.cpp
Filter=N
LastObject=ID_APP_ABOUT
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CPhotoDoc]
Type=0
HeaderFile=PhotoDoc.h
ImplementationFile=PhotoDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CPhotoDoc

[CLS:CPhotoView]
Type=0
HeaderFile=PhotoView.h
ImplementationFile=PhotoView.cpp
Filter=C
LastObject=IDC_NAME
BaseClass=CScrollView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=W
LastObject=CMainFrame
BaseClass=CMDIFrameWnd
VirtualFilter=fWC


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M
LastObject=ID_FILE_PRINT
BaseClass=CMDIChildWnd
VirtualFilter=mfWC


[CLS:CAboutDlg]
Type=0
HeaderFile=Photo.cpp
ImplementationFile=Photo.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_HELP_FINDER
Command9=ID_APP_ABOUT
CommandCount=9

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_CONTEXT_HELP
Command10=ID_SCROLL_BUTTON
CommandCount=10

[MNU:IDR_PHOTOTYPE]
Type=1
Class=CPhotoView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_SEND_MAIL
Command10=ID_FILE_MRU_FILE1
Command11=ID_APP_EXIT
Command12=ID_EDIT_UNDO
Command13=ID_EDIT_CUT
Command14=ID_EDIT_COPY
Command15=ID_EDIT_PASTE
Command16=ID_VIEW_TOOLBAR
Command17=ID_VIEW_STATUS_BAR
Command18=ID_VIEW_OPERATOR_TOOLBAR
Command19=ID_IMAGE_NORMAL
Command20=ID_IMAGE_CENTER
Command21=ID_IMAGE_STRETCH
Command22=ID_IMAGE_GRAYSCALE
Command23=ID_IMAGE_CUT
Command24=ID_IMAGE_SAVEIMAGESARRAY
Command25=ID_IMAGE_INFORMATION
Command26=ID_TOOLS_OPERATOR_ADD
Command27=ID_TOOLS_OPERATOR_SUB
Command28=ID_TOOLS_OPERATOR_MUL
Command29=ID_TOOLS_OPERATOR_DIV
Command30=ID_TOOLS_OPERATOR_NOT
Command31=ID_TOOLS_OPERATOR_AND
Command32=ID_TOOLS_OPERATOR_OR
Command33=ID_TOOLS_OPERATOR_XOR
Command34=ID_TOOLS_OPERATOR_MIN
Command35=ID_TOOLS_OPERATOR_MAX
Command36=ID_TOOLS_OPERATOR_ABS
Command37=ID_TOOLS_OPERATOR_TICHCHAP
Command38=ID_TOOLS_FILTER_LINEARFILTER
Command39=ID_TOOLS_FILTER_MEDIANFILTER
Command40=ID_ENHANCE_HISTOGRAMEQUALIZATION
Command41=ID_WINDOW_NEW
Command42=ID_WINDOW_CASCADE
Command43=ID_WINDOW_TILE_HORZ
Command44=ID_WINDOW_ARRANGE
Command45=ID_WINDOW_SPLIT
Command46=ID_HELP_FINDER
Command47=ID_APP_ABOUT
CommandCount=47

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
Command15=ID_CONTEXT_HELP
Command16=ID_HELP
CommandCount=16

[DLG:IDR_MAINFRAME]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_TIP]
Type=1
Class=?
ControlCount=6
Control1=65535,static,1342177287
Control2=IDC_TIPSTRING,static,1342308352
Control3=IDC_STARTUP,button,1342373891
Control4=IDC_NEXTTIP,button,1342373888
Control5=IDOK,button,1342373889
Control6=IDC_BULB,static,1342177294

[DLG:IDD_OPERATOR_CHOOSE_DIALOG]
Type=1
Class=COperatorDlg
ControlCount=8
Control1=IDC_INTEGER_RADIO,button,1342308361
Control2=IDC_FILE_RADIO,button,1342177289
Control3=IDC_INTEGER_EDIT,edit,1484857472
Control4=IDC_BROWSE_BUTTON,button,1476460544
Control5=IDCANCEL,button,1342242816
Control6=IDOK,button,1342242817
Control7=IDC_STATIC,button,1342177287
Control8=IDC_REVERSED_CHECK,button,1476460547

[CLS:COperatorDlg]
Type=0
HeaderFile=OperatorDlg.h
ImplementationFile=OperatorDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=COperatorDlg

[DLG:IDD_INFO_DIALOG]
Type=1
Class=CInfoDlg
ControlCount=5
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_BITMAPINFOHEADER_MSFLEXGRID,{6262D3A0-531B-11CF-91F6-C2863C385E30},1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_BITMAPFILEHEADER_MSFLEXGRID,{6262D3A0-531B-11CF-91F6-C2863C385E30},1342242816

[CLS:CInfoDlg]
Type=0
HeaderFile=InfoDlg.h
ImplementationFile=InfoDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CInfoDlg

[CLS:CMDIClient]
Type=0
HeaderFile=MDIClient.h
ImplementationFile=MDIClient.cpp
BaseClass=CFrameWnd
Filter=T
VirtualFilter=fWC
LastObject=CMDIClient

[CLS:CBitmapClient]
Type=0
HeaderFile=BitmapClient.h
ImplementationFile=BitmapClient.cpp
BaseClass=CFrameWnd
Filter=T
VirtualFilter=fWC
LastObject=CBitmapClient

[CLS:CHistView]
Type=0
HeaderFile=HistView.h
ImplementationFile=HistView.cpp
BaseClass=CScrollView
Filter=C

[CLS:CToggleBar]
Type=0
HeaderFile=ToggleBar.h
ImplementationFile=ToggleBar.cpp
BaseClass=CStatusBar
Filter=W
LastObject=CToggleBar

[TB:IDR_OPERATOR_TOOLBAR]
Type=1
Class=CMainFrame
Command1=ID_TOOLS_OPERATOR_ADD
Command2=ID_TOOLS_OPERATOR_SUB
Command3=ID_TOOLS_OPERATOR_MUL
Command4=ID_TOOLS_OPERATOR_DIV
Command5=ID_TOOLS_OPERATOR_NOT
Command6=ID_TOOLS_OPERATOR_AND
Command7=ID_TOOLS_OPERATOR_OR
Command8=ID_TOOLS_OPERATOR_XOR
Command9=ID_TOOLS_OPERATOR_MIN
Command10=ID_TOOLS_OPERATOR_MAX
Command11=ID_TOOLS_OPERATOR_ABS
Command12=ID_TOOLS_OPERATOR_TICHCHAP
CommandCount=12

[DLG:IDD_CUT_DIALOG]
Type=1
Class=CCutDlg
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_MEDIT,edit,1350639744
Control5=IDC_STATIC,static,1342308352
Control6=IDC_NEDIT,edit,1350639744
Control7=IDC_STATIC,static,1342308352
Control8=IDC_MVIEWEDIT,edit,1350639744
Control9=IDC_STATIC,static,1342308352
Control10=IDC_NVIEWEDIT,edit,1350639744
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352

[CLS:CCutDlg]
Type=0
HeaderFile=CutDlg.h
ImplementationFile=CutDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CCutDlg
VirtualFilter=dWC

[DLG:IDD_CHOOSE_NAME_DIALOG]
Type=1
Class=CChooseNameDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_DIR,edit,1350631552

[CLS:CChooseNameDlg]
Type=0
HeaderFile=ChooseNameDlg.h
ImplementationFile=ChooseNameDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_DIR

