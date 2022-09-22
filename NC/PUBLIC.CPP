#include "Public.hpp"
//#include "Mouse.hpp"
void border(int left,int top,int right,int bottom)
{
	int height = bottom-top,
	width = right-left+1 ;
	textbackground(7);
	textcolor(6);
	window(left,top,right,bottom);
	clrscr();
	for(int i=2;i<width;i++)
	{
		gotoxy(i,2);
		cprintf("Ä");
		gotoxy(i,height);
		cprintf("Ä");
	}
	for(i=3;i<height;i++)
	{
		gotoxy(1,i);
		cprintf("³");
		gotoxy(width,i);
		cprintf("³");
	}
	gotoxy(1,2);
	cprintf("Ú");
	gotoxy(1,height);
	cprintf("À");
	gotoxy(width,2);
	cprintf("¿");
	gotoxy(width,height);
	cprintf("Ù");
}

void border2(int left,int top,int right,int bottom,int bkColor,int Color)
{
	window(1,1,80,25);
	textbackground(bkColor);
	textcolor(Color);
	for(int i=left+1;i<right;i++)
	{
		gotoxy(i,top);
		cprintf("Ä");
		gotoxy(i,bottom);
		cprintf("Ä");
	}
	for(i=top+1;i<bottom;i++)
	{
		gotoxy(left,i);
		cprintf("³");
		gotoxy(right,i);
		cprintf("³");
	}
	gotoxy(left,top);
	cprintf("Ú");
	gotoxy(left,bottom);
	cprintf("À");
	gotoxy(right,top);
	cprintf("¿");
	gotoxy(right,bottom);
	cprintf("Ù");
	window(left+1,top+1,right-1,bottom-1);
	clrscr();
}

void Message(int x1,int y1,int x2, int y2, char *s1,char *s2)
{
	int temp1=strlen(s1),
	temp2= strlen(s2);
	border2(x1,y1,x2,y2,RED,WHITE);
	textcolor(14);
	gotoxy((x2-x1)/2-temp1/2,1);
	cprintf("%s",s1);
	gotoxy((x2-x1)/2-temp2/2,2);
	cprintf("%s",s2);
	window(1,1,80,24);
	gotoxy(1,1);
}

void hidecursor()
{
	union REGS reg;
	reg.h.ah=1;
	reg.h.ch=0x20;
	reg.h.cl=1;
	int86(0x10,&reg,&reg);
}

void showcursor()
{
	union REGS reg;
	reg.h.ah=1;
	reg.h.ch=0x0d;
	reg.h.cl=0x0e;
	int86(0x10,&reg,&reg);
}

template <class X> void Swap(X &a,X &b)
{
	X t;
	t=a;
	a=b;
	b=t;
}

int Round(float x)
{
	double t;
	t=floor(x);
	if(x-t>=0.5)	t=t+1;
	return (int)t;
}
void Creat_Arg(char*s, char ch, int &num_arg, char* arg[])
{
	int begin,end,i,j,k;

	end=strlen(s)-1;
	if (end==-1)
		exit(1);
	while ((s[end]==ch)&&(end>-1))
		end--;
	if(end==-1) return;

	begin=0;
	num_arg=0;
	do
	{
		while (s[begin]==ch)
			begin++;
		i=begin+1;
		k=1;
		while ((s[i]!=ch)&&(i<end+1))
		{
			k++;
			i++;
		}
		strncpy(arg[num_arg],s+begin,k);
		arg[num_arg][k]=0;
		num_arg++;
		begin=i;
	} while (begin<end+1);
}

int Printf(char *s, int n)
{
	char *p;
	if(n<1)
		return -1;
	int ret,len;
	if(n>(len=strlen(s)))
		n=len;
	p=(char*)malloc(n+1);
	memcpy(p,s,n);
	p[n]=0;
	ret=printf("%s",p);
	free(p);
	return ret;
}

