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
#include <string>


namespace Dapfor
{

namespace Common
{

class DF_COMMON_API CWideStringHelper
{
public:
    static std::string  ToString(const std::wstring& str);
    static std::wstring ToWString(const std::string& str);
    static char    ToChar(wchar_t wch);
    static wchar_t ToWChar(char ch);
};

} //namespace Common

} //namespace Dapfor
