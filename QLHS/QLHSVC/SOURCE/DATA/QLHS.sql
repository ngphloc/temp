ALTER TABLE [dbo].[CHUNHIEM] DROP CONSTRAINT FK_CHUNHIEM_GIAOVIEN
GO

ALTER TABLE [dbo].[DAY] DROP CONSTRAINT FK_DAY_GIAOVIEN
GO

ALTER TABLE [dbo].[DIEM] DROP CONSTRAINT FK_DIEM_HINHTHUCKT
GO

ALTER TABLE [dbo].[DIEM] DROP CONSTRAINT FK_DIEM_HOCKY
GO

ALTER TABLE [dbo].[DIEM] DROP CONSTRAINT FK_DIEM_HOCSINH
GO

ALTER TABLE [dbo].[HOC] DROP CONSTRAINT FK_HOC_HOCSINH
GO

ALTER TABLE [dbo].[LOP] DROP CONSTRAINT FK_LOP_KHOILOP
GO

ALTER TABLE [dbo].[DAY] DROP CONSTRAINT FK_DAY_MONHOC
GO

ALTER TABLE [dbo].[DIEM] DROP CONSTRAINT FK_DIEM_MONHOC
GO

ALTER TABLE [dbo].[DIEM] DROP CONSTRAINT FK_DIEM_NIENKHOA
GO

ALTER TABLE [dbo].[LOP] DROP CONSTRAINT FK_LOP_NIENKHOA
GO

ALTER TABLE [dbo].[LOP] DROP CONSTRAINT FK_LOP_PHONG
GO

ALTER TABLE [dbo].[CHUNHIEM] DROP CONSTRAINT FK_CHUNHIEM_LOP
GO

ALTER TABLE [dbo].[DAY] DROP CONSTRAINT FK_DAY_LOP
GO

ALTER TABLE [dbo].[HOC] DROP CONSTRAINT FK_HOC_LOP
GO

