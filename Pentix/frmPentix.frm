VERSION 5.00
Object = "{C1A8AF28-1257-101B-8FB0-0020AF039CA3}#1.1#0"; "MCI32.OCX"
Object = "{22D6F304-B0F6-11D0-94AB-0080C74C7E95}#1.0#0"; "MSDXM.OCX"
Begin VB.Form frmPentix 
   Caption         =   "BasicPENTIX"
   ClientHeight    =   6405
   ClientLeft      =   2955
   ClientTop       =   630
   ClientWidth     =   5535
   LinkTopic       =   "Form1"
   ScaleHeight     =   427
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   369
   Begin VB.Timer Timer3 
      Left            =   5160
      Top             =   120
   End
   Begin MCI.MMControl MMControl3 
      Height          =   330
      Left            =   0
      TabIndex        =   11
      Top             =   6120
      Visible         =   0   'False
      Width           =   4095
      _ExtentX        =   7223
      _ExtentY        =   582
      _Version        =   393216
      DeviceType      =   ""
      FileName        =   ""
   End
   Begin MCI.MMControl MMControl2 
      Height          =   330
      Left            =   720
      TabIndex        =   10
      Top             =   360
      Visible         =   0   'False
      Width           =   3735
      _ExtentX        =   6588
      _ExtentY        =   582
      _Version        =   393216
      DeviceType      =   ""
      FileName        =   ""
   End
   Begin MCI.MMControl MMControl1 
      Height          =   330
      Left            =   360
      TabIndex        =   9
      Top             =   5640
      Visible         =   0   'False
      Width           =   3540
      _ExtentX        =   6244
      _ExtentY        =   582
      _Version        =   393216
      DeviceType      =   ""
      FileName        =   ""
   End
   Begin VB.Timer Timer2 
      Left            =   5160
      Top             =   720
   End
   Begin VB.PictureBox Picture2 
      BackColor       =   &H80000007&
      Height          =   1125
      Left            =   3900
      ScaleHeight     =   71
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   71
      TabIndex        =   8
      Top             =   4965
      Width           =   1125
      Begin VB.Image imgNext 
         Height          =   300
         Index           =   8
         Left            =   675
         Stretch         =   -1  'True
         Top             =   675
         Width           =   300
      End
      Begin VB.Image imgNext 
         Height          =   300
         Index           =   7
         Left            =   375
         Stretch         =   -1  'True
         Top             =   675
         Width           =   300
      End
      Begin VB.Image imgNext 
         Height          =   300
         Index           =   6
         Left            =   75
         Stretch         =   -1  'True
         Top             =   675
         Width           =   300
      End
      Begin VB.Image imgNext 
         Height          =   300
         Index           =   5
         Left            =   675
         Stretch         =   -1  'True
         Top             =   375
         Width           =   300
      End
      Begin VB.Image imgNext 
         Height          =   300
         Index           =   4
         Left            =   375
         Stretch         =   -1  'True
         Top             =   375
         Width           =   300
      End
      Begin VB.Image imgNext 
         Height          =   300
         Index           =   3
         Left            =   75
         Stretch         =   -1  'True
         Top             =   375
         Width           =   300
      End
      Begin VB.Image imgNext 
         Height          =   300
         Index           =   2
         Left            =   675
         Stretch         =   -1  'True
         Top             =   75
         Width           =   300
      End
      Begin VB.Image imgNext 
         Height          =   300
         Index           =   1
         Left            =   375
         Stretch         =   -1  'True
         Top             =   75
         Width           =   300
      End
      Begin VB.Image imgNext 
         Height          =   300
         Index           =   0
         Left            =   75
         Stretch         =   -1  'True
         Top             =   75
         Width           =   300
      End
   End
   Begin VB.Timer Timer1 
      Left            =   5160
      Top             =   1800
   End
   Begin VB.PictureBox Picture1 
      BackColor       =   &H80000012&
      Height          =   4695
      Left            =   240
      ScaleHeight     =   309
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   181
      TabIndex        =   1
      Top             =   720
      Width           =   2775
      Begin VB.Label lbGameOver 
         BackColor       =   &H000000C0&
         BorderStyle     =   1  'Fixed Single
         Caption         =   "GAME OVER"
         BeginProperty Font 
            Name            =   "Arial Black"
            Size            =   14.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00FFFFFF&
         Height          =   450
         Left            =   480
         TabIndex        =   2
         Top             =   2025
         Visible         =   0   'False
         Width           =   2025
      End
      Begin VB.Image Cells 
         Height          =   300
         Index           =   0
         Left            =   0
         Stretch         =   -1  'True
         Top             =   0
         Width           =   300
      End
   End
   Begin MediaPlayerCtl.MediaPlayer MediaPlayer1 
      Height          =   2055
      Left            =   3360
      TabIndex        =   12
      Top             =   960
      Width           =   2175
      AudioStream     =   -1
      AutoSize        =   0   'False
      AutoStart       =   -1  'True
      AnimationAtStart=   -1  'True
      AllowScan       =   -1  'True
      AllowChangeDisplaySize=   -1  'True
      AutoRewind      =   0   'False
      Balance         =   0
      BaseURL         =   ""
      BufferingTime   =   5
      CaptioningID    =   ""
      ClickToPlay     =   -1  'True
      CursorType      =   0
      CurrentPosition =   -1
      CurrentMarker   =   0
      DefaultFrame    =   ""
      DisplayBackColor=   0
      DisplayForeColor=   16777215
      DisplayMode     =   0
      DisplaySize     =   4
      Enabled         =   -1  'True
      EnableContextMenu=   -1  'True
      EnablePositionControls=   -1  'True
      EnableFullScreenControls=   -1  'True
      EnableTracker   =   -1  'True
      Filename        =   ""
      InvokeURLs      =   -1  'True
      Language        =   -1
      Mute            =   0   'False
      PlayCount       =   1
      PreviewMode     =   0   'False
      Rate            =   1
      SAMILang        =   ""
      SAMIStyle       =   ""
      SAMIFileName    =   ""
      SelectionStart  =   -1
      SelectionEnd    =   -1
      SendOpenStateChangeEvents=   -1  'True
      SendWarningEvents=   -1  'True
      SendErrorEvents =   -1  'True
      SendKeyboardEvents=   0   'False
      SendMouseClickEvents=   0   'False
      SendMouseMoveEvents=   0   'False
      SendPlayStateChangeEvents=   -1  'True
      ShowCaptioning  =   0   'False
      ShowControls    =   0   'False
      ShowAudioControls=   -1  'True
      ShowDisplay     =   0   'False
      ShowGotoBar     =   0   'False
      ShowPositionControls=   -1  'True
      ShowStatusBar   =   0   'False
      ShowTracker     =   -1  'True
      TransparentAtStart=   0   'False
      VideoBorderWidth=   0
      VideoBorderColor=   0
      VideoBorder3D   =   -1  'True
      Volume          =   -60
      WindowlessVideo =   0   'False
   End
   Begin VB.Image imgSample 
      Height          =   300
      Index           =   4
      Left            =   120
      Picture         =   "frmPentix.frx":0000
      Stretch         =   -1  'True
      Top             =   240
      Width           =   300
   End
   Begin VB.Image imgSetDrop 
      Height          =   300
      Left            =   5400
      Picture         =   "frmPentix.frx":018A
      Stretch         =   -1  'True
      Top             =   5880
      Visible         =   0   'False
      Width           =   300
   End
   Begin VB.Image imgEnd 
      Height          =   300
      Left            =   4800
      Picture         =   "frmPentix.frx":0314
      Stretch         =   -1  'True
      Top             =   6120
      Visible         =   0   'False
      Width           =   300
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "Next"
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   14.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF8080&
      Height          =   375
      Left            =   4080
      TabIndex        =   7
      Top             =   4485
      Width           =   735
   End
   Begin VB.Label lbLevel 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "1"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H8000000E&
      Height          =   375
      Left            =   4050
      TabIndex        =   6
      Top             =   4125
      Width           =   855
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "Level"
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   14.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF8080&
      Height          =   375
      Left            =   4080
      TabIndex        =   5
      Top             =   3765
      Width           =   735
   End
   Begin VB.Label lbScore 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "0"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H8000000E&
      Height          =   375
      Left            =   3960
      TabIndex        =   4
      Top             =   3525
      Width           =   975
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "Score"
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   14.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF8080&
      Height          =   375
      Left            =   3990
      TabIndex        =   3
      Top             =   3165
      Width           =   855
   End
   Begin VB.Shape Shape1 
      BackStyle       =   1  'Opaque
      BorderColor     =   &H0000FFFF&
      BorderStyle     =   3  'Dot
      BorderWidth     =   3
      FillColor       =   &H00000040&
      Height          =   5175
      Left            =   120
      Top             =   480
      Width           =   3015
   End
   Begin VB.Label lb 
      BackStyle       =   0  'Transparent
      Caption         =   "BasicPENTIX"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   26.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFF80&
      Height          =   615
      Left            =   2040
      TabIndex        =   0
      Top             =   0
      Width           =   2895
   End
   Begin VB.Image imgSample 
      Height          =   300
      Index           =   3
      Left            =   480
      Picture         =   "frmPentix.frx":049E
      Stretch         =   -1  'True
      Top             =   240
      Width           =   300
   End
   Begin VB.Image imgSample 
      Height          =   300
      Index           =   2
      Left            =   840
      Picture         =   "frmPentix.frx":0628
      Stretch         =   -1  'True
      Top             =   240
      Width           =   300
   End
   Begin VB.Image imgSample 
      Height          =   300
      Index           =   1
      Left            =   1200
      Picture         =   "frmPentix.frx":07B2
      Stretch         =   -1  'True
      Top             =   240
      Width           =   300
   End
   Begin VB.Image imgSample 
      Height          =   300
      Index           =   0
      Left            =   1560
      Picture         =   "frmPentix.frx":093C
      Stretch         =   -1  'True
      Top             =   240
      Width           =   300
   End
   Begin VB.Menu mnuGame 
      Caption         =   "&Game"
      Begin VB.Menu mnuStart 
         Caption         =   "&Start Game"
         Shortcut        =   ^S
      End
      Begin VB.Menu mnuStop 
         Caption         =   "&Stop Game"
         Shortcut        =   ^T
      End
      Begin VB.Menu mnuStep1 
         Caption         =   "_"
      End
      Begin VB.Menu mnuNext 
         Caption         =   "Show &Next"
         Shortcut        =   ^N
      End
      Begin VB.Menu mnuStep2 
         Caption         =   "_"
      End
      Begin VB.Menu mnuExit 
         Caption         =   "E&xit"
         Shortcut        =   ^E
      End
   End
   Begin VB.Menu mnuOption 
      Caption         =   "&Option"
      Begin VB.Menu mnuConfigure 
         Caption         =   "Con&figuration"
      End
      Begin VB.Menu mnuStep3 
         Caption         =   "_"
      End
      Begin VB.Menu mnuMusic 
         Caption         =   "&Music On/Off"
         Checked         =   -1  'True
      End
   End
   Begin VB.Menu mnuHelp 
      Caption         =   "&Help"
      Begin VB.Menu mnuTopics 
         Caption         =   "Help &Topics"
      End
      Begin VB.Menu mnuAbout 
         Caption         =   "&About"
      End
   End
