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
/// \brief Implements an html browser as a window to display the tooltip
///
/// \version <b>1.0.0.0</b> Initial version
/// 
/// \class  CHtmlTooltipCtrl HtmlTooltipCtrl.h Dapfor/GUI/HtmlTooltipCtrl.h
/// \file HtmlTooltipCtrl.h
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CHtmlTooltipCtrl : public CTooltipCtrl
{
public:
    ///Constructor
    CHtmlTooltipCtrl(CSize size, bool autoDelete);
    
    ///Destructor
    ~CHtmlTooltipCtrl();

    // Attaches a tooltip window to the grid
    virtual bool    Attach(CGrid& grid);

    // Detaches a tooltip window from the grid
    virtual void    Detach();

    // Makes a tooltip window visible
    virtual bool    Activate(const CGrid& grid, CGridCell& cell);

    // Gets the text returned by ITooltip interface
    virtual CString GetCurrentText() const;

    /// Gets size of the html window passed in the constructor
    virtual CSize   GetSize(const CGrid& grid, const CGridCell& cell) const;

    /// Gets default implementation of ITooltip interface.
    virtual const ITooltip& GetDefaultToolip() const;

protected:
    //{{AFX_MSG(CHtmlTooltipCtrl)
    afx_msg void OnPaint();
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()
private:
    struct Impl;
    Impl* m_Impl;
};


}//namespace GUI

}//namespace Dapfor
