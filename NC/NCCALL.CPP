#include "NCCall.hpp"

extern int edit();
int Copy()
{
	char *p, s[256];
	int ret=FALSE;
	p=(char*)malloc(4000);
	switch(CurMode)
	{
		case LEFT:
			if((LMode==TREE)||(LMode==INFO)||(LMode==QUICKVIEW))
				return ret;
			gettext(1,1,80,25,p);
			sprintf(s,"%s",RDir);
			if(Copy(LFileStr[LCurPos].ff_name,RDir))
			{
				InsertDF(RNum,RNumDir,LFileStr[LCurPos],RFileStr);
				ret=TRUE;
			}

			sprintf(RDir,"%s",s);
			puttext(1,1,80,25,p);
			break;
		case RIGHT:
			if((RMode==TREE)||(RMode==INFO)||(RMode==QUICKVIEW))
				return ret;
			gettext(1,1,80,25,p);
			sprintf(s,"%s",LDir);
			if(Copy(RFileStr[RCurPos].ff_name,LDir))
			{
				InsertDF(LNum,LNumDir,RFileStr[RCurPos],LFileStr);
				ret=TRUE;
			}

			sprintf(LDir,"%s",s);
			puttext(1,1,80,25,p);
			break;

	}
	free(p);
	return ret;
}
int Rename()
{
	char *p, s1[256], s2[256];
	int ret=FALSE;
	p=(char*)malloc(4000);
	switch(CurMode)
	{
		case LEFT:
			if((LMode==TREE)||(LMode==INFO)||(LMode==QUICKVIEW))
				return ret;
			gettext(1,1,80,25,p);
			sprintf(s1,"%s",RDir);
			sprintf(s2,"%s",LDir);
			if(Rename(LFileStr[LCurPos].ff_name,RDir))
			{
				InsertDF(RNum,RNumDir,LFileStr[LCurPos],RFileStr);
				if(ScanDF(LPath,LNum,LNumDir,LFileStr,Attr)!=0)
					exit(1);
				SortDF(LNum,LNumDir,  LFileStr);
				ret=TRUE;
			}

			sprintf(RDir,"%s",s1);
			sprintf(LDir,"%s",s2);
			puttext(1,1,80,25,p);
			break;
		case RIGHT:
			if((RMode==TREE)||(RMode==INFO)||(RMode==QUICKVIEW))
				return ret;
			gettext(1,1,80,25,p);
			sprintf(s1,"%s",LDir);
			sprintf(s2,"%s",RDir);
			if(Rename(RFileStr[LCurPos].ff_name,LDir))
			{
				InsertDF(LNum,LNumDir,RFileStr[RCurPos],LFileStr);
				if(ScanDF(RPath,RNum,RNumDir,RFileStr,Attr)!=0)
					exit(1);
				SortDF(RNum,RNumDir,  RFileStr);
				ret=TRUE;
			}

			sprintf(LDir,"%s",s1);
			sprintf(RDir,"%s",s2);
			puttext(1,1,80,25,p);
			break;

	}
	free(p);
	return ret;

}
int MakeDir()
{
	char *p, s[256];
	int ret=FALSE;
	p=(char*)malloc(4000);
	switch(CurMode)
	{
		case LEFT:
			if((LMode==TREE)||(LMode==INFO)||(LMode==QUICKVIEW))
				return ret;
			gettext(1,1,80,25,p);
			sprintf(s,"%s",LDir);
			if(MakeDir(LFileStr[LCurPos].ff_name))
			{
				if(ScanDF(LPath,LNum,LNumDir,LFileStr,Attr)!=0)
					exit(1);
				SortDF(LNum,LNumDir,  LFileStr);
				ret=TRUE;
			}
			sprintf(LDir,"%s",s);
			if(!strcmp(LDir,RDir))
			{
				if(ScanDF(RPath,RNum,RNumDir,RFileStr,Attr)!=0)
					exit(1);
				SortDF(RNum,RNumDir,  RFileStr);
			}

			puttext(1,1,80,25,p);
			break;
		case RIGHT:
			if((RMode==TREE)||(RMode==INFO)||(RMode==QUICKVIEW))
				return ret;
			gettext(1,1,80,25,p);
			sprintf(s,"%s",RDir);
			if(MakeDir(RFileStr[RCurPos].ff_name))
			{
				if(ScanDF(RPath,RNum,RNumDir,RFileStr,Attr)!=0)
					exit(1);
				SortDF(RNum,RNumDir,  RFileStr);
				ret=TRUE;
			}
			sprintf(RDir,"%s",s);
			if(!strcmp(LDir,RDir))
			{
				if(ScanDF(LPath,LNum,LNumDir,LFileStr,Attr)!=0)
					exit(1);
				SortDF(LNum,LNumDir,  LFileStr);
			}
			puttext(1,1,80,25,p);
			break;
	}
	free(p);
	return ret;

}
int Delete()
{
	char *p, s[256];
	int ret=FALSE;
	p=(char*)malloc(4000);
	switch(CurMode)
	{
		case LEFT:
			if((LMode==TREE)||(LMode==INFO)||(LMode==QUICKVIEW))
				return ret;
			gettext(1,1,80,25,p);
			sprintf(s,"%s",LDir);
			if(Erase(LFileStr[LCurPos].ff_name))
			{
				if(ScanDF(LPath,LNum,LNumDir,LFileStr,Attr)!=0)
					exit(1);
				SortDF(LNum,LNumDir,  LFileStr);
				ret=TRUE;
			}
			sprintf(LDir,"%s",s);
			if(!strcmp(LDir,RDir))
			{
				if(ScanDF(RPath,RNum,RNumDir,RFileStr,Attr)!=0)
					exit(1);
				SortDF(RNum,RNumDir,  RFileStr);
			}

			puttext(1,1,80,25,p);
			break;
		case RIGHT:
			if((RMode==TREE)||(RMode==INFO)||(RMode==QUICKVIEW))
				return ret;
			gettext(1,1,80,25,p);
			sprintf(s,"%s",RDir);
			if(Erase(RFileStr[RCurPos].ff_name))
			{
				if(ScanDF(RPath,RNum,RNumDir,RFileStr,Attr)!=0)
					exit(1);
				SortDF(RNum,RNumDir,  RFileStr);
				ret=TRUE;
			}
			sprintf(RDir,"%s",s);
			if(!strcmp(LDir,RDir))
			{
				if(ScanDF(LPath,LNum,LNumDir,LFileStr,Attr)!=0)
					exit(1);
				SortDF(LNum,LNumDir,  LFileStr);
			}
			puttext(1,1,80,25,p);
			break;
	}
	free(p);
	return ret;
}

