VERSION 5.00
Begin VB.Form frmChonHS 
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Chon Hoc Sinh"
   ClientHeight    =   3195
   ClientLeft      =   45
   ClientTop       =   285
   ClientWidth     =   4680
   BeginProperty Font 
      Name            =   "VNI-Times"
      Size            =   9.75
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   ShowInTaskbar   =   0   'False
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdQuayVeHS 
      Caption         =   "Quay Veà"
      Height          =   375
      Left            =   3000
      TabIndex        =   7
      Top             =   2640
      Visible         =   0   'False
      Width           =   1095
   End
   Begin VB.CommandButton cmdThucHienHS 
      Caption         =   "Thöïc Hieän"
      Height          =   375
      Left            =   600
      TabIndex        =   6
      Top             =   2640
      Visible         =   0   'False
      Width           =   1095
   End
   Begin VB.CommandButton cmdTraCuuHS 
      Caption         =   "Tra Cöùu"
      Height          =   375
      Left            =   600
      TabIndex        =   5
      Top             =   2640
      Width           =   1095
   End
   Begin VB.CommandButton cmdNhan 
      Caption         =   "Nhaän"
      Height          =   375
      Left            =   3000
      TabIndex        =   4
      Top             =   2640
      Width           =   1095
   End
   Begin VB.Data DataHocSinh 
      Connect         =   "Access"
      DatabaseName    =   "D:\CNPM\qlhs.mdb"
      DefaultCursorType=   0  'DefaultCursor
      DefaultType     =   2  'UseODBC
      Exclusive       =   0   'False
      Height          =   375
      Left            =   1080
      Options         =   0
      ReadOnly        =   0   'False
      RecordsetType   =   1  'Dynaset
      RecordSource    =   "HocSinh"
      Top             =   1920
      Width           =   2415
   End
   Begin VB.TextBox txtHoTenHS 
      DataField       =   "HoTenHS"
      DataSource      =   "DataHocSinh"
      Height          =   375
      Left            =   1800
      Locked          =   -1  'True
      TabIndex        =   3
      Top             =   1080
      Width           =   2535
   End
   Begin VB.TextBox txtMaHS 
      DataField       =   "MaHS"
      DataSource      =   "DataHocSinh"
      Height          =   375
      Left            =   1800
      Locked          =   -1  'True
      TabIndex        =   1
      Top             =   480
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "Hoï Teân Hoïc sinh"
      Height          =   375
      Left            =   240
      TabIndex        =   2
      Top             =   1080
      Width           =   1455
   End
   Begin VB.Label lbMaHS 
      Caption         =   "Maõ Hoïc sinh"
      Height          =   375
      Left            =   240
      TabIndex        =   0
      Top             =   480
      Width           =   1215
   End
End
Attribute VB_Name = "frmChonHS"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Private HSFlag As Boolean
Private OldSourceHS As String

Private Sub ChangeStatusHS()
    HSFlag = Not (HSFlag)
    cmdTraCuuHS.Visible = Not (HSFlag)
    cmdNhan.Visible = Not (HSFlag)
    cmdThucHienHS.Visible = HSFlag
    cmdQuayVeHS.Visible = HSFlag
End Sub

Private Sub cmdNhan_Click()
    txtMaHS.Locked = False
    MaHS = txtMaHS.Text
    txtMaHS.Locked = True
    Unload frmChonHS
End Sub

Private Sub cmdQuayVeHS_Click()
    ChangeStatusHS
    DataHocSinh.Refresh
    DataHocSinh.RecordSource = OldSourceHS
    DataHocSinh.Refresh
    txtMaHS.Locked = True
    txtHoTenHS.Locked = True
End Sub

Private Sub cmdThucHienHS_Click()
    Dim SQL As String
    Dim FirstPredicate As Boolean
    Dim SL As Long
    
    FirstPredicate = True
    
    'OldSourceHS = DataHocSinh.RecordSource
    SQL = "Select * from HOCSINH"
    If txtHoTenHS <> "" And txtHoTenHS <> "*" Then
        SQL = SQL & " Where HoTenHS  LIKE '*" & txtHoTenHS.Text & "*'"
        FirstPredicate = False
    End If
    
    If txtMaHS <> "" And txtMaHS <> "*" Then
        SQL = SQL _
        & IIf(FirstPredicate, " Where MaHS LIKE '*", " AND MaHS LIKE '*") _
        & txtMaHS.Text & "*'"
        FirstPredicate = False
    End If
    
    ' Thuc hien lai cau truy van lien ket voi Data control
    DataHocSinh.RecordSource = SQL
    DataHocSinh.Refresh
    If Not (DataHocSinh.Recordset.BOF) Then
        DataHocSinh.Recordset.MoveLast
        DataHocSinh.Recordset.MoveFirst
        SL = DataHocSinh.Recordset.RecordCount
        ChangeStatusHS
        MsgBox ("Tim duoc " & Str(SL) & _
        " hoc sinh thoa dieu kien ")
        txtMaHS.Locked = True
        txtHoTenHS.Locked = True
    Else
        MsgBox ("Khong tim duoc hoc sinh nao thoa dieu kien")
        cmdTraCuuHS_Click
    End If
End Sub

Private Sub cmdTraCuuHS_Click()
    ChangeStatusHS
    
    txtMaHS.Text = "*"
    txtHoTenHS.Text = "*"
    txtMaHS.Locked = False
    txtHoTenHS.Locked = False
    txtMaHS.SetFocus
End Sub

Private Sub Form_Load()
    DataHocSinh.DatabaseName = DBPath
    HSFlag = False
    OldSourceHS = DataHocSinh.RecordSource
End Sub

Private Sub DataHocSinh_Error(DataErr As Integer, Response As Integer)
     MsgBox "Data error event hit err:" & Error$(DataErr)
     Response = 0  'Throw away the error
End Sub

Private Sub DataHocSinh_Reposition()
     Screen.MousePointer = vbDefault
    On Error Resume Next
    DataHocSinh.Caption = "Record: " & (DataHocSinh.Recordset.AbsolutePosition + 1)
End Sub

Private Sub DataHocSinh_Validate(Action As Integer, Save As Integer)
     Select Case Action
        Case vbDataActionMoveFirst
        Case vbDataActionMovePrevious
        Case vbDataActionMoveNext
        Case vbDataActionMoveLast
        Case vbDataActionAddNew
        Case vbDataActionUpdate
        Case vbDataActionDelete
        Case vbDataActionFind
        Case vbDataActionBookmark
        Case vbDataActionClose
         Screen.MousePointer = vbDefault
  End Select
  Screen.MousePointer = vbHourglass
End Sub

Private Sub Form_Unload(Cancel As Integer)
    Screen.MousePointer = vbDefault
End Sub
