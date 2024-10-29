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
#include <Dapfor/GUI/IEditInPlace.h>
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
class IControlReflector;
class CEditInPlaceContext;
class CGrid;
class CColumn;


//////////////////////////////////////////////////////////////////////////
/// \brief Default implementation of IEditInPlace interface.
///
/// \version <b>2.0.0</b> Initial version
///
/// \class  CEditInPlace EditInPlace.h Dapfor/GUI/EditInPlace.h
/// \file EditInPlace.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CEditInPlace : public IEditInPlace
{
public:
    CEditInPlace(bool bAutoDelete = false);     //!< Constructor
    virtual ~CEditInPlace();                    //!< Virtual destructor

    // Indicates whether edit in place can be started in the specified cell with the given start reason.
    virtual bool  CanBeginEdit(const CEditInPlaceContext& context, StartReason startReason) const;
    
    // Starts edit in place. Handles control creation through IControlReflector interface. 
    // The best place to choose the appropriate reflector if default behavior doesn't conform to your needs.
    virtual bool  AttachControl(CEditInPlaceContext& context, StartReason startReason, const Common::CFormat* format);
    
    // Indicates whether edit in place can be stopped.
    virtual bool  CanStopEdit(const CEditInPlaceContext& context,  StopReason stopReason) const;
    
    // Stops edit in place. Detaches a control through IControlReflector interface.
    virtual bool  CanApply(StopReason reason) const;

    // Called at the beginning of edit in place. 
    virtual void  OnBeginEdit(const CEditInPlaceContext& context, CWnd* attachedControl);
    
    // Stops edit in place. Detaches the control through IControlReflector interface.
    virtual void  OnEndEdit(CEditInPlaceContext& context, StopReason stopReason, CWnd* detachedControl, const Common::CFormat* format);

    // Permits to choose the next control when a navigation event like Tab, KeyUp, KeyDown etc. occurs.
    virtual bool  Navigate(CEditInPlaceContext& context, StopReason stopReason);
    
    /// Forwards cell drawing of CGrid painting routine to an appropriate reflector before the cell is painted.
    virtual UINT  PrePaintCell(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);
    
    /// Forwards cell drawing of CGrid painting routine to an appropriate reflector after the cell is painted.
    virtual void  PostPaintCell(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);

    ///Looks for the reflector that matches the specified format.
    virtual IControlReflector* GetReflector(const CGrid& grid,
                                            HITEM hItem, 
                                            const Common::CDataObject* pDO, 
                                            const CColumn* column, 
                                            const Common::CFormat* format);
    
    ///IAutoDelete interface implementation. Indicates whether the object should be destroyed in the destructor of CGrid.
    virtual bool AutoDelete() const;

private:
    CEditInPlace(const CEditInPlace&);
    CEditInPlace& operator = (const CEditInPlace&);

    struct Impl;
    Impl*  m_Impl;

};


}//namespace GUI

}//namespace Dapfor

