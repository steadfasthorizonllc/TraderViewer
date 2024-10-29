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
namespace Common
{
class CDataObject;
}

namespace GUI
{

class CColumn ;
class CGrid;
class CGridCell;

//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Interface determining a content of the tooltip
///
/// The interface determines content that is displayed in the tooltip window. GUI library presents two implementations 
/// CTooltip and CHtmlTooltip representing information in form of text or text with html tags. 
/// When the grid displays information in the tooltip window, it first searches for the implementation established 
/// by the CGrid::SetTooltip() function. If the programmer has not set his tooltip implementation, 
/// the grid tries to get default ITooltip interface by calling ITooltipCtrl::GetDefaultToolip().
/// 
/// \class  ITooltip ITooltip.h Dapfor/GUI/ITooltip.h
/// \file ITooltip.h
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API ITooltip : public IAutoDelete
{
public:
    ///Indicates whether the tooltip can be shown at a given cell.
    virtual bool CanShow(const CGrid& grid, const CGridCell& cell) const = 0;
    
    ///Gets text to display it in the tooltip.
    virtual TString GetText(const CGrid& grid, const CGridCell& cell) const = 0;
};

}

}//namespace Dapfor
