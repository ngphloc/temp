#include "Screen.hpp"

char *MenuPopup[] =
{
   "Left","Files","Disk","Command","Right"
};
ITEM pItem[5]=
{
	{
		18,
		1,2,37,23,
		{
			"Brief                         ",
			"Full                          ",
			"Info                          ",
			"Tree                          ",
			"Quick View                    ",
			"Compressed File               ",
			"Find file panel               ",
			"Directory information         ",
			"Link                          ",
			"On/off                 Ctrl-F1",
			"Name                   Ctrl-F3",
			"Extension              Ctrl-F4",
			"Time                   Ctrl-F5",
			"Size                   Ctrl-F6",
			"Unsorted               Ctrl-F7",
			"Re-read                       ",
			"Filter ...                    ",
			"Drive ...              Alt-F1 "
		},
		{
			{4,3},{4,4},{4,5},{4,6},{4,7},{4,8},{4,9},{4,10},{4,11},{4,12},
			{4,14},{4,15},{4,16},{4,17},{4,18},
			{4,20},{4,21},{4,22}
		},
		{
			'B','F','I','T','v','C','p','y','k','O','N','x','m','S','U','R',
			'l','D'
		},
		{
			0,0,0,0,6,0,10,8,3,0,0,1,2,0,0,0,2,0
		},
		2,
		{13,19},
		{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18}
	},

	{
		15,
		10,2,46,20,
		{
			"Help                   F1      ",
			"User menu              F2      ",
			"View                   F3      ",
			"Edit                   F4      ",
			"Copy                   F5      ",
			"Rename or move         F6      ",
			"Make directory         F7      ",
			"Delete                 F8      ",
			"Split/Merge            Ctrl-F10",
			"File attributes                ",
			"Select group           Gray +  ",
			"Deselect group         Gray -  ",
			"Invert selection       Gray *  ",
			"Restore selection              ",
			"Quit                   F10     "
		},
		{
			{13,3},{13,4},{13,5},{13,6},{13,7},{13,8},{13,9},{13,10},{13,11},
			{13,13},
			{13,14},{13,15},{13,16},{13,17},
			{13,19}
		},
		{
			'H','U','V','E','C','R','M','D','p','a','g','t','I','s','Q'
		},
		{
			0,0,0,0,0,0,0,0,1,5,7,7,0,2,0
		},
		2,
		{12,18},
		{19,20,21,22,23,24,25,26,27,28,29,30,31,32,33}
	},
	{
		5,
		20,2,56,10,
		{
			"Copy diskette ...              ",
			"Format diskette ...            ",
			"Label disk ...                 ",
			"Netwok utilities ...   Shift-F2",
			"Disk cleanup ...               "
		},
		{
			{23,3},{23,4},{23,5},
			{23,7},
			{23,9},
		},
		{
			'C','F','L','N','D'
		},
		{
			0,0,0,0,0
		},
		2,
		{6,8},
		{34,35,36,37,38}
	},
	{
		14,
		30,2,66,21,
		{
			"NCD tree                Alt-F10",
			"Find file               Alt-F7 ",
			"History                 Alt-F8 ",
			"EGA lines               Alt-F9 ",
			"System information             ",
			"Swap panels             Ctrl-U ",
			"Panels on/off           Ctrl-O ",
			"Compare directories            ",
			"Synchronize directories Ctrl-F8",
			"Terminal Emulation             ",
			"Menu file edit ...             ",
			"Extension file edit ...        ",
			"Editors ...                    ",
			"Configuration ...              ",
		},
		{
			{33,3},{33,4},{33,5},{33,6},{33,7},
			{33,9},{33,10},{33,11},{33,12},
			{33,14},
			{33,16},{33,17},{33,18},
			{33,20}
		},
		{
			'N','F','H','E','i','S','P','C','y','T','M','x','o','g'
		},
		{
			0,0,0,0,7,0,0,0,1,0,0,1,4,5
		},
		4,
		{8,13,15,19},
		{39,40,41,42,43,44,45,45,47,48,49,50,51,52}
	},
	{
		18,
		40,2,76,23,
		{
			"Brief                         ",
			"Full                          ",
			"Info                          ",
			"Tree                          ",
			"Quick View                    ",
			"Compressed File               ",
			"Find file panel               ",
			"Directory information         ",
			"Link                          ",
			"On/off                 Ctrl-F2",
			"Name                   Ctrl-F3",
			"Extension              Ctrl-F4",
			"Time                   Ctrl-F5",
			"Size                   Ctrl-F6",
			"Unsorted               Ctrl-F7",
			"Re-read                       ",
			"Filter ...                    ",
			"Drive ...              Alt-F2 "
		},
		{
			{43,3},{43,4},{43,5},{43,6},{43,7},{43,8},{43,9},{43,10},{43,11},{43,12},
			{43,14},{43,15},{43,16},{43,17},{43,18},
			{43,20},{43,21},{43,22}
		},
		{
			'B','F','I','T','v','C','p','y','k','O','N','x','m','S','U','R',
			'l','D'
		},
		{
			0,0,0,0,6,0,10,8,3,0,0,1,2,0,0,0,2,0
		},
		2,
		{13,19},
        {53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70}
	},
};

