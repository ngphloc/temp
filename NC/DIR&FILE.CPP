#include "Dir&File.hpp"
static char *s;

//MD
void md(int num_arg,char *argl[])
{
	if (num_arg==1)
		 cprintf("Required Parameters Missing \n\r");
	if (num_arg>2)
		 cprintf("Too Many Parameters \n\r");
	if (num_arg==2)
		 if (mkdir(argl[1]))
			cprintf("Bad Command or Filename \n\r");
	return;
}

//RD
void rd(int num_arg,char *argl[])
{
	if (num_arg==1)
		cprintf("Required Parameters Missing \n\r");
	if (num_arg>2)
		 cprintf("Too Many Parameters \n\r");
	if (num_arg==2)
		if (rmdir(argl[1]))
			cprintf("Bad Command or Filename \n\r");
	return;
}

//CD
void cd(int num_arg,char *argl[])
{
	if (num_arg==1)
		cprintf("Required Parameters Missing \n\r");
	if (num_arg>2)
		 cprintf("Too Many Parameters \n\r");
	if (num_arg==2)
		if (chdir(argl[1]))
			cprintf("Bad Command or Filename \n\r");
	return;
}

//REN
void ren(int num_arg,char *argl[])
{
	if (num_arg==1)
		cprintf("Required Parameters Missing \n\r");
	if (num_arg==2)
		cprintf("Too Few Parameters \n\r");
	if (num_arg>3)
		cprintf("Too Many Parameters \n\r");
	if (num_arg==3)
		if (rename(argl[1],argl[2]))
			cprintf("Bad Command or Filename \n\r");
	return;
}

//DEL
int erase(char *d)
{
	char dd[80] , ddd[80],dtemp[80]="";
	for (int i=strlen(d);i>0;i--)
		if (*(d+i)=='\\')
		{
			 strncpy(d,dtemp,i+1);
			break;
		}
	int first = 1,
	attr=(FA_RDONLY|FA_HIDDEN|FA_SYSTEM|FA_DIREC|FA_ARCH);
	uattrib atf;
	struct ffblk f;
	char *s;

	int k ;
	while(1)
	{
		if(first)
		{
			k = findfirst(d,&f,attr);
			first = !first;
		}
		else k = findnext(&f);
		if ( k!=0 ) break;
			if (f.ff_name[0]=='.') continue;
				atf.attr=f.ff_attrib;
			if ( atf.a.d==0)
			{
				 sprintf(dd,"%s%s",dtemp,f.ff_name);
				 if (remove(dd))
					 return 0;
			}
	}
	first=!first;
	s=(char *)malloc(80*sizeof(char));
	while(1)
	{
		sprintf(dd ,"%s\\*.*" ,d) ;
		if(first)
		{
			k = findfirst(dd,&f,attr);
			first = !first;
		}
		else k = findnext(&f);
		if ( k!=0 ) break;
		if (f.ff_name[0]=='.') continue;
		if ((f.ff_attrib>=0x10&&f.ff_attrib<0x20)
			   ||f.ff_attrib>=0x30)
		{
			sprintf(ddd ,"%s\\%s" ,d ,f.ff_name);
			if (!erase(ddd))
			{
				free(s);
				return 0;
			}
		}
		else
		{
			sprintf(ddd ,"%s\\%s" ,d ,f.ff_name);
			if (remove(ddd)) return 0;
		}
	}
	free(s) ;

	k = findfirst(d,&f,0X10);
	if (k) return 1;
	atf.attr=f.ff_attrib;
	if (atf.a.d==1)
		if (rmdir(d)) return 0;
	return 1;
}

void del(int num_arg,char *argl[])
{
	if (num_arg==1)
		cprintf("Required Parameters Missing \n\r");
	if (num_arg>2)
		cprintf("Too Many Parameters \n\r");
	if (num_arg==2)
		if (!erase(argl[1]))
			cprintf("Bad Command or Filename \n\r");
	return;
}

//TYPE
void type(int num_arg,char *argl[])
{
	FILE *f;
	char c;

	if (num_arg==1)
		cprintf("Required Parameters Missing \n\r");
	if (num_arg>2)
		cprintf("Too Many Parameters \n\r");
	if (num_arg==2)
	{
		if ((f=fopen(argl[1],"rb"))==NULL)
			cprintf("Bad Command or Filename \n\r");
		else
		{
			while(!feof(f))
			{
				c=fgetc(f);
				cprintf("%c",c);
			}
			fclose(f);
		}
	}
	return;
}

//DATE

