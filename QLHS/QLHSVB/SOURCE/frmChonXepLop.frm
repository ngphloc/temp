VERSION 5.00
Begin VB.Form frmChonXepLop 
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Chon Xep Lop"
   ClientHeight    =   2370
   ClientLeft      =   45
   ClientTop       =   285
   ClientWidth     =   4350
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
   ScaleHeight     =   2370
   ScaleWidth      =   4350
   ShowInTaskbar   =   0   'False
   StartUpPosition =   3  'Windows Default
   Begin VB.ComboBox cmbMaXepLop 
      Height          =   375
      Left            =   2160
      TabIndex        =   2
      Top             =   480
      Width           =   1215
   End
   Begin VB.CommandButton cmdNhan 
      Caption         =   "Nhaän"
      Height          =   375
      Left            =   1680
      TabIndex        =   1
      Top             =   1680
      Width           =   855
   End
   Begin VB.Label lbMaXepLop 
      Caption         =   "Maõ Xeáp Lôùp"
      Height          =   375
      Left            =   600
      TabIndex        =   0
      Top             =   480
      Width           =   1095
   End
End
Attribute VB_Name = "frmChonXepLop"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Private Sub cmdNhan_Click()
    If (cmbMaXepLop.Text = "" Or IsNull(cmbMaXepLop.Text)) Then
        MsgBox "Khong the de trong ma xep lop ", 16, "Loi"
        cmbMaXepLop.SetFocus
        Exit Sub
    End If
    MaXepLop = cmbMaXepLop.Text
    Unload frmChonXepLop
End Sub

Private Sub Form_Load()
    Dim wk As Workspace
    Dim Db As Database
    Dim rs As Recordset
    Dim cSQL As String
    
    cSQL = "SELECT  MaXepLop from XepLop"
    Set wk = DBEngine.CreateWorkspace("", "Admin", "", dbUseJet)
    Set Db = wk.OpenDatabase(DBPath)
    Set rs = Db.OpenRecordset(cSQL)
    With rs
        While Not (.EOF)
            cmbMaXepLop.AddItem rs.Fields(0), 0
            .MoveNext
        Wend
    End With
    cmbMaXepLop.Text = cmbMaXepLop.List(0)
    rs.Close
    Db.Close
    wk.Close
End Sub

