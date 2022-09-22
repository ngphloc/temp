VERSION 5.00
Object = "{00028C01-0000-0000-0000-000000000046}#1.0#0"; "DBGRID32.OCX"
Object = "{BDC217C8-ED16-11CD-956C-0000C04E4C0A}#1.1#0"; "TABCTL32.OCX"
Begin VB.Form frmMain 
   Caption         =   "frmMain"
   ClientHeight    =   6390
   ClientLeft      =   165
   ClientTop       =   735
   ClientWidth     =   7530
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
   ScaleHeight     =   6390
   ScaleWidth      =   7530
   StartUpPosition =   3  'Windows Default
   Begin TabDlg.SSTab SSTab1 
      Height          =   5655
      Left            =   120
      TabIndex        =   0
      Top             =   720
      Width           =   7365
      _ExtentX        =   12991
      _ExtentY        =   9975
      _Version        =   393216
      Tabs            =   6
      Tab             =   1
      TabsPerRow      =   6
      TabHeight       =   520
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "VNI-Times"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      TabCaption(0)   =   "Hoïc Sinh"
      TabPicture(0)   =   "frmMain.frx":0000
      Tab(0).ControlEnabled=   0   'False
      Tab(0).Control(0)=   "cmdHSXepLop"
      Tab(0).Control(1)=   "cmdDiem"
      Tab(0).Control(2)=   "DataDiem"
      Tab(0).Control(3)=   "cmdThucHienHS"
      Tab(0).Control(4)=   "cmdQuayVeHS"
      Tab(0).Control(5)=   "cmdCapNhatHS"
      Tab(0).Control(6)=   "cmdXoaHS"
      Tab(0).Control(7)=   "cmdThemHS"
      Tab(0).Control(8)=   "cmdTraCuuHS"
      Tab(0).Control(9)=   "txtSoNgayVang"
      Tab(0).Control(10)=   "cmbDienHS"
      Tab(0).Control(11)=   "txtDiaChiHS"
      Tab(0).Control(12)=   "chkNam"
      Tab(0).Control(13)=   "txtNgaySinhHS"
      Tab(0).Control(14)=   "txtHoTenHS"
      Tab(0).Control(15)=   "txtMaHS"
      Tab(0).Control(16)=   "DataHocSinh"
      Tab(0).Control(17)=   "lbSoNgayVang"
      Tab(0).Control(18)=   "lbDienHS"
      Tab(0).Control(19)=   "lbDiaChiHS"
      Tab(0).Control(20)=   "lbNgaySinhHS"
      Tab(0).Control(21)=   "lbHoTenHS"
      Tab(0).Control(22)=   "lbMaHS"
      Tab(0).ControlCount=   23
      TabCaption(1)   =   "Giaùo vieân"
      TabPicture(1)   =   "frmMain.frx":001C
      Tab(1).ControlEnabled=   -1  'True
      Tab(1).Control(0)=   "lbMaGV"
      Tab(1).Control(0).Enabled=   0   'False
      Tab(1).Control(1)=   "lbHoTenGV"
      Tab(1).Control(1).Enabled=   0   'False
      Tab(1).Control(2)=   "lbNgaySinhGV"
      Tab(1).Control(2).Enabled=   0   'False
      Tab(1).Control(3)=   "lbDiaChiGV"
      Tab(1).Control(3).Enabled=   0   'False
      Tab(1).Control(4)=   "txtMaGV"
      Tab(1).Control(4).Enabled=   0   'False
      Tab(1).Control(5)=   "txtHoTenGV"
      Tab(1).Control(5).Enabled=   0   'False
      Tab(1).Control(6)=   "chkNamGV"
      Tab(1).Control(6).Enabled=   0   'False
      Tab(1).Control(7)=   "txtNgaySinhGV"
      Tab(1).Control(7).Enabled=   0   'False
      Tab(1).Control(8)=   "txtDiaChiGV"
      Tab(1).Control(8).Enabled=   0   'False
      Tab(1).Control(9)=   "DBGridGV"
      Tab(1).Control(9).Enabled=   0   'False
      Tab(1).Control(10)=   "DataGiaoVien"
      Tab(1).Control(10).Enabled=   0   'False
      Tab(1).Control(11)=   "cmdThucHienGV"
      Tab(1).Control(11).Enabled=   0   'False
      Tab(1).Control(12)=   "cmdQuayVeGV"
      Tab(1).Control(12).Enabled=   0   'False
      Tab(1).Control(13)=   "cmdCapNhatGV"
      Tab(1).Control(13).Enabled=   0   'False
      Tab(1).Control(14)=   "cmdTraCuuGV"
      Tab(1).Control(14).Enabled=   0   'False
      Tab(1).Control(15)=   "cmdThemGV"
      Tab(1).Control(15).Enabled=   0   'False
      Tab(1).Control(16)=   "cmdXoaGV"
      Tab(1).Control(16).Enabled=   0   'False
      Tab(1).Control(17)=   "cmdDay"
      Tab(1).Control(17).Enabled=   0   'False
      Tab(1).Control(18)=   "cmdChuNhiem"
      Tab(1).Control(18).Enabled=   0   'False
      Tab(1).ControlCount=   19
      TabCaption(2)   =   "Moân hoïc"
      TabPicture(2)   =   "frmMain.frx":0038
      Tab(2).ControlEnabled=   0   'False
      Tab(2).Control(0)=   "lbMaMH"
      Tab(2).Control(0).Enabled=   0   'False
      Tab(2).Control(1)=   "lbTenMH"
      Tab(2).Control(1).Enabled=   0   'False
      Tab(2).Control(2)=   "lbSotiet"
      Tab(2).Control(2).Enabled=   0   'False
      Tab(2).Control(3)=   "lbHeso"
      Tab(2).Control(3).Enabled=   0   'False
      Tab(2).Control(4)=   "lbGhiChuMH"
      Tab(2).Control(4).Enabled=   0   'False
      Tab(2).Control(5)=   "txtMaMH"
      Tab(2).Control(5).Enabled=   0   'False
      Tab(2).Control(6)=   "txtTenMH"
      Tab(2).Control(6).Enabled=   0   'False
      Tab(2).Control(7)=   "txtSotiet"
      Tab(2).Control(7).Enabled=   0   'False
      Tab(2).Control(8)=   "txtHeso"
      Tab(2).Control(8).Enabled=   0   'False
      Tab(2).Control(9)=   "txtGhiChu"
      Tab(2).Control(9).Enabled=   0   'False
      Tab(2).Control(10)=   "DBGridMH"
      Tab(2).Control(10).Enabled=   0   'False
      Tab(2).Control(11)=   "DataMonHoc"
      Tab(2).Control(11).Enabled=   0   'False
      Tab(2).Control(12)=   "cmdThemMH"
      Tab(2).Control(12).Enabled=   0   'False
      Tab(2).Control(13)=   "cmdXoaMH"
      Tab(2).Control(13).Enabled=   0   'False
      Tab(2).Control(14)=   "cmdTraCuuMH"
      Tab(2).Control(14).Enabled=   0   'False
      Tab(2).Control(15)=   "cmdCapNhatMH"
      Tab(2).Control(15).Enabled=   0   'False
      Tab(2).Control(16)=   "cmdThucHienMH"
      Tab(2).Control(16).Enabled=   0   'False
      Tab(2).Control(17)=   "cmdQuayVeMH"
      Tab(2).Control(17).Enabled=   0   'False
      Tab(2).ControlCount=   18
      TabCaption(3)   =   "Lôùp hoïc"
      TabPicture(3)   =   "frmMain.frx":0054
      Tab(3).ControlEnabled=   0   'False
      Tab(3).Control(0)=   "lbMaLop"
      Tab(3).Control(0).Enabled=   0   'False
      Tab(3).Control(1)=   "lbTenLop"
      Tab(3).Control(1).Enabled=   0   'False
      Tab(3).Control(2)=   "lbKhoiLop"
      Tab(3).Control(2).Enabled=   0   'False
      Tab(3).Control(3)=   "lbNienKhoa"
      Tab(3).Control(3).Enabled=   0   'False
      Tab(3).Control(4)=   "lbPhong"
      Tab(3).Control(4).Enabled=   0   'False
      Tab(3).Control(5)=   "lbSiSo"
      Tab(3).Control(5).Enabled=   0   'False
      Tab(3).Control(6)=   "txtMaLop"
      Tab(3).Control(6).Enabled=   0   'False
      Tab(3).Control(7)=   "txtTenLop"
      Tab(3).Control(7).Enabled=   0   'False
      Tab(3).Control(8)=   "cmbNienKhoa"
      Tab(3).Control(8).Enabled=   0   'False
      Tab(3).Control(9)=   "cmbPhong"
      Tab(3).Control(9).Enabled=   0   'False
      Tab(3).Control(10)=   "txtSiSo"
      Tab(3).Control(10).Enabled=   0   'False
      Tab(3).Control(11)=   "cmbKhoiLop"
      Tab(3).Control(11).Enabled=   0   'False
      Tab(3).Control(12)=   "DBGridLop"
      Tab(3).Control(12).Enabled=   0   'False
      Tab(3).Control(13)=   "DataLop"
      Tab(3).Control(13).Enabled=   0   'False
      Tab(3).Control(14)=   "cmdThucHienLop"
      Tab(3).Control(14).Enabled=   0   'False
      Tab(3).Control(15)=   "cmdQuayVeLop"
      Tab(3).Control(15).Enabled=   0   'False
      Tab(3).Control(16)=   "cmdCapNhatLop"
      Tab(3).Control(16).Enabled=   0   'False
      Tab(3).Control(17)=   "cmdTraCuuLop"
      Tab(3).Control(17).Enabled=   0   'False
      Tab(3).Control(18)=   "cmdThemLop"
      Tab(3).Control(18).Enabled=   0   'False
      Tab(3).Control(19)=   "cmdXoaLop"
      Tab(3).Control(19).Enabled=   0   'False
      Tab(3).ControlCount=   20
      TabCaption(4)   =   "Phoøng hoïc"
      TabPicture(4)   =   "frmMain.frx":0070
      Tab(4).ControlEnabled=   0   'False
      Tab(4).Control(0)=   "lbMaPHG"
      Tab(4).Control(0).Enabled=   0   'False
      Tab(4).Control(1)=   "lbTenPHG"
      Tab(4).Control(1).Enabled=   0   'False
      Tab(4).Control(2)=   "lbGhiChuPHG"
      Tab(4).Control(2).Enabled=   0   'False
      Tab(4).Control(3)=   "DataPHG"
      Tab(4).Control(3).Enabled=   0   'False
      Tab(4).Control(4)=   "txtMaPHG"
      Tab(4).Control(4).Enabled=   0   'False
      Tab(4).Control(5)=   "txtTenPHG"
      Tab(4).Control(5).Enabled=   0   'False
      Tab(4).Control(6)=   "txtGhiChuPHG"
      Tab(4).Control(6).Enabled=   0   'False
      Tab(4).Control(7)=   "DBGridPHG"
      Tab(4).Control(7).Enabled=   0   'False
      Tab(4).Control(8)=   "cmdThucHienPHG"
      Tab(4).Control(8).Enabled=   0   'False
      Tab(4).Control(9)=   "cmdQuayVePHG"
      Tab(4).Control(9).Enabled=   0   'False
      Tab(4).Control(10)=   "cmdCapNhatPHG"
      Tab(4).Control(10).Enabled=   0   'False
      Tab(4).Control(11)=   "cmdTraCuuPHG"
      Tab(4).Control(11).Enabled=   0   'False
      Tab(4).Control(12)=   "cmdThemPHG"
      Tab(4).Control(12).Enabled=   0   'False
      Tab(4).Control(13)=   "cmdXoaPHG"
      Tab(4).Control(13).Enabled=   0   'False
      Tab(4).ControlCount=   14
      TabCaption(5)   =   "TK Bieåu"
      TabPicture(5)   =   "frmMain.frx":008C
      Tab(5).ControlEnabled=   0   'False
      Tab(5).Control(0)=   "DBGridTKB"
      Tab(5).Control(0).Enabled=   0   'False
      Tab(5).Control(1)=   "DataTKB"
      Tab(5).Control(1).Enabled=   0   'False
      Tab(5).Control(2)=   "cmdThemTKB"
      Tab(5).Control(2).Enabled=   0   'False
      Tab(5).Control(3)=   "cmdXoaTKB"
      Tab(5).Control(3).Enabled=   0   'False
      Tab(5).Control(4)=   "cmdGhiTKB"
      Tab(5).Control(4).Enabled=   0   'False
      Tab(5).ControlCount=   5
      Begin VB.CommandButton cmdChuNhiem 
         Caption         =   "Chuû Nhieäm"
         Height          =   375
         Left            =   4920
         TabIndex        =   93
         Top             =   4920
         Width           =   1095
      End
      Begin VB.CommandButton cmdGhiTKB 
         Caption         =   "Ghi"
         Height          =   375
         Left            =   -69480
         TabIndex        =   92
         Top             =   4920
         Width           =   1095
      End
      Begin VB.CommandButton cmdXoaTKB 
         Caption         =   "Xoùa"
         Height          =   375
         Left            =   -72000
         TabIndex        =   91
         Top             =   4920
         Width           =   1215
      End
      Begin VB.CommandButton cmdThemTKB 
         Caption         =   "Theâm"
         Height          =   375
         Left            =   -74280
         TabIndex        =   90
         Top             =   4920
         Width           =   1095
      End
      Begin VB.Data DataTKB 
         Connect         =   "Access"
         DatabaseName    =   "D:\CNPM\qlhs.mdb"
         DefaultCursorType=   0  'DefaultCursor
         DefaultType     =   2  'UseODBC
         Exclusive       =   0   'False
         Height          =   360
         Left            =   -72480
         Options         =   0
         ReadOnly        =   0   'False
         RecordsetType   =   1  'Dynaset
         RecordSource    =   "TKBQuery"
         Top             =   4320
         Width           =   2655
      End
      Begin MSDBGrid.DBGrid DBGridTKB 
         Bindings        =   "frmMain.frx":00A8
         Height          =   3615
         Left            =   -74640
         OleObjectBlob   =   "frmMain.frx":00CB
         TabIndex        =   89
         Top             =   600
         Width           =   6615
      End
      Begin VB.CommandButton cmdXoaPHG 
         Caption         =   "Xoùa PHG"
         Height          =   375
         Left            =   -72840
         TabIndex        =   87
         Top             =   4560
         Width           =   1095
      End
      Begin VB.CommandButton cmdThemPHG 
         Caption         =   "Theâm PHG"
         Height          =   375
         Left            =   -74640
         TabIndex        =   86
         Top             =   4560
         Width           =   1095
      End
      Begin VB.CommandButton cmdTraCuuPHG 
         Caption         =   "Tra Cöùu"
         Height          =   375
         Left            =   -69240
         TabIndex        =   85
         Top             =   4560
         Width           =   1095
      End
      Begin VB.CommandButton cmdCapNhatPHG 
         Caption         =   "Caäp nhaät laïi "
         BeginProperty Font 
            Name            =   "VNI-Times"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   -71040
         TabIndex        =   84
         Top             =   4560
         Width           =   1095
      End
      Begin VB.CommandButton cmdQuayVePHG 
         Caption         =   "Quay veà"
         Height          =   375
         Left            =   -72840
         TabIndex        =   83
         Top             =   4560
         Width           =   1095
      End
      Begin VB.CommandButton cmdThucHienPHG 
         Caption         =   "Thöïc Hieän"
         Height          =   375
         Left            =   -74640
         TabIndex        =   82
         Top             =   4560
         Width           =   1095
      End
      Begin MSDBGrid.DBGrid DBGridPHG 
         Bindings        =   "frmMain.frx":0AA8
         Height          =   2655
         Left            =   -71040
         OleObjectBlob   =   "frmMain.frx":0ACB
         TabIndex        =   81
         Top             =   720
         Width           =   3255
      End
      Begin VB.TextBox txtGhiChuPHG 
         DataField       =   "GhiChu"
         DataSource      =   "DataPHG"
         Height          =   375
         Left            =   -73560
         TabIndex        =   80
         Top             =   3000
         Width           =   2055
      End
      Begin VB.TextBox txtTenPHG 
         DataField       =   "TenPHG"
         DataSource      =   "DataPHG"
         Height          =   375
         Left            =   -73560
         TabIndex        =   78
         Top             =   1920
         Width           =   1455
      End
      Begin VB.TextBox txtMaPHG 
         DataField       =   "MaPHG"
         DataSource      =   "DataPHG"
         Height          =   375
         Left            =   -73560
         TabIndex        =   76
         Top             =   720
         Width           =   1455
      End
      Begin VB.Data DataPHG 
         Connect         =   "Access"
         DatabaseName    =   "D:\CNPM\qlhs.mdb"
         DefaultCursorType=   0  'DefaultCursor
         DefaultType     =   2  'UseODBC
         Exclusive       =   0   'False
         Height          =   360
         Left            =   -72120
         Options         =   0
         ReadOnly        =   0   'False
         RecordsetType   =   1  'Dynaset
         RecordSource    =   "Phong"
         Top             =   3840
         Width           =   2415
      End
      Begin VB.CommandButton cmdXoaLop 
         Caption         =   "Xoùa Lôùp"
         Height          =   375
         Left            =   -72840
         TabIndex        =   74
         Top             =   4800
         Width           =   1095
      End
      Begin VB.CommandButton cmdThemLop 
         Caption         =   "Theâm lôùp"
         Height          =   375
         Left            =   -74760
         TabIndex        =   73
         Top             =   4800
         Width           =   1095
      End
      Begin VB.CommandButton cmdTraCuuLop 
         Caption         =   "Tra cöùu lôùp"
         Height          =   375
         Left            =   -69000
         TabIndex        =   72
         Top             =   4800
         Width           =   1095
      End
      Begin VB.CommandButton cmdCapNhatLop 
         Caption         =   "Caäp nhaät laïi"
         BeginProperty Font 
            Name            =   "VNI-Times"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   -70920
         TabIndex        =   71
         Top             =   4800
         Width           =   1095
      End
      Begin VB.CommandButton cmdQuayVeLop 
         Caption         =   "Quay Veà"
         Height          =   375
         Left            =   -72840
         TabIndex        =   70
         Top             =   4800
         Visible         =   0   'False
         Width           =   1095
      End
      Begin VB.CommandButton cmdThucHienLop 
         Caption         =   "Thöïc Hieän"
         Height          =   375
         Left            =   -74760
         TabIndex        =   69
         Top             =   4800
         Visible         =   0   'False
         Width           =   1095
      End
      Begin VB.Data DataLop 
         Connect         =   "Access"
         DatabaseName    =   "D:\CNPM\qlhs.mdb"
         DefaultCursorType=   0  'DefaultCursor
         DefaultType     =   2  'UseODBC
         Exclusive       =   0   'False
         Height          =   360
         Left            =   -72360
         Options         =   0
         ReadOnly        =   0   'False
         RecordsetType   =   1  'Dynaset
         RecordSource    =   "Lop"
         Top             =   4200
         Width           =   2295
      End
      Begin MSDBGrid.DBGrid DBGridLop 
         Bindings        =   "frmMain.frx":1498
         Height          =   3135
         Left            =   -71160
         OleObjectBlob   =   "frmMain.frx":14BB
         TabIndex        =   68
         Top             =   840
         Width           =   3375
      End
      Begin VB.ComboBox cmbKhoiLop 
         DataField       =   "KhoiLop"
         DataSource      =   "DataLop"
         Height          =   375
         Left            =   -73440
         TabIndex        =   67
         Top             =   1800
         Width           =   1335
      End
      Begin VB.TextBox txtSiSo 
         DataField       =   "SiSo"
         DataSource      =   "DataLop"
         Height          =   375
         Left            =   -73440
         TabIndex        =   66
         Top             =   3600
         Width           =   1335
      End
      Begin VB.ComboBox cmbPhong 
         DataField       =   "Phong"
         DataSource      =   "DataLop"
         Height          =   375
         Left            =   -73440
         TabIndex        =   64
         Top             =   3000
         Width           =   1335
      End
      Begin VB.ComboBox cmbNienKhoa 
         DataField       =   "NienKhoa"
         DataSource      =   "DataLop"
         Height          =   375
         Left            =   -73440
         TabIndex        =   62
         Top             =   2400
         Width           =   1335
      End
      Begin VB.TextBox txtTenLop 
         DataField       =   "TenLop"
         DataSource      =   "DataLop"
         Height          =   375
         Left            =   -73440
         TabIndex        =   59
         Top             =   1200
         Width           =   1335
      End
      Begin VB.CommandButton cmdQuayVeMH 
         Caption         =   "Quay veà"
         Height          =   375
         Left            =   -72720
         TabIndex        =   57
         Top             =   4440
         Visible         =   0   'False
         Width           =   1095
      End
      Begin VB.CommandButton cmdThucHienMH 
         Caption         =   "Thöïc Hieän"
         Height          =   375
         Left            =   -74520
         TabIndex        =   56
         Top             =   4440
         Visible         =   0   'False
         Width           =   1215
      End
      Begin VB.CommandButton cmdCapNhatMH 
         Caption         =   "Caäp nhaät laïi"
         BeginProperty Font 
            Name            =   "VNI-Times"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   -71040
         TabIndex        =   55
         Top             =   4440
         Width           =   1095
      End
      Begin VB.CommandButton cmdTraCuuMH 
         Caption         =   "Tra cöùu MH"
         Height          =   375
         Left            =   -69360
         TabIndex        =   54
         Top             =   4440
         Width           =   1215
      End
      Begin VB.CommandButton cmdXoaMH 
         Caption         =   "Xoùa MH"
         Height          =   375
         Left            =   -72720
         TabIndex        =   53
         Top             =   4440
         Width           =   1095
      End
      Begin VB.CommandButton cmdThemMH 
         Caption         =   "Theâm MH"
         Height          =   375
         Left            =   -74520
         TabIndex        =   52
         Top             =   4440
         Width           =   1215
      End
      Begin VB.Data DataMonHoc 
         Connect         =   "Access"
         DatabaseName    =   "D:\CNPM\qlhs.mdb"
         DefaultCursorType=   0  'DefaultCursor
         DefaultType     =   2  'UseODBC
         Exclusive       =   0   'False
         Height          =   360
         Left            =   -72360
         Options         =   0
         ReadOnly        =   0   'False
         RecordsetType   =   1  'Dynaset
         RecordSource    =   "MonHoc"
         Top             =   3720
         Width           =   2295
      End
      Begin MSDBGrid.DBGrid DBGridMH 
         Bindings        =   "frmMain.frx":1E88
         Height          =   2655
         Left            =   -71160
         OleObjectBlob   =   "frmMain.frx":1EBD
         TabIndex        =   51
         Top             =   720
         Width           =   3375
      End
      Begin VB.TextBox txtGhiChu 
         DataField       =   "Ghichu"
         DataSource      =   "DataMonHoc"
         Height          =   375
         Left            =   -73440
         TabIndex        =   50
         Top             =   3000
         Width           =   1695
      End
      Begin VB.TextBox txtHeso 
         DataField       =   "Heso"
         DataSource      =   "DataMonHoc"
         Height          =   375
         Left            =   -73440
         TabIndex        =   48
         Top             =   2400
         Width           =   1095
      End
      Begin VB.TextBox txtSotiet 
         DataField       =   "Sotiet"
         DataSource      =   "DataMonHoc"
         Height          =   375
         Left            =   -73440
         TabIndex        =   46
         Top             =   1800
         Width           =   1095
      End
      Begin VB.TextBox txtTenMH 
         DataField       =   "TenMH"
         DataSource      =   "DataMonHoc"
         Height          =   375
         Left            =   -73440
         TabIndex        =   44
         Top             =   1200
         Width           =   1695
      End
      Begin VB.TextBox txtMaMH 
         DataField       =   "MaMH"
         DataSource      =   "DataMonHoc"
         Height          =   375
         Left            =   -73440
         TabIndex        =   42
         Top             =   600
         Width           =   1095
      End
      Begin VB.CommandButton cmdDay 
         Caption         =   "Daïy"
         Height          =   375
         Left            =   1320
         TabIndex        =   40
         Top             =   4920
         Width           =   1095
      End
      Begin VB.CommandButton cmdXoaGV 
         Caption         =   "Xoùa GV"
         Height          =   375
         Left            =   2280
         TabIndex        =   39
         Top             =   4320
         Width           =   1215
      End
      Begin VB.CommandButton cmdThemGV 
         Caption         =   "Theâm GV"
         Height          =   375
         Left            =   360
         TabIndex        =   38
         Top             =   4320
         Width           =   1215
      End
      Begin VB.CommandButton cmdTraCuuGV 
         Caption         =   "Tra Cöùu GV"
         Height          =   375
         Left            =   5760
         TabIndex        =   37
         Top             =   4320
         Width           =   1095
      End
      Begin VB.CommandButton cmdCapNhatGV 
         Caption         =   "Caäp nhaät laïl"
         BeginProperty Font 
            Name            =   "VNI-Times"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   4080
         TabIndex        =   36
         Top             =   4320
         Width           =   1095
      End
      Begin VB.CommandButton cmdQuayVeGV 
         Caption         =   "Quay Veà"
         Height          =   375
         Left            =   2280
         TabIndex        =   35
         Top             =   4320
         Visible         =   0   'False
         Width           =   1215
      End
      Begin VB.CommandButton cmdThucHienGV 
         Caption         =   "Thöïc Hieän"
         Height          =   375
         Left            =   360
         TabIndex        =   34
         Top             =   4320
         Visible         =   0   'False
         Width           =   1215
      End
      Begin VB.Data DataGiaoVien 
         Connect         =   "Access"
         DatabaseName    =   "D:\CNPM\qlhs.mdb"
         DefaultCursorType=   0  'DefaultCursor
         DefaultType     =   2  'UseODBC
         Exclusive       =   0   'False
         Height          =   360
         Left            =   2760
         Options         =   0
         ReadOnly        =   0   'False
         RecordsetType   =   1  'Dynaset
         RecordSource    =   "GiaoVien"
         Top             =   3600
         Width           =   2295
      End
      Begin MSDBGrid.DBGrid DBGridGV 
         Bindings        =   "frmMain.frx":2889
         Height          =   2775
         Left            =   3600
         OleObjectBlob   =   "frmMain.frx":28CC
         TabIndex        =   33
         Top             =   600
         Width           =   3735
      End
      Begin VB.TextBox txtDiaChiGV 
         DataField       =   "DiaChiGV"
         DataSource      =   "DataGiaoVien"
         Height          =   375
         Left            =   1320
         TabIndex        =   32
         Top             =   3000
         Width           =   1335
      End
      Begin VB.TextBox txtNgaySinhGV 
         DataField       =   "NgaySinhGV"
         DataSource      =   "DataGiaoVien"
         Height          =   375
         Left            =   1320
         TabIndex        =   30
         Top             =   2400
         Width           =   1215
      End
      Begin VB.CheckBox chkNamGV 
         Alignment       =   1  'Right Justify
         Caption         =   "Nam"
         DataField       =   "Nam"
         DataSource      =   "DataGiaoVien"
         Height          =   375
         Left            =   240
         TabIndex        =   28
         Top             =   1800
         Width           =   1335
      End
      Begin VB.TextBox txtHoTenGV 
         DataField       =   "HoTenGV"
         DataSource      =   "DataGiaoVien"
         Height          =   375
         Left            =   1320
         TabIndex        =   27
         Top             =   1200
         Width           =   1935
      End
      Begin VB.TextBox txtMaGV 
         DataField       =   "MaGV"
         DataSource      =   "DataGiaoVien"
         Height          =   375
         Left            =   1320
         TabIndex        =   25
         Top             =   600
         Width           =   1215
      End
      Begin VB.TextBox txtMaLop 
         DataField       =   "MaLop"
         DataSource      =   "DataLop"
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
         Left            =   -73440
         TabIndex        =   23
         Top             =   600
         Width           =   1335
      End
      Begin VB.CommandButton cmdHSXepLop 
         Caption         =   "Xeáp lôùp"
         Height          =   375
         Left            =   -73920
         TabIndex        =   21
         Top             =   4800
         Width           =   1695
      End
      Begin VB.CommandButton cmdDiem 
         Caption         =   "Xem phieáu ñieåm"
         BeginProperty Font 
            Name            =   "VNI-Times"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   -70200
         TabIndex        =   20
         Top             =   4800
         Width           =   1575
      End
      Begin VB.Data DataDiem 
         Connect         =   "Access"
         DatabaseName    =   "..\..\..\qlhs.mdb"
         DefaultCursorType=   0  'DefaultCursor
         DefaultType     =   2  'UseODBC
         Exclusive       =   0   'False
         BeginProperty Font 
            Name            =   "VNI-Times"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   345
         Left            =   -67560
         Options         =   0
         ReadOnly        =   0   'False
         RecordsetType   =   1  'Dynaset
         RecordSource    =   "Diem"
         Top             =   5640
         Width           =   2175
      End
      Begin VB.CommandButton cmdThucHienHS 
         Caption         =   "Thöïc hieän "
         BeginProperty Font 
            Name            =   "VNI-Times"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   -74880
         TabIndex        =   19
         Top             =   4200
         Visible         =   0   'False
         Width           =   1095
      End
      Begin VB.CommandButton cmdQuayVeHS 
         Caption         =   "Quay veà"
         Height          =   375
         Left            =   -72840
         TabIndex        =   18
         Top             =   4200
         Visible         =   0   'False
         Width           =   1095
      End
      Begin VB.CommandButton cmdCapNhatHS 
         Caption         =   "Caäp nhaät laïi"
         BeginProperty Font 
            Name            =   "VNI-Times"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   -70800
         TabIndex        =   17
         Top             =   4200
         Width           =   1095
      End
      Begin VB.CommandButton cmdXoaHS 
         Caption         =   "Xoùa HS"
         Height          =   375
         Left            =   -72840
         TabIndex        =   16
         Top             =   4200
         Width           =   1095
      End
      Begin VB.CommandButton cmdThemHS 
         Caption         =   "Theâm HS"
         Height          =   375
         Left            =   -74880
         TabIndex        =   15
         Top             =   4200
         Width           =   1095
      End
      Begin VB.CommandButton cmdTraCuuHS 
         Caption         =   "Tra Cöùu HS"
         Height          =   375
         Left            =   -69000
         TabIndex        =   14
         Top             =   4200
         Width           =   1095
      End
      Begin VB.TextBox txtSoNgayVang 
         DataField       =   "SoNgayVang"
         DataSource      =   "DataHocSinh"
         Height          =   375
         Left            =   -70680
         TabIndex        =   13
         Top             =   2520
         Width           =   975
      End
      Begin VB.ComboBox cmbDienHS 
         DataField       =   "DienHS"
         DataSource      =   "DataHocSinh"
         Height          =   375
         ItemData        =   "frmMain.frx":3298
         Left            =   -73920
         List            =   "frmMain.frx":32AB
         TabIndex        =   11
         Top             =   2640
         Width           =   975
      End
      Begin VB.TextBox txtDiaChiHS 
         DataField       =   "DiaChiHS"
         DataSource      =   "DataHocSinh"
         Height          =   375
         Left            =   -73920
         TabIndex        =   9
         Top             =   1800
         Width           =   1695
      End
      Begin VB.CheckBox chkNam 
         Alignment       =   1  'Right Justify
         Caption         =   "Nam"
         DataField       =   "Nam"
         DataSource      =   "DataHocSinh"
         Height          =   375
         Left            =   -74880
         TabIndex        =   7
         Top             =   1200
         Width           =   1215
      End
      Begin VB.TextBox txtNgaySinhHS 
         DataField       =   "NgaySinhHS"
         DataSource      =   "DataHocSinh"
         Height          =   375
         Left            =   -70680
         TabIndex        =   6
         Top             =   1800
         Width           =   1095
      End
      Begin VB.TextBox txtHoTenHS 
         DataField       =   "HoTenHS"
         DataSource      =   "DataHocSinh"
         Height          =   375
         Left            =   -70680
         TabIndex        =   4
         Top             =   720
         Width           =   1695
      End
      Begin VB.TextBox txtMaHS 
         DataField       =   "MaHS"
         DataSource      =   "DataHocSinh"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   285
         Left            =   -73800
         TabIndex        =   2
         Top             =   720
         Width           =   1095
      End
      Begin VB.Data DataHocSinh 
         Connect         =   "Access"
         DatabaseName    =   "D:\CNPM\qlhs.mdb"
         DefaultCursorType=   0  'DefaultCursor
         DefaultType     =   2  'UseODBC
         Exclusive       =   0   'False
         Height          =   375
         Left            =   -72720
         Options         =   0
         ReadOnly        =   0   'False
         RecordsetType   =   1  'Dynaset
         RecordSource    =   "HocSinh"
         Top             =   3480
         Width           =   2415
      End
      Begin VB.Label lbGhiChuPHG 
         Caption         =   "Ghi chuù"
         Height          =   375
         Left            =   -74760
         TabIndex        =   79
         Top             =   3000
         Width           =   975
      End
      Begin VB.Label lbTenPHG 
         Caption         =   "Teân Phoøng"
         Height          =   375
         Left            =   -74760
         TabIndex        =   77
         Top             =   1920
         Width           =   975
      End
      Begin VB.Label lbMaPHG 
         Caption         =   "Maõ phoøng"
         Height          =   375
         Left            =   -74760
         TabIndex        =   75
         Top             =   720
         Width           =   975
      End
      Begin VB.Label lbSiSo 
         Caption         =   "Só Soá"
         Height          =   375
         Left            =   -74640
         TabIndex        =   65
         Top             =   3600
         Width           =   975
      End
      Begin VB.Label lbPhong 
         Caption         =   "Phoøng"
         Height          =   375
         Left            =   -74640
         TabIndex        =   63
         Top             =   3000
         Width           =   975
      End
      Begin VB.Label lbNienKhoa 
         Caption         =   "Nieân Khoùa"
         Height          =   375
         Left            =   -74640
         TabIndex        =   61
         Top             =   2400
         Width           =   975
      End
      Begin VB.Label lbKhoiLop 
         Caption         =   "Khoái Lôùp"
         Height          =   375
         Left            =   -74640
         TabIndex        =   60
         Top             =   1800
         Width           =   975
      End
      Begin VB.Label lbTenLop 
         Caption         =   "Teân Lôùp"
         Height          =   375
         Left            =   -74640
         TabIndex        =   58
         Top             =   1200
         Width           =   975
      End
      Begin VB.Label lbGhiChuMH 
         Caption         =   "Ghi chuù"
         Height          =   375
         Left            =   -74760
         TabIndex        =   49
         Top             =   3000
         Width           =   1095
      End
      Begin VB.Label lbHeso 
         Caption         =   "Heä soá"
         Height          =   375
         Left            =   -74760
         TabIndex        =   47
         Top             =   2400
         Width           =   855
      End
      Begin VB.Label lbSotiet 
         Caption         =   "Soá tieát"
         Height          =   375
         Left            =   -74760
         TabIndex        =   45
         Top             =   1800
         Width           =   855
      End
      Begin VB.Label lbTenMH 
         Caption         =   "Teân moân hoïc"
         Height          =   375
         Left            =   -74760
         TabIndex        =   43
         Top             =   1200
         Width           =   1095
      End
      Begin VB.Label lbMaMH 
         Caption         =   "Maõ moân hoïc"
         Height          =   375
         Left            =   -74760
         TabIndex        =   41
         Top             =   600
         Width           =   1215
      End
      Begin VB.Label lbDiaChiGV 
         Caption         =   "Ñòa chæ"
         Height          =   375
         Left            =   240
         TabIndex        =   31
         Top             =   3000
         Width           =   855
      End
      Begin VB.Label lbNgaySinhGV 
         Caption         =   "Ngaøy Sinh"
         Height          =   375
         Left            =   240
         TabIndex        =   29
         Top             =   2400
         Width           =   975
      End
      Begin VB.Label lbHoTenGV 
         Caption         =   "Hoï Teân GV"
         Height          =   375
         Left            =   240
         TabIndex        =   26
         Top             =   1200
         Width           =   975
      End
      Begin VB.Label lbMaGV 
         Caption         =   "Maõ soá GV"
         Height          =   375
         Left            =   240
         TabIndex        =   24
         Top             =   600
         Width           =   855
      End
      Begin VB.Label lbMaLop 
         Caption         =   "Maõ lôùp"
         Height          =   375
         Left            =   -74640
         TabIndex        =   22
         Top             =   600
         Width           =   975
      End
      Begin VB.Label lbSoNgayVang 
         Caption         =   "Soá ngaøy vaéng     "
         Height          =   495
         Left            =   -71640
         TabIndex        =   12
         Top             =   2520
         Width           =   735
      End
      Begin VB.Label lbDienHS 
         Caption         =   "Dieän HS"
         Height          =   375
         Left            =   -74880
         TabIndex        =   10
         Top             =   2640
         Width           =   855
      End
      Begin VB.Label lbDiaChiHS 
         Caption         =   "Ñòa chæ"
         Height          =   375
         Left            =   -74880
         TabIndex        =   8
         Top             =   1800
         Width           =   855
      End
      Begin VB.Label lbNgaySinhHS 
         Caption         =   "Ngaøy Sinh"
         Height          =   375
         Left            =   -71640
         TabIndex        =   5
         Top             =   1800
         Width           =   855
      End
      Begin VB.Label lbHoTenHS 
         Caption         =   "Hoï teân"
         Height          =   255
         Left            =   -71640
         TabIndex        =   3
         Top             =   720
         Width           =   735
      End
      Begin VB.Label lbMaHS 
         Alignment       =   2  'Center
         Caption         =   "Maõ soá HS"
         Height          =   255
         Left            =   -74880
         TabIndex        =   1
         Top             =   720
         Width           =   855
      End
   End
   Begin VB.Label lbTieuDe 
      Alignment       =   2  'Center
      Caption         =   "Chöông Trình Quaûn Lyù Hoïc Sinh Trung Hoïc"
      BeginProperty Font 
         Name            =   "VNI-Times"
         Size            =   14.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   375
      Left            =   1080
      TabIndex        =   88
      Top             =   120
      Width           =   5415
   End
   Begin VB.Menu mnuHoSo 
      Caption         =   "&Ho so"
      Begin VB.Menu mnuThoat 
         Caption         =   "&Thoat"
         Shortcut        =   ^T
      End
   End
   Begin VB.Menu mnuCongCu 
      Caption         =   "&Cong cu"
   End
   Begin VB.Menu mnuGiupdo 
      Caption         =   "&Giup do"
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Private HSFlag As Boolean
Private GVFlag As Boolean
Private MHFlag As Boolean
Private LopFlag As Boolean
Private PHGFlag As Boolean
Private OldSourceHS As String
Private OldSourceGV As String
Private OldSourceMH As String
Private OldSourceLop As String
Private OldSourcePHG As String

