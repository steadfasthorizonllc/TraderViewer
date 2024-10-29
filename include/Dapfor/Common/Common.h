/////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2007-2010 Dapfor
//                                                                         
// This file is part of the Dapfor software, and may only be used, modified, and distributed 
// under the terms of the Dapfor LICENSE AGREEMENT FOR MFC GRID SOFTWARE.
// (See accompanying file lisense.txt or open the license at http://www.dapfor.com/license_agreement_v2.aspx)
// By continuing to use, modify, or distribute this file you indicate that you have read the license 
// and fully understand and accept it.
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __DF__COMMON__H
#define __DF__COMMON__H
 

#if defined _AFXDLL && !defined DF_STATIC_LIB
    #ifdef DF_COMMON_EXPORT
       #define DF_COMMON_API  _declspec(dllexport)
    #else
       #define DF_COMMON_API  _declspec(dllimport)
    #endif
#else
    #define DF_COMMON_API
#endif


#endif//__DF__COMMON__H
