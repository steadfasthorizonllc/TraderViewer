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

class CHeader;

/////////////////////////////////////////////////////////////////////////////
/// \brief Handles visibility and location of columns in the header
///
/// It is intended for handling columns visibility and location in the grid using a dialog. 
/// The class can be used to replace columns, to display or withdraw them. As a parameter of the constructor, 
/// the class accepts an object of CHeader class into which then all changes are made in the case when the user 
/// confirms his choice pressing the button OK. If the header transferred into the constructor is used by the grid, 
/// the grid automatically updates its contents depending on the new values set in the header.
/// 
/// \class  CHeaderConfigurationDlg HeaderConfigurationDlg.h Dapfor/GUI/HeaderConfigurationDlg.h
/// \file HeaderConfigurationDlg.h
/////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CHeaderConfigurationDlg : public CDialog
{
public:
    //Control identifiers used by dialog
    enum ControlId
    {
        ID_OK       = 1000,
        ID_CANCEL,
        ID_TOP,
        ID_UP,
        ID_DOWN,
        ID_BOTTOM,
        ID_STATIC,
        ID_GRID,
        ID_SPIN_FIXED_COUNT,
        ID_FIXED_COUNT,
    };

public:
    CHeaderConfigurationDlg(CHeader& header, CWnd* pParent = NULL); //!< Constructor
    virtual ~CHeaderConfigurationDlg();                             //!< Destructor

    ///Configures the header in a modal window 
    virtual DF_DOMODAL_TYPE DoModal();

protected:
    //{{AFX_VIRTUAL(CHeaderConfigurationDlg)
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual void OnOK();
    virtual void OnCancel();
    //}}AFX_VIRTUAL

    //{{AFX_MSG(CHeaderConfigurationDlg)
    virtual BOOL OnInitDialog();
    afx_msg void OnBtnOK();
    afx_msg void OnBtnCancel();
    afx_msg void OnTop();
    afx_msg void OnUp();
    afx_msg void OnDown();
    afx_msg void OnBottom();
    afx_msg void OnSpinFixedCount(NMHDR* pNMHDR, LRESULT* pResult);
    //}}AFX_MSG

    //{{AFX_DATA(CHeaderConfigurationDlg)
    int     m_FixedCount;
    //}}AFX_DATA
    
    DECLARE_MESSAGE_MAP()

private:
    struct Impl;
    Impl* m_Impl;

};

}//namespace GUI

}//namespace Dapfor
