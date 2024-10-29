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
/// \brief Transforms char-type value to its text presentation and vice versa.
///
/// \class CCharFormat CharFormat.h <Dapfor/Common/CharFormat.h>
/// \code
/// 
/// Format examples:
///
/// 1. CCharFormat(CCharFormat::Decimal).FormatStl(65, 0);
/// 2. CCharFormat(CCharFormat::Decimal).FormatStl(165, 0);
/// 3. CCharFormat(CCharFormat::Hex, true, false, false).FormatStl(15, 0);
/// 4. CCharFormat(CCharFormat::Hex, true, true, false).FormatStl(15, 0);
/// 5. CCharFormat(CCharFormat::Hex, true, true, true).FormatStl(15, 0);
/// 6. CCharFormat(CCharFormat::Char).FormatStl(65, 0);
///
/// Output strings:
/// 1. 65
/// 2. -91
/// 3. F
/// 4. 0xF
/// 5. 0x0F
/// 6. A
///
/// \endcode
/// \file CharFormat.h
/////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CCharFormat : public CFormat
{
public:
    ///Styles 
    enum Style
    {
        Decimal,    //!< Display char as a decimal number
        Hex,        //!< Display char as a hexadecimal number
        Char,       //!< Display char as ASCII symbol 
    };

public:
    //Constructors
    CCharFormat(Style style = Char, bool showZero = true, bool showHexPrefix = true, bool showNonSignificantZero = true);
    CCharFormat(const CCharFormat& format);
    ~CCharFormat();

    virtual TString FormatStl(char val, const CDataObject* pDO) const; 
    virtual bool    ParseStl(const TString&, char& val, const CDataObject* pDO) const;    

#ifndef DF_NOT_MFC
    virtual CString FormatMfc(char val, const CDataObject* pDO) const; 
    virtual bool    ParseMfc(const CString& str, char& val, const CDataObject* pDO) const;   
#endif//DF_NOT_MFC

    virtual CFormat* Clone() const;

    static  int  GetSerializeVertion();
    virtual void Serialize(CSerializer& serializer);    //Serializes the format

    inline Style GetStyle() const;

private:
    Style m_Style;
    bool  m_ShowZero;
    bool  m_ShowHexPrefix;
    bool  m_ShowNonSignificantZero;

    DF_DECLARE_FORMAT()
};

inline CCharFormat::Style CCharFormat::GetStyle() const             {return m_Style;}


}//namespace Common
 
}//namespace Dapfor
