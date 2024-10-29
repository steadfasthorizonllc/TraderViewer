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

#include <Dapfor/GUI/Types.h>
#include <Dapfor/GUI/IEditInPlace.h>

namespace Dapfor
{

//Forward declarations
namespace Common
{
    class CFormat;
    class CDataObject;
}


namespace GUI
{

class CGrid;
class CColumn;
class CGridCell;
class CPaintContext;

//////////////////////////////////////////////////////////////////////////
/// \brief IControlReflector interface.
///
/// \version <b>2.0.0</b> Initial version
///
/// \class  IControlReflector IControlReflector.h Dapfor/GUI/IControlReflector.h
/// \file IControlReflector.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API IControlReflector
{
public:
    virtual ~IControlReflector();   //!< Virtual destructor

    /// Indicates whether a reflector can show a data object field via the specified format in an appropriated MFC control.
    virtual bool  Match(const Common::CFormat* format) const = 0;
    
    /// Creates and fills appropriate MFC control, and attaches it to a cell in CGrid
    virtual bool  CreateAndAttachControl(CEditInPlaceContext& context, const Common::CFormat* format, IEditInPlace::StartReason startReason) = 0;
    
    /// Shows the control
    virtual void  ShowControl() = 0;

    /// Indicates whether CGrid can stop edit in place in the control
    virtual bool  CanStopEdit(const CEditInPlaceContext& context, IEditInPlace::StopReason reason) const = 0;   
    
    /// Applies the new value set by user in MFC control to the specified field in the data object.
    virtual bool  Apply(CEditInPlaceContext& context, const Common::CFormat* format) = 0;
    
    /// Detaches MFC control from CGrid and destroys it.
    virtual bool  DetachAndDestroyControl(CGrid& grid, HITEM  hItem, const CColumn* column) = 0;
    
    /// Indicates that a control should be painted in CGrid painting routine. 
    virtual bool  CanDrawControl(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) = 0;
    
    /// Paints a reflector in CGrid painting routine before the cell is pained.
    virtual UINT  PrePaintCell(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) const;

    /// Paints a reflector in CGrid painting routine after the cell is pained.
    virtual void  PostPaintCell(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) = 0;

    /// Indicates whether MFC control can be activated if the user clicks inside of a cell.
    virtual bool  CanActivateOnThumbClick(const CEditInPlaceContext& context, const Common::CFormat* format) const = 0;    
    
    /// Gets underlying MFC control
    virtual CWnd* GetControl() = 0;
};


}//namespace GUI

}//namespace Dapfor
