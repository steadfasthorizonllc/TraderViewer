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
//////////////////////////////////////////////////////////////////////////
//Forward declarations
namespace GUI
{

class ICustomDraw;
class ILinePaintFormat;
class ICellPaintFormat;
class IHeaderPaintFormat;
class IColumnPaintFormat;
class IDragDrop;
class ICopyPaste;

class IHeaderItemPaintFormat;
class IEditInPlace;
class IKeyManager;
class ITooltipCtrl;
class CAppearance;

//////////////////////////////////////////////////////////////////////////
/// \brief Provides preferences of GUI library and default implementations of various interfaces
///
/// \version <b>2.0.0</b> Initial version
///
/// \class  CPreferences GuiPreferences.h Dapfor/GUI/GuiPreferences.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CPreferences
{
public:
    ///Threading mode
    enum ThreadingMode
    {
        /// Common::CDataObject is protected by critical sections or mutexes.
        DirectCall,     
        
        /// CGrid copies all data in the calling thread and doesn't call Common::CDataObject functions anymore
        MemoryBuffer,   
    };

public:
    /// Gets a current threading mode
    static ThreadingMode        GetThreadingMode();             
    
    /// Sets a new threading mode
    static void                 SetThreadingMode(ThreadingMode threadingMode); 

    /// Gets the default font used in grids
    static CFont*               GetFont();                      
    
    /// Sets a default font to be used in grids
    static void                 SetFont(CFont* font);           

    /// Gets the default appearance used in grids
    static CAppearance&         GetDefaultAppearance();         
    
    /// Sets a new appearance to be used in grids
    static void                 SetDefaultAppearance(CAppearance& appearance);  

    //Default interfaces

    static ICustomDraw&         GetDefaultCustomDraw();           //!< Gets a default implementation of ICustomDraw interface
    static ILinePaintFormat&    GetDefaultLinePaintFormat();      //!< Gets a default implementation of ILinePaintFormat interface
    static ICellPaintFormat&    GetDefaultCellPaintFormat();      //!< Gets a default implementation of ICellPaintFormat interface
    static IHeaderPaintFormat&  GetDefaultHeaderPaintFormat();    //!< Gets a default implementation of IHeaderPaintFormat interface
    static IColumnPaintFormat&  GetDefaultColumnPaintFormat();    //!< Gets a default implementation of IColumnPaintFormat interface
    static IDragDrop&           GetDefaultDragDrop();             //!< Gets a default implementation of IDragDrop interface
    static ICopyPaste&          GetDefaultCopyPaste();            //!< Gets a default implementation of ICopyPaste interface
    static IEditInPlace&        GetDefaultEditInPlace();          //!< Gets a default implementation of IEditInPlace interface
    static IKeyManager&         GetDefaultKeyManager();           //!< Gets a default implementation of IKeyManager interface
    static ITooltipCtrl*        CreateDefaultTooltipCtrl();       //!< Gets a default implementation of ITooltipCtrl interface for tooltips
    static ITooltipCtrl*        CreateDefaultInPlaceTooltipCtrl();//!< Gets a default implementation of ITooltipCtrl interface for 'in place' tooltips

private:
    CPreferences();

private:
    struct CPreferencesImpl;
    friend CPreferencesImpl;
};

}

}//namespace Dapfor