void Frame(char Left, char Top, char Right, char Bottom, char ground_color, char text_color, char flag)
{
	char i;
	textbackground(ground_color);
	textcolor(text_color);
	window(Left,Top,Right,Bottom);
	Right=Right-Left+1;
	Bottom=Bottom-Top+1;
	Left=1;
	Top=1;
	clrscr();

	for(i=Left+1;i<=Right-1;i++)
	{
		gotoxy(i,Top);
		if(flag==TRUE)
			cprintf("Í");
		else
			cprintf("Ä");

		gotoxy(i,Bottom);
		if(flag==TRUE)
			cprintf("Í");
		else
			cprintf("Ä");
	}

	for(i=Top+1;i<=Bottom-1;i++)
	{
		gotoxy(Left,i);
		if(flag==TRUE)
			cprintf("º");
		else
				cprintf("³");

		gotoxy(Right,i);
		if(flag==TRUE)
			cprintf("º");
		else
				cprintf("³");
	}

	gotoxy(Left,Top);
	if(flag==TRUE)
		cprintf("É");
	else
		cprintf("Ú");

	gotoxy(Right,Top);
	if(flag==TRUE)
		cprintf("»");
	else
		cprintf("¿");


	gotoxy(Left,Bottom);
	if(flag==TRUE)
		printf("È");
	else
		cprintf("À");

	gotoxy(Right,Bottom);
	if(flag==TRUE)
		printf("¼");
	else
		printf("¼");
		//cprintf("Ù");

	textbackground(BLACK);
	textcolor(WHITE);
	window(1,1,80,25);
}
void NCWindow(char side,char item, char x1, char x2, char x3)
{
	char i;
	char left,top;
	char right,bottom;
	if((side!=LEFT)&&(side!=RIGHT))
		exit(1);
	switch(side)
	{
		case LEFT:
			left=LLEFT;
			top=LTOP;
			right=LRIGHT;
			bottom=LBOTTOM;
			break;
		case RIGHT:
			left=RLEFT;
			top=RTOP;
			right=RRIGHT;
			bottom=RBOTTOM;
			break;
	}
	Frame(left,top,right,bottom,BLUE,LIGHTCYAN,TRUE);

	textbackground(BLUE);
	textcolor(LIGHTCYAN);
	switch(item)
	{
		case BRIEF:
			if((0<x1)&&(x1<x2)&&(x2<right-left))
			{
				for(i=top+1;i<=bottom-3;i++)
				{
					gotoxy(left+x1,i);
					cprintf("³");
					gotoxy(left+x2,i);
					cprintf("³");
				}
				for(i=left+1;i<=right-1;i++)
				{
					gotoxy(i,bottom-2);
					cprintf("Ä");
				}

				gotoxy(left+x1,top);
				cprintf("Ñ");
				gotoxy(left+x2,top);
				cprintf("Ñ");

				gotoxy(left+x1,bottom-2);
				cprintf("Á");
				gotoxy(left+x2,bottom-2);
				cprintf("Á");

				gotoxy(left,bottom-2);
				cprintf("Ç");
				gotoxy(right,bottom-2);
				cprintf("¶");

				textcolor(YELLOW);
				gotoxy(left+2,top+1);
				cprintf("%c",58);
				gotoxy(left+3,top+1);
				cprintf("%c",25);
				gotoxy(left+5,top+1);
				cprintf("Name");
				gotoxy(left+x1+5,top+1);
				cprintf("Name");
				gotoxy(left+x2+5,top+1);
				cprintf("Name");
			}

			break;
		case FULL:
			if((0<x1)&&(x1<x2)&&(x2<x3)&&(x3<right-left))
			{
				for(i=top+1;i<=bottom-3;i++)
				{
					gotoxy(left+x1,i);
					cprintf("³");
					gotoxy(left+x2,i);
					cprintf("³");
					gotoxy(left+x3,i);
					cprintf("³");
				}
				for(i=left+1;i<=right-1;i++)
				{
					gotoxy(i,bottom-2);
					cprintf("Ä");
				}
				gotoxy(left+x1,top);
				cprintf("Ñ");
				gotoxy(left+x2,top);
				cprintf("Ñ");
				gotoxy(left+x3,top);
				cprintf("Ñ");

				gotoxy(left+x1,bottom-2);
				cprintf("Á");
				gotoxy(left+x2,bottom-2);
				cprintf("Á");
				gotoxy(left+x3,bottom-2);
				cprintf("Á");

				gotoxy(left,bottom-2);
				cprintf("Ç");
				gotoxy(right,bottom-2);
				cprintf("¶");

				textcolor(YELLOW);
				gotoxy(left+2,top+1);
				cprintf("%c",58);
				gotoxy(left+3,top+1);
				cprintf("%c",25);
				gotoxy(left+5,top+1);
				cprintf("Name");
				gotoxy(left+x1+4,top+1);
				cprintf("Size");
				gotoxy(left+x2+3,top+1);
				cprintf("Date");
				gotoxy(left+x3+2,top+1);
				cprintf("Time");
			}
			break;
		case INFO:
			for(i=left+1;i<=right-1;i++)
			{
				gotoxy(i,top+3);
				cprintf("Ä");
				gotoxy(i,top+11);
				cprintf("Ä");
				gotoxy(i,top+14);
				cprintf("Ä");
			}
			gotoxy(left,top+3);
			cprintf("Ç");
			gotoxy(right,top+3);
			cprintf("¶");

			gotoxy(left,top+11);
			cprintf("Ç");
			gotoxy(right,top+11);
			cprintf("¶");

			gotoxy(left,top+14);
			cprintf("Ç");
			gotoxy(right,top+14);
			cprintf("¶");

			gotoxy(left+16,top);
			cprintf(" Info ");

			gotoxy(left+4,top+1);
			cprintf("The Norton Comander ,Version 1.0 ");
			gotoxy(left+6,top+2);
			cprintf("Written by Nguyen Phuoc Loc");
			gotoxy(left+3,bottom-6);
			cprintf("No \"dirinfo\" file in this directory");
			break;
		case TREE:
			for(i=left+1;i<=right-1;i++)
			{
				gotoxy(i,bottom-2);
				cprintf("Ä");
			}
			gotoxy(left,bottom-2);
			cprintf("Ç");
			gotoxy(right,bottom-2);
			cprintf("¶");

			gotoxy(left+16,top);
			cprintf(" Tree ");
			break;
		case QUICKVIEW:
			for(i=left+1;i<=right-1;i++)
			{
				gotoxy(i,bottom-2);
				cprintf("Ä");
			}

			gotoxy(left,bottom-2);
			cprintf("Ç");
			gotoxy(right,bottom-2);
			cprintf("¶");

			gotoxy(left+16,top);
			cprintf(" View ");
			break;
	}
}
void DrawMark(char i, char ground_color, char color, char reversed_color)
{
	textbackground(ground_color);
	textcolor(color);
	gotoxy(i*12+2,1);
	cprintf("   %s   ",MenuPopup[i]);
	textcolor(reversed_color);
	gotoxy(i*12+2,1);
	cprintf("   %c",MenuPopup[i][0]);

}
void DrawMenu()
{
	char i;
	gotoxy(1,1);
	textbackground(CYAN);
	cprintf("                                                              ");
	cprintf("                  ");
	textcolor(BLACK);
	for (i=0;i<5;i++)
	{
		gotoxy(i*12+2,1);
		cprintf("%s",MenuPopup[i]);
	}
	textcolor(YELLOW);
	for (i=0;i<5;i++)
	{
		gotoxy(i*12+2,1);
		cprintf("%c",MenuPopup[i][0]);
	}
}
void DrawPopupMark(char item, char i, char ground_color, char color, char reversed_color)
{
	char x,y;
	textbackground(ground_color);
	textcolor(color);
	x= pItem[item].pStrPos[i].x-2;
	y= pItem[item].pStrPos[i].y;
	gotoxy(x,y);
	cprintf("  %s",pItem[item].pStr[i]);

	textcolor(reversed_color);
	x= pItem[item].pStrPos[i].x+pItem[item].pCharPos[i];
	y= pItem[item].pStrPos[i].y;
	gotoxy(x,y);
	cprintf("%c",pItem[item].pChar[i]);

	textbackground(CYAN);
	textcolor(WHITE);

}

