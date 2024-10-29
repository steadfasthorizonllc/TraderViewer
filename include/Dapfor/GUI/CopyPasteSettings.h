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
///\brief Copy/cut/paste settings.
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  CCopyPasteSettings CopyPasteSettings.h Dapfor/GUI/CopyPasteSettings.h
/// \file CopyPasteSettings.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CCopyPasteSettings
{
public:
    /// Paste placement
    enum PasteType
    {
        pasteAsFirstClild,          //!< Paste as the first child of the focused row
        pasteAsLastClild,           //!< Paste as the last child of the focused row
        pasteAfterFocusedRow,       //!< Paste after the focused row at the same hierarchical level
        pasteAsRootItem,            //!< Paste after the focused row as the root item (hierarchical level = 0)

        defaultPasteType = pasteAsRootItem,
    };

    /// Scrolling & visibility ensuring 
    enum EnsureVisibleMode
    {
        ensureVisibleNone,          //!< Doesn't ensure visibility
        ensureVisibleFirstInserted, //!< Ensures visibility of the first inserted row
        ensureVisibleLastInserted,  //!< Ensures visibility of the last inserted row
        ensureVisibleFocusedRow,    //!< Ensures visibility of the focused row

        defaultEnsureVisibleMode = ensureVisibleFocusedRow,
    };

    /// Focus manipulation
    enum FocusMode
    {
        focusRemove,                //!< Removes the focus
        focusFirstInserted,         //!< Focuses the first inserted row
        focusLastInserted,          //!< Focuses the last inserted row
        focusFlatLastInserted,      //!< Focuses the last inserted row at the same hierarchical level as the first one

        focusFocusMode = focusFlatLastInserted,
    };


public:
    CCopyPasteSettings();                                   //!< Constructor
    CCopyPasteSettings(const CCopyPasteSettings& settings); //!< Copy constructor
    ~CCopyPasteSettings();                                  //!< Destructor


    /// Indicates whether items can be copied from fixed context
    bool CanCopyFromFixedContext() const;           
    
    /// Indicates whether items can be copied from scrollable context
    bool CanCopyFromScrollableContext() const;      
    
    /// Indicates whether non-selected children can be copied with their parent
    bool CanCopyNonSelectedChildren() const;        
    
    /// Indicates whether CGrid can copy the items, filtered by IGridFilter interface
    bool CanCopyFilteredChildren() const;           
    
    /// Indicates whether items can be cut from fixed context
    bool CanCutFromFixedContext() const;            
    
    /// Indicates whether items can be cut from scrollable context
    bool CanCutFromScrollableContext() const;       
    
    /// Indicates whether items can be pasted to fixed context
    bool CanPasteToFixedContext() const;            
    
    /// Indicates whether items can be pasted to scrollable context
    bool CanPasteToScrollableContext() const;       
    
    /// Indicates whether a paste operation is possible if CGrid doesn't have a focused line
    bool CanPasteWhenNoFocus() const;               
    
    /// Indicates that CGrid pastes items to the end of the scrollable (if cannot to the fixed) context if there is no focus.
    bool CanPasteWhenNoFocusToEnd() const;          
    
    /// Indicates whether CGrid can import data from other applications.
    bool CanImportDataFromAnotherApplication() const;   
    
    /// Gets paste position
    PasteType GetPasteType() const;                     
    
    /// Visibility ensuring operations to be performed
    EnsureVisibleMode GetEnsureVisibleMode() const;             
    
    /// Focus displacement
    FocusMode GetFocusMode() const;                     




    /// Enables copying from fixed context
    void EnableCopyFromFixedContext(bool bEnable);              
    
    /// Enables copying from scrollable context
    void EnableCopyFromScrollableContext(bool bEnable);         
    
    /// Enables copying non-selected children with their parent
    void EnableCopyNonSelectedChildren(bool bEnable);           
    
    /// Enables copying items, filtered by IGridFilter interface
    void EnableCopyFilteredChildren(bool bEnable);              
    
    /// Enables cutting from fixed context
    void EnableCutFromFixedContext(bool bEnable);               
    
    /// Enables cutting from scrollable context
    void EnableCutFromScrollableContext(bool bEnable);          
    
    /// Enables pasting to fixed context
    void EnablePasteToFixedContext(bool bEnable);               
    
    /// Enables pasting to scrollable context
    void EnablePasteToScrollableContext(bool bEnable);          
    
    /// Enables pasting when CGrid doesn't have a focused line
    void EnablePasteWhenNoFocus(bool bEnable);                  
    
    /// Permits CGrid to paste items to the end of scrollable context (if cannot paste to fixed contex)if there is no focus.
    void EnablePasteWhenNoFocusToEnd(bool bEnable);             
    
    /// Enables copying data from other applications
    void EnableImportDataFromAnotherApplication(bool bEnable);  
    
    /// Sets a new paste position
    void SetPasteType(PasteType pasteType);                     
    
    /// Sets new visibility ensuring operations to be performed
    void SetEnsureVisibleMode(EnsureVisibleMode ensureVisibleMode); 
    
    /// Sets a new focus displacement mode
    void SetFocusMode(FocusMode focusMode);                     


    static int GetSerializeVertion();   //!< Serialization version                              
    void       Serialize(CArchive& ar); //!< Serializes/deserializes object to/from the archive

    CCopyPasteSettings& operator = (const CCopyPasteSettings& settings);
 
private:
    struct Impl;
    Impl* m_Impl;
};


}//namespace GUI

}//namespace Dapfor

