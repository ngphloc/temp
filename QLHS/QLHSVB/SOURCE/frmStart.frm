VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form frmStart 
   Caption         =   "Quan ly hoc sinh"
   ClientHeight    =   4125
   ClientLeft      =   165
   ClientTop       =   735
   ClientWidth     =   5655
   BeginProperty Font 
      Name            =   "VNI-Times"
      Size            =   12
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   ForeColor       =   &H00FF0000&
   LinkTopic       =   "Form1"
   ScaleHeight     =   4125
   ScaleWidth      =   5655
   StartUpPosition =   3  'Windows Default
   Begin MSComDlg.CommonDialog FileComDialog 
      Left            =   360
      Top             =   3600
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
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
      Height          =   495
      Left            =   2160
      TabIndex        =   3
      Top             =   3360
      Width           =   1335
   End
   Begin VB.CommandButton cmdBaoCao 
      Caption         =   "Baùo Caùo Ñieåm Hoïc Sinh"
      BeginProperty Font 
         Name            =   "VNI-Times"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   960
      TabIndex        =   2
      Top             =   2400
      Width           =   3735
   End
   Begin VB.CommandButton cmdDoiTuong 
      BackColor       =   &H00FFFF00&
      Caption         =   "Laøm vieäc vôùi moät ñoái töôïng"
      BeginProperty Font 
         Name            =   "VNI-Times"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   960
      MaskColor       =   &H00FF0000&
      TabIndex        =   1
      Top             =   1440
      Width           =   3735
   End
   Begin VB.Label lbQLHS 
      Caption         =   "Chöông Trình Quaûn Lyù Hoïc Sinh"
      BeginProperty Font 
         Name            =   "VNI-Times"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   615
      Left            =   240
      TabIndex        =   0
      Top             =   600
      Width           =   5295
   End
   Begin VB.Menu mnuOpen 
      Caption         =   "&Mo tap tin"
      Begin VB.Menu mnuOpenMDB 
         Caption         =   "Mo tap tin .m&db"
         Shortcut        =   ^D
      End
      Begin VB.Menu mnuStep1 
         Caption         =   "_"
         Index           =   0
      End
      Begin VB.Menu mnuOpenRP 
         Caption         =   "Mo tap tin .&rp"
         Shortcut        =   ^R
      End
      Begin VB.Menu mnuStep2 
         Caption         =   "_"
      End
      Begin VB.Menu mnuExit 
         Caption         =   "&Exit"
         Shortcut        =   ^E
      End
   End
   Begin VB.Menu mnuHelp 
      Caption         =   "&Giup do"
      Begin VB.Menu mnuGuide 
         Caption         =   "&Huong dan"
         Shortcut        =   ^H
      End
      Begin VB.Menu mnuStep3 
         Caption         =   "_"
      End
      Begin VB.Menu mnuAbout 
         Caption         =   "&So luoc"
         Shortcut        =   ^S
      End
   End
End
Attribute VB_Name = "frmStart"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Private DBFlag As Boolean
Private RPFlag As Boolean
Private Sub cmdBaoCao_Click()
    If DBFlag = False Then
        MsgBox "Ban phai mo File qlhs.mdb", 16, "Loi"
        Exit Sub
    End If
    If RPFlag = False Then
        MsgBox "Ban phai mo File rpthocsinh.rpt", 16, "Loi"
        Exit Sub
    End If
    Load frmBaoCaoDiem
    frmBaoCaoDiem.Show
End Sub

Private Sub cmdDoiTuong_Click()
    If DBFlag = False Then
        MsgBox "Ban phai mo File qlhs.mdb", 16, "Loi"
        Exit Sub
    End If
    Load frmMain
    frmMain.Show
End Sub

Private Sub cmdThoat_Click()
    End
End Sub

Private Sub Form_Load()
    DBPath = "C:\TEMP\QLHS\DATA\qlhs.mdb"
    RPPath = "C:\TEMP\QLHS\DATA\rpthocsinh.rpt"
    DBFlag = False
    RPFlag = False
    'FileComDialog.InitDir = "C:\TEMP\QLHS\DATA"
    FileComDialog.InitDir = "K"
End Sub

Private Sub Form_Unload(Cancel As Integer)
    Screen.MousePointer = vbDefault
End Sub

Private Sub mnuExit_Click()
    Unload Me
End Sub

Private Sub mnuOpenMDB_Click()
    
    FileComDialog.DialogTitle = "Chon file co so du lieu .MDB trong ACCESS "
    FileComDialog.Filter = "Microsoft Access Database |*.mdb"
    FileComDialog.ShowOpen
    'If UCase(FileComDialog.FileTitle) = UCase("qlhs.mdb") Then
    If FileComDialog.FileTitle = "qlhs.mdb" Then
        DBPath = FileComDialog.FileName
        DBFlag = True
    Else
        MsgBox "Ban chon sai ten File , ten file dung la qlhs.mdb", 16, "Loi"
    End If
End Sub

Private Sub mnuOpenRP_Click()
    FileComDialog.DialogTitle = "Chon file report .rpt"
    FileComDialog.Filter = "Report Files |*.rpt"
    FileComDialog.ShowOpen
    If FileComDialog.FileTitle = "rpthocsinh.rpt" Then
        RPPath = FileComDialog.FileName
        RPFlag = True
    Else
        MsgBox "Ban chon sai ten File , ten file dung la rpthocsinh.rpt", 16, "Loi"
    End If
End Sub