int Attrib()
{
	char *p, s[256];
	int ret=FALSE;
	p=(char*)malloc(4000);
	switch(CurMode)
	{
		case LEFT:
			if((LMode==TREE)||(LMode==INFO)||(LMode==QUICKVIEW))
				return ret;
			gettext(1,1,80,25,p);
			sprintf(s,"%s",LDir);
			if(Attrib(LFileStr[LCurPos].ff_name))
			{
				//InsertDF(RNum,RNumDir,LFileStr[LCurPos],RFileStr);
				if(ScanDF(LPath,LNum,LNumDir,LFileStr,Attr)!=0)
					exit(1);
				SortDF(LNum,LNumDir,  LFileStr);
				ret=TRUE;
			}

			sprintf(LDir,"%s",s);
			puttext(1,1,80,25,p);
			break;
		case RIGHT:
			if((RMode==TREE)||(RMode==INFO)||(RMode==QUICKVIEW))
				return ret;
			gettext(1,1,80,25,p);
			sprintf(s,"%s",RDir);
			if(Attrib(RFileStr[RCurPos].ff_name))
			{
				//InsertDF(LNum,LNumDir,RFileStr[RCurPos],LFileStr);
				if(ScanDF(RPath,RNum,RNumDir,RFileStr,Attr)!=0)
					exit(1);
				SortDF(RNum,RNumDir,  RFileStr);
				ret=TRUE;
			}

			sprintf(RDir,"%s",s);
			puttext(1,1,80,25,p);
			break;

	}
	free(p);
	return ret;

}
void DrawItem(int x, int y, char ground_color, char text_color, int name_width, ffblk f,char mode)
{
	switch(mode)
	{
		case BRIEF:
			if(!strcmp(f.ff_name,".."))
			{
				textbackground(ground_color);
				textcolor(text_color);
				gotoxy(x,y);
				cprintf("            ");
				gotoxy(x,y);
				cprintf("..");
				return;
			}
			int num_arg,i;
			char *arg[2];
			for(i=0;i<2;i++)
				arg[i]=(char*)malloc(14);

			Creat_Arg(f.ff_name,'.',num_arg,arg);
			if(f.ff_attrib&FA_DIREC)
				for(i=0;i<num_arg;i++)
					strupr(arg[i]);
			else
			{
				for(i=0;i<num_arg;i++)
					strlwr(arg[i]);
				if(f.ff_attrib&FA_HIDDEN)
					if(islower(arg[0][0]))
						arg[0][0]-=32;
			}

			textbackground(ground_color);
			textcolor(text_color);
			gotoxy(x,y);
			cprintf("            ");
			gotoxy(x,y);
			cprintf("%s",arg[0]);


			if(num_arg>1)
			{
				gotoxy(x+name_width-4,y);
				cprintf("%s",arg[1]);
			}
			if(f.ff_attrib&FA_HIDDEN)
			{
				gotoxy(x+name_width-5,y);
				cprintf("°");
			}
			for(i=0;i<2;i++)
				free(arg[i]);
			break;
		case FULL:
			break;
		case INFO:
			break;
		case TREE:
			break;
		case QUICKVIEW:
			break;
	}
}
void DrawItem(char ground_color, char text_color)
{
	int left,top,right,bottom;
	int name_width;
	int pos;
	char mode;
	ffblk	f;
	int x,y;
	switch(CurMode)
	{
		case LEFT:
			if(LCurPos>=LNum)
				exit(1);
			left=LLeft;
			top=LTop;
			right=LRight;
			bottom=LBottom;
			name_width=LNameWidth;
			pos=LCurPos-LStartPos;
			f=LFileStr[LCurPos];
			mode=LMode;
			break;
		case RIGHT:
			if(RCurPos>=RNum)
				exit(1);
			left=RLeft;
			top=RTop;
			right=RRight;
			bottom=RBottom;
			name_width=RNameWidth;
			pos=RCurPos-RStartPos;
			f=RFileStr[RCurPos];
			mode=RMode;
			break;
	}

	int d=bottom-5,k=0;
	if(pos>=d)
	k++;
	if(pos>=2*d)
		k++;

	x=left+1+k*name_width;
	y=top+pos+2-18*k;
	DrawItem(x,y,ground_color,text_color,name_width,f,mode);
}
void Display(int Mode)
{
	int i,k;
	int left,top,right,bottom;
	int Num;
	int name_width;
	int StartPos;
	char mode;
	ffblk far*FileStr;
	//FileStr=(ffblk far*)farmalloc(2000*sizeof(ffblk));
	char count;
	int	pos;
	//NCWindow(Mode);

	switch(Mode)
	{
		case LEFT:
			if(LNum==0)
				exit(1);
			left=LLeft;
			right=LRight;
			top=LTop;
			bottom=LBottom;
			name_width=LNameWidth;
			Num=LNum;
			FileStr=LFileStr;
			StartPos=LStartPos;
			mode=LMode;
			chdir(LDir);
			break;
		case RIGHT:
			if(RNum==0)
				exit(1);
			left=RLeft;
			right=RRight;
			top=RTop;
			bottom=RBottom;
			name_width=RNameWidth;
			Num=RNum;
			StartPos=RStartPos;
			FileStr=RFileStr;
			mode=RMode;
			chdir(RDir);
			break;
	}
	switch(mode)
	{
		case BRIEF:
			k=0;
			int d=LBottom-5; //d==18
			for(i=0;(i<=53)&&(StartPos+i<Num);i++)
			{
				if(i==d)
					k++;
				if(i==2*d)
					k++;
				DrawItem(left+1+k*name_width,top+i+2-18*k,BLUE,LIGHTCYAN,name_width,FileStr[i+StartPos],mode);
			}
			textbackground(BLUE);
			textcolor(BLUE);

			while(i<=53)
			{
				if(i==d)
					k++;
				if(i==2*d)
					k++;
				gotoxy(left+1+k*name_width,top+i+2-18*k);
				cprintf("            ");
				i++;
			}

			break;

		case FULL:
			break;
		case INFO:

			if(Mode==LEFT)
			{
				NCWindow(RIGHT);
				Info(RIGHT,LDrive);
			}
			else
			{
				NCWindow(LEFT);
				Info(LEFT,RDrive);
			}
			break;
		case TREE:
			if(Mode==LEFT)
			{
				NCWindow(RIGHT);
				Tree(RIGHT,LDir);
			}
			else
			{
				NCWindow(LEFT);
				Tree(LEFT,RDir);
			}
			break;
		case QUICKVIEW:
			break;

	}
	//farfree(FileStr);
}
void Display()
{
	char mode1,mode2,Mode;
	char *Dir1,*Dir2;
	int Left1,Right1,Top1,Left2,Right2,Top2;
	switch(CurMode)
	{
		case LEFT:
			Mode=LEFT;
			mode1=RMode;mode2=LMode;
			Dir1=RDir;Dir2=LDir;
			Left1=RLeft;Left2=LLeft;
			Right1=RRight;Right2=LRight;
			Top1=RTop;Top2=LTop;
			//chdir(LDir);
			break;
		case RIGHT:
			Mode=RIGHT;
			mode1=LMode;mode2=RMode;
			Dir1=LDir;Dir2=RDir;
			Left1=LLeft;Left2=RLeft;
			Right1=LRight;Right2=RRight;
			Top1=LTop;Top2=RTop;
			//chdir(RDir);
			break;
	}

	textbackground(BLUE);
	textcolor(LIGHTCYAN);
	if((mode1==BRIEF)||(mode1==FULL))
	{
		gotoxy(Left1+(Right1-Left1)/2-strlen(Dir1)/2,Top1);
		cprintf(" %s ",Dir1);
	}
	gotoxy(Left1+16,Top1);
	switch(mode1)
	{
		case INFO:
			cprintf(" Info ");
			break;
		case TREE:
			cprintf(" Tree ");
			break;
		case QUICKVIEW:
			cprintf(" View ");
			break;
	}


	textcolor(LIGHTCYAN);
	textbackground(BLUE);
	for(int i=Left2+1;i<=Right2-1;i++)
	{
		gotoxy(i,Top2);
		cprintf("Í");
	}

	textbackground(LIGHTGREEN);
	if((mode2==BRIEF)||(mode2==FULL))
	{
		gotoxy(Left2+(Right2-Left2)/2-strlen(Dir2)/2,Top2);
		cprintf(" %s ",Dir2);
	}
	gotoxy(Left2+16,Top2);
	switch(mode2)
	{
		case INFO:
			cprintf(" Info ");
			break;
		case TREE:
			cprintf(" Tree ");
			break;
		case QUICKVIEW:
			cprintf(" View ");
			break;
	}

	Display(Mode);

	textbackground(BLUE);
	textcolor(YELLOW);
}
char IncRow(int inc)
{
	int pos,CurPos,StartPos,Num;
	char ret;
	char mode;
	char k;
	ret=FALSE;

	switch(CurMode)
	{
		case LEFT:
			CurPos=LCurPos;
			StartPos=LStartPos;
			pos=CurPos-StartPos;
			Num=LNum;
			mode=LMode;
			break;
		case RIGHT:
			CurPos=RCurPos;
			StartPos=RStartPos;
			pos=CurPos-StartPos;
			Num=RNum;
			mode=RMode;
			break;
	}
	if((mode!=BRIEF)&&(mode!=FULL))
		return ret;
	if(Num==0)
		return ret;
	if(mode==BRIEF)
		k=53;
	else
		k=18;
	switch(inc)
	{
		case 1:

			if(StartPos+1>=Num)
			{
				CurPos=Num-1;
				break;
			}
			else
				if(pos+1<=k)
				{
					CurPos+=1;
					if(CurPos>=Num)
						CurPos=Num-1;
				}
				else
				{
					ret=TRUE;
					StartPos+=1;
					if(StartPos+k>=Num)
						StartPos=Num-1-k;
					CurPos=StartPos+k;
				}
			break;
		case -1:
			if(pos>0)
				CurPos--;
			else
			{
				ret=TRUE;
				StartPos--;
				if(StartPos<0)
					StartPos=0;
				CurPos=StartPos;
			}
			break;
		case 53:
			if(StartPos+k>=Num)
			{
				CurPos=Num-1;
				break;
			}
			ret=TRUE;
			StartPos+=k;
			CurPos=StartPos;
			break;
		case -53:
			if(StartPos-k<0)
			{
				StartPos=0;
				CurPos=0;
				ret=TRUE;
				break;
			}
			ret=TRUE;
			StartPos-=k;
			if(StartPos<0)
				StartPos=0;
			CurPos=StartPos;
			break;
		case 18:
			if(StartPos+18>=Num)
			{
				CurPos=Num-1;
				break;
			}
			if(pos+18<=53)
			{
				CurPos+=18;
				if(CurPos>=Num)
					CurPos=Num-1;
				break;
			}
			ret=TRUE;
			StartPos+=18;
			CurPos=StartPos;
			break;
		case -18:
			if(pos-18>0)
				CurPos-=18;
			else
			{   /*
				if(StartPos-18<0)
				{
					StartPos=0;
					CurPos=0;
					ret=TRUE;
					break;
				}
				*/
				ret=TRUE;
				StartPos-=18;
				if(StartPos<0)
					StartPos=0;
				CurPos=StartPos;
			}
			break;

	}

	switch(CurMode)
	{
		case LEFT:
			LCurPos=CurPos;
			LStartPos=StartPos;
			break;
		case RIGHT:
			RCurPos=CurPos;
			RStartPos=StartPos;
			break;
	}

	return ret;
}
void NCWindow(char Mode)
{
	char mode;
	int NameWidth,SizeWidth,DateWidth,TimeWidth;
	switch(Mode)
	{
		case LEFT:
			mode=LMode;
			NameWidth=LNameWidth;
			SizeWidth=LSizeWidth;
			DateWidth=LDateWidth;
			break;
		case RIGHT:
			mode=RMode;
			NameWidth=RNameWidth;
			SizeWidth=RSizeWidth;
			DateWidth=RDateWidth;
			break;
	}
	switch(mode)
	{
		case BRIEF:
			NCWindow(Mode,mode,NameWidth,2*NameWidth);
			break;
		case FULL:
			NCWindow(Mode,mode,NameWidth,SizeWidth,DateWidth);
			break;
		case INFO:
			NCWindow(Mode,mode);
			break;
		case TREE:
			NCWindow(Mode,mode);
			break;
		case QUICKVIEW:
			NCWindow(Mode,mode);
			break;
	}

}

