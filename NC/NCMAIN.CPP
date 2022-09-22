#include "NCCall.hpp"

char    CurMode;

char	LMode  	,   RMode; 		//che do : BRIEF,FULL,INFO,TREE,QUICKVIEW

int		LDrive  	,   RDrive;			//o dia hien hanh
char 	LDir[256]	,	RDir[256]; 		//chuoi thu muc hien hanh
char    LExt[3]="*"	,	RExt[3]="*";	//phan mo rong hien hanh
char	LPath[256] 	,   RPath[256]; 	//Duong dan hien hanh


ffblk  far *LFileStr, 	far *RFileStr;	//chuoi file hien hanh
int	   LNum		    ,	RNum;			//so file
int		LNumDir		,	RNumDir;		//so thu muc
int		LStartPos   ,   RStartPos;
int		LCurPos		,	RCurPos;		//vi tri hien hanh

int	    LLeft=LLEFT 	,	RLeft=RLEFT;
int	LTop=LTOP 		,	RTop=RTOP;
int	LRight=LRIGHT 	,	RRight=RRIGHT;
int	LBottom=LBOTTOM ,	RBottom=RBOTTOM;

int	LNameWidth=13   ,	RNameWidth=13;
int	LSizeWidth=23   ,	RSizeWidth=23;
int	LDateWidth=32   ,	RDateWidth=32;

