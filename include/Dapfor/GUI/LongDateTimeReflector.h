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

#include <Dapfor/GUI/IControlReflector.h>

namespace Dapfor
{
namespace GUI
{

//////////////////////////////////////////////////////////////////////////
/// \brief Performs edit in place operations on long-type fields in CEmbeddedDateTimeCtrl control.
///
/// \version <b>2.0.0</b> Initial version
///
/// \class  CLongDateTimeReflector LongDateTimeReflector.h Dapfor/GUI/LongDateTimeReflector.h
/// \file LongDateTimeReflector.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CLongDateTimeReflector : public IControlReflector
{
public:
    CLongDateTimeReflector();           //!< Constructor
    virtual ~CLongDateTimeReflector();  //!< Virtual destructor

    /// Indicates whether a reflector matches to a specified format.
    virtual bool  Match(const Common::CFormat* format) const;
    
    /// Creates datetime MFC control
    virtual bool  CreateAndAttachControl(CEditInPlaceContext& context, const Common::CFormat* format, IEditInPlace::StartReason startReason);

    // Shows the control
    virtual void  ShowControl();

    // Indicates whether CGrid can stop edit in place operation in the control
    virtual bool  CanStopEdit(const CEditInPlaceContext& context, IEditInPlace::StopReason reason) const;

    // Applies the new value set by the user in MFC control to the specified field in a data object.
    virtual bool  Apply(CEditInPlaceContext& context, const Common::CFormat* format);
    
    // Detaches MFC control from CGrid and destroys it.
    virtual bool  DetachAndDestroyControl(CGrid& grid, HITEM  hItem, const CColumn* column);
    
    // Indicates that a control should be painted in CGrid painting routine. 
    virtual bool  CanDrawControl(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);

    /// Paints dropdown or spin buttons to the right of a cell
    virtual void  PostPaintCell(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);

    /// Indicates that an MFC control can be activated if the user clicks on a dropdown or spin button painted in the cell.
    virtual bool  CanActivateOnThumbClick(const CEditInPlaceContext& context, const Common::CFormat* format) const;

    /// Gets datetime MFC control.
    virtual CWnd* GetControl();
private:
    struct Impl;
    Impl*  m_Impl;
};


}

}//namespace Dapfor
