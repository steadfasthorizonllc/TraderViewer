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
#include <Dapfor/Common/Format.h>
#include <Dapfor/Common/CommonPreferences.h>

namespace Dapfor
{
namespace Common
{

///////////////////////////////////////////////////////////////////////////
/// \brief Transforms time represented by 32-bit value that is a number of seconds elapsed
/// since midnight, January 1, 1970. 
/// 
/// To get the current time, use the static function CLongDateFormat::Now()
///
/// \note The upper date limit is January 18, 2038
///
/// \class CLongDateFormat LongDateFormat.h <Dapfor/Common/LongDateFormat.h>
/// \code
/// Format examples:
///
/// CPreferences::SetDateType(CPreferences::DayMonthYear);
///
/// 1. CLongDateFormat(CLongDateFormat::date).FormatStl(CLongDateFormat::Now(), 0);
/// 2. CLongDateFormat(CLongDateFormat::short_date).FormatStl(CLongDateFormat::Now(), 0);
/// 3. CLongDateFormat(CLongDateFormat::time).FormatStl(CLongDateFormat::Now(), 0);
/// 4. CLongDateFormat(CLongDateFormat::short_datetime).FormatStl(CLongDateFormat::Now(), 0);
///
/// CPreferences::SetDateType(CPreferences::MonthDayYear);
///
/// 5. CLongDateFormat(CLongDateFormat::date).FormatStl(CLongDateFormat::Now(), 0);
/// 6. CLongDateFormat(CLongDateFormat::short_date).FormatStl(CLongDateFormat::Now(), 0);
/// 7. CLongDateFormat(CLongDateFormat::time).FormatStl(CLongDateFormat::Now(), 0);
/// 8. CLongDateFormat(CLongDateFormat::short_datetime).FormatStl(CLongDateFormat::Now(), 0);
///
/// CPreferences::SetDateType(CPreferences::YearMonthDay);
/// CPreferences::SetDateSeparator(_T("-"));
///
/// 9. CLongDateFormat(CLongDateFormat::date).FormatStl(CLongDateFormat::Now(), 0);
/// 10. CLongDateFormat(CLongDateFormat::short_date).FormatStl(CLongDateFormat::Now(), 0);
/// 11. CLongDateFormat(CLongDateFormat::time).FormatStl(CLongDateFormat::Now(), 0);
/// 12. CLongDateFormat(CLongDateFormat::short_datetime).FormatStl(CLongDateFormat::Now(), 0);

///
/// Output strings:
///
/// 1. 16/06/2007
/// 2. 16/06/07
/// 3. 13:18:58
/// 4. 16/06/07 13:18:58
///
/// 5. 06/16/2007
/// 6. 06/16/07
/// 7. 13:18:58
/// 8. 06/16/07 13:18:58
///
/// 9.  2007-06-16
/// 10. 07-06-16
/// 11. 13:18:58
/// 12. 07-06-16 13:18:58
///
/// \endcode
/// \file LongDateFormat.h
///////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CLongDateFormat : public CFormat
{
public:
    /// Format style
    enum Style
    {
        year        = 0x1,      //!< yyyy
        short_year  = 0x2,      //!< yy
        month       = 0x4,      //!< mm    1..12
        day         = 0x8,      //!< dd    1..31
        hour        = 0x10,     //!< hh    0..23
        minute      = 0x20,     //!< mm    0..59
        second      = 0x40,     //!< ss    0..59

        //the most useful combinations
        date                = day | month | year,       //!< dd/mm/yyyy
        short_date          = day | month | short_year, //!< dd/mm/yy
        time                = hour | minute | second,   //!< hh:mm:ss
        datetime            = date | time,              //!< dd/mm/yyyy hh:mm:ss
        short_datetime      = short_date | time,        //!< dd/mm/yy hh:mm:ss
    };


public:
    CLongDateFormat(unsigned long nType);   
    CLongDateFormat(const CLongDateFormat&);
    ~CLongDateFormat();

    virtual TString FormatStl(long val, const CDataObject* pDO) const;
    virtual bool    ParseStl(const TString&, long& val, const CDataObject* pDO) const;

#ifndef DF_NOT_MFC
    virtual CString FormatMfc(long val, const CDataObject* pDO) const; 
    virtual bool    ParseMfc(const CString& str, long& val, const CDataObject* pDO) const;   
#endif//DF_NOT_MFC


    virtual CFormat* Clone() const;

    ///Gets local time, that is a number of seconds elapsed since midnight, January 1, 1970
    static long Now();                                  

    ///Indicates whether a format presents a date.
    virtual bool  IsDate() const;                       
    
    ///Gets a format style which is a combination of CLongDateFormat::Style enumeration.
    unsigned long GetStyle() const;                     

    static  int  GetSerializeVertion();
    virtual void Serialize(CSerializer& serializer);    //Serializes this format

    
    //Helpers to format and parse the and time...

    //The function converts a non-formatted value of long type to the string
    static TString  FormatStl(long val,                            //Value to be formatted
                           const CDataObject* pDO,              //Pointer to a data object
                           unsigned long  style,                //Combination of the CLongDateFormat::Style enumeration
                           CPreferences::DateType dateType);    //Date type.
    
    //The function converts a string to the non-formatted value of long type
    static bool         ParseStl(const TString& text,              //Formatted text to be parsed
                              long& val,                        //Value, to which text is parsed
                              const CDataObject* pDO,           //Pointer to a data object
                              unsigned long style,              //Combination of the CLongDateFormat::Style enum
                              CPreferences::DateType dateType); //Date type.


private:
    CLongDateFormat();  
    unsigned long  m_DateType;

private:
    DF_DECLARE_FORMAT()
};


}//namespace Common

}//namespace Dapfor

