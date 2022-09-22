VERSION 5.00
Object = "{00028C01-0000-0000-0000-000000000046}#1.0#0"; "DBGRID32.OCX"
Begin VB.Form frmXepLop 
   Caption         =   "Xep lop"
   ClientHeight    =   5745
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   8670
   BeginProperty Font 
      Name            =   "VNI-Times"
      Size            =   9.75
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "Form2"
   ScaleHeight     =   5745
   ScaleWidth      =   8670
   StartUpPosition =   3  'Windows Default
   Begin VB.ComboBox cmbMaLop 
      DataField       =   "Malop"
      DataSource      =   "DataXepLop"
      Height          =   375
      Left            =   1200
      TabIndex        =   13
      Top             =   2400
      Width           =   1455
   End
   Begin VB.ComboBox cmbMaHS 
      DataField       =   "MaHS"
      DataSource      =   "DataXepLop"
      Height          =   375
      Left            =   1200
      TabIndex        =   12
      Top             =   1320
      Width           =   1455
   End
   Begin VB.Data DataGridXepLop 
      Caption         =   "Data1"
      Connect         =   "Access"
      DatabaseName    =   "D:\CNPM\qlhs.mdb"
      DefaultCursorType=   0  'DefaultCursor
      DefaultType     =   2  'UseODBC
      Exclusive       =   0   'False
      Height          =   360
      Left            =   4680
      Options         =   0
      ReadOnly        =   0   'False
      RecordsetType   =   1  'Dynaset
      RecordSource    =   ""
      Top             =   3600
      Visible         =   0   'False
      Width           =   2415
   End
   Begin VB.CommandButton cmdThoat 
      Caption         =   "Thoaùt"
      Height          =   375
      Left            =   5280
      TabIndex        =   11
      Top             =   4920
      Width           =   1695
   End
   Begin VB.CommandButton cmdGhiXepLop 
      Caption         =   "Ghi Xeáp Lôùp"
      Height          =   375
      Left            =   1920
      TabIndex        =   10
      Top             =   4920
      Width           =   1575
   End
   Begin VB.CommandButton cmdChonLop 
      Caption         =   "Choïn Lôùp"
      Height          =   375
      Left            =   6360
      TabIndex        =   9
      Top             =   4080
      Width           =   1575
   End
   Begin VB.CommandButton cmdChonXepLop 
      Caption         =   "Choïn Xeáp Lôùp"
      Height          =   375
      Left            =   1920
      TabIndex        =   8
      Top             =   4080
      Width           =   1575
   End
   Begin MSDBGrid.DBGrid DBGridXepLop 
      Bindings        =   "frmXepLop.frx":0000
      Height          =   3495
      Left            =   3240
      OleObjectBlob   =   "frmXepLop.frx":003D
      TabIndex        =   7
      Top             =   0
      Width           =   5415
   End
   Begin VB.CommandButton cmdXoaXepLop 
      Caption         =   "Xoùa Xeáp Lôùp"
      Height          =   375
      Left            =   0
      TabIndex        =   6
      Top             =   4920
      Width           =   1575
   End
   Begin VB.Data DataXepLop 
      Connect         =   "Access"
      DatabaseName    =   "D:\CNPM\qlhs.mdb"
      DefaultCursorType=   0  'DefaultCursor
      DefaultType     =   2  'UseODBC
      Exclusive       =   0   'False
      Height          =   375
      Left            =   360
      Options         =   0
      ReadOnly        =   0   'False
      RecordsetType   =   1  'Dynaset
      RecordSource    =   "XepLop"
      Top             =   3120
      Width           =   2340
   End
   Begin VB.CommandButton cmdChonHS 
      Caption         =   "Choïn Hoïc sinh"
      Height          =   375
      Left            =   4440
      TabIndex        =   5
      Top             =   4080
      Width           =   1575
   End
   Begin VB.CommandButton cmdThemXepLop 
      Caption         =   "Theâm Xeáp Lôùp"
      Height          =   375
      Left            =   0
      TabIndex        =   4
      Top             =   4080
      Width           =   1575
   End
   Begin VB.TextBox txtMaXepLop 
      DataField       =   "MaXepLop"
      DataSource      =   "DataXepLop"
      Height          =   375
      Left            =   1200
      TabIndex        =   3
      Top             =   240
      Width           =   1335
   End
   Begin VB.Label lbXepLop 
      Caption         =   "Maõ Xeáp lôùp"
      Height          =   375
      Left            =   0
      TabIndex        =   2
      Top             =   240
      Width           =   975
   End
   Begin VB.Label lbMaLop 
      Caption         =   "Maõ lôùp"
      Height          =   375
      Left            =   0
      TabIndex        =   1
      Top             =   2400
      Width           =   975
   End
   Begin VB.Label lblMaHS 
      Caption         =   "Maõ Hoïc Sinh"
      Height          =   375
      Left            =   0
      TabIndex        =   0
      Top             =   1320
      Width           =   1095
   End