void main()
{

	char ch;

	textbackground(0);
	textcolor(15);
	window(1,1,80,25);
	clrscr();

	clrscr();
					/**************************/

	LDrive=RDrive=getdisk();
	setdisk(3);
	getcwd(LDir,256);
	getcwd(RDir,256);
	int len=strlen(LDir);
	if(LDir[len-1]=='\\')
		LDir[len-1]=0;

	len=strlen(RDir);
	if(RDir[len-1]=='\\')
		RDir[len-1]=0;
	sprintf(LPath,"%s\\*.%s",LDir,LExt);
	sprintf(RPath,"%s\\*.%s",RDir,RExt);
	getcwd(LDir,256);
	getcwd(RDir,256);

					/**************************/

	LFileStr=(ffblk far*)farmalloc(2000*sizeof(ffblk));
	if(LFileStr==NULL)
		exit(1);
	if(ScanDF(LPath,LNum,LNumDir,  LFileStr,Attr)!=0)
		exit(1);
	SortDF(LNum,LNumDir, LFileStr);
	LStartPos=0;
	LCurPos=0;

					/**************************/

	RFileStr=(ffblk far*)farmalloc(2000*sizeof(ffblk));
	if(RFileStr==NULL)
		exit(1);
	if(ScanDF(RPath,RNum,RNumDir,RFileStr,Attr)!=0)
		exit(1);
	SortDF(RNum,RNumDir,  RFileStr);
	RStartPos=0;
	RCurPos=0;

					/**************************/
	CurMode=LEFT;
	LMode=BRIEF;
	RMode=BRIEF;

	NCWindow(LEFT);
	NCWindow(RIGHT);
	Display(LEFT);
	Display(RIGHT);
	Display();
	DrawItem(LIGHTGREEN,LIGHTCYAN);
	textbackground(1);
	textcolor(14);
	gotoxy(1,25);
	cprintf("1 Help³2 User³3 View³4 Edit³5 Copy³6 ReMov³7 MkDir³8 Delete³9 PullDown³10 Quit");
	textbackground(0);
	textcolor(11);

	do
	{
		ch=getch();
		int t1, t2;
		if(ch==0)
		{
			ch=getch();
			switch(ch)
			{
				case 80:	//phim mui ten xuong
					DrawItem(BLUE,LIGHTCYAN);
					if(IncRow(1))
						Display();
					DrawItem(LIGHTGREEN,LIGHTCYAN);
					break;
				case 72:	//phim mui ten len
					if((CurMode==RIGHT)&&(RCurPos>500))	break;
					DrawItem(BLUE,LIGHTCYAN);
					if(IncRow(-1))
						Display();
					DrawItem(LIGHTGREEN,LIGHTCYAN);
					break;
				case 77:    //phim mui ten phai
					DrawItem(BLUE,LIGHTCYAN);
					if(IncRow(18))
						Display();
					DrawItem(LIGHTGREEN,LIGHTCYAN);
					break;
				case 75:    //phim mui ten trai
					DrawItem(BLUE,LIGHTCYAN);
					if(IncRow(-18))
						Display();
					DrawItem(LIGHTGREEN,LIGHTCYAN);
					break;
				case 81:    //phim PgDn
					DrawItem(BLUE,LIGHTCYAN);

					if(IncRow(53))
						Display();
					DrawItem(LIGHTGREEN,LIGHTCYAN);
					break;
				case 73:    //phim PgUp
					DrawItem(BLUE,LIGHTCYAN);
					if(IncRow(-53))
						Display();
					DrawItem(LIGHTGREEN,LIGHTCYAN);
					break;
				case 67: 	//phim F9
					char t=NCMenu();
					gotoxy(1,24);
					//printf("%d",t);
					switch(t)
					{
						case 28: 	//Thuoc tinh file
							showcursor();
							Attrib();
							Display();
							DrawItem(LIGHTGREEN,LIGHTCYAN);
							hidecursor();
							break;
						case 3:     //INFO

							t1=CurMode, t2;
							if(t1!=LEFT)
							{
								CurMode=LEFT;
								t2=LMode;
								if(t2!=TREE)
									LMode=INFO;
								Display();
								CurMode=t1;
								LMode=t2;
							}
							else
							{
								t2=LMode;
								if(t2!=TREE)
									LMode=INFO;
								Display();
								CurMode=t1;
								LMode=t2;
							}
							NCWindow(LEFT);
							NCWindow(RIGHT);
							Display(LEFT);
							Display(RIGHT);
							Display();
							DrawItem(LIGHTGREEN,LIGHTCYAN);
							break;
						case 4:		//LEFT TREE

							t1=CurMode, t2;
							if(t1!=LEFT)
							{
								CurMode=LEFT;
								t2=LMode;
								if(t2!=TREE)
									LMode=TREE;
								Display();
								CurMode=t1;
								LMode=t2;
							}
							else
							{
								t2=LMode;
								if(t2!=TREE)
									LMode=TREE;
								Display();
								CurMode=t1;
								LMode=t2;
							}
							NCWindow(LEFT);
							NCWindow(RIGHT);
							Display(LEFT);
							Display(RIGHT);
							Display();
							DrawItem(LIGHTGREEN,LIGHTCYAN);
							break;
						case 55:  //   INFO
							t1=CurMode, t2;
							if(t1!=RIGHT)
							{
								CurMode=RIGHT;
								t2=RMode;
								if(t2!=INFO)
									RMode=INFO;
								Display();
								CurMode=t1;
								RMode=t2;
							}
							else
							{
								t2=RMode;
								if(t2!=INFO)
									RMode=INFO;
								Display();
								CurMode=t1;
								RMode=t2;
							}
							NCWindow(LEFT);
							NCWindow(RIGHT);
							Display(LEFT);
							Display(RIGHT);
							Display();
							DrawItem(LIGHTGREEN,LIGHTCYAN);
							break;
						case 56:   //TREE
							t1=CurMode, t2;
							if(t1!=RIGHT)
							{
								CurMode=RIGHT;
								t2=RMode;
								if(t2!=TREE)
									RMode=TREE;
								Display();
								CurMode=t1;
								RMode=t2;
							}
							else
							{
								t2=RMode;
								if(t2!=TREE)
									RMode=TREE;
								Display();
								CurMode=t1;
								RMode=t2;
							}
							NCWindow(LEFT);
							NCWindow(RIGHT);
							Display(LEFT);
							Display(RIGHT);
							Display();
							DrawItem(LIGHTGREEN,LIGHTCYAN);
							break;
						case 34:   //copy disk
							copydiskette();
							NCWindow(LEFT);
							NCWindow(RIGHT);
							Display(LEFT);
							Display(RIGHT);
							Display();
							DrawItem(LIGHTGREEN,LIGHTCYAN);
							break;
						case 35:	//format disk
							formatdiskette();
							NCWindow(LEFT);
							NCWindow(RIGHT);
							Display(LEFT);
							Display(RIGHT);
							Display();
							DrawItem(LIGHTGREEN,LIGHTCYAN);
							break;
						case 36:   //label
							label();
							NCWindow(LEFT);
							NCWindow(RIGHT);
							Display(LEFT);
							Display(RIGHT);
							Display();
							DrawItem(LIGHTGREEN,LIGHTCYAN);
							break;
					}
					break;
				case 68:   	//phim F10
					goto end;
				case 61:	//phim F3
					View();
					hidecursor();
					Display();
					DrawItem(LIGHTGREEN,LIGHTCYAN);
					break;
				case 62:	//phim F4
					Edit();
					hidecursor();
					Display();
					DrawItem(LIGHTGREEN,LIGHTCYAN);
					break;
				case 63:    //phim F5
					if(Copy())
					{
						if(CurMode==LEFT)
						{
							RStartPos=RCurPos=0;
							Display(RIGHT);
						}
						else
						{
							LStartPos=LCurPos=0;
							Display(LEFT);
						}
					}
					DrawItem(LIGHTGREEN,LIGHTCYAN);
					break;
				case 64:	//phim F6
					if(Rename())
					{
						LCurPos=LStartPos=0;
						RCurPos=RStartPos=0;
						Display(LEFT);
						Display(RIGHT);
					}
					DrawItem(LIGHTGREEN,LIGHTCYAN);
					break;
				case 65:	//phim F7
					if(MakeDir())
					{
						LCurPos=LStartPos=0;
						RCurPos=RStartPos=0;
						Display(LEFT);
						Display(RIGHT);
					}
					DrawItem(LIGHTGREEN,LIGHTCYAN);
					break;
				case 66:	//phim F8
					if(Delete())
					{
						LCurPos=LStartPos=0;
						RCurPos=RStartPos=0;
						Display(LEFT);
						Display(RIGHT);
					}
					DrawItem(LIGHTGREEN,LIGHTCYAN);
					break;
				case 104:	//phim Alt-F1
					t1=CurMode;
					drive(LEFT);
					if(ScanDF(LPath,LNum,LNumDir,  LFileStr,Attr)!=0)
						exit(1);
					SortDF(LNum,LNumDir, LFileStr);
					LStartPos=0;
					LCurPos=0;
					CurMode=LEFT;
					Display();

					CurMode=t1;
					Display();
					DrawItem(LIGHTGREEN,LIGHTCYAN);

					if(CurMode==RIGHT)
					{
						setdisk(RDrive);
						chdir(RDir);
					}

					break;
				case 105:	//phim Alt-F2
					t2=CurMode;
					drive(RIGHT);
					if(ScanDF(RPath,RNum,RNumDir,  RFileStr,Attr)!=0)
						exit(1);
					SortDF(RNum,RNumDir, RFileStr);
					RStartPos=0;
					RCurPos=0;
					CurMode=RIGHT;
					Display();

					CurMode=t2;
					Display();
					DrawItem(LIGHTGREEN,LIGHTCYAN);
					if(CurMode==LEFT)
					{
						setdisk(LDrive);
						chdir(LDir);
					}
					break;
			}
		}
		else
		{
			switch(ch)
			{
				case 13:
					ChangeDir();
					break;
				case 27:
					break;
				case 9:
					DrawItem(BLUE,LIGHTCYAN);
					if(CurMode==RIGHT)
					{
						CurMode=LEFT;
						setdisk(LDrive);
						chdir(LDir);
					}
					else
					{
						CurMode=RIGHT;
						setdisk(RDrive);
						chdir(RDir);
					}
					Display();
					DrawItem(LIGHTGREEN,LIGHTCYAN);
					break;


			}
		}
	}	while(1);
end:
	textbackground(0);
	textcolor(15);
	window(1,1,80,25);
	clrscr();
	farfree(LFileStr);
	farfree(RFileStr);
}