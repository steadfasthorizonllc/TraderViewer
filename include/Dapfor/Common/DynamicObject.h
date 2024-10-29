/////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2007-2010 Dapfor
//                                                                         
// This file is part of the Dapfor software, and may only be used, modified, and distributed 
// under the terms of the Dapfor LICENSE AGREEMENT FOR MFC GRID SOFTWARE.
// (See accompanying file lisense.txt or open the license at http://www.dapfor.com/license_agreement_v2.aspx)
// By continuing to use, modify, or distribute this file you indicate that you have read the license 
// and understand and accept it.
/////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <Dapfor/Common/DataObject.h>
#include <Dapfor/Common/Types.h>

namespace Dapfor
{

namespace Common
{

/////////////////////////////////////////////////////////////////////////////
/// \brief CDynamicObject has nether Set- nor Get- functions. The values are accessible by the field identifiers.
///
/// CDynamicObject provides access to values stored in the table. This table can be changed at run time 
/// in contrast to the static tables organized with DF_DECLARE_FIELD_MAP(), DF_BEGIN_FIELD_MAP(), 
/// DF_BEGIN_FIELD_MAP_EX(), DF_END_FIELD_MAP() macros. In this case memory consumption for dynamic data objects increases 
/// greatly. CDynamicObject is usually used if data object type is unknown beforehand. (For example, if data is 
/// imported from another application using drag&drop or copy/paste). If the object type is known, it is 
/// recommended to use static declaration. CDynamicObject doesn't contain Get- and Set- methods
/// To simulate standard behavior of the data object, all the functions working with unformatted and formatted data
/// were redefined. Every CDynamicObject contains two tables.
/// \n 1. CFieldMap table to store information about formats for transformation of data into a string and back.
/// \n 2. Container that stores unformatted data which are accessible by its identifier.
///
/// During the first call of any Set- method, CDynamicObject adds a new value corresponding 
/// to the identifier to the table of unformatted values. To transform the value into the string with custom format, 
/// this format can be registered in CFieldMap with DeclareField() function. 
/// CDynamicObject in its destructor destroys all registered fields. In multi-threaded applications 
/// essential mechanisms were implemented in order to enable simultaneous access from different threads.
///
/// \version <b>2.0.0</b> Initial version
///
/// \class CDynamicObject DynamicObject.h <Dapfor/Common/DynamicObject.h>
/// \file DynamicObject.h
/////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CDynamicObject : public CDataObject
{
public:
    CDynamicObject(bool canNotify);
    virtual ~CDynamicObject();

    virtual const Field         GetField(FID fid) const;                    //!< Gets a data object field
    virtual void                GetAllFields(Fields& fields) const;         //!< The function copies all declared fields
    virtual void                GetAllFids(Fids& fids) const;               //!< Gets all the integer identifiers supported by the object

    virtual const CFieldMap*    GetFieldMap() const;                        //!< Gets data object fields
    
    virtual bool                DeclareField(CField* field);                //!< Declares a new field


#ifndef DF_NOT_MFC
    virtual bool                SetMfcString(FID fid, const CString& val);  //!< Sets a MFC string value in the field specified by the identifier
#endif
    virtual bool                SetStlString(FID fid, const TString& val);  //!< Sets a STL string value in the field specified by the identifier
    virtual bool                SetChar(FID fid, char val);                 //!< Sets char value in the field specified by the identifier
    virtual bool                SetUChar(FID fid, unsigned char val);       //!< Sets unsigned char value in the field specified by the identifier
    virtual bool                SetShort(FID fid, short val);               //!< Sets short value in the field specified by the identifier
    virtual bool                SetUShort(FID fid, unsigned short val);     //!< Sets unsigned short value in the field specified by the identifier
    virtual bool                SetLong(FID fid, long val);                 //!< Sets long value in the field specified by the identifier
    virtual bool                SetULong(FID fid, unsigned long val);       //!< Sets unsigned long value in the field specified by the identifier
    virtual bool                SetInt64(FID fid, int64 val);               //!< Sets __int64 value in the field specified by the identifier
    virtual bool                SetBool(FID fid, bool val);                 //!< Sets bool value in the field specified by the identifier
    virtual bool                SetFloat(FID fid, float val);               //!< Sets float value in the field specified by the identifier
    virtual bool                SetDouble(FID fid, double val);             //!< Sets double value in the field specified by the identifier
    virtual bool                SetObjectPtr(FID fid, CDataObject* val);    //!< Sets a pointer to CDataObject in the field specified by the identifier
    virtual bool                SetValue(FID fid, const CValue& val);       //!< Sets CValue in the field specified by the identifier

#ifndef DF_NOT_MFC
    virtual CString             GetMfcString(FID fid) const;                //!< Gets MFC string value from the field specified by the identifier
#endif
    virtual TString             GetStlString(FID fid) const;                //!< Gets STL string value from the field specified by the identifier
    virtual char                GetChar(FID fid) const;                     //!< Gets char value from the field specified by the identifier
    virtual unsigned char       GetUChar(FID fid) const;                    //!< Gets unsigned char value from the field specified by the identifier
    virtual short               GetShort(FID fid) const;                    //!< Gets short value from the field specified by the identifier
    virtual unsigned short      GetUShort(FID fid) const;                   //!< Gets unsigned short value from the field specified by the identifier
    virtual long                GetLong(FID fid) const;                     //!< Gets long value from the field specified by the identifier
    virtual unsigned long       GetULong(FID fid) const;                    //!< Gets unsigned long value from the field specified by the identifier
    virtual int64               GetInt64(FID fid) const;                    //!< Gets __int64 value from the field specified by the identifier
    virtual bool                GetBool(FID fid) const;                     //!< Gets bool value from the field specified by the identifier
    virtual float               GetFloat(FID fid) const;                    //!< Gets float value from the field specified by the identifier
    virtual double              GetDouble(FID fid) const;                   //!< Gets double value from the field specified by the identifier
    virtual CDataObject*        GetObjectPtr(FID fid) const;                //!< Gets a pointer to CDataObject from the field specified by the identifier
    virtual CValue              GetValue(FID fid) const;

#ifndef DF_NOT_MFC
    ///Gets a formatted MFC string
    virtual CString             GetFormattedMfcString(FID fid, const CFormat* defaultFormat) const;
    ///Sets a formatted MFC string
    virtual bool                SetFormattedMfcString(FID fid, const CString& val, const CFormat* defaultFormat);
#endif

    ///Gets a formatted STL string
    virtual TString             GetFormattedStlString(FID fid, const CFormat* defaultFormat) const;
    ///Sets a formatted STL string
    virtual bool                SetFormattedStlString(FID fid, const TString& val, const CFormat* defaultFormat);

    virtual bool                HasGetMethod(FID fid) const;    //!< Indicates whether the object has Get- method.
    virtual bool                HasSetMethod(FID fid) const;    //!< Indicates whether the object has Set- method.
    virtual EnType              GetFieldType(FID fid) const;    //!< Gets a field type.
    virtual TString             GetFieldName(FID fid) const;    //!< Gets the field name, set during CField registration
    virtual const CFormat*      GetFormat(FID fid) const;       //!< Gets the format to convert non-formatted value to the string and back. 


private:
    //Point implementation interface
    struct Impl;
    Impl* m_Impl;
};

}//namespace Common

}//namespace Dapfor