void DrawPopupMenu(char item)
{
	char x,y,i;

	Frame(pItem[item].left,pItem[item].top,pItem[item].right,pItem[item].bottom,3,0,FALSE);
	textbackground(CYAN);
	textcolor(WHITE);
	for(i=0;i<pItem[item].n;i++)
	{
		x= pItem[item].pStrPos[i].x;
		y= pItem[item].pStrPos[i].y;
		gotoxy(x,y);
		cprintf("%s",pItem[item].pStr[i]);
	}

	textcolor(YELLOW);
	for(i=0;i<pItem[item].n;i++)
	{
		x= pItem[item].pStrPos[i].x+pItem[item].pCharPos[i];
		y= pItem[item].pStrPos[i].y;
		gotoxy(x,y);
		cprintf("%c",pItem[item].pChar[i]);
	}

	textcolor(BLACK);
	x=pItem[item].pStrPos[0].x-1;
	for(i=0;i<pItem[item].NumLine;i++)
	{
		y=pItem[item].pLineY[i];
		gotoxy(x,y);
		cprintf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
	}

	highvideo();
	for(i=pItem[item].top+1;i<=pItem[item].bottom;i++)
	{
		textcolor(BLACK);
		gotoxy(pItem[item].right+1,i);
		cprintf("ÛÛ");
	}
	for(i=pItem[item].left+1;i<=pItem[item].right+1;i++)
	{
		textcolor(BLACK);
		gotoxy(i,pItem[item].bottom+1);
		cprintf("ÛÛ");
	}
	normvideo();
}