Private Sub ChangeStatusHS()
    HSFlag = Not (HSFlag)
    cmdTraCuuHS.Visible = Not (HSFlag)
    cmdXoaHS.Visible = Not (HSFlag)
    cmdCapNhatHS.Visible = Not (HSFlag)
    cmdThemHS.Visible = Not (HSFlag)
    cmdHSXepLop.Visible = Not (HSFlag)
    cmdThucHienHS.Visible = HSFlag
    cmdQuayVeHS.Visible = HSFlag

' Gia su chi cho phep tim kiem theo Ho ten ,Dia chi
    txtMaHS.Enabled = Not (HSFlag)
    txtNgaySinhHS.Enabled = Not (HSFlag)
    txtSoNgayVang.Enabled = Not (HSFlag)
    cmbDienHS.Enabled = Not (HSFlag)
    chkNam.Enabled = Not (HSFlag)

End Sub
Private Sub ChangeStatusGV()
    GVFlag = Not (GVFlag)
    cmdTraCuuGV.Visible = Not (GVFlag)
    cmdXoaGV.Visible = Not (GVFlag)
    cmdCapNhatGV.Visible = Not (GVFlag)
    cmdThemGV.Visible = Not (GVFlag)
    cmdDay.Visible = Not (GVFlag)
    cmdThucHienGV.Visible = GVFlag
    cmdQuayVeGV.Visible = GVFlag

