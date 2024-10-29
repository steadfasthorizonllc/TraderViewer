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
/// \brief Transforms short-type value to its text presentation and vice versa.
///
/// \class CShortFormat ShortFormat.h <Dapfor/Common/ShortFormat.h>
/// \code
/// 
/// Format examples:
///
/// 1. CShortFormat().FormatStl(1234, 0);
/// 2. CShortFormat().FormatStl(-1234, 0);
/// 3. CShortFormat(CShortFormat.Hex, true, _T(' '), false, false).FormatStl(1234, 0);
/// 4. CShortFormat(CShortFormat.Hex, true, _T(' '), true, false).FormatStl(1234, 0);
/// 5. CShortFormat(CShortFormat.Hex, true, _T(' '), true, true).FormatStl(1234, 0);
///
/// Output strings:
///
/// 1. 1 234
/// 2. -1 234
/// 3. 4D2
/// 4. 0x4D2
/// 5. 0x04D2
///
/// \endcode
///
/// \file ShortFormat.h
/////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CShortFormat : public CFormat
{
public:
    /// Format styles
    enum Style
    {
        Decimal,    //!< Display short as decimal number
        Hex,        //!< Display short as hexadecimal number
    };

public:
    CShortFormat(Style = Decimal, 
                 bool showZero = true, 
                 TCHAR chThousandSeparator = _T(' '),
                 bool showHexPrefix = true,
                 bool showNonSignificantZero = true);
    
    CShortFormat(const CShortFormat&);
    ~CShortFormat();

    virtual TString FormatStl(short val, const CDataObject* pDO) const;    
    virtual bool    ParseStl(const TString& str, short& val, const CDataObject* pDO) const;   

#ifndef DF_NOT_MFC
    virtual CString FormatMfc(short val, const CDataObject* pDO) const; 
    virtual bool    ParseMfc(const CString& str, short& val, const CDataObject* pDO) const;   
#endif//DF_NOT_MFC

    virtual CFormat* Clone() const;

    static  int  GetSerializeVertion();
    virtual void Serialize(CSerializer& serializer);    //Serializes the format

    inline TCHAR GetSeparator() const;
    inline void SetSeparator(TCHAR chSeparator);

    inline Style GetStyle() const;
    inline void  SetStyle(Style style);


private:
    Style m_Style;
    bool  m_ShowZero;
    TCHAR  m_ThousandSeparator;
    bool  m_ShowHexPrefix;
    bool  m_ShowNonSignificantZero;

    DF_DECLARE_FORMAT();
};

inline TCHAR               CShortFormat::GetSeparator() const           {return m_ThousandSeparator;}
inline void                CShortFormat::SetSeparator(TCHAR separator)  {m_ThousandSeparator = separator;}
inline CShortFormat::Style CShortFormat::GetStyle() const               {return m_Style;}
inline void                CShortFormat::SetStyle(Style style)          {m_Style = style;}


}//namespace Common

}//namespace Dapfor 
