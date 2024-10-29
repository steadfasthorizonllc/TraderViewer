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
/// \brief Performs edit in place operations on bool-type fields.
///
/// The reflector doesn't create underlying MFC control, but simulates checkbox behavior by 
/// painting an appropriate control in CGrid cell.
///
/// \version <b>2.0.0</b> Initial version
///
/// \class  CCheckBoxReflector CheckBoxReflector.h Dapfor/GUI/CheckBoxReflector.h
/// \file CheckBoxReflector.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CCheckBoxReflector : public IControlReflector
{
public:
    //Checkbox styles
    enum Alignement
    {
        LeftFromText,           //!< Paints the checkbox to the left and a text to the right of the cell
        RightFromText,          //!< Paints the checkbox to the right and a text to the left of the cell
        DisableText,            //!< Paints the checkbox at the center of the cell.

        DefaultStyle = LeftFromText,
    };

public:
    CCheckBoxReflector(Alignement style = DefaultStyle); //!< Constructor
    virtual ~CCheckBoxReflector();                  //!< Virtual destructor

    /// Indicates whether a reflector matches to the specified format.
    virtual bool  Match(const Common::CFormat* format) const;
    
    /// Creates nothing. Stop previous edit in place if it can. Always returns true.
    virtual bool  CreateAndAttachControl(CEditInPlaceContext& context, const Common::CFormat* format, IEditInPlace::StartReason startReason);

    // Shows the control
    virtual void  ShowControl();
    
    /// Does nothing. Always returns true.
    virtual bool  CanStopEdit(const CEditInPlaceContext& context, IEditInPlace::StopReason reason) const;
    
    /// Applies the new value, set by the user to the specified field in the data object.
    virtual bool  Apply(CEditInPlaceContext& context, const Common::CFormat* format);
    
    /// Does nothing. Always returns true.
    virtual bool  DetachAndDestroyControl(CGrid& grid, HITEM  hItem, const CColumn* column);
    
    ///Indicates that the control should be painted in CGrid painting routine. 
    virtual bool  CanDrawControl(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);
    
    /// Performs check box drawing after the cell is painted.
    virtual void  PostPaintCell(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);
    
    /// The function modifies the paintFilter to prevent from text drawing in the cell painting procedure. 
    virtual UINT PrePaintCell(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) const;

    /// Indicates that the control can be activated if the user clicks inside of the cell. 
    virtual bool  CanActivateOnThumbClick(const CEditInPlaceContext& context, const Common::CFormat* format) const;

    /// Reflector doesn't have an MFC control and always returns zero.
    virtual CWnd* GetControl();

private:
    Alignement m_Style;
};


}//namespace GUI

}//namespace Dapfor
