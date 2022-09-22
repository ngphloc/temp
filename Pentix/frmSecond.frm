VERSION 5.00
Object = "{C1A8AF28-1257-101B-8FB0-0020AF039CA3}#1.1#0"; "MCI32.OCX"
Begin VB.Form frmSecond 
   BackColor       =   &H00808000&
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Congratulation"
   ClientHeight    =   1710
   ClientLeft      =   45
   ClientTop       =   285
   ClientWidth     =   4125
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1710
   ScaleWidth      =   4125
   ShowInTaskbar   =   0   'False
   Begin MCI.MMControl MMControl1 
      Height          =   375
      Left            =   120
      TabIndex        =   3
      Top             =   1080
      Visible         =   0   'False
      Width           =   3780
      _ExtentX        =   6668
      _ExtentY        =   661
      _Version        =   393216
      DeviceType      =   ""
      FileName        =   ""
   End
   Begin VB.Label Label3 
      BackStyle       =   0  'Transparent
      Caption         =   "Press any key to continue"
      ForeColor       =   &H000000FF&
      Height          =   255
      Left            =   1080
      TabIndex        =   2
      Top             =   1440
      Width           =   1935
   End
   Begin VB.Label Label2 
      BackStyle       =   0  'Transparent
      Caption         =   "YOU PASSED THIS LEVEL AND MAY CONTINUE"
      BeginProperty Font 
         Name            =   "Small Fonts"
         Size            =   6.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   255
      Left            =   120
      TabIndex        =   1
      Top             =   840
      Width           =   3855
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackColor       =   &H00FF0000&
      BackStyle       =   0  'Transparent
      Caption         =   "CONGRATULATION"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   615
      Left            =   0
      TabIndex        =   0
      Top             =   240
      Width           =   4095
   End
End
Attribute VB_Name = "frmSecond"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub Form_KeyDown(KeyCode As Integer, Shift As Integer)
    MMControl1.Command = "Close"
    'Timer1.Enabled = False
    Unload frmSecond
End Sub

Private Sub Form_Load()
  MMControl1.DeviceType = "WaveAudio"
  MMControl1.FileName = "D:\PENTIX\CONGRATULATION.WAV"
  MMControl1.Command = "Open"
  MMControl1.Command = "Play"
  'Timer1.Interval = MMControl1.Length
  'Timer1.Enabled = True
  'frmPentix.MMControl2.Command = "Play"
End Sub

