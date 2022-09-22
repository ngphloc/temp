#ifndef _MOUSE_HPP
#define _MOUSE_HPP
extern "C"
{
	#include "Public.hpp"

	extern void far AssHand(void);
	typedef unsigned char BYTE;
	typedef unsigned long PTRVIEW;
	typedef struct
	{
		int x1,y1,x2,y2;
		PTRVIEW ptr_mask;
	} TEXTZONE;

	typedef struct
	{
		int x1,y1,x2,y2;
		char table[8][8];
	} GRAPHZONE;
	typedef void (far* MOUHAPTR) (void) ;

	#define TEXT  	0
	#define GRAPH   1

	#define EV_MOU_MOVE	 	 1
	#define EV_LEFT_PRESS	 2
	#define EV_LEFT_REL	 	 4
	#define EV_RIGHT_PRESS	 8
	#define EV_RIGHT_REL	 16
	#define EV_MID_PRESS     32
	#define EV_MID_REL       64
	#define EV_MOU_ALL	     127

	#define AUCUNE_ZONE   255

	#define  ELVEC(x)	(sizeof(x)/sizeof(x[0]))

	#define  MouPtrMask(z,f) ((((PTRVIEW)f)>>8<<24)+(((PTRVIEW)z)>>8<<16)+(((f)&255)<<8)+((z)&255))

	#define  PTRSAMECHAR	(0x00ff)
	#define  PTRDIFCHAR(z)	((z)<<8)
	#define  PTRSAMECOL		(0x00ff)
	#define  PTRINVCOL		(0x7777)
	#define  PTRSAMECOLC	(0x807f)
	#define  PTRINVCOLC		(0xF777)
	#define  PTRDIFCOL(f)	((f)<<8)
	#define  PTRDIFCOLC(f)	(((f)|0x80)<<8)

	#define	 ET   0
	#define  OU   1

	#define  MOUINT(rin,rout)	int86(0x33,&rin,&rout)
	#define  MOUINTX(rin,rout,sr)	int86x(0x33,&rin,&rout,&sr)

	#define  XTOCOLTEXT(x)      ((x)>>3)
	#define  YTOROWTEXT(y)      ((y)>>3)
	#define  COLTOXTEXT(c)      ((c)<<3)
	#define  ROWTOYTEXT(r)      ((r)<<3)
	/*
	#define  XTOCOLGRAPH(x)      (x*getmaxx()/632)
	#define  YTOROWGRAPH(y)      (y*getmaxy()/192)
	#define  COLTOXGRAPH(c)      (c*632/getmaxx())
	#define  ROWTOYGRAPH(r)      (r*192/getmaxy())

	int XTOCOLGRAPH(int x)       {return x;}
	int YTOROWGRAPH(int y)       {return y;}
	int COLTOXGRAPH(int c)       {return c;}
	int ROWTOYGRAPH(int r)       {return r;}
	*/
	#define  XTOCOLGRAPH(x)      (x)
	#define  YTOROWGRAPH(y)      (y)
	#define  COLTOXGRAPH(c)      (c)
	#define  ROWTOYGRAPH(r)      (r)

	int   MouGetCol()	;
	int   MouGetRow()	;
	BYTE  MouGetZone()	;
	BYTE  MouAvail()	;

	int   MouGetActCol();
	int   MouGetActRow();
	int   MouGetPreActCol()	 ;
	int   MouGetPreActRow()	 ;
	BYTE  MouGetActZon();

	int   MouIsLeftPress()	;
	int   MouIsLeftRel()	;
	int   MouIsRightPress()	;
	int   MouIsRightRel()	;
	int   MouIsMidPress()   ;
	int   MouIsMidRel()     ;

	int   MouIsPreLeftPress()	;
	int   MouIsPreLeftRel()	;
	int   MouIsPreRightPress()	;
	int   MouIsPreRightRel()	;
	int   MouIsPreMidPress()   ;
	int   MouIsPreMidRel()     ;

	void  MouSetMoveAreaAll()  ;
//*************************************************************************//
	void  MouEventHandler(int EvFlags,int ButState,int x,int y);
	void MouDefineTextPtr(PTRVIEW mask);
	void MouDefineGraphPtr(int left, int right, char table[8][8]);
	void MouDefTextZone(BYTE nombre, TEXTZONE *ptr);

	BYTE MouInit(int colonnes, int lignes, BYTE mode);

	void MouSetLightPen();
	void MouRemoveLightPen();
	void MouSetThresh(int threshold);
	void MouSetPage(int page);
	void MouSetMoveArea(int x1, int y1, int x2, int y2);
	void MouSetBanArea(int x1, int y1, int x2, int y2);
	static void MouISetEventHandler(unsigned event, MOUHAPTR ptr);
	void MouSetSpeed(int xspeed, int yspeed);
	void MouSetDefaultTextPtr(PTRVIEW standard);

	int MouGetPage();
	REGS MouGetMouseType();
	static int MouIGetX(void);
	static int MouIGetY(void);
	REGS GetStatus();
	REGS GetPressButton(int button);
	REGS GetRelButton(int button);

	static void MouIBufFill(int x1, int y1, int x2, int y2, BYTE code);
	int MouEventWait(BYTE typ,int wait_event);
	void MouShowMouse(void);
	void MouHideMouse(void);
	void MouMovePtr(int col, int row);
	void MouEnd(void);

}
#endif