VERSION 5.00
Begin VB.Form frmKetQua 
   Caption         =   "Ket Qua"
   ClientHeight    =   4200
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6420
   LinkTopic       =   "Form1"
   ScaleHeight     =   4200
   ScaleWidth      =   6420
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdThoat 
      Cancel          =   -1  'True
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
      Left            =   2760
      TabIndex        =   13
      Top             =   3600
      Width           =   1095
   End
   Begin VB.CheckBox chkDuocLenLop 
      Alignment       =   1  'Right Justify
      Caption         =   "Ñöôïc Leân lôùp"
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
      Left            =   3720
      TabIndex        =   12
      Top             =   3000
      Width           =   1575
   End
   Begin VB.TextBox txtXepLoai 
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
      Left            =   1680
      Locked          =   -1  'True
      TabIndex        =   11
      Top             =   3000
      Width           =   975
   End
   Begin VB.TextBox txtDiemTBCN 
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
      Left            =   5640
      Locked          =   -1  'True
      TabIndex        =   9
      Top             =   2040
      Width           =   735
   End
   Begin VB.TextBox txtDiemTBHKII 
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
      Left            =   3480
      Locked          =   -1  'True
      TabIndex        =   7
      Top             =   2040
      Width           =   735
   End
   Begin VB.TextBox txtDiemTBHKI 
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
      Left            =   1320
      Locked          =   -1  'True
      TabIndex        =   5
      Top             =   2040
      Width           =   615
   End
   Begin VB.TextBox txtNienKhoa 
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
      Left            =   1680
      Locked          =   -1  'True
      TabIndex        =   3
      Top             =   960
      Width           =   1095
   End
   Begin VB.TextBox txtMaHS 
      Height          =   375
      Left            =   1680
      Locked          =   -1  'True
      TabIndex        =   1
      Top             =   360
      Width           =   1095
   End
   Begin VB.Label lbXepLoai 
      Caption         =   "Xeáp Loaïi"
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
      TabIndex        =   10
      Top             =   3000
      Width           =   855
   End
   Begin VB.Label lbDiemTBCN 
      Caption         =   "Ñieåm TBCN"
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
      Left            =   4440
      TabIndex        =   8
      Top             =   2040
      Width           =   1095
   End
   Begin VB.Label lbDiemTBHKII 
      Caption         =   "Ñieåm TBHKII"
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
      Left            =   2160
      TabIndex        =   6
      Top             =   2040
      Width           =   1215
   End
   Begin VB.Label lbDiemTBHKI 
      Caption         =   "Ñieåm TBHKI"
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
      Left            =   120
      TabIndex        =   4
      Top             =   2040
      Width           =   1095
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
      Left            =   360
      TabIndex        =   2
      Top             =   1080
      Width           =   975
   End
   Begin VB.Label lbMaHS 
      Caption         =   "Maõ Hoïc sinh"
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
      TabIndex        =   0
      Top             =   360
      Width           =   1095
   End
End
Attribute VB_Name = "frmKetQua"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Private Sub cmdThoat_Click()
    Unload frmKetQua
End Sub

Private Sub Form_Load()
    Dim DiemTBHKI As Single
    Dim DiemTBHKII As Single
    Dim DiemTBCN As Single
    DiemTBHKI = 0
    DiemTBHKII = 0
    DiemTBCN = 0
    
    DiemTB Val(frmPhieuDiem.txtMaHS.Text), Val(frmPhieuDiem.cmbNienKhoa.Text), DiemTBHKI, DiemTBHKII, DiemTBCN
    txtMaHS.Text = frmPhieuDiem.txtMaHS.Text
    txtNienKhoa.Text = frmPhieuDiem.cmbNienKhoa.Text
    txtDiemTBHKI.Text = Str(DiemTBHKI)
    txtDiemTBHKII.Text = Str(DiemTBHKII)
    txtDiemTBCN.Text = Str(DiemTBCN)
    If (DiemTBCN >= 8) Then txtXepLoai.Text = "Gioûi"
    If (DiemTBCN < 8) And (DiemTBCN >= 6.5) Then txtXepLoai.Text = "Khaù"
    If (DiemTBCN < 6.5) And (DiemTBCN >= 5) Then txtXepLoai.Text = "Trung bình"
    If (DiemTBCN < 5) Then txtXepLoai.Text = "Yeáu"
    
    If (DiemTBCN) >= 5 Then
        chkDuocLenLop.Value = 1
    Else
        chkDuocLenLop.Value = 0
    End If
End Sub

Private Sub Form_Unload(Cancel As Integer)
    Screen.MousePointer = vbDefault
End Sub