void date(int num_arg,char *argl[])
{
	struct date d;

	if (num_arg>1)
		cprintf("Required Parameters Missing \n\r");
	else
	{
		s=(char*)malloc(10);
		getdate(&d);
		cprintf("\n\rThe current date is: %d:%d:%d\n\r",d.da_mon,d.da_day,d.da_year);
		cprintf("Enter new date ( mm/dd/yy ):");
		gets(s);
		d.da_mon=atoi(s);
		d.da_day=atoi(s+3);
		d.da_year=atoi(s+6);
		setdate(&d);
		free(s);
	}
	return;
}

//TIME
void time(int num_arg,char *argl[])
{
	struct time t;
	if(num_arg>1)
		cprintf("Required Parameters Missing \n\r");
	else
	{
		s=(char*)malloc(10);
		gettime(&t);
		cprintf("The current date is: %d:%d:%d:%d\n\r",t.ti_hour,t.ti_min,t.ti_sec,t.ti_hund);
		cprintf("Enter new time ( hh:mm:ss ) : ");
		gets(s);
		t.ti_hour=atoi(s);
		t.ti_min=atoi(s+3);
		t.ti_sec=atoi(s+6);
		settime(&t);
		free(s);
	}
	return;
}

//DIR
int sf , nn ;
struct ffblk f ;
void dir(int num_arg,char *argl[])
{
	if (num_arg==1)
		cprintf("Required Parameters Missing \n\r");
	if (num_arg>2)
		cprintf("Too Many Parameters \n\r");
	if (num_arg == 2)
		if (!scandir(argl[1]))
			cprintf("File not found !!!");
	return;
}

int scandir(char *dd)
{
	int first = 1,k,sf=0;
	char *s;
	s=(char*)malloc(128);
	uattrib atf;
	sprintf(s ,"%s\\*.*" ,dd);
	strupr(dd);
	cprintf("\n\r\n\r%s" , dd) ;
	unsigned char attr=FA_DIREC;
	while(1)
	{
		if(first)
		{
			k = findfirst(s,&f,attr);
			first = 0 ;
		}
		else k = findnext(&f);
		if( k!=0 ) break;
			if(f.ff_name[0]=='.')continue;
				sf++;
		atf.attr=f.ff_attrib;
		if (atf.a.d==1)
			cprintf("\n\r   %-12s      <DIR> ",f.ff_name);
		if (sf%23==0)
			getch();
	}
	attr=FA_RDONLY+FA_HIDDEN+FA_SYSTEM+FA_ARCH; //+FA_LABEL
	first =1;
	while(1)
	{
		if(first)
		{
			k = findfirst(s,&f,attr);
			first = 0 ;
		}
		else k = findnext(&f);
		if ( k!=0 ) break;
			if (f.ff_name[0]=='.')continue;
				sf++;
		strlwr(f.ff_name);
		cprintf("\n\r   %-12s %15ld",f.ff_name,f.ff_fsize);
		if (sf%23==0)
			getch();
	}
	free(s);
	return sf;
}

//TREE

void tree(int num_arg,char *argl[])
{
	if (num_arg==1)
		cprintf("Required Parameters Missing \n\r");
	if (num_arg>2)
		cprintf("Too Many Parameters \n\r");
	if (num_arg == 2)
	{
		memset(blank, 0, sizeof(blank));
		memset(info, 0, sizeof(info));
		FILE *filetemp;
		if ((filetemp=fopen("treetemp.txt","wb"))==NULL)
			return ;
		fprintf(filetemp,"%s",argl[1]);
		if (!scantree(argl[1],1,filetemp))
		{
			cprintf("Bad command or filename !!!");
			fclose(filetemp);
		}
		else
		{
			fclose(filetemp);
			ViewFile("treetemp.txt",2,3,79,24,0x0f,0x0f);
			remove("treetemp.txt");
		}
	}
	return;
}