' Gia su chi cho phep tim kiem theo Ho ten ,Dia chi
    txtMaGV.Enabled = Not (GVFlag)
    txtNgaySinhGV.Enabled = Not (GVFlag)
    chkNamGV.Enabled = Not (GVFlag)

End Sub
Private Sub ChangeStatusMH()
    MHFlag = Not (MHFlag)
    cmdTraCuuMH.Visible = Not (MHFlag)
    cmdXoaMH.Visible = Not (MHFlag)
    cmdCapNhatMH.Visible = Not (MHFlag)
    cmdThemMH.Visible = Not (MHFlag)
    cmdThucHienMH.Visible = MHFlag
    cmdQuayVeMH.Visible = MHFlag

' Gia su chi cho phep tim kiem theo Ma MH va ten MH
    txtHeso.Enabled = Not (LopFlag)
    txtSotiet.Enabled = Not (LopFlag)
    txtGhiChu.Enabled = Not (LopFlag)

End Sub
Private Sub ChangeStatusLop()
    LopFlag = Not (LopFlag)
    cmdTraCuuLop.Visible = Not (LopFlag)
    cmdXoaLop.Visible = Not (LopFlag)
    cmdCapNhatLop.Visible = Not (LopFlag)
    cmdThemLop.Visible = Not (LopFlag)
    cmdThucHienLop.Visible = LopFlag
    cmdQuayVeLop.Visible = LopFlag

