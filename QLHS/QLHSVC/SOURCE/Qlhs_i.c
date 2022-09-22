/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Oct 25 07:49:11 2000
 */
/* Compiler settings for D:\HQTCSDL\Qlhs\Qlhs.odl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID LIBID_Qlhs = {0x7921BDC3,0x9FAD,0x11D4,{0xA3,0xE4,0xB0,0x17,0xBF,0x6D,0x81,0x0E}};


const IID DIID_IQlhs = {0x7921BDC4,0x9FAD,0x11D4,{0xA3,0xE4,0xB0,0x17,0xBF,0x6D,0x81,0x0E}};


const CLSID CLSID_Document = {0xCC94600B,0x9DE3,0x11D4,{0xA3,0xE4,0x9F,0x67,0xC9,0x6D,0x1B,0x09}};


#ifdef __cplusplus
}
#endif