int scantree(char path[MAXPATH],int deft,FILE *filetemp)
{
	struct ffblk ffblk, fft;
	int done;
	uattrib atfb,atft;
	char tmp[MAXPATH];
	strcpy(tmp, path);
	if (tmp[strlen(path)-1]=='\\')
		strcat(tmp, "*.*");
	else
		strcat(tmp, "\\*.*");
	fseek(filetemp,0,SEEK_END);
	done = findfirst(tmp, &ffblk, FA_DIREC);
	done = findnext(&ffblk);	// bo qua thu muc .
	done = findnext(&ffblk);     // bo qua thu muc ..
	if (done) return 0;
	while (!done)
	{
		fft = ffblk;
		atft.attr=fft.ff_attrib;
		do
		{
			done = findnext(&ffblk);
			atfb.attr=ffblk.ff_attrib;
		}
		while (!done && (atfb.a.d != 1));

		if (atft.a.d  == 1)
		{
			memset(blank,' ', sizeof(blank));
			for (i=0;i<deft;i++)
				if (info[i])
					blank[i*4-2] = '³';
			i = deft*4-2;
			if (!done && (atfb.a.d  == 1))
			{
				blank[i] = 'Ã';
				blank[i+1] = 'Ä';
				info[deft] = 1;
			}
			else
			{
				blank[i] = 'À';
				blank[i+1] = 'Ä';
				info[deft] = 0;
			}
			blank[i+2] = 0;		// ket thuc chuoi
			strcat(blank, fft.ff_name);
			fprintf(filetemp,"\n%s",blank);
			strcpy(tmp, path);
			if (tmp[strlen(path)-1]=='\\')
				strcat(tmp, fft.ff_name);
			else
			{
				strcat(tmp, "\\");
				strcat(tmp, fft.ff_name);
			}
			scantree(tmp,deft+1,filetemp);
		}
	}
	return 1;
}

//COPY
void copy(int num_arg,char *argl[])
{
	if((num_arg==1)||(num_arg==2))
		cprintf("Required Parameters Missing \n\r");
	if (num_arg>3)
		cprintf("Too Many Parameters \n\r");
	if (num_arg==3)
	{
		cprintf("\n\rLoading file !!! Wait... ");
		if (!copydir(argl[1],argl[2]))
			cprintf("\rBad command or filename  ");
	}
	return;
}

//COPYFILE
int copyfile(char *filename1,char *filename2)
{
	FILE *f1,*f2;
	char c;

	if ((f1=fopen(filename1,"rb"))==NULL)
	return 0;
		if ((f2=fopen(filename2,"wb"))==NULL)
			return 0;
		c = fgetc(f1);
	while(!feof(f1))
	{
		fputc(c,f2);
		c = fgetc(f1);
	}
	fclose(f1);
	fclose(f2);
	return 1;
}

int copydir(char *dirname1,char *dirname2)
{
	char *dd1 , *ddd1,*dd2,*ddd2 ;
	int first = 1 ,
	attr=(FA_RDONLY|FA_HIDDEN|FA_SYSTEM|FA_LABEL|FA_DIREC|FA_ARCH);
	struct ffblk f;
	char *s;
	int k;
	for (int j=strlen(dirname1)-1;j>0;j--)
		if (dirname1[j] =='\\'||dirname1[j] =='/') break;

	k=findfirst(dirname2,&f,attr);
	if (!k)
		if ((f.ff_attrib>=0x10&&f.ff_attrib<0x20)
				  ||f.ff_attrib>=0x30)
		if (dirname1[j]=='\\'||dirname1[j] =='/')
			strcat(dirname2,dirname1+j);
		else
		{
			strcat(dirname2,"\\");
			strcat(dirname2,dirname1+j);
		}

	k = findfirst(dirname1,&f,attr);
	if (k) return 0;
	if (f.ff_attrib<0x10||((f.ff_attrib<0x30)
				   &&(f.ff_attrib>=0x20)))
		if (!copyfile(dirname1,dirname2)) return 0;
		else  return 1;
	else if (mkdir(dirname2)) return 0;

	s=(char *)malloc(80*sizeof(char));
	ddd1=(char *)malloc(80*sizeof(char));
	ddd2=(char *)malloc(80*sizeof(char));
	dd1=(char *)malloc(80*sizeof(char));
	dd2=(char *)malloc(80*sizeof(char));

	while(1)
	{
		sprintf(dd1,"%s\\*.*",dirname1) ;
		sprintf(dd2,"%s\\*.*",dirname2) ;
		if (first)
		{
			k = findfirst(dd1,&f,attr);
			first = 0 ;
		}
		else k = findnext(&f);
		if ( k!=0 ) break;
		if (f.ff_name[0]=='.') continue;
		if ((f.ff_attrib>=0x10&&f.ff_attrib<0x20)
			   ||f.ff_attrib>=0x30)
		{
			sprintf(ddd1 ,"%s\\%s" ,dirname1,f.ff_name);
			sprintf(ddd2 ,"%s\\%s" ,dirname2,f.ff_name);
			if (!copydir(ddd1,ddd2))
			{
				free(s);
				free(ddd1);free(ddd2);
				free(dd1); free(dd2);
				return 0;
			}
		}
		else
		{
			sprintf(ddd1 ,"%s\\%s" ,dirname1,f.ff_name);
			sprintf(ddd2 ,"%s\\%s" ,dirname2,f.ff_name);
			if (!copyfile(ddd1,ddd2))
			{
				free(s);
				free(ddd1);free(ddd2);
				free(dd1); free(dd2);
				return 0;
			}
		}
	}
	free(s) ;
	free(ddd1);free(ddd2);
	free(dd1); free(dd2);
	return 1;
}

