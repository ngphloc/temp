VERSION 5.00
Begin VB.Form frmChonDay 
   Caption         =   "Chon Day"
   ClientHeight    =   2280
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
   ScaleHeight     =   2280
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdNhan 
      Caption         =   "Nhaän"
      Height          =   375
      Left            =   1800
      TabIndex        =   2
      Top             =   1440
      Width           =   1095
   End
   Begin VB.ComboBox cmbMaDay 
      Height          =   375
      Left            =   2400
      TabIndex        =   1
      Top             =   480
      Width           =   1335
   End
   Begin VB.Label lbMaDay 
      Caption         =   "Maõ Daïy"
      Height          =   375
      Left            =   960
      TabIndex        =   0
      Top             =   480
      Width           =   975
   End
End
Attribute VB_Name = "frmChonDay"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub cmdNhan_Click()
    If (cmbMaDay.Text = "" Or IsNull(cmbMaDay.Text)) Then
        MsgBox "Khong the de trong ma xep lop ", 16, "Loi"
        cmbMaDay.SetFocus
        Exit Sub
    End If
    MaDay = cmbMaDay.Text
    Unload Me
End Sub

Private Sub Form_Load()
    Dim wk As Workspace
    Dim Db As Database
    Dim rs As Recordset
    Dim cSQL As String
    
    cSQL = "SELECT  MaDay from Day"
    Set wk = DBEngine.CreateWorkspace("", "Admin", "", dbUseJet)
    Set Db = wk.OpenDatabase(DBPath)
    Set rs = Db.OpenRecordset(cSQL)
    With rs
        While Not (.EOF)
            cmbMaDay.AddItem rs.Fields(0), 0
            .MoveNext
        Wend
    End With
    cmbMaDay.Text = cmbMaDay.List(0)
    rs.Close
    Db.Close
    wk.Close
End Sub

