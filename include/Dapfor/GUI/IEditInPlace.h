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
#include <Dapfor/GUI/IAutoDelete.h>
#include <Dapfor/GUI/EditInPlaceContext.h>

namespace Dapfor
{

namespace Common
{
class CDataObject;
class CFormat;
}


namespace GUI
{
class CColumn;
class CGrid;
class CPaintContext;
class CGridCell;
class CEditInPlaceContext;
class CEmbeddedControlParams;


//////////////////////////////////////////////////////////////////////////
///\brief Manages all phases of edit in place process.
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  IEditInPlace IEditInPlace.h Dapfor/GUI/IEditInPlace.h
/// \file IEditInPlace.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API IEditInPlace : public IAutoDelete
{
public:
    ///Indicates the reason for the start of edit in place
    enum StartReason
    {
        ActivateOnMouseClick,       //!< The user clicks with the left mouse button on a cell
        ActivateOnMouseDblClick,    //!< The user double clicks with the left mouse button on a cell
        ActivateOnNavigation,       //!< Navigation between edit in place controls.
        ActivateOnUserStart,        //!< Other reasons
    };

    ///Indicates the reason for the stop of edit in place
    enum StopReason
    {
        Undefined,                  //!< Undefined cause
        KeyReturn,                  //!< Stop because 'Return' is pressed
        KeyEscape,                  //!< Stop because 'Escape' is pressed
        KeyUp,                      //!< Stop because 'Key up' is pressed. 
        KeyDown,                    //!< Stop because 'Key down' is pressed. 
        KeyLeft,                    //!< Stop because 'Key left' is pressed. 
        KeyRight,                   //!< Stop because 'Key right'is pressed. 
        KeyPageUp,                  //!< Stop because 'Page up' is pressed. 
        KeyPageDown,                //!< Stop because 'Page down' is pressed. 
        KeyHome,                    //!< Stop because 'Home' is pressed. 
        KeyEnd,                     //!< Stop because 'End' is pressed. 
        KeySpace,                   //!< Stop because 'Space' is pressed. 
        KeyTab,                     //!< Stop because 'Tab' is pressed. 
        KeyShiftTab,                //!< Stop because 'Shith + Tab' is pressed. 
        KeyCtrlTab,                 //!< Stop because 'Control + Tab' is pressed. 
        MouseWheelUp,               //!< Stop because 'Mouse wheel up' is rotated. 
        MouseWheelDown,             //!< Stop because 'Mouse wheel down' is rotated. 
        MouseRBDown,                //!< Stop because 'Mouse right button' is pressed down.
        MouseLBDown,                //!< Stop because 'Mouse left button' is pressed down. 
        MouseLBDblClick,            //!< Stop because 'Mouse right button' is double clicked. 
        MouseRBDblClick,            //!< Stop because 'Mouse left button' is double clicked. 

        //MFC control-specific events
        ComboSelEndOk,              //Occured when CComboBox sends CBN_SELENDOK notification
        ComboSelEndCancel,          //Occured when CComboBox sends CBN_SELENDCANCEL notification

        LostFocus,                  //!< Stop because the focus is lost
        UserStop                   //!< Other reasons
    };

    ///Determines the next cell which can participate in navigation
    struct NavigationTarget
    {
        HITEM hItem;            //!< a handle in CGrid
        const CColumn* column;  //!< a column
    };

public:
    virtual ~IEditInPlace(); //!< Virtual destructor

    /// Indicates whether edit in place can be started in a specified cell with a given start reason.
    virtual bool  CanBeginEdit(const CEditInPlaceContext& context, StartReason startReason) const = 0;

    /// Starts edit in place. Handles control creation through IControlReflector interface. 
    /// The best place to choose the appropriate reflector if default behavior doesn't conform to your needs.
    virtual bool  AttachControl(CEditInPlaceContext& context, StartReason startReason, const Common::CFormat* format) = 0;

    /// Indicates whether edit in place can be stopped.
    virtual bool  CanStopEdit(const CEditInPlaceContext& context,  StopReason stopReason) const = 0;

    /// Called at the beginning of edit in place. 
    virtual void  OnBeginEdit(const CEditInPlaceContext& context, CWnd* editControl) = 0;

    /// Stops edit in place. Detaches a control throught IControlReflector interface.
    virtual void  OnEndEdit(CEditInPlaceContext& context, StopReason stopReason, CWnd* detachedControl, const Common::CFormat* format) = 0;
    
    /// Allows to choose the next control upon a navigation event like Tab, KeyUp, KeyDown etc.
    virtual bool  Navigate(CEditInPlaceContext& context,           StopReason stopReason) = 0;

    /// Forwards cell drawing of CGrid painting routine to an appropriate reflector before the cell is pained.
    virtual UINT  PrePaintCell(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) = 0;

    /// Forwards cell drawing of CGrid painting routine to an appropriate reflector after the cell is pained.
    virtual void  PostPaintCell(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) = 0;
};

    

}//namespace GUI

}//namespace Dapfor