void ChangeDir()
{
	char s[256];
	int len;
	switch(CurMode)
	{
		case LEFT:
			if(LFileStr[LCurPos].ff_attrib&FA_DIREC)
			{
				len=strlen(LDir);
				if(LDir[len-1]=='\\')
					sprintf(s,"%s%s",LDir,LFileStr[LCurPos].ff_name);
				else
					sprintf(s,"%s\\%s",LDir,LFileStr[LCurPos].ff_name);
				chdir(s);
				getcwd(LDir,256);
				len=strlen(LDir);
				if(LDir[len-1]=='\\')
					sprintf(LPath,"%s*.%s",LDir,LExt);
				else
					sprintf(LPath,"%s\\*.%s",LDir,LExt);

				if(ScanDF(LPath,LNum,LNumDir,  LFileStr,Attr)!=0)
					exit(1);
				SortDF(LNum,LNumDir, LFileStr);
				LStartPos=0;
				LCurPos=0;

				Display();
				DrawItem(LIGHTGREEN,LIGHTCYAN);
			}
			break;
		case RIGHT:
			if(RFileStr[RCurPos].ff_attrib&FA_DIREC)
			{
				len=strlen(RDir);
				if(RDir[len-1]=='\\')
					sprintf(s,"%s%s",RDir,RFileStr[RCurPos].ff_name);
				else
					sprintf(s,"%s\\%s",RDir,RFileStr[RCurPos].ff_name);
				chdir(s);
				getcwd(RDir,256);
				len=strlen(RDir);
				if(RDir[len-1]=='\\')
					sprintf(RPath,"%s*.%s",RDir,RExt);
				else
					sprintf(RPath,"%s\\*.%s",RDir,RExt);

				if(ScanDF(RPath,RNum,RNumDir,  RFileStr,Attr)!=0)
					exit(1);
				SortDF(RNum,RNumDir, RFileStr);
				RStartPos=0;
				RCurPos=0;

				Display();
				DrawItem(LIGHTGREEN,LIGHTCYAN);
			}
			break;
	}
}

