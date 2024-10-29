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

#include <vector>

#include <Dapfor/GUI/GUI_Export.h>
#include <Dapfor/GUI/Types.h>


namespace Dapfor
{
namespace Common
{
    class CDataObject;
    class CSerializer;
}


namespace GUI
{

//////////////////////////////////////////////////////////////////////////
///\brief Interface to import data objects from other applications.
///
/// These objects are deserialized from a binary presentation by Common::CTypeFactory.
/// Restored objects can be obtained by GetImportedObjects() call. When an application is stopped,
/// all non-retrieved data objects are destroyed. If you want to prevent them from destruction, 
/// after each drop operation it should call RemoveImportedObjects(false).
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  IObjectImporter IObjectImporter.h Dapfor/GUI/IObjectImporter.h
/// \file IObjectImporter.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API IObjectImporter
{
public:
    /// Container to store imported (created by Common::CTypeFactory) data objects 
    typedef std::vector<Common::CDataObject*> ImportedObjects;

public:
    
    /// Tries to create a new data object of the class specified in the className parameter. 
    virtual Common::CDataObject* ImportObject(const TString& className) const = 0;

    /// Copies all imported data objects to the container.
    virtual void GetImportedObjects(ImportedObjects& container) const = 0;

    /// Removes all imported objects from the local cache. 
    virtual void RemoveImportedObjects(bool bDestroy) = 0;
};


}//namespace GUI

}//namespace Dapfor

