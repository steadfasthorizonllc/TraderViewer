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
#include <Dapfor/Common/Types.h>
#include <Dapfor/Common/FormatFactory.h>

#include <vector>

#include "assert.h"

namespace Dapfor
{
namespace Common
{

class CDataObject;
class CValue;
class CSerializer;


//////////////////////////////////////////////////////////////////////////
/// \brief Base class for all the formats that transform the unformatted value returned by CDataObject to its text
/// presentation and vice versa.
///
/// \par Thread safety
/// Thread safety depends on implementation in children objects. 
/// Usually the formats are not thread-safe. But if they are used in the static field maps, 
/// organized by the macros DF_DECLARE_FIELD_MAP(), etc, their usage is safe.
///
/// \class CFormat Format.h <Dapfor/Common/Format.h>
///
/// \par Example
/// \include custom_format.example
///
/// \file Format.h
//////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CFormat
{
public:
    virtual ~CFormat(); //!< Virtual destructor


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

    virtual bool ParseStl(const TString& str, TString& val, const CDataObject* pDO) const; 
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

    inline  EnType      GetType() const;                    //!< Gets a format type.
    
    virtual bool        IsDate() const;                     //!< Indicates whether the format presents a date.
    virtual bool        IsEnum() const;                     //!< Indicates whether the format presents an enumeration.
    
    virtual CFormat*    Clone() const = 0;                  //!< Creates a deep copy of a format

    static CFormat&     GetDefaultFormat(EnType nType);     //!< Gets a default format

    //Serialization
    virtual TString     GetFormatName() const;              //!< Gets format name
    virtual bool        IsSerializableType() const;         //!< Indicates whether the format is serializable
    virtual void        Serialize(CSerializer& serializer); //!< Serializes a format
    static  int         GetSerializeVertion();              //!< Serialization version

protected:
    CFormat(EnType nType);                                  //!< Constructor.
    CFormat(const CFormat&);                                //!< Copy constructor.

private:
    CFormat& operator = (const CFormat&);

private:
    EnType  m_Type;
};



inline EnType CFormat::GetType() const {return m_Type;}

}//namespace Common

}//namespace Dapfor


///@name Field declarations
///@{

/// \def DF_DECLARE_FORMAT()
/// \brief Declares child class that derives from the CFormat as serialisable one. 
#define DF_DECLARE_FORMAT()                                      \
public:                                                          \
    static Dapfor::Common::CFormat* CreateFormat();         \
    virtual bool IsSerializableType() const;                     \
    virtual Dapfor::Common::TString GetFormatName() const;  \
    static  Dapfor::Common::TString GetFormatClassName();   \
    struct DF_COMMON_API Dummy { Dummy(); };               \
    friend Dummy;                                                \
    static Dummy m_Dummy;                           

/// \def DF_IMPLEMENT_FORMAT(_name)
/// \brief Implements serializable format.
#define DF_IMPLEMENT_FORMAT(_name)                                                         \
    Dapfor::Common::CFormat* _name::CreateFormat() {return new _name;}                \
    bool _name::IsSerializableType() const {return true;}                                  \
    Dapfor::Common::TString _name::GetFormatName() const{return _T(#_name);}          \
    Dapfor::Common::TString _name::GetFormatClassName() {return _T(#_name);}          \
    _name::Dummy::Dummy()                                                                  \
    {                                                                                      \
        Dapfor::Common::CFormatFactory::RegisterFormat(_T(#_name), CreateFormat);     \
    }                                                                                      \
    _name::Dummy m_Dummy;

///@} 