' Gia su chi cho phep tim kiem theo Ma Lop va ten Lop
    cmbKhoiLop.Enabled = Not (LopFlag)
    cmbNienKhoa.Enabled = Not (LopFlag)
    cmbPhong.Enabled = Not (LopFlag)
    txtSiSo.Enabled = Not (LopFlag)

End Sub
Private Sub ChangeStatusPHG()
    PHGFlag = Not (PHGFlag)
    cmdTraCuuPHG.Visible = Not (PHGFlag)
    cmdXoaPHG.Visible = Not (PHGFlag)
    cmdCapNhatPHG.Visible = Not (PHGFlag)
    cmdThemPHG.Visible = Not (PHGFlag)
    cmdThucHienPHG.Visible = PHGFlag
    cmdQuayVePHG.Visible = PHGFlag

' Gia su chi cho phep tim kiem theo Ma PHG va ten PHG
    txtGhiChuPHG.Enabled = Not (LopFlag)
End Sub

Private Sub cmdCapNhatGV_Click()
    Dim cSQL As String
    Dim rs As Recordset
    Dim Db As Database
    Dim wk As Workspace
   
   'DataGiaoVien.Refresh
    If (OldSourceGV <> DataGiaoVien.RecordSource) Then
        DataGiaoVien.RecordSource = OldSourceGV
        DataGiaoVien.Refresh
    End If
    If (IsNull(txtMaGV.Text)) Or (txtMaGV.Text = "") Then
        MsgBox " Gia Tri khoa chinh khong the de trong", 16, "Loi"
        If Not (DataGiaoVien.Recordset.BOF) Then
            DataGiaoVien.Recordset.MoveFirst
        End If
        Exit Sub
    End If
    
    Set wk = DBEngine.CreateWorkspace("", "Admin", "", dbUseJet)
    Set Db = wk.OpenDatabase(DBPath)
    Set rs = Db.OpenRecordset("Day", dbOpenDynaset)
    cSQL = "MaGV =  " & txtMaGV.Text
    rs.FindFirst cSQL
    If (rs.NoMatch) Then
        MsgBox "Moi giao vien phai duoc phan cong day it" + Chr(13) + _
                        "nhat mot lop .Giao vien nay chua duoc phan cong", 4160
        cmdDay_Click
    End If
    rs.Close
    Db.Close
    wk.Close

