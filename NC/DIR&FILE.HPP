#ifndef	_DIR&FILE_HPP
#define	_DIR&FILE_HPP
#include "Screen.hpp"

static char blank[MAXPATH] = "";
static int  i,info[MAXPATH] = {0};

void md(int num_arg,char *argl[]);
void rd(int num_arg,char *argl[]);
void cd(int num_arg,char *argl[]);
void ren(int num_arg,char *argl[]);
int scandir(char *dd);
void dir(int num_arg,char *argl[]);
int scantree(char path[MAXPATH], int muc,FILE *filename);
void tree(int num_arg,char *argl[]);
void vol(int num_arg,char *argl[]);
void label(int num_arg,char *argl[]);
void del(int num_arg,char *argl[]);
int erase(char *d);
void copy(int num_arg,char *argl[]);
int copyfile(char *filename1,char *filename2);
int copydir(char *filename1,char *filename2);
void type(int num_arg,char *argl[]);
void date(int num_arg,char *argl[]);
void time(int num_arg,char *argl[]);

int attrib(char *path,byte attrib,byte funtion);
int splitfile(char*filename,char*filename1,char*filename2);
int mergefile(char*filename, int num_arg,char *file[]);

int Copy(char *s1, char *s2);
int Erase(char *s1);
int Rename(char *s1, char *s2);
int Attrib(char *s1);
int MakeDir (char *s1);


//Ham quet va ham tao mang file
int Scan(char *d, int &num, ffblk far*p, int attrib);
int ScanDF(char *d,int &num, int &num_dir, ffblk far*p, int attrib);
void CreatDF(int num, int &num_dir, ffblk far*pin, ffblk far*pout);

//Ham sap xep
void SortDF(int num, int num_dir, ffblk far*p);

//Ham them va chen file
void AppendDF(int &num, int &num_dir, ffblk f, ffblk far*p);
void InsertDF(int &num, int &num_dir, ffblk f, ffblk far*p);

typedef struct bootsector
	{
	 byte  person[3];
	 byte  version[8];
	 word  bytepersector;
	 byte  sectorpercluster;
	 word  reservedsector;
	 byte  fatnum;
	 word  rootentry;
	 word  sum_sector;
	 byte  mediadescriptor;
	 word  sectorperfat;
	 word  sectrk;
	 word  hdno;
	 long  hiddensector;
	 long  sumsector;
	 byte  physicdisk;
	 byte  danhrieng;
	 byte  klhieunhandien;
	 long  serialnumber;
	 char  volumelabel[11];
	 byte  fatid[8];
	 byte  rest[450];  //512-62
	};
void Info(int Mode, int drive);
void Tree(int Mode,char *dir);
void drive(int Mode);

#endif