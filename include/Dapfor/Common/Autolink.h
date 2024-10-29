/////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2007-2010 Dapfor
//                                                                         
// This file is part of the Dapfor software, and may only be used, modified, and distributed 
// under the terms of the Dapfor LICENSE AGREEMENT FOR MFC GRID SOFTWARE.
// (See accompanying file lisense.txt or open the license at http://www.dapfor.com/license_agreement_v2.aspx)
// By continuing to use, modify, or distribute this file you indicate that you have read the license 
// and fully understand and accept it.
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __DF_COMMON_AUTOLINK__H
#define __DF_COMMON_AUTOLINK__H

#if defined(_WIN64)

    #include <Dapfor/Common/Autolink_64.h>

#else

#if !defined DF_NOT_MFC
//The Common library has been compiled with MFC support.
    #if(_MSC_VER == 1200) //VC6
        //--------------------------------------------
        // Dapfor shared DLL, 
        // MFC shared DLL, 
        // Multithreaded Dll runtime libraries (switches /MD or /MDd)
        //--------------------------------------------
        #if defined _AFXDLL && !defined DF_STATIC_LIB
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid60ud.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60ud.dll (Dapfor unicode debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid60d.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60d.dll (Dapfor debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   //_DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid60u.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60u.dll (Dapfor unicode release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid60.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60.dll (Dapfor release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #endif
            #endif  //_DEBUG
        //--------------------------------------------
        // Dapfor static libraries, 
        // MFC in a static library
        // Multithreaded runtime libraries (switches /MT or /MTd)
        //--------------------------------------------
        #elif defined DF_STATIC_LIB && !defined _AFXDLL
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid60uds.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60uds.lib (Dapfor unicode debug static library, MFC static libraries, Debug multithreaded runtime library (switch /MTd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid60ds.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60ds.lib (Dapfor debug static library, MFC static libraries, Debug multithreaded runtime library (switch /MTd))") 
                #endif
            #else   // Release
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid60us.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60us.lib (Dapfor unicode release static library, MFC static libraries, Multithreaded runtime library (switch /MT))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid60s.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60s.lib (Dapfor release static library, MFC static libraries, Multithreaded runtime library (switch /MT))") 
                #endif
            #endif//_DEBUG

        //--------------------------------------------
        // Dapfor static libraries, 
        // MFC shared DLL, 
        // Multithreaded Dll runtime libraries (switches /MD or /MDd)
        //--------------------------------------------
        #else
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid60udss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60udss.lib (Dapfor unicode debug static library, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid60dss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60dss.lib (Dapfor debug static library, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   // Release
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid60uss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60uss.lib (Dapfor unicode release static library, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid60ss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60ss.lib (Dapfor release static library, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #endif
            #endif//_DEBUG
        #endif

    #elif(_MSC_VER == 1400) //VC8
    //--------------------------------------------
    // Dapfor shared DLL, 
    // MFC shared DLL, 
    // Multithreaded Dll runtime libraries (switches /MD or /MDd)
    //--------------------------------------------
        #if defined _AFXDLL && !defined DF_STATIC_LIB
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid80ud.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80ud.dll (Dapfor unicode debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid80d.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80d.dll (Dapfor debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   //_DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid80u.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80u.dll (Dapfor unicode release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid80.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80.dll (Dapfor release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #endif
            #endif  //_DEBUG
        //--------------------------------------------
        // Dapfor static libraries, 
        // MFC in a static library
        // Multithreaded runtime libraries (switches /MT or /MTd)
        //--------------------------------------------
        #elif defined DF_STATIC_LIB && !defined _AFXDLL
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid80uds.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80uds.lib (Dapfor unicode debug static library, MFC static libraries, Debug multithreaded runtime library (switch /MTd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid80ds.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80ds.lib (Dapfor debug static library, MFC static libraries, Debug multithreaded runtime library (switch /MTd))") 
                #endif
            #else   // Release
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid80us.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80us.lib (Dapfor unicode release static library, MFC static libraries, Multithreaded runtime library (switch /MT))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid80s.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80s.lib (Dapfor release static library, MFC static libraries, Multithreaded runtime library (switch /MT))") 
                #endif
            #endif//_DEBUG

        //--------------------------------------------
        // Dapfor static libraries, 
        // MFC shared DLL, 
        // Multithreaded Dll runtime libraries (switches /MD or /MDd)
        //--------------------------------------------
        #else
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid80udss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80udss.lib (Dapfor unicode debug static library, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid80dss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80dss.lib (Dapfor debug static library, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   // Release
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid80uss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80uss.lib (Dapfor unicode release static library, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid80ss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80ss.lib (Dapfor release static library, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #endif
            #endif//_DEBUG
        #endif
    #elif(_MSC_VER == 1500) //VC9
    //--------------------------------------------
    // Dapfor shared DLL, 
    // MFC shared DLL, 
    // Multithreaded Dll runtime libraries (switches /MD or /MDd)
    //--------------------------------------------
        #if defined _AFXDLL && !defined DF_STATIC_LIB
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid90ud.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90ud.dll (Dapfor unicode debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid90d.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90d.dll (Dapfor debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   //_DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid90u.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90u.dll (Dapfor unicode release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid90.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90.dll (Dapfor release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #endif
            #endif  //_DEBUG
        //--------------------------------------------
        // Dapfor static libraries, 
        // MFC in a static library
        // Multithreaded runtime libraries (switches /MT or /MTd)
        //--------------------------------------------
        #elif defined DF_STATIC_LIB && !defined _AFXDLL
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid90uds.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90uds.lib (Dapfor unicode debug static library, MFC static libraries, Debug multithreaded runtime library (switch /MTd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid90ds.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90ds.lib (Dapfor debug static library, MFC static libraries, Debug multithreaded runtime library (switch /MTd))") 
                #endif
            #else   // Release
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid90us.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90us.lib (Dapfor unicode release static library, MFC static libraries, Multithreaded runtime library (switch /MT))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid90s.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90s.lib (Dapfor release static library, MFC static libraries, Multithreaded runtime library (switch /MT))") 
                #endif
            #endif//_DEBUG

        //--------------------------------------------
        // Dapfor static libraries, 
        // MFC shared DLL, 
        // Multithreaded Dll runtime libraries (switches /MD or /MDd)
        //--------------------------------------------
        #else
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid90udss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90udss.lib (Dapfor unicode debug static library, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid90dss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90dss.lib (Dapfor debug static library, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   // Release
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid90uss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90uss.lib (Dapfor unicode release static library, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid90ss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90ss.lib (Dapfor release static library, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #endif
            #endif//_DEBUG
        #endif
    #elif(_MSC_VER == 1600) //VC10
    //--------------------------------------------
    // Dapfor shared DLL, 
    // MFC shared DLL, 
    // Multithreaded Dll runtime libraries (switches /MD or /MDd)
    //--------------------------------------------
        #if defined _AFXDLL && !defined DF_STATIC_LIB
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid10ud.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid10ud.dll (Dapfor unicode debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid10d.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid10d.dll (Dapfor debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   //_DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid10u.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid10u.dll (Dapfor unicode release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid10.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid10.dll (Dapfor release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #endif
            #endif  //_DEBUG
        //--------------------------------------------
        // Dapfor static libraries, 
        // MFC in a static library
        // Multithreaded runtime libraries (switches /MT or /MTd)
        //--------------------------------------------
        #elif defined DF_STATIC_LIB && !defined _AFXDLL
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid10uds.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid10uds.lib (Dapfor unicode debug static library, MFC static libraries, Debug multithreaded runtime library (switch /MTd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid10ds.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid10ds.lib (Dapfor debug static library, MFC static libraries, Debug multithreaded runtime library (switch /MTd))") 
                #endif
            #else   // Release
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid10us.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid10us.lib (Dapfor unicode release static library, MFC static libraries, Multithreaded runtime library (switch /MT))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid10s.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid10s.lib (Dapfor release static library, MFC static libraries, Multithreaded runtime library (switch /MT))") 
                #endif
            #endif//_DEBUG

        //--------------------------------------------
        // Dapfor static libraries, 
        // MFC shared DLL, 
        // Multithreaded Dll runtime libraries (switches /MD or /MDd)
        //--------------------------------------------
        #else
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid10udss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid10udss.lib (Dapfor unicode debug static library, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid10dss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid10dss.lib (Dapfor debug static library, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   // Release
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid10uss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid10uss.lib (Dapfor unicode release static library, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid10ss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid10ss.lib (Dapfor release static library, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #endif
            #endif//_DEBUG
        #endif
    #else
        #error This compiler version is not supported
    #endif//_MSC_VER

#else//DF_NOT_MFC
//If you have a project that consists of many libraries and some of them doesn't support MFC, you can 
//use the configuration of Dapfor.Grid where the library Dapfor.Common has been compiled without MFC support.

    #if(_MSC_VER == 1200) //VC6 = 1200
        //--------------------------------------------
        // Dapfor shared DLL, 
        // MFC shared DLL, 
        // Multithreaded Dll runtime libraries (switches /MD or /MDd)
        //--------------------------------------------
        #if defined _AFXDLL && !defined DF_STATIC_LIB
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid60ud.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60ud.dll (Dapfor unicode debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid60d.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60d.dll (Dapfor debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   //_DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid60u.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60u.dll (Dapfor unicode release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid60.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60.dll (Dapfor release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #endif
            #endif  //_DEBUG

        //--------------------------------------------
        // Dapfor static libraries, 
        // MFC in a static library
        // Multithreaded runtime libraries (switches /MT or /MTd)
        //--------------------------------------------
        #elif defined DF_STATIC_LIB && !defined _AFXDLL
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common60uds.lib") 
                    #pragma message("Automatically linking with Dapfor.Common60uds.lib (Dapfor unicode debug static library, MFC libraries are not used, Debug multithreaded runtime library (switch /MTd))") 
                #else
                    #pragma comment(lib,"Dapfor.Common60ds.lib") 
                    #pragma message("Automatically linking with Dapfor.Common60ds.lib (Dapfor debug static library, MFC libraries are not used, Debug multithreaded runtime library (switch /MTd))") 
                #endif
            #else   // _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common60us.lib") 
                    #pragma message("Automatically linking with Dapfor.Common60us.lib (Dapfor unicode release static library, MFC libraries are not used, Multithreaded runtime library (switch /MT))") 
                #else
                    #pragma comment(lib,"Dapfor.Common60s.lib") 
                    #pragma message("Automatically linking with Dapfor.Common60s.lib (Dapfor release static library, MFC libraries are not used, Multithreaded runtime library (switch /MT))") 
                #endif
            #endif  //_DEBUG
        //--------------------------------------------
        // Dapfor static libraries, 
        // MFC shared DLL, 
        // Multithreaded Dll runtime libraries (switches /MD or /MDd)
        //--------------------------------------------
        #else 
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common60udss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common60udss.lib (Dapfor unicode debug static library, MFC libraries are not used, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Common60dss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common60dss.lib (Dapfor debug static library, MFC libraries are not used, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   // _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common60uss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common60uss.lib (Dapfor unicode release static library, MFC libraries are not used, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Common60ss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common60ss.lib (Dapfor release static library, MFC libraries are not used, Multithreaded Dll runtime library (switch /MD))") 
                #endif
            #endif  //_DEBUG
        #endif

    #elif(_MSC_VER == 1400) //VC8
        //--------------------------------------------
        // Dapfor shared DLL, 
        // MFC shared DLL, 
        // Multithreaded Dll runtime libraries (switches /MD or /MDd)
        //--------------------------------------------
        #if defined _AFXDLL && !defined DF_STATIC_LIB
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid80ud.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80ud.dll (Dapfor unicode debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid80d.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80d.dll (Dapfor debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   //_DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid80u.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80u.dll (Dapfor unicode release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid80.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80.dll (Dapfor release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #endif
            #endif  //_DEBUG
        //--------------------------------------------
        // Dapfor static libraries, 
        // MFC in a static library
        // Multithreaded runtime libraries (switches /MT or /MTd)
        //--------------------------------------------
        #elif defined DF_STATIC_LIB && !defined _AFXDLL
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common80uds.lib") 
                    #pragma message("Automatically linking with Dapfor.Common80uds.lib (Dapfor unicode debug static library, MFC libraries are not used, Debug multithreaded runtime library (switch /MTd))") 
                #else
                    #pragma comment(lib,"Dapfor.Common80ds.lib") 
                    #pragma message("Automatically linking with Dapfor.Common80ds.lib (Dapfor debug static library, MFC libraries are not used, Debug multithreaded runtime library (switch /MTd))") 
                #endif
            #else   // _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common80us.lib") 
                    #pragma message("Automatically linking with Dapfor.Common80us.lib (Dapfor unicode release static library, MFC libraries are not used, Multithreaded runtime library (switch /MT))") 
                #else
                    #pragma comment(lib,"Dapfor.Common80s.lib") 
                    #pragma message("Automatically linking with Dapfor.Common80s.lib (Dapfor release static library, MFC libraries are not used, Multithreaded runtime library (switch /MT))") 
                #endif
            #endif  //_DEBUG
        //--------------------------------------------
        // Dapfor static libraries, 
        // MFC shared DLL, 
        // Multithreaded Dll runtime libraries (switches /MD or /MDd)
        //--------------------------------------------
        #else 
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common80udss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common80udss.lib (Dapfor unicode debug static library, MFC libraries are not used, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Common80dss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common80dss.lib (Dapfor debug static library, MFC libraries are not used, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   // _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common80uss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common80uss.lib (Dapfor unicode release static library, MFC libraries are not used, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Common80ss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common80ss.lib (Dapfor release static library, MFC libraries are not used, Multithreaded Dll runtime library (switch /MD))") 
                #endif
            #endif  //_DEBUG
        #endif
    #elif(_MSC_VER == 1500) //VC9
        //--------------------------------------------
        // Dapfor shared DLL, 
        // MFC shared DLL, 
        // Multithreaded Dll runtime libraries (switches /MD or /MDd)
        //--------------------------------------------
        #if defined _AFXDLL && !defined DF_STATIC_LIB
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid90ud.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90ud.dll (Dapfor unicode debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid90d.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90d.dll (Dapfor debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   //_DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid90u.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90u.dll (Dapfor unicode release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid90.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90.dll (Dapfor release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #endif
            #endif  //_DEBUG
        //--------------------------------------------
        // Dapfor static libraries, 
        // MFC in a static library
        // Multithreaded runtime libraries (switches /MT or /MTd)
        //--------------------------------------------
        #elif defined DF_STATIC_LIB && !defined _AFXDLL
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common90uds.lib") 
                    #pragma message("Automatically linking with Dapfor.Common90uds.lib (Dapfor unicode debug static library, MFC libraries are not used, Debug multithreaded runtime library (switch /MTd))") 
                #else
                    #pragma comment(lib,"Dapfor.Common90ds.lib") 
                    #pragma message("Automatically linking with Dapfor.Common90ds.lib (Dapfor debug static library, MFC libraries are not used, Debug multithreaded runtime library (switch /MTd))") 
                #endif
            #else   // _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common90us.lib") 
                    #pragma message("Automatically linking with Dapfor.Common90us.lib (Dapfor unicode release static library, MFC libraries are not used, Multithreaded runtime library (switch /MT))") 
                #else
                    #pragma comment(lib,"Dapfor.Common90s.lib") 
                    #pragma message("Automatically linking with Dapfor.Common90s.lib (Dapfor release static library, MFC libraries are not used, Multithreaded runtime library (switch /MT))") 
                #endif
            #endif  //_DEBUG
        //--------------------------------------------
        // Dapfor static libraries, 
        // MFC shared DLL, 
        // Multithreaded Dll runtime libraries (switches /MD or /MDd)
        //--------------------------------------------
        #else 
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common90udss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common90udss.lib (Dapfor unicode debug static library, MFC libraries are not used, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Common90dss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common90dss.lib (Dapfor debug static library, MFC libraries are not used, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   // _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common90uss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common90uss.lib (Dapfor unicode release static library, MFC libraries are not used, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Common90ss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common90ss.lib (Dapfor release static library, MFC libraries are not used, Multithreaded Dll runtime library (switch /MD))") 
                #endif
            #endif  //_DEBUG
        #endif

    #elif(_MSC_VER == 1600) //VC10
        //--------------------------------------------
        // Dapfor shared DLL, 
        // MFC shared DLL, 
        // Multithreaded Dll runtime libraries (switches /MD or /MDd)
        //--------------------------------------------
        #if defined _AFXDLL && !defined DF_STATIC_LIB
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid10ud.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid10ud.dll (Dapfor unicode debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid10d.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid10d.dll (Dapfor debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   //_DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid10u.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid10u.dll (Dapfor unicode release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid10.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid10.dll (Dapfor release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #endif
            #endif  //_DEBUG
        //--------------------------------------------
        // Dapfor static libraries, 
        // MFC in a static library
        // Multithreaded runtime libraries (switches /MT or /MTd)
        //--------------------------------------------
        #elif defined DF_STATIC_LIB && !defined _AFXDLL
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common10uds.lib") 
                    #pragma message("Automatically linking with Dapfor.Common10uds.lib (Dapfor unicode debug static library, MFC libraries are not used, Debug multithreaded runtime library (switch /MTd))") 
                #else
                    #pragma comment(lib,"Dapfor.Common10ds.lib") 
                    #pragma message("Automatically linking with Dapfor.Common10ds.lib (Dapfor debug static library, MFC libraries are not used, Debug multithreaded runtime library (switch /MTd))") 
                #endif
            #else   // _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common10us.lib") 
                    #pragma message("Automatically linking with Dapfor.Common10us.lib (Dapfor unicode release static library, MFC libraries are not used, Multithreaded runtime library (switch /MT))") 
                #else
                    #pragma comment(lib,"Dapfor.Common10s.lib") 
                    #pragma message("Automatically linking with Dapfor.Common10s.lib (Dapfor release static library, MFC libraries are not used, Multithreaded runtime library (switch /MT))") 
                #endif
            #endif  //_DEBUG
        //--------------------------------------------
        // Dapfor static libraries, 
        // MFC shared DLL, 
        // Multithreaded Dll runtime libraries (switches /MD or /MDd)
        //--------------------------------------------
        #else 
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common10udss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common10udss.lib (Dapfor unicode debug static library, MFC libraries are not used, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Common10dss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common10dss.lib (Dapfor debug static library, MFC libraries are not used, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   // _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common10uss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common10uss.lib (Dapfor unicode release static library, MFC libraries are not used, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Common10ss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common10ss.lib (Dapfor release static library, MFC libraries are not used, Multithreaded Dll runtime library (switch /MD))") 
                #endif
            #endif  //_DEBUG
        #endif

    #else
        #error This compiler version is not supported
    #endif//_MSC_VER

#endif//DF_NOT_MFC

#endif//_WIN64

#endif// __DF_COMMON_AUTOLINK__H
