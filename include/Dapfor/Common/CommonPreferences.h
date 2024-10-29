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

//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Global preferences of Common library.
///
/// \class CPreferences CommonPreferences.h <Dapfor/Common/CommonPreferences.h>
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CPreferences
{
public:

    ///This enum specifies date presentation for different cultures and it is used by date formats.
    enum DateType
    {
        DayMonthYear,   //!< The date is presented as Day - Month - Year
        MonthDayYear,   //!< The date is presented as Month - Day - Year
        YearMonthDay,   //!< The date is presented as Year - Month - Day 

        DefaultDateFormat = DayMonthYear,
    };
public:

    
    static void         SetDateType(DateType dateFormat);           //!< Sets a new date format
    static DateType     GetDateType();                              //!< Gets a current date format

    static TString      GetDateSeparator();                         //!< Gets a current date separator
    static TString      GetTimeSeparator();                         //!< Gets a current time separator
    static TString      GetMillisecondSeparator();                  //!< Gets a current millisecond separator

    static void         SetDateSeparator(const TString& separator = _T("/"));       //!< Sets a new date separator
    static void         SetTimeSeparator(const TString& separator = _T(":"));       //!< Sets a new time separator
    static void         SetMillisecondSeparator(const TString& separator = _T("."));//!< Sets a new millisecond separator

private:
    //private constructors & methods to prevent from unwanted use
    CPreferences();

private:
    //Point implementation interface
    struct Impl;
    friend Impl;
};


}

}


