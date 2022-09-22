; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CQlhsView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "qlhs.h"
LastPage=0

ClassCount=8
Class1=CInPlaceFrame
Class2=CMainFrame
Class3=CQlhsApp
Class4=CAboutDlg
Class5=CQlhsDoc
Class6=CQlhsView

ResourceCount=8
Resource1="IDR_QLHSTYPE_SRVR_IP"
Resource2=IDD_ABOUTBOX
Resource3=IDR_SRVR_INPLACE
Resource4=IDD_LOGON_DIALOG
Resource5=IDR_MAINFRAME
Resource6=IDD_QLHS_FORM
Class7=CLogonDlg
Resource7=IDR_SRVR_EMBEDDED
Class8=CProviderDlg
Resource8=IDD_PROVIDER_DIALOG

[CLS:CInPlaceFrame]
Type=0
BaseClass=COleIPFrameWnd
HeaderFile=IpFrame.h
ImplementationFile=IpFrame.cpp

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
VirtualFilter=fWC
LastObject=CMainFrame

[CLS:CQlhsApp]
Type=0
BaseClass=CWinApp
HeaderFile=Qlhs.h
ImplementationFile=Qlhs.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=Qlhs.cpp
ImplementationFile=Qlhs.cpp

[CLS:CQlhsDoc]
Type=0
BaseClass=COleServerDoc
HeaderFile=QlhsDoc.h
ImplementationFile=QlhsDoc.cpp

[CLS:CQlhsView]
Type=0
BaseClass=CFormView
HeaderFile=QlhsView.h
ImplementationFile=QlhsView.cpp
LastObject=CQlhsView
Filter=D
VirtualFilter=VWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_QLHS_FORM]
Type=1
Class=CQlhsView
ControlCount=61
Control1=IDC_STATIC,static,1342308865
Control2=IDC_ADD_BUTTON,button,1342242816
Control3=IDC_DELETE_BUTTON,button,1342242816
Control4=IDC_UPDATE_BUTTON,button,1342242816
Control5=IDC_FIND_BUTTON,button,1342242816
Control6=IDC_QLHS_TAB,SysTabControl32,1342177280
Control7=IDC_MAHS_STATIC,static,1342308352
Control8=IDC_HOTENHS_STATIC,static,1342308352
Control9=IDC_NAMHS_CHECK,button,1342242851
Control10=IDC_NGAYSINHHS_STATIC,static,1342308352
Control11=IDC_DIACHIHS_STATIC,static,1342308352
Control12=IDC_DIENHS_STATIC,static,1342308352
Control13=IDC_SONGAYVANG_STATIC,static,1342308352
Control14=IDC_MAHS_EDIT,edit,1350631552
Control15=IDC_HOTENHS_EDIT,edit,1350631552
Control16=IDC_NGAYSINHHS_EDIT,edit,1350631552
Control17=IDC_DIACHIHS_EDIT,edit,1350631552
Control18=IDC_DIENHS_EDIT,edit,1350631552
Control19=IDC_SONGAYVANG_EDIT,edit,1350631552
Control20=IDC_HOCSINH_LIST,SysListView32,1350631425
Control21=IDC_MAGV_STATIC,static,1342308352
Control22=IDC_HOTENGV_STATIC,static,1342308352
Control23=IDC_NAMGV_CHECK,button,1342242851
Control24=IDC_NGAYSINHGV_STATIC,static,1342308352
Control25=IDC_DIACHIGV_STATIC,static,1342308352
Control26=IDC_GHICHUGV_STATIC,static,1342308352
Control27=IDC_MAGV_EDIT,edit,1350631552
Control28=IDC_HOTENGV_EDIT,edit,1350631552
Control29=IDC_NGAYSINHGV_EDIT,edit,1350631552
Control30=IDC_DIACHIGV_EDIT,edit,1350631552
Control31=IDC_GHICHUGV_EDIT,edit,1350631552
Control32=IDC_GIAOVIEN_LIST,SysListView32,1350631425
Control33=IDC_MALOP_STATIC,static,1342308352
Control34=IDC_TENLOP_STATIC,static,1342308352
Control35=IDC_KHOILOP_STATIC,static,1342308352
Control36=IDC_NIENKHOA_STATIC,static,1342308352
Control37=IDC_PHONG_STATIC,static,1342308352
Control38=IDC_SISO_STATIC,static,1342308352
Control39=IDC_GHICHULOP_STATIC,static,1342308352
Control40=IDC_MALOP_EDIT,edit,1350631552
Control41=IDC_TENLOP_EDIT,edit,1350631552
Control42=IDC_LOP_LIST,SysListView32,1350631425
Control43=IDC_GHICHULOP_EDIT,edit,1350631552
Control44=IDC_KHOILOP_COMBO,combobox,1344340227
Control45=IDC_NIENKHOA_COMBO,combobox,1344340227
Control46=IDC_PHONG_COMBO,combobox,1344340227
Control47=IDC_SISO_EDIT,edit,1350631552
Control48=IDC_MAMH_STATIC,static,1342308352
Control49=IDC_TENMH_STATIC,static,1342308352
Control50=IDC_SOTIET_STATIC,static,1342308352
Control51=IDC_HESO_STATIC,static,1342308352
Control52=IDC_GHICHUMH_STATIC,static,1342308352
Control53=IDC_MAMH_EDIT,edit,1350631552
Control54=IDC_TENMH_EDIT,edit,1350631552
Control55=IDC_SOTIET_EDIT,edit,1350631552
Control56=IDC_HESO_EDIT,edit,1350631552
Control57=IDC_GHICHUMH_EDIT,edit,1350631552
Control58=IDC_MONHOC_LIST,SysListView32,1350631425
Control59=IDC_HOC_BUTTON,button,1342242816
Control60=IDC_DIEM_BUTTON,button,1342242816
Control61=IDC_BAOCAO_BUTTON,button,1342242816

