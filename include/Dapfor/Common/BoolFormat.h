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
/// \brief Transforms bool-type value to its text presentation and vice versa.
///
/// \class CBoolFormat BoolFormat.h <Dapfor/Common/CBoolFormat.h>
/// \code
/// 
/// Format examples:
///
/// 1. CBoolFormat().FormatStl(true, 0);
/// 2. CBoolFormat().FormatStl(false, 0);
///
/// Output strings:
/// 1. true
/// 2. false
///
/// \endcode
/////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CBoolFormat : public CFormat
{
public:
    CBoolFormat();                      //!< Constructor
    CBoolFormat(const CBoolFormat&);    //!< Copy constructor
    ~CBoolFormat();                     //!< Destructor

    virtual TString FormatStl(bool val, const CDataObject* pDO) const; 
    virtual bool    ParseStl(const TString& str, bool& val, const CDataObject* pDO) const;   

#ifndef DF_NOT_MFC
    virtual CString FormatMfc(bool val, const CDataObject* pDO) const; 
    virtual bool    ParseMfc(const CString& str, bool& val, const CDataObject* pDO) const;   
#endif//DF_NOT_MFC

    virtual CFormat* Clone() const;

    static  int  GetSerializeVertion();
    virtual void Serialize(CSerializer& serializer);    //Serializes the format

private:
    DF_DECLARE_FORMAT()
};


}//namespace Common
 
}//namespace Dapfor