End Sub

Private Sub cmdCapNhatHS_Click()
    Dim cSQL As String
    Dim rs As Recordset
    Dim Db As Database
    Dim wk As Workspace
    Dim t1, t2 As Date
   
   'DataHocSinh.Refresh
    If (OldSourceHS <> DataHocSinh.RecordSource) Then
        DataHocSinh.RecordSource = OldSourceHS
        DataHocSinh.Refresh
    End If
    If (IsNull(txtMaHS.Text)) Or (txtMaHS.Text = "") Then
        MsgBox " Gia Tri khoa chinh khong the de trong", 16, "Loi"
        If Not (DataHocSinh.Recordset.BOF) Then
            DataHocSinh.Recordset.MoveFirst
        End If
        Exit Sub
    End If
    
    Set wk = DBEngine.CreateWorkspace("", "Admin", "", dbUseJet)
    Set Db = wk.OpenDatabase(DBPath)
    
    Set rs = Db.OpenRecordset("GiaoVien", dbOpenDynaset)
    'Debug.Print rs.Fields("NgaySinhGV").Value
    Do While Not rs.EOF
        t1 = CDate(rs.Fields("NgaySinhGV").Value)
        t2 = CDate(DataHocSinh.Recordset.Fields("NgaySinhHS").Value)
        'If CDate(rs.Fields("NgaySinhGV").Value) >= CDate(DataHocSinh.Recordset.Fields("NgaySinhHS").Value) Then
        'If  rs.Fields("NgaySinhGV").Value  > DataHocSinh.Recordset.Fields("NgaySinhHS").Value Then
        If t1 >= t2 Then
            MsgBox "Tuoi cua giao vien khong the nho hon hoac bang tuoi " + Chr(13) + _
                            " cua hoc sinh ", 4160
            If txtMaHS.Locked = False Then txtMaHS.SetFocus
            Exit Sub
        End If
        rs.MoveNext
    Loop
    
    Set rs = Db.OpenRecordset("XepLop", dbOpenDynaset)
    cSQL = "MaHS =  " & txtMaHS.Text
    rs.FindFirst cSQL
    If (rs.NoMatch) Then
        MsgBox "Ban phai xep lop cho hoc sinh nay vi " + Chr(13) + _
                            " hoc sinh nay chua duoc xep lop ", 4160
        cmdHSXepLop_Click
    End If
    rs.Close
    Db.Close
    wk.Close
    
    End Sub

