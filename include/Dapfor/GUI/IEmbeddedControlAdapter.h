/////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2007-2010 Dapfor
//                                                                         
// This file is part of the Dapfor software, and may only be used, modified, and distributed 
// under the terms of the Dapfor LICENSE AGREEMENT FOR MFC GRID SOFTWARE.
// (See accompanying file lisense.txt or open the license at http://www.dapfor.com/license_agreement_v2.aspx)
// By continuing to use, modify, or distribute this file you indicate that you have read the license 
// and fully understand and accept it.
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __GUI_I_EMBEDDED_CONTROL_ADAPTER__H
#define __GUI_I_EMBEDDED_CONTROL_ADAPTER__H

#include <Dapfor/GUI/GUI_Export.h>
#include <Dapfor/GUI/IAutoDelete.h>

namespace Dapfor
{
namespace GUI
{

class  CGridCell;
class  CPaintContext;
struct CEmbeddedControlParams;

class DF_GUI_API IEmbeddedControlAdapter : public IAutoDelete
{
public:
    struct ISink
    {
        virtual ~ISink() {}

        virtual void OnEmbeddedControlMessage(IEmbeddedControlAdapter* adapter, UINT uMsg, WPARAM wParam, LPARAM lParam) {};
    };

public:
    virtual ~IEmbeddedControlAdapter() {};

    virtual void  MoveControl(const CRect& cellRect) = 0;
    virtual CWnd* GetControl() const = 0;
    virtual bool  PaintControl(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) = 0;
    
    //Moves the control outside of the parent's client area
    virtual void  MoveAway() = 0; 

    //Hides the control when the row is collapsed or filtered
    virtual void  HideControl() = 0;

    //Shows the control
    virtual void  ShowControl() = 0;

    //Gets current settings 
    virtual const CEmbeddedControlParams& GetParams() const = 0;
        


    virtual void AddSink(ISink* sink) = 0;
    virtual void RemoveSink(ISink* sink) = 0;
};

}//namespace GUI

}//namespace Dapfor

#endif//__GUI_I_EMBEDDED_CONTROL_ADAPTER__H
