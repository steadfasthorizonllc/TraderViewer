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
#include <Dapfor/Common/Value.h>

#include <set>

namespace Dapfor
{

namespace Common
{

//Forward declarations
class CField;
class CFieldMap;
class CFormat;
class CSerializer;


//////////////////////////////////////////////////////////////////////////
/// \brief Base class for the objects presented in GUI::CGrid.
///
/// The data object represents the mechanism of separating data from its presentation on the class level. 
/// The data object can return unformatted values like char, long, double by calling the appropriate function 
/// of the derived class by its integer identifier, and permits to transform unformatted data to the string 
/// through the appropriate format and vice-versa. To make separation of data from its presentation 
/// possible, the table of functions is organized. These functions can be called by their identifiers. 
/// The macro DF_DECLARE_FIELD_MAP()  declares this table in the derived class. If there is an inheritance chain, 
/// each derived class can organize its own table. The table instantiation occurs in cpp file with 
/// DF_BEGIN_FIELD_MAP() and DF_END_FIELD_MAP() macros.
/// 
/// Integer identifiers are used to insert data into the table. Within one table these identifiers should not 
/// recur and should not be equal to Common::allFields (-1) or Common:: fieldNotSpecified (-2). 
/// If there is an inheritance chain, the identifiers of derived classes and base classes 
/// can be the same. This can be used to enable polymorphic behavior of a data object in GUI::CGrid. 
/// Each record in the table is presented in the form of an object of CField type. The table itself is represented 
/// by the object of CFieldMap class. Table initialization takes place at the start of the application. 
/// The table is not changed during the application running, and it enables organizing access 
/// from different threads. If there is a large quantity of declared fields (more than 50), 
/// it is recommended to use DF_END_HASH_FIELD_MAP() instead of the DF_END_FIELD_MAP() macro in order 
/// to accelerate access to class functions by their identifiers.
///
/// CDataObject provides CDataObject::ISink callback interface to inform the subscribers about change of its 
/// internal state. AddSink() function is used for subscription to the events. RemoveSink() function should 
/// be called to remove the subscribers from CDataObject. Notifications are sent by calling NotifyUpdate().
/// implementation of the container that stores the subscriber list and is thread-safe. NotifyUpdate() function
/// is implemented without taking a synchronization object during function call. This prevents deadlocks 
/// between two and more threads. 
/// Usually NotifyUpdate function is called after data object state modification.
///
/// The data object offers an interface for data serialization. 
/// The macro DF_DECLARE_SERIALIZABLE_TYPE() is used to declare a serializable type.
///
/// \class CDataObject DataObject.h <Dapfor/Common/DataObject.h>
///
/// Read \ref DataObjectIntro "What is a data object?" article to get more information.
///
/// The article \ref howtoinstall "How to install the MFC grid and compile the first application?" explains all 
/// steps of installing and compiling your first application.
///
/// \par Examples
/// - \ref data_object_declaration_example
/// - \ref data_object_set_methods_example
/// - \ref data_object_threadsafe_methods_example
///
//////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CDataObject
{
public:
    ///@name Get method types
    //@{
#ifndef DF_NOT_MFC
    typedef CString         (CDataObject::*pfnGetMfcString)() const;    //!< Get-method of the CString type
#endif
    typedef TString         (CDataObject::*pfnGetStlString)() const;    //!< Get-method of the STL string type
    typedef char            (CDataObject::*pfnGetChar)() const;         //!< Get-method of the char type
    typedef unsigned char   (CDataObject::*pfnGetUChar)() const;        //!< Get-method of the unsigned char type
    typedef short           (CDataObject::*pfnGetShort)() const;        //!< Get-method of the short type
    typedef unsigned short  (CDataObject::*pfnGetUShort)() const;       //!< Get-method of the unsigned short type
    typedef long            (CDataObject::*pfnGetLong)() const;         //!< Get-method of the long type
    typedef unsigned long   (CDataObject::*pfnGetULong)() const;        //!< Get-method of the unsigned long type
    typedef int64           (CDataObject::*pfnGetInt64)() const;        //!< Get-method of the __int64 type
    typedef bool            (CDataObject::*pfnGetBool)() const;         //!< Get-method of the bool type
    typedef float           (CDataObject::*pfnGetFloat)() const;        //!< Get-method of the float type
    typedef double          (CDataObject::*pfnGetDouble)() const;       //!< Get-method of the double type
    typedef CDataObject*    (CDataObject::*pfnGetObjectPtr)() const;    //!< Get-method of CDataObject pointer type
    //@} 

    ///@name Set method types
    //@{
#ifndef DF_NOT_MFC
    typedef void (CDataObject::*pfnSetMfcString)(const CString&);       //!< Set-method of the CString type
#endif
    typedef void (CDataObject::*pfnSetStlString)(const TString&);       //!< Set-method of the string type
    typedef void (CDataObject::*pfnSetChar)     (char);                 //!< Set-method of the char type
    typedef void (CDataObject::*pfnSetUChar)    (unsigned char);        //!< Set-method of the unsigned char type
    typedef void (CDataObject::*pfnSetShort)    (short);                //!< Set-method of the short type
    typedef void (CDataObject::*pfnSetUShort)   (unsigned short);       //!< Set-method of the unsigned short type
    typedef void (CDataObject::*pfnSetLong)     (long);                 //!< Set-method of the long type
    typedef void (CDataObject::*pfnSetULong)    (unsigned long);        //!< Set-method of the unsigned long type
    typedef void (CDataObject::*pfnSetInt64)    (int64);                //!< Set-method of the __int64 type
    typedef void (CDataObject::*pfnSetBool)     (bool);                 //!< Set-method of the bool type
    typedef void (CDataObject::*pfnSetFloat)    (float);                //!< Set-method of the float type
    typedef void (CDataObject::*pfnSetDouble)   (double);               //!< Set-method of the double type
    typedef void (CDataObject::*pfnSetObjectPtr)(CDataObject*);         //!< Set-method of CDataObject pointer type
    //@} 


    typedef std::pair<CField*, CDataObject*> Field;                     //!< This type represents a pair of field and data object where the field is applicable
    typedef std::set<Field> Fields;                                     //!< Set of the fields
    typedef std::set<FID>   Fids;                                       //!< Set of field identifiers


        


public:
    virtual ~CDataObject();

    ///@name Field accessors 
    //@{
    virtual const Field      GetField(FID fid) const;                   //!< Gets a field of the data object
    virtual void             GetAllFields(Fields& fields) const;        //!< The function copies all the fields declared in the derived classes
    virtual void             GetAllFids(Fids& fields) const;            //!< Gets all the integer identifiers supported by the data object
    virtual const CFieldMap* GetFieldMap() const = 0;                   //!< Gets data object fields
    
    virtual bool             HasGetMethod(FID fid) const;               //!< Indicates whether Get- method is presented.
    virtual bool             HasSetMethod(FID fid) const;               //!< Checks if Set function can be called to set non-formatted value by the specified field identifier.
    virtual EnType           GetFieldType(FID fid) const;               //!< Gets a field type.
    virtual TString          GetFieldName(FID fid) const;               //!< Gets a field name, set during CFieldMap initialization
    virtual const CFormat*   GetFormat(FID fid) const;                  //!< Gets format to transmit non-formatted value to the string and back. 
    //@} 

    ///@name Get methods 
    //@{
#ifndef DF_NOT_MFC
    virtual CString          GetMfcString(FID fid) const;               //!< Calls Get-method in the derived class by its field identifier to get CString value
#endif
    virtual TString          GetStlString(FID fid) const;               //!< Calls Get-method in the derived class by its field identifier to get STL string value 
    virtual char             GetChar(FID fid) const;                    //!< Calls Get-method in the derived class by its field identifier to get char value 
    virtual unsigned char    GetUChar(FID fid) const;                   //!< Calls Get-method in the derived class by its field identifier to get unsigned char value 
    virtual short            GetShort(FID fid) const;                   //!< Calls Get-method in the derived class by its field identifier to get short value 
    virtual unsigned short   GetUShort(FID fid) const;                  //!< Calls Get-method in the derived class by its field identifier to get unsigned short value 
    virtual long             GetLong(FID fid) const;                    //!< Calls Get-method in the derived class by its field identifier to get long value 
    virtual unsigned long    GetULong(FID fid) const;                   //!< Calls Get-method in the derived class by its field identifier to get unsigned long value 
    virtual int64            GetInt64(FID fid) const;                   //!< Calls Get-method in the derived class by its field identifier to get __int64 value 
    virtual bool             GetBool(FID fid) const;                    //!< Calls Get-method in the derived class by its field identifier to get bool value 
    virtual float            GetFloat(FID fid) const;                   //!< Calls Get-method in the derived class by its field identifier to get float value 
    virtual double           GetDouble(FID fid) const;                  //!< Calls Get-method in the derived class by its field identifier to get double value 
    virtual CDataObject*     GetObjectPtr(FID fid) const;               //!< Calls Get-method in the derived class by its field identifier to get CDataObject pointer
    virtual CValue           GetValue(FID fid) const;                   //!< Calls Get-method in the derived class by its field identifier to get CValue object 
    //@} 


    ///@name Set methods 
    //@{
#ifndef DF_NOT_MFC
    virtual bool             SetMfcString(FID fid, const CString& val); //!< Calls Set-method in the derived class by its field identifier to set CString value 
#endif
    virtual bool             SetStlString(FID fid, const TString& val); //!< Calls Set-method in the derived class by its field identifier to set STL string value 
    virtual bool             SetChar(FID fid, char val);                //!< Calls Set-method in the derived class by its field identifier to set char value 
    virtual bool             SetUChar(FID fid, unsigned char val);      //!< Calls Set-method in the derived class by its field identifier to set unsigned char value 
    virtual bool             SetShort(FID fid, short val);              //!< Calls Set-method in the derived class by its field identifier to set short value 
    virtual bool             SetUShort(FID fid, unsigned short val);    //!< Calls Set-method in the derived class by its field identifier to set unsigned short value 
    virtual bool             SetLong(FID fid, long val);                //!< Calls Set-method in the derived class by its field identifier to set long value 
    virtual bool             SetULong(FID fid, unsigned long val);      //!< Calls Set-method in the derived class by its field identifier to set unsigned long value 
    virtual bool             SetInt64(FID fid, int64 val);              //!< Calls Set-method in the derived class by its field identifier to set __int64 value 
    virtual bool             SetBool(FID fid, bool val);                //!< Calls Set-method in the derived class by its field identifier to set bool value 
    virtual bool             SetFloat(FID fid, float val);              //!< Calls Set-method in the derived class by its field identifier to set float value 
    virtual bool             SetDouble(FID fid, double val);            //!< Calls Set-method in the derived class by its field identifier to set double value 
    virtual bool             SetObjectPtr(FID fid, CDataObject* val);   //!< Calls Set-method in the derived class by its field identifier to set CDataObject pointer 
    virtual bool             SetValue(FID fid, const CValue& val);      //!< Calls Set-method in the derived class by its field identifier to set CValue object 
    //@} 



    ///@name Formatted strings 
    //@{
#ifndef DF_NOT_MFC
    virtual CString          GetFormattedMfcString(FID fid, const CFormat* defaultFormat) const;  //!< Gets a formatted string by calling corresponding function in the derived class
    virtual bool             SetFormattedMfcString(FID fid, const CString& str, const CFormat* defaultFormat); //!< Sets a formatted string by calling corresponding function in the derived class
#endif

    virtual TString          GetFormattedStlString(FID fid, const CFormat* defaultFormat) const;  //!< Gets a formatted string by calling corresponding function in the derived class
    virtual bool             SetFormattedStlString(FID fid, const TString& str, const CFormat* defaultFormat); //!< Sets a formatted string by calling corresponding function in the derived class
    //@} 

    
    ///@name Serialization 
    //@{
    virtual const TString&     GetSerializationName() const;            //!< Gets serialization name
    virtual bool               IsSerializableType() const;              //!< Indicates whether the object is serializable
    virtual void               Serialize(CSerializer& serializer);      //!< Serializes the object into the serializer
    //@} 
    static  int                GetSerializeVertion();                   




    ///@name Notifications 
    //@{

    /// \brief Interface to receive notifications from CDataObject.
    struct DF_COMMON_API ISink
    {
        virtual void OnUpdate(FID fid, const CDataObject* dataObject) = 0;      //!< Called when the field is updated.
        virtual void OnUpdate(const Fids& fids, const CDataObject* dataObject); //!< Called when the fields are updated.
        virtual void OnDelete(const CDataObject* dataObject);                   //!< Called when the object ends its life cycle
    };


    void AddSink(ISink* sink);              //!< Adds a new listener
    void RemoveSink(ISink* sink);           //!< Removes a specified listener
    void NotifyUpdate(FID fid);             //!< Sends notification to the listeners, that the field was changed
    void NotifyUpdate(const Fids& fids);    //!< Sends notification to the listeners with a list of the modified fields
    //@}
    
    
protected:
    void NotifyDelete();                    //!< Sends the notification, that the object ends its life cycle.


protected:
    CDataObject();                          // Protected constructor


private:
    CDataObject(const CDataObject&);
    CDataObject& operator = (const CDataObject&);

    struct Impl;                            //Pointer implementation interface
    Impl* m_Impl;
};

}//namespace Common

}//namespace Dapfor



