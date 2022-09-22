#ifndef _SCREEN_HPP
#define _SCREEN_HPP
#include "Public.hpp"
typedef struct
{
	char	 	n;
	char 		left,top;
	char 		right,bottom;
	char 		*pStr[18];
	TEXTPOINT 	pStrPos[18];
	char 		pChar[18];
	char 		pCharPos[18];
	char    	NumLine;
	char    	pLineY[4];
	char    	value[18];
} ITEM;


void Frame(char Left, char Top, char Right, char Bottom, char ground_color, char text_color, char flag);
void NCWindow(char side,char item, char x1=13, char x2=23, char x3=32);
char  NCMenu();

int mnuHorizontal(int x,int y,int nummenu,char *Menu[]);
int mnuVertical(int x,int y,int nummenu,char *Menu[]);
byte mnuChoose(byte x,byte y,byte numRow,
			byte numCol,byte spaceHorizon);
byte mnuOption(byte x,byte y,byte numRow,
			byte numCol,byte spaceHorizon);
int mnuHorizontal2(int x,int y,int space,int nummenu,char *Menu[]);

unsigned offset(int x,int y);
void SetAttr(int x1,int y1,int x2,int y2,byte attr);
void ScrollUp(byte x1,byte y1,byte x2,
		byte y2,byte attr,byte numline);
void ScrollDown(byte x1,byte y1,byte x2,
		byte y2,byte attr,byte numline);
int Display(char **bufferfile,unsigned counter,byte x1,
		byte y1,byte x2,byte y2,byte attr,byte selectattr);
int ViewFile(char *filename,byte x1,byte y1,
			  byte x2,byte y2,byte attr,byte selectattr);
int Viewtree1(char *filename,int Mode,byte attr,byte selectattr);
int SelectHelp();
void Help();

#endif