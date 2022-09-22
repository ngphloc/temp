VERSION 5.00
Object = "{00028C01-0000-0000-0000-000000000046}#1.0#0"; "DBGRID32.OCX"
Begin VB.Form frmChuNhiem 
   Caption         =   "Chu Nhiem"
   ClientHeight    =   5160
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7095
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
   ScaleHeight     =   5160
   ScaleWidth      =   7095
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdThoat 
      Caption         =   "Thoaùt"
      Height          =   375
      Left            =   2880
      TabIndex        =   1
      Top             =   4560
      Width           =   1335
   End
   Begin VB.Data DataCN 
      Connect         =   "Access"
      DatabaseName    =   "D:\CNPM\qlhs.mdb"
      DefaultCursorType=   0  'DefaultCursor
      DefaultType     =   2  'UseODBC
      Exclusive       =   0   'False
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   2280
      Options         =   0
      ReadOnly        =   0   'False
      RecordsetType   =   1  'Dynaset
      RecordSource    =   "CNQuery"
      Top             =   3840
      Width           =   2535
   End
   Begin MSDBGrid.DBGrid DBGridCN 
      Bindings        =   "frmChuNhiem.frx":0000
      Height          =   3375
      Left            =   360
      OleObjectBlob   =   "frmChuNhiem.frx":0011
      TabIndex        =   0
      Top             =   120
      Width           =   6615
   End
End
Attribute VB_Name = "frmChuNhiem"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub cmdThoat_Click()
    Unload Me
End Sub

Private Sub Form_Load()
    DataCN.DatabaseName = DBPath
End Sub
Private Sub DataCN_Error(DataErr As Integer, Response As Integer)
     MsgBox "Data error event hit err:" & Error$(DataErr)
     Response = 0  'Throw away the error
End Sub

Private Sub DataCN_Reposition()
     Screen.MousePointer = vbDefault
    On Error Resume Next
  ' This will display the current record position for dynasets and snapshots
    DataCN.Caption = "Record: " & (DataCN.Recordset.AbsolutePosition + 1)
End Sub

Private Sub DataCN_Validate(Action As Integer, Save As Integer)
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
