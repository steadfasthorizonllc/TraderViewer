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
/// \brief Transforms float-type value to its text presentation and vice versa.
///
/// \class CFloatFormat FloatFormat.h <Dapfor/Common/FloatFormat.h>
/// \code
/// 
/// Format examples:
///
/// 1. CFloatFormat(3).FormatStl(1234.5678f, 0);
/// 2. CFloatFormat(3).FormatStl(1234.56f, 0);
/// 3. CFloatFormat(3, true).FormatStl(1234.56f, 0);
/// 4. CFloatFormat(3, false, true, 0, '$').FormatStl(1234.56f, 0);
/// 5. CFloatFormat(3, false, true, '@').FormatStl(1234.56f, 0);
///
/// Output strings:
/// 1. 1 234,568
/// 2. 1 234,56
/// 3. 1 234,560
/// 4. 1 234,56$
/// 5. @1 234,56
///
/// \endcode
/////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CFloatFormat : public CFormat
{
public:
    enum
    {
        maxMantissaLen = 6,
    };
public:
    CFloatFormat(char  precision = 2,    
                 bool  bShowNonSignifyZero = false, 
                 bool  bShowZero = true, 
                 TCHAR chPrefix = _T('\0'),
                 TCHAR chSuffix = _T('\0'),
                 TCHAR chThousandSeparator = _T(' '));

    CFloatFormat(const CFloatFormat&);
    ~CFloatFormat();

    virtual TString FormatStl(float val, const CDataObject* pDO) const;    
    virtual bool    ParseStl(const TString&, float& val, const CDataObject* pDO) const;   

#ifndef DF_NOT_MFC
    virtual CString FormatMfc(float val, const CDataObject* pDO) const; 
    virtual bool    ParseMfc(const CString& str, float& val, const CDataObject* pDO) const;   
#endif//DF_NOT_MFC


    virtual CFormat* Clone() const;

    static  int  GetSerializeVertion();
    virtual void Serialize(CSerializer& serializer);    //Serializes the format

private:
    char  m_Precision;
    bool  m_ShowZero;
    bool  m_bShowNonSignifyZero;
    TCHAR m_Prefix;
    TCHAR m_Suffix;
    TCHAR m_ThousandSeparator;

private:
    DF_DECLARE_FORMAT()
};


}//namespace Common
 
}//namespace Dapfor
