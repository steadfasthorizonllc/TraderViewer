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

namespace Dapfor
{
namespace GUI
{

//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Color picker control
///
/// \version <b>1.0.0.0</b> Initial version
/// 
/// \class  CColorPicker ColorPicker.h Dapfor/GUI/ColorPicker.h
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CColorPicker : public CButton
{
    typedef CButton BaseClass;

public:
    enum
    {
        CPN_COLORCHANGE = WM_USER + 1001,   // Color change notification, LPARAM contains a new color, WPARAM - control id
    };

public:
    CColorPicker();
    virtual ~CColorPicker();

    COLORREF GetCurrentColor() const;
    void     SetCurrentColor(COLORREF color);
    void     ExpandColorPalette();
    bool     IsColorPaletteExpanded() const;
	void     ClosePalette();


protected:
    virtual void PreSubclassWindow();
    virtual void DrawItem(LPDRAWITEMSTRUCT ds);

    afx_msg BOOL    OnClick();
    afx_msg LRESULT OnPopupClick(WPARAM wp, LPARAM lp);
    afx_msg void    OnKillFocus(CWnd * pNewWnd);
    afx_msg void    OnDestroy();
private:
    struct CImpl;
    CImpl* m_Impl;

    DECLARE_MESSAGE_MAP();
};


}//namespace GUI

}//namespace Dapfor
