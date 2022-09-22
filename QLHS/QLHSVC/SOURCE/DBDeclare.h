#ifndef    _DBDECLARE_H_
#define    _DBDECLARE_H_

#include "GiaoVien.H"
#include "HinhThucKT.H"
#include "HocKy.H"
#include "HocSinh.H"
#include "KhoiLop.H"
#include "Lop.H"
#include "MonHoc.H"
#include "NienKhoa.H"
#include "Phong.H"
#include "oledberr.h"

#define		ACCESS_GIAOVIEN			1
#define		ACCESS_HINHTHUCKT		2
#define		ACCESS_HOCKY			4
#define		ACCESS_HOCSINH			8
#define		ACCESS_KHOILOP			16
#define		ACCESS_LOP				32
#define		ACCESS_MONHOC			64
#define		ACCESS_NIENKHOA			128
#define		ACCESS_PHONG			512
#define		ACCESS_HOC				1024
#define		ACCESS_DIEM				2048
#define		ACCESS_DAY				4196
#define		ACCESS_CHUNHIEM			8392
#define		ACCESS_ERROR			0xFFFFFFFF

#define		IDX_HOCSINH		0
#define		IDX_LOP			1
#define		IDX_MONHOC		2
#define		IDX_GIAOVIEN	3
#define		IDX_ERROR		0xFF

#define		DBOPEN			0
#define		DBEMPTY			1
#define		DBCLOSED		2
#define		DBERROR			0xFF

#endif