char  NCMenu()
{

	char i,j,k;
	char ch,ret,s[160];
	char p[4000];
	static char c1,c2=10,c3,c4=10;

	gettext(1,2,80,25,p);
	gettext(1,1,80,1,s);
	DrawMenu();
	i=0;
	DrawMark(i,BLACK,WHITE,YELLOW);
	do
	{
		ch=getch();
		if (ch==0)
		{
			ch=getch();
			if(ch==68)	 //phim F10
			{
				ret=0;
				goto end;
			}
			if(ch==80)   //phim mui ten xuong
			{
				j=i;
				goto submenu;
			}
			switch(ch)
			{
				case 75: //phim mui ten trai
					DrawMark(i,CYAN,BLACK,YELLOW);
					i--;
					if (i<0) i=4;
					DrawMark(i,BLACK,WHITE,YELLOW);
					break;
				case 77: //phim mui ten phai
					DrawMark(i,CYAN,BLACK,YELLOW);
					i++;
					if (i>4) i=0;
					DrawMark(i,BLACK,WHITE,YELLOW);
					break;
				case 71: //phim Home
					DrawMark(i,CYAN,BLACK,YELLOW);
					i=0;
					DrawMark(i,BLACK,WHITE,YELLOW);
					break;
				case 79: //phim End
					DrawMark(i,CYAN,BLACK,YELLOW);
					i=4;
					DrawMark(i,BLACK,WHITE,YELLOW);
					break;
			}
		}
		else
		{
			if(ch==27)   //phim ESC
			{
				ret=0;
				goto end;
			}
			if(ch==13)   //phim Enter
			{
				j=i;
				goto submenu;
			}
			int t;
			t=ch;
			if(!isupper(t))
				t=t-32;
			switch(t)
			{
				case 'L':
					DrawMark(i,CYAN,BLACK,YELLOW);
					i=0;
					DrawMark(i,BLACK,WHITE,YELLOW);
					break;
				case 'F':
					DrawMark(i,CYAN,BLACK,YELLOW);
					i=1;
					DrawMark(i,BLACK,WHITE,YELLOW);
					break;
				case 'D':
					DrawMark(i,CYAN,BLACK,YELLOW);
					i=2;
					DrawMark(i,BLACK,WHITE,YELLOW);
					break;
				case 'C':
					DrawMark(i,CYAN,BLACK,YELLOW);
					i=3;
					DrawMark(i,BLACK,WHITE,YELLOW);
					break;
				case 'R':
					DrawMark(i,CYAN,BLACK,YELLOW);
					i=4;
					DrawMark(i,BLACK,WHITE,YELLOW);
					break;
			}
		}
		goto ignore;
	submenu:
		k=0;
		DrawPopupMenu(j);
		DrawPopupMark(j,k,BLACK,WHITE,YELLOW);
		if(j==0)
		{
				gotoxy(pItem[j].left+1,pItem[j].pStrPos[c1].y);
				cprintf("û");
				textbackground(CYAN);
				textcolor(WHITE);
				gotoxy(pItem[j].left+1,pItem[j].pStrPos[c2].y);
				cprintf("û");
		}
		if(j==4)
		{
				gotoxy(pItem[j].left+1,pItem[j].pStrPos[c3].y);
				cprintf("û");
				textbackground(CYAN);
				textcolor(WHITE);
				gotoxy(pItem[j].left+1,pItem[j].pStrPos[c4].y);
				cprintf("û");
		}

		do
		{
			ch=getch();
			if(ch==0)
			{
				ch=getch();
				switch(ch)
				{
					case 68:   //phim F10
						puttext(1,2,80,25,p);
						goto ignore;
					case 75:   //phim mui ten trai
						puttext(1,2,80,25,p);
						DrawMark(i,CYAN,BLACK,YELLOW);
						i--;
						if (i<0) i=4;
						DrawMark(i,BLACK,WHITE,YELLOW);
						j=i;
						goto submenu;
					case 77:   //phim mui ten phai
						puttext(1,2,80,25,p);
						DrawMark(i,CYAN,BLACK,YELLOW);
						i++;
						if (i>4) i=0;
						DrawMark(i,BLACK,WHITE,YELLOW);
						j=i;
						goto submenu;
					case 71:   //phim Home
						puttext(1,2,80,25,p);
						DrawMark(i,CYAN,BLACK,YELLOW);
						i=0;
						DrawMark(i,BLACK,WHITE,YELLOW);
						j=i;
						goto submenu;
					case 79:   //phim End
						puttext(1,2,80,25,p);
						DrawMark(i,CYAN,BLACK,YELLOW);
						i=4;
						DrawMark(i,BLACK,WHITE,YELLOW);
						j=i;
						goto submenu;
					case 80:   //phim mui ten xuong
						DrawPopupMark(j,k,CYAN,WHITE,YELLOW);
						if(j==0)
						{
							textbackground(CYAN);
							textcolor(WHITE);
							if(k==c1)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c1].y);
								cprintf("û");
							}
							else if(k==c2)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c2].y);
								cprintf("û");
							}
						}
						if(j==4)
						{
							textbackground(CYAN);
							textcolor(WHITE);
							if(k==c3)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c3].y);
								cprintf("û");
							}
							else if(k==c4)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c4].y);
								cprintf("û");
							}
						}
						k++;
						if(k>pItem[j].n-1)	k=0;
						DrawPopupMark(j,k,BLACK,WHITE,YELLOW);
						if(j==0)
						{
							textbackground(BLACK);
							textcolor(WHITE);
							if(k==c1)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c1].y);
								cprintf("û");
							}
							else if(k==c2)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c2].y);
								cprintf("û");
							}
						}
						if(j==4)
						{
							textbackground(BLACK);
							textcolor(WHITE);
							if(k==c3)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c3].y);
								cprintf("û");
							}
							else if(k==c4)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c4].y);
								cprintf("û");
							}
						}
						break;
					case 72:   //phim mui ten len
						DrawPopupMark(j,k,CYAN,WHITE,YELLOW);
						if(j==0)
						{
							textbackground(CYAN);
							textcolor(WHITE);
							if(k==c1)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c1].y);
								cprintf("û");
							}
							else if(k==c2)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c2].y);
								cprintf("û");
							}
						}
						if(j==4)
						{
							textbackground(CYAN);
							textcolor(WHITE);
							if(k==c3)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c3].y);
								cprintf("û");
							}
							else if(k==c4)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c4].y);
								cprintf("û");
							}
						}

						k--;
						if(k<0)	k=pItem[j].n-1;
						DrawPopupMark(j,k,BLACK,WHITE,YELLOW);
						if(j==0)
						{
							textbackground(BLACK);
							textcolor(WHITE);
							if(k==c1)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c1].y);
								cprintf("û");
							}
							else if(k==c2)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c2].y);
								cprintf("û");
							}
						}
						if(j==4)
						{
							textbackground(BLACK);
							textcolor(WHITE);
							if(k==c3)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c3].y);
								cprintf("û");
							}
							else if(k==c4)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c4].y);
								cprintf("û");
							}
						}
						break;
					case 73:   //phim PagUp
						DrawPopupMark(j,k,CYAN,WHITE,YELLOW);
						if(j==0)
						{
							textbackground(CYAN);
							textcolor(WHITE);
							if(k==c1)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c1].y);
								cprintf("û");
							}
							else if(k==c2)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c2].y);
								cprintf("û");
							}
						}
						if(j==4)
						{
							textbackground(CYAN);
							textcolor(WHITE);
							if(k==c3)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c3].y);
								cprintf("û");
							}
							else if(k==c4)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c4].y);
								cprintf("û");
							}
						}

						k=0;
						DrawPopupMark(j,k,BLACK,WHITE,YELLOW);
						if(j==0)
						{
							textbackground(BLACK);
							textcolor(WHITE);
							if(k==c1)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c1].y);
								cprintf("û");
							}
							else if(k==c2)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c2].y);
								cprintf("û");
							}
						}
						if(j==4)
						{
							textbackground(BLACK);
							textcolor(WHITE);
							if(k==c3)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c3].y);
								cprintf("û");
							}
							else if(k==c4)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c4].y);
								cprintf("û");
							}
						}
						break;
					case 81:   //phim PagDn
						DrawPopupMark(j,k,CYAN,WHITE,YELLOW);
						if(j==0)
						{
							textbackground(CYAN);
							textcolor(WHITE);
							if(k==c1)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c1].y);
								cprintf("û");
							}
							else if(k==c2)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c2].y);
								cprintf("û");
							}
						}
						if(j==4)
						{
							textbackground(CYAN);
							textcolor(WHITE);
							if(k==c3)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c3].y);
								cprintf("û");
							}
							else if(k==c4)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c4].y);
								cprintf("û");
							}
						}

						k=pItem[j].n-1;
						DrawPopupMark(j,k,BLACK,WHITE,YELLOW);
						if(j==0)
						{
							textbackground(BLACK);
							textcolor(WHITE);
							if(k==c1)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c1].y);
								cprintf("û");
							}
							else if(k==c2)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c2].y);
								cprintf("û");
							}
						}
						if(j==4)
						{
							textbackground(BLACK);
							textcolor(WHITE);
							if(k==c3)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c3].y);
								cprintf("û");
							}
							else if(k==c4)
							{
								gotoxy(pItem[j].left+1,pItem[j].pStrPos[c4].y);
								cprintf("û");
							}
						}
						break;
				}
			}
			else
			{
				switch(ch)
				{
					case 13:   //phim Enter
						puttext(1,2,80,25,p);
						ret=pItem[j].value[k];
						if(j==0)
						{
							if((k>=0)&&(k<=9))
								c1=k;
							if((k>=10)&&(k<=14))
								c2=k;
						}
						if(j==4)
						{
							if((k>=0)&&(k<=9))
								c3=k;
							if((k>=10)&&(k<=14))
								c4=k;
						}
						goto end;
					case 27:   //phim ESC
						puttext(1,2,80,25,p);
						goto ignore;
					default:   //cac phim ky tu
						char count=0;
						int t1,t2;
						t1=ch;
						if(!isupper(t1))
							t1=t1-32;
						while(1)
						{
							t2=pItem[j].pChar[count];
							if(!isupper(t2))
								t2=t2-32;
							if((t1!=t2)&&(count<pItem[j].n))
								count++;
							break;
						}
						if(count!=pItem[j].n)
						{
							puttext(1,2,80,25,p);
							ret=pItem[j].value[k];
							goto end;
						}
				}
			}
		} while(1);

	ignore:
	}  	while(1);

