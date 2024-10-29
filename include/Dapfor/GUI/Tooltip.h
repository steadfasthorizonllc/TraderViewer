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

#include <Dapfor/GUI/ITooltip.h>

namespace Dapfor
{
namespace GUI
{

//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dedault implementation of ITooltip
///
/// Returns formatted text of the data object returned by Common::CDataObject::GetFormattedString()
///
/// \version <b>1.0.0.0</b> Initial version
/// 
/// \class  CTooltip Tooltip.h Dapfor/GUI/Tooltip.h
/// \file Tooltip.h
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CTooltip : public ITooltip
{
public:
    ///Constructor
    CTooltip(bool autoDelete);

    // Indicates whether the tooltip can be shown over a given cell.
    bool CanShow(const CGrid& grid, const CGridCell& cell) const;
    
    // Gets a text to display it in the tooltip.
    TString GetText(const CGrid& grid, const CGridCell& cell) const;

    /// IAutoDelete implementation. Returns the value, passed in the constructor.
    virtual bool AutoDelete() const;

private:
    bool m_AutoDelete;
};

}

}//namespace Dapfor
