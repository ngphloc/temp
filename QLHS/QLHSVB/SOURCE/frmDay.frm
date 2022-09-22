VERSION 5.00
Object = "{00028C01-0000-0000-0000-000000000046}#1.0#0"; "DBGRID32.OCX"
Begin VB.Form frmDay 
   Caption         =   "Day"
   ClientHeight    =   4770
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7650
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
   ScaleHeight     =   4770
   ScaleWidth      =   7650
   StartUpPosition =   3  'Windows Default
   Begin VB.Data DataGridDay 
      Caption         =   "Data1"
      Connect         =   "Access"
      DatabaseName    =   "D:\CNPM\qlhs.mdb"
      DefaultCursorType=   0  'DefaultCursor
      DefaultType     =   2  'UseODBC
      Exclusive       =   0   'False
      Height          =   360
      Left            =   4440
      Options         =   0
      ReadOnly        =   0   'False
      RecordsetType   =   1  'Dynaset
      RecordSource    =   "Day"
      Top             =   3120
      Visible         =   0   'False
      Width           =   2775
   End
   Begin MSDBGrid.DBGrid DBGridDay 
      Bindings        =   "frmDay.frx":0000
      Height          =   2895
      Left            =   3480
      OleObjectBlob   =   "frmDay.frx":001A
      TabIndex        =   16
      Top             =   120
      Width           =   4095
   End
   Begin VB.CommandButton cmdChonMH 
      Caption         =   "Choïn moân hoïc"
      Height          =   375
      Left            =   4080
      TabIndex        =   15
      Top             =   4080
      Width           =   1575
   End
   Begin VB.ComboBox cmbMaMH 
      DataField       =   "MaMH"
      DataSource      =   "DataDay"
      Height          =   375
      Left            =   1440
      TabIndex        =   14
      Top             =   1920
      Width           =   1335
   End
   Begin VB.CommandButton cmdThoat 
      Caption         =   "Thoaùt"
      Height          =   375
      Left            =   6000
      TabIndex        =   12
      Top             =   4080
      Width           =   1455
   End
   Begin VB.CommandButton cmdChonLop 
      Caption         =   "Choïn Lôùp"
      Height          =   375
      Left            =   6000
      TabIndex        =   11
      Top             =   3360
      Width           =   1455
   End
   Begin VB.CommandButton cmdChonGV 
      Caption         =   "Choïn Giaùo Vieân"
      Height          =   375
      Left            =   4080
      TabIndex        =   10
      Top             =   3360
      Width           =   1575
   End
   Begin VB.CommandButton cmdGhiDay 
      Caption         =   "Ghi Daïy"
      Height          =   375
      Left            =   1800
      TabIndex        =   9
      Top             =   4080
      Width           =   1095
   End
   Begin VB.CommandButton cmdXoaDay 
      Caption         =   "Xoùa Daïy"
      Height          =   375
      Left            =   240
      TabIndex        =   8
      Top             =   4080
      Width           =   1215
   End
   Begin VB.CommandButton cmdChonDay 
      Caption         =   "Choïn Daïy"
      Height          =   375
      Left            =   1800
      TabIndex        =   7
      Top             =   3360
      Width           =   1095
   End
   Begin VB.Data DataDay 
      Connect         =   "Access"
      DatabaseName    =   "D:\CNPM\qlhs.mdb"
      DefaultCursorType=   0  'DefaultCursor
      DefaultType     =   2  'UseODBC
      Exclusive       =   0   'False
      Height          =   360
      Left            =   240
      Options         =   0
      ReadOnly        =   0   'False
      RecordsetType   =   1  'Dynaset
      RecordSource    =   "Day"
      Top             =   2640
      Width           =   2295
   End
   Begin VB.CommandButton cmdThemDay 
      Caption         =   "Theâm Daïy"
      Height          =   375
      Left            =   240
      TabIndex        =   6
      Top             =   3360
      Width           =   1215
   End
   Begin VB.ComboBox cmbMaLop 
      DataField       =   "MaLop"
      DataSource      =   "DataDay"
      Height          =   375
      Left            =   1440
      TabIndex        =   5
      Top             =   1320
      Width           =   1335
   End
   Begin VB.ComboBox cmbMaGV 
      DataField       =   "MaGV"
      DataSource      =   "DataDay"
      Height          =   375
      Left            =   1440
      TabIndex        =   3
      Top             =   720
      Width           =   1335
   End
   Begin VB.TextBox txtMaDay 
      DataField       =   "MaDay"
      DataSource      =   "DataDay"
      Height          =   375
      Left            =   1440
      TabIndex        =   1
      Top             =   120
      Width           =   1335
   End
   Begin VB.Label lbMaMH 
      Caption         =   "Maõ moân MH"
      Height          =   375
      Left            =   240
      TabIndex        =   13
      Top             =   1920
      Width           =   1095
   End
   Begin VB.Label lbMaLop 
      Caption         =   "Maõ lôùp"
      Height          =   375
      Left            =   240
      TabIndex        =   4
      Top             =   1320
      Width           =   855
   End
   Begin VB.Label lbMaHS 
      Caption         =   "Maõ GV"
      Height          =   375
      Left            =   240
      TabIndex        =   2
      Top             =   720
      Width           =   735
   End
   Begin VB.Label lbMaDay 
      Caption         =   "Maõ Daïy"
      Height          =   375
      Left            =   240
      TabIndex        =   0
      Top             =   120
      Width           =   855
   End