end:
	puttext(1,1,80,1,s);
	return ret;
}

int mnuHorizontal(int x,int y,int nummenu,char *Menu[])
{
	int i;
	char ch;
	textbackground(1);
	textcolor(11);
	window(1,1,80,24);
	for (i=1;i<nummenu;i++)
	{
		gotoxy(x+i*10+5,y);
		cprintf(" %s ",Menu[i]);
	}
	i=0; //menu Left
	textbackground(4);
	textcolor(14);
	gotoxy(x+5,y);
	cprintf("®%s¯",Menu[0]);
	gotoxy(1,1);

	do
	{
	   ch=getch();
	   if (ch==0)
	   {
		  textbackground(1);
		  textcolor(11);
		  gotoxy(x+i*10+5,y);
		  ch=getch();
		  switch(ch)
		  {
		 case 'K':   //Left
				  cprintf(" %s ",Menu[i]);
				  i--;
				  if (i<0) i=nummenu-1;
				  break;
		 case 'M':   //Right
				  cprintf(" %s ",Menu[i]);
				  i++;
				  if (i>=nummenu) i=0;
				  break;
		  }
		  textbackground(4);
		  textcolor(14);
		  gotoxy(x+i*10+5,y);
		  cprintf("®%s¯",Menu[i]);
		  //gotoxy(X,Y);
		  gotoxy(1,1);
	   }
	   else
		  switch (ch)
		  {
		  case 13:
			   return i;
		  case 9:
			   return 100;
	}
	  }
	  while(ch!=27);
	  textbackground(0);
	  textcolor(11);
	  return 128;
}

