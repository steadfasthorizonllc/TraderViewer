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
/// \brief Performs edit in place operations with long-type fields in CNumericEdit control.
///
/// \version <b>2.0.0</b> Initial version
///
/// \class  CLongReflector LongReflector.h Dapfor/GUI/LongReflector.h
/// \file LongReflector.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CLongReflector : public IControlReflector
{
public:
    CLongReflector();               //!< Constructor
    virtual ~CLongReflector();      //!< Virtual destructor

    /// Indicates whether a reflector matches a specified format.
    virtual bool  Match(const Common::CFormat* format) const;
    
    /// Creates edit-type MFC control
    virtual bool  CreateAndAttachControl(CEditInPlaceContext& context, const Common::CFormat* format, IEditInPlace::StartReason startReason);

    // Shows the control
    virtual void  ShowControl();

    // Indicates whether CGrid can stop edit in place operation in the control
    virtual bool  CanStopEdit(const CEditInPlaceContext& context, IEditInPlace::StopReason reason) const;

    // Applies the new value set by the user in MFC control to the specified field in the data object.
    virtual bool  Apply(CEditInPlaceContext& context, const Common::CFormat* format);

    // Detaches MFC control from CGrid and destroys it.
    virtual bool  DetachAndDestroyControl(CGrid& grid, HITEM  hItem, const CColumn* column);
    
    /// The function always returns false. 
    virtual bool  CanDrawControl(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);

    /// Paints nothing.
    virtual void  PostPaintCell(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);

    /// The function always returns false. 
    virtual bool  CanActivateOnThumbClick(const CEditInPlaceContext& context, const Common::CFormat* format) const;

    /// Gets MFC control of CNumericEdit type.
    virtual CWnd* GetControl();

private:
    struct Impl;
    Impl*  m_Impl;
};


}

}//namespace Dapfor
