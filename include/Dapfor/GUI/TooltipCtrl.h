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

#include <Dapfor/GUI/ITooltipCtrl.h>

namespace Dapfor
{
namespace GUI
{

//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Default implementation of ITooltipCtrl interface
///
/// \version <b>1.0.0.0</b> Initial version
/// 
/// \class  CTooltipCtrl TooltipCtrl.h Dapfor/GUI/TooltipCtrl.h
/// \file TooltipCtrl.h
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CTooltipCtrl : public CWnd
                              , public ITooltipCtrl
{
public:
    ///Constructor
    CTooltipCtrl(bool autoDelete);
    ///Virtual Destructor
    virtual ~CTooltipCtrl();

    // Attaches a tooltip window to the grid
    virtual bool    Attach(CGrid& grid);

    // Detaches a tooltip window from the grid
    virtual void    Detach();

    // Makes a tooltip window visible
    virtual bool    Activate(const CGrid& grid, CGridCell& cell);

    // Makes a tooltip window invisible
    virtual void    Desactivate();

    /// Gets the text returned by ITooltip interface
    virtual CString GetCurrentText() const;
    
    /// Gets the size requested by the tooltip to show a text without restriction.
    virtual CSize   GetSize(const CGrid& grid, const CGridCell& cell) const;

    /// Gets a default implementation of ITooltip interface.
    virtual const ITooltip& GetDefaultToolip() const;
    
    /// IAutoDelete implementation. Returns value passed in the constructor.
    virtual bool    AutoDelete() const;

protected:
    /// Gets the grid, to which the tooltip is attached
    const CGrid*    GetGrid() const;

    //{{AFX_MSG(CTooltipCtrl)
    afx_msg void OnPaint();
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg LRESULT OnSetFont(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnGetFont(WPARAM wParam, LPARAM lParam);
    afx_msg void OnDestroy();
    //}}AFX_MSG

private:
    DECLARE_MESSAGE_MAP()

private:
    CTooltipCtrl(CTooltipCtrl& ctrl);
    CTooltipCtrl& operator = (CTooltipCtrl& ctrl);

    struct Impl;
    Impl* m_Impl;
};


}

}//namespace Dapfor
