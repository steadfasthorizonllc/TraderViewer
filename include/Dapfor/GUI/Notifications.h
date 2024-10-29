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
#include <Dapfor/GUI/IEditInPlace.h>

namespace Dapfor
{
namespace GUI
{
class CGrid;
class CHeader;
class CColumn;
class CDragSource;
class CDropTarget;

namespace Notifications
{

/*! \page Notifications Notifications

The grid can inform its owners about some events, 
such as addition of a new line, selection or focus changes, etc. The given information 
is sent in form of WM_NOTIFY message, where one of the structures containing the detailed information 
about an event is stored in the lParam.  
For improving grid productivity it is possible to block event sending by calling 
CGrid::AllowNotifications() function.

List of available notifications:
 - NM_GRIDITEM
 - NM_GRIDDRAGDROP
 - NM_GRIDEDIT
 - NM_GRIDCOLUMN
 - NM_GRIDSORT

The following example demonstrates how to get notications from the grid

1. You have a class that contains the GGrid object

\code
//File SomeDialog.h

using namespace Dapfor;
class CSomeDialog : public CDialog
{
...
protected:
    afx_msg void OnSelectionChanged(NMHDR*, LRESULT*);
    afx_msg void OnExpansionChanged(NMHDR*, LRESULT*);

private:
    GUI::CGrid m_Grid;
}; 


  
//File SomeDialog.cpp
BEGIN_MESSAGE_MAP(CSomeDialog, CDialog)
    ...
    ON_NOTIFY(Dapfor::GUI::Notifications::SelectionChanged, IDC_CUSTOM1, OnSelectionChanged)
    ON_NOTIFY(Dapfor::GUI::Notifications::ExpansionChanged, IDC_CUSTOM1, OnExpansionChanged)
END_MESSAGE_MAP()

void CSomeDialog::OnSelectionChanged(NMHDR* hdr, LRESULT* lresult)
{
    Dapfor::GUI::NM_GRIDITEM* item = (Dapfor::GUI::NM_GRIDITEM*)hdr;
    //Your implementation...
}
  
void CSomeDialog::OnExpansionChanged(NMHDR* hdr, LRESULT* lresult)
{
    Dapfor::GUI::NM_GRIDITEM* item = (Dapfor::GUI::NM_GRIDITEM*)hdr;
    //Your implementation...
}

\endcode

2. If you have your own control that derives from the grid, you can use the following:

\code

//File CustomGrid.h
#include <Dapfor/GUI/Grid.h>

class CCustomGrid : public Dapfor::GUI::CGrid
{
protected:
    afx_msg void OnLButtonDown(UINT flags, CPoint point);
    afx_msg void OnExpansionChanged(NMHDR*, LRESULT*);

    DECLARE_MESSAGE_MAP()
};


//File CustomGrid.cpp
#include <Dapfor/GUI/Notifications.h>

BEGIN_MESSAGE_MAP(CCustomGrid, Dapfor::GUI::CGrid)
    ON_WM_LBUTTONDOWN()
    ON_NOTIFY_REFLECT(Dapfor::GUI::Notifications::ExpansionChanged, OnExpansionChanged)
END_MESSAGE_MAP()

void CCustomGrid::OnLButtonDown(UINT flags, CPoint point)
{
    //Don't forget to call the method of the base class
    CGrid::OnLButtonDown(flags, point);
}
  
void CCustomGrid::OnExpansionChanged(NMHDR* hdr, LRESULT* lresult)
{
    Dapfor::GUI::NM_GRIDITEM* item = (Dapfor::GUI::NM_GRIDITEM*)hdr;
    ...
} 

\endcode

*/



/// Notification type
enum NotificationType
{
    AddItem,            //!< A new item has been added to the grid. Notification structure: NM_GRIDITEM
    RemoveItem,         //!< An item has been removed from the grid. Notification structure: NM_GRIDITEM
    MoveItem,           //!< An item has been displaced in the grid. Notification structure: NM_GRIDITEM
    AttachItem,         //!< An unattached item has been attached to the grid. Notification structure: NM_GRIDITEM
    DetachItem,         //!< An item has been detached from the grid. Notification structure: NM_GRIDITEM

    FocusChanged,       //!< A new item is focused in the grid (or focus was removed). Notification structure: NM_GRIDITEM
    SelectionChanged,   //!< Selection has been changed. Notification structure: NM_GRIDITEM
    ExpansionChanged,   //!< An item has been expanded or collapsed. Notification structure: NM_GRIDITEM
    FilterChanged,      //!< After item updating it became filtered or vice versa. Notification structure: NM_GRIDITEM
    VisibilityChanged,  //!< After item updating or collapsing/expanding the item changed its visibility. Notification structure: NM_GRIDITEM 
    UpdateItem,         //!< The item was updated by ISink interface or by the CGrid::Update(...) call. Notification structure: NM_GRIDITEM
    
