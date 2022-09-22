VERSION 5.00
Begin VB.Form frmChonLop 
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Chon Lop"
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
   Begin VB.CommandButton cmdQuayVeLop 
      Caption         =   "Quay veà"
      Height          =   375
      Left            =   3000
      TabIndex        =   7
      Top             =   2640
      Visible         =   0   'False
      Width           =   1095
   End
   Begin VB.CommandButton cmdThucHienLop 
      Caption         =   "Thöïc hieän "
      Height          =   375
      Left            =   480
      TabIndex        =   6
      Top             =   2640
      Visible         =   0   'False
      Width           =   1095
   End
   Begin VB.CommandButton cmdTraCuuLop 
      Caption         =   "Tra cöùu"
      Height          =   375
      Left            =   480
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
   Begin VB.TextBox txtTenLop 
      DataField       =   "TenLop"
      DataSource      =   "DataLop"
      Height          =   375
      Left            =   2280
      TabIndex        =   3
      Top             =   1200
      Width           =   1095
   End
   Begin VB.Data DataLop 
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
      RecordSource    =   "Lop"
      Top             =   1920
      Width           =   2295
   End
   Begin VB.TextBox txtMaLop 
      DataField       =   "MaLop"
      DataSource      =   "DataLop"
      Height          =   375
      Left            =   2280
      TabIndex        =   1
      Top             =   480
      Width           =   1095
   End
   Begin VB.Label lbTenLop 
      Caption         =   "Teân Lôùp"
      Height          =   375
      Left            =   1080
      TabIndex        =   2
      Top             =   1200
      Width           =   975
   End
   Begin VB.Label lbMaLop 
      Caption         =   "Maõ lôùp"
      Height          =   375
      Left            =   1080
      TabIndex        =   0
      Top             =   480
      Width           =   975
   End
End
Attribute VB_Name = "frmChonLop"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Private LopFlag As Boolean
Private OldSourceLop As String

Private Sub ChangeStatusLop()
    LopFlag = Not (LopFlag)
    cmdTraCuuLop.Visible = Not (LopFlag)
    cmdNhan.Visible = Not (LopFlag)
    cmdThucHienLop.Visible = LopFlag
    cmdQuayVeLop.Visible = LopFlag
End Sub
Private Sub cmdNhan_Click()
    txtMaLop.Locked = False
    MaLop = txtMaLop.Text
    txtMaLop.Locked = True
    Unload frmChonLop
End Sub

Private Sub cmdQuayVeLop_Click()
    ChangeStatusLop
    DataLop.Refresh
    DataLop.RecordSource = OldSourceLop
    DataLop.Refresh
    txtMaLop.Locked = True
    txtTenLop.Locked = True
End Sub

Private Sub cmdThucHienLop_Click()
    Dim SQL As String
    Dim FirstPredicate As Boolean
    Dim SL As Long
    
    FirstPredicate = True
    
    'OldSourceMH = DataLop.RecordSource
    SQL = "Select * from LOP"
    If txtTenLop <> "" And txtTenLop <> "*" Then
        SQL = SQL & " Where TenLop  LIKE '*" & txtTenLop.Text & "*'"
        FirstPredicate = False
    End If
    
    If txtMaLop <> "" And txtMaLop <> "*" Then
        SQL = SQL _
        & IIf(FirstPredicate, " Where MaLop LIKE '*", " AND MaLop LIKE '*") _
        & txtMaLop.Text & "*'"
        FirstPredicate = False
    End If
    
    ' Thuc hien lai cau truy van lien ket voi Data control
    DataLop.RecordSource = SQL
    DataLop.Refresh
    If Not (DataLop.Recordset.BOF) Then
        DataLop.Recordset.MoveLast
        DataLop.Recordset.MoveFirst
        SL = DataLop.Recordset.RecordCount
        ChangeStatusLop
        MsgBox ("Tim duoc " & Str(SL) & _
        " lop hoc thoa dieu kien ")
        txtMaLop.Locked = True
        txtTenLop.Locked = True
    Else
        MsgBox ("Khong tim duoc lop hoc nao thoa dieu kien")
        cmdTraCuuLop_Click
    End If
End Sub

Private Sub cmdTraCuuLop_Click()
    ChangeStatusLop
    
    txtMaLop.Text = "*"
    txtTenLop.Text = "*"
    txtMaLop.Locked = False
    txtTenLop.Locked = False
    txtMaLop.SetFocus
End Sub
Private Sub Form_Load()
    DataLop.DatabaseName = DBPath
    LopFlag = False
    OldSourceLop = DataLop.RecordSource
End Sub
Private Sub DataLop_Error(DataErr As Integer, Response As Integer)
    'This is where you would put error handling code
  ' If you want to ignore errors, comment out the next line
    'If you want to trap them, add code here to handle them
     MsgBox "Data error event hit err:" & Error$(DataErr)
     Response = 0  'Throw away the error
End Sub

Private Sub DataLop_Reposition()
     Screen.MousePointer = vbDefault
    On Error Resume Next
  ' This will display the current record position for dynasets and snapshots
    DataLop.Caption = "Record: " & (DataLop.Recordset.AbsolutePosition + 1)
End Sub

Private Sub DataLop_Validate(Action As Integer, Save As Integer)
'This is where you put validation code
  'This event gets called when the following actions occur
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
