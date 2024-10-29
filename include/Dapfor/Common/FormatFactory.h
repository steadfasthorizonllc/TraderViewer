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
#include "assert.h"

namespace Dapfor
{
namespace Common
{

//Forward declaration
class CFormat;


///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Singleton which realizes a format factory. 
///
/// The factory enables creating CFormat object by a string. 
/// The factory was designed for serialization purpose, however it can be used in another way. 
/// To make format registration easier, DF_DECLARE_FORMAT() macro can be used. If there are two formats 
/// with the same name, but in different namespaces, an ambiguous situation may occur during 
/// the registration. To avoid this, it is recommended to use a full name together with a namespace name.
/// All the formats, included in this library can be created by CFormatFactory. 
/// 
/// \par Example:
/// \code
/// //You can get a format of CLongFormat type, by making the following:
/// 
/// Common::CFormat* format = CFormatFactory::Create("Common::CLongFormat");
/// \endcode
/// 
/// \version <b>1.0.0</b> Initial version
///
/// \class  CFormatFactory FormatFactory.h Dapfor/Common/FormatFactory.h
/// \file FormatFactory.h
///////////////////////////////////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CFormatFactory
{
public:
    typedef CFormat* (*pfnCreate)(); //!< Function prototype to create a format object

    /// Registers a new format
    static bool RegisterFormat(const TString& formatName, pfnCreate f)
    {
        bool result = InternalRegisterFormat(formatName, f);

        //The format can't be added to the factory because another format with the same 
        //name has already been added. To prevent the ambiguity, use namespace in the format declaration.
        //Ex: 
        //    DF_IMPLEMENT_FORMAT(MyNamespace::CMyFormat);
        assert(result);
        
        return result;
    }
    
    /// Creates a new format object by a string
    static CFormat* Create(const TString& formatName);

private:
    static bool InternalRegisterFormat(const TString& formatName, pfnCreate f);

    //Point implementation interface
    struct Impl;
    friend Impl;
} ;

}

}//namespace Dapfor
