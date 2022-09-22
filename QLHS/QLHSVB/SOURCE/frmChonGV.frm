VERSION 5.00
Begin VB.Form frmChonGV 
   Caption         =   "Chon giao vien"
   ClientHeight    =   2820
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
   ScaleHeight     =   2820
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.Data DataGV 
      Connect         =   "Access"
      DatabaseName    =   "D:\CNPM\qlhs.mdb"
      DefaultCursorType=   0  'DefaultCursor
      DefaultType     =   2  'UseODBC
      Exclusive       =   0   'False
      Height          =   360
      Left            =   1560
      Options         =   0
      ReadOnly        =   0   'False
      RecordsetType   =   1  'Dynaset
      RecordSource    =   "GiaoVien"
      Top             =   1560
      Width           =   2175
   End
   Begin VB.CommandButton cmdQuayVe 
      Caption         =   "Quay veà"
      Height          =   375
      Left            =   2880
      TabIndex        =   7
      Top             =   2280
      Visible         =   0   'False
      Width           =   1095
   End
   Begin VB.CommandButton cmdThucHien 
      Caption         =   "Thöïc hieän"
      Height          =   375
      Left            =   600
      TabIndex        =   6
      Top             =   2280
      Visible         =   0   'False
      Width           =   1095
   End
   Begin VB.CommandButton cmdNhan 
      Caption         =   "Nhaän"
      Height          =   375
      Left            =   2880
      TabIndex        =   5
      Top             =   2280
      Width           =   1095
   End
   Begin VB.CommandButton cmdTraCuu 
      Caption         =   "Tra cöùu"
      Height          =   375
      Left            =   600
      TabIndex        =   4
      Top             =   2280
      Width           =   1095
   End
   Begin VB.TextBox txtHoTenGV 
      DataField       =   "HoTenGV"
      DataSource      =   "DataGV"
      Height          =   375
      Left            =   1800
      TabIndex        =   3
      Top             =   960
      Width           =   2415
   End
   Begin VB.TextBox txtMaGV 
      DataField       =   "MaGV"
      DataSource      =   "DataGV"
      Height          =   375
      Left            =   1920
      TabIndex        =   2
      Top             =   360
      Width           =   1335
   End
   Begin VB.Label lbHoTenGV 
      Caption         =   "Hoï teân GV"
      Height          =   375
      Left            =   480
      TabIndex        =   1
      Top             =   960
      Width           =   1455
   End
   Begin VB.Label lbMaGV 
      Caption         =   "Maõ Giaùo vieân"
      Height          =   375
      Left            =   480
      TabIndex        =   0
      Top             =   360
      Width           =   1335
   End
End
Attribute VB_Name = "frmChonGV"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Private GVFlag As Boolean
Private OldSourceGV As String

Private Sub ChangeStatusGV()
    GVFlag = Not (GVFlag)
    cmdTraCuu.Visible = Not (GVFlag)
    cmdNhan.Visible = Not (GVFlag)
    cmdThucHien.Visible = GVFlag
    cmdQuayVe.Visible = GVFlag
End Sub

Private Sub cmdNhan_Click()
    txtMaGV.Locked = False
    MaGV = txtMaGV.Text
    txtMaGV.Locked = True
    Unload frmChonGV
End Sub

Private Sub cmdQuayVe_Click()
    ChangeStatusGV
    DataGV.Refresh
    DataGV.RecordSource = OldSourceGV
    DataGV.Refresh
    txtMaGV.Locked = True
    txtHoTenGV.Locked = True
End Sub

Private Sub cmdThucHien_Click()
    Dim SQL As String
    Dim FirstPredicate As Boolean
    Dim SL As Long
    
    FirstPredicate = True
    
    'OldSourceHS = DataHocSinh.RecordSource
    SQL = "Select * from GIAOVIEN"
    If txtHoTenGV <> "" And txtHoTenGV <> "*" Then
        SQL = SQL & " Where HoTenGV  LIKE '*" & txtHoTenGV.Text & "*'"
        FirstPredicate = False
    End If
    
    If txtMaGV <> "" And txtMaGV <> "*" Then
        SQL = SQL _
        & IIf(FirstPredicate, " Where MaGV LIKE '*", " AND MaGV LIKE '*") _
        & txtMaGV.Text & "*'"
        FirstPredicate = False
    End If
    
    ' Thuc hien lai cau truy van lien ket voi Data control
    DataGV.RecordSource = SQL
    DataGV.Refresh
    If Not (DataGV.Recordset.BOF) Then
        DataGV.Recordset.MoveLast
        DataGV.Recordset.MoveFirst
        SL = DataGV.Recordset.RecordCount
        ChangeStatusGV
        MsgBox ("Tim duoc " & Str(SL) & _
        " giao vien thoa dieu kien ")
        txtMaGV.Locked = True
        txtHoTenGV.Locked = True
    Else
        MsgBox ("Khong tim duoc giao vien nao thoa dieu kien")
        cmdTraCuu_Click
    End If
End Sub

Private Sub cmdTraCuu_Click()
    ChangeStatusGV
    
    txtMaGV.Text = "*"
    txtHoTenGV.Text = "*"
    txtMaGV.Locked = False
    txtHoTenGV.Locked = False
    txtMaGV.SetFocus
End Sub

Private Sub Form_Load()
    DataGV.DatabaseName = DBPath
    GVFlag = False
    OldSourceGV = DataGV.RecordSource
End Sub

Private Sub DataGV_Error(DataErr As Integer, Response As Integer)
     MsgBox "Data error event hit err:" & Error$(DataErr)
     Response = 0  'Throw away the error
End Sub

Private Sub DataGV_Reposition()
     Screen.MousePointer = vbDefault
    On Error Resume Next
    DataGV.Caption = "Record: " & (DataGV.Recordset.AbsolutePosition + 1)
End Sub

Private Sub DataGV_Validate(Action As Integer, Save As Integer)
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