End
Attribute VB_Name = "frmXepLop"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Private OldSourceXepLop As String
Private SQL As String
Private GridSQL As String

Private Sub cmdChonHS_Click()
    Dim s1, s2 As String
    Load frmChonHS
    frmChonHS.Show 1
    s1 = SQL
    s2 = GridSQL
    If (MaHS = "") Or (IsNull(MaHS)) Then Exit Sub
    SQL = SQL & " WHERE XepLop.MaHS =  " & MaHS
    GridSQL = GridSQL & " WHERE XepLop.MaHS =  " & MaHS
    DataXepLop.RecordSource = SQL
    DataXepLop.Refresh
    DataGridXepLop.RecordSource = GridSQL
    DataGridXepLop.Refresh
    
    SQL = s1
    GridSQL = s2
    txtMaXepLop.Locked = False
    cmbMaHS.Locked = True
    cmbMaLop.Locked = False
    cmdThemXepLop.SetFocus
End Sub

Private Sub cmdChonLop_Click()
    Dim s1, s2 As String
    Load frmChonLop
    frmChonLop.Show 1
    s1 = SQL
    s2 = GridSQL
    If (MaLop = "") Or (IsNull(MaLop)) Then Exit Sub
    SQL = SQL & " WHERE XepLop.MaLop =  " & MaLop
    GridSQL = GridSQL & " WHERE XepLop.MaLop =  " & MaLop
    
    DataXepLop.RecordSource = SQL
    DataXepLop.Refresh
    DataGridXepLop.RecordSource = GridSQL
    DataGridXepLop.Refresh
    SQL = s1
    GridSQL = s2
    txtMaXepLop.Locked = False
    cmbMaHS.Locked = False
    cmbMaLop.Locked = True
    cmdThemXepLop.SetFocus
End Sub

Private Sub cmdChonXepLop_Click()
    Dim s1, s2 As String
    Load frmChonXepLop
    frmChonXepLop.Show 1
    s1 = SQL
    s2 = GridSQL
    If (MaXepLop = "") Or (IsNull(MaXepLop)) Then Exit Sub
    SQL = SQL & " WHERE XepLop.MaXepLop =  " & MaXepLop
    GridSQL = GridSQL & " WHERE XepLop.MaXepLop =  " & MaXepLop
    
    DataXepLop.RecordSource = SQL
    DataXepLop.Refresh
    DataGridXepLop.RecordSource = GridSQL
    DataGridXepLop.Refresh
    SQL = s1
    GridSQL = s2
    txtMaXepLop.Locked = True
    cmbMaHS.Locked = False
    cmbMaLop.Locked = False
    cmdThemXepLop.SetFocus
End Sub