int splitfile(char*filename,char*filename1,char*filename2)
{
	FILE *f,*f2;
	char c;

	if (!copyfile(filename1,filename))
	{
		Message(20,8,60,12,"ERROR","file can't be openned !!!");
		getch();
		return 0;
	}

	if ((f = fopen(filename,"w+b"))==NULL)
	{
		Message(25,10,55,15,"ERROR","File can't be splitted");
		getch();
		return 0;
	}

	if ((f2 = fopen(filename2,"rb"))==NULL)
	{
		Message(25,10,55,15,"ERROR","File can't be openned");
		getch();
		return 0;
	}

	while(!feof(f2))
	{
		c=fgetc(f2);
		fputc(c,f);
	}
	fclose(f2);
	fclose(f);
	return 1;
}

int mergefile(char*filename, int num_arg,char *file[])
{
	int n,temp=0;
	FILE *f,*fm;
	char c;
	if ((f = fopen(filename,"wb"))==NULL)
	{
		Message(25,10,55,15,"ERROR","File can't be openned");
		getch();
		return 0;
	}

	fseek(f,0,SEEK_END);
	n=ftell(f)/num_arg;
	rewind(f);
	for (int i=0;i<num_arg;i++)
	{
		temp=0;
		if ((fm = fopen(file[i],"wb"))==NULL)
		{
			Message(25,10,55,15,"ERROR","File can't be created");
			getch();
			return 0;
		}
		while(temp<n&&feof(f))
		{
			c=fgetc(f);
			fputc(c,fm);
			temp++;
		}
		fclose(fm);
	}
	fclose(f);
	return 1;
}

int attrib(char *path,byte attrib,byte funtion)
{
	union REGS reg;
	struct SREGS sreg;
	reg.h.ah=0x43;
	reg.h.al=funtion;
	reg.x.cx=attrib;
	reg.x.dx=FP_OFF(path);
	sreg.ds=FP_SEG(path);
	intdosx(&reg,&reg,&sreg);
	if (funtion)
		return (reg.x.ax);
	else
		return (reg.x.cx);
}


char *Ok[2] = {
			"OK",
			 "Cancel"
		  };
int OutputString(int x1,int y1,int x2,int y2,char *s1)
{
   textattr(0x0f);
   window(x1,y1,x2,y2);
   clrscr();
   cputs(s1);
   char ch=getch();
   switch(ch)
   {
	  case 27: return 27;
	  case 13: return 13;
	  case 9: return 9;
	  default : return 10;
   }
}

int Copy(char *s1, char *s2)
{
	char *buf1,*buf2,ch;
	int i=0,j=0;
	int ret=FALSE;
	buf1=(char*)malloc(80);
	buf1[0]=78;
	buf2=(char*)malloc(80);
	buf2[0]=78;
	border(15,5,65,15);
	textcolor(1);
	gotoxy(24,1);
		cprintf("COPY");
	gotoxy(1,11);
		cprintf("Copy file or directory from source to dest !!!");
	gotoxy(3,3);
		cprintf("Source :");
	gotoxy(3,5);
		cprintf("Destination :");

	textbackground(1);
	textcolor(11);
	gotoxy(28,8);
	cprintf(" Cancel ");

	textbackground(4);
	textcolor(14);
	gotoxy(18,8);
	cprintf("®OK¯");

	textbackground(0);
	window(17,10,63,10);
	clrscr();
	cputs(s2);

	Input :
	i=OutputString(17,8,63,8,s1);
	switch (i)
	{
	  case 27: textattr(0x0b);
			window(1,1,80,25);
			clrscr();
		   free(buf1);free(buf2);
		   return ret;
	  case 13: i=0;
		   break;
	  case 9:
		   j=OutputString(17,10,63,10,s2);
		   break;
	  case 10:
		   clrscr();
		   s1=cgets(buf1);
		   j=OutputString(17,10,63,10,s2);
		   break;
	}
	if (i)
	   switch (j)
	   {
		case 27:
			textattr(0x0b);
			window(1,1,80,25);
			clrscr();
			free(buf1);free(buf2);
			return ret;
		case 13: i=0;
			  break;
		case 9:
			   i=mnuHorizontal(27,12,2,Ok);
			   break;
		case 10:
			   clrscr();
			   s2=cgets(buf2);
			   i=mnuHorizontal(27,12,2,Ok);
			   break;
	   }
	switch (i)
	{
	 case 0:
		 if (!copydir(s1,s2))
			Message(25,10,55,13,"ERROR","File can't be copied !");
		 else
		 {
			Message(25,10,55,13,"SUCCESS","Copy finished !!!");
			ret =TRUE;
		 }
		 getch();
		 break;
	 case 100:
	 case 15: goto Input;
	 default: break;
	}
	free(buf1);
	free(buf2);
	window(1,1,80,25);
	clrscr();
	return ret;
}