[DLG:"IDR_QLHSTYPE_SRVR_IP"]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_RECORD_FIRST
Command9=ID_RECORD_PREV
Command10=ID_RECORD_NEXT
Command11=ID_RECORD_LAST
Command12=ID_APP_ABOUT
Command13=ID_CONTEXT_HELP
CommandCount=13

[TB:IDR_SRVR_INPLACE]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_RECORD_FIRST
Command5=ID_RECORD_PREV
Command6=ID_RECORD_NEXT
Command7=ID_RECORD_LAST
Command8=ID_APP_ABOUT
Command9=ID_CONTEXT_HELP
CommandCount=9

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_SEND_MAIL
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_HELP_FINDER
Command18=ID_APP_ABOUT
CommandCount=18

[MNU:IDR_SRVR_INPLACE]
Type=1
Class=?
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
Command5=ID_VIEW_TOOLBAR
Command6=ID_HELP_FINDER
Command7=ID_APP_ABOUT
CommandCount=7

[MNU:IDR_SRVR_EMBEDDED]
Type=1
Class=?
Command1=ID_FILE_UPDATE
Command2=ID_FILE_SAVE_COPY_AS
Command3=ID_FILE_PRINT
Command4=ID_FILE_PRINT_PREVIEW
Command5=ID_FILE_PRINT_SETUP
Command6=ID_FILE_SEND_MAIL
Command7=ID_APP_EXIT
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_VIEW_TOOLBAR
Command13=ID_VIEW_STATUS_BAR
Command14=ID_HELP_FINDER
Command15=ID_APP_ABOUT
CommandCount=15

[ACL:IDR_MAINFRAME]
Type=1
Class=?
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

[ACL:IDR_SRVR_INPLACE]
Type=1
Class=?
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_CONTEXT_HELP
Command10=ID_HELP
Command11=ID_CANCEL_EDIT_SRVR
CommandCount=11

[ACL:IDR_SRVR_EMBEDDED]
Type=1
Class=?
Command1=ID_FILE_UPDATE
Command2=ID_FILE_PRINT
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_NEXT_PANE
Command12=ID_PREV_PANE
Command13=ID_CONTEXT_HELP
Command14=ID_HELP
CommandCount=14

[DLG:IDR_MAINFRAME]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_LOGON_DIALOG]
Type=1
Class=CLogonDlg
ControlCount=18
Control1=IDC_SERVER_EDIT,edit,1350631552
Control2=IDC_WINNT_RADIO,button,1342177289
Control3=IDC_SQL_RADIO,button,1342177289
Control4=IDC_LOGINNAME_EDIT,edit,1350631552
Control5=IDC_PASSWORD_EDIT,edit,1350631584
Control6=IDOK,button,1342242817
Control7=IDCANCEL,button,1342242816
Control8=ID_CONTEXT_HELP,button,1342242817
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_DATABASE_EDIT,edit,1350631552
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_PROGID_EDIT,edit,1350633600
Control18=IDC_CHANGE_BUTTON,button,1342242816

[CLS:CLogonDlg]
Type=0
HeaderFile=LogonDlg.h
ImplementationFile=LogonDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CLogonDlg
VirtualFilter=dWC

[DLG:IDD_PROVIDER_DIALOG]
Type=1
Class=CProviderDlg
ControlCount=4
Control1=IDC_PROVIDER_EDIT,edit,1350631552
Control2=IDCANCEL,button,1342242816
Control3=IDOK,button,1342242817
Control4=IDC_STATIC,static,1342308352

[CLS:CProviderDlg]
Type=0
HeaderFile=ProviderDlg.h
ImplementationFile=ProviderDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC
