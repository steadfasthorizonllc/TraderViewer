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
/// \brief Transforms unsigned char-type value to its text presentation and vice versa.
///
/// \class CUCharFormat UCharFormat.h <Dapfor/Common/UCharFormat.h>
/// \code
/// 
/// Format examples:
///
/// Format examples:
///
/// 1. CUCharFormat(CUCharFormat::Decimal).FormatStl(65, 0);
/// 2. CUCharFormat(CUCharFormat::Decimal).FormatStl(165, 0);
/// 3. CUCharFormat(CUCharFormat::Hex, true, false, false).FormatStl(15, 0);
/// 4. CUCharFormat(CUCharFormat::Hex, true, true, false).FormatStl(15, 0);
/// 5. CUCharFormat(CUCharFormat::Hex, true, true, true).FormatStl(15, 0);
/// 6. CUCharFormat(CUCharFormat::Char).FormatStl(65, 0);
///
/// Output strings:
/// 1. 65
/// 2. 165
/// 3. F
/// 4. 0xF
/// 5. 0x0F
/// 6. A
///
/// \endcode
///
/// \file UCharFormat.h
/////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CUCharFormat : public CFormat
{
public:
    /// Format styles
    enum Style
    {
        Decimal, //!< Display char as a decimal number
        Hex,     //!< Display char as a hexadecimal number
        Char,    //!< Display char as ASCII symbol 
    } ;

public:
    //Constructors
    CUCharFormat(Style style = Char, bool showZero = true, bool showHexPrefix = true, bool showNonSignificantZero = true);
    CUCharFormat(const CUCharFormat&);
    ~CUCharFormat();

    virtual TString FormatStl(unsigned char val, const CDataObject* pDO) const;    
    virtual bool    ParseStl(const TString&, unsigned char& val, const CDataObject* pDO) const;   

#ifndef DF_NOT_MFC
    virtual CString FormatMfc(unsigned char val, const CDataObject* pDO) const; 
    virtual bool    ParseMfc(const CString& str, unsigned char& val, const CDataObject* pDO) const;   
#endif//DF_NOT_MFC


    virtual CFormat* Clone() const;

    static  int  GetSerializeVertion();
    virtual void Serialize(CSerializer& serializer);    //Serializes the format

    inline Style GetStyle() const;
    inline void  SetStyle(Style style);

private:
    Style m_Style;
    bool m_ShowZero;
    bool m_ShowHexPrefix;
    bool m_ShowNonSignificantZero;


    DF_DECLARE_FORMAT()
};

inline CUCharFormat::Style CUCharFormat::GetStyle() const           {return m_Style;}
inline void                CUCharFormat::SetStyle(Style style)      {m_Style = style;}

}//namespace Common
 
}//namespace Dapfor
