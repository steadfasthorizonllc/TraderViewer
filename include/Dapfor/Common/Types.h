/////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2007-2010 Dapfor
//                                                                         
// This file is part of the Dapfor software, and may only be used, modified, and distributed 
// under the terms of the Dapfor LICENSE AGREEMENT FOR MFC GRID SOFTWARE.
// (See accompanying file lisense.txt or open the license at http://www.dapfor.com/license_agreement_v2.aspx)
// By continuing to use, modify, or distribute this file you indicate that you have read the license 
// and fully understand and accept it.
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __DF__COMMON_TYPES__H
#define __DF__COMMON_TYPES__H

#pragma warning(disable : 4786) //the identifier was truncated to '255' characters in the debug information

#include <Dapfor/Common/Common.h>

#include <tchar.h>
#include <string>
#include <exception>

namespace Dapfor
{

namespace Common
{

/// Types used by the library
enum EnType
{
    Undefined,      //!< Undefined type
    MfcString,      //!< CString
    StlString,      //!< STL string
    Char,           //!< Signed char
    UChar,          //!< Unsigned char
    Short,          //!< 16-bit Signed short   (short)
    UShort,         //!< 16-bit unsigned value (unsigned shot)
    Long,           //!< 32-bit signed value   (long)
    ULong,          //!< 32-bit unsigned value (unsigned long)
    Int64,          //!< 64-bit signed value (__int64)
    Bool,           //!< Boolean value (bool)
    Float,          //!< 32-bit floating-point number (float)
    Double,         //!< 64-bit floating-point number (double)
    ObjectPtr,      //!< pointer to CDataObject
    Value,          //!< One of the main primitive types or pointer to CDataObject
};

typedef long FID;                   //!< Field identifier

const FID allFields = -1;           //!< All fields
const FID fieldNotSpecified = -2;   //!< Unspecified field


typedef __int64 int64;              //!< 64-bit signed integer value

#ifdef _UNICODE 
    typedef std::wstring TString;   //!< wide STL string
#else 
    typedef std::string TString;    //!< STL string
#endif




/// \brief Base class, used by Common library.
struct DF_COMMON_API CommonException : public std::exception
{
    ///Constructor
    ///\param[in] msg Text message
    CommonException(const char* msg) : std::exception(msg){}
};

struct DF_COMMON_API ProductInfo
{
    static TString GetVersion();
    static TString GetProductName();
    static TString GetCompanyName();
    static TString GetCopyright();
};

}

}//namespace Dapfor

#endif//__DF__COMMON_TYPES__H
