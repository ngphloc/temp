#ifndef _DISK_HPP
#define _DISK_HPP
#include "Public.hpp"
   /*BIOSread()
	Ham doc dia cua BIOS
Vao :   drive :so hieu o dia
	face :so hieu mat
	track :so hieu ranh
	sector :so hieu cua sector dau tien se doc
	number : so luong sector se doc
Ra :    Ma loi dia (neu co)
	Vung dem chua du lieu doc tu dia */

	typedef struct format
	{
		byte track, // Ranh can tao khuon (Dinh dang)
		face, //Mat dia can dinh dang
		sector, //So secto cua ranh
		size; //Kich thuoc (so byte) cua secto
	} format;

byte BIOSread(byte drive, byte face, byte track,
				byte sector, byte number, char*buffer);

/*	BIOSwrite()
	Ham ghi dia cua BIOS
Vao :   drive : so hieu o dia
	face : so hieu mat
	track : so hieu ranh
	sector : so hieu cua sector dau tien se doc
	number : so luong sector se ghi
		vung dem chua thong can ghi len dia
Ra :    Ma loi dia (neu co) */


byte BIOSwrite(byte drive, byte face, byte track,
				   byte sector, byte number, char*buffer);
/* CheckDiskReady(byte drive)
	Kiem tra xem dia co san sang
Vao :	so hieu o dia
Ra :	Ma loi(trang thai)
*/

byte CheckDiskReady(byte drive);

/* setdrive()
Dat loai dia mem dung cho chuc nang format:
Vao : so hieu o dia mem (0/1)
Ra : loai dia logic :0: khong dung
			 1: 360K trong o 360K
			 2: 360K trong o 1.2M
			 3: 1.2M trong o 1.2M
*/

void setdrive(byte drive,byte logical);

/*setcurdisk(byte drive)
	Chon o dia hien hanh
	Vao: so hieu cua o dia hien hanh:0(A),1(B),2(C),...
*/

byte setcurdisk(byte drive);

/* byte getcurdisk()
	Xac dinh o dia hien hanh*/

byte getcurdisk();

/* getlable()
Lay nhan dia
Vao: so hieu dia
Ra: nhan dia */

char *getlabel(byte drive);
void getlabel2(byte drive,char *label);

/*settable(char)
	Cai dat nhan dia */

byte setlabel(byte drive,char label[12]);
/*  format()
Dinh dang dia mem ( o dia 1.44MB)
Vao : So hieu o dia (drive (0..3))
	  So hieu mat dia (face (0/1))
	  So hieu track
	  So secto toi da cho track
	  So byte trong secto  : 0- 128 ,1- 256,
	  2- 512,1- 1024
Ra:   Ma loi (neu co)
*/

byte Format(byte drive,byte face,byte track,
			   byte sector,byte size);

void label();
void formatdiskette();
void copydiskette();

#endif