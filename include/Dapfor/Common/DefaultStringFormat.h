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
/// \brief This format doesn't performs any actions. 
///
/// \class CDefaultStlStringFormat DefaultStringFormat.h <Dapfor/Common/DefaultStringFormat.h>
/////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CDefaultStlStringFormat : public CFormat
{
public:
    CDefaultStlStringFormat();                                     //Constructor 
    CDefaultStlStringFormat(const CDefaultStlStringFormat& format);   //Copy constructor
    ~CDefaultStlStringFormat();                                    //Destructor

    //Does nothing. The string returned by the format is the same as val.
    virtual TString FormatStl(const TString& val, const CDataObject* pDO) const;
    
    //Does nothing. Writes str to val without any modification.
    virtual bool    ParseStl(const TString& str, TString& val, const CDataObject* pDO) const;

#ifndef DF_NOT_MFC
    //The value, returned by the format is the same that val but it has CString type.
    virtual CString FormatMfc(const TString& val, const CDataObject* pDO) const;
    
    //Writes str to val with changing the type. The string is not changed.
    virtual bool    ParseMfc(const CString& str, TString& val, const CDataObject* pDO) const;
#endif


    virtual CFormat* Clone() const;
    static  int  GetSerializeVertion();
    virtual void Serialize(CSerializer& serializer);    //Serializes the format

private:
    DF_DECLARE_FORMAT()
};





#ifndef DF_NOT_MFC
/////////////////////////////////////////////////////////////////////////////
/// \brief This format performs no actions. 
///
/// \class CDefaultMfcStringFormat DefaultStringFormat.h <Dapfor/Common/DefaultStringFormat.h>
/////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CDefaultMfcStringFormat : public CFormat
{
public:
    CDefaultMfcStringFormat();                                      //Constructor 
    CDefaultMfcStringFormat(const CDefaultMfcStringFormat& format); //Copy constructor
    ~CDefaultMfcStringFormat();                                     //Destructor
    
    //The value, returned by the format is the same that val but it has TString type.
    virtual TString FormatStl(const CString& val, const CDataObject* pDO) const;
    
    //Writes str to val with changing the type. The string is not changed.
    virtual bool    ParseStl(const TString& str, CString& val, const CDataObject* pDO) const;
    
    //Does nothing. The string, returned by the format is the same that val.
    virtual CString FormatMfc(const CString& val, const CDataObject* pDO) const;
    
    //Does nothing. Writes str to val without any modification.
    virtual bool    ParseMfc(const CString& str, CString& val, const CDataObject* pDO) const;
    
    virtual CFormat* Clone() const;
    static  int      GetSerializeVertion();
    virtual void     Serialize(CSerializer& serializer);    //Serializes the format
    
private:
    DF_DECLARE_FORMAT()
};

#endif

}//namespace Common
 
}//namespace Dapfor
