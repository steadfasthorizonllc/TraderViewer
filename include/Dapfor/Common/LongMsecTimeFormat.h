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
#include <Dapfor/Common/Format.h>


namespace Dapfor
{
namespace Common
{

/////////////////////////////////////////////////////////////////////////////
/// \brief Format for long-type values representing time in milliseconds.
///
/// The time is stored as long value. 
/// Therefore for signed values, the format will wrap interval around -24,86 .. 24.86 days
/// and for unsigned values around to zero for 49.7 days.
///
/// \class  CLongMsecTimeFormat LongMsecTimeFormat.h Dapfor/Common/LongMsecTimeFormat.h
/// \code
/// 
/// Format examples:
///
/// 1. CLongMsecTimeFormat(CLongMsecTimeFormat::time).FormatStl(1234567, 0);
/// 2. CLongMsecTimeFormat(CLongMsecTimeFormat::day_time).FormatStl(1234567, 0);
/// 3. CLongMsecTimeFormat(CLongMsecTimeFormat::mstime).FormatStl(1234567, 0);
/// 4. CLongMsecTimeFormat(CLongMsecTimeFormat::day_mstime).FormatStl(1234567890, 0);

/// 5. CLongMsecTimeFormat(CLongMsecTimeFormat::time, true).FormatStl(1234567, 0);
/// 6. CLongMsecTimeFormat(CLongMsecTimeFormat::day_time, true).FormatStl(1234567, 0);
/// 7. CLongMsecTimeFormat(CLongMsecTimeFormat::mstime, true).FormatStl(1234567, 0);
/// 8. CLongMsecTimeFormat(CLongMsecTimeFormat::day_mstime, true).FormatStl(1234567890, 0);

///
/// Output strings:
/// 1. 20:34
/// 2. 20:34
/// 3. 20:34.567
/// 4. 14 6:56:07.890
///
/// 5. 00:20:34
/// 6. 0 00:20:34
/// 7. 00:20:34.567
/// 8. 14 06:56:07.890
///
/// \endcode
///
/// \file LongMsecTimeFormat.h
/////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CLongMsecTimeFormat : public CFormat
{
public:

    ///Format styles
    enum Style
    {
        day         = 0x01,     //!< dd    1..31
        hour        = 0x02,     //!< hh    0..23
        minute      = 0x04,     //!< mm    0..59
        second      = 0x08,     //!< ss    0..59
        millisec    = 0x10,     //!< xxx   0..999

        //the most useful combinations
        time                = hour | minute | second,   //!< hh:mm:ss
        day_time            = day  | time,              //!< dd hh:mm:ss
        mstime              = time | millisec,          //!< hh:mm:ss.xxx
        day_mstime          = day  | mstime,            //!< dd hh:mm:ss.xxx
    };

public:
    CLongMsecTimeFormat(unsigned long style,                    //Combination of the Style enumeration
                        bool showNonSignificative = false,      //Indicates whether it should show non-significant zeros
                        const TString& timeSuffix = _T(""),     //Suffix following the time.
                        const TString& daySuffix = _T(""));     //Suffix following the days.

    ~CLongMsecTimeFormat();

    //Formats long-type value representing time in milliseconds. The range is: -24,86 .. 24.86 days
    virtual TString FormatStl(long val, const CDataObject* pDO) const;

    //Converts formatted STL string to a long-type value representing time in milliseconds.
    virtual bool    ParseStl(const TString& str, long& val, const CDataObject* pDO) const;

#ifndef DF_NOT_MFC
    //Formats long-type value representing time in milliseconds. The range is: -24,86 .. 24.86 days
    virtual CString FormatMfc(long val, const CDataObject* pDO) const; 

    //Converts formatted MFC string to a long-type value representing time in milliseconds.
    virtual bool    ParseMfc(const CString& str, long& val, const CDataObject* pDO) const;   
#endif//DF_NOT_MFC

    virtual CFormat* Clone() const;

    virtual bool IsDate() const;                                
    virtual unsigned long GetStyle() const;     

    static  int  GetSerializeVertion();
    virtual void Serialize(CSerializer& serializer);            


protected:
    CLongMsecTimeFormat();

private:
    unsigned long   m_TimeFormat;
    bool            m_ShowNonSignificative;
    TString*        m_DaySuffix;
    TString*        m_TimeSuffix;

private:
    DF_DECLARE_FORMAT();
};





}//namespace Common

}//namespace Dapfor

