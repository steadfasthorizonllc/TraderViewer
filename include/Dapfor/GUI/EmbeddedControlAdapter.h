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

namespace Dapfor
{
namespace GUI
{

class CEmbeddedControlParams;
class CGridCell;
class CPaintContext;

//////////////////////////////////////////////////////////////////////////
/// \brief Enables attachment of almost any MFC control to CGrid.
///
/// An object of this class enables communication between CGrid and MFC control. 
/// It forwards some notifications from the control to the grid i.e. focus lost, control destruction, etc.
/// On the other hand, the grid can manage visibility, placement the control over the client area and paint 
/// via an adapter in the control.
///
/// \version <b>2.0.0</b> Initial version
///
/// \class  CEmbeddedControlAdapter EmbeddedControlAdapter.h Dapfor/GUI/EmbeddedControlAdapter.h
/// \file EmbeddedControlAdapter.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CEmbeddedControlAdapter
{
public:
    ///Callback interface to receive notifications from MFC control.
    struct DF_GUI_API ISink
    {
        ///Virtual destructor
        virtual ~ISink();

        ///Callback function that is called when MFC control receives a window message.
        virtual void OnEmbeddedControlMessage(CEmbeddedControlAdapter* adapter, UINT uMsg, WPARAM wParam, LPARAM lParam) {};
    };

public:
    /// Constructor
    CEmbeddedControlAdapter(CWnd* pWnd, const CEmbeddedControlParams& params);
    
    /// Virtual destructor
    virtual ~CEmbeddedControlAdapter();                                         

    /// Moves MFC control over the client area of the grid
    virtual void  MoveControl(const CRect& cellRect);
    
    /// Gets MFC control
    virtual CWnd* GetControl() const;                                           
    
    /// Paints MFC control
    virtual bool  PaintControl(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);   
    
    /// Moves MFC control outside of the client area without changing its visibility
    virtual void  MoveAway();                                
    
    /// Makes the control invisible
    virtual void  HideControl();                             
    
    /// Makes the control visible
    virtual void  ShowControl();

    /// Adds a callback interface to receive notifications from MFC control
    virtual void AddSink(ISink* sink);                       
    
    /// Removes a callback interface from the subscription list
    virtual void RemoveSink(ISink* sink);                    

    /// Gets current settings
    virtual const CEmbeddedControlParams& GetParams() const; 

    /// IAutoDelete implementation. Returns true.
    virtual bool AutoDelete() const;                         

private:
    //Point implementation interface
    struct CImpl;
    CImpl* m_Impl;
};


}//namespace GUI

}//namespace Dapfor


