/////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2007-2010 Dapfor
//                                                                         
// This file is part of the Dapfor software, and may only be used, modified, and distributed 
// under the terms of the Dapfor LICENSE AGREEMENT FOR MFC GRID SOFTWARE.
// (See accompanying file lisense.txt or open the license at http://www.dapfor.com/license_agreement_v2.aspx)
// By continuing to use, modify, or distribute this file you indicate that you have read the license 
// and fully understand and accept it.
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __DF_GUI_AUTOLINK__H
#define __DF_GUI_AUTOLINK__H

#if defined(_WIN64)

#if !defined DF_NOT_MFC

    //The Common library has been compiled with MFC support. 
    //GUI and Common modules have been compiled into single library
    #include <Dapfor/Common/Autolink_64.h>

#else//DF_NOT_MFC

//If you have a project that consists of many libraries and some of them don't support MFC, you can 
//use the configuration of Dapfor.Grid where the library Dapfor.Common has been compiled without MFC support.
    #if(_MSC_VER == 1200) //VC6
        //--------------------------------------------
        // Dapfor shared DLL, 
        // MFC shared DLL, 
        // Multithreaded Dll runtime libraries (switches /MD or /MDd)
        //--------------------------------------------
        #if defined _AFXDLL && !defined DF_STATIC_LIB
            
            //The Common library has been compiled with MFC support. 
            //GUI and Common modules have been compiled into single library
            #include <Dapfor/Common/Autolink.h>

        //--------------------------------------------
        // Dapfor static libraries, 
        // MFC in a static library
        // Multithreaded runtime libraries (switches /MT or /MTd)
        //--------------------------------------------
        #elif defined DF_STATIC_LIB && !defined _AFXDLL
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.GUI60uds.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI60uds.lib (Dapfor unicode debug static library, MFC static libraries, Debug multithreaded runtime library (switch /MTd))") 
                #else
                    #pragma comment(lib,"Dapfor.GUI60ds.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI60ds.lib (Dapfor debug static library, MFC static libraries, Debug multithreaded runtime library (switch /MTd))") 
                #endif
            #else   // Release
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.GUI60us.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI60us.lib (Dapfor unicode release static library, MFC static libraries, Multithreaded runtime library (switch /MT))") 
                #else
                    #pragma comment(lib,"Dapfor.GUI60s.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI60s.lib (Dapfor release static library, MFC static libraries, Multithreaded runtime library (switch /MT))") 
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
                    #pragma comment(lib,"Dapfor.GUI60udss.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI60udss.lib (Dapfor unicode debug static library, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.GUI60dss.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI60dss.lib (Dapfor debug static library, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   // Release
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.GUI60uss.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI60uss.lib (Dapfor unicode release static library, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.GUI60ss.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI60ss.lib (Dapfor release static library, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
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
            

            //The Common library has been compiled with MFC support. 
            //GUI and Common modules have been compiled into single library
            #include <Dapfor/Common/Autolink.h>

        //--------------------------------------------
        // Dapfor static libraries, 
        // MFC in a static library
        // Multithreaded runtime libraries (switches /MT or /MTd)
        //--------------------------------------------
        #elif defined DF_STATIC_LIB && !defined _AFXDLL
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.GUI80uds.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI80uds.lib (Dapfor unicode debug static library, MFC static libraries, Debug multithreaded runtime library (switch /MTd))") 
                #else
                    #pragma comment(lib,"Dapfor.GUI80ds.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI80ds.lib (Dapfor debug static library, MFC static libraries, Debug multithreaded runtime library (switch /MTd))") 
                #endif
            #else   // Release
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.GUI80us.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI80us.lib (Dapfor unicode release static library, MFC static libraries, Multithreaded runtime library (switch /MT))") 
                #else
                    #pragma comment(lib,"Dapfor.GUI80s.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI80s.lib (Dapfor release static library, MFC static libraries, Multithreaded runtime library (switch /MT))") 
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
                    #pragma comment(lib,"Dapfor.GUI80udss.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI80udss.lib (Dapfor unicode debug static library, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.GUI80dss.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI80dss.lib (Dapfor debug static library, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   // Release
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.GUI80uss.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI80uss.lib (Dapfor unicode release static library, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.GUI80ss.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI80ss.lib (Dapfor release static library, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
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
            

            //The Common library has been compiled with MFC support. 
            //GUI and Common modules have been compiled into single library
            #include <Dapfor/Common/Autolink.h>

        //--------------------------------------------
        // Dapfor static libraries, 
        // MFC in a static library
        // Multithreaded runtime libraries (switches /MT or /MTd)
        //--------------------------------------------
        #elif defined DF_STATIC_LIB && !defined _AFXDLL
            #ifdef _DEBUG
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.GUI90uds.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI90uds.lib (Dapfor unicode debug static library, MFC static libraries, Debug multithreaded runtime library (switch /MTd))") 
                #else
                    #pragma comment(lib,"Dapfor.GUI90ds.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI90ds.lib (Dapfor debug static library, MFC static libraries, Debug multithreaded runtime library (switch /MTd))") 
                #endif
            #else   // Release
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.GUI90us.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI90us.lib (Dapfor unicode release static library, MFC static libraries, Multithreaded runtime library (switch /MT))") 
                #else
                    #pragma comment(lib,"Dapfor.GUI90s.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI90s.lib (Dapfor release static library, MFC static libraries, Multithreaded runtime library (switch /MT))") 
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
                    #pragma comment(lib,"Dapfor.GUI90udss.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI90udss.lib (Dapfor unicode debug static library, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #else
                    #pragma comment(lib,"Dapfor.GUI90dss.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI90dss.lib (Dapfor debug static library, MFC shared DLL, Debug Multithreaded Dll runtime library (switch /MDd))") 
                #endif
            #else   // Release
                #ifdef _UNICODE
                    #pragma comment(lib,"Dapfor.GUI90uss.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI90uss.lib (Dapfor unicode release static library, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #else
                    #pragma comment(lib,"Dapfor.GUI90ss.lib") 
                    #pragma message("Automatically linking with Dapfor.GUI90ss.lib (Dapfor release static library, MFC shared DLL, Multithreaded Dll runtime library (switch /MD))") 
                #endif
            #endif//_DEBUG
        #endif
    #else
        #error This compiler version is not supported
    #endif//_MSC_VER

#endif//DF_NOT_MFC

#endif// _WIN64

#endif// __DF_GUI_AUTOLINK__H
