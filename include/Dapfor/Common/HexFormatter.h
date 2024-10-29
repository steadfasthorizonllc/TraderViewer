/////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2007-2010 Dapfor
//                                                                         
// This file is part of the Dapfor software, and may only be used, modified, and distributed 
// under the terms of the Dapfor LICENSE AGREEMENT FOR MFC GRID SOFTWARE.
// (See accompanying file lisense.txt or open the license at http://www.dapfor.com/license_agreement_v2.aspx)
// By continuing to use, modify, or distribute this file you indicate that you have read the license 
// and fully understand and accept it.
/////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <Dapfor/Common/Common.h>
#include <Dapfor/Common/Types.h>

namespace Dapfor
{
namespace Common
{


///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Helper that converts value to a hexadecimal string and vice versa
/// 
/// \class  CHexFormatter HexFormatter.h Dapfor/Common/HexFormatter.h
/// \file HexFormatter.h
///////////////////////////////////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CHexFormatter
{
public:
    //Functions to convert a non-formatted falues to a hexadecimal string
    static TString ToString(char val, bool showNonSignificantZeros);
    static TString ToString(unsigned char val, bool showNonSignificantZeros);
    static TString ToString(short val, bool showNonSignificantZeros);
    static TString ToString(unsigned short val, bool showNonSignificantZeros);
    static TString ToString(long val, bool showNonSignificantZeros);
    static TString ToString(unsigned long val, bool showNonSignificantZeros);
    static TString ToString(int64 val, bool showNonSignificantZeros);
    static TString ToString(int64 val, int minDigitsCount, bool showNonSignificantZeros);

    //Functions to convert a hexadecimal string to a non-formatted value
    static bool ToHex(const TString& str, char& val);
    static bool ToHex(const TString& str, unsigned char& val);
    static bool ToHex(const TString& str, short& val);
    static bool ToHex(const TString& str, unsigned short& val);
    static bool ToHex(const TString& str, long& val);
    static bool ToHex(const TString& str, unsigned long& val);
    static bool ToHex(const TString& str, int64& val);
};


}//namespace Common

}//namespace Dapfor
