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

#include <Dapfor/GUI/GUI_Export.h>
#include <Dapfor/GUI/Types.h>
#include <Dapfor/GUI/ICopyPaste.h>
#include <Dapfor/GUI/IObjectImporter.h>
#include <Dapfor/GUI/IClipboardFormat.h>

namespace Dapfor
{
namespace GUI
{
class CCutCopySource;

//////////////////////////////////////////////////////////////////////////
///\brief Default implementation of ICopyPaste interface.
///
/// Provides basic functionality to copy/cut/paste objects from one grid to another via the clipboard 
/// mechanism.
/// An object of this class can import data objects from other applications.
/// These objects are deserialized from a binary presentation with the help of Common::CTypeFactory 
/// and are stocked in the internal container. 
/// Restored objects can be obtained by GetImportedObjects() call. When the application is stopped,
/// all non retrieved data objects will be destroyed in the destructor of this class. 
/// If you want to prevent them from destruction, after each paste operation it should call 
/// RemoveImportedObjects(false).
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  CCopyPaste CopyPaste.h Dapfor/GUI/CopyPaste.h
/// \file CopyPaste.h
//////////////////////////////////////////////////////////////////////////
class CCopyPaste : public ICopyPaste, public IObjectImporter
{
public:
    ///List of the clipboard formats
    typedef std::vector<IClipboardFormat*> Formats;

public:
    CCopyPaste(bool bAutoDelete = false);   //!< Constructor
    virtual ~CCopyPaste();                  //!< Virtual destructor

    /// Registers a new clipboard format. The formats are applied in order of their registration.
    virtual void        RegisterFormat(IClipboardFormat* format);

    /// Gets a list of all registered formats
    virtual Formats&    GetFormats() const;

    ///Copies content of CGrid to the clipboard
    virtual bool Copy(const CGrid& grid);
    
    /// Cuts content of CGrid to the clipboard
    virtual bool Cut(const CGrid& grid);
    
    ///Pastes the data, placed in the clipboard to CGrid.
    virtual bool Paste(CPasteTarget& pasteTarget);

    /// Performs a copy/cut operation. The source has serializable content that can be modified.
    virtual bool CustomCutCopy(CCutCopySource& source);

    /// Performs a paste operation. The restoredInfo contains deserialized content which can be modified before being put to the grid.
    virtual bool CustomPaste(CPasteTarget& pasteTarget, IClipboardFormat::RestoredInfo& restoredInfo, OperationType type);

    /// Tries to create a new data object of the class specified in the className parameter. 
    virtual Common::CDataObject* ImportObject(const TString& className) const;

    /// Gets all imported objects.
    virtual void GetImportedObjects(ImportedObjects& container) const;

    /// Removes all imported objects from the local cache. 
    virtual void RemoveImportedObjects(bool bDestroy);

    /// IAutoDelete implementation. Returns the value, passed in the constructor.
    virtual bool AutoDelete() const;

private:
    CCopyPaste(const CCopyPaste&);
    CCopyPaste& operator = (const CCopyPaste&);

    //Point implementation interface
    struct CCopyPasteImpl;
    CCopyPasteImpl* m_Impl;
};

}

}//namespace Dapfor