    BeginDrag,          //!< Start of the drag & drop. Notification structure: NM_GRIDDRAGDROP
    EndDrag,            //!< End of the the drag & drop. Notification structure: NM_GRIDDRAGDROP
    BeginDrop,          //!< Start of the dropping data from the clipboard. Notification structure: NM_GRIDDRAGDROP 
    EndDrop,            //!< End of the dropping data from the clipboard. Notification structure: NM_GRIDDRAGDROP 
    BeginEdit,          //!< Start of edit in place. Notification structure: NM_GRIDEDIT
    EndEdit,            //!< End of edit in place. Notification structure: NM_GRIDEDIT
    
    AddColumn,          //!< A new column has been added. Notification structure NM_GRIDCOLUMN
    RemoveColumn,       //!< A column has been removed. Notification structure NM_GRIDCOLUMN
    MoveColumn,         //!< A column in the header has been displaced. Notification structure NM_GRIDCOLUMN
    ResizeColumn,       //!< A column in the header has been resized. Notification structure NM_GRIDCOLUMN
    UpdateColumn,       //!< Any parameter of the column has been changed. Notification structure NM_GRIDCOLUMN

    SortChanged,        //!< Sorting has been modified. Notification structure NM_GRIDSORT
};

/// Item states
enum ItemState
{
    ItemSelected        = 0x01, //!< The item is selected
    ItemFocused         = 0x02, //!< The item is focused
    ItemVisible         = 0x04, //!< The item is visible (not filtered and not hidden by its parents)
    ItemExpanded        = 0x08, //!< The item is expanded
    ItemFiltered        = 0x10, //!< The item is filtered
    ItemAttached        = 0x20, //!< The item is actually attached to the grid
};

enum ColumnState
{
    ColumnVisible       = 0x01, //!< The column is visible
    ColumnFixed         = 0x02, //!< The column is fixed
    ColumnSorted        = 0x04, //!< The column has sorting
};

}//namespace Notifications

///\brief Sent by the grid to notify its parent window about item updating.
///This notification is sent in form of WM_NOTIFY message. 
struct DF_GUI_API NM_GRIDITEM { 
    NMHDR                           hdr;        //!< NMHDR structure that contains information about this notification message. 
    Notifications::NotificationType type;       //!< Notification type
    CGrid*                          grid;       //!< The grid that sends this notification
    UINT                            state;      //!< Combination of GUI::Notifications::ItemState enumeration
    HITEM                           item;       //!< Handle in the grid
    Common::CDataObject*       pDO;        //!< The data object, associated with a handle
    ContextType                     context;    //!< The grid context to which a handle is related
    int                             row;        //!< Index of a line in the context
};

///\brief Sent by the grid to notify its parent window about drag & drop processing.
///This notification is sent in form of WM_NOTIFY message. 
struct DF_GUI_API NM_GRIDDRAGDROP { 
    NMHDR                           hdr;        //!< NMHDR structure that contains information about this notification message. 
    Notifications::NotificationType type;       //!< Notification type
    CGrid*                          grid;       //!< The grid that sends this notification
    CDragSource*                    dragSource; //!< Source of a content
    CDropTarget*                    dropTarget; //!< Location where a clipboard content is to be dropped
    DROPEFFECT                      effect;     //!< Drop effect. One of the next values: DROPEFFECT_COPY, DROPEFFECT_MOVE, DROPEFFECT_LINK, DROPEFFECT_NONE
};



///\brief Sent by the grid to notify its parent window about edit in place processing.
///This notification is sent in form of WM_NOTIFY message. 
struct DF_GUI_API NM_GRIDEDIT { 
    NMHDR                           hdr;        //!< NMHDR structure that contains information about this notification message. 
    Notifications::NotificationType type;       //!< Notification type
    CGrid*                          grid;       //!< The grid that sends this notification
    HITEM                           item;       //!< Handle in the grid
    Common::CDataObject*       pDO;        //!< The data object, associated with a handle
    ContextType                     context;    //!< The grid context to which a handle is related
    int                             row;        //!< Index of a line in the context
    CColumn*                        column;     //!< A column
    CWnd*                           control;    //!< Edit in place control if it exists
    IEditInPlace::StartReason       startReason;//!< Edit in place start reason
    IEditInPlace::StopReason        stopReason; //!< Edit in place stop reason
};



///\brief Sent by the grid to notify its parent window about column changing.
///This notification is sent in form of WM_NOTIFY message. 
struct DF_GUI_API NM_GRIDCOLUMN { 
    NMHDR                           hdr;    //!< NMHDR structure that contains information about this notification message. 
    Notifications::NotificationType type;   //!< Notification type
    CGrid*                          grid;   //!< The grid that sends this notification
    CHeader*                        header; //!< Grid header
    UINT                            state;  //!< Combination of GUI::Notifications::ColumnState enumeration
    CColumn*                        column; //!< The column where it is appropriate
};


///\brief Sent by the grid to notify its parent window about sorting changing.
///This notification is sent in form of WM_NOTIFY message. 
struct DF_GUI_API NM_GRIDSORT { 
    NMHDR                           hdr;    //!< NMHDR structure that contains information about this notification message. 
    Notifications::NotificationType type;   //!< Notification type
    CGrid*                          grid;   //!< The grid which sent this notification
    CHeader*                        header; //!< Grid header
};



}//namespace GUI

}//namespace Dapfor