int mnuHorizontal2(int x,int y,int space,int nummenu,char *Menu[])
{
	int i;
	char ch;
	textbackground(1);
	textcolor(11);
	border2(x,y-2,x+space*(nummenu+3),y+1,7,1);
	textattr(0x1b);
	clrscr();
	cprintf(" Change drive :");
	window(1,1,80,24);
	for (i=1;i<nummenu;i++)
	{
		gotoxy(x+i*space+5,y);
		cprintf(" %s ",Menu[i]);
	}
	i=0; //menu Left
	textbackground(4);
	textcolor(14);
	gotoxy(x+5,y);
	cprintf("®%s¯",Menu[0]);
	//gotoxy(X,Y);
	gotoxy(1,1);
	do
	{
	   ch=getch();
	   if (ch==0)
	   {
	      textbackground(1);
	      textcolor(11);
	      gotoxy(x+space*i+5,y);
	      ch=getch();
	      switch(ch)
	      {
		 case 'K':   //Left
			      cprintf(" %s ",Menu[i]);
			      i--;
			      if (i<0) i=nummenu-1;
			      break;
		 case 'M':   //Right
				  cprintf(" %s ",Menu[i]);
			      i++;
				  if (i>=nummenu) i=0;
			      break;
	      }
	      textbackground(4);
	      textcolor(14);
	      gotoxy(x+i*space+5,y);
	      cprintf("®%s¯",Menu[i]);
		  //gotoxy(X,Y);
		  gotoxy(1,1);
	   }
	   else
	      switch (ch)
	      {
		  case 13:
			   return i;
		  case 9:
			   return 100;
	}
      }
      while(ch!=27);
      textbackground(0);
      textcolor(11);
      return 128;
}

// Thiet lap menu doc

int mnuVertical(int x,int y,int nummenu,char *Menu[])
{
	char ch;
	int hshien,hsmoi;
	int hsCode,i;

	textcolor(BLACK);
	textbackground(WHITE);
	gotoxy(x,y);
	cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");//218.196.191
	textbackground(GREEN);
	gotoxy(x,y+1);
	cprintf("%s",Menu[0]);
	textbackground(WHITE);
	for(i=1;i<nummenu+1;i++)
	{
	 gotoxy(x,y+i+1);
	 cprintf("%s",Menu[i]);
	}
	//gotoxy(X,Y);
	gotoxy(1,1);
	hshien=0;
	hsmoi=0;
	do
	{
	  ch=getch();
	  if(ch==0)//cac phim dac biet
		switch(getch())
		{
		  case 'G':hsmoi=0;break;//home
		  case 'O':hsmoi=nummenu-1;break;//end
		  case 'H':if(hshien>0) hsmoi=hshien-1;
				   else hsmoi=nummenu-1;break;//up
		  case 'P':if(hshien<nummenu-1) hsmoi=hshien+1;
				   else hsmoi=0;//Down
		}
		if (hsmoi!=hshien)
		{
			textbackground(WHITE);
			gotoxy(x,y+hshien+1);
			textcolor(BLACK);
			cprintf("%s",Menu[hshien]);
			textbackground(GREEN);
			gotoxy(x,y+hsmoi+1);
			textcolor(BLACK);
			cprintf("%s",Menu[hsmoi]);
			hshien=hsmoi;
			//gotoxy(X,Y);
			gotoxy(1,1);
	   }
	}
	while((ch!=13)&&(ch!=27));
	hsCode=hshien;
	clrscr();
	if (ch!=27)
	   return hsCode;
	else
	   return 128;
}

