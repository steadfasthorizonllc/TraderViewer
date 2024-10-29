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

namespace Dapfor
{
namespace GUI
{

//////////////////////////////////////////////////////////////////////////
///\brief Drag and drop settings.
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  CDragDropSettings DragDropSettings.h Dapfor/GUI/DragDropSettings.h
/// \file DragDropSettings.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CDragDropSettings
{
public:
    CDragDropSettings();                                    //!< Default constructor
    CDragDropSettings(const CDragDropSettings& settings);   //!< Copy constructor
    ~CDragDropSettings();                                   //!< Destructor

    /// Indicates whether items can be dragged from fixed context
    bool CanDragFromFixedContext() const;       

    /// Indicates whether items can be dragged from scrollable context
    bool CanDragFromScrollableContext() const;  

    /// Indicates whether non-selected children can be dragged with their parent
    bool CanDragNonSelectedChildren() const;    

    /// Indicates whether CGrid can drag the items, filtered by IGridFilter interface
    bool CanDragFilteredChildren() const;       

    /// Indicates whether items can be dropped to fixed context
    bool CanDropToFixedContext() const;         

    /// Indicates whether items can be dropped to scrollable context
    bool CanDropToScrollableContext() const;        

    /// Indicates whether CGrid can copy the clipboard content taken from the same grid
    bool CanLocalGridCopy() const;              

    /// Indicates whether CGrid can displace the items taken from the same grid via drag&drop operations
    bool CanLocalGridMove() const;              

    /// Indicates whether CGrid can copy the clipboard content taken from other grids
    bool CanRemoteGridCopy() const;             

    /// Indicates whether CGrid can detach the items taken from other grids and attach them to their own contexts
    bool CanRemoteGridMove() const;             

    /// Indicates whether CGrid can import data from other applications
    bool CanImportDataFromAnotherApplication() const;   

    /// Indicates that CGrid creates an image of the clipboard content while dragging
    bool CanGenerateDragImage() const;          

    /// Indicates whether CGrid can drop a clipboard content on any level of hierarchy.
    bool CanHierarchicalDrop() const;           

    /// Indicates whether dropping items can change their hierarchical level. 
    bool MustKeepLevel() const;                 

    /// Indicates whether CGrid should drop the clipboard content keeping the hierarchical structure.
    bool MustKeepParent() const;                    

    /// Gets a color of the indicators, that point to the dropping position and hierarchical level.
    COLORREF GetDropColor() const;                  




    /// Enables items to be dragged from fixed context
    void EnableDragFromFixedContext(bool bEnable);          

    /// Enables items to be dragged from scrollable context
    void EnableDragFromScrollableContext(bool    bEnable);  

    /// Enables non-selected children to be dragged with their parent
    void EnableDragNonSelectedChildren(bool bEnable);       

    /// Enables CGrid to drag the items, filtered by IGridFilter interface
    void EnableDragFilteredChildren(bool bEnable);          

    /// Enables items to be dropped to fixed context
    void EnableDropToFixedContext(bool   bEnable);          

    /// Enables items to be dropped to scrollable context
    void EnableDropToScrollableContext(bool  bEnable);      

    /// Enables CGrid to copy the clipboard content taken from the same grid
    void EnableLocalGridCopy(bool    bEnable);              

    /// Enables CGrid to displace the items taken from the same grid via drag&drop operations
    void EnableLocalGridMove(bool    bEnable);              

    /// Enables CGrid to copy the clipboard content taken from other grids
    void EnableRemoteGridCopy(bool   bEnable);              

    /// Enables CGrid to detach the items taken from other grids and attach them to their own contexts
    void EnableRemoteGridMove(bool   bEnable);              

    /// Enables CGrid to import data from other applications
    void EnableImportDataFromAnotherApplication(bool bEnable);  

    /// Enables CGrid to create an image of the clipboard content while dragging
    void EnableGenerateDragImage(bool    bEnable);          

    /// Enables CGrid to drop a clipboard content on any level of hierarchy.
    void EnableHierarchicalDrop(bool bEnable);              

    /// Forces item to be dropped only on the same hierarchical level.
    void SetKeepLevel(bool bEnable);                            

    /// Enables CGrid to drop clipboard content while preserving the hierarchical structure.
    void SetKeepParent(bool bEnable);                       

    /// Sets a new color of the indicators, that point to the dropping position and hierarchical level.
    void SetDropColor(COLORREF color);                      


    CDragDropSettings& operator = (const CDragDropSettings& settings);

    static int GetSerializeVertion();   //!< Serialization version
    void       Serialize(CArchive& ar); //!< Serializes/Deserializes this object to/from the archive


private:
    struct Impl;
    Impl* m_Impl;
};


}//namespace GUI

}//namespace Dapfor