End
Attribute VB_Name = "frmDay"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Private OldSourceXepLop As String
Private SQL As String
Private GridSQL As String

Private Sub cmdChonDay_Click()
    Dim s1, s2 As String
    Load frmChonDay
    frmChonDay.Show 1
    s1 = SQL
    s2 = GridSQL
    If (MaDay = "") Or (IsNull(MaDay)) Then Exit Sub
    SQL = SQL & " WHERE Day.MaDay =  " & MaDay
    GridSQL = GridSQL & " WHERE Day.MaDay =  " & MaDay
    
    DataDay.RecordSource = SQL
    DataDay.Refresh
    DataGridDay.RecordSource = GridSQL
    DataGridDay.Refresh
    SQL = s1
    GridSQL = s2
    txtMaDay.Locked = True
    cmbMaGV.Locked = False
    cmbMaLop.Locked = False
    cmbMaMH.Locked = False
    cmdThemDay.SetFocus

End Sub

Private Sub cmdChonGV_Click()
    Dim s1, s2 As String
    Load frmChonGV
    frmChonGV.Show 1
    s1 = SQL
    s2 = GridSQL
    If (MaGV = "") Or (IsNull(MaGV)) Then Exit Sub
    SQL = SQL & " WHERE Day.MaGV =  " & MaGV
    GridSQL = GridSQL & " WHERE Day.MaGV =  " & MaGV
    DataDay.RecordSource = SQL
    DataDay.Refresh
    DataGridDay.RecordSource = GridSQL
    DataGridDay.Refresh
    
    SQL = s1
    GridSQL = s2
    txtMaDay.Locked = False
    cmbMaGV.Locked = True
    cmbMaLop.Locked = False
    cmbMaMH.Locked = False
    cmdThemDay.SetFocus

End Sub

Private Sub cmdChonLop_Click()
    Dim s1, s2 As String
    Load frmChonLop
    frmChonLop.Show 1
    s1 = SQL
    s2 = GridSQL
    If (MaLop = "") Or (IsNull(MaLop)) Then Exit Sub
    SQL = SQL & " WHERE Day.MaLop =  " & MaLop
    GridSQL = GridSQL & " WHERE Day.MaLop =  " & MaLop
    DataDay.RecordSource = SQL
    DataDay.Refresh
    DataGridDay.RecordSource = GridSQL
    DataGridDay.Refresh
    
    SQL = s1
    GridSQL = s2
    txtMaDay.Locked = False
    cmbMaGV.Locked = False
    cmbMaLop.Locked = True
    cmbMaMH.Locked = False
    cmdThemDay.SetFocus

End Sub

Private Sub cmdChonMH_Click()
    Dim s1, s2 As String
    Load frmChonMH
    frmChonMH.Show 1
    s1 = SQL
    s2 = GridSQL
    If (MaMH = "") Or (IsNull(MaMH)) Then Exit Sub
    SQL = SQL & " WHERE Day.MaMH =  " & MaMH
    GridSQL = GridSQL & " WHERE Day.MaMH =  " & MaMH
    DataDay.RecordSource = SQL
    DataDay.Refresh
    DataGridDay.RecordSource = GridSQL
    DataGridDay.Refresh
    
    SQL = s1
    GridSQL = s2
    txtMaDay.Locked = False
    cmbMaGV.Locked = False
    cmbMaLop.Locked = False
    cmbMaMH.Locked = True
    cmdThemDay.SetFocus

End Sub

Private Sub cmdGhiDay_Click()
    If (txtMaDay.Text = "") Or (IsNull(txtMaDay.Text)) Then
        MsgBox "Gia tri nay khong the de trong ", 16, "Loi"
        Exit Sub
    End If
    If (cmbMaGV.Text = "") Or (IsNull(cmbMaGV.Text)) Then
        MsgBox "Gia tri nay khong the de trong ", 16, "Loi"
        Exit Sub
    End If
    If (cmbMaLop.Text = "") Or (IsNull(cmbMaLop.Text)) Then
        MsgBox "Gia tri nay khong the de trong ", 16, "Loi"
        Exit Sub
    End If
    If (cmbMaMH.Text = "") Or (IsNull(cmbMaMH.Text)) Then
        MsgBox "Gia tri nay khong the de trong ", 16, "Loi"
        Exit Sub
    End If
    DataDay.Refresh
    DataGridDay.Refresh
    txtMaDay.Locked = False
    cmbMaGV.Locked = False
    cmbMaLop.Locked = False
    cmbMaMH.Locked = False
