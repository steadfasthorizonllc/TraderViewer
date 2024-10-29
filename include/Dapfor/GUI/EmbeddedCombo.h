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
#include <Dapfor/GUI/Types.h>

namespace Dapfor
{
namespace GUI
{

//////////////////////////////////////////////////////////////////////////
/// \brief Extension of CComboBox.
///
/// The main purpose of this class is to show a combo box in small bounds without 
/// any malfunction. The class keeps all functionality of the base class, but it performs 
/// special drawing for small comboboxes.
///
/// \version <b>2.0.0</b> Initial version
///
/// \class  CEmbeddedCombo EmbeddedCombo.h Dapfor/GUI/EmbeddedCombo.h
/// \file EmbeddedCombo.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CEmbeddedCombo : public CComboBox
{
public:
    typedef CComboBox BaseClass;

    CEmbeddedCombo();           //!< Constructor
    virtual ~CEmbeddedCombo();  //!< Virtual destructor

protected:
    //{{AFX_VIRTUAL(CEmbeddedCombo)
    LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
    //}}AFX_VIRTUAL

    //{{AFX_MSG(CEmbeddedCombo)
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnPaint();
    afx_msg void OnNcPaint();
    afx_msg BOOL OnSelchange();
    afx_msg void OnSetFocus(CWnd* pOldWnd);
    afx_msg void OnKillFocus(CWnd* pNewWnd);
    afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
    //}}AFX_MSG

private:
    DECLARE_MESSAGE_MAP()
    
    //Point implementation interface 
    struct Impl;
    Impl*  m_Impl;
};


}//namespace GUI

}//namespace Dapfor