End
Attribute VB_Name = "frmPentix"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Option Base 1
Const Rows = 18
Const Columns = 10
Const w = 20
Const h = 20
Const m = 20
Dim K As Byte
Dim PItem(3, 3) As Byte
Dim PenShape(m) As String
Dim PX, PY As Integer
Dim ColorNum As Integer
Dim NextShape As Integer
Dim NextColor As Integer
Dim Score As Long
Dim Level As Integer
Dim KeyFlag As Boolean
Dim GameStarted As Boolean
Dim NumberShape As Integer
Dim NumberColor As Integer
Dim Test(14) As Integer
'Dim Flag As Boolean
Private Sub MakeCells()
  Dim I, J As Integer
  Dim Index As Integer
  ScaleMode = 3
  Picture1.ScaleMode = 3
  Picture1.Width = w * Columns + 4
  Picture1.Height = h * Rows + 4
  lbGameOver.Left = Picture1.Width \ 2 - lbGameOver.Width \ 2
  lbGameOver.Top = Picture1.Height \ 2 - lbGameOver.Height \ 2

  With Picture1
    Shape1.Move .Left - 2, .Top - 2, .ScaleWidth + 7, .ScaleHeight + 7
  End With
  Cells(0).Tag = 0
  Cells(0).Move 0, 0, w, h
    
  For J = 0 To Rows - 1
    For I = 0 To Columns - 1
      Index = J * Columns + I
      If Index <> 0 Then
        Load Cells(Index)
        Cells(Index).Move I * w, J * h
        Cells(Index).Visible = True
        Cells(Index).Tag = 0
      End If
    Next I
  Next J
