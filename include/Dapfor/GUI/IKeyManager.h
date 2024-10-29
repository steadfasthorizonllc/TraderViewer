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
#include <Dapfor/GUI/IAutoDelete.h>

namespace Dapfor
{
namespace GUI
{
class CGrid;

//////////////////////////////////////////////////////////////////////////
///\brief Interface to perform some actions (copy, paste, navigation, etc.) in the grid in response 
// to key pressing.
///
/// Navigation handling and reaction on keystrokes are processed by the grid in a separate module. 
/// Grid behavior can be completely redefined in IKeyManager interface. GUI library provides a default implementation
/// of this interface. The programmer can create his own implementation inheriting from CKeyManager or IKeyManager. 
/// The grid provides CGrid::SetKeyManager() function that enables setting of a new manager. When the manager 
/// is not set, the grid  uses the default implementation returned by CPreferences::GetDefaultKeyManager().
///
/// \class  IKeyManager IKeyManager.h Dapfor/GUI/IKeyManager.h
/// \file IKeyManager.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API IKeyManager : virtual public IAutoDelete 
{
public:
    /// Called when a non-system key is pressed
    virtual BOOL OnKeyDown(CGrid& grid, UINT nChar, UINT nRepCnt, UINT nFlags) = 0;
    
    /// Called when a non-system key is released
    virtual BOOL OnKeyUp(CGrid& grid, UINT nChar, UINT nRepCnt, UINT nFlags) = 0;

    ///\brief Moves the focus up and scrolls down one line according to specified 
    ///  values of bShift and bCtrl and navigation settings
    virtual void NavigateKeyUp(CGrid& grid, bool bShift, bool bCtrl) = 0;

    ///\brief Moves the focus down and scrolls up one line according to specified 
    ///  values of bShift and bCtrl and navigation settings
    virtual void NavigateKeyDown(CGrid& grid, bool bShift, bool bCtrl) = 0;

    ///\brief Moves the focus up and scrolls down one page according to specified 
    ///  values of bShift and bCtrl and navigation settings
    virtual void NavigateKeyPageUp(CGrid& grid, bool bShift, bool bCtrl) = 0;

    ///\brief Moves the focus down and scrolls up one page according to specified 
    ///  values of bShift and bCtrl and navigation settings.
    virtual void NavigateKeyPageDown(CGrid& grid, bool bShift, bool bCtrl) = 0;

    ///\brief Focuses the first line in the fixed or scrollable context according to specified 
    ///  values of bShift and bCtrl and navigation settings.
    virtual void NavigateKeyHome(CGrid& grid, bool bShift, bool bCtrl) = 0;

    ///\brief Focuses the last line in the fixed or scrollable context according to specified 
    ///  values of bShift and bCtrl and navigation settings.
    virtual void NavigateKeyEnd(CGrid& grid, bool bShift, bool bCtrl) = 0;
    
    ///\brief Collapses lines and Moves the focus up according to specified 
    ///  values of bShift and bCtrl and navigation settings.
    virtual void NavigateKeyLeft(CGrid& grid, bool bShift, bool bCtrl) = 0;

    ///\brief Expands lines and Moves the focus down according to specified 
    ///  values of bShift and bCtrl and navigation settings.
    virtual void NavigateKeyRight(CGrid& grid, bool bShift, bool bCtrl) = 0;
};


}//namespace GUI

}//namespace Dapfor

