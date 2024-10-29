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
#include <Dapfor/GUI/IKeyManager.h>

namespace Dapfor
{
namespace GUI
{
class CGrid;

//////////////////////////////////////////////////////////////////////////
///\brief Default implementation of IKeyManager interface
///
/// The given manager processes the following events:
/// - Escape:         Removes a selection, takes focus away
/// - KeyUp:          Moves focus one line up
/// - KeyDown:        Moves focus one line down
/// - PageUp:         Moves focus one page up 
/// - PageDown:       Moves focus one page down
/// - Home:           Moves focus at the beginning of a context (fixed or scrollable)
/// - End:            Moves focus at the end of a context (fixed or scrollable)
/// - Space:          Moves focus one page down
/// - Shift+Space:    Moves focus one page up
/// - KeyLeft:        Collapses children for focused line or moves focus one line up 
/// - KeyRight:       Expands children for focused line or moves focus one line down
/// - Return:         Collapses or expands children for focused line
/// - Ctrl+A, Ctrl+a: Selects all lines in the grid
/// - Ctrl+C, Ctrl+c: Copies a selection to the clipboard
/// - Ctrl+X, Ctrl+x: Cuts a selection to the clipboard 
/// - Ctrl+V, Ctrl+v: Inserts data from the clipboard into the grid
///
/// Pressing Shift key together with KeyUp KeyDown inverts selection multiple lines. 
/// The manager can be used for navigation and selection in either one or both contexts.
///
/// \class  CKeyManager KeyManager.h Dapfor/GUI/KeyManager.h
/// \file KeyManager.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CKeyManager : public IKeyManager
{
public:
    CKeyManager(bool autoDelete = false);   //!< Constructor
    ~CKeyManager();                         //!< Destructor


    // Called when a nonsystem key is pressed
    virtual BOOL OnKeyDown(CGrid& grid, UINT nChar, UINT nRepCnt, UINT nFlags);
    
    // Called when a nonsystem key is released
    virtual BOOL OnKeyUp(CGrid& grid, UINT nChar, UINT nRepCnt, UINT nFlags);

    // Moves focus up and scrolls down one line according to specified 
    // values of bShift and bCtrl and navigation settings
    virtual void NavigateKeyUp(CGrid& grid, bool bShift, bool bCtrl);
    
    // Moves focus down and scrolls up one line according to specified 
    // values of bShift and bCtrl and navigation settings
    virtual void NavigateKeyDown(CGrid& grid, bool bShift, bool bCtrl);
    
    // Moves focus up and scrolls down one page according to specified 
    // values of bShift and bCtrl and navigation settings
    virtual void NavigateKeyPageUp(CGrid& grid, bool bShift, bool bCtrl);
    
    // Moves focus down and scrolls up one page according to specified 
    // of bShift and bCtrl and navigation settings.
    virtual void NavigateKeyPageDown(CGrid& grid, bool bShift, bool bCtrl);
    
    // Focuses the first line in fixed or scrollable context according to specified 
    // values of bShift and bCtrl and navigation settings.
    virtual void NavigateKeyHome(CGrid& grid, bool bShift, bool bCtrl);

    // Focuses the last line in fixed or scrollable context according to specified 
    // values of bShift and bCtrl and navigation settings.
    virtual void NavigateKeyEnd(CGrid& grid, bool bShift, bool bCtrl);

    // Collapses lines and moves focus up according to specified 
    // values of bShift and bCtrl and navigation settings.
    virtual void NavigateKeyLeft(CGrid& grid, bool bShift, bool bCtrl);

    // Expands lines and moves focus down according to specified 
    // values of bShift and bCtrl and navigation settings.
    virtual void NavigateKeyRight(CGrid& grid, bool bShift, bool bCtrl);

    /// Handles 'Escape' key pressing
    virtual void OnEscape(CGrid& grid);

    /// Handles 'Return' key pressing
    virtual void OnReturn(CGrid& grid);
    
    /// Handles 'Ctri+A' key pressing. Selects all contents of the grid
    virtual void OnSelectAll(CGrid& grid);

    /// Handles 'Ctri+C' key pressing. Copies selection to the clipboard
    virtual void OnCopySelection(CGrid& grid);

    /// Handles 'Ctri+X' key pressing. Cuts selection to the clipboard
    virtual void OnCutSelection(CGrid& grid);

    /// Handles 'Ctri+V' key pressing. Copies clipboard content to the grid.
    virtual void OnPasteSelection(CGrid& grid);

    // IAutoDelete implementation
    virtual bool AutoDelete() const;

protected:
    bool m_AutoDelete;

private:
    //Prevent from copy
    CKeyManager(const CKeyManager&);
    CKeyManager operator = (const CKeyManager&);
};


}//namespace GUI

}//namespace Dapfor