End Sub
Private Sub MakeItem(Index As Integer)
  Dim I, J As Integer
  For J = 1 To 3
    For I = 1 To 3
      PItem(J, I) = Val(Mid(PenShape(Index), (J - 1) * 3 + I, 1))
    Next I
  Next J
End Sub
Private Sub ShiftUp()
  Dim I, J As Integer
  
  For J = 1 To 2
    For I = 1 To 3
      PItem(J, I) = PItem(J + 1, I)
    Next I
  Next J
  
  For I = 1 To 3
    PItem(3, I) = 0
  Next I
End Sub
Private Sub RotateItem()
  Const Pi = 3.14159265358979
  Dim I, J As Integer
  Dim X, Y As Integer
  Dim Temp(3, 3)
  For J = 1 To 3
    For I = 1 To 3
      Temp(J, I) = PItem(J, I)
    Next I
  Next J
  
  For J = 1 To 3
    For I = 1 To 3
      X = 3 + Fix(I * Cos(Pi / 2) - J * Sin(Pi / 2))
      Y = 1 + Fix(I * Sin(Pi / 2) - J * Cos(Pi / 2))
      PItem(J, I) = Temp(Y, X)
    Next I
  Next J
  
  Do While PItem(1, 1) = 0 And PItem(1, 2) = 0 And PItem(1, 3) = 0
    ShiftUp
  Loop