#include <Dapfor/Common/Field.h>
#include <Dapfor/Common/FieldMap.h>
#include <Dapfor/Common/TypeFactory.h>

/////////////////////////////////////////////////////////////////////////////
//Declarations
/////////////////////////////////////////////////////////////////////////////
/// \file DataObject.h
///@name Field map declarations
///@{

/// \def DF_DECLARE_FIELD_MAP()
/// \brief Declares table of functions in classes derived from Dapfor::Common::CDataObject.
#define DF_DECLARE_FIELD_MAP()                                             \
protected:                                                                 \
        static Dapfor::Common::CFieldMap& GetClassFieldMap();         \
        virtual Dapfor::Common::CFieldMap* GetFieldMap();             \
        virtual const Dapfor::Common::CFieldMap* GetFieldMap() const; \
private:                                                                   \
        static struct FieldMap_dummy{FieldMap_dummy();} m_FieldMap_dummy;  \
        friend struct FieldMap_dummy;                                      \
        static void InitFieldMap();


/// \def DF_BEGIN_FIELD_MAP()
/// \brief Begins table of functions for the class derived from the Dapfor::Common::CDataObject. 
#define DF_BEGIN_FIELD_MAP(__name)                                                                          \
    Dapfor::Common::CFieldMap* __name::GetFieldMap() {return &__name::GetClassFieldMap();}            \
    const Dapfor::Common::CFieldMap* __name::GetFieldMap() const {return &__name::GetClassFieldMap();}\
    Dapfor::Common::CFieldMap& __name::GetClassFieldMap() {static Dapfor::Common::CFieldMap fieldMap; return fieldMap;}\
    __name::FieldMap_dummy __name::m_FieldMap_dummy;                                                        \
    __name::FieldMap_dummy::FieldMap_dummy() {__name::InitFieldMap();}                                      \
    void __name::InitFieldMap() {                                                                           \
        typedef __name __ClassName;                                                                         \
        using namespace Dapfor;                                                                            \
        using namespace Dapfor::Common;                                                               \
        using Dapfor::Common::CField;                                                                 \
        using Dapfor::Common::CFieldMap;                                                              \
        CFieldMap& fmap = __name::GetClassFieldMap();

/// \def DF_BEGIN_FIELD_MAP_EX()
/// \brief Begins table of functions for the class in a chain of inheritance.
#define DF_BEGIN_FIELD_MAP_EX(__name, __baseClass)                                                          \
    Dapfor::Common::CFieldMap* __name::GetFieldMap() {return &__name::GetClassFieldMap();}            \
    const Dapfor::Common::CFieldMap* __name::GetFieldMap() const {return &__name::GetClassFieldMap();}\
    Dapfor::Common::CFieldMap& __name::GetClassFieldMap() {static Dapfor::Common::CFieldMap fieldMap(&__baseClass::GetClassFieldMap()); return fieldMap;}\
    __name::FieldMap_dummy __name::m_FieldMap_dummy;                                                        \
    __name::FieldMap_dummy::FieldMap_dummy() {__name::InitFieldMap();}                                      \
    void __name::InitFieldMap() {                                                                           \
        typedef __name __ClassName;                                                                         \
        using namespace Dapfor;                                                                            \
        using namespace Dapfor::Common;                                                               \
        using Dapfor::Common::CField;                                                                 \
        using Dapfor::Common::CFieldMap;                                                              \
        CFieldMap& fmap = __name::GetClassFieldMap();


/// \def DF_END_FIELD_MAP()
/// \brief Ends field map.
#define DF_END_FIELD_MAP()  \
    }


/// \def DF_END_HASH_FIELD_MAP()
/// \brief Ends field map and initialises hash map to accelerate access to the fields. It is recommended to use this 
/// macro when count of fields is greater than 50.
#define DF_END_HASH_FIELD_MAP()     \
    fmap.InitHash();                \
    }

