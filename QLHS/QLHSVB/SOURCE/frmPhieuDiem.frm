VERSION 5.00
Object = "{00028C01-0000-0000-0000-000000000046}#1.0#0"; "DBGRID32.OCX"
Begin VB.Form frmPhieuDiem 
   Caption         =   "Phieu Diem"
   ClientHeight    =   5835
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6240
   LinkTopic       =   "Form1"
   ScaleHeight     =   5835
   ScaleWidth      =   6240
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdKetQua 
      Caption         =   "Keát quaû"
      BeginProperty Font 
         Name            =   "VNI-Times"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   2640
      TabIndex        =   12
      Top             =   5280
      Width           =   975
   End
   Begin VB.TextBox txtMaHS 
      DataField       =   "MaHS"
      DataSource      =   "DataDiem"
      Height          =   375
      Left            =   1200
      TabIndex        =   11
      Top             =   3480
      Width           =   1215
   End
   Begin VB.ComboBox cmbHinhThucKT 
      DataField       =   "HinhThucKT"
      DataSource      =   "DataDiem"
      Height          =   315
      ItemData        =   "frmPhieuDiem.frx":0000
      Left            =   4920
      List            =   "frmPhieuDiem.frx":0010
      TabIndex        =   9
      Top             =   3480
      Width           =   735
   End
   Begin VB.TextBox txtDiem 
      DataField       =   "Diem"
      DataSource      =   "DataDiem"
      BeginProperty Font 
         Name            =   "VNI-Times"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   1200
      TabIndex        =   7
      Top             =   4080
      Width           =   615
   End
   Begin VB.CommandButton cmdThoat 
      Caption         =   "Thoaùt"
      BeginProperty Font 
         Name            =   "VNI-Times"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   4800
      TabIndex        =   5
      Top             =   5280
      Width           =   1095
   End
   Begin VB.CommandButton cmdCapNhat 
      Caption         =   "Caäp nhaät"
      BeginProperty Font 
         Name            =   "VNI-Times"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   360
      TabIndex        =   4
      Top             =   5280
      Width           =   1095
   End
   Begin VB.CommandButton cmdXemDiem 
      Caption         =   "Xem Ñieåm"
      BeginProperty Font 
         Name            =   "VNI-Times"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   600
      TabIndex        =   3
      Top             =   120
      Width           =   1095
   End
   Begin VB.ComboBox cmbNienKhoa 
      Height          =   315
      ItemData        =   "frmPhieuDiem.frx":0020
      Left            =   4080
      List            =   "frmPhieuDiem.frx":0022
      TabIndex        =   2
      Top             =   120
      Width           =   1455
   End
   Begin VB.Data DataDiem 
      Connect         =   "Access"
      DatabaseName    =   "D:\CNPM\qlhs.mdb"
      DefaultCursorType=   0  'DefaultCursor
      DefaultType     =   2  'UseODBC
      Exclusive       =   0   'False
      Height          =   300
      Left            =   2040
      Options         =   0
      ReadOnly        =   0   'False
      RecordsetType   =   1  'Dynaset
      RecordSource    =   "Diem"
      Top             =   4680
      Width           =   2415
   End
   Begin MSDBGrid.DBGrid DBGridDiem 
      Bindings        =   "frmPhieuDiem.frx":0024
      Height          =   2415
      Left            =   120
      OleObjectBlob   =   "frmPhieuDiem.frx":0089
      TabIndex        =   0
      Top             =   840
      Width           =   6015
   End
   Begin VB.Label lbMaHS 
      Caption         =   "Maõ HS"
      BeginProperty Font 
         Name            =   "VNI-Times"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   240
      TabIndex        =   10
      Top             =   3480
      Width           =   735
   End
   Begin VB.Label lbHinhThucKT 
      Caption         =   "Hình thöùc  KT"
      DataField       =   "HinhThucKT"
      BeginProperty Font 
         Name            =   "VNI-Times"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   3240
      TabIndex        =   8
      Top             =   3480
      Width           =   1335
   End
   Begin VB.Label lbDiem 
      Caption         =   "Ñieåm"
      BeginProperty Font 
         Name            =   "VNI-Times"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   240
      TabIndex        =   6
      Top             =   4080
      Width           =   495
   End
   Begin VB.Label lbNienKhoa 
      Caption         =   "Nieân Khoùa"
      BeginProperty Font 
         Name            =   "VNI-Times"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   3000
      TabIndex        =   1
      Top             =   120
      Width           =   975
   End
End
Attribute VB_Name = "frmPhieuDiem"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Private SQL As String

Private Sub cmdCapNhat_Click()
    DataDiem.Refresh
End Sub

Private Sub cmdKetQua_Click()
    Load frmKetQua
    frmKetQua.Show
End Sub

Private Sub cmdThoat_Click()
    Unload frmPhieuDiem
End Sub

Private Sub cmdXemDiem_Click()
    If (cmbNienKhoa.Text = "") Or (IsNull(cmbNienKhoa.Text)) Then
        cmbNienKhoa.SetFocus
        Exit Sub
    End If
    DataDiem.RecordSource = SQL & " AND Lop.NienKhoa = " & cmbNienKhoa.Text
    DataDiem.Refresh
End Sub

Private Sub DataDiem_Error(DataErr As Integer, Response As Integer)
     MsgBox "Data error event hit err:" & Error$(DataErr)
     Response = 0  'Throw away the error
End Sub

Private Sub DataDiem_Reposition()
     Screen.MousePointer = vbDefault
    On Error Resume Next
    DataDiem.Caption = "Record: " & (DataDiem.Recordset.AbsolutePosition + 1)
End Sub

Private Sub DataDiem_Validate(Action As Integer, Save As Integer)
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

Private Sub Form_Load()
    Dim cSQL As String
    Dim wk As Workspace
    Dim Db As Database
    Dim rs As Recordset
    
    DataDiem.DatabaseName = DBPath
    cSQL = "SELECT  MaNienKhoa from NienKhoa"
    Set wk = DBEngine.CreateWorkspace("", "Admin", "", dbUseJet)
    Set Db = wk.OpenDatabase(DBPath)
    Set rs = Db.OpenRecordset(cSQL)
    With rs
        While Not (.EOF)
            cmbNienKhoa.AddItem rs.Fields(0), 0
            .MoveNext
        Wend
    End With
    cmbNienKhoa.Text = cmbNienKhoa.List(0)
    rs.Close
    Db.Close
    wk.Close
    
    SQL = "SELECT HocSinh.MaHS, HocSinh.HoTenHS, MonHoc.MaMH, MonHoc.TenMH, Diem.Diem,  "
    SQL = SQL & "MonHoc.Heso, Hoc.MaHK, Lop.NienKhoa, Lop.TenLop , Diem.HinhThucKT "
    SQL = SQL & "FROM ((((Hoc INNER JOIN XepLop ON Hoc.MaXepLop = XepLop.MaXepLop) "
    SQL = SQL & "INNER JOIN HocSinh ON XepLop.MaHS = HocSinh.MaHS) INNER JOIN Lop ON XepLop.MaLop =  "
    SQL = SQL & "Lop.MaLop) INNER JOIN MonHoc ON Hoc.MaMH = MonHoc.MaMH)  "
    SQL = SQL & " LEFT JOIN Diem ON Hoc.MaHoc = Diem.MaHoc "
    SQL = SQL & " WHERE  HocSinh.MaHS =  " & frmMain.txtMaHS.Text
    
    DataDiem.RecordSource = SQL & " AND Lop.NienKhoa = " & cmbNienKhoa.Text
    DataDiem.Refresh
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    Screen.MousePointer = vbDefault
End Sub
