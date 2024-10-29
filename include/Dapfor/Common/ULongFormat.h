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
/// \brief Transforms unsigned long-type value to its text presentation and vice versa.
///
/// \class CULongFormat ULongFormat.h <Dapfor/Common/ULongFormat.h>
/// \code
/// 
/// Format examples:
///
/// 1. CULongFormat().FormatStl(1234567, 0);
/// 2. CULongFormat().FormatStl(-1234567, 0);
/// 3. CULongFormat(CULongFormat.Hex, true, _T(' '), false, false).FormatStl(1234567, 0);
/// 4. CULongFormat(CULongFormat.Hex, true, _T(' '), true, false).FormatStl(1234567, 0);
/// 5. CULongFormat(CULongFormat.Hex, true, _T(' '), true, true).FormatStl(1234567, 0);
///
/// Output strings:
///
/// 1. 1 234 567
/// 2. 4 293 732 729
/// 3. 12D687
/// 4. 0x12D687
/// 5. 0x0012D687
///
/// \endcode
///
/// \file ULongFormat.h
/////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CULongFormat : public CFormat
{
public:
    ///Format styles
    enum Style
    {
        Decimal,    //!< Display long as decimal number
        Hex,        //!< Display long as hexadecimal number
    };
    
public:
    CULongFormat(Style = Decimal, 
                 bool showZero = true, 
                 TCHAR thousandSeparator = _T(' '),
                 bool showHexPrefix = true,
                 bool showNonSignificantZero = false);
    
    CULongFormat(const CULongFormat&);
    ~CULongFormat();


    virtual TString FormatStl(unsigned long val, const CDataObject* pDO) const;    
    virtual bool    ParseStl(const TString&, unsigned long& val, const CDataObject* pDO) const;   

#ifndef DF_NOT_MFC
    virtual CString FormatMfc(unsigned long val, const CDataObject* pDO) const; 
    virtual bool    ParseMfc(const CString& str, unsigned long& val, const CDataObject* pDO) const;   
#endif//DF_NOT_MFC


    virtual CFormat* Clone() const;

    static  int  GetSerializeVertion();
    virtual void Serialize(CSerializer& serializer);

    inline TCHAR GetSeparator() const;
    inline void  SetSeparator(TCHAR chSeparator);

    inline Style GetStyle() const;
    inline void  SetStyle(Style style);

private:
    Style m_Style;
    bool  m_ShowZero;
    TCHAR  m_ThousandSeparator;
    bool  m_ShowHexPrefix;
    bool  m_ShowNonSignificantZero;

private:
    DF_DECLARE_FORMAT()
};


inline void                 CULongFormat::SetSeparator(TCHAR separator) {m_ThousandSeparator = separator;}
inline TCHAR                CULongFormat::GetSeparator() const          {return m_ThousandSeparator;}
inline CULongFormat::Style  CULongFormat::GetStyle() const              {return m_Style;}
inline void                 CULongFormat::SetStyle(Style style)         {m_Style = style;}


}//namespace Common
 
}//namespace Dapfor