End Sub
Private Function CellAt(ByVal X As Integer, ByVal Y As Integer, ByVal J As Integer, ByVal I As Integer) As Integer
  CellAt = (Y + J - 1) * Columns + X + I - 1
End Function
Private Sub DrawItem(ByVal X As Integer, ByVal Y As Integer)
  Dim I, J As Integer
  Dim Index As Integer
  
  For J = 1 To 3
    For I = 1 To 3
      Index = CellAt(X, Y, J, I)
      If (Index < Rows * Columns) Then
        If Cells(Index).Tag <> 1 Then
          If PItem(J, I) = 1 Then
            Cells(Index).Picture = imgSample(ColorNum).Picture
            'Cells(Index).BorderStyle = 1
          Else
            Cells(Index).Picture = Nothing
          End If
        End If
      End If
    Next I
  Next J
End Sub
Private Sub ClearItem(ByVal X, ByVal Y)
  Dim I, J As Integer
  Dim Index As Integer
  For J = 1 To 3
    For I = 1 To 3
      Index = CellAt(X, Y, J, I)
      If (Index < Rows * Columns) Then
        If (Cells(Index).Tag <> 1) And (PItem(J, I) = 1) Then
          Cells(Index).Picture = Nothing
          Cells(Index).BorderStyle = 0
        End If
      End If
    Next I
  Next J
End Sub
Private Sub DrawNext()
  Dim I As Byte
  
  For I = 1 To 9
    If Mid(PenShape(NextShape), I, 1) = "1" Then
      imgNext(I - 1).Picture = imgSample(NextColor).Picture
    Else
      imgNext(I - 1).Picture = Nothing
    End If
  Next I
End Sub
Private Sub NewItem()
  Dim Exame, Flag As Boolean
  Dim I As Integer
  Timer1.Enabled = False
  MakeItem NextShape
  ColorNum = NextColor
  Do
    NextShape = Int(Rnd * (NumberShape + 1))
    If (NextShape = 0) Then
      Flag = False
    Else
      If (Test(NextShape) < 1) Then
        Flag = True
        Test(NextShape) = Test(NextShape) + 1
      Else
        Flag = False
        Exame = True
        For I = 1 To NumberShape
          Exame = Exame And CBool(Test(I) = 1)
        Next I
      
        If (Exame = True) Then
          For I = 1 To NumberShape
            Test(I) = 0
          Next I
        End If
      End If
    End If
  Loop Until (Flag = True)
  Timer1.Enabled = True
  NextColor = Int(Rnd * NumberColor)
  
  DrawNext
  PX = 4
  PY = 0
End Sub
Private Function Touch() As Boolean
  Dim I, J As Integer
  Dim Index As Integer
  Dim Found As Boolean
  
  Found = False
  J = 3
  Do
    I = 1
    Do
      If PY + J + 1 <= Rows Then
        Index = CellAt(PX, PY + 1, J, I)
        Found = CBool((PItem(J, I) = 1) And (Cells(Index).Tag = 1))
      Else
        Found = CBool(PItem(J, I) = 1)
      End If
      I = I + 1
    Loop Until Found Or (I > 3) Or ((PX + I) > Columns)
    J = J - 1
  Loop Until Found Or (J < 1)
  Touch = Found
End Function
Private Function CanLeft() As Boolean
  Dim I, J As Integer
  Dim Index As Integer
  Dim Found As Boolean
  
  I = 1
  Do
    J = 3
    Do
      If PX + I - 1 > 0 Then
        If PY + J <= Rows Then
          Index = CellAt(PX - 1, PY, J, I)
          Found = CBool((PItem(J, I) = 1) And (Cells(Index).Tag = 1))
        End If
      Else
        Found = CBool(PItem(J, I) = 1)
      End If
      J = J - 1
    Loop Until Found Or (J < 1)
    I = I + 1
  Loop Until Found Or (I > 3)
  CanLeft = Not Found