Private Sub cmdCapNhatLop_Click()
    If (OldSourceLop <> DataLop.RecordSource) Then
        DataLop.RecordSource = OldSourceLop
        DataLop.Refresh
    End If
    If (IsNull(txtMaLop.Text)) Or (txtMaLop.Text = "") Then
        MsgBox " Gia Tri khoa chinh khong the de trong", 16, "Loi"
        If Not (DataLop.Recordset.BOF) Then
            DataLop.Recordset.MoveFirst
        End If
        Exit Sub
    End If
End Sub

Private Sub cmdCapNhatMH_Click()
    If (OldSourceMH <> DataMonHoc.RecordSource) Then
        DataMonHoc.RecordSource = OldSourceMH
        DataMonHoc.Refresh
    End If
    If (IsNull(txtMaMH.Text)) Or (txtMaMH.Text = "") Then
        MsgBox " Gia Tri khoa chinh khong the de trong", 16, "Loi"
        If Not (DataMonHoc.Recordset.BOF) Then
            DataMonHoc.Recordset.MoveFirst
        End If
        Exit Sub
    End If

End Sub

Private Sub cmdCapNhatPHG_Click()
    If (OldSourcePHG <> DataPHG.RecordSource) Then
        DataPHG.RecordSource = OldSourcePHG
        DataPHG.Refresh
    End If
    If (IsNull(txtMaPHG.Text)) Or (txtMaPHG.Text = "") Then
        MsgBox " Gia Tri khoa chinh khong the de trong", 16, "Loi"
        If Not (DataPHG.Recordset.BOF) Then
            DataPHG.Recordset.MoveFirst
        End If
        Exit Sub
    End If
End Sub

Private Sub cmdChuNhiem_Click()
    Load frmChuNhiem
    frmChuNhiem.Show
End Sub

Private Sub cmdDay_Click()
    Load frmDay
    frmDay.Show
End Sub

Private Sub cmdDiem_Click()
    Load frmPhieuDiem
    frmPhieuDiem.Show
End Sub

Private Sub cmdGhiTKB_Click()
    DataTKB.Refresh
End Sub

Private Sub cmdHSXepLop_Click()
    Load frmXepLop
    frmXepLop.Show
End Sub

Private Sub cmdQuayVeGV_Click()
    ChangeStatusHS
    DataHocSinh.Refresh
End Sub

Private Sub cmdQuayVeHS_Click()
    ChangeStatusHS
    DataHocSinh.Refresh
End Sub

Private Sub cmdQuayVeLop_Click()
    ChangeStatusLop
    DataLop.Refresh
End Sub

Private Sub cmdQuayVeMH_Click()
    ChangeStatusMH
    DataMonHoc.Refresh
End Sub

Private Sub cmdQuayVePHG_Click()
    ChangeStatusPHG
    DataPHG.Refresh
End Sub

Private Sub cmdThemGV_Click()
    DataGiaoVien.Recordset.AddNew
    txtMaGV.SetFocus
End Sub

Private Sub cmdThemHS_Click()
    DataHocSinh.Recordset.AddNew
    txtMaHS.SetFocus
End Sub

Private Sub cmdThemLop_Click()
    DataLop.Recordset.AddNew
    txtMaLop.SetFocus
End Sub

Private Sub cmdThemMH_Click()
    DataMonHoc.Recordset.AddNew
    txtMaMH.SetFocus
End Sub

Private Sub cmdThemPHG_Click()
    DataPHG.Recordset.AddNew
    txtMaPHG.SetFocus
End Sub

Private Sub cmdThemTKB_Click()
    DataTKB.Recordset.AddNew
End Sub

Private Sub cmdThucHienGV_Click()
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
    
    If txtDiaChiGV <> "" And txtDiaChiGV <> "*" Then
        SQL = SQL _
        & IIf(FirstPredicate, " Where DiaChiGV LIKE '*", " AND DiaChiGV LIKE '*") _
        & txtDiaChiGV.Text & "*'"
        FirstPredicate = False
    End If
    
    ' Thuc hien lai cau truy van lien ket voi Data control
    DataGiaoVien.RecordSource = SQL
    DataGiaoVien.Refresh
    If Not (DataGiaoVien.Recordset.BOF) Then
        DataGiaoVien.Recordset.MoveLast
        DataGiaoVien.Recordset.MoveFirst
        SL = DataGiaoVien.Recordset.RecordCount
        ChangeStatusHS
        MsgBox ("Tim duoc " & Str(SL) & _
        " giao vien thoa dieu kien ")
    Else
        MsgBox ("Khong tim duoc giao vien nao thoa dieu kien")
        cmdTraCuuGV_Click