void View()
{
	char *p;
	p=(char *)malloc(4000);
	gettext(1,1,80,25,p);
	window(1,1,80,25);
	clrscr();
	SetAttr(1,1,80,25,0x4e);
	gotoxy(1,25);
	SetAttr(2,3,79,23,0x1f);
	textattr(0x4b);
	cprintf("Press a key : Up / Down / PgUp / PgDn to view , \
		ESC / Enter to quit");
	if (CurMode==LEFT)
	{
		gotoxy(1,1);
		textattr(0x4e);
		cprintf("Guide commander ÄÄ View File :%s \n\r",
		   LFileStr[LCurPos].ff_name);
		border2(1,2,80,24,BLUE,WHITE);
		ViewFile(LFileStr[LCurPos].ff_name,
				   2,2,79,24,0x1f,0x1f);
	}
	else
	{
		gotoxy(1,1);
		textattr(0x4e);
		cprintf("Guide commander ÄÄ View File :%s \n\r",
		   RFileStr[RCurPos].ff_name);
		border2(1,2,80,24,BLUE,WHITE);
		ViewFile(RFileStr[RCurPos].ff_name,
				   2,2,79,24,0x1f,0x1f);
	}
	window(1,1,80,25);
	clrscr();
	puttext(1,1,80,25,p);
	free(p);
}

void Edit()
{
	char *p;
	p=(char *)malloc(4000);
	gettext(1,1,80,25,p);
	edit();
	window(1,1,80,25);
	clrscr();
	puttext(1,1,80,25,p);
	free(p);
}