End Function
Private Function CanRight() As Boolean
  Dim I, J As Integer
  Dim Index As Integer
  Dim Found As Boolean
  
  I = 3
  Do
    J = 3
    Do
      If PX + I < Columns Then
        If PY + J <= Rows Then
          Index = CellAt(PX + 1, PY, J, I)
          Found = CBool((PItem(J, I) = 1) And (Cells(Index).Tag = 1))
        End If
      Else
        Found = CBool(PItem(J, I) = 1)
      End If
      J = J - 1
    Loop Until Found Or (J < 1)
    I = I - 1
  Loop Until Found Or (I < 1)
  CanRight = Not Found
End Function
Private Function CanRotate() As Boolean
  Dim I, J, K, L As Integer
  J = 3
  I = 1
  K = 3
  L = 1
  Do While (PItem(J, 1) = 0) And (PItem(J, 2) = 0) And (PItem(J, 3) = 0)
    J = J - 1
  Loop
  Do While (PItem(I, 1) = 0) And (PItem(I, 2) = 0) And (PItem(I, 3) = 0)
    I = I + 1
  Loop
  
  Do While (PItem(1, K) = 0) And (PItem(2, K) = 0) And (PItem(3, K) = 0)
    K = K - 1
  Loop
  Do While (PItem(1, L) = 0) And (PItem(2, L) = 0) And (PItem(3, L) = 0)
    L = L + 1
  Loop
  
  If (PY + L < Rows) Then
    If (PX + I <= Columns) And (PX + I >= 1) And (PX + J <= Columns) And (PX + J >= 1) And (PX + J <= Columns) Then
      If (PY + L = Rows - 1) And ((NextShape = 1) Or (NextShape = 2)) Then
        CanRotate = False
        Exit Function
      End If
      If (PY + L <> Rows - 1) Then
        CanRotate = CBool((Cells(CellAt(PX, PY, 1, J)).Tag = 0) And (Cells(CellAt(PX, PY, 2, J)).Tag = 0) And (Cells(CellAt(PX, PY, 3, J)).Tag = 0))
        If (I <> J) Then
          CanRotate = CanRotate And CBool((Cells(CellAt(PX, PY, 1, I)).Tag = 0) And (Cells(CellAt(PX, PY, 2, I)).Tag = 0) And (Cells(CellAt(PX, PY, 3, I)).Tag = 0))
        End If
        
        CanRotate = CanRotate And CBool((Cells(CellAt(PX, PY, K, 1)).Tag = 0) And (Cells(CellAt(PX, PY, K, 2)).Tag = 0) And (Cells(CellAt(PX, PY, K, 3)).Tag = 0))
        If (K <> L) Then
          CanRotate = CanRotate And CBool((Cells(CellAt(PX, PY, L, 1)).Tag = 0) And (Cells(CellAt(PX, PY, L, 2)).Tag = 0) And (Cells(CellAt(PX, PY, L, 3)).Tag = 0))
        End If
      End If
    Else
      CanRotate = False
    End If
  Else
    CanRotate = False
  End If
End Function
Private Function LineFull(LineNum As Integer) As Boolean
  Dim I As Integer
  Dim Index As Integer
  Dim IsFull As Boolean
  
  IsFull = True
  For I = 0 To Columns - 1
    Index = LineNum * Columns + I
    IsFull = IsFull And CBool(Cells(Index).Tag = 1)
  Next I
  LineFull = IsFull
End Function
Private Sub Colapse(LineNum As Integer)
  Dim I, J As Integer
  Dim Index1, Index2 As Integer
  'Timer1.Enabled = False

  For I = 0 To Columns - 1
    Index1 = LineNum * Columns + I
    Cells(Index1).Picture = Nothing
    Cells(Index1).BorderStyle = 0
  Next I
  
  For J = LineNum To 1 Step -1
    For I = 0 To Columns - 1
      Index1 = J * Columns + I
      Index2 = (J - 1) * Columns + I
      Cells(Index1).Picture = Cells(Index2).Picture
      Cells(Index1).Tag = Cells(Index2).Tag
      'If (Cells(Index1).Tag = 1) Then
        'Cells(Index1).BorderStyle = 1
      'Else
        'Cells(Index1).BorderStyle = 0
      'End If
      
      Cells(Index2).Picture = Nothing
      Cells(Index2).Tag = 0
      Cells(Index2).BorderStyle = 0
    Next I
  Next J
  'MMControl3.Command = "Prev"
  'MMControl3.Command = "Play"

  'Score = Score + 10
  'lbScore = CStr(Score)
  'If (Score Mod 100 = 0) And (Level < 7) Then
    'Level = Level + 1
    'K = K + 1
    'Timer1.Interval = 50 + (8 - Level) * 60
    'lbLevel = CStr(Level)
  'End If
  'Timer1.Enabled = True
