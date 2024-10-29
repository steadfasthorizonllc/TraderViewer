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
#include <Dapfor/Common/DataObject.h>

namespace Dapfor
{

namespace Common
{

class CFormat;
class CDataObject;

/////////////////////////////////////////////////////////////////////////////
/// \brief Presets and describes a field in a class derived from CDataObject.
///
/// C++ doesn't provide language possibilities to describe properties like Visual Basic.
/// This class is equivalent to a property in Visual Basic and includes:
/// \n 1. Integer identifier that can't be equal to Common::allFields(-1) or Common::fieldNotSpecified(-2).
/// \n 2. Field name
/// \n 3. Pointer to Get- method of the class derived from CDataObject
/// \n 4. Pointer to Set- method of the class derived from CDataObject
/// \n 5. Pointer to CFormat object which converts the value returned by Get-method to a formatted string and vice versa. 
///
/// The field can be either single-sided or double-sided, i.e. it can have either Get or Set methods separately 
/// or combined. Each field has its type that depends on the type of Set and Get methods.
/// The field is also used by CDataObject to call the methods of the derived classes by its identifiers.
///
/// \class CField Field.h <Dapfor/Common/CField.h>
/// \file Field.h
/// 
/////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CField
{
public:
    CField();                               //!< Constructor
    CField(const CField& field);            //!< Copy constructor

    /// Constructor
    CField(FID fid,                         
           const TCHAR* name,
           EnType   fieldType,
           CFormat* format);

#ifndef DF_NOT_MFC
    ///Constructor for the STL string-type field 
    CField(FID fid,                         
        const TCHAR* name,
        CDataObject::pfnGetMfcString getMethod,
        CDataObject::pfnSetMfcString setMethod,
        CFormat* format,
        const TCHAR* getMethodName = 0,
        const TCHAR* setMethodName = 0);
#endif

    ///Constructor for the STL string-type field 
    CField(FID fid,                         
           const TCHAR* name,
           CDataObject::pfnGetStlString getMethod,
           CDataObject::pfnSetStlString setMethod,
           CFormat* format,
           const TCHAR* getMethodName = 0,
           const TCHAR* setMethodName = 0);

    ///Constructor for the char-type field 
    CField(FID fid,
           const TCHAR* name,
           CDataObject::pfnGetChar getMethod,
           CDataObject::pfnSetChar setMethod,
           CFormat* format,
           const TCHAR* getMethodName = 0,
           const TCHAR* setMethodName = 0);

    ///Constructor for the unsigned char-type field 
    CField(FID fid,
           const TCHAR* name,
           CDataObject::pfnGetUChar getMethod,
           CDataObject::pfnSetUChar setMethod,
           CFormat* format,
           const TCHAR* getMethodName = 0,
           const TCHAR* setMethodName = 0);

    ///Constructor for the short-type field 
    CField(FID fid,
           const TCHAR* name,
           CDataObject::pfnGetShort getMethod,
           CDataObject::pfnSetShort setMethod,
           CFormat* format,
           const TCHAR* getMethodName = 0,
           const TCHAR* setMethodName = 0);

    ///Constructor for the unsigned short-type field 
    CField(FID fid,                         
           const TCHAR* name,
           CDataObject::pfnGetUShort getMethod,
           CDataObject::pfnSetUShort setMethod,
           CFormat* format,
           const TCHAR* getMethodName = 0,
           const TCHAR* setMethodName = 0);

    ///Constructor for the long-type field 
    CField(FID fid,
           const TCHAR* name,
           CDataObject::pfnGetLong getMethod,
           CDataObject::pfnSetLong setMethod,
           CFormat* format,
           const TCHAR* getMethodName = 0,
           const TCHAR* setMethodName = 0);

    ///Constructor for the unsigned short-type field 
    CField(FID fid,
           const TCHAR* name,
           CDataObject::pfnGetULong getMethod,
           CDataObject::pfnSetULong setMethod,
           CFormat* format,
           const TCHAR* getMethodName = 0,
           const TCHAR* setMethodName = 0);

    ///Constructor for the int64-type field 
    CField(FID fid,
           const TCHAR* name,
           CDataObject::pfnGetInt64 getMethod,
           CDataObject::pfnSetInt64 setMethod,
           CFormat* format,
           const TCHAR* getMethodName = 0,
           const TCHAR* setMethodName = 0);

    ///Constructor for the bool-type field 
    CField(FID fid,               
           const TCHAR* name,
           CDataObject::pfnGetBool getMethod,
           CDataObject::pfnSetBool setMethod,
           CFormat* format,
           const TCHAR* getMethodName = 0,
           const TCHAR* setMethodName = 0);

    ///Constructor for the float-type field 
    CField(FID fid,
           const TCHAR* name,
           CDataObject::pfnGetFloat getMethod,
           CDataObject::pfnSetFloat setMethod,
           CFormat* format,
           const TCHAR* getMethodName = 0,
           const TCHAR* setMethodName = 0);

    ///Constructor for the double-type field 
    CField(FID fid,
           const TCHAR* name,
           CDataObject::pfnGetDouble getMethod,
           CDataObject::pfnSetDouble setMethod,
           CFormat* format,
           const TCHAR* getMethodName = 0,
           const TCHAR* setMethodName = 0);

    ///Constructor for the pointer to CDataObject - type field 
    CField(FID fid,                         
           const TCHAR* name,
           CDataObject::pfnGetObjectPtr getMethod,
           CDataObject::pfnSetObjectPtr setMethod,
           CFormat* format,
           const TCHAR* getMethodName = 0,
           const TCHAR* setMethodName = 0);

    virtual ~CField();                                          //!< Virtual destructor

    virtual CField* Clone() const;                              //<! makes a deep copy of the object


    inline FID          GetFid() const;                         //!< Gets a field identifier
    TString             GetName() const;                        //!< Gets a field name
    inline EnType       GetType() const;                        //!< Gets a field type
    inline CFormat*     GetFormat() const;                      //!< Gets a textual format
    TString             GetPfnGetName() const;                  //!< Gets the name of Get-methos
    TString             GetPfnSetName() const;                  //!< Gets the name of Set-methos
    
    inline bool         HasGetMethod() const;                   //!< Returns the value, indicating whether the field contains Get-method
    inline bool         HasSetMethod() const;                   //!< Returns the value, indicating whether the field contains Set-method

//Get methods
#ifndef DF_NOT_MFC
    inline CDataObject::pfnGetMfcString PfnGetMfcString() const;//!< Returns MFC string-type Get-method
#endif

    inline CDataObject::pfnGetStlString PfnGetStlString() const;//!< Returns STL string-type Get-method
    inline CDataObject::pfnGetChar      PfnGetChar() const;     //!< Returns char-type Get-method
    inline CDataObject::pfnGetUChar     PfnGetUChar() const;    //!< Returns unsigned char-type Get-method
    inline CDataObject::pfnGetShort     PfnGetShort() const;    //!< Returns short-type Get-method
    inline CDataObject::pfnGetUShort    PfnGetUShort() const;   //!< Returns unsigned short-type Get-method
    inline CDataObject::pfnGetLong      PfnGetLong() const;     //!< Returns long-type Get-method
    inline CDataObject::pfnGetULong     PfnGetULong() const;    //!< Returns unsigned long-type Get-method
    inline CDataObject::pfnGetInt64     PfnGetInt64() const;    //!< Returns __int64 type Get-method
    inline CDataObject::pfnGetBool      PfnGetBool() const;     //!< Returns bool-type Get-method
    inline CDataObject::pfnGetFloat     PfnGetFloat() const;    //!< Returns float-type Get-method
    inline CDataObject::pfnGetDouble    PfnGetDouble() const;   //!< Returns double-type Get-method
    inline CDataObject::pfnGetObjectPtr PfnGetObjectPtr() const;//!< Returns pointer to CDataObject type Get-method

//Set methods
#ifndef DF_NOT_MFC
    inline CDataObject::pfnSetMfcString PfnSetMfcString() const;//!< Returns MFC string-type Set-method
#endif
    inline CDataObject::pfnSetStlString PfnSetStlString() const;//!< Returns STL string-type Set-method
    inline CDataObject::pfnSetChar      PfnSetChar() const;     //!< Returns char-type Set-method
    inline CDataObject::pfnSetUChar     PfnSetUChar() const;    //!< Returns unsigned char-type Set-method
    inline CDataObject::pfnSetShort     PfnSetShort() const;    //!< Returns short-type Set-method
    inline CDataObject::pfnSetUShort    PfnSetUShort() const;   //!< Returns unsigned short-type Set-method
    inline CDataObject::pfnSetLong      PfnSetLong() const;     //!< Returns long-type Set-method
    inline CDataObject::pfnSetULong     PfnSetULong() const;    //!< Returns unsigned long-type Set-method
    inline CDataObject::pfnSetInt64     PfnSetInt64() const;    //!< Returns __int64 type Set-method
    inline CDataObject::pfnSetBool      PfnSetBool() const;     //!< Returns boolean-type Set-method
    inline CDataObject::pfnSetFloat     PfnSetFloat() const;    //!< Returns float-type Set-method
    inline CDataObject::pfnSetDouble    PfnSetDouble() const;   //!< Returns double-type Set-method
    inline CDataObject::pfnSetObjectPtr PfnSetObjectPtr() const;//!< Returns pointer to CDataObject type Set-method

protected:
    FID          m_Fid;
    TString*     m_Name;
    EnType       m_Type;
    CFormat*     m_Format;
    TString*     m_GetMethodName;
    TString*     m_SetMethodName;

    union
    {
#ifndef DF_NOT_MFC
        CDataObject::pfnGetMfcString m_fnGetMfcString;
#endif
        CDataObject::pfnGetStlString m_fnGetStlString;
        CDataObject::pfnGetChar      m_fnGetChar;
        CDataObject::pfnGetUChar     m_fnGetUChar;
        CDataObject::pfnGetShort     m_fnGetShort;
        CDataObject::pfnGetUShort    m_fnGetUShort;
        CDataObject::pfnGetLong      m_fnGetLong;
        CDataObject::pfnGetULong     m_fnGetULong;
        CDataObject::pfnGetInt64     m_fnGetInt64;
        CDataObject::pfnGetBool      m_fnGetBool;
        CDataObject::pfnGetFloat     m_fnGetFloat;
        CDataObject::pfnGetDouble    m_fnGetDouble;
        CDataObject::pfnGetObjectPtr m_fnGetObjectPtr;
    };
    union
    {
#ifndef DF_NOT_MFC
        CDataObject::pfnSetMfcString m_fnSetMfcString;
#endif
        CDataObject::pfnSetStlString m_fnSetStlString;
        CDataObject::pfnSetChar      m_fnSetChar;
        CDataObject::pfnSetUChar     m_fnSetUChar;
        CDataObject::pfnSetShort     m_fnSetShort;
        CDataObject::pfnSetUShort    m_fnSetUShort;
        CDataObject::pfnSetLong      m_fnSetLong;
        CDataObject::pfnSetULong     m_fnSetULong;
        CDataObject::pfnSetInt64     m_fnSetInt64;
        CDataObject::pfnSetBool      m_fnSetBool;
        CDataObject::pfnSetFloat     m_fnSetFloat;
        CDataObject::pfnSetDouble    m_fnSetDouble;
        CDataObject::pfnSetObjectPtr m_fnSetObjectPtr;
    };

private:
    CField& operator = (const CField& field);
};

inline FID      CField::GetFid() const          {return m_Fid;}
inline EnType   CField::GetType() const         {return m_Type;}
inline CFormat* CField::GetFormat() const       {return m_Format;}

#ifndef DF_NOT_MFC
inline CDataObject::pfnGetMfcString CField::PfnGetMfcString() const {return m_Type == MfcString ? m_fnGetMfcString : 0;}
#endif

inline CDataObject::pfnGetStlString CField::PfnGetStlString() const {return m_Type == StlString ? m_fnGetStlString : 0;}
inline CDataObject::pfnGetChar      CField::PfnGetChar()      const {return m_Type == Char   ? m_fnGetChar   : 0;}
inline CDataObject::pfnGetUChar     CField::PfnGetUChar()     const {return m_Type == UChar  ? m_fnGetUChar  : 0;}
inline CDataObject::pfnGetShort     CField::PfnGetShort()     const {return m_Type == Short  ? m_fnGetShort  : 0;}
inline CDataObject::pfnGetUShort    CField::PfnGetUShort()    const {return m_Type == UShort ? m_fnGetUShort : 0;}
inline CDataObject::pfnGetLong      CField::PfnGetLong()      const {return m_Type == Long   ? m_fnGetLong   : 0;}
inline CDataObject::pfnGetULong     CField::PfnGetULong()     const {return m_Type == ULong  ? m_fnGetULong  : 0;}
inline CDataObject::pfnGetInt64     CField::PfnGetInt64()     const {return m_Type == Int64  ? m_fnGetInt64  : 0;}
inline CDataObject::pfnGetBool      CField::PfnGetBool()      const {return m_Type == Bool   ? m_fnGetBool   : 0;}
inline CDataObject::pfnGetFloat     CField::PfnGetFloat()     const {return m_Type == Float  ? m_fnGetFloat  : 0;}
inline CDataObject::pfnGetDouble    CField::PfnGetDouble()    const {return m_Type == Double ? m_fnGetDouble : 0;}
inline CDataObject::pfnGetObjectPtr CField::PfnGetObjectPtr() const {return m_Type == ObjectPtr ? m_fnGetObjectPtr : 0;}

#ifndef DF_NOT_MFC
inline CDataObject::pfnSetMfcString CField::PfnSetMfcString() const {return m_Type == MfcString ? m_fnSetMfcString : 0;}
#endif

inline CDataObject::pfnSetStlString CField::PfnSetStlString() const {return m_Type == StlString ? m_fnSetStlString : 0;}
inline CDataObject::pfnSetChar      CField::PfnSetChar()      const {return m_Type == Char   ? m_fnSetChar   : 0;}
inline CDataObject::pfnSetUChar     CField::PfnSetUChar()     const {return m_Type == UChar  ? m_fnSetUChar  : 0;}
inline CDataObject::pfnSetShort     CField::PfnSetShort()     const {return m_Type == Short  ? m_fnSetShort  : 0;}
inline CDataObject::pfnSetUShort    CField::PfnSetUShort()    const {return m_Type == UShort ? m_fnSetUShort : 0;}
inline CDataObject::pfnSetLong      CField::PfnSetLong()      const {return m_Type == Long   ? m_fnSetLong   : 0;}
inline CDataObject::pfnSetULong     CField::PfnSetULong()     const {return m_Type == ULong  ? m_fnSetULong  : 0;}
inline CDataObject::pfnSetInt64     CField::PfnSetInt64()     const {return m_Type == Int64  ? m_fnSetInt64  : 0;}
inline CDataObject::pfnSetBool      CField::PfnSetBool()      const {return m_Type == Bool   ? m_fnSetBool   : 0;}
inline CDataObject::pfnSetFloat     CField::PfnSetFloat()     const {return m_Type == Float  ? m_fnSetFloat  : 0;}
inline CDataObject::pfnSetDouble    CField::PfnSetDouble()    const {return m_Type == Double ? m_fnSetDouble : 0;}
inline CDataObject::pfnSetObjectPtr CField::PfnSetObjectPtr() const {return m_Type == ObjectPtr ? m_fnSetObjectPtr : 0;}

inline bool CField::HasGetMethod() const    {return m_fnGetStlString != 0;}
inline bool CField::HasSetMethod() const    {return m_fnSetStlString != 0;}



}

}//namespace Dapfor