Private Sub cmdGhiXepLop_Click()
    Dim wk As Workspace
    Dim Db As Database
    Dim rs As Recordset
    Dim cSQL As String
    Dim Lop(1000) As Integer
    Dim NienKhoa(1000) As Integer
    Dim i As Integer
    Dim n As Integer
    Dim a, b As Integer
    Dim DTBHKI As Single
    Dim DTBHKII As Single
    Dim DTBCN As Single
    
    If (txtMaXepLop.Text = "") Or (IsNull(txtMaXepLop.Text)) Then
        MsgBox "Gia tri nay khong the de trong ", 16, "Loi"
        Exit Sub
    End If
    If (cmbMaHS.Text = "") Or (IsNull(cmbMaHS.Text)) Then
        MsgBox "Gia tri nay khong the de trong ", 16, "Loi"
        Exit Sub
    End If
    If (cmbMaLop.Text = "") Or (IsNull(cmbMaLop.Text)) Then
        MsgBox "Gia tri nay khong the de trong ", 16, "Loi"
        Exit Sub
    End If
    
    Set wk = DBEngine.CreateWorkspace("", "Admin", "", dbUseJet)
    Set Db = wk.OpenDatabase(DBPath)
    cSQL = "SELECT Lop.NienKhoa, Lop.KhoiLop "
    cSQL = cSQL & "FROM XepLop INNER JOIN Lop ON XepLop.MaLop = Lop.MaLop "
    If cmbMaHS.Locked = True Then
        cmbMaHS.Locked = False
        cSQL = cSQL & "WHERE XepLop.MaHS =  " & cmbMaHS.Text
        cmbMaHS.Locked = True
    Else
        cSQL = cSQL & "WHERE XepLop.MaHS =  " & cmbMaHS.Text
    End If
    
    Set rs = Db.OpenRecordset(cSQL)
    'rs.MoveLast
    If rs.RecordCount > 0 Then
        rs.MoveFirst
        n = rs.RecordCount
        'ReDim Lop(rs.RecordCount)
        'ReDim NienKhoa(rs.RecordCount)
        i = 0
        Do While (Not rs.EOF)
            NienKhoa(i) = rs.Fields(0).Value
            Lop(i) = rs.Fields(1).Value
            i = i + 1
            rs.MoveNext
        Loop
        rs.MoveFirst
        
        
        cSQL = "SELECT NienKhoa, KhoiLop "
        cSQL = cSQL & "FROM Lop WHERE MaLop = " & cmbMaLop.Text
        Set rs = Db.OpenRecordset(cSQL)
        a = rs.Fields(0).Value
        b = rs.Fields(1).Value
        For i = 0 To n - 1
            If ((NienKhoa(i) < a) And (Lop(i) > b)) Or ((NienKhoa(i) > a) And (Lop(i) < b)) Then
                MsgBox "Khong the co tinh trang tuong tu nhu : " + Chr(13) + _
                        "Mot HS Khoa 1996 hoc lop 11 nhung khoa 1997  lai" + Chr(13) + _
                        "hoc lop 10.Neu NK1>NK2 thi Khoi lop 1>=Khoi lop 2", 16, "Loi "
                GoTo kt
                
            End If
            If (NienKhoa(i) = a) Then
                MsgBox "Trong cung mot Nien Khoa Hoc sinh nay Khong the" + Chr(13) + _
                    "hoc hai khoi lop hay hai lop khac nhau.Ban can phai xep lop lai ", 16, "Loi"
                GoTo kt
            End If
            If (NienKhoa(i) < a) Then
                DTBHKI = 0
                DTBHKII = 0
                DTBCN = 0
                DiemTB Val(cmbMaHS.Text), Val(NienKhoa(i)), DTBHKI, DTBHKII, DTBCN
                If (Lop(i) < b) And (DTBCN < 5) Then
                    MsgBox "Hoc Sinh nay co Diem trung binh <5 nen khong  " + Chr(13) + _
                        "duoc len lop.Ban can phai xep lop lai ", 16, "Loi"
                    GoTo kt
                End If
            End If
        Next i
    End If
    DataXepLop.Refresh
    DataGridXepLop.Refresh
kt:
    rs.Close
    Db.Close
    wk.Close
    txtMaXepLop.Locked = False
    cmbMaHS.Locked = False
    cmbMaLop.Locked = False
End Sub

