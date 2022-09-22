#ifndef _MOUSE_CPP
#define _MOUSE_CPP
#include "Mouse.hpp"
extern "C"
{
	//CAC BIEN TOAN CUC

	int sline,scol;
	BYTE mavail=FALSE,flag=TEXT;

	PTRVIEW stdptr=MouPtrMask(PTRSAMECHAR,PTRINVCOL);

	BYTE *bufz,nmb_zones=0;

	TEXTZONE *zone_act_text;
	GRAPHZONE *zone_act_graph;
	unsigned long  blen;

	BYTE mouzon=AUCUNE_ZONE;
	int moucol,mourow,pre_moucol,pre_mourow;
	int  mouevent=0x0000,pre_mouevent=0x0000;//=EV_LEFT_REL | EV_RIGHT_REL |  EV_MID_REL;

	BYTE ev_zon;
	int ev_col,ev_row;

	int const Graph_Left=5,Graph_Right=5;

	//DINH NGHIA HAM

//*************************************************************************//

	int   MouGetCol()			{return ev_col;}
	int   MouGetRow()			{return ev_row;}
	BYTE  MouGetZone()		    {return ev_zon;}
	BYTE  MouAvail()			{return mavail;}

	int   MouGetActCol()		{return moucol;}
	int   MouGetActRow()		{return mourow;}
	int   MouGetPreActCol()		{return pre_moucol;}
	int   MouGetPreActRow()		{return pre_mourow;}
	BYTE  MouGetActZon()		{return mouzon;}

	int   MouIsLeftPress()	    {return (mouevent & EV_LEFT_PRESS);}
	int   MouIsLeftRel()		{return (mouevent & EV_LEFT_REL);}
	int   MouIsRightPress()	    {return (mouevent & EV_RIGHT_PRESS);}
	int   MouIsRightRel()		{return (mouevent & EV_RIGHT_REL);}
	int   MouIsMidPress()       {return (mouevent & EV_MID_PRESS);}
	int   MouIsMidRel()         {return (mouevent & EV_MID_REL);}

	int   MouIsPreLeftPress()	{return (pre_mouevent & EV_LEFT_PRESS);}
	int   MouIsPreLeftRel()		{return (pre_mouevent & EV_LEFT_REL);}
	int   MouIsPreRightPress()	{return (pre_mouevent & EV_RIGHT_PRESS);}
	int   MouIsPreRightRel()	{return (pre_mouevent & EV_RIGHT_REL);}
	int   MouIsPreMidPress()    {return (pre_mouevent & EV_MID_PRESS);}
	int   MouIsPreMidRel()      {return (pre_mouevent & EV_MID_REL);}

	void  MouSetMoveAreaAll()	{MouSetMoveArea(0, 0, scol-1, sline-1);}

//*************************************************************************//

	#pragma  check_stack(off)
	void MouDefineTextPtr(PTRVIEW mask)
	{
		if(flag==TEXT)
		{
			static PTRVIEW  anciencursor=(PTRVIEW) 0;
			union REGS regs;
			if(anciencursor!=mask)
			{
				regs.x.ax=0x000a;
				regs.x.bx=0;
				regs.x.cx=mask;
				regs.x.dx=mask>>16;
				MOUINT(regs,regs);
				anciencursor=mask;
			}
		}
	}

//*************************************************************************//

	void MouDefineGraphPtr(int left, int right, char table[8][8])
	{
		REGS regs;
		SREGS sregs;
		regs.x.ax=0x0009;
		regs.x.bx=left;
		regs.x.cx=right;
		sregs.es=FP_SEG(table);
		regs.x.dx=FP_OFF(table);
		MOUINTX(regs,regs,sregs);
	}

//*************************************************************************//

	void MouSetLightPen()
	{
		REGS regs;
		regs.x.ax=0x000d;
		MOUINT(regs,regs);
	}

//*************************************************************************//

	void MouRemoveLightPen()
	{
		REGS regs;
		regs.x.ax=0x000e;
		MOUINT(regs,regs);
	}

//*************************************************************************//

	REGS MouGetMouseType()
	{
		REGS regs;
		regs.x.ax=0x0024;
		MOUINT(regs,regs);
		return regs;
	}

//*************************************************************************//

	void MouSetThresh(int threshold)
	{
		REGS regs;
		regs.x.ax=0x0013;
		regs.x.dx=threshold;
		MOUINT(regs,regs);
	}

//*************************************************************************//

	void MouSetPage(int page)
	{
		REGS regs;
		regs.x.ax=0x001d;
		regs.x.bx=page;
		MOUINT(regs,regs);
	}

//*************************************************************************//

	int MouGetPage()
	{
		REGS regs;
		regs.x.ax=0x001e;
		MOUINT(regs,regs);
		return regs.x.bx;
	}

//*************************************************************************//

	void  MouEventHandler(int EvFlags,int ButState,int x,int y)
	{
		#define  LBITS  (EV_LEFT_PRESS | EV_LEFT_REL)
		#define  RBITS  (EV_RIGHT_PRESS | EV_RIGHT_REL)
		#define  MBITS  (EV_MID_PRESS   | EV_MID_REL)
		unsigned  nouzon;

		pre_mouevent=mouevent;
		mouevent &= (~1);
		mouevent |= (EvFlags&1);

		if (EvFlags & LBITS)
		{
			mouevent &= (~LBITS);
			mouevent |= (EvFlags & LBITS);
		}

		if (EvFlags & RBITS)
		{
			mouevent &= (~RBITS);
			mouevent |= (EvFlags & RBITS);
		}

		if (EvFlags & MBITS)
		{
			mouevent &= (~MBITS);
			mouevent |= (EvFlags & MBITS);
		}

		pre_moucol=moucol;
		pre_mourow=mourow;
		if (flag==TEXT)
		{
			moucol=XTOCOLTEXT(x);
			mourow=YTOROWTEXT(y);
			nouzon=*(bufz+mourow*scol+moucol);

			if(nouzon!=mouzon)
				MouDefineTextPtr((nouzon==AUCUNE_ZONE)? stdptr : (zone_act_text+nouzon)->ptr_mask);
		}
		else
		{
			moucol=XTOCOLGRAPH(x);
			mourow=YTOROWGRAPH(y);
			nouzon=*(bufz+mourow*scol+moucol);

		}
		mouzon=nouzon;

	}
	#pragma check_stack
	#pragma check_stack

//*************************************************************************//

	static void MouIBufFill(int x1, int y1, int x2, int y2, BYTE code)
	{
		register BYTE *lptr;
		int i;
		int n=(x2-x1+1)*(y2-y1+1);
		lptr=bufz+y1*scol+x1;

		for(i=0;i<n;i++)
			memset(lptr+i,code,1);

	}

//*************************************************************************//

	void MouDefTextZone(BYTE nombre, TEXTZONE *ptr)
	{
		register BYTE i,zone;

		zone_act_text=ptr;
		nmb_zones=nombre;
		memset(bufz,AUCUNE_ZONE,blen);
		for(i=0;i<nombre;++ptr)
			MouIBufFill(ptr->x1,ptr->y1,ptr->x2,ptr->y2,i++);
		zone=*(bufz+mourow*scol+moucol);
		MouDefineTextPtr((zone==AUCUNE_ZONE)? stdptr : (zone_act_text+zone)->ptr_mask);
	}

//**************************************************************************//

	void MouDefGraphZone(BYTE nombre, GRAPHZONE *ptr)
	{
		register BYTE i,zone;

		zone_act_graph=ptr;
		nmb_zones=nombre;
		memset(bufz,AUCUNE_ZONE,blen);
		for(i=0;i<nombre;++ptr)
			MouIBufFill(ptr->x1,ptr->y1,ptr->x2,ptr->y2,i++);
		zone=*(bufz+mourow*scol+moucol);
		if(zone!=AUCUNE_ZONE)
			MouDefineGraphPtr(Graph_Left,Graph_Right,(zone_act_graph+zone)->table);
	}

//*************************************************************************//

	int MouEventWait(BYTE typ,int wait_event)
	{
		int act_event;
		register int colonne=moucol,ligne=mourow;

		BYTE fin=FALSE;

		while(!fin)
		{
			if(typ==ET)
				while((act_event=mouevent)!=wait_event)
				;
			else
				while(((act_event=mouevent) & wait_event)==0)
				;
			act_event &= wait_event;

			if((wait_event & EV_MOU_MOVE) && (colonne==moucol)&&(ligne==mourow))
			{
				act_event &= (~EV_MOU_MOVE);
				fin=(act_event !=0);
			}
			else
				fin=TRUE;
		}
		ev_col=moucol;
		ev_row=mourow;
		ev_zon=mouzon;
		return (act_event);
	}

//*************************************************************************//

	static void MouISetEventHandler(unsigned event, MOUHAPTR ptr)
	{
		union REGS regs;
		struct SREGS sregs;

		regs.x.ax=0x000C;
		regs.x.cx=event;
		regs.x.dx=FP_OFF(ptr);
		sregs.es=FP_SEG(ptr);
		MOUINTX(regs,regs,sregs);
	}

//*************************************************************************//

	static int MouIGetX(void)
	{
		union REGS regs;

		regs.x.ax=0x0003;
		MOUINT(regs,regs);
		return  ((flag==TEXT)? XTOCOLTEXT(regs.x.cx) : XTOCOLGRAPH(regs.x.cx));
	}

//*************************************************************************//

	static int MouIGetY(void)
	{
		union REGS regs;

		regs.x.ax=0x0003;
		MOUINT(regs,regs);
		return  ((flag==TEXT)? YTOROWTEXT(regs.x.dx) : YTOROWGRAPH(regs.x.dx));
	}

//*************************************************************************//

	void MouShowMouse(void)
	{
		union REGS regs;
		regs.x.ax=0x0001;
		MOUINT(regs,regs);
	}

//*************************************************************************//

	void MouHideMouse(void)
	{
		union REGS regs;
		regs.x.ax=0x0002;
		MOUINT(regs,regs);
	}

//*************************************************************************//

	void MouSetMoveArea(int x1, int y1, int x2, int y2)
	{
		union REGS regs;
		regs.x.ax=0x0008;
		if(flag==TEXT)
		{
			regs.x.cx=ROWTOYTEXT(y1);
			regs.x.dx=ROWTOYTEXT(y2);
		}
		else
		{
			regs.x.cx=ROWTOYGRAPH(y1);
			regs.x.dx=ROWTOYGRAPH(y2);
		}
		MOUINT(regs,regs);

		regs.x.ax=0x0007;
		if(flag==TEXT)
		{
			regs.x.cx=COLTOXTEXT(x1);
			regs.x.dx=COLTOXTEXT(x2);
		}
		else
		{
			regs.x.cx=COLTOXGRAPH(x1);
			regs.x.dx=COLTOXGRAPH(x2);
		}
		MOUINT(regs,regs);
	}

//*************************************************************************//

	void MouSetBanArea(int x1, int y1, int x2, int y2)
	{
		union REGS regs;
		regs.x.ax=0x0010;

		if(flag==TEXT)
		{
			regs.x.cx=COLTOXTEXT(x1);
			regs.x.dx=ROWTOYTEXT(y1);
			regs.x.si=COLTOXTEXT(x2);
			regs.x.di=ROWTOYTEXT(y2);
		}
		else
		{
			regs.x.cx=COLTOXGRAPH(x1);
			regs.x.dx=ROWTOYGRAPH(y1);
			regs.x.si=COLTOXGRAPH(x2);
			regs.x.di=ROWTOYGRAPH(y2);
		}

		MOUINT(regs,regs);
	}

//*************************************************************************//

	REGS GetStatus()
	{
		REGS regs;
		regs.x.ax=0x0003;
		MOUINT(regs,regs);
		return regs;
	}

//*************************************************************************//

	REGS GetPressButton(int button)
	{
		if((button!=0)||(button!=1)||(button!=2))
			exit(1);
		REGS regs;
		regs.x.ax=0x0005;
		regs.x.bx=button;
		MOUINT(regs,regs);
		return regs;
	}

//*************************************************************************//

	REGS GetRelButton(int button)
	{
		if((button!=0)||(button!=1)||(button!=2))
			exit(1);
		REGS regs;
		regs.x.ax=0x0006;
		regs.x.bx=button;
		MOUINT(regs,regs);
		return regs;
	}

//*************************************************************************//

	void MouSetSpeed(int xspeed, int yspeed)
	{
		union REGS regs;

		regs.x.ax=0x000f;
		regs.x.cx=xspeed;
		regs.x.dx=yspeed;
		MOUINT(regs,regs);
	}

//*************************************************************************//

	void MouMovePtr(int col, int row)
	{
		union REGS regs;
		unsigned nouzon;
        pre_moucol=moucol;
		pre_mourow=mourow;

		regs.x.ax=0x0004;
		if(flag==TEXT)
		{
			regs.x.cx=COLTOXTEXT(moucol=col);
			regs.x.dx=ROWTOYTEXT(mourow=row);
		}
		else
		{
			regs.x.cx=COLTOXGRAPH(moucol=col);
			regs.x.dx=ROWTOYGRAPH(mourow=row);
		}
		MOUINT(regs,regs);

		nouzon=*(bufz + mourow * scol + moucol);
		if(nouzon !=mouzon)
			if(flag==TEXT)
				MouDefineTextPtr((nouzon==AUCUNE_ZONE) ? stdptr : (zone_act_text+nouzon)->ptr_mask);
		mouzon=nouzon;
	}

//*************************************************************************//

	void MouSetDefaultTextPtr(PTRVIEW standard)
	{
		stdptr = standard;

		if(MouGetZone()==AUCUNE_ZONE)
			MouDefineTextPtr(standard);
	}

//*************************************************************************//

	void MouEnd(void)
	{
		union REGS regs;

		MouHideMouse();
		regs.x.ax=0;
		MOUINT(regs,regs);

		free(bufz);
	}

//*************************************************************************//

	BYTE MouInit(int colonnes, int lignes, BYTE mode)
	{
		union REGS regs;
		sline=lignes;
		scol =colonnes;
		flag =mode;

		atexit(MouEnd);

		bufz =(BYTE *)malloc(blen=sline*scol);
		MouIBufFill(0,0,scol-1,sline-1,AUCUNE_ZONE);

		if(flag==TEXT)
			MouDefineTextPtr(stdptr);

		regs.x.ax=0;
		MOUINT(regs,regs);
		if(regs.x.ax !=0xffff)
			return FALSE;

		MouSetMoveAreaAll();

		moucol=MouIGetX();
		mourow=MouIGetY();

		MouISetEventHandler(EV_MOU_ALL,(MOUHAPTR) AssHand);

		return mavail = TRUE;

	}

}
#endif