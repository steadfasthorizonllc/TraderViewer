/////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2007-2010 Dapfor
//                                                                         
// This file is part of the Dapfor software, and may only be used, modified, and distributed 
// under the terms of the Dapfor LICENSE AGREEMENT FOR MFC GRID SOFTWARE.
// (See accompanying file lisense.txt or open the license at http://www.dapfor.com/license_agreement_v2.aspx)
// By continuing to use, modify, or distribute this file you indicate that you have read the license 
// and fully understand and accept it.
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __DF_COMMON_AUTOLINK_64__H
#define __DF_COMMON_AUTOLINK_64__H

#if defined(_WIN64)

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
                    #pragma comment(lib,"Dapfor.Grid60_64ud.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60_64ud.dll (Dapfor unicode debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid60_64d.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60_64d.dll (Dapfor debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   //_DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid60_64u.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60_64u.dll (Dapfor unicode release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid60_64.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60_64.dll (Dapfor release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
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
                    #pragma comment(lib,"Dapfor.Grid60_64uds.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60_64uds.lib (Dapfor unicode debug static library, MFC static libraries, Debug multithreaded runtime library (switch /MTd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid60_64ds.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60_64ds.lib (Dapfor debug static library, MFC static libraries, Debug multithreaded runtime library (switch /MTd))") 
                #endif
            #else   // Release
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid60_64us.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60_64us.lib (Dapfor unicode release static library, MFC static libraries, Multithreaded runtime library (switch /MT))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid60_64s.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60_64s.lib (Dapfor release static library, MFC static libraries, Multithreaded runtime library (switch /MT))") 
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
                    #pragma comment(lib,"Dapfor.Grid60_64udss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60_64udss.lib (Dapfor unicode debug static library, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid60_64dss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60_64dss.lib (Dapfor debug static library, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   // Release
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid60_64uss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60_64uss.lib (Dapfor unicode release static library, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid60_64ss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60_64ss.lib (Dapfor release static library, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
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
                    #pragma comment(lib,"Dapfor.Grid80_64ud.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80_64ud.dll (Dapfor unicode debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid80_64d.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80_64d.dll (Dapfor debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   //_DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid80_64u.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80_64u.dll (Dapfor unicode release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid80_64.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80_64.dll (Dapfor release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
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
                    #pragma comment(lib,"Dapfor.Grid80_64uds.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80_64uds.lib (Dapfor unicode debug static library, MFC static libraries, Debug multithreaded runtime library (switch /MTd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid80_64ds.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80_64ds.lib (Dapfor debug static library, MFC static libraries, Debug multithreaded runtime library (switch /MTd))") 
                #endif
            #else   // Release
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid80_64us.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80_64us.lib (Dapfor unicode release static library, MFC static libraries, Multithreaded runtime library (switch /MT))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid80_64s.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80_64s.lib (Dapfor release static library, MFC static libraries, Multithreaded runtime library (switch /MT))") 
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
                    #pragma comment(lib,"Dapfor.Grid80_64udss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80_64udss.lib (Dapfor unicode debug static library, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid80_64dss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80_64dss.lib (Dapfor debug static library, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   // Release
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid80_64uss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80_64uss.lib (Dapfor unicode release static library, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid80_64ss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80_64ss.lib (Dapfor release static library, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
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
                    #pragma comment(lib,"Dapfor.Grid90_64ud.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90_64ud.dll (Dapfor unicode debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid90_64d.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90_64d.dll (Dapfor debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   //_DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid90_64u.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90_64u.dll (Dapfor unicode release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid90_64.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90_64.dll (Dapfor release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
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
                    #pragma comment(lib,"Dapfor.Grid90_64uds.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90_64uds.lib (Dapfor unicode debug static library, MFC static libraries, Debug multithreaded runtime library (switch /MTd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid90_64ds.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90_64ds.lib (Dapfor debug static library, MFC static libraries, Debug multithreaded runtime library (switch /MTd))") 
                #endif
            #else   // Release
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid90_64us.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90_64us.lib (Dapfor unicode release static library, MFC static libraries, Multithreaded runtime library (switch /MT))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid90_64s.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90_64s.lib (Dapfor release static library, MFC static libraries, Multithreaded runtime library (switch /MT))") 
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
                    #pragma comment(lib,"Dapfor.Grid90_64udss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90_64udss.lib (Dapfor unicode debug static library, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid90_64dss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90_64dss.lib (Dapfor debug static library, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   // Release
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid90_64uss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90_64uss.lib (Dapfor unicode release static library, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid90_64ss.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90_64ss.lib (Dapfor release static library, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
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
                    #pragma comment(lib,"Dapfor.Grid60_64ud.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60_64ud.dll (Dapfor unicode debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid60_64d.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60_64d.dll (Dapfor debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   //_DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid60_64u.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60_64u.dll (Dapfor unicode release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid60_64.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid60_64.dll (Dapfor release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
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
                    #pragma comment(lib,"Dapfor.Common60_64uds.lib") 
                    #pragma message("Automatically linking with Dapfor.Common60_64uds.lib (Dapfor unicode debug static library, MFC libraries are not used, Debug multithreaded runtime library (switch /MTd))") 
                #else
                    #pragma comment(lib,"Dapfor.Common60_64ds.lib") 
                    #pragma message("Automatically linking with Dapfor.Common60_64ds.lib (Dapfor debug static library, MFC libraries are not used, Debug multithreaded runtime library (switch /MTd))") 
                #endif
            #else   // _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common60_64us.lib") 
                    #pragma message("Automatically linking with Dapfor.Common60_64us.lib (Dapfor unicode release static library, MFC libraries are not used, Multithreaded runtime library (switch /MT))") 
                #else
                    #pragma comment(lib,"Dapfor.Common60_64s.lib") 
                    #pragma message("Automatically linking with Dapfor.Common60_64s.lib (Dapfor release static library, MFC libraries are not used, Multithreaded runtime library (switch /MT))") 
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
                    #pragma comment(lib,"Dapfor.Common60_64udss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common60_64udss.lib (Dapfor unicode debug static library, MFC libraries are not used, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Common60_64dss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common60_64dss.lib (Dapfor debug static library, MFC libraries are not used, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   // _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common60_64uss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common60_64uss.lib (Dapfor unicode release static library, MFC libraries are not used, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Common60_64ss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common60_64ss.lib (Dapfor release static library, MFC libraries are not used, Multithreaded Dll runtime library (switch /MD))") 
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
                    #pragma comment(lib,"Dapfor.Grid80_64ud.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80_64ud.dll (Dapfor unicode debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid80_64d.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80_64d.dll (Dapfor debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   //_DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid80_64u.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80_64u.dll (Dapfor unicode release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid80_64.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid80_64.dll (Dapfor release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
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
                    #pragma comment(lib,"Dapfor.Common80_64uds.lib") 
                    #pragma message("Automatically linking with Dapfor.Common80_64uds.lib (Dapfor unicode debug static library, MFC libraries are not used, Debug multithreaded runtime library (switch /MTd))") 
                #else
                    #pragma comment(lib,"Dapfor.Common80_64ds.lib") 
                    #pragma message("Automatically linking with Dapfor.Common80_64ds.lib (Dapfor debug static library, MFC libraries are not used, Debug multithreaded runtime library (switch /MTd))") 
                #endif
            #else   // _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common80_64us.lib") 
                    #pragma message("Automatically linking with Dapfor.Common80_64us.lib (Dapfor unicode release static library, MFC libraries are not used, Multithreaded runtime library (switch /MT))") 
                #else
                    #pragma comment(lib,"Dapfor.Common80_64s.lib") 
                    #pragma message("Automatically linking with Dapfor.Common80_64s.lib (Dapfor release static library, MFC libraries are not used, Multithreaded runtime library (switch /MT))") 
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
                    #pragma comment(lib,"Dapfor.Common80_64udss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common80_64udss.lib (Dapfor unicode debug static library, MFC libraries are not used, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Common80_64dss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common80_64dss.lib (Dapfor debug static library, MFC libraries are not used, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   // _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common80_64uss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common80_64uss.lib (Dapfor unicode release static library, MFC libraries are not used, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Common80_64ss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common80_64ss.lib (Dapfor release static library, MFC libraries are not used, Multithreaded Dll runtime library (switch /MD))") 
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
                    #pragma comment(lib,"Dapfor.Grid90_64ud.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90_64ud.dll (Dapfor unicode debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid90_64d.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90_64d.dll (Dapfor debug DLL, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   //_DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Grid90_64u.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90_64u.dll (Dapfor unicode release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Grid90_64.lib") 
                    #pragma message("Automatically linking with Dapfor.Grid90_64.dll (Dapfor release DLL, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
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
                    #pragma comment(lib,"Dapfor.Common90_64uds.lib") 
                    #pragma message("Automatically linking with Dapfor.Common90_64uds.lib (Dapfor unicode debug static library, MFC libraries are not used, Debug multithreaded runtime library (switch /MTd))") 
                #else
                    #pragma comment(lib,"Dapfor.Common90_64ds.lib") 
                    #pragma message("Automatically linking with Dapfor.Common90_64ds.lib (Dapfor debug static library, MFC libraries are not used, Debug multithreaded runtime library (switch /MTd))") 
                #endif
            #else   // _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common90_64us.lib") 
                    #pragma message("Automatically linking with Dapfor.Common90_64us.lib (Dapfor unicode release static library, MFC libraries are not used, Multithreaded runtime library (switch /MT))") 
                #else
                    #pragma comment(lib,"Dapfor.Common90_64s.lib") 
                    #pragma message("Automatically linking with Dapfor.Common90_64s.lib (Dapfor release static library, MFC libraries are not used, Multithreaded runtime library (switch /MT))") 
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
                    #pragma comment(lib,"Dapfor.Common90_64udss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common90_64udss.lib (Dapfor unicode debug static library, MFC libraries are not used, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.Common90_64dss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common90_64dss.lib (Dapfor debug static library, MFC libraries are not used, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   // _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.Common90_64uss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common90_64uss.lib (Dapfor unicode release static library, MFC libraries are not used, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.Common90_64ss.lib") 
                    #pragma message("Automatically linking with Dapfor.Common90_64ss.lib (Dapfor release static library, MFC libraries are not used, Multithreaded Dll runtime library (switch /MD))") 
                #endif
            #endif  //_DEBUG
        #endif

    #else
        #error This compiler version is not supported
    #endif//_MSC_VER

#endif//DF_NOT_MFC

#endif//_WIN64

#endif// __DF_COMMON_AUTOLINK_64__H