Private Sub cmdThemXepLop_Click()
    DataXepLop.Recordset.AddNew
    If txtMaXepLop.Locked = True Then
        txtMaXepLop.Locked = False
        txtMaXepLop.Text = MaXepLop
        txtMaXepLop.Locked = True
    End If
    If cmbMaHS.Locked = True Then
        cmbMaHS.Locked = False
        cmbMaHS.Text = MaHS
        cmbMaHS.Locked = True
    End If
    If cmbMaLop.Locked = True Then
        cmbMaLop.Locked = False
        cmbMaLop.Text = MaLop
        cmbMaLop.Locked = True
    End If
    
    If txtMaXepLop.Locked = False Then txtMaXepLop.SetFocus
    If cmbMaHS.Locked = False Then cmbMaHS.SetFocus
    If cmbMaLop.Locked = False Then cmbMaLop.SetFocus
    
End Sub

Private Sub cmdThoat_Click()
     MsgBox "Ban nen cap nhat lai tat ca ", 48, "Kiem tra"
    Unload frmXepLop
End Sub

Private Sub cmdXoaXepLop_Click()
    Dim i As Integer
    i = MsgBox("Ban co chac chan xoa khong ? ", 289, "Kiem tra")
    If i = 2 Then Exit Sub
     With DataXepLop.Recordset
        .Delete
        If (.RecordCount > 0) Then
            .MoveNext
            If .EOF Then .MoveLast
        End If
    End With
End Sub

Private Sub Form_Load()
    Dim cSQL As String
    Dim wk As Workspace
    Dim Db As Database
    Dim rs As Recordset
    
    DataXepLop.DatabaseName = DBPath
    DataGridXepLop.DatabaseName = DBPath
    SQL = "SELECT * FROM XepLop "
    GridSQL = "SELECT XepLop.MaXepLop, HocSinh.MaHS, HocSinh.HoTenHS , "
    GridSQL = GridSQL & "Lop.MaLop, Lop.TenLop, Lop.NienKhoa,Lop.KhoiLop  "
    GridSQL = GridSQL & " FROM Lop INNER JOIN ( HocSinh INNER JOIN XepLop ON  "
    GridSQL = GridSQL & "HocSinh.MaHS = XepLop.MaHS ) ON Lop.MaLop = XepLop.MaLop "
    DataXepLop.RecordSource = SQL
    DataGridXepLop.RecordSource = GridSQL

    cSQL = "SELECT  MaHS from HocSinh"
    Set wk = DBEngine.CreateWorkspace("", "Admin", "", dbUseJet)
    Set Db = wk.OpenDatabase(DBPath)
    Set rs = Db.OpenRecordset(cSQL)
    With rs
        While Not (.EOF)
            cmbMaHS.AddItem rs.Fields(0), 0
            .MoveNext
        Wend
    End With
    cmbMaHS.Text = cmbMaHS.List(0)
    rs.Close
    Db.Close
    wk.Close

    cSQL = "SELECT  MaLop from Lop"
    Set wk = DBEngine.CreateWorkspace("", "Admin", "", dbUseJet)
    Set Db = wk.OpenDatabase(DBPath)
    Set rs = Db.OpenRecordset(cSQL)
    With rs
        While Not (.EOF)
            cmbMaLop.AddItem rs.Fields(0), 0
            .MoveNext
        Wend
    End With
    cmbMaLop.Text = cmbMaLop.List(0)
    rs.Close
    Db.Close
    wk.Close
    
    MaXepLop = txtMaXepLop.Text
    MaHS = cmbMaHS.Text
   MaLop = cmbMaLop.Text
    txtMaXepLop.Locked = False
    cmbMaHS.Locked = False
    cmbMaLop.Locked = False
End Sub
Private Sub DataXepLop_Error(DataErr As Integer, Response As Integer)
     MsgBox "Data error event hit err:" & Error$(DataErr)
     Response = 0  'Throw away the error
End Sub