byte mnuChoose(byte x,byte y,byte numRow,
			byte numCol,byte spaceHorizon)
{
   int i=x,j=y;
   window(1,1,80,24);
   textattr(0x0E);
   gotoxy(i,j);
   putchar('ù');
   gotoxy(i,j);
   char ch;
   do
   {
      ch=getch();
	  if (ch==0)
      {
	 putchar(' ');
	 ch=getch();
	 switch(ch)
	 {
	    case 'K':   //Left
		      i-=spaceHorizon;
		      if (i<x) i = x+spaceHorizon*(numCol-1);
		      break;
	    case 'M':   //Right
		      i+=spaceHorizon;
		      if (i>x+spaceHorizon*(numCol-1)) i=x;
		      break;
	    case 'H':   //Up
		      j--;
		      if (j<y) j=y+numRow-1;
			  break;
	    case 'P':   //Down
			  j++;
		      if (j>y+numRow-1) j=y;
		      break;
	 }
	 gotoxy(i,j);
	 putchar('ù');
	 gotoxy(i,j);
      }
      else
	 if (ch==13||ch==9) return (j-y)*numRow+i;
   }
   while(ch!=27);
   return 0;
}

byte mnuOption(byte x,byte y,byte numRow,
			byte numCol,byte spaceHorizon)
{
   int i,j;
   int temp=0;
   window(1,1,80,24);
   byte check[10][4];
   char ch;
   for (i=0;i<=numCol;i++)
       for (j=0;j<=numCol;j++)
	   check[i][j]=0;
   i=x;j=y;
   do
   {
      gotoxy(i,j);
      ch=getch();
      switch (ch)
	  {
	case 0:
	 ch=getch();
	 switch(ch)
	 {
	    case 'K':   //Left
		      i-=spaceHorizon;
		      if (i<x) i=x+spaceHorizon*(numCol-1);
		      break;
	    case 'M':   //Right
		      i+=spaceHorizon;
		      if (i>x+spaceHorizon*(numCol-1)) i=x;
		      break;
	    case 'H':   //Up
		      j--;
		      if (j<y) j=y+numRow-1;
		      break;
		case 'P':   //Down
		      j++;
			  if (j>y+numRow-1) j=y;
		      break;
	 }
	 break;
       case 32:
	    temp=(i-x)/spaceHorizon;
	    check[temp][j-y]=!check[temp][j-y];
	    if (!check[temp][j-y])
	       putchar(' ');
	    else putchar('û');
	 break;
      }
   }
   while(ch!=27&&ch!=13&&ch!=9);
   temp=0;
   for (i=0;i<numRow;i++)
       for (j=0;j<numCol;j++)
	   if (check[i][j]) temp+=(int)pow(2,i*numCol+j);
   return temp;
}

unsigned offset(int x,int y)
{
	switch (peekb(0x0000,0x0449))
	{
		case 0:
		case 1:
		return 2*(x-1)+80*(y-1);
	}
	return 2*(x-1)+160*(y-1);
}

void SetAttr(int x1,int y1,int x2,int y2,byte attr)
{
	byte i,j;
	for(i=x1;i<=x2;i++)
	for(j=y1;j<=y2;j++)
		pokeb(0xb800,offset(i,j)+1,attr);
}

void ScrollUp(byte x1,byte y1,byte x2,byte y2,byte attr,byte numline)
{
	union REGS reg;
	reg.h.ah=6;
	reg.h.al=numline;
	reg.h.ch=y1;
	reg.h.cl=x1;
	reg.h.dh=y2;
	reg.h.dl=x2;
	reg.h.bh=attr;
	int86(0x10,&reg,&reg);
}

void ScrollDown(byte x1,byte y1,byte x2,byte y2,byte attr,byte numline)
{
	union REGS reg;
	reg.h.ah=7;
	reg.h.al=numline;
	reg.h.ch=y1;
	reg.h.cl=x1;
	reg.h.dh=y2;
	reg.h.dl=x2;
	reg.h.bh=attr;
	int86(0x10,&reg,&reg);
}

int Display(char **bufferfile,unsigned counter,byte x1,
		byte y1,byte x2,byte y2,byte attr,byte selectattr)
{
	unsigned numline,i,index=0,j,current=1;
	char ch;
	window(x1+1,y1+1,x2,y2);
	textattr(attr);
	if (counter<=y2-1-y1)
	{
		for (i=0;i<counter;i++)
		{
			gotoxy(1,i+1);
			cputs(bufferfile[i]);
		}
		ch=getch();
	}
	else
	{
		for (i=0;i<y2-y1-1;i++)
		{
			gotoxy(1,i+1);
			cputs(bufferfile[i]);
		}
		numline=y2-1-y1;
		gotoxy(1,current);
		textattr(selectattr);
		cputs(bufferfile[index]);
		textattr(attr);
		gotoxy(1,current);
		do
		{
			ch=getch();
			if (ch==0)
			{
				gotoxy(1,current);
				textattr(attr);
				cputs(bufferfile[index]);
				gotoxy(1,current);
				ch = getch();
				switch (ch)
				{
					case 'H': //Up
						if (index)
						{
							index--;
							if (wherey() == 1)
							{
								ScrollDown(x1,y1,x2-1,y2-2,attr,1);
								gotoxy(1,1);
								cputs(bufferfile[index]);
								gotoxy(1,1);
							}
							else
								current--;
						}
						break;
					case 'P': //Down
						if(index < (counter-1))
						{
							index++;
							if (wherey() == y2-y1-1)
							{
								ScrollUp(x1,y1,x2-1,y2-2,attr,1);
								gotoxy(1,y2-y1-1);
								cputs(bufferfile[index]);
							}
							else
								current++;
						}
						break;
					case 'I': //PgUp
						if(index)
							if (index>numline)
							{
								index-=numline;
								ScrollDown(x1,y1,x2-1,y2-2,attr,0);
								for (i=index;i<index+numline;i++)
								{
									gotoxy(1,i-index+1);
									cputs(bufferfile[i]);
								}
							}
						else
						{
							index=0;
							ScrollDown(x1,y1,x2-1,y2-2,attr,0);
							for (i=0;i<numline;i++)
							{
								gotoxy(1,i+1);
								cputs(bufferfile[i]);
							}
						}
						current=1;
						break;
					case 'Q':
						if(index == counter-1) break;
						if ((index+2*numline)<(counter))
						{
							index += numline;
							ScrollUp(x1,y1,x2-1,y2-2,attr,0);
							for (i=index;i<index+numline;i++)
							{
								gotoxy(1,i-index+1);
								cputs(bufferfile[i]);
							}
							current=1;
						}
						else
						{
							ScrollUp(x1,y1,x2-1,y2-2,attr,0);
							index = counter-1;
							j = 0;
							for (i=index-numline+1;i<counter;i++)
							{
								gotoxy(1,j+1);
								cputs(bufferfile[i]);
								j++;
							}
							current=y2-y1-1;
						}
						break;
				}
				gotoxy(1,current);
				textattr(selectattr);
				cputs(bufferfile[index]);
				textattr(attr);
				gotoxy(1,current);
			}
		}
		while (ch!=27&&ch!=13);
	}
	if(ch==27) return 0;
	return index+1;
}

