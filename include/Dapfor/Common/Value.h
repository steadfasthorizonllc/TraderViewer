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

namespace Dapfor
{

namespace Common
{

class CFormat;
class CSerializer;
class CDataObject;

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Stores value of the primitive type used by Common and GUI libraries.
/// 
/// The value can be one of the following types:
/// \n 1.  STL string
/// \n 2.  MFC CString
/// \n 3.  char
/// \n 4.  undefined char
/// \n 5.  short
/// \n 6.  undefined short
/// \n 7.  long
/// \n 8.  undefined long
/// \n 9.  __int64
/// \n 10.  float
/// \n 11. double
/// \n 12. bool
///
/// \par Thread safety
/// Functions of the class are not thread-safe.
///
/// \class  CValue Value.h Dapfor/Common/Value.h
/// \file Value.h
///////////////////////////////////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CValue
{
public:
    CValue() ;                      //Default constructor 
    CValue( const CValue& v);       //Copy constructor
#ifndef DF_NOT_MFC    
    CValue( const CString& v );     //MfcString type constructor
#endif
    CValue( const TString& v );     //StlString type constructor
    CValue( char v ) ;              //Char type constructor
    CValue( unsigned char v ) ;     //Unsigned char type constructor
    CValue( short v ) ;             //Short type constructor
    CValue( unsigned short v) ;     //Unsigned short type constructor
    CValue( long v) ;               //Long type constructor
    CValue( unsigned long v) ;      //Unsigned long type constructor
    CValue( int64 v) ;              //Int64 type constructor
    CValue( bool v ) ;              //Bool type constructor
    CValue( float v) ;              //Float type constructor
    CValue( double v) ;             //Double type constructor
    CValue( CDataObject* v) ;       //Pointer to CDataObject type constructor
    ~CValue() ;                     //Destructor




    CValue& operator=( const CValue& ) ;
#ifndef DF_NOT_MFC    
    inline CValue& operator=( const CString& ) ;
#endif
    inline CValue& operator=( const TString& ) ;
    inline CValue& operator=( char ) ;
    inline CValue& operator=( unsigned char ) ;
    inline CValue& operator=( short ) ;
    inline CValue& operator=( unsigned short ) ;
    inline CValue& operator=( long ) ;
    inline CValue& operator=( unsigned long ) ;
    inline CValue& operator=( int64 ) ;
    inline CValue& operator=( float ) ;
    inline CValue& operator=( bool  ) ;
    inline CValue& operator=( double ) ;
    inline CValue& operator=( CDataObject* ) ;

#ifndef DF_NOT_MFC    
    inline operator const CString& () const ;
#endif
    inline operator const TString& () const ;
    inline operator char() const ;
    inline operator unsigned char() const ;
    inline operator short() const ;
    inline operator unsigned short() const ;
    inline operator long() const ;
    inline operator unsigned long() const ;
    inline operator int64() const ;
    inline operator bool() const ;
    inline operator float() const ;
    inline operator double() const ;
    inline operator CDataObject*() const;

    bool operator == (const CValue&) const;
#ifndef DF_NOT_MFC    
    bool operator == (const CString&) const;
#endif
    bool operator == (const TString&) const;
    inline bool operator == (char) const;
    inline bool operator == (unsigned char) const;
    inline bool operator == (short) const;
    inline bool operator == (unsigned short) const;
    inline bool operator == (long) const;
    inline bool operator == (unsigned long) const;
    inline bool operator == (int64) const;
    inline bool operator == (bool) const;
    inline bool operator == (float) const;
    inline bool operator == (double) const;
    inline bool operator == (CDataObject*) const;

    inline bool operator != (const CValue&) const;
#ifndef DF_NOT_MFC    
    inline bool operator != (const CString&) const;
#endif
    inline bool operator != (const TString&) const;
    inline bool operator != (char) const;
    inline bool operator != (unsigned char) const;
    inline bool operator != (short) const;
    inline bool operator != (unsigned short) const;
    inline bool operator != (long) const;
    inline bool operator != (unsigned long) const;
    inline bool operator != (int64) const;
    inline bool operator != (bool) const;
    inline bool operator != (float) const;
    inline bool operator != (double) const;
    inline bool operator != (CDataObject*) const;


    bool operator < (const CValue&) const;
#ifndef DF_NOT_MFC    
    bool operator < (const CString&) const;
#endif
    bool operator < (const TString&) const;
    inline bool operator < (char) const;
    inline bool operator < (unsigned char) const;
    inline bool operator < (short) const;
    inline bool operator < (unsigned short) const;
    inline bool operator < (long) const;
    inline bool operator < (unsigned long) const;
    inline bool operator < (int64) const;
    inline bool operator < (bool) const;
    inline bool operator < (double) const;
    inline bool operator < (float) const;
    inline bool operator < (CDataObject*) const;

    bool operator <= (const CValue&) const;
#ifndef DF_NOT_MFC    
    bool operator <= (const CString&) const;
#endif
    bool operator <= (const TString&) const;
    inline bool operator <= (char) const;
    inline bool operator <= (unsigned char) const;
    inline bool operator <= (short) const;
    inline bool operator <= (unsigned short) const;
    inline bool operator <= (long) const;
    inline bool operator <= (unsigned long) const;
    inline bool operator <= (int64) const;
    inline bool operator <= (bool) const;
    inline bool operator <= (float) const;
    inline bool operator <= (double) const;
    inline bool operator <= (CDataObject*) const;


    bool operator > (const CValue&) const;
#ifndef DF_NOT_MFC    
    bool operator > (const CString&) const;
#endif
    bool operator > (const TString&) const;
    inline bool operator > (char) const;
    inline bool operator > (unsigned char) const;
    inline bool operator > (short) const;
    inline bool operator > (unsigned short) const;
    inline bool operator > (long) const;
    inline bool operator > (unsigned long) const;
    inline bool operator > (int64) const;
    inline bool operator > (bool) const;
    inline bool operator > (float) const;
    inline bool operator > (double) const;
    inline bool operator > (CDataObject*) const;


    bool operator >= (const CValue&) const;
#ifndef DF_NOT_MFC    
    bool operator >= (const CString&) const;
#endif
    bool operator >= (const TString&) const;
    inline bool operator >= (char) const;
    inline bool operator >= (unsigned char) const;
    inline bool operator >= (short) const;
    inline bool operator >= (unsigned short) const;
    inline bool operator >= (long) const;
    inline bool operator >= (unsigned long) const;
    inline bool operator >= (int64) const;
    inline bool operator >= (bool) const;
    inline bool operator >= (float) const;
    inline bool operator >= (double) const;
    inline bool operator >= (CDataObject*) const;


    TString FormatStl( const CFormat* format ) const;           //!< Formats value to the formatted STL string
    bool ParseStl( const CFormat* format, const TString& str);  //!< Parses a formatted STL string to the non-formatted value
    static TString& GetEmptyStlString();                        //!< Returns a reference to an empty STL string

#ifndef DF_NOT_MFC    
    CString FormatMfc( const CFormat* format ) const;           //!< Formats value to the MFC formatted string
    bool ParseMfc( const CFormat* format, const CString& str);  //!< Parses a MFC formatted string to the non-formatted value
    static CString& GetEmptyMfcString();                        //!< Returns a reference to an empty MFC string
#endif//DF_NOT_MFC

    inline EnType GetType() const;                              //!< Gets a value type
    static unsigned char GetSerializeVertion();                 //!< Gets a serialization version
    void Serialize(CSerializer& serializer);                    //!< Serializes this object to CSerializer

private:
    void SetStlString( const TString& str ) ;
#ifndef DF_NOT_MFC    
    void SetMfcString( const CString& str ) ;
#endif

    union Value
    {
#ifndef DF_NOT_MFC    
        CString*        m_MfcString;
#endif
        TString*        m_StlString;
        char            m_Char;
        unsigned char   m_UChar;
        short           m_Short;
        unsigned short  m_UShort;
        long            m_Long;
        unsigned long   m_ULong;
        int64           m_Int64;
        bool            m_Bool; 
        float           m_Float;
        double          m_Double;
        CDataObject*    m_DataObject;
    } ;
    Value               m_Value;
    EnType              m_Type;
} ;


#ifndef DF_NOT_MFC    
inline CValue::operator const CString& () const 
{
    return m_Type == MfcString && m_Value.m_MfcString ? *m_Value.m_MfcString : GetEmptyMfcString();
}
#endif

inline CValue::operator const TString& () const 
{
    return m_Type == StlString && m_Value.m_StlString ? *m_Value.m_StlString : GetEmptyStlString();
}
inline CValue::operator char() const 
{
    return m_Type == Char ? m_Value.m_Char : 0;
}
inline CValue::operator unsigned char() const 
{
    return m_Type == UChar ? m_Value.m_UChar : 0;
}
inline CValue::operator short() const 
{
    return m_Type == Short ? m_Value.m_Short : 0;
}
inline CValue::operator unsigned short() const 
{
    return m_Type == UShort ? m_Value.m_UShort : 0;
}
inline CValue::operator long() const
{
    return m_Type == Long ? m_Value.m_Long : 0;
}
inline CValue::operator unsigned long() const
{
    return m_Type == ULong ? m_Value.m_ULong : 0;
}
inline CValue::operator int64() const 
{
    return m_Type == Int64 ? m_Value.m_Int64 : 0;
}
inline CValue::operator bool() const
{
    return m_Type == Bool ? m_Value.m_Bool : 0;
}
inline CValue::operator float() const 
{
    return m_Type == Float ? m_Value.m_Float : 0;
}
inline CValue::operator double() const 
{
    return m_Type == Double ? m_Value.m_Double : 0;
}
inline CValue::operator CDataObject*() const 
{
    return m_Type == ObjectPtr ? m_Value.m_DataObject : 0;
}

#ifndef DF_NOT_MFC    
inline CValue& CValue::operator=( const CString& s)
{
    if(m_Type == Undefined) {m_Value.m_MfcString = 0; m_Type = MfcString;}
    SetMfcString(s);
    return *this;
}
#endif


inline CValue& CValue::operator=( const TString& s)
{
    if(m_Type == Undefined) {m_Value.m_StlString = 0; m_Type = StlString;}
    SetStlString(s);
    return *this;
}

inline CValue& CValue::operator=( char ch)
{
    if(m_Type == Char) m_Value.m_Char = ch;
    else 
    {
        if(m_Type == Undefined) {m_Value.m_Char = ch; m_Type = Char;}
    } 
    return *this ;
}

inline CValue& CValue::operator=(unsigned char ch)
{
    if(m_Type == UChar) m_Value.m_UChar = ch;
    else 
    {
        if(m_Type == Undefined) {m_Value.m_UChar = ch; m_Type = UChar;}
    } 
    return *this ;
}

inline CValue& CValue::operator=( short sh)
{
    if(m_Type == Short) m_Value.m_Short = sh;
    else 
    {
        if(m_Type == Undefined) {m_Value.m_Short = sh; m_Type = Short;}
    } 
    return *this ;
}

inline CValue& CValue::operator=(unsigned short sh)
{
    if(m_Type == UShort) m_Value.m_Short = sh;
    else 
    {
        if(m_Type == Undefined) {m_Value.m_Short = sh; m_Type = UShort;}
    } 
    return *this ;
}

inline CValue& CValue::operator=( long l )
{
    if(m_Type == Long) m_Value.m_Long = l;
    else 
    {
        if(m_Type == Undefined) {m_Value.m_Long = l; m_Type = Long;}
    }
    return *this ;
}

inline CValue& CValue::operator=(unsigned long l )
{
    if(m_Type == ULong) m_Value.m_Long = l;
    else 
    {
        if(m_Type == Undefined) {m_Value.m_Long = l; m_Type = ULong;}
    }
    return *this ;
}

inline CValue& CValue::operator=( int64 d)
{
    if(m_Type == Int64) m_Value.m_Int64 = d;
    else 
    {
        if(m_Type == Undefined) {m_Value.m_Int64 = d; m_Type = Int64;}
    } 
    return *this ;
}

inline CValue& CValue::operator=( bool b )
{
    if(m_Type == Bool) m_Value.m_Bool = b; 
    else 
    {
        if(m_Type == Undefined) {m_Value.m_Bool = b; m_Type = Bool;}
    } 
    return *this ;
}

inline CValue& CValue::operator=( float d)
{
    if(m_Type == Float) m_Value.m_Float = d;
    else 
    {
        if(m_Type == Undefined) {m_Value.m_Float = d; m_Type = Float;}
    } 
    return *this ;
}

inline CValue& CValue::operator=( double d)
{
    if(m_Type == Double) m_Value.m_Double = d;
    else 
    {
        if(m_Type == Undefined) {m_Value.m_Double = d; m_Type = Double;}
    } 
    return *this ;
}
inline CValue& CValue::operator=( CDataObject* o)
{
    if(m_Type == ObjectPtr) m_Value.m_DataObject = o;
    else 
    {
        if(m_Type == Undefined) {m_Value.m_DataObject = o; m_Type = ObjectPtr;}
    } 
    return *this ;
}

inline bool CValue::operator == (char ch) const
{
    if(m_Type == Char) return m_Value.m_Char == ch;
    else {return false;}
}
inline bool CValue::operator == (unsigned char ch) const
{
    if(m_Type == UChar) return m_Value.m_UChar == ch;
    else {return false;}
}
inline bool CValue::operator == (short sh) const
{
    if(m_Type == Short) return m_Value.m_Short == sh;
    else {return false;}
}
inline bool CValue::operator == (unsigned short sh) const
{
    if(m_Type == UShort) return m_Value.m_UShort == sh;
    else {return false;}
}
inline bool CValue::operator == (long l) const
{
    if(m_Type == Long) return m_Value.m_Long == l;
    else {return false;}
}
inline bool CValue::operator == (unsigned long l) const
{
    if(m_Type == ULong) return m_Value.m_ULong == l;
    else {return false;}
}
inline bool CValue::operator == (int64 d) const
{
    if(m_Type == Int64) return m_Value.m_Int64 == d;
    else {return false;}
}
inline bool CValue::operator == (bool b) const
{
    if(m_Type == Bool) return m_Value.m_Bool == b;
    else {return false;}
}
inline bool CValue::operator == (float d) const
{
    if(m_Type == Float) return m_Value.m_Float == d;
    else {return false;}
}
inline bool CValue::operator == (double d) const
{
    if(m_Type == Double) return m_Value.m_Double == d;
    else {return false;}
}
inline bool CValue::operator == (CDataObject* o) const
{
    if(m_Type == ObjectPtr) return m_Value.m_DataObject == o;
    else {return false;}
}


#ifndef DF_NOT_MFC    
inline bool CValue::operator != (const CString& s) const
{
    return !(*this == s);
}
#endif

inline bool CValue::operator != (const CValue& v) const
{
    return !(*this == v);
}
inline bool CValue::operator != (const TString& s) const
{
    return !(*this == s);
}
inline bool CValue::operator != (char ch) const
{
    return !(*this == ch);
}
inline bool CValue::operator != (unsigned char ch) const
{
    return !(*this == ch);
}
inline bool CValue::operator != (short sh) const
{
    return !(*this == sh);
}
inline bool CValue::operator != (unsigned short sh) const
{
    return !(*this == sh);
}
inline bool CValue::operator != (long l) const
{
    return !(*this == l);
}
inline bool CValue::operator != (unsigned long l) const
{
    return !(*this == l);
}
inline bool CValue::operator != (int64 d) const
{
    return !(*this == d);
}
inline bool CValue::operator != (bool b) const
{
    return !(*this == b);
}
inline bool CValue::operator != (float d) const
{
    return !(*this == d);
}
inline bool CValue::operator != (double d) const
{
    return !(*this == d);
}
inline bool CValue::operator != (CDataObject* o) const
{
    return !(*this == o);
}


inline bool CValue::operator < (char ch) const
{
    if(m_Type == Char) return m_Value.m_Char < ch;
    else {return false;}
}
inline bool CValue::operator < (unsigned char ch) const
{
    if(m_Type == UChar) return m_Value.m_UChar < ch;
    else {return false;}
}
inline bool CValue::operator < (short sh) const
{
    if(m_Type == Short) return m_Value.m_Short < sh;
    else {return false;}
}
inline bool CValue::operator < (unsigned short sh) const
{
    if(m_Type == UShort) return m_Value.m_UShort < sh;
    else {return false;}
}
inline bool CValue::operator < (long l) const
{
    if(m_Type == Long) return m_Value.m_Long < l;
    else {return false;}
}
inline bool CValue::operator < (unsigned long l) const
{
    if(m_Type == ULong) return m_Value.m_ULong < l;
    else {return false;}
}
inline bool CValue::operator < (int64 i64) const
{
    if(m_Type == Int64) return m_Value.m_Int64 < i64;
    else {return false;}
}
inline bool CValue::operator < (bool b) const
{
    if(m_Type == Bool) return m_Value.m_Bool < b;
    else {return false;}
}
inline bool CValue::operator < (float f) const
{
    if(m_Type == Float) return m_Value.m_Float < f;
    else {return false;}
}
inline bool CValue::operator < (double d) const
{
    if(m_Type == Double) return m_Value.m_Double < d;
    else {return false;}
}
inline bool CValue::operator < (CDataObject* o) const
{
    if(m_Type == ObjectPtr) return m_Value.m_DataObject < o;
    else {return false;}
}

inline bool CValue::operator <= (char ch) const
{
    if(m_Type == Char) return m_Value.m_Char <= ch;
    else {return false;}
}
inline bool CValue::operator <= (unsigned char ch) const
{
    if(m_Type == UChar) return m_Value.m_UChar <= ch;
    else {return false;}
}
inline bool CValue::operator <= (short sh) const
{
    if(m_Type == Short) return m_Value.m_Short <= sh;
    else {return false;}
}
inline bool CValue::operator <= (unsigned short sh) const
{
    if(m_Type == UShort) return m_Value.m_UShort <= sh;
    else {return false;}
}
inline bool CValue::operator <= (long l) const
{
    if(m_Type == Long) return m_Value.m_Long <= l;
    else {return false;}
}
inline bool CValue::operator <= (unsigned long l) const
{
    if(m_Type == ULong) return m_Value.m_ULong <= l;
    else {return false;}
}
inline bool CValue::operator <= (int64 i64) const
{
    if(m_Type == Int64) return m_Value.m_Int64 <= i64;
    else {return false;}
}
inline bool CValue::operator <= (bool b) const
{
    if(m_Type == Bool) return m_Value.m_Bool <= b;
    else {return false;}
}
inline bool CValue::operator <= (float f) const
{
    if(m_Type == Float) return m_Value.m_Float <= f;
    else {return false;}
}
inline bool CValue::operator <= (double d) const
{
    if(m_Type == Double) return m_Value.m_Double <= d;
    else {return false;}
}
inline bool CValue::operator <= (CDataObject* o) const
{
    if(m_Type == ObjectPtr) return m_Value.m_DataObject <= o;
    else {return false;}
}

inline bool CValue::operator > (char ch) const
{
    if(m_Type == Char) return m_Value.m_Char > ch;
    else {return false;}
}
inline bool CValue::operator > (unsigned char ch) const
{
    if(m_Type == UChar) return m_Value.m_UChar > ch;
    else {return false;}
}
inline bool CValue::operator > (short sh) const
{
    if(m_Type == Short) return m_Value.m_Short > sh;
    else {return false;}
}
inline bool CValue::operator > (unsigned short sh) const
{
    if(m_Type == UShort) return m_Value.m_UShort > sh;
    else {return false;}
}
inline bool CValue::operator > (long l) const
{
    if(m_Type == Long) return m_Value.m_Long > l;
    else {return false;}
}
inline bool CValue::operator > (unsigned long l) const
{
    if(m_Type == ULong) return m_Value.m_ULong > l;
    else {return false;}
}
inline bool CValue::operator > (int64 i64) const
{
    if(m_Type == Int64) return m_Value.m_Int64 > i64;
    else {return false;}
}
inline bool CValue::operator > (bool b) const
{
    if(m_Type == Bool) return m_Value.m_Bool > b;
    else {return false;}
}
inline bool CValue::operator > (float f) const
{
    if(m_Type == Float) return m_Value.m_Float > f;
    else {return false;}
}
inline bool CValue::operator > (double d) const
{
    if(m_Type == Double) return m_Value.m_Double > d;
    else {return false;}
}
inline bool CValue::operator > (CDataObject* o) const
{
    if(m_Type == ObjectPtr) return m_Value.m_DataObject > o;
    else {return false;}
}


inline bool CValue::operator >= (char ch) const
{
    if(m_Type == Char) return m_Value.m_Char >= ch;
    else {return false;}
}
inline bool CValue::operator >= (unsigned char ch) const
{
    if(m_Type == UChar) return m_Value.m_UChar >= ch;
    else {return false;}
}
inline bool CValue::operator >= (short sh) const
{
    if(m_Type == Short) return m_Value.m_Short >= sh;
    else {return false;}
}
inline bool CValue::operator >= (unsigned short sh) const
{
    if(m_Type == UShort) return m_Value.m_UShort >= sh;
    else {return false;}
}
inline bool CValue::operator >= (long l) const
{
    if(m_Type == Long) return m_Value.m_Long >= l;
    else {return false;}
}
inline bool CValue::operator >= (unsigned long l) const
{
    if(m_Type == ULong) return m_Value.m_ULong >= l;
    else {return false;}
}
inline bool CValue::operator >= (int64 i64) const
{
    if(m_Type == Int64) return m_Value.m_Int64 >= i64;
    else {return false;}
}
inline bool CValue::operator >= (bool b) const
{
    if(m_Type == Bool) return m_Value.m_Bool >= b;
    else {return false;}
}
inline bool CValue::operator >= (float f) const
{
    if(m_Type == Float) return m_Value.m_Float >= f;
    else {return false;}
}
inline bool CValue::operator >= (double d) const
{
    if(m_Type == Double) return m_Value.m_Double >= d;
    else {return false;}
}
inline bool CValue::operator >= (CDataObject* o) const
{
    if(m_Type == ObjectPtr) return m_Value.m_DataObject >= o;
    else {return false;}
}


inline EnType CValue::GetType() const 
{
    return m_Type ;
}

}//namespace Common

}//namespace Dapfor

