#include "Screen.hpp"
#include "Dir&File.hpp"
#include "Disk.hpp"
byte BIOSread(byte drive, byte face, byte track,
				byte sector, byte number, char*buffer)
{
	union REGS reg;
	reg.h.ah=2;
	reg.h.al=number;
	reg.h.dh=face;
	reg.h.dl=drive;
	reg.h.ch=track;
	reg.h.cl=sector;
	reg.x.bx=(unsigned int) buffer;
	int86(0x13,&reg,&reg);
	return(reg.h.ah);
}

byte BIOSwrite(byte drive, byte face, byte track,
				   byte sector, byte number, char*buffer)
{
	union REGS reg;
	reg.h.ah=3;
	reg.h.al=number;
	reg.h.dh=face;
	reg.h.dl=drive;
	reg.h.ch=track;
	reg.h.cl=sector;
	reg.x.bx = (unsigned int) buffer;
	int86(0x13,&reg,&reg);
	return(reg.h.ah);
}

byte CheckDiskReady(byte drive)
{	union REGS reg;
	reg.h.ah=0x10;
	reg.h.dl=drive;
	int86(0x13,&reg,&reg);
	return(reg.h.ah);
}

char *getlabel(byte drive)
{
	int k=0;
	char *dd;
	ffblk buf;
	sprintf(dd,"%c:\\*.*",(drive+'A'));
	k=findfirst(dd,&buf,0x08);
	if (k) return "";
	return buf.ff_name;
}

void getlabel2(byte drive,char *label)
{
  bootsector buf;
  absread(drive,1,0,&buf);
  if (!strcmp(buf.volumelabel,"")) label="";
  else strncpy(label,buf.volumelabel,11);
}

byte setlabel(byte drive,char label[12])
{
	bootsector buf;
	if (absread(drive,1,0,&buf)) return 0;
	strncpy(buf.volumelabel,label,11);
	if (abswrite(drive,1,0,&buf)) return 0;
	return 1;
}

byte Format(byte drive,byte face,byte track,
			   byte sector,byte size)
{
   union REGS reg;
   struct format CHNS[18]; //So sector tren moi track
   if (sector<=18)         //toi da la 18
   {
	  for (int i=0;i<sector;i++)
	  {
	  CHNS[i].track=track;
	  CHNS[i].face=face;
	  CHNS[i].sector=i+1; // So hieu secto
	  CHNS[i].size=size;
	  }
	  reg.h.ah=5;
	  reg.h.al=sector;
	  reg.h.dh=face;
	  reg.h.dl=drive;
	  reg.h.ch=track;
	  reg.x.bx=(unsigned int)CHNS;
	  int86(0x13,&reg,&reg);
	  return (reg.h.ah);
   }
   return 0xFF;
}

extern char *Ok[2] ;
extern int OutputString(int x1,int y1,int x2,int y2,char *s1);

void label()
{
	char *Label,*buf1,*s;
	int i=0;
	buf1=(char*)malloc(13);
	s=(char*)malloc(13);
	buf1[0]=12;

	border(20,5,41,11);
	textcolor(1);
	gotoxy(4,1);
	cprintf("LABEL - Drive %c:",getdisk()+'A');
	gotoxy(3,7);
	cprintf("Set label to disk");
	gotoxy(2,3);
	cprintf("Label ");

	textattr(0x1b);
	gotoxy(13,5);
	 cprintf(" Cancel ");
	textattr(0x4E);
	gotoxy(3,5);
	 cprintf("®OK¯");

	strcpy(s,"");
	getlabel2((byte)getdisk(),s);
	Label=s;

	Input:
	i=OutputString(29,7,40,7,Label);
	switch (i)
	{
	  case 27: textattr(0x0b);clrscr();
		   free(buf1);free(s);
		   return;
	  case 13: i=0;
		   break;
	  case 9:
		   i=mnuHorizontal(17,9,2,Ok);
		   break;
	  case 10:
		   clrscr();
		   Label=cgets(buf1);
		   i=mnuHorizontal(17,9,2,Ok);
		   break;
	}
	switch (i)
	{
	  case 0:
		  if (strcmp(s,Label))
		  {
		 if (!setlabel(getdisk(),Label))
			Message(25,10,55,13,"ERROR",
				 "Disk can't be written !!!");
		 else
			Message(25,10,55,13,"SUCCESS",
				 "Disk was set label");
		 getch();
		  }
		  break;
	  case 100:
	  case 15: goto Input;
	  default: break;
	}
	free(buf1);free(s);
	textattr(0x0b);
    window(1,1,80,25);
	clrscr();
}

void formatdiskette()
{
   border(20,5,60,17);
   textcolor(1);
   gotoxy(17,1);
	cprintf("FORMAT");
   gotoxy(1,13);
	cprintf("Format diskete - 3« Floppy !!!");

   border2(21,7,37,11,7,BLUE);
   gotoxy(2,1);
	cprintf("( ) 1.44 MB ");
   gotoxy(2,2);
	cprintf("( ) 1.2 MB ");
   gotoxy(2,3);
	cprintf("( ) 720 KB ");

   border2(40,7,59,11,7,BLUE);
   gotoxy(2,1);
	cprintf("( ) Quick Format");
   gotoxy(2,2);
	cprintf("( ) Safe Format");
   gotoxy(2,3);
	cprintf("( ) DOS ");

   window(21,6,59,19);
   gotoxy(5,2);
	cprintf("Type");
   gotoxy(25,2);
	cprintf("Method");

   gotoxy(10,7);
	cprintf("[ ] Make system disk");
   gotoxy(8,8);
	cprintf("Volume Label ");

   textattr(0x1b);
   gotoxy(22,10);
	cprintf(" Cancel ");
   textattr(0x4E);
   gotoxy(12,10);
	cprintf("®OK¯");

	textbackground(0);
	window(41,13,51,13);
	clrscr();

  getch();

  textbackground(0);
  textcolor(11);
  window(1,1,80,25);
  clrscr();
}

void copydiskette()
{
   border(20,5,60,14);
   textcolor(1);
   gotoxy(15,1);
    cprintf("COPY DISKETE");
   gotoxy(1,10);
    cprintf("Backup diskete - 3« Floppy !!!");

   border2(21,7,38,10,7,BLUE);
   gotoxy(2,1);
    cprintf("(ù) 3« Floppy");
   gotoxy(2,2);
    cprintf("( ) Image file");

   border2(40,7,59,10,7,BLUE);
   gotoxy(2,1);
    cprintf("( ) 3« Floppy");
   gotoxy(2,2);
	cprintf("(ù) Image file");

   window(21,6,59,17);
   gotoxy(5,2);
    cprintf("Source");
   gotoxy(25,2);
	cprintf("Destination");

   textattr(0x1b);
   gotoxy(22,7);
    cprintf(" Cancel ");
   textattr(0x4E);
   gotoxy(12,7);
    cprintf("®OK¯");

  getch();
  textbackground(0);
  textcolor(11);
  window(1,1,80,25);
  clrscr();
}
