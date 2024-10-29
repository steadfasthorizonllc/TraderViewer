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
/// \brief Transforms long-type value to its text presentation and vice versa.
///
/// \class CLongFormat LongFormat.h <Dapfor/Common/LongFormat.h>
/// \code
/// 
/// Format examples:
///
/// 1. CLongFormat().FormatStl(1234567, 0);
/// 2. CLongFormat().FormatStl(-1234567, 0);
/// 3. CLongFormat(CLongFormat.Hex, true, _T(' '), false, false).FormatStl(1234567, 0);
/// 4. CLongFormat(CLongFormat.Hex, true, _T(' '), true, false).FormatStl(1234567, 0);
/// 5. CLongFormat(CLongFormat.Hex, true, _T(' '), true, true).FormatStl(1234567, 0);
///
/// Output strings:
/// 1. 1 234 567
/// 2. -1 234 567
/// 3. 12D687
/// 4. 0x12D687
/// 5. 0x0012D687
///
/// \endcode
///
/// \file LongFormat.h
/////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CLongFormat : public CFormat
{
public:
    ///Format styles
    enum Style
    {
        Decimal,    //!< Display long as decimal number
        Hex,        //!< Display long as hexadecimal number
    };

public:
    CLongFormat( Style = Decimal, 
                 bool showZero = true, 
                 TCHAR thousandSeparator = _T(' '),
                 bool showHexPrefix = true,
                 bool showNonSignificantZero = false);
    
    CLongFormat(const CLongFormat&);
    ~CLongFormat();

    virtual TString FormatStl(long val, const CDataObject* pDO) const; 
    virtual bool    ParseStl(const TString&, long& val, const CDataObject* pDO) const;    

#ifndef DF_NOT_MFC
    virtual CString FormatMfc(long val, const CDataObject* pDO) const; 
    virtual bool    ParseMfc(const CString& str, long& val, const CDataObject* pDO) const;   
#endif//DF_NOT_MFC

    virtual CFormat* Clone() const;

    static  int  GetSerializeVertion();
    virtual void Serialize(CSerializer& serializer);    //Serializes this format

    inline TCHAR GetSeparator() const;
    inline void SetSeparator(TCHAR chSeparator);

    inline Style GetStyle() const;
    inline void  SetStyle(Style style);

private:
    Style m_Style;
    bool  m_ShowZero;
    TCHAR m_ThousandSeparator;
    bool  m_ShowHexPrefix;
    bool  m_ShowNonSignificantZero;

private:
    DF_DECLARE_FORMAT()
};


inline TCHAR              CLongFormat::GetSeparator() const          {return m_ThousandSeparator;}
inline void               CLongFormat::SetSeparator(TCHAR separator) {m_ThousandSeparator = separator;}
inline CLongFormat::Style CLongFormat::GetStyle() const              {return m_Style;}
inline void               CLongFormat::SetStyle(Style style)         {m_Style = style;}


}//namespace Common
 
}//namespace Dapfor