int Erase(char *s1)
{
	char *buf1;
	int i=0;
	int ret=FALSE;
	buf1=(char*)malloc(50);
	buf1[0]=48;
	border(15,5,65,12);
	textcolor(1);
	gotoxy(23,1);
	cprintf("DELETE");
	gotoxy(1,8);
	cprintf("Erase file or directory");
	gotoxy(3,3);
	cprintf("File name will be deleted:");

	textattr(0x1b);
	gotoxy(28,6);
	 cprintf(" Cancel ");
	textattr(0x4E);
	gotoxy(18,6);
	 cprintf("®OK¯");

	Input:
	i=OutputString(17,8,63,8,s1);
	switch (i)
	{
	  case 27: textattr(0x0b);
			window(1,1,80,25);
			clrscr();
		   free(buf1);
		   return ret;
	  case 13: i=0;
		   break;
	  case 9:
		   i=mnuHorizontal(27,10,2,Ok);
		   break;
	  case 10:
		   clrscr();
		   s1=cgets(buf1);
		   i=mnuHorizontal(27,10,2,Ok);
		   break;
	}
	switch (i)
	{
	  case 0:
		  if (!erase(s1))
			  Message(25,10,55,13,"ERROR","File can't be deleted !!!");
		  else
		  {
			  Message(25,10,55,13,"SUCCESS","File was deleted !!!");
			  ret=TRUE;
		  }
		  getch();
		  break;
	  case 100:
	  case 15: goto Input;
	  default: break;
	}
	free(buf1);
	//FREE
	textattr(0x0b);
	window(1,1,80,25);
	clrscr();
	return ret;
}

//***************************************************

