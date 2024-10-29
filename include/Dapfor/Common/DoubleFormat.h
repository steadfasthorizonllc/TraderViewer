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
/// \brief Transforms double-type value to its text presentation and vice versa.
///
/// \class CDoubleFormat DoubleFormat.h <Dapfor/Common/DoubleFormat.h>
/// \code
/// 
/// Format examples:
///
/// 1. CDoubleFormat(3).FormatStl(1234.5678, 0);
/// 2. CDoubleFormat(3).FormatStl(1234.56, 0);
/// 3. CDoubleFormat(3, true).FormatStl(1234.56, 0);
/// 4. CDoubleFormat(3, false, true, 0, '$').FormatStl(1234.56, 0);
/// 5. CDoubleFormat(3, false, true, '@').FormatStl(1234.56, 0);
///
/// Output strings:
/// 1. 1 234,568
/// 2. 1 234,56
/// 3. 1 234,560
/// 4. 1 234,56$
/// 5. @1 234,56
///
/// \endcode
/// \file DoubleFormat.h
/////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CDoubleFormat : public CFormat
{
public:
    enum
    {
        maxMantissaLen = 9,
    };
public:
    CDoubleFormat(char  precision = 3,   
                  bool  showNonSignificantZero = false, 
                  bool  showZero = true, 
                  TCHAR chPrefix = _T('\0'),
                  TCHAR chSuffix = _T('\0'),
                  TCHAR chThousandSeparator = _T(' '));

    CDoubleFormat(const CDoubleFormat&);
    ~CDoubleFormat();

    virtual TString FormatStl(double val, const CDataObject* pDO) const;   
    virtual bool    ParseStl(const TString& str, double& val, const CDataObject* pDO) const;

#ifndef DF_NOT_MFC
    virtual CString FormatMfc(double val, const CDataObject* pDO) const; 
    virtual bool    ParseMfc(const CString& str, double& val, const CDataObject* pDO) const;   
#endif//DF_NOT_MFC


    virtual CFormat* Clone() const;

    static  int  GetSerializeVertion();
    virtual void Serialize(CSerializer& serializer);    //Serializes the format

private:
    char  m_Precision;
    bool  m_ShowZero;
    bool  m_ShowNonSignificantZero;
    TCHAR m_Prefix;
    TCHAR m_Suffix;
    TCHAR m_ThousandSeparator;

private:
    DF_DECLARE_FORMAT()
};


}//namespace Common
 
}//namespace Dapfor

