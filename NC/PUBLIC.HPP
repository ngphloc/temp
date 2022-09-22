#ifndef	_PUBLIC_HPP
#define _PUBLIC_HPP

#define	MAX			2000

#define 	TRUE 		(1==1)
#define 	FALSE   	(1==0)
#define 	LEFT 		0
#define 	RIGHT   	1

#define     BRIEF		0
#define     FULL		1
#define     INFO		2
#define     TREE		3
#define     QUICKVIEW	4

#define 	LLEFT 	1
#define 	LTOP     1
#define		LRIGHT   40
#define		LBOTTOM  23
#define 	RLEFT 	41
#define 	RTOP    1
#define		RRIGHT  80
#define		RBOTTOM 23

//#define min(a,b) (a<b)?a:b
//#define max(a,b) (a>b)?a:b
#define Attr (FA_RDONLY |FA_HIDDEN | FA_SYSTEM | FA_DIREC | FA_ARCH)

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <dos.h>
#include <string.h>
#include <math.h>
#include <dir.h>
#include <limits.h>
#include <alloc.h>
#include <time.h>
typedef struct
{
	char x;
	char y;
} TEXTPOINT;

typedef struct
{
	char left,top;
	char right,bottom;
} TEXTWINDOW;
extern char    CurMode;

extern char	LMode  	,   RMode; 		//che do : BRIEF,FULL,INFO,TREE,QUICKVIEW

extern	int		LDrive  	,   RDrive;			//o dia hien hanh
extern char 	LDir[256]	,	RDir[256]; 		//chuoi thu muc hien hanh
extern char    LExt[3]	,		RExt[3];	//phan mo rong hien hanh
extern char	LPath[256] 	,   RPath[256]; 	//Duong dan hien hanh

extern ffblk  far *LFileStr, 	far *RFileStr;	//chuoi file hien hanh
extern int	   LNum		    ,	RNum;			//so file
extern int		LNumDir		,	RNumDir;		//so thu muc
extern int		LStartPos   ,   RStartPos;
extern int		LCurPos		,	RCurPos;		//vi tri hien hanh

extern int	LLeft		 	,	RLeft;
extern int	LTop			,	RTop;
extern int	LRight			,	RRight;
extern int	LBottom			,	RBottom;

extern int	LNameWidth   ,	RNameWidth;
extern int	LSizeWidth   ,	RSizeWidth;
extern int	LDateWidth   ,	RDateWidth;

void border2(int left,int top,int right,int bottom,int bkColor,int Color);
void border(int left,int top,int right,int bottom);
void Message(int x1,int y1,int x2, int y2, char *s1,char *s2);

typedef unsigned char byte;
typedef unsigned int word ;
typedef struct
	 {
	   byte r:1;  //read only
	   byte h:1;  //hidden
	   byte s:1;  //system
	   byte l:1;  //label
	   byte d:1;  //directory
	   byte a:1;  //archive
	   byte n:2;  //not using
	 } sattrib ;
typedef union
	 {
	   word attr;
	   sattrib a;
	 } uattrib;

typedef struct
	 {
	   byte dd:5;  //ngay
	   byte mm:4;  //thang
	   byte yy:7;  //nam
	 } strdate ;
typedef union
	 {
	   word day;
	   strdate d;
	 } udate;

typedef struct
	 {
	   byte sec:5;  //gio
	   byte min:6;  //phut
	   byte hour:5; //giay
	 } strtime ;
typedef union
	 {
	   word clock;
	   strtime t;
	 } utime;

typedef struct
	 {
	   byte hi,lo;
	 } tam;

typedef union
	 {
	   word t;
	   tam f;
	 } W;

void hidecursor();
void showcursor();

template <class X> void Swap(X a,X b);				//ham hoan vi
int Round(float x);									//ham lam tron
void Creat_Arg(char*s, char ch, int &num_arg, char* arg[]);	//ham tach chuoi
int Printf(char *s, int n);                         //ham n ky tu cua chuoi

#endif