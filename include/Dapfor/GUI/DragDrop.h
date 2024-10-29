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
#include <Dapfor/GUI/IDragDrop.h>
#include <Dapfor/GUI/IObjectImporter.h>
#include <Dapfor/GUI/IClipboardFormat.h>

namespace Dapfor
{
namespace GUI
{

//////////////////////////////////////////////////////////////////////////
///\brief Default implementation of the drag and drop interface.
///
/// An object of this class can import data objects from other applications.
/// These objects are deserialized from binary presentation with help of Common::CTypeFactory 
/// and are stocked in the internal container. 
/// The restored objects can be obtained by calling GetImportedObjects(). When the application is stopped,
/// all non-retrieved data objects are destroyed in the destructor of this class. 
/// If you want to prevent their destruction, after each drop operation it should call 
/// RemoveImportedObjects(false).
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  CDragDrop DragDrop.h Dapfor/GUI/DragDrop.h
/// \file DragDrop.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CDragDrop : public IDragDrop, public IObjectImporter
{
public:
    ///List of the clipboard formats
    typedef std::vector<IClipboardFormat*> Formats;

public:
    CDragDrop(bool bAutoDelete = false);    //!< Constructor
    virtual ~CDragDrop();                   //!< Virtual destructor

    /// Registers a new clipboard format. The formats are applied in order of their registration.
    virtual void        RegisterFormat(IClipboardFormat* format);
    
    /// Gets a list of all registered formats
    virtual Formats&    GetFormats() const;

    // Called to perform a drag operation. 
    virtual DROPEFFECT  DoDrag(CDragSource& dragSource);

    // Called by CGrid when the cursor is dragged into the window for the first time.
    virtual DROPEFFECT  OnDragEnter(const CDropTarget& dropTarget);
    
    // Called by CGrid when the cursor is dragged over the window.
    virtual DROPEFFECT  OnDragOver(const CDropTarget& dropTarget);
    
    // Called by CGrid when a drop operation is to occur.
    virtual BOOL        OnDrop(const CDropTarget& dropTarget, DROPEFFECT dropEffect);
    
    // Called by the framework when the cursor leaves the window while a dragging operation is in effect.
    virtual void        OnDragLeave(const CGrid& grid);

    // The function indicates whether the data can be dropped to the specified location.
    virtual bool        CanDrop(const CDropTarget& dropTarget) const;

    /// Customization of a drag operation. 
    virtual DROPEFFECT  DoCustomDrag(CDragSource& dragSource, Formats formats);

    /// Customization of a drop operation. 
    virtual BOOL        DoCustomDrop(const CDropTarget& dropTarget, IClipboardFormat::RestoredInfo& restoredInfo, DROPEFFECT dropEffect);
    
    /// Tries to create a new data object of the class specified in the className parameter. 
    virtual Common::CDataObject* ImportObject(const TString& className) const;

    /// Gets all imported objects.
    virtual void GetImportedObjects(ImportedObjects& container) const;

    /// Removes all imported objects from the local cache. 
    virtual void RemoveImportedObjects(bool bDestroy);

    /// IAutoDelete implementation. Returns the value, passed in the constructor.
    virtual bool AutoDelete() const;

private:
    CDragDrop(const CDragDrop&);
    CDragDrop& operator = (const CDragDrop&);

    //Point implementation interface
    struct CDragDropImpl;
    CDragDropImpl* m_Impl;
};

}//namespace GUI

}//namespace Dapfor

