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
#include <Dapfor/GUI/GUI_Export.h>
#include <Dapfor/GUI/IAutoDelete.h>

namespace Dapfor
{
namespace GUI
{
class CGrid;
class CGridCell;
class ITooltip;

//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Interface to handle tooltip location in the grid
///
/// It is used for handling the tooltip window, its location and visibility. 
/// The grid supports two types of tooltips. The first is a usual window that appears above grid cell 
/// if the cursor does not move for a certain time interval and disappears upon a certain time interval, 
/// set in the grid parameters. The second type is a built-in window, appearing above 
/// a cell when the cell is so small that text information doesn't fit in it. 
/// In this case the grid shows this window precisely above the cell and displays all
/// cell text inside it, applying the same font, size, text alignment as in
/// the cell. GUI library has some implementations of  ITooltipCtrl interface. CTooltipCtrl 
/// and CTooltip classes display text information in a window. CHtmlTooltipCtrl and CHtmlTooltip implementations 
/// display a cell content in the Internet browser in the form of a html text. CInPlaceTooltipCtrl implementation
/// displays partially visible text above a cell. It is also possible to implement arbitrary tooltips, 
/// representing information by means of MFC coltrols, or by means of the same grid.
/// 
/// \class  ITooltipCtrl ITooltipCtrl.h Dapfor/GUI/ITooltipCtrl.h
/// \file ITooltipCtrl.h
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API ITooltipCtrl : virtual public IAutoDelete
{
public:
    ///Virtual destructor
    virtual ~ITooltipCtrl();    

    ///Attaches a tooltip window to the grid
    virtual bool Attach(CGrid& grid) = 0;

    ///Detaches a tooltip window from the grid
    virtual void Detach() = 0;

    ///Makes a tooltip window visible
    virtual bool Activate(const CGrid& grid, CGridCell& cell) = 0;

    ///Makes a tooltip window invisible
    virtual void Desactivate() = 0;

    ///Gets default ITooltip implementation to display a grid's content
    virtual const ITooltip& GetDefaultToolip() const = 0;
};

} //namespace GUI

}//namespace Dapfor