End Sub
Private Sub CheckColapse()
  Dim I As Integer
  Dim a As Integer
  Dim b As Integer
  Dim c As Integer
  Dim t As Integer
  a = -1
  b = -1
  c = -1
  I = Rows - 1
  Do
    If LineFull(I) Then
      If (a = -1) Then
        a = I
      Else
        If (b = -1) Then
          b = I
        Else
          If (c = -1) Then
            c = I
          End If
        End If
      End If
    End If
    I = I - 1
  Loop Until (I < 1) Or (c <> -1) Or (b = a - 2)
  If (c <> -1) Then
    Timer1.Enabled = False
    'Timer2.Enabled = False
    'MMControl2.Command = "Stop"
    'MMControl2.Command = "Prev"
    MMControl3.Command = "Prev"
    MMControl3.Command = "Play"
    Colapse a
    Colapse a
    Colapse a
    t = Score
    Score = Score + 90
    lbScore = CStr(Score)
    If (((t >= 10) And (t <= 90)) Or ((t >= 110) And (t <= 190)) Or ((t >= 210) And (t <= 290)) Or ((t >= 310) And (t <= 390)) Or ((t >= 410) And (t <= 490)) Or ((t >= 510) And (t <= 590))) And (Level < 7) Then
      Level = Level + 1
      K = K + 1
      Timer1.Interval = 50 + (8 - Level) * 60
      lbLevel = CStr(Level)
      Timer2.Enabled = False
      MMControl2.Command = "Stop"
      MediaPlayer1.Mute = False
      
      frmSecond.BorderStyle = 4
      Load frmSecond
      frmSecond.Move frmPentix.Left + frmPentix.Width \ 2 - frmSecond.Width \ 2, frmPentix.Top + frmPentix.Height \ 2 - frmSecond.Height \ 2
      frmSecond.Show 1
      
      'MediaPlayer1.Mute = True
      'MMControl2.Command = "Play"
      Timer2.Enabled = True
    End If
    Timer1.Enabled = True
  Else
    If (b <> -1) Then
      Timer1.Enabled = False
      'Timer2.Enabled = False
      'MMControl2.Command = "Stop"
      'MMControl2.Command = "Prev"
      MMControl3.Command = "Prev"
      MMControl3.Command = "Play"
      If (b = a - 1) Then
        Colapse a
        Colapse a
      Else
        Colapse a
        Colapse a - 1
      End If
      t = Score
      Score = Score + 40
      lbScore = CStr(Score)
      If (((t >= 60) And (t <= 90)) Or ((t >= 160) And (t <= 190)) Or ((t >= 260) And (t <= 290)) Or ((t >= 360) And (t <= 390)) Or ((t >= 460) And (t <= 490)) Or ((t >= 560) And (t <= 590))) And (Level < 7) Then
        Level = Level + 1
        K = K + 1
        Timer1.Interval = 50 + (8 - Level) * 60
        lbLevel = CStr(Level)
        Timer2.Enabled = False
        MMControl2.Command = "Stop"
        MediaPlayer1.Mute = False
        
        Load frmSecond
        frmSecond.Move frmPentix.Left + frmPentix.Width \ 2 - frmSecond.Width \ 2, frmPentix.Top + frmPentix.Height \ 2 - frmSecond.Height \ 2
        frmSecond.BorderStyle = 4
        frmSecond.Show 1
        
        'MediaPlayer1.Mute = True
        'MMControl2.Command = "Play"
        Timer2.Enabled = True
      End If
      Timer1.Enabled = True
    Else
      If (a <> -1) Then
        Timer1.Enabled = False
        'Timer2.Enabled = False
        'MMControl2.Command = "Stop"
        'MMControl2.Command = "Prev"
        MMControl3.Command = "Prev"
        MMControl3.Command = "Play"
        Colapse a
        Score = Score + 10
        lbScore = CStr(Score)
        If (Score Mod 100 = 0) And (Level < 7) Then
          Level = Level + 1
          K = K + 1
          Timer1.Interval = 50 + (8 - Level) * 60
          lbLevel = CStr(Level)
          Timer2.Enabled = False
          MMControl2.Command = "Stop"
          MediaPlayer1.Mute = False

          Load frmSecond
          frmSecond.Move frmPentix.Left + frmPentix.Width \ 2 - frmSecond.Width \ 2, frmPentix.Top + frmPentix.Height \ 2 - frmSecond.Height \ 2
          frmSecond.BorderStyle = 4
          frmSecond.Show 1
          
          'MediaPlayer1.Mute = True
          'MMControl2.Command = "Play"
          Timer2.Enabled = True
          
        End If
        Timer1.Enabled = True
      End If
    End If
  End If
  
        
  'I = Rows - 1
  'Do
    'If LineFull(I) Then
      'Colapse I
    'Else
      'I = I - 1
    'End If
  'Loop Until I < 1
