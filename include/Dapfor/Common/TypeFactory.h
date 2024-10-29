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
class CDataObject;

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Singleton which realizes a data object factory. 
///
/// The factory is designed to create an object of a specific type by a class name. 
/// It is usually used during serialization of a data object in the archive, or when importing data 
/// from other applications (other address spaces) by using copy/copy or drag&drop. 
/// Declaration in the factory is usually realized by the macros DF_DECLARE_SERIALIZABLE_TYPE() and 
/// DF_IMPLEMENT_SERIALIZABLE_TYPE(). A class name in a factory must be unique. If two classes with the same names 
/// are used in the project, you can use namespace at declaration. 
///
/// \class  CTypeFactory TypeFactory.h Dapfor/Common/TypeFactory.h
///
/// \par Example:
/// \include serialization.example
///////////////////////////////////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CTypeFactory
{
public:
    typedef CDataObject* (ObjectCreator)(void); //!< Function prototype to create a data object of a specified class


    //!< Creates an object by the name of its class. 
    static CDataObject* CreateObject(const TString& className);

    //!< Registers a new class name with the function, that constructs an object.
    static bool RegisterClass(const TString& className, ObjectCreator* creator)
    {
        bool result = InternalRegisterClass(className, creator);
        
        // A class type with the same name has already been registered.
        // To resolve the conflict try to add into DF_IMPLEMENT_SERIALIZABLE_TYPE()
        // the name of namespace where this class has been declared. 
        // Ex: DF_IMPLEMENT_SERIALIZABLE_TYPE(MyNameSpace::MyClass)
        assert(result); 
        
        return result;
    }

private:
    static bool InternalRegisterClass(const TString& className, ObjectCreator* creator);

    //Point implementation interface
    struct Impl;
    friend Impl;
};


}//namespace Common

}//namespace Dapfor