int Attrib(char *s1)
{
	char *buf1;
	int ret=FALSE;
	buf1=(char*)malloc(50);
	buf1[0]=48;
	border(15,5,65,15);
	textcolor(1);
	gotoxy(23,1);
	cprintf("ATTRIB");
	gotoxy(1,11);
	cprintf("Set attributes to file or directory !!!");
	gotoxy(3,3);
	cprintf("File name will be set :");
	gotoxy(2,5);
	cprintf("ÄÄÄÄÄÄAttrib will be setÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
	gotoxy(5,6);
	cprintf("[ ] Read only         [ ] Hidden");
	gotoxy(5,7);
	cprintf("[ ] System            [ ] Archive");
	gotoxy(2,8);
	cprintf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");

	textattr(0x1b);
	gotoxy(28,9);
	cprintf(" Cancel ");
	textattr(0x4E);
	gotoxy(18,9);
	cprintf("®OK¯");

	int i=0,j=0;
	Input:
	i=OutputString(17,8,63,8,s1);
	switch (i)
	{
		case 27: textattr(0x0b);
			window(1,1,80,25);
			clrscr();
			free(buf1);
			return ret;
		case 13: i=0;
			break;
		case 9:
			j=mnuOption(20,10,2,2,22);
			i=mnuHorizontal(27,13,2,Ok);
			break;
		case 10:
			clrscr();
			s1=cgets(buf1);
			j=mnuOption(20,10,2,2,22);
			i=mnuHorizontal(27,13,2,Ok);
			break;
	}
	if (j>=8) j+=24;

	switch (i)
	{
		case 0:
			if (!attrib(s1,j,1))
				Message(20,10,60,13,"ERROR","Can't be set attrib to file !");
			else
			{
				Message(25,10,55,13,"SUCCESS","File was set attrib !!!");
				ret=TRUE;
			}
			getch();
			break;
		case 100:
		case 15: goto Input;
		default: break;
	}
	free(buf1);
	textbackground(0);
	textcolor(11);
	window(1,1,80,25);
	clrscr();
	return ret;
}

//***************************************************

int Rename(char *s1, char *s2)
{
	char *buf1,*buf2;
	int ret=FALSE;
	buf1=(char*)malloc(50);
	buf2=(char*)malloc(50);
	buf1[0]=48;buf2[0]=48;
	border(15,5,65,15);

	textcolor(1);
	gotoxy(20,1);
	cprintf("RENAME OR MOVE");
	gotoxy(1,11);
	cprintf("Ren/move file or directory from source to dest !!!");
	gotoxy(3,3);
	cprintf("Source :");
	gotoxy(3,5);
	cprintf("Destination :");

	textattr(0x1b);
	gotoxy(28,8);
	cprintf(" Cancel ");
	textattr(0x4e);
	gotoxy(18,8);
	cprintf("®OK¯");

	textattr(0x0f);
	window(17,10,63,10);
	clrscr();
	cputs(s2);
	int i=0,j=0;

	Input :
	i=OutputString(17,8,63,8,s1);
	switch (i)
	{
		case 27:
			textattr(0x0b);
			window(1,1,80,25);
			clrscr();
			free(buf1);free(buf2);
			return ret;
		case 13: i=0;
			break;
		case 9:
			j=OutputString(17,10,63,10,s2);
			break;
		case 10:
			clrscr();
			s1=cgets(buf1);
			j=OutputString(17,10,63,10,s2);
			break;
	}
	if (i)
		switch (j)
		{
			case 27:
				textattr(0x0b);
				window(1,1,80,25);
				clrscr();
				free(buf1);free(buf2);
				return ret;
			case 13: i=0;
				break;
			case 9:
				i=mnuHorizontal(27,12,2,Ok);
				break;
			case 10:
				clrscr();
				s2=cgets(buf2);
				i=mnuHorizontal(27,12,2,Ok);
				break;
		}
	switch (i)
	{
		case 0:
			if (rename(s1,s2))
				Message(20,10,60,13,"ERROR","File can't be renamed or moved !!!");
			else
			{
				Message(20,10,60,13,"SUCCESS","Rename and Move finished !!!");
				ret=TRUE;
			}
			getch();
			break;
		case 15:
		case 100: goto Input;
		default: break;
	}
	free(buf1);
	free(buf2);
	textattr(0x0b);
	window(1,1,80,25);
	clrscr();
	return ret;
}

//***************************************************

int MakeDir(char *s1)
{
	char *buf1;
	int ret=FALSE;
	buf1=(char*)malloc(50);
	buf1[0]=48;

	border(15,5,65,12);
	textcolor(1);
	gotoxy(20,1);
	cprintf("MAKE DIRECTORY");
	gotoxy(1,8);
	cprintf("Make a new directory !!!");
	gotoxy(3,3);
	cprintf("Directory will be made :");

	textattr(0x1b);
	gotoxy(28,6);
	cprintf(" Cancel ");
	textattr(0x4e);
	gotoxy(18,6);
	cprintf("®OK¯");
	textbackground(0);

	int i=0;
	Input:
	i=OutputString(17,8,63,8,s1);
	switch (i)
	{
		case 27:
			textattr(0x0b);
			window(1,1,80,25);
			clrscr();
			free(buf1);
			return ret;
		case 13: i=0;
			break;
		case 9:
			i=mnuHorizontal(27,10,2,Ok);
			break;
		case 10:
			clrscr();
			s1=cgets(buf1);
			i=mnuHorizontal(27,10,2,Ok);
			break;
	}
	switch (i)
	{
		case 0:
			if (mkdir(s1))
				Message(25,10,55,13,"ERROR","Directory can't be made !!!");
			else
			{
				Message(25,10,55,13,"SUCCESS","Directory was made !!!");
				ret=TRUE;
			}
			getch();
			break;
		case 100:
		case 15: goto Input;
		default: break;
	}

	free(buf1);
	textattr(0x0b);
	window(1,1,80,25);
	clrscr();
	return ret;
}

char pathtemp[64];
word extenmemorysize()
{
	byte hi,lo;
	asm mov al,17h
	asm out 70h,al
	asm nop
	asm in al,71h
	asm mov hi,al
	asm mov al,18h
	asm out 70h,al
	asm nop
	asm in al,71h
	asm mov lo,al
	return (word)hi*256+lo;
}

word basememorysize()
{
	byte hi,lo;
	asm mov al,15h
	asm out 70h,al
	asm nop
	asm in al,71h
	asm mov hi,al
	asm mov al,16h
	asm out 70h,al
	asm nop
	asm in al,71h
	asm mov lo,al
	return (word)hi*256+lo;
}

void Info(int Mode, int drive)
{
	union REGS reg;
	int n;
	if(Mode==LEFT)
		n=0;
	else
		n=40 ;
	window(n+1,1,40+n,23);
	clrscr();
	border2(1+n,1,40+n,23,BLUE,WHITE);
	reg.h.ah=0x36;
	reg.h.dl=drive+1;
	int86(0x21,&reg,&reg);
	bootsector buf;
	strcpy(buf.volumelabel," ");
	absread(drive,1,0,&buf);
	unsigned long ax= reg.x.ax,
	bx= reg.x.bx,
	cx= reg.x.cx,
	dx= reg.x.dx;
	unsigned long Total=ax*cx*dx,
	   Free=ax*cx*bx;
	if(ax==0xFFFF)
	{
		Message(5+n,10,35+n,13,
			  "Error","Can't read disk");
		getch();
		return;
	}
	word lo=buf.serialnumber&0xffff,
	   hi=buf.serialnumber/256/256;
	cprintf("         Diskete Information\n\r\
		\n\r      Base memory %u Byte\
		\n\r      Extended memory %u KB\
		\n\r Total byte in disk: %lu\
		\n\r Free byte in disk : %lu",basememorysize(),
			extenmemorysize(),Total,Free);
	cprintf("\n\rÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
	printf("   Volume Label : %-11s",buf.volumelabel);
	cprintf("\n\r   Serial number : %X-%X",hi,lo);
	cprintf("\n\rÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");

	int i,Num;
	char *Dir;
	if(Mode==LEFT)
	{
		i=strlen(LDir);
		Num=LNum;
		strcpy(Dir,LDir);
	}
	else
	{
		i=strlen(RDir);
		Num=RNum;
		strcpy(Dir,RDir);
	}
	if (i>38)
		 printf("%d file or directory on %s",Num,Dir);
	else
		 printf("%d file or directory on %s",Num,Dir);
	cprintf("\n\rÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");

  getch();
}

void Tree(int Mode,char *dir)
{
	int n;
	if(Mode==LEFT)
		n=0;
	else
		n=40;
	window(n+1,1,40+n,23);
	clrscr();
	char *tempf;
	tempf=(char*)malloc(80*sizeof(char));
	sprintf(tempf,"%s\\treetemp.txt",pathtemp);
	border2(1+n,1,40+n,23,BLUE,WHITE);
	cprintf("                Tree");
	cprintf("\n\r    ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
	gotoxy(1,20);
	cprintf("\r     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
	Message(5+n,10,35+n,13,"Finding And Counting" ,"Wait ...");
	memset(blank, 0, sizeof(blank));
	memset(info, 0, sizeof(info));
	FILE *filetemp;
	if ((filetemp=fopen(tempf,"wt"))==NULL)
	{
		free(tempf);
		return ;
	}
	fprintf(filetemp,"%s",dir);
	if (!scantree(dir,1,filetemp))
	{
		Message(5+n,10,35+n,13,
			  "Error","Can't read disk");
		fclose(filetemp);
	}
	else
	{
		fclose(filetemp);
		Viewtree1(tempf,Mode,0x1f,0x1f);
	}
	free(tempf);
	window(1,1,80,25);
	clrscr();
	return;
}

void drive(int Mode)
{
	byte i,x,set=0; //a,b
	char *p;
	p=(char *)malloc(4000);
	gettext(1,1,80,25,p);

	char ch[2];
	ch[1]='\0';
	if(Mode==LEFT) x=0;
	else	x=40;
	static char *diskete[26]={" "," "," "," "," "," "," "," "," "," "," "," "
		" "," "," "," "," "," "," "," "," "," "," "," "," "," "};
	int k,d=getdisk();
	for (k = 0;k < 26;++k)
	{
		setdisk(k);
		if (k == getdisk())
		{
			ch[0]= k + 'A';
			strcpy(diskete[set],ch);
			set++;
		}
	}
	setdisk(d);
	if (set<=2) i=mnuHorizontal2(x+5,10,10,set,diskete);
	else
		i=mnuHorizontal2(x+5,10,3,set,diskete);
	if (i<26)
	{
		i=diskete[i][0] - 'A';
		setdisk(i);
	}
	if(Mode==LEFT)
	{
		LDrive=getdisk();
		getcwd(LDir,256);
		int len=strlen(LDir);
		if(LDir[len-1]=='\\')
			LDir[len-1]=0;

		sprintf(LPath,"%s\\*.%s",LDir,LExt);
		getcwd(LDir,256);
	}
	else
	{
		RDrive=getdisk();
		getcwd(RDir,256);
		int len=strlen(RDir);
		if(RDir[len-1]=='\\')
			RDir[len-1]=0;

		sprintf(RPath,"%s\\*.%s",RDir,RExt);
		getcwd(RDir,256);
	}
	puttext(1,1,80,25,p);
	free(p);
}


int Scan(char *d, int &num, ffblk far* p, int attrib)
{
	char dd[30];
	int check, first=1;
	struct ffblk f;

	num=0;

	while(1)
	{
		if(first)
		{
			check=findfirst(d,&f,Attr);
			first=0;
		}
		else
			check=findnext(&f);
		if(check!=0)
			return 0;
		if((f.ff_name[0]=='.')&&(f.ff_name[1]!='.'))
			continue;

		if((f.ff_attrib&attrib))
		{
			p[num]=f;
			num++;
		}

	}
	if(num==0)
		return -1;
	else
		return 0;
}


int ScanDF(char *d,int &num, int &num_dir, ffblk  far* p, int attrib)
{
	ffblk far*temp;
	int ret,i,j;
	temp=(ffblk far*)farmalloc(2000*sizeof(ffblk));
	ret=Scan(d,num,temp,attrib);
	num_dir=0;

	for(i=0;i<num;i++)
	{
		if((temp[i].ff_attrib&FA_DIREC))
		{
			p[num_dir]=temp[i];
			num_dir++;
		}
	}

	ret=Scan(d,num,temp,attrib);
	j=num_dir;
	for(i=0;i<num;i++)
		if(!(temp[i].ff_attrib&FA_DIREC))
		{
			p[j]=temp[i];
			j++;
		}

	farfree(temp);
	return ret;
}
void CreatDF(int num, int &num_dir, ffblk far*pin, ffblk far*pout)
{
	int i,j;
	num_dir=0;
	for(i=0;i<num;i++)
	{
		if((pin[i].ff_attrib&FA_DIREC))
		{
			pout[num_dir]=pin[i];
			num_dir++;
		}
	}

	j=num_dir;
	for(i=0;i<num;i++)
		if(!(pin[i].ff_attrib&FA_DIREC))
		{
			pout[j]=pin[i];
			j++;
		}
}


void SortDF(int num, int num_dir, ffblk far *p)
{
	int i,j;
	ffblk x;
	for (i=1;i<num_dir;i++)
	{
		x=p[i];j=i;
		while((j>0)&&(strcmpi((const char*) p[j-1].ff_name,x.ff_name) >0))
		{
			p[j]=p[j-1];
			j--;
		}
		p[j]=x;
	}

	for (i=num_dir+1;i<num;i++)
	{
		x=p[i];j=i;
		while((j>num_dir)&&(strcmpi((char*)p[j-1].ff_name,x.ff_name) >0))
		{
			p[j]=p[j-1];
			j--;
		}
		p[j]=x;
	}
}
void AppendDF(int &num, int &num_dir, ffblk f, ffblk far* p)
{
	int j;
	ffblk x;
	p[num]=f;
	if(f.ff_attrib&FA_DIREC)
	{
		x=p[num];j=num;
		while((j>0)&&(!(p[j-1].ff_attrib&FA_DIREC)))
		{
			p[j]=p[j-1];
			j--;
		}
		p[j]=x;
		num_dir++;
	}
	num++;
}
void InsertDF(int &num, int &num_dir, ffblk f, ffblk far*p)
{
	int j;
	ffblk x;
	p[num]=f;
	if(f.ff_attrib&FA_DIREC)
	{
		x=p[num];j=num;
		while((j>0)&&(!(p[j-1].ff_attrib&FA_DIREC)))
		{
			p[j]=p[j-1];
			j--;
		}
		p[j]=x;

		x=p[j];
		while((j>0)&&(strcmpi((char*)p[j-1].ff_name,x.ff_name) >0))
		{
			p[j]=p[j-1];
			j--;
		}
		p[j]=x;
		num_dir++;
	}
	else
	{
		x=p[num];j=num;
		while((j>num_dir)&&(strcmpi((char*)p[j-1].ff_name,x.ff_name) >0))
		{
			p[j]=p[j-1];
			j--;
		}
		p[j]=x;
	}

	num++;
}