End Sub
Private Sub SetDrop()
  Dim I, J As Integer
  Dim Index As Integer
  For J = 1 To 3
    For I = 1 To 3
      Index = CellAt(PX, PY, J, I)
      If Index < Rows * Columns Then
        If PItem(J, I) = 1 Then
          Cells(Index).Tag = 1
          Cells(Index).Picture = imgSetDrop.Picture
          'Cells(Index).BorderStyle = 1
        End If
      End If
    Next I
  Next J
  CheckColapse
End Sub
Private Sub DropItem()
  Dim I As Integer
  I = 0
  Timer1.Enabled = False
  'Timer2.Enabled = False
  If (KeyFlag = True) Then
    MMControl1.Command = "Prev"
    MMControl1.Command = "Play"
  End If
  Do While (Not Touch) And (I <= K)
    ClearItem PX, PY
    PY = PY + 1
    DrawItem PX, PY
    I = I + 1
  Loop
  If Touch Then
    SetDrop
    NewItem
    DrawItem PX, PY
  End If
  'MMControl1.Command = "Prev"
  Timer1.Enabled = True
  'Timer2.Enabled = True
End Sub
Private Sub StartGame()
  Dim I As Integer
  
  For I = 0 To Rows * Columns - 1
    Cells(I).Picture = Nothing
    Cells(I).Tag = 0
    Cells(I).BorderStyle = 0
  Next I
  lbGameOver.Visible = False
  GameStarted = True
  mnuStart.Enabled = False
  mnuStop.Enabled = True
  
  Timer1.Interval = 50 + (8 - Level) * 60
  Timer1.Enabled = True
  Timer2.Interval = 760
  Timer2.Enabled = True
  
  NextShape = Int(Rnd * 100) Mod NumberShape + 1
  NextColor = Int(Rnd * NumberColor)
  For I = 0 To 8
    imgNext(I).Visible = True
  Next I
  mnuNext.Checked = True
  NewItem
  lbScore.Caption = CStr(Score)
  lbLevel.Caption = CStr(Level)
  KeyFlag = True
  
  MMControl1.FileName = "D:\PENTIX\LASER.WAV"
  MMControl1.Command = "Open"
  MMControl2.FileName = "D:\PENTIX\TINHCO.WAV"
  MMControl2.Command = "Open"
  MMControl3.FileName = "D:\PENTIX\DRUMROLL.WAV"
  MMControl3.Command = "Open"
  MediaPlayer1.Mute = True

  
  Timer1.Interval = 50 + (8 - Level) * 60
  Timer1.Enabled = True
  Timer2.Interval = MMControl2.Length
  Timer2.Enabled = True
  'ReDim Test(NumberShape + 1) As Integer
  For I = 1 To NumberShape
    Test(I) = 0
  Next I
  Test(NextShape) = 1
End Sub
Private Sub StopGame()
  Dim I As Integer
   
  Timer1.Enabled = False
  Timer2.Enabled = False
  
  For I = 0 To Rows * Columns - 1
    Cells(I).Picture = imgEnd.Picture
    'Cells(I).BorderStyle = 1
  Next I
  For I = 0 To 8
    imgNext(I).Picture = Nothing
  Next I
  lbGameOver.Visible = True
  GameStarted = False
  mnuStart.Enabled = True
  mnuStop.Enabled = False
  KeyFlag = False
  
  Score = 0
  Level = 1
  
  MMControl1.Command = "Close"
  MMControl2.Command = "Close"
  MediaPlayer1.Mute = False

End Sub

