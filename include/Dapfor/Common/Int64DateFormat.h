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

//#include "wtypes.h"
//#include "winbase.h"

#include <Dapfor/Common/Common.h>
#include <Dapfor/Common/Format.h>
#include <Dapfor/Common/CommonPreferences.h>

struct _FILETIME;
typedef struct _FILETIME FILETIME;

namespace Dapfor
{
namespace Common
{


///////////////////////////////////////////////////////////////////////////
/// \brief This class formats time represented by 64-bit value that is the number of 100-nanosecond 
/// intervals since January 1, 1601. 
//
/// To get current time, use the static function CInt64DateFormat::Now()
///
/// \sa FILETIME structure in MSDN. 
///
/// \class CInt64DateFormat Int64DateFormat.h <Dapfor/Common/Int64DateFormat.h>
/// \code
/// Format examples:
///
/// CPreferences::SetDateFormat(CPreferences::DayMonthYear);
///
/// 1. CInt64DateFormat(CInt64DateFormat::date).FormatStl(CInt64DateFormat::Now(), 0);
/// 2. CInt64DateFormat(CInt64DateFormat::short_date).FormatStl(CInt64DateFormat::Now(), 0);
/// 3. CInt64DateFormat(CInt64DateFormat::time).FormatStl(CInt64DateFormat::Now(), 0);
/// 4. CInt64DateFormat(CInt64DateFormat::short_datemstime).FormatStl(CInt64DateFormat::Now(), 0);
///
/// CPreferences::SetDateFormat(CPreferences::MonthDayYear);
///
/// 5. CInt64DateFormat(CInt64DateFormat::date).FormatStl(CInt64DateFormat::Now(), 0);
/// 6. CInt64DateFormat(CInt64DateFormat::short_date).FormatStl(CInt64DateFormat::Now(), 0);
/// 7. CInt64DateFormat(CInt64DateFormat::time).FormatStl(CInt64DateFormat::Now(), 0);
/// 8. CInt64DateFormat(CInt64DateFormat::short_datemstime).FormatStl(CInt64DateFormat::Now(), 0);
///
/// CPreferences::SetDateFormat(CPreferences::MonthDayYear);
/// CPreferences::SetDateSeparator(_T("-"));
///
/// 9.  CInt64DateFormat(CInt64DateFormat::date).FormatStl(CInt64DateFormat::Now(), 0);
/// 10. CInt64DateFormat(CInt64DateFormat::short_date).FormatStl(CInt64DateFormat::Now(), 0);
/// 11. CInt64DateFormat(CInt64DateFormat::time).FormatStl(CInt64DateFormat::Now(), 0);
/// 12. CInt64DateFormat(CInt64DateFormat::short_datemstime).FormatStl(CInt64DateFormat::Now(), 0);

///
/// Output strings:
/// 1. 16/06/2007
/// 2. 16/06/07
/// 3. 12:39:10
/// 4. 16/06/07 12:39:10.875
///
/// 5. 06/16/2007
/// 6. 06/16/07
/// 7. 12:39:10
/// 8. 06/16/07 12:39:10.875
///
/// 9.  2007-06-16
/// 10. 07-06-16
/// 11. 12:39:10
/// 12. 07-06-16 12:39:10.875
/// \endcode
/// \file Int64DateFormat.h
///////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CInt64DateFormat : public CFormat
{
public:
    ///Data or time types
    enum Style
    {
        year        = 0x1,      //!< yyyy
        short_year  = 0x2,      //!< yy
        month       = 0x4,      //!< mm    1..12
        day         = 0x8,      //!< dd    1..31
        hour        = 0x10,     //!< hh    0..23
        minute      = 0x20,     //!< mm    0..59
        second      = 0x40,     //!< ss    0..59
        millisec    = 0x80,     //!< xxx   0..999

        //the most useful combinations
        date                = day | month | year,       //!< dd/mm/yyyy
        short_date          = day | month | short_year, //!< dd/mm/yy
        time                = hour | minute | second,   //!< hh:mm:ss
        mstime              = time | millisec,          //!< hh:mm:ss.xxx
        datetime            = date | time,              //!< dd/mm/yyyy hh:mm:ss
        datemstime          = date | mstime,            //!< dd/mm/yyyy hh:mm:ss.xxx
        short_datetime      = short_date | time,        //!< dd/mm/yy hh:mm:ss
        short_datemstime    = short_date | mstime,      //!< dd/mm/yy hh:mm:ss.xxx
    };


public:
    CInt64DateFormat(unsigned long nStyle);         
    CInt64DateFormat(const CInt64DateFormat&);
    ~CInt64DateFormat();

    virtual TString FormatStl(int64 val, const CDataObject* pDO) const;
    virtual bool    ParseStl(const TString&, int64& val, const CDataObject* pDO) const;

#ifndef DF_NOT_MFC
    virtual CString FormatMfc(int64 val, const CDataObject* pDO) const; 
    virtual bool    ParseMfc(const CString& str, int64& val, const CDataObject* pDO) const;   
#endif//DF_NOT_MFC


    virtual CFormat* Clone() const;

    ///Indicates whether the format presents a date.
    virtual bool IsDate() const;                
    
    ///Gets the format style that is a combination of CInt64DateFormat::Style enum.
    virtual unsigned long GetStyle() const;     

    ///Gets the local time that equals the number of 100-nanosecond intervals since January 1, 1601.
    static int64 Now();
    static int64 UtcNow();
    static int64 FileTimeToInt64(FILETIME ft);
    static FILETIME Int64ToFileTime(int64 ft);

    static  int  GetSerializeVertion();
    virtual void Serialize(CSerializer& serializer);            //Serializes the format

public:
    // A helper-function that transforms unformatted value of __int64 type into the formatted string, 
    // depending on the format style and the date type.
    static TString  FormatStl(int64 val,                           //Value to be formatted
                           const CDataObject* pDO,              //Pointer to a data object
                           unsigned long  style,                //Combination of CInt64DateFormat::Style enum
                           CPreferences::DateType dateType);    //Date type.
    
    // A helper-function that parses the formatted string which presents a date to the  value of __int64 type, 
    // depending on the format style and the date type.
    static bool ParseStl(const TString& text,                  //Formatted text to be parsed
                      int64& val,                           //Value, to which text is parsed
                      const CDataObject* pDO,               //Pointer to a data object
                      unsigned long style,                  //Combination of CInt64DateFormat::Style enum
                      CPreferences::DateType dateType);     //Date type.



private:
    CInt64DateFormat();
    unsigned long m_DateType;
    
private:
    DF_DECLARE_FORMAT()
};


}//namespace Common

}//namespace Dapfor