End If

End Sub

Private Sub cmdThucHienHS_Click()
    Dim SQL As String
    Dim FirstPredicate As Boolean
    Dim SL As Long
    
    FirstPredicate = True
    
    'OldSourceHS = DataHocSinh.RecordSource
    SQL = "Select * from HOCSINH"
    If txtHoTenHS <> "" And txtHoTenHS <> "*" Then
        SQL = SQL & " Where HoTenHS  LIKE '*" & txtHoTenHS.Text & "*'"
        FirstPredicate = False
    End If
    
    If txtDiaChiHS <> "" And txtDiaChiHS <> "*" Then
        SQL = SQL _
        & IIf(FirstPredicate, " Where DiaChiHS LIKE '*", " AND DiaChiHS LIKE '*") _
        & txtDiaChiHS.Text & "*'"
        FirstPredicate = False
    End If
    
    ' Thuc hien lai cau truy van lien ket voi Data control
    DataHocSinh.RecordSource = SQL
    DataHocSinh.Refresh
    If Not (DataHocSinh.Recordset.BOF) Then
        DataHocSinh.Recordset.MoveLast
        DataHocSinh.Recordset.MoveFirst
        SL = DataHocSinh.Recordset.RecordCount
        ChangeStatusHS
        MsgBox ("Tim duoc " & Str(SL) & _
        " hoc sinh thoa dieu kien ")
    Else
        MsgBox ("Khong tim duoc hoc sinh nao thoa dieu kien")
        cmdTraCuuHS_Click
End If

End Sub

Private Sub cmdThucHienLop_Click()
    Dim SQL As String
    Dim FirstPredicate As Boolean
    Dim SL As Long
    
    FirstPredicate = True
    
    SQL = "Select * from LOP"
    If txtMaLop <> "" And txtMaLop <> "*" Then
        SQL = SQL & " Where MaLop  LIKE '*" & txtMaLop.Text & "*'"
        FirstPredicate = False
    End If
    
    If txtTenLop <> "" And txtTenLop <> "*" Then
        SQL = SQL _
        & IIf(FirstPredicate, " Where TenLop  LIKE '*", " AND TenLop  LIKE '*") _
        & txtTenLop.Text & "*'"
        FirstPredicate = False
    End If
    
    ' Thuc hien lai cau truy van lien ket voi Data control
    DataLop.RecordSource = SQL
    DataLop.Refresh
    If Not (DataLop.Recordset.BOF) Then
        DataLop.Recordset.MoveLast
        DataLop.Recordset.MoveFirst
        SL = DataLop.Recordset.RecordCount
        ChangeStatusLop
        MsgBox ("Tim duoc " & Str(SL) & _
        " lop  thoa dieu kien ")
    Else
        MsgBox ("Khong tim duoc lop hoc  nao thoa dieu kien")
        cmdTraCuuLop_Click
End If

End Sub

Private Sub cmdThucHienMH_Click()
    Dim SQL As String
    Dim FirstPredicate As Boolean
    Dim SL As Long
    
    FirstPredicate = True
    
    SQL = "Select * from MONHOC"
    If txtMaMH <> "" And txtMaMH <> "*" Then
        SQL = SQL & " Where MaMH  LIKE '*" & txtMaMH.Text & "*'"
        FirstPredicate = False
    End If
    
    If txtTenMH <> "" And txtTenMH <> "*" Then
        SQL = SQL _
        & IIf(FirstPredicate, " Where TenMH  LIKE '*", " AND TenMH  LIKE '*") _
        & txtTenMH.Text & "*'"
        FirstPredicate = False
    End If
    
    ' Thuc hien lai cau truy van lien ket voi Data control
    DataMonHoc.RecordSource = SQL
    DataMonHoc.Refresh
    If Not (DataMonHoc.Recordset.BOF) Then
        DataMonHoc.Recordset.MoveLast
        DataMonHoc.Recordset.MoveFirst
        SL = DataMonHoc.Recordset.RecordCount
        ChangeStatusMH
        MsgBox ("Tim duoc " & Str(SL) & _
        " mon hoc  thoa dieu kien ")
    Else
        MsgBox ("Khong tim duoc mon hoc  nao thoa dieu kien")
        cmdTraCuuMH_Click
End If

End Sub

Private Sub cmdThucHienPHG_Click()
    Dim SQL As String
    Dim FirstPredicate As Boolean
    Dim SL As Long
    
    FirstPredicate = True
    
    SQL = "Select * from PHONG"
    If txtMaPHG <> "" And txtMaPHG <> "*" Then
        SQL = SQL & " Where MaPHG  LIKE '*" & txtMaPHG.Text & "*'"
        FirstPredicate = False
    End If
    
    If txtTenPHG <> "" And txtTenPHG <> "*" Then
        SQL = SQL _
        & IIf(FirstPredicate, " Where TenPHG  LIKE '*", " AND TenPHG  LIKE '*") _
        & txtTenPHG.Text & "*'"
        FirstPredicate = False
    End If
    
    ' Thuc hien lai cau truy van lien ket voi Data control
    DataPHG.RecordSource = SQL
    DataPHG.Refresh
    If Not (DataPHG.Recordset.BOF) Then
        DataPHG.Recordset.MoveLast
        DataPHG.Recordset.MoveFirst
        SL = DataPHG.Recordset.RecordCount
        ChangeStatusPHG
        MsgBox ("Tim duoc " & Str(SL) & _
        " phong nao thoa dieu kien ")
    Else
        MsgBox ("Khong tim duoc phong hoc  nao thoa dieu kien")
        cmdTraCuuPHG_Click
End If
End Sub

Private Sub cmdTraCuuGV_Click()
    txtMaGV.Text = ""
    txtNgaySinhGV.Text = ""
    chkNamGV.Value = 0
    ChangeStatusGV
    
    txtHoTenGV.Text = "*"
    txtDiaChiGV.Text = "*"
    txtHoTenGV.SetFocus

End Sub

Private Sub cmdTraCuuHS_Click()
    txtMaHS.Text = ""
    txtNgaySinhHS.Text = ""
    txtSoNgayVang.Text = ""
    cmbDienHS.Text = ""
    chkNam.Value = 0
    ChangeStatusHS
    
    txtHoTenHS.Text = "*"
    txtDiaChiHS.Text = "*"
    txtHoTenHS.SetFocus
End Sub

Private Sub cmdTraCuuLop_Click()
   cmbKhoiLop.Text = ""
    cmbNienKhoa.Text = ""
    cmbPhong.Text = ""
    txtSiSo.Text = ""
    ChangeStatusLop
    
    txtMaLop.Text = "*"
    txtTenLop.Text = "*"
    txtMaLop.SetFocus

End Sub

Private Sub cmdTraCuuMH_Click()
   txtSotiet.Text = ""
    txtHeso.Text = ""
    txtGhiChu.Text = ""
    ChangeStatusMH
    
    txtMaMH.Text = "*"
    txtTenMH.Text = "*"
    txtMaMH.SetFocus
End Sub

Private Sub cmdTraCuuPHG_Click()
    txtGhiChuPHG.Text = ""
    ChangeStatusPHG
    
    txtMaPHG.Text = "*"
    txtTenPHG.Text = "*"
    txtMaPHG.SetFocus
End Sub

Private Sub cmdXoaGV_Click()
    Dim i As Integer
    i = MsgBox("Ban co chac chan xoa khong ? ", 289, "Kiem tra")
    If i = 2 Then Exit Sub
    With DataGiaoVien.Recordset
        .Delete
         If (.RecordCount > 0) Then
            .MoveNext
            If .EOF Then .MoveLast
        End If
    End With

End Sub

Private Sub cmdXoaHS_Click()
    Dim i As Integer
    i = MsgBox("Ban co chac chan xoa khong ? ", 289, "Kiem tra")
    If i = 2 Then Exit Sub
    With DataHocSinh.Recordset
        .Delete
         If (.RecordCount > 0) Then
            .MoveNext
            If .EOF Then .MoveLast
        End If
    End With
End Sub

Private Sub cmdXoaLop_Click()
    Dim i As Integer
    i = MsgBox("Ban co chac chan xoa khong ? ", 289, "Kiem tra")
    If i = 2 Then Exit Sub
    With DataLop.Recordset
        .Delete
         If (.RecordCount > 0) Then
            .MoveNext
            If .EOF Then .MoveLast
        End If
    End With