Private Sub Form_Load()
  Dim I As Integer
  PenShape(1) = "100000000"
  PenShape(2) = "110000000"
  PenShape(3) = "111000000"
  PenShape(4) = "110100000"
  PenShape(5) = "110010000"
  PenShape(10) = "110011000"
  PenShape(11) = "011110000"
  PenShape(8) = "001111000"
  PenShape(9) = "111100000"
  PenShape(6) = "110110000"
  PenShape(12) = "010111010"
  PenShape(13) = "100111001"
  PenShape(14) = "001111100"
  PenShape(7) = "111010000"
  Picture1.BackColor = 0
  Picture2.BackColor = 0
  GameStarted = False
  lbGameOver.Visible = False
  mnuStart.Enabled = True
  mnuStop.Enabled = False
  Timer1.Enabled = False
  lbScore.Caption = "        "
  lbLevel.Caption = "        "
  Randomize
  MakeCells

  For I = 0 To 8
    imgNext(I).Visible = False
    imgNext(I).Picture = Nothing
  Next I
  mnuNext.Checked = False
  KeyFlag = False
  NumberShape = 14
  NumberColor = 5
  Score = 0
  Level = 1
  K = 4
  
  Timer1.Enabled = False
  Timer2.Enabled = False
  'Timer3.Enabled = True
  
  
  MMControl1.Visible = False
  MMControl1.DeviceType = "WaveAudio"
  
  MMControl2.Visible = False
  MMControl2.DeviceType = "WaveAudio"
  
  MMControl3.Visible = False
  MMControl3.DeviceType = "WaveAudio"
  
  MediaPlayer1.FileName = "D:\PENTIX\T0000003.AVI"
  MediaPlayer1.Mute = False
  
  Timer3.Interval = MediaPlayer1.BufferingTime
End Sub

Private Sub Form_Paint()
  Dim I As Integer
  Dim dh As Integer
  dh = (ScaleHeight \ 195) + 1
  For I = 60 To 255
   Line (0, (I - 60) * dh)-(ScaleWidth, (I - 60 + 1) * dh), RGB(I \ 4, I \ 2, I), BF
  Next I
End Sub

Private Sub Form_Unload(Cancel As Integer)
  MMControl1.Command = "Close"
  MMControl2.Command = "Close"
End Sub

Private Sub mnuExit_Click()
  StopGame
  End
End Sub


Private Sub mnuNext_Click()
  Dim I As Integer
  For I = 0 To 8
    imgNext(I).Visible = Not imgNext(I).Visible
  Next I
  mnuNext.Checked = imgNext(0).Visible
End Sub

Private Sub mnuMusic_Click()
    mnuMusic.Checked = Not mnuMusic.Checked
    If mnuMusic.Checked = True Then
        Timer2.Enabled = True
        'Timer3.Enabled = True
        'MMControl1.Command = "Play"
        MMControl2.Command = "Play"
        'MMControl3.Command = "Play"
        MediaPlayer1.Mute = False
    Else
        'MMControl1.Command = "Stop"
        MMControl2.Command = "Stop"
        'MMControl3.Command = "Stop"
        MediaPlayer1.Mute = True
        Timer2.Enabled = False
        'Timer3.Enabled = False
    End If
    
        
End Sub

Private Sub mnuStart_Click()
  StartGame
End Sub

Private Sub mnuStop_Click()
  StopGame
End Sub

Private Sub Picture1_KeyDown(KeyCode As Integer, Shift As Integer)
  If (GameStarted = False) Then
    Exit Sub
  End If
  Select Case KeyCode
    Case vbKeyLeft, vbKeyNumpad4
      If Timer1.Enabled = False Then
        Exit Sub
      End If
      If CanLeft Then
        ClearItem PX, PY
        PX = PX - 1
        DrawItem PX, PY
      End If
    Case vbKeyRight, vbKeyNumpad6
      If Timer1.Enabled = False Then
        Exit Sub
      End If
      If CanRight Then
        ClearItem PX, PY
        PX = PX + 1
        DrawItem PX, PY
      End If
    Case vbKeyUp, vbKeyNumpad8, vbKeySpace
      If Timer1.Enabled = False Then
        Exit Sub
      End If
      If CanRotate Then
        ClearItem PX, PY
        RotateItem
        DrawItem PX, PY
      End If
    Case vbKeyNumpad5, vbKeyDown
      If Timer1.Enabled = False Then
        Exit Sub
      End If
      'If KeyFlag = True Then
        DropItem
        KeyFlag = False
      'End If
    Case vbKeyEscape
      Timer1.Enabled = Not Timer1.Enabled
  End Select
  'KeyFlag = False
End Sub

Private Sub Picture1_KeyUp(KeyCode As Integer, Shift As Integer)
  KeyFlag = True
End Sub

Private Sub Timer1_Timer()
  If Touch Then
    SetDrop
    NewItem
    PX = 4
    PY = 0
    If Touch Then
      StopGame
    Else
      DrawItem PX, PY
    End If
  Else
    ClearItem PX, PY
    PY = PY + 1
    DrawItem PX, PY
  End If
End Sub

Private Sub Timer2_Timer()
  MediaPlayer1.Mute = True
  MMControl2.Command = "Prev"
  MMControl2.Command = "Play"
End Sub

Private Sub Timer3_Timer()
    MediaPlayer1.Play
End Sub