int ViewFile(char *filename,byte x1,byte y1,
		 byte x2,byte y2,byte attr,byte selectattr)
{
	char **bufferfile,*tam;
	unsigned i,counter=0;
	FILE *fp;
	if ((fp=fopen(filename,"rt"))==NULL)
	{
		Message(25,10,55,13,"ERROR"," Can't Load File ");
		getch();
		return 0;
	}
	tam=(char *)malloc(x2-x1+1);
	hidecursor();
	while(!feof(fp))
	{
		fgets(tam,x2-x1,fp);
		counter++;
		if (!strcmp(tam,""))
			break;
	}
	free(tam);
	if (counter>=256)
	{
		Message(25,10,55,13,"ERROR","Not enough memory to view");
		getch();
		counter=255;
	}
	bufferfile=(char**)malloc((counter+1)*sizeof(char*));
	if (bufferfile==NULL)
	{
		Message(25,10,55,13,"ERROR" ,"Not enough memory");
		getch();
		fclose(fp);
		return 0;
	}
	for (i=0;i<=counter;i++)
	{
		bufferfile[i]=(char *)malloc(x2-x1+1);
		if (bufferfile[i]==NULL)
		{
			Message(25,10,55,13,"ERROR" ,"Not enough memory");
			getch();
			fclose(fp);
			return 0;
		}
	}
	rewind(fp);
	for (i=0;i<counter;i++)
	{
		if (!feof(fp))
		fgets(bufferfile[i],x2-x1,fp);
	}
	fclose(fp);
	int k;
	window(24,9,56,14);
	textattr(attr);
	clrscr();
	k=Display(bufferfile,counter,x1,y1,x2,y2,attr,selectattr);
	for (i=0;i<=counter;i++)
		free(bufferfile[i]);
	free(bufferfile);
	window(1,1,80,25);
	textattr(0x0f);
	clrscr();
	showcursor();
	return k;
}

int Viewtree1(char *filename,int Mode,byte attr,byte selectattr)
{
	char **bufferfile,*tam;
	byte x;
	if(Mode==LEFT)
		x=0;
	else
		x=40;

	unsigned i,counter=0;
	FILE *fp;
	if ((fp=fopen(filename,"rt"))==NULL)
	{
		Message(x+5,10,x+35,13,"ERROR"," Can't Load File ");
		getch();
		return 0;
	}
	hidecursor();
	tam=(char *)malloc(40);
	while(!feof(fp))
	{
		fgets(tam,38,fp);
		counter++;
		if (!strcmp(tam,""))
			break;
	}
	free(tam);

	bufferfile=(char**)malloc((counter+1)*sizeof(char*));
	if (bufferfile==NULL)
	{
		Message(x+5,10,x+35,13,"ERROR" ,"Not enough memory");
		getch();
		fclose(fp);
		return 0;
	}
	for (i=0;i<=counter;i++)
	{
		bufferfile[i]=(char *)malloc(39);
		if (bufferfile[i]==NULL)
		{
			Message(x+5,10,x+35,13,"ERROR" ,"Not enough memory");
			getch();
			counter = i-1;
			break;
		}
	}
	rewind(fp);
	for (i=0;i<counter;i++)
	{
		if (!feof(fp))
		fgets(bufferfile[i],38,fp);
	}
	fclose(fp);
	int k;
	window(x+4,9,x+36,14);
	textattr(attr);
	clrscr();
	k=Display(bufferfile,counter,x+1,4,39+x,22,attr,selectattr);
	for (i=0;i<=counter;i++)
		free(bufferfile[i]);
	free(bufferfile);
	window(1,1,80,25);
	textattr(0x0f);
	clrscr();
	showcursor();
	return k;
}