Private Sub DataXepLop_Reposition()
    Dim wk As Workspace
    Dim Db As Database
    Dim rs As Recordset
    Dim cSQL As String
    Dim Lop(1000) As Integer
    Dim NienKhoa(1000) As Integer
    Dim i As Integer
    Dim n As Integer
    Dim a, b As Integer
    Dim DTBHKI As Single
    Dim DTBHKII As Single
    Dim DTBCN As Single
     Screen.MousePointer = vbDefault
    On Error Resume Next
    DataXepLop.Caption = "Record: " & (DataXepLop.Recordset.AbsolutePosition + 1)
    
    If (cmbMaHS.Text = "") Or (IsNull(cmbMaHS.Text)) Then Exit Sub
    If (cmbMaLop.Text = "") Or (IsNull(cmbMaLop.Text)) Then Exit Sub
    
    Set wk = DBEngine.CreateWorkspace("", "Admin", "", dbUseJet)
    Set Db = wk.OpenDatabase(DBPath)
    cSQL = "SELECT Lop.NienKhoa, Lop.KhoiLop "
    cSQL = cSQL & "FROM XepLop INNER JOIN Lop ON XepLop.MaLop = Lop.MaLop "
    If cmbMaHS.Locked = True Then
        cmbMaHS.Locked = False
        cSQL = cSQL & "WHERE XepLop.MaHS =  " & cmbMaHS.Text
        cmbMaHS.Locked = True
    Else
        cSQL = cSQL & "WHERE XepLop.MaHS =  " & cmbMaHS.Text
    End If
    
    Set rs = Db.OpenRecordset(cSQL)
    'rs.MoveLast
    If rs.RecordCount > 0 Then
        rs.MoveFirst
        n = rs.RecordCount
        'ReDim Lop(rs.RecordCount)
        'ReDim NienKhoa(rs.RecordCount)
        i = 0
        Do While (Not rs.EOF)
            NienKhoa(i) = rs.Fields(0).Value
            Lop(i) = rs.Fields(1).Value
            i = i + 1
            rs.MoveNext
        Loop
        rs.MoveFirst
        
        
        cSQL = "SELECT NienKhoa, KhoiLop "
        cSQL = cSQL & "FROM Lop WHERE MaLop = " & cmbMaLop.Text
        Set rs = Db.OpenRecordset(cSQL)
        a = rs.Fields(0).Value
        b = rs.Fields(1).Value
        For i = 0 To n - 1
            If ((NienKhoa(i) < a) And (Lop(i) > b)) Or ((NienKhoa(i) > a) And (Lop(i) < b)) Then
                MsgBox "Khong the co tinh trang tuong tu nhu : " + Chr(13) + _
                        "Mot HS Khoa 1996 hoc lop 11 nhung khoa 1997 " + Chr(13) + _
                        "lai hoc lop 10.Neu NK1>NK2 thi Khoi Lop1>=Khoi Lop2 ", 16, "Loi "
                GoTo kt
                
            End If
            'If (NienKhoa(i) = a) Then
                'MsgBox "Trong cung mot Nien Khoa Hoc sinh Khong " + Chr(13) + _
                    '"the hoc hai khoi lop hay hai lop khac nhau ", 16, "Loi"
                'GoTo kt
            'End If
            If (NienKhoa(i) < a) Then
                DTBHKI = 0
                DTBHKII = 0
                DTBCN = 0
                DiemTB Val(cmbMaHS.Text), Val(NienKhoa(i)), DTBHKI, DTBHKII, DTBCN
                If (Lop(i) < b) And (DTBCN < 5) Then
                    MsgBox "Hoc Sinh nay co Diem trung binh <5 nen khong " + Chr(13) + _
                        "duoc len lop.Ban phai xep lop lai cho HS nay ", 16, "Loi"
                    GoTo kt
                End If
            End If
        Next i
    End If
    'DataXepLop.Refresh
    'DataGridXepLop.Refresh
kt:
    rs.Close
    Db.Close
    wk.Close
    txtMaXepLop.Locked = False
    cmbMaHS.Locked = False
    cmbMaLop.Locked = False
End Sub

Private Sub DataXepLop_Validate(Action As Integer, Save As Integer)
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
