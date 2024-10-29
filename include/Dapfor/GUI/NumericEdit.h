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

//////////////////////////////////////////////////////////////////////////
/// \brief Edit control that is optimized to work with numeric values.
///
/// \version <b>2.0.0</b> Initial version
///
/// \class  CNumericEdit NumericEdit.h Dapfor/GUI/NumericEdit.h
/// \file NumericEdit.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CNumericEdit : public CEdit
{
public:

    /// Mask, that restricts the user's input.
    enum Type
    {
        String,     //!< All possible characters
        Decimal,    //!< 0..9
        Hex,        //!< 0..9, a..f, A..F, x, X
        Char,       //!< One symbol
        Float,      //!< 0..9, e, d, E, D, ".,+-"
        Time,       //!< 0..9, ':'
        MsecTime,   //!< 0..9, ":.,"

        Default = String,
    };

public:
    CNumericEdit(Type type);    //!< Constructor

protected:
    //{{AFX_MSG(CNumericEdit)
    afx_msg BOOL    OnEnUpdate();
    afx_msg void    OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void    OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()
    DECLARE_DYNAMIC(CNumericEdit)
private:
    int         m_Selection;
    CString     m_Text;
    Type        m_Type;
};


}//namespace GUI

}//namespace Dapfor