/****** Object:  Table [dbo].[CHUNHIEM]    Script Date: 10/26/00 6:58:38 PM ******/
if exists (select * from sysobjects where id = object_id(N'[dbo].[CHUNHIEM]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[CHUNHIEM]
GO

/****** Object:  Table [dbo].[DAY]    Script Date: 10/26/00 6:58:38 PM ******/
if exists (select * from sysobjects where id = object_id(N'[dbo].[DAY]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[DAY]
GO

/****** Object:  Table [dbo].[HOC]    Script Date: 10/26/00 6:58:38 PM ******/
if exists (select * from sysobjects where id = object_id(N'[dbo].[HOC]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[HOC]
GO

/****** Object:  Table [dbo].[DIEM]    Script Date: 10/26/00 6:58:38 PM ******/
if exists (select * from sysobjects where id = object_id(N'[dbo].[DIEM]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[DIEM]
GO

/****** Object:  Table [dbo].[LOP]    Script Date: 10/26/00 6:58:38 PM ******/
if exists (select * from sysobjects where id = object_id(N'[dbo].[LOP]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[LOP]
GO

/****** Object:  Table [dbo].[GIAOVIEN]    Script Date: 10/26/00 6:58:38 PM ******/
if exists (select * from sysobjects where id = object_id(N'[dbo].[GIAOVIEN]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[GIAOVIEN]
GO

/****** Object:  Table [dbo].[HINHTHUCKT]    Script Date: 10/26/00 6:58:38 PM ******/
if exists (select * from sysobjects where id = object_id(N'[dbo].[HINHTHUCKT]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[HINHTHUCKT]
GO

/****** Object:  Table [dbo].[HOCKY]    Script Date: 10/26/00 6:58:38 PM ******/
if exists (select * from sysobjects where id = object_id(N'[dbo].[HOCKY]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[HOCKY]
GO

/****** Object:  Table [dbo].[HOCSINH]    Script Date: 10/26/00 6:58:38 PM ******/
if exists (select * from sysobjects where id = object_id(N'[dbo].[HOCSINH]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[HOCSINH]
GO

/****** Object:  Table [dbo].[KHOILOP]    Script Date: 10/26/00 6:58:38 PM ******/
if exists (select * from sysobjects where id = object_id(N'[dbo].[KHOILOP]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[KHOILOP]
GO

/****** Object:  Table [dbo].[MONHOC]    Script Date: 10/26/00 6:58:38 PM ******/
if exists (select * from sysobjects where id = object_id(N'[dbo].[MONHOC]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[MONHOC]
GO

/****** Object:  Table [dbo].[NIENKHOA]    Script Date: 10/26/00 6:58:38 PM ******/
if exists (select * from sysobjects where id = object_id(N'[dbo].[NIENKHOA]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[NIENKHOA]
GO

/****** Object:  Table [dbo].[PHONG]    Script Date: 10/26/00 6:58:38 PM ******/
if exists (select * from sysobjects where id = object_id(N'[dbo].[PHONG]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[PHONG]
GO

/****** Object:  Table [dbo].[GIAOVIEN]    Script Date: 10/26/00 6:58:50 PM ******/
CREATE TABLE [dbo].[GIAOVIEN] (
	[MaGV] [varchar] (50) NOT NULL ,
	[HoTenGV] [varchar] (50) NOT NULL ,
	[NgaySinhGV] [datetime] NULL ,
	[Nam] [bit] NULL ,
	[DiaChiGV] [varchar] (255) NULL ,
	[GhiChu] [varchar] (255) NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[HINHTHUCKT]    Script Date: 10/26/00 6:58:52 PM ******/
CREATE TABLE [dbo].[HINHTHUCKT] (
	[MaHinhThucKT] [int] NOT NULL ,
	[TenHinhThucKT] [varchar] (50) NOT NULL ,
	[HeSo] [int] NOT NULL ,
	[GhiChu] [varchar] (255) NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[HOCKY]    Script Date: 10/26/00 6:58:53 PM ******/
CREATE TABLE [dbo].[HOCKY] (
	[MaHK] [int] NOT NULL ,
	[TenHK] [varchar] (50) NULL ,
	[GhiChu] [varchar] (255) NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[HOCSINH]    Script Date: 10/26/00 6:58:53 PM ******/
CREATE TABLE [dbo].[HOCSINH] (
	[MaHS] [varchar] (50) NOT NULL ,
	[HoTenHS] [varchar] (50) NOT NULL ,
	[Nam] [bit] NULL ,
	[NgaySinhHS] [datetime] NULL ,
	[DiaChiHS] [varchar] (255) NULL ,
	[HinhAnhHS] [image] NULL ,
	[DienHS] [int] NULL ,
	[SoNgayVang] [int] NULL 
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO

/****** Object:  Table [dbo].[KHOILOP]    Script Date: 10/26/00 6:58:54 PM ******/
CREATE TABLE [dbo].[KHOILOP] (
	[MaKL] [int] NOT NULL ,
	[TenKL] [varchar] (50) NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[MONHOC]    Script Date: 10/26/00 6:58:55 PM ******/
CREATE TABLE [dbo].[MONHOC] (
	[MaMH] [varchar] (50) NOT NULL ,
	[TenMH] [varchar] (50) NOT NULL ,
	[HeSo] [tinyint] NOT NULL ,
	[SoTiet] [tinyint] NULL ,
	[GhiChu] [varchar] (255) NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[NIENKHOA]    Script Date: 10/26/00 6:58:55 PM ******/
CREATE TABLE [dbo].[NIENKHOA] (
	[MaNK] [int] NOT NULL ,
	[TenNK] [varchar] (50) NULL ,
	[GhiChu] [varchar] (255) NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[PHONG]    Script Date: 10/26/00 6:58:56 PM ******/
CREATE TABLE [dbo].[PHONG] (
	[MaPHG] [varchar] (50) NOT NULL ,
	[TenPHG] [varchar] (50) NULL ,
	[GhiChu] [varchar] (255) NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[DIEM]    Script Date: 10/26/00 6:58:56 PM ******/
CREATE TABLE [dbo].[DIEM] (
	[HocSinh] [varchar] (50) NOT NULL ,
	[NienKhoa] [int] NOT NULL ,
	[HocKy] [int] NOT NULL ,
	[MonHoc] [varchar] (50) NOT NULL ,
	[HinhThucKT] [int] NOT NULL ,
	[Diem] [real] NOT NULL ,
	[LanThu] [int] NOT NULL ,
	[GhiChu] [varchar] (255) NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[LOP]    Script Date: 10/26/00 6:58:57 PM ******/
CREATE TABLE [dbo].[LOP] (
	[MaLop] [varchar] (50) NOT NULL ,
	[TenLop] [varchar] (50) NULL ,
	[KhoiLop] [int] NULL ,
	[NienKhoa] [int] NULL ,
	[Phong] [varchar] (50) NULL ,
	[SiSo] [int] NULL ,
	[GhiChu] [varchar] (255) NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[CHUNHIEM]    Script Date: 10/26/00 6:58:58 PM ******/
CREATE TABLE [dbo].[CHUNHIEM] (
	[GiaoVien] [varchar] (50) NOT NULL ,
	[Lop] [varchar] (50) NOT NULL ,
	[GhiChu] [varchar] (255) NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[DAY]    Script Date: 10/26/00 6:58:58 PM ******/
CREATE TABLE [dbo].[DAY] (
	[GiaoVien] [varchar] (50) NOT NULL ,
	[Lop] [varchar] (50) NOT NULL ,
	[MonHoc] [varchar] (50) NOT NULL ,
	[GhiChu] [varchar] (255) NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[HOC]    Script Date: 10/26/00 6:58:59 PM ******/
CREATE TABLE [dbo].[HOC] (
	[HocSinh] [varchar] (50) NOT NULL ,
	[Lop] [varchar] (50) NOT NULL ,
	[GhiChu] [varchar] (255) NULL 
) ON [PRIMARY]
GO

ALTER TABLE [dbo].[GIAOVIEN] WITH NOCHECK ADD 
	CONSTRAINT [PK_GIAOVIEN] PRIMARY KEY  NONCLUSTERED 
	(
		[MaGV]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[HINHTHUCKT] WITH NOCHECK ADD 
	CONSTRAINT [PK_HINHTHUCKT] PRIMARY KEY  NONCLUSTERED 
	(
		[MaHinhThucKT]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[HOCKY] WITH NOCHECK ADD 
	CONSTRAINT [PK_HOCKY] PRIMARY KEY  NONCLUSTERED 
	(
		[MaHK]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[HOCSINH] WITH NOCHECK ADD 
	CONSTRAINT [PK_HOCSINH] PRIMARY KEY  NONCLUSTERED 
	(
		[MaHS]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[KHOILOP] WITH NOCHECK ADD 
	CONSTRAINT [PK_KHOILOP] PRIMARY KEY  NONCLUSTERED 
	(
		[MaKL]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[MONHOC] WITH NOCHECK ADD 
	CONSTRAINT [PK_MONHOC] PRIMARY KEY  NONCLUSTERED 
	(
		[MaMH]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[NIENKHOA] WITH NOCHECK ADD 
	CONSTRAINT [PK_NIENKHOA] PRIMARY KEY  NONCLUSTERED 
	(
		[MaNK]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[PHONG] WITH NOCHECK ADD 
	CONSTRAINT [PK_PHONG] PRIMARY KEY  NONCLUSTERED 
	(
		[MaPHG]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[DIEM] WITH NOCHECK ADD 
	CONSTRAINT [PK_DIEM] PRIMARY KEY  NONCLUSTERED 
	(
		[HocSinh],
		[NienKhoa],
		[HocKy],
		[MonHoc],
		[HinhThucKT],
		[Diem],
		[LanThu]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[LOP] WITH NOCHECK ADD 
	CONSTRAINT [PK_LOP] PRIMARY KEY  NONCLUSTERED 
	(
		[MaLop]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[CHUNHIEM] WITH NOCHECK ADD 
	CONSTRAINT [PK_CHUNHIEM] PRIMARY KEY  NONCLUSTERED 
	(
		[GiaoVien],
		[Lop]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[DAY] WITH NOCHECK ADD 
	CONSTRAINT [PK_DAY] PRIMARY KEY  NONCLUSTERED 
	(
		[GiaoVien],
		[Lop],
		[MonHoc]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[HOC] WITH NOCHECK ADD 
	CONSTRAINT [PK_HOC] PRIMARY KEY  NONCLUSTERED 
	(
		[HocSinh],
		[Lop]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[DIEM] ADD 
	CONSTRAINT [FK_DIEM_HINHTHUCKT] FOREIGN KEY 
	(
		[HinhThucKT]
	) REFERENCES [dbo].[HINHTHUCKT] (
		[MaHinhThucKT]
	),
	CONSTRAINT [FK_DIEM_HOCKY] FOREIGN KEY 
	(
		[HocKy]
	) REFERENCES [dbo].[HOCKY] (
		[MaHK]
	),
	CONSTRAINT [FK_DIEM_HOCSINH] FOREIGN KEY 
	(
		[HocSinh]
	) REFERENCES [dbo].[HOCSINH] (
		[MaHS]
	),
	CONSTRAINT [FK_DIEM_MONHOC] FOREIGN KEY 
	(
		[MonHoc]
	) REFERENCES [dbo].[MONHOC] (
		[MaMH]
	),
	CONSTRAINT [FK_DIEM_NIENKHOA] FOREIGN KEY 
	(
		[NienKhoa]
	) REFERENCES [dbo].[NIENKHOA] (
		[MaNK]
	)
GO

ALTER TABLE [dbo].[LOP] ADD 
	CONSTRAINT [FK_LOP_KHOILOP] FOREIGN KEY 
	(
		[KhoiLop]
	) REFERENCES [dbo].[KHOILOP] (
		[MaKL]
	),
	CONSTRAINT [FK_LOP_NIENKHOA] FOREIGN KEY 
	(
		[NienKhoa]
	) REFERENCES [dbo].[NIENKHOA] (
		[MaNK]
	),
	CONSTRAINT [FK_LOP_PHONG] FOREIGN KEY 
	(
		[Phong]
	) REFERENCES [dbo].[PHONG] (
		[MaPHG]
	)
GO

ALTER TABLE [dbo].[CHUNHIEM] ADD 
	CONSTRAINT [FK_CHUNHIEM_GIAOVIEN] FOREIGN KEY 
	(
		[GiaoVien]
	) REFERENCES [dbo].[GIAOVIEN] (
		[MaGV]
	),
	CONSTRAINT [FK_CHUNHIEM_LOP] FOREIGN KEY 
	(
		[Lop]
	) REFERENCES [dbo].[LOP] (
		[MaLop]
	)
GO

ALTER TABLE [dbo].[DAY] ADD 
	CONSTRAINT [FK_DAY_GIAOVIEN] FOREIGN KEY 
	(
		[GiaoVien]
	) REFERENCES [dbo].[GIAOVIEN] (
		[MaGV]
	),
	CONSTRAINT [FK_DAY_LOP] FOREIGN KEY 
	(
		[Lop]
	) REFERENCES [dbo].[LOP] (
		[MaLop]
	),
	CONSTRAINT [FK_DAY_MONHOC] FOREIGN KEY 
	(
		[MonHoc]
	) REFERENCES [dbo].[MONHOC] (
		[MaMH]
	)
GO

ALTER TABLE [dbo].[HOC] ADD 
	CONSTRAINT [FK_HOC_HOCSINH] FOREIGN KEY 
	(
		[HocSinh]
	) REFERENCES [dbo].[HOCSINH] (
		[MaHS]
	),
	CONSTRAINT [FK_HOC_LOP] FOREIGN KEY 
	(
		[Lop]
	) REFERENCES [dbo].[LOP] (
		[MaLop]
	)
GO

