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

#include <Dapfor/GUI/Tooltip.h>

namespace Dapfor
{
namespace GUI
{


//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief ITooltip implementation that presents a cell's content as a html-formatted text
///
/// Formats text of the data object returned by Common::CDataObject::GetFormattedString() into html 
/// form and returns it.
///
/// \version <b>1.0.0.0</b> Initial version
/// 
/// \class  CHtmlTooltip HtmlTooltip.h Dapfor/GUI/HtmlTooltip.h
/// \file HtmlTooltip.h
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CHtmlTooltip : public CTooltip
{
public:
    ///Constructor
    CHtmlTooltip(bool autoDelete);

    // Gets text to display it in the tooltip.
    TString GetText(const CGrid& grid, const CGridCell& cell) const;
};

}

}//namespace Dapfor
