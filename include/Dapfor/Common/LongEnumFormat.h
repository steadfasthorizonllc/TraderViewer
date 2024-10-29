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
#include <Dapfor/Common/Format.h>

#include "assert.h"
#include <vector>

namespace Dapfor
{
namespace Common
{

///////////////////////////////////////////////////////////////////////////
/// \brief Converts enumerated value to a text and vice versa. 
///
/// \class CLongEnumFormat LongEnumFormat.h <Dapfor/Common/LongEnumFormat.h>
///
/// \par Format example:
/// \include enum_format.example
///
///////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CLongEnumFormat : public CFormat
{
public:

    ///Represents a pair of numeric value and a corresponding formatted string.
    struct DF_COMMON_API Item
    {
        long         m_Id;       //!< Numeric value
        const TCHAR* m_String;   //!< Formatted string
    };

    ///Container that holds pairs of formatted and non-formatted values.
    typedef std::vector< std::pair<long, TString> > Container;

public:
    CLongEnumFormat(const Container& container);
    CLongEnumFormat(const Item* const items, long itemCount) : CFormat(Long)
    {
        bool result = CreateLongEnumFormat(items, itemCount);
        
        //Two or more identically identifiers are presented in the array.
        assert(result);
    }
    
    CLongEnumFormat(const CLongEnumFormat& fmt);
    ~CLongEnumFormat();


    virtual TString FormatStl(long val, const CDataObject* pDO) const; 
    virtual bool    ParseStl(const TString& str, long& val, const CDataObject* pDO) const;

#ifndef DF_NOT_MFC
    virtual CString FormatMfc(long val, const CDataObject* pDO) const; 
    virtual bool    ParseMfc(const CString& str, long& val, const CDataObject* pDO) const;   
#endif//DF_NOT_MFC

    
    virtual CFormat* Clone() const;

    virtual bool IsEnum() const;
    virtual bool GetItems(Container& items) const;
    virtual bool AddItem(long value, const TString& text);
    virtual bool RemoveItem(long value);
    virtual TString& operator [](long value);
    


    static  int  GetSerializeVertion();
    virtual void Serialize(CSerializer& serializer);    //Serializes the format

private:
    CLongEnumFormat();
    bool CreateLongEnumFormat(const Item* const items, long itemCount);

    struct Impl;
    Impl*  m_Impl;


    DF_DECLARE_FORMAT()
};

}//namespace Common

}//namespace Dapfor


/// \file LongEnumFormat.h
///@{

/// \def DF_ENUM_FORMAT(__items)
/// \brief Creates a new Dapfor::Common::CLongEnumFormat with table of numeric values and corresponding strings.
/// \param[in] __items Table, which contains pairs of numeric values and formatted strings.
#define DF_ENUM_FORMAT(__items) new Dapfor::Common::CLongEnumFormat(__items, sizeof(__items)/sizeof(__items[0]))


///@}
