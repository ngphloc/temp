VERSION 5.00
Begin VB.Form frmBaoCao 
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Bao Cao"
   ClientHeight    =   2475
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
   ScaleHeight     =   2475
   ScaleWidth      =   4680
   ShowInTaskbar   =   0   'False
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdXem 
      Caption         =   "Xem"
      BeginProperty Font 
         Name            =   "VNI-Times"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   360
      TabIndex        =   3
      Top             =   1920
      Width           =   1215
   End
   Begin VB.ComboBox cmbMaHS 
      Height          =   375
      Left            =   1800
      TabIndex        =   2
      Top             =   600
      Width           =   1935
   End
   Begin VB.PictureBox rptHocSinh 
      Height          =   480
      Left            =   240
      ScaleHeight     =   420
      ScaleWidth      =   1140
      TabIndex        =   4
      Top             =   2520
      Width           =   1200
   End
   Begin VB.CommandButton cmdThoat 
      Caption         =   "Thoaùt"
      BeginProperty Font 
         Name            =   "VNI-Times"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   3120
      TabIndex        =   0
      Top             =   1920
      Width           =   1215
   End
   Begin VB.Label lbMaHS 
      Caption         =   "Maõ Hoïc Sinh"
      Height          =   255
      Left            =   360
      TabIndex        =   1
      Top             =   600
      Width           =   1095
   End
End
Attribute VB_Name = "frmBaoCao"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Private Sub cmdThoat_Click()
    Unload frmBaoCao
End Sub

Private Sub cmdXem_Click()
    If cmbMaHS.Text = "Tat ca Hoc Sinh" Then
        'rptHocSinh.Formulas(0) = "Header='TAT CA NIEN KHOA'"
        'rptHocSinh.Formulas(0) = "Header = TAT CA NIEN KHOA "
        'rptHocSinh.ReplaceSelectionFormula ("")
    Else
        'rptHocSinh.Formulas(0) = "Header=UPPERCASE({Lop.NienKhoa})"
        'rptHocSinh.ReplaceSelectionFormula ("{Lop.NienKhoa}='" & cmbNienKhoa.Text & "'")
        'rptHocSinh.ReplaceSelectionFormula (" {HocSinh.MaHS} =  " & cmbMaHS.Text)
    End If
    'rptHocSinh.Action = 1

End Sub

Private Sub Form_Load()
Dim SQL As String
Dim wk As Workspace
Dim Db As Database
Dim rs As Recordset

'rptHocSinh.ReportFileName = RPPath
SQL = "SELECT  MaHS from HocSinh"
Set wk = DBEngine.CreateWorkspace("", "Admin", "", dbUseJet)
Set Db = wk.OpenDatabase(DBPath)
Set rs = Db.OpenRecordset(SQL)
With rs
        While Not (.EOF)
            cmbMaHS.AddItem rs.Fields(0), 0
            .MoveNext
        Wend
End With
cmbMaHS.AddItem "Tat ca Hoc Sinh", 0
cmbMaHS.Text = cmbMaHS.List(0)
rs.Close
Db.Close
wk.Close

End Sub