End Sub

Private Sub cmdXoaMH_Click()
    Dim i As Integer
    i = MsgBox("Ban co chac chan xoa khong ? ", 289, "Kiem tra")
    If i = 2 Then Exit Sub
    With DataMonHoc.Recordset
        .Delete
         If (.RecordCount > 0) Then
            .MoveNext
            If .EOF Then .MoveLast
        End If
    End With
End Sub

Private Sub cmdXoaPHG_Click()
    Dim i As Integer
    i = MsgBox("Ban co chac chan xoa khong ? ", 289, "Kiem tra")
    If i = 2 Then Exit Sub
    With DataPHG.Recordset
        .Delete
         If (.RecordCount > 0) Then
            .MoveNext
            If .EOF Then .MoveLast
        End If
    End With
End Sub

Private Sub cmdXoaTKB_Click()
    Dim i As Integer
    i = MsgBox("Ban co chac chan xoa khong ? ", 289, "Kiem tra")
    If i = 2 Then Exit Sub
    With DataTKB.Recordset
        .Delete
         If (.RecordCount > 0) Then
            .MoveNext
            If .EOF Then .MoveLast
        End If
    End With

End Sub

Private Sub DataGiaoVien_Error(DataErr As Integer, Response As Integer)
     MsgBox "Data error event hit err:" & Error$(DataErr)
     Response = 0  'Throw away the error
End Sub

Private Sub DataGiaoVien_Reposition()
     Screen.MousePointer = vbDefault
    On Error Resume Next
  ' This will display the current record position for dynasets and snapshots
    DataGiaoVien.Caption = "Record: " & (DataGiaoVien.Recordset.AbsolutePosition + 1)
    
    If (txtMaGV = "") Then Exit Sub
    Dim cSQL As String
    Dim rs As Recordset
    Dim Db As Database
    Dim wk As Workspace

    Set wk = DBEngine.CreateWorkspace("", "Admin", "", dbUseJet)
    Set Db = wk.OpenDatabase(DBPath)
    Set rs = Db.OpenRecordset("Day", dbOpenDynaset)
    cSQL = "MaGV =  " & txtMaGV.Text
    rs.FindFirst cSQL
    If (rs.NoMatch) Then
        MsgBox "Moi giao vien phai duoc phan cong day it" + Chr(13) + _
                        "nhat mot lop .Giao vien nay chua duoc phan cong", 4160
        cmdDay_Click
    End If
    rs.Close
    Db.Close
    wk.Close
    
End Sub

Private Sub DataGiaoVien_Validate(Action As Integer, Save As Integer)
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

Private Sub DataHocSinh_Error(DataErr As Integer, Response As Integer)
    'This is where you would put error handling code
  ' If you want to ignore errors, comment out the next line
    'If you want to trap them, add code here to handle them
     MsgBox "Data error event hit err:" & Error$(DataErr)
     Response = 0  'Throw away the error
End Sub

Private Sub DataHocSinh_Reposition()
     Screen.MousePointer = vbDefault
    On Error Resume Next
  ' This will display the current record position for dynasets and snapshots
    DataHocSinh.Caption = "Record: " & (DataHocSinh.Recordset.AbsolutePosition + 1)
    If (txtMaHS = "") Then Exit Sub
    Dim cSQL As String
    Dim rs As Recordset
    Dim Db As Database
    Dim wk As Workspace

    Set wk = DBEngine.CreateWorkspace("", "Admin", "", dbUseJet)
    Set Db = wk.OpenDatabase(DBPath)
    Set rs = Db.OpenRecordset("XepLop", dbOpenDynaset)
    cSQL = "MaHS =  " & txtMaHS.Text
    rs.FindFirst cSQL
    If (rs.NoMatch) Then
        MsgBox "Ban phai xep lop cho hoc sinh nay vi " + Chr(13) + _
                            " hoc sinh nay chua duoc xep lop ", 4160
        cmdHSXepLop_Click
    End If
    rs.Close
    Db.Close
    wk.Close
    
End Sub

Private Sub DataHocSinh_Validate(Action As Integer, Save As Integer)
'This is where you put validation code
  'This event gets called when the following actions occur
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

Private Sub DataLop_Error(DataErr As Integer, Response As Integer)
     MsgBox "Data error event hit err:" & Error$(DataErr)
     Response = 0  'Throw away the error
End Sub

Private Sub DataLop_Reposition()
     Screen.MousePointer = vbDefault
    On Error Resume Next
  ' This will display the current record position for dynasets and snapshots
    DataLop.Caption = "Record: " & (DataLop.Recordset.AbsolutePosition + 1)
    If (txtMaLop = "") Then Exit Sub

End Sub

Private Sub DataLop_Validate(Action As Integer, Save As Integer)
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

Private Sub DataMonHoc_Error(DataErr As Integer, Response As Integer)
     MsgBox "Data error event hit err:" & Error$(DataErr)
     Response = 0  'Throw away the error
End Sub

Private Sub DataMonHoc_Reposition()
     Screen.MousePointer = vbDefault
    On Error Resume Next
  ' This will display the current record position for dynasets and snapshots
    DataMonHoc.Caption = "Record: " & (DataMonHoc.Recordset.AbsolutePosition + 1)
    If (txtMaMH = "") Then Exit Sub
End Sub

Private Sub DataMonHoc_Validate(Action As Integer, Save As Integer)
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

Private Sub DataPHG_Error(DataErr As Integer, Response As Integer)
     MsgBox "Data error event hit err:" & Error$(DataErr)
     Response = 0  'Throw away the error
End Sub

Private Sub DataPHG_Reposition()
     Screen.MousePointer = vbDefault
    On Error Resume Next
  ' This will display the current record position for dynasets and snapshots
    DataPHG.Caption = "Record: " & (DataPHG.Recordset.AbsolutePosition + 1)
    If (txtMaPHG = "") Then Exit Sub
End Sub

Private Sub DataPHG_Validate(Action As Integer, Save As Integer)
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

Private Sub DataTKB_Error(DataErr As Integer, Response As Integer)
     MsgBox "Data error event hit err:" & Error$(DataErr)
     Response = 0  'Throw away the error

End Sub

Private Sub DataTKB_Reposition()
     Screen.MousePointer = vbDefault
    On Error Resume Next
  ' This will display the current record position for dynasets and snapshots
    DataTKB.Caption = "Record: " & (DataTKB.Recordset.AbsolutePosition + 1)
End Sub

Private Sub DataTKB_Validate(Action As Integer, Save As Integer)
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

Private Sub Form_Load()
    Dim cSQL As String
    Dim wk As Workspace
    Dim Db As Database
    Dim rs As Recordset
    
    HSFlag = False
    GVFlag = False
    MHFlag = False
    LopFlag = False
    PHGFlag = False
    DataHocSinh.DatabaseName = DBPath
    DataDiem.DatabaseName = DBPath
    DataMonHoc.DatabaseName = DBPath
    DataGiaoVien.DatabaseName = DBPath
    DataLop.DatabaseName = DBPath
    DataPHG.DatabaseName = DBPath
    DataTKB.DatabaseName = DBPath
    
    OldSourceHS = DataHocSinh.RecordSource
    OldSourceGV = DataGiaoVien.RecordSource
    OldSourceMH = DataMonHoc.RecordSource
    OldSourceLop = DataLop.RecordSource
    OldSourcePHG = DataPHG.RecordSource
    
    cSQL = "SELECT  MaNienKhoa from NienKhoa"
    Set wk = DBEngine.CreateWorkspace("", "Admin", "", dbUseJet)
    Set Db = wk.OpenDatabase(DBPath)
    Set rs = Db.OpenRecordset(cSQL)
    With rs
        While Not (.EOF)
            cmbNienKhoa.AddItem rs.Fields(0), 0
            .MoveNext
        Wend
    End With
    
    cSQL = "SELECT  MaPHG  from Phong"
    Set rs = Db.OpenRecordset(cSQL)
    With rs
        While Not (.EOF)
            cmbPhong.AddItem rs.Fields(0), 0
            .MoveNext
        Wend
    End With
    
    cSQL = "SELECT  MaKhoi  from  KhoiLop"
    Set rs = Db.OpenRecordset(cSQL)
    With rs
        While Not (.EOF)
            cmbKhoiLop.AddItem rs.Fields(0), 0
            .MoveNext
        Wend
    End With
    
    rs.Close
    Db.Close
    wk.Close
End Sub

Private Sub Form_Unload(Cancel As Integer)
 Screen.MousePointer = vbDefault
End Sub

Private Sub mnuThoat_Click()
    Unload Me
End Sub