End Sub

Private Sub cmdThemDay_Click()
    DataDay.Recordset.AddNew
    If txtMaDay.Locked = True Then
        txtMaDay.Locked = False
        txtMaDay.Text = MaDay
        txtMaDay.Locked = True
    End If
    If cmbMaGV.Locked = True Then
        cmbMaGV.Locked = False
        cmbMaGV.Text = MaGV
        cmbMaGV.Locked = True
    End If
    If cmbMaLop.Locked = True Then
        cmbMaLop.Locked = False
        cmbMaLop.Text = MaLop
        cmbMaLop.Locked = True
    End If
    If cmbMaMH.Locked = True Then
        cmbMaMH.Locked = False
        cmbMaMH.Text = MaMH
        cmbMaMH.Locked = True
    End If
    
    If txtMaDay.Locked = False Then txtMaDay.SetFocus
    If cmbMaGV.Locked = False Then cmbMaGV.SetFocus
    If cmbMaLop.Locked = False Then cmbMaLop.SetFocus
    If cmbMaMH.Locked = False Then cmbMaMH.SetFocus

End Sub

Private Sub cmdThoat_Click()
    MsgBox "Ban nen cap nhat lai tat ca ", 48, "Nhac"
    Unload Me
End Sub

Private Sub cmdXoaDay_Click()
    Dim i As Integer
    i = MsgBox("Ban co chac chan xoa khong ? ", 289, "Kiem tra")
    If i = 2 Then Exit Sub
     With DataDay.Recordset
        .Delete
        If (.RecordCount > 0) Then
            .MoveNext
            If .EOF Then .MoveLast
        End If
    End With
End Sub

Private Sub DataDay_Validate(Action As Integer, Save As Integer)
     Screen.MousePointer = vbDefault
    On Error Resume Next
    DataDay.Caption = "Record: " & (DataDay.Recordset.AbsolutePosition + 1)

End Sub

Private Sub DataGridDay_Error(DataErr As Integer, Response As Integer)
     MsgBox "Data error event hit err:" & Error$(DataErr)
     Response = 0  'Throw away the error
End Sub

Private Sub DataGridDay_Validate(Action As Integer, Save As Integer)
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
    
    DataDay.DatabaseName = DBPath
    DataGridDay.DatabaseName = DBPath
    SQL = "SELECT * FROM Day "
    
    GridSQL = "SELECT Day.MaDay, GiaoVien.MaGV, GiaoVien.HoTenGV, "
    GridSQL = GridSQL & "Lop.MaLop, Lop.TenLop, Lop.NienKhoa, MonHoc.MaMH, "
    GridSQL = GridSQL & "MonHoc.TenMH, MonHoc.Sotiet, MonHoc.Heso "
    GridSQL = GridSQL & "FROM MonHoc INNER JOIN (Lop INNER JOIN  "
    GridSQL = GridSQL & "(GiaoVien INNER JOIN Day ON GiaoVien.MaGV = Day.MaGV) ON Lop.MaLop = Day.MaLop) ON MonHoc.MaMH = Day.MaMH  "
    DataDay.RecordSource = SQL
    DataGridDay.RecordSource = GridSQL

    cSQL = "SELECT  MaGV from GiaoVien"
    Set wk = DBEngine.CreateWorkspace("", "Admin", "", dbUseJet)
    Set Db = wk.OpenDatabase(DBPath)
    Set rs = Db.OpenRecordset(cSQL)
    With rs
        While Not (.EOF)
            cmbMaGV.AddItem rs.Fields(0), 0
            .MoveNext
        Wend
    End With
    cmbMaGV.Text = cmbMaGV.List(0)

    rs.Close
    cSQL = "SELECT  MaLop from Lop"
    Set rs = Db.OpenRecordset(cSQL)
    With rs
        While Not (.EOF)
            cmbMaLop.AddItem rs.Fields(0), 0
            .MoveNext
        Wend
    End With
    cmbMaLop.Text = cmbMaLop.List(0)
    
    rs.Close
    cSQL = "SELECT  MaMH from MonHoc"
    Set rs = Db.OpenRecordset(cSQL)
    With rs
        While Not (.EOF)
            cmbMaMH.AddItem rs.Fields(0), 0
            .MoveNext
        Wend
    End With
    cmbMaMH.Text = cmbMaMH.List(0)
    
    MaDay = txtMaDay.Text
    MaGV = cmbMaGV.Text
    MaLop = cmbMaLop.Text
    MaMH = cmbMaMH.Text
    
    txtMaDay.Locked = False
    cmbMaGV.Locked = False
    cmbMaLop.Locked = False
    cmbMaMH.Locked = False
    
    rs.Close
    Db.Close
    wk.Close
End Sub

Private Sub Form_Unload(Cancel As Integer)
    Screen.MousePointer = vbDefault
End Sub
