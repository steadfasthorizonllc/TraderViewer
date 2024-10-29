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

class CValue;
class CDataObject;
class CFormat;


/////////////////////////////////////////////////////////////////////////////
/// \brief CSerializer enables you to save objects in binary form 
/// and reconstruct them in memory from a binary archive. 
/// 
/// \class CSerializer Serializer.h <Dapfor/Common/Serializer.h>
///
/// \par Example
/// \include serialization.example
///
/////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CSerializer
{
public:
    /// Working mode
    enum Mode
    {
        Store,      //!< Stores objects into the binary storage
        Restore,    //!< Reconstructs objects in the memory from the binary storage
    };

    /// Base class for serialization exceptions
    struct SerializationException : public CommonException
    {
        ///Constructor
        SerializationException(const char* msg) : CommonException(msg)
        {
        }
    };

    ///Thrown when an object tries to restore itself from the archive with a version greater than the maximum supported.
    struct BadVersionException : public SerializationException
    {
        ///Constructor
        BadVersionException(const char* msg) : SerializationException(msg)
        {
        }
    };

    ///Thrown when an object doesn't support serialization
    struct NotSupportedException : public SerializationException
    {
        ///Constructor
        NotSupportedException(const char* msg) : SerializationException(msg)
        {
        }
    };


public:
    CSerializer(Mode mode);                         //!< Constructor
    CSerializer(const CSerializer& serializer);     //!< Copy constructor
    ~CSerializer();                                 //!< Destructor

    bool Write(void* buf, int len);                 //!< Writes bytes to the serializer

    CSerializer& operator<<(char v);                //!< Writes char-type value to the serializer
    CSerializer& operator<<(unsigned char v);       //!< Writes unsigned char-type value to the serializer
    CSerializer& operator<<(short v);               //!< Writes short-type value to the serializer
    CSerializer& operator<<(unsigned short v);      //!< Writes unsigned short-type value to the serializer
    CSerializer& operator<<(long v);                //!< Writes long-type value to the serializer
    CSerializer& operator<<(unsigned long v);       //!< Writes unsigned long-type value to the serializer
    CSerializer& operator<<(int v);                 //!< Writes int-type value to the serializer
    CSerializer& operator<<(unsigned int v);        //!< Writes unsigned int-type value to the serializer
    CSerializer& operator<<(int64 v);               //!< Writes __int64-type value to the serializer
    CSerializer& operator<<(float v);               //!< Writes float-type value to the serializer
    CSerializer& operator<<(double v);              //!< Writes double-type value to the serializer
    CSerializer& operator<<(bool v);                //!< Writes bool-type value to the serializer
#ifndef DF_NOT_MFC
    CSerializer& operator<<(const CString& v);      //!< Writes MFC string - type value to the serializer
#endif    
    CSerializer& operator<<(const TString& v);      //!< Writes STL string - type value to the serializer
    CSerializer& operator<<(const CValue& v);       //!< Writes an object of CValue class to the serializer
    CSerializer& operator<<(const CDataObject& v);  //!< Writes CDataObject instance to the serializer
    CSerializer& operator<<(const CFormat& v);      //!< Writes an object of CFormat class to the serializer

    bool Read(void* buf, int len);                  //!< Reads bytes from the serializer

    CSerializer& operator>>(char& v);               //!< Reads char-type value from the serializer
    CSerializer& operator>>(unsigned char& v);      //!< Reads unsigned char-type value from the serializer
    CSerializer& operator>>(short& v);              //!< Reads short-type value from the serializer
    CSerializer& operator>>(unsigned short& v);     //!< Reads unsigned short-type value from the serializer
    CSerializer& operator>>(long& v);               //!< Reads long-type value from the serializer
    CSerializer& operator>>(unsigned long& v);      //!< Reads unsigned long-type value from the serializer
    CSerializer& operator>>(int& v);                //!< Reads int-type value from the serializer
    CSerializer& operator>>(unsigned int& v);       //!< Reads unsigned int-type value from the serializer
    CSerializer& operator>>(int64& v);              //!< Reads __int64-type value from the serializer
    CSerializer& operator>>(float& v);              //!< Reads float-type value from the serializer
    CSerializer& operator>>(double& v);             //!< Reads double-type value from the serializer
    CSerializer& operator>>(bool& v);               //!< Reads bool-type value from the serializer
#ifndef DF_NOT_MFC
    CSerializer& operator>>(CString& v);            //!< Reads MFC string - type value from the serializer
#endif    
    CSerializer& operator>>(TString& v);            //!< Reads STL string - type value from the serializer
    CSerializer& operator>>(CValue& v);             //!< Reads an object of CValue class from the serializer
    CSerializer& operator>>(CDataObject& v);        //!< Reads CDataObject instance from the serializer
    CSerializer& operator>>(CFormat& v);            //!< Reads an object of CFormat class from the serializer


    int  SaveToBuffer(void* buffer) const;              //!< Copies serialized data to a binary buffer. 
    void LoadFromBuffer(const void* buffer, int size);  //!< Loads data from a binary buffer.
    int  GetSavingSize() const;                         //!< Gets the size of the buffer needed to copy serialized data.
    Mode GetMode() const;                               //!< Gets a mode
    void Clear();                                       //!< Clears all serialized data

    CSerializer& operator = (const CSerializer& serializer);    //!< Copy an operator

private:
    //Point implementation interface
    struct Impl;
    Impl*  m_Impl;
};

}//namespace Common

}//namespace Dapfor

