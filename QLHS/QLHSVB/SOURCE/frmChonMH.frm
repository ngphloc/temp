VERSION 5.00
Begin VB.Form frmChonMH 
   Caption         =   "Chon mon hoc"
   ClientHeight    =   3105
   ClientLeft      =   60
   ClientTop       =   345
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
   ScaleHeight     =   3105
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdQuayVeMH 
      Caption         =   "Quay veà"
      Height          =   375
      Left            =   3000
      TabIndex        =   7
      Top             =   2400
      Visible         =   0   'False
      Width           =   1095
   End
   Begin VB.CommandButton cmdThucHienMH 
      Caption         =   "Thöïc hieän"
      Height          =   375
      Left            =   480
      TabIndex        =   6
      Top             =   2400
      Visible         =   0   'False
      Width           =   1095
   End
   Begin VB.CommandButton cmdNhan 
      Caption         =   "Nhaän"
      Height          =   375
      Left            =   3000
      TabIndex        =   5
      Top             =   2400
      Width           =   1095
   End
   Begin VB.CommandButton cmdTraCuuMH 
      Caption         =   "Tra cöùu"
      Height          =   375
      Left            =   480
      TabIndex        =   4
      Top             =   2400
      Width           =   1095
   End
   Begin VB.Data DataMonHoc 
      Connect         =   "Access"
      DatabaseName    =   "D:\CNPM\qlhs.mdb"
      DefaultCursorType=   0  'DefaultCursor
      DefaultType     =   2  'UseODBC
      Exclusive       =   0   'False
      Height          =   360
      Left            =   1320
      Options         =   0
      ReadOnly        =   0   'False
      RecordsetType   =   1  'Dynaset
      RecordSource    =   "MonHoc"
      Top             =   1680
      Width           =   2055
   End
   Begin VB.TextBox txtTenMH 
      DataField       =   "TenMH"
      DataSource      =   "DataMonHoc"
      Height          =   375
      Left            =   2160
      TabIndex        =   3
      Top             =   960
      Width           =   1335
   End
   Begin VB.TextBox txtMaMH 
      DataField       =   "MaMH"
      DataSource      =   "DataMonHoc"
      Height          =   375
      Left            =   2160
      TabIndex        =   1
      Top             =   360
      Width           =   1335
   End
   Begin VB.Label lbTenMH 
      Caption         =   "Teân MH"
      Height          =   375
      Left            =   840
      TabIndex        =   2
      Top             =   960
      Width           =   1095
   End
   Begin VB.Label lbMaMH 
      Caption         =   "Maõ MH"
      Height          =   375
      Left            =   840
      TabIndex        =   0
      Top             =   360
      Width           =   975
   End
End
Attribute VB_Name = "frmChonMH"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Private MHFlag As Boolean
Private OldSourceMH As String

Private Sub ChangeStatusMH()
    MHFlag = Not (MHFlag)
    cmdTraCuuMH.Visible = Not (MHFlag)
    cmdNhan.Visible = Not (MHFlag)
    cmdThucHienMH.Visible = MHFlag
    cmdQuayVeMH.Visible = MHFlag
End Sub

Private Sub cmdNhan_Click()
    txtMaMH.Locked = False
    MaMH = txtMaMH.Text
    txtMaMH.Locked = True
    Unload frmChonMH
End Sub

Private Sub cmdQuayVeMH_Click()
    ChangeStatusMH
    DataMonHoc.Refresh
    DataMonHoc.RecordSource = OldSourceMH
    DataMonHoc.Refresh
    txtMaMH.Locked = True
    txtTenMH.Locked = True
End Sub

Private Sub cmdThucHienMH_Click()
    Dim SQL As String
    Dim FirstPredicate As Boolean
    Dim SL As Long
    
    FirstPredicate = True
    
    'OldSourceMH = DataMonHoc.RecordSource
    SQL = "Select * from MONHOC"
    If txtTenMH <> "" And txtTenMH <> "*" Then
        SQL = SQL & " Where TenMH  LIKE '*" & txtTenMH.Text & "*'"
        FirstPredicate = False
    End If
    
    If txtMaMH <> "" And txtMaMH <> "*" Then
        SQL = SQL _
        & IIf(FirstPredicate, " Where MaMH LIKE '*", " AND MaMH LIKE '*") _
        & txtMaMH.Text & "*'"
        FirstPredicate = False
    End If
    
    ' Thuc hien lai cau truy van lien ket voi Data control
    DataMonHoc.RecordSource = SQL
    DataMonHoc.Refresh
    If Not (DataMonHoc.Recordset.BOF) Then
        DataMonHoc.Recordset.MoveLast
        DataMonHoc.Recordset.MoveFirst
        SL = DataMonHoc.Recordset.RecordCount
        ChangeStatusMH
        MsgBox ("Tim duoc " & Str(SL) & _
        " mon hoc thoa dieu kien ")
        txtMaMH.Locked = True
        txtTenMH.Locked = True
    Else
        MsgBox ("Khong tim duoc mon hoc nao thoa dieu kien")
        cmdTraCuuMH_Click
    End If
End Sub

Private Sub cmdTraCuuMH_Click()
    ChangeStatusMH
    
    txtMaMH.Text = "*"
    txtTenMH.Text = "*"
    txtMaMH.Locked = False
    txtTenMH.Locked = False
    txtMaMH.SetFocus
End Sub

Private Sub Form_Load()
    DataMonHoc.DatabaseName = DBPath
    MHFlag = False
    OldSourceMH = DataMonHoc.RecordSource
End Sub

Private Sub DataMonHoc_Error(DataErr As Integer, Response As Integer)
     MsgBox "Data error event hit err:" & Error$(DataErr)
     Response = 0  'Throw away the error
End Sub

Private Sub DataMonHoc_Reposition()
     Screen.MousePointer = vbDefault
    On Error Resume Next
    DataMonHoc.Caption = "Record: " & (DataMonHoc.Recordset.AbsolutePosition + 1)
End Sub

Private Sub DataMonHoc_Validate(Action As Integer, Save As Integer)
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