///@} 


///@name Field declarations
///@{

/// \def DF_STL_STRING_ID()
/// \brief Declares field of the <b>Dapfor::Common::TString</b> type. __getMethod or __setMethod can be 0.
/// \n __fid  Numeric identifier 
/// \n __name Name of the field. 
/// \n __getMethod Get-method with the following prototype: <b>TString (ClassName::*pfnGetStlString)() const</b>
/// \n __setMethod Set-method with the following prototype: <b>void (ClassName::*pfnSetStlString)(const Dapfor::Common::TString&)</b>
/// \n __format Format, used for the field.
#define DF_STL_STRING_ID(__fid, __name, __getMethod, __setMethod, __format) \
    fmap.AddField(__fid,                                 \
              new Dapfor::Common::CField(__fid,     \
                                      __name,            \
                                      static_cast<Dapfor::Common::CDataObject::pfnGetStlString>(__getMethod), \
                                      static_cast<Dapfor::Common::CDataObject::pfnSetStlString>(__setMethod), \
                                      __format,          \
                                      _T(#__getMethod),  \
                                      _T(#__setMethod)));


#ifndef DF_NOT_MFC
/// \def DF_MFC_STRING_ID()
/// \brief Declares field of the <b>CString</b> type. __getMethod or __setMethod can be 0.
/// \n __fid  Numeric identifier 
/// \n __name Name of the field. 
/// \n __getMethod Get-method with the following prototype: <b>CString (ClassName::*pfnGetMfcString)() const</b>
/// \n __setMethod Set-method with the following prototype: <b>void (ClassName::*pfnSetMfcString)(const CString&)</b>
/// \n __format Format, used for the field.
#define DF_MFC_STRING_ID(__fid, __name, __getMethod, __setMethod, __format) \
    fmap.AddField(__fid,                                 \
               new Dapfor::Common::CField(__fid,    \
                                       __name,           \
                                       static_cast<Dapfor::Common::CDataObject::pfnGetMfcString>(__getMethod), \
                                       static_cast<Dapfor::Common::CDataObject::pfnSetMfcString>(__setMethod), \
                                       __format,         \
                                      _T(#__getMethod),  \
                                      _T(#__setMethod)));

#endif//DF_NOT_MFC

/// \def DF_CHAR_ID()
/// \brief Declares field of the <b>char</b> type. __getMethod or __setMethod can be 0.
/// \n __fid  Numeric identifier 
/// \n __name Name of the field. 
/// \n __getMethod Get-method with the following prototype: <b>char (CDataObject::*pfnGetChar)() const</b>
/// \n __setMethod Set-method with the following prototype: <b>void (CDataObject::*pfnSetChar) (char)</b>
/// \n __format Format, used for the field.
#define DF_CHAR_ID(__fid, __name, __getMethod, __setMethod, __format)   \
    fmap.AddField(__fid, \
              new Dapfor::Common::CField(__fid,   \
                                      __name,           \
                                      static_cast<Dapfor::Common::CDataObject::pfnGetChar>(__getMethod), \
                                      static_cast<Dapfor::Common::CDataObject::pfnSetChar>(__setMethod), \
                                      __format,         \
                                      _T(#__getMethod), \
                                      _T(#__setMethod)));

/// \def DF_UCHAR_ID()
/// \brief Declares field of the <b>unsigned char</b> type. __getMethod or __setMethod can be 0.
/// \n __fid  Numeric identifier 
/// \n __name Name of the field. 
/// \n __getMethod Get-method with the following prototype: <b>unsigned char (CDataObject::*pfnGetUChar)() const</b>
/// \n __setMethod Set-method with the following prototype: <b>void (CDataObject::*pfnSetUChar) (unsigned char)</b>
/// \n __format Format, used for the field.
#define DF_UCHAR_ID(__fid, __name, __getMethod, __setMethod, __format)  \
    fmap.AddField(__fid,                                \
              new Dapfor::Common::CField(__fid,   \
                                      __name,           \
                                      static_cast<Dapfor::Common::CDataObject::pfnGetUChar>(__getMethod), \
                                      static_cast<Dapfor::Common::CDataObject::pfnSetUChar>(__setMethod), \
                                      __format,         \
                                      _T(#__getMethod), \
                                      _T(#__setMethod)));


/// \def DF_SHORT_ID()
/// \brief Declares field of the <b>short</b> type. __getMethod or __setMethod can be 0.
/// \n __fid  Numeric identifier 
/// \n __name Name of the field. 
/// \n __getMethod Get-method with the following prototype: <b>short (CDataObject::*pfnGetShort)() const</b>
/// \n __setMethod Set-method with the following prototype: <b>void (CDataObject::*pfnSetShort) (short)</b>
/// \n __format Format, used for the field.
#define DF_SHORT_ID(__fid, __name, __getMethod, __setMethod, __format)  \
    fmap.AddField(__fid,                                \
              new Dapfor::Common::CField(__fid,   \
                                      __name,           \
                                      static_cast<Dapfor::Common::CDataObject::pfnGetShort>(__getMethod), \
                                      static_cast<Dapfor::Common::CDataObject::pfnSetShort>(__setMethod), \
                                      __format,         \
                                      _T(#__getMethod), \
                                      _T(#__setMethod)));

/// \def DF_USHORT_ID()
/// \brief Declares field of the <b>unsigned short</b> type. __getMethod or __setMethod can be 0.
/// \n __fid  Numeric identifier 
/// \n __name Name of the field. 
/// \n __getMethod Get-method with the following prototype: <b>unsigned short (CDataObject::*pfnGetUShort)() const</b>
/// \n __setMethod Set-method with the following prototype: <b>void (CDataObject::*pfnSetUShort) (unsigned short)</b>
/// \n __format Format, used for the field.
#define DF_USHORT_ID(__fid, __name, __getMethod, __setMethod, __format) \
    fmap.AddField(__fid,                                \
              new Dapfor::Common::CField(__fid,   \
                                      __name,           \
                                      static_cast<Dapfor::Common::CDataObject::pfnGetUShort>(__getMethod), \
                                      static_cast<Dapfor::Common::CDataObject::pfnSetUShort>(__setMethod), \
                                      __format,         \
                                      _T(#__getMethod), \
                                      _T(#__setMethod)));


/// \def DF_LONG_ID()
/// \brief Declares field of the <b>long</b> type. __getMethod or __setMethod can be 0.
/// \n __fid  Numeric identifier 
/// \n __name Name of the field. 
/// \n __getMethod Get-method with the following prototype: <b>long (CDataObject::*pfnGetLong)() const</b>
/// \n __setMethod Set-method with the following prototype: <b>void (CDataObject::*pfnSetLong) (long)</b>
/// \n __format Format, used for the field.
#define DF_LONG_ID(__fid, __name, __getMethod, __setMethod, __format)   \
    fmap.AddField(__fid,                                \
              new Dapfor::Common::CField(__fid,   \
                                      __name,           \
                                      static_cast<Dapfor::Common::CDataObject::pfnGetLong>(__getMethod), \
                                      static_cast<Dapfor::Common::CDataObject::pfnSetLong>(__setMethod), \
                                      __format,         \
                                      _T(#__getMethod), \
                                      _T(#__setMethod)));

/// \def DF_ULONG_ID()
/// \brief Declares field of the <b>unsigned long</b> type. __getMethod or __setMethod can be 0.
/// \n __fid  Numeric identifier 
/// \n __name Name of the field. 
/// \n __getMethod Get-method with the following prototype: <b>unsigned long (CDataObject::*pfnGetULong)() const</b>
/// \n __setMethod Set-method with the following prototype: <b>void (CDataObject::*pfnSetULong) (unsigned long)</b>
/// \n __format Format, used for the field.
#define DF_ULONG_ID(__fid, __name, __getMethod, __setMethod, __format)  \
    fmap.AddField(__fid,                                \
              new Dapfor::Common::CField(__fid,   \
                                      __name,           \
                                      static_cast<Dapfor::Common::CDataObject::pfnGetULong>(__getMethod), \
                                      static_cast<Dapfor::Common::CDataObject::pfnSetULong>(__setMethod), \
                                      __format,         \
                                      _T(#__getMethod), \
                                      _T(#__setMethod)));


/// \def DF_ENUM_ID()
/// \brief Declares field of the <b>long</b> type. __getMethod or __setMethod can be 0.
/// \n __fid  Numeric identifier 
/// \n __name Name of the field. 
/// \n __getMethod Get-method with the following prototype: <b>long (CDataObject::*pfnGetLong)() const</b>
/// \n __setMethod Set-method with the following prototype: <b>void (CDataObject::*pfnSetLong) (long)</b>
/// \n __format Format, used for the field.
#define DF_ENUM_ID(__fid, __name, __getMethod, __setMethod, __format)   \
    fmap.AddField(__fid,                                \
              new Dapfor::Common::CField(__fid,   \
                                      __name,           \
                                      reinterpret_cast<Dapfor::Common::CDataObject::pfnGetLong>(__getMethod), \
                                      reinterpret_cast<Dapfor::Common::CDataObject::pfnSetLong>(__setMethod), \
                                      __format,         \
                                      _T(#__getMethod), \
                                      _T(#__setMethod)));


/// \def DF_INT64_ID()
/// \brief Declares field of the <b>__int64</b> type. __getMethod or __setMethod can be 0.
/// \n __fid  Numeric identifier 
/// \n __name Name of the field. 
/// \n __getMethod Get-method with the following prototype: <b>__int64 (CDataObject::*pfnGetInt64)() const</b>
/// \n __setMethod Set-method with the following prototype: <b>void (CDataObject::*pfnSetInt64) (__int64)</b>
/// \n __format Format, used for the field.
#define DF_INT64_ID(__fid, __name, __getMethod, __setMethod, __format)  \
    fmap.AddField(__fid,                                \
              new Dapfor::Common::CField(__fid,   \
                                      __name,           \
                                      static_cast<Dapfor::Common::CDataObject::pfnGetInt64>(__getMethod), \
                                      static_cast<Dapfor::Common::CDataObject::pfnSetInt64>(__setMethod), \
                                      __format,         \
                                      _T(#__getMethod), \
                                      _T(#__setMethod)));

/// \def DF_BOOL_ID()
/// \brief Declares field of the <b>bool</b> type. __getMethod or __setMethod can be 0.
/// \n __fid  Numeric identifier 
/// \n __name Name of the field. 
/// \n __getMethod Get-method with the following prototype: <b>bool (CDataObject::*pfnGetBool)() const</b>
/// \n __setMethod Set-method with the following prototype: <b>void (CDataObject::*pfnSetBool)(bool)</b>
/// \n __format Format, used for the field.
#define DF_BOOL_ID(__fid, __name, __getMethod, __setMethod, __format)   \
    fmap.AddField(__fid,                                \
              new Dapfor::Common::CField(__fid,   \
                                      __name,           \
                                      static_cast<Dapfor::Common::CDataObject::pfnGetBool>(__getMethod), \
                                      static_cast<Dapfor::Common::CDataObject::pfnSetBool>(__setMethod), \
                                      __format,         \
                                      _T(#__getMethod), \
                                      _T(#__setMethod)));


/// \def DF_FLOAT_ID()
/// \brief Declares field of the <b>float</b> type. __getMethod or __setMethod can be 0.
/// \n __fid  Numeric identifier 
/// \n __name Name of the field. 
/// \n __getMethod Get-method with the following prototype: <b>float (CDataObject::*pfnGetFloat)() const</b>
/// \n __setMethod Set-method with the following prototype: <b>void (CDataObject::*pfnSetFloat)(float)</b>
/// \n __format Format, used for the field.
#define DF_FLOAT_ID(__fid, __name, __getMethod, __setMethod, __format)  \
    fmap.AddField(__fid,                                \
              new Dapfor::Common::CField(__fid,   \
                                      __name,           \
                                      static_cast<Dapfor::Common::CDataObject::pfnGetFloat>(__getMethod), \
                                      static_cast<Dapfor::Common::CDataObject::pfnSetFloat>(__setMethod), \
                                      __format,         \
                                      _T(#__getMethod), \
                                      _T(#__setMethod)));

/// \def DF_DOUBLE_ID()
/// \brief Declares field of the <b>double</b> type. __getMethod or __setMethod can be 0.
/// \n __fid  Numeric identifier 
/// \n __name Name of the field. 
/// \n __getMethod Get-method with the following prototype: <b>double (CDataObject::*pfnGetDouble)() const</b>
/// \n __setMethod Set-method with the following prototype: <b>void (CDataObject::*pfnSetDouble) (double)</b>
/// \n __format Format, used for the field.
#define DF_DOUBLE_ID(__fid, __name, __getMethod, __setMethod, __format) \
    fmap.AddField(__fid,                                \
              new Dapfor::Common::CField(__fid,   \
                                      __name,           \
                                      static_cast<Dapfor::Common::CDataObject::pfnGetDouble>(__getMethod), \
                                      static_cast<Dapfor::Common::CDataObject::pfnSetDouble>(__setMethod), \
                                      __format,         \
                                      _T(#__getMethod), \
                                      _T(#__setMethod)));

/// \def DF_OBJECT_PTR_ID()
/// \brief Declares field which points to a CDataObject. __getMethod or __setMethod can be 0.
/// \n __fid  Numeric identifier 
/// \n __name Name of the field. 
/// \n __getMethod Get-method with the following prototype: <b>CDataObject* (CDataObject::*pfnGetObjectPtr)() const</b>
/// \n __setMethod Set-method with the following prototype: <b>void (CDataObject::*pfnSetObjectPtr)(CDataObject*)</b>
/// \n __format Format, used for the field.
#define DF_OBJECT_PTR_ID(__fid, __name, __getMethod, __setMethod, __format) \
    fmap.AddField(__fid,                                \
              new Dapfor::Common::CField(__fid,   \
                                      __name,           \
                                      static_cast<Dapfor::Common::CDataObject::pfnGetObjectPtr>(__getMethod), \
                                      static_cast<Dapfor::Common::CDataObject::pfnSetObjectPtr>(__setMethod), \
                                      __format,         \
                                      _T(#__getMethod), \
                                      _T(#__setMethod)));

///@} 


///@name Field declarations
///@{


/// \def DF_DECLARE_SERIALIZABLE_TYPE()
/// \brief Declares child class that derives from the CDataObject as serializable. 
/// If the class has both set- and get- methods, values of the object can be stored and 
/// restored to/from binary archive.
#define DF_DECLARE_SERIALIZABLE_TYPE()                                                          \
public:                                                                                         \
    virtual const Dapfor::Common::TString& GetSerializationName() const;                  \
    static  const Dapfor::Common::TString& GetClassSerializationName();                   \
    virtual bool IsSerializableType() const;                                                    \
protected:                                                                                      \
    static Dapfor::Common::CDataObject* ConstructObject();                                \
private:                                                                                        \
    static struct SerializableType_dummy{SerializableType_dummy();} m_SerializableType_dummy;   \
    friend struct SerializableType_dummy;                                                       \
    static void InitSerializableType();


/// \def DF_IMPLEMENT_SERIALIZABLE_TYPE()
/// \brief Implements serializable class
#define DF_IMPLEMENT_SERIALIZABLE_TYPE(__name)                                                                              \
    const Dapfor::Common::TString& __name::GetClassSerializationName(){static Dapfor::Common::TString className(_T(#__name)); return className;}\
    const Dapfor::Common::TString& __name::GetSerializationName() const {return __name::GetClassSerializationName();} \
    Dapfor::Common::CDataObject* __name::ConstructObject()    {return new __name();}                                  \
    bool __name::IsSerializableType() const {return true;}                                                                  \
    __name::SerializableType_dummy __name::m_SerializableType_dummy;                                                        \
    __name::SerializableType_dummy::SerializableType_dummy() {__name::InitSerializableType();}                              \
    void __name::InitSerializableType() {Dapfor::Common::CTypeFactory::RegisterClass(__name::GetClassSerializationName(), __name::ConstructObject);}

///@} 
