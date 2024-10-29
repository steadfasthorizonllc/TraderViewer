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
#include <Dapfor/GUI/TooltipCtrl.h>

namespace Dapfor
{
namespace GUI
{

//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Implements the tooltip that is displayed over the cell with partially 
///     visible text.
///
/// It uses the same font and text alignement as in the cell.
///
/// \version <b>1.0.0.0</b> Initial version
/// 
/// \class  CInPlaceTooltipCtrl InPlaceTooltipCtrl.h Dapfor/GUI/InPlaceTooltipCtrl.h
/// \file InPlaceTooltipCtrl.h
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CInPlaceTooltipCtrl : public CTooltipCtrl
{
public:
    ///Constructor
    CInPlaceTooltipCtrl(bool autoDelete);

    // Attaches a tooltip window to the grid
    virtual bool    Activate(const CGrid& grid, CGridCell& cell);

    // Gets the text returned by ITooltip interface
    virtual CString GetCurrentText() const;
    
    // Gets size requested by the tooltip to display text without restrictions.
    virtual CSize   GetSize(const CGrid& grid, const CGridCell& cell) const;

protected:
    //{{AFX_MSG(CInPlaceTooltipCtrl)
    afx_msg void OnPaint();
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()
private:
    CString m_Text;
};


}//namespace GUI

}//namespace Dapfor
