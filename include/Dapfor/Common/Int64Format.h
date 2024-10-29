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

namespace Dapfor
{
namespace Common
{

/////////////////////////////////////////////////////////////////////////////
/// \brief Transforms __int64 - type value to its text presentation and vice versa.
///
/// \class CInt64Format Int64Format.h <Dapfor/Common/Int64Format.h>
/// \code
/// 
/// Format examples:
///
/// 1. CInt64Format(CInt64Format::Decimal).FormatStl(123456789012, 0);
/// 2. CInt64Format(CInt64Format::Decimal).FormatStl(-123456789012, 0);
/// 3. CInt64Format(CInt64Format::Hex, true, _T(' '), false, false).FormatStl(123456789012, 0);
/// 4. CInt64Format(CInt64Format::Hex).FormatStl(123456789012, 0);
/// 5. CInt64Format(CInt64Format::Hex, true, _T(' '), true, true).FormatStl(123456789012, 0);
///
/// Output strings:
///
/// 1. 123 456 789 012
/// 2. -123 456 789 012
/// 3. 1CBE991A14
/// 4. 0x1CBE991A14
/// 5. 0x0000001CBE991A14
///
/// \endcode
/// \file Int64Format.h
/////////////////////////////////////////////////////////////////////////////

class DF_COMMON_API CInt64Format : public CFormat
{
public:
    ///Format styles
    enum Style
    {
        Decimal,    //!< Display int64 as a decimal number
        Hex,        //!< Display int64 as a hexadecimal number
    };

public:
    CInt64Format(Style style = Decimal, 
                 bool  showZero = true, 
                 TCHAR thousandSeparator = _T(' '),
                 bool  showHexPrefix = true,
                 bool  showNonSignificantZero = false);
    
    CInt64Format(const CInt64Format&);
    ~CInt64Format();

    virtual TString FormatStl(int64 val, const CDataObject* pDO) const;    
    virtual bool    ParseStl(const TString&, int64& val, const CDataObject* pDO) const;   

#ifndef DF_NOT_MFC
    virtual CString FormatMfc(int64 val, const CDataObject* pDO) const; 
    virtual bool    ParseMfc(const CString& str, int64& val, const CDataObject* pDO) const;   
#endif//DF_NOT_MFC


    virtual CFormat* Clone() const;

    static  int  GetSerializeVertion();
    virtual void Serialize(CSerializer& serializer);    //Serializes the format

    inline TCHAR GetSeparator() const;
    inline void  SetSeparator(TCHAR chSeparator);

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

inline TCHAR                CInt64Format::GetSeparator() const          {return m_ThousandSeparator;}
inline void                 CInt64Format::SetSeparator(TCHAR separator) {m_ThousandSeparator = separator;}
inline CInt64Format::Style  CInt64Format::GetStyle() const              {return m_Style;}
inline void                 CInt64Format::SetStyle(Style style)         {m_Style = style;}


}//namespace Common
 
}//namespace Dapfor
