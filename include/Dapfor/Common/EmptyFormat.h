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
#include <Dapfor/Common/Types.h>

namespace Dapfor
{
namespace Common
{

/////////////////////////////////////////////////////////////////////////////
/// \brief This format doesn't perform actions with non-formatted value and always returns an empty string.
///
/// \class CEmptyFormat EmptyFormat.h <Dapfor/Common/EmptyFormat.h>
/// \file EmptyFormat.h
/////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CEmptyFormat : public CFormat
{
public:
    CEmptyFormat(EnType type); //!< Constructor


#ifndef DF_NOT_MFC
    //MFC format functions
    virtual CString FormatMfc(const CString& val, const CDataObject* pDO) const; 
    virtual CString FormatMfc(const TString& val, const CDataObject* pDO) const; 
    virtual CString FormatMfc(char val,           const CDataObject* pDO) const;
    virtual CString FormatMfc(unsigned char val,  const CDataObject* pDO) const;
    virtual CString FormatMfc(short val,          const CDataObject* pDO) const;
    virtual CString FormatMfc(unsigned short val, const CDataObject* pDO) const;
    virtual CString FormatMfc(long val,           const CDataObject* pDO) const;
    virtual CString FormatMfc(unsigned long val,  const CDataObject* pDO) const;
    virtual CString FormatMfc(int64 val,          const CDataObject* pDO) const;
    virtual CString FormatMfc(bool val,           const CDataObject* pDO) const;
    virtual CString FormatMfc(float val,          const CDataObject* pDO) const;
    virtual CString FormatMfc(double val,         const CDataObject* pDO) const;
    virtual CString FormatMfc(CDataObject* val,   const CDataObject* pDO) const;
    virtual CString FormatMfc(const CValue& val,  const CDataObject* pDO) const;
    
    //MFC parse functions
    virtual bool ParseMfc(const CString& str, CString& val, const CDataObject* pDO) const; 
    virtual bool ParseMfc(const CString& str, TString& val, const CDataObject* pDO) const; 
    virtual bool ParseMfc(const CString& str, char& val, const CDataObject* pDO) const;    
    virtual bool ParseMfc(const CString& str, unsigned char& val, const CDataObject* pDO) const;   
    virtual bool ParseMfc(const CString& str, short& val, const CDataObject* pDO) const;   
    virtual bool ParseMfc(const CString& str, unsigned short& val, const CDataObject* pDO) const;  
    virtual bool ParseMfc(const CString& str, long& val, const CDataObject* pDO) const;
    virtual bool ParseMfc(const CString& str, unsigned long& val, const CDataObject* pDO) const;
    virtual bool ParseMfc(const CString& str, int64& val, const CDataObject* pDO) const;   
    virtual bool ParseMfc(const CString& str, bool& val, const CDataObject* pDO) const;
    virtual bool ParseMfc(const CString& str, float& val, const CDataObject* pDO) const;   
    virtual bool ParseMfc(const CString& str, CDataObject*& val, const CDataObject* pDO) const;
    virtual bool ParseMfc(const CString& str, double& val, const CDataObject* pDO) const;  
    virtual bool ParseMfc(const CString& str, CValue& val, const CDataObject* pDO) const;
#endif


    //STL format functions
#ifndef DF_NOT_MFC
    virtual TString FormatStl(const CString& val, const CDataObject* pDO) const; 
#endif      
    virtual TString FormatStl(const TString& val, const CDataObject* pDO) const;
    virtual TString FormatStl(char val, const CDataObject* pDO) const;
    virtual TString FormatStl(unsigned char val, const CDataObject* pDO) const;
    virtual TString FormatStl(short val, const CDataObject* pDO) const;
    virtual TString FormatStl(unsigned short val, const CDataObject* pDO) const;
    virtual TString FormatStl(long val, const CDataObject* pDO) const;
    virtual TString FormatStl(unsigned long val, const CDataObject* pDO) const;
    virtual TString FormatStl(int64 val, const CDataObject* pDO) const;
    virtual TString FormatStl(bool val, const CDataObject* pDO) const;
    virtual TString FormatStl(float val, const CDataObject* pDO) const;
    virtual TString FormatStl(double val, const CDataObject* pDO) const;
    virtual TString FormatStl(CDataObject* val, const CDataObject* pDO) const;
    virtual TString FormatStl(const CValue& val, const CDataObject* pDO) const;

    //STL parse functions
#ifndef DF_NOT_MFC
    virtual bool ParseStl(const TString& str, CString& val, const CDataObject* pDO) const; 
#endif      
    virtual bool ParseStl(const TString& str, TString&, const CDataObject* pDO) const; 
    virtual bool ParseStl(const TString& str, char& val, const CDataObject* pDO) const;    
    virtual bool ParseStl(const TString& str, unsigned char& val, const CDataObject* pDO) const;   
    virtual bool ParseStl(const TString& str, short& val, const CDataObject* pDO) const;   
    virtual bool ParseStl(const TString& str, unsigned short& val, const CDataObject* pDO) const;  
    virtual bool ParseStl(const TString& str, long& val, const CDataObject* pDO) const;
    virtual bool ParseStl(const TString& str, unsigned long& val, const CDataObject* pDO) const;
    virtual bool ParseStl(const TString& str, int64& val, const CDataObject* pDO) const;   
    virtual bool ParseStl(const TString& str, bool& val, const CDataObject* pDO) const;
    virtual bool ParseStl(const TString& str, float& val, const CDataObject* pDO) const;   
    virtual bool ParseStl(const TString& str, CDataObject*& val, const CDataObject* pDO) const;
    virtual bool ParseStl(const TString& str, double& val, const CDataObject* pDO) const;  
    virtual bool ParseStl(const TString& str, CValue& val, const CDataObject* pDO) const;

    virtual CFormat* Clone() const;

    static  int  GetSerializeVertion();
    virtual void Serialize(CSerializer& serializer);    //Serializes the format

private:
    CEmptyFormat();

private:
    DF_DECLARE_FORMAT()
};


}

}//namespace Dapfor
