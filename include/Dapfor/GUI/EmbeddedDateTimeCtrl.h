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
#include <vector>

namespace Dapfor
{
namespace GUI
{

//////////////////////////////////////////////////////////////////////////
/// \brief Datetime control that is optimized to work with date or time values.
///
/// \version <b>2.0.0</b> Initial version
///
/// \class  CEmbeddedDateTimeCtrl EmbeddedDateTimeCtrl.h Dapfor/GUI/EmbeddedDateTimeCtrl.h
/// \file EmbeddedDateTimeCtrl.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CEmbeddedDateTimeCtrl : public CWnd
{
    struct Impl;
public:
    ///Allowed formats
    enum Format
    {
        year        = 0x1,      //!< yyyy
        short_year  = 0x2,      //!< yy
        month       = 0x4,      //!< mm    1..12
        day         = 0x8,      //!< dd    1..31
        hour        = 0x10,     //!< hh    0..23
        minute      = 0x20,     //!< mm    0..59
        second      = 0x40,     //!< ss    0..59
        millisec    = 0x80,     //!< nnn   0..999

        //frequently used formats
        date                = day | month | year,       //!< dd/mm/yyyy
        short_date          = day | month | short_year, //!< dd/mm/yy
        time                = hour | minute | second,   //!< hh:mm:ss
    };

    ///Logical slot inside of the datetime control
    struct Slot
    {
        Slot(long value, long minValue, long maxValue, long size, Format format, const CString& separator);

        long    m_Size;         //!< Place holder to display digits in a slot (count of digits)
        long    m_MinValue;     //!< Min possible value
        long    m_MaxValue;     //!< Max possible value
        long    m_Value;        //!< Current value
        CString m_Separator;    //!< Separator after a slot
        Format  m_Format;       //!< Current format
    
    private:
        friend struct Impl;
        CString m_Text;         //Text which is displayed in the control
    };
    typedef std::vector<Slot> Slots;


public:
    CEmbeddedDateTimeCtrl(UINT format = short_date|time);   //!< Constructor
    virtual ~CEmbeddedDateTimeCtrl();                       //!< Virtual destructor

    
    void   AddSlot(const Slot& slot);               //!< Adds a new logical slot 
    Slots& GetSlots() const;                        //!< Gets a list of logical slots
    void   RemoveSlots();                           //!< Removes all slots

    
    void   SetFormat(UINT format);                  //!< Sets a new format

    bool   ValueUp();                               //!< Increments value in the selected slot
    bool   ValueDown();                             //!< Decrements value in the selected slot
    
    void   SelectLeft();                            //!< Selects the next slot in order. 
    void   SelectRight();                           //!< Selects the previous slot in order. 
    void   SetCurrentSelection(int newSelection);   //!< Selects a slot with the specified index
    int    GetCurrentSelection() const;             //!< Gets an index of the selected slot.

    
    void   ApplyCalendar();                         //!< Closes a child calendar window and sets the value received from the calendar to the date-time control.
    void   CloseCalendar();                         //!< Closes a child calendar window
    bool   HasCalendar() const;                     //!< Indicates whether this control has a child calendar window.

    CRect  GetSpinRect() const;                     //!< Gets bounds of the spin control (for time style).
    CRect  GetDropDownRect() const;                 //!< Gets bounds of the dropdown control (for date style).


    ///\brief Sets new time represented by 32-bit value that is the number of seconds elapsed
    /// since midnight, January 1, 1970.
    bool   SetDateTime(long dt);

    ///\brief Sets new time represented by 64-bit value that is the number of 100-nanosecond 
    /// intervals since January 1, 1601. 
    bool   SetDateTime(__int64 dt);
    
    
    long   GetDateTime() const;                     //!< Gets a time, represented by 32-bit value.
    bool   GetDateTime(__int64& dt) const;          //!< Gets a time, represented by 64-bit value.

protected:
    BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
    //{{AFX_VIRTUAL(CEmbeddedDateTimeCtrl)
    //}}AFX_VIRTUAL


    //{{AFX_MSG(CEmbeddedDateTimeCtrl)
    afx_msg int     OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void    OnDestroy();
    afx_msg void    OnPaint();
    afx_msg BOOL    OnEraseBkgnd(CDC* pDC);
    afx_msg void    OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void    OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void    OnLButtonDblClk(UINT nFlags, CPoint point);
    afx_msg void    OnRButtonDown(UINT nFlags, CPoint point);
    afx_msg void    OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void    OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg LRESULT OnSetFont(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnGetFont(WPARAM wParam, LPARAM lParam);
    afx_msg void    OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void    OnKillFocus(CWnd* pNewWnd);
    afx_msg void    OnSetFocus(CWnd* pOldWnd);
    afx_msg UINT    OnGetDlgCode();
    afx_msg void    OnTimer(DF_ON_TIMER_TYPE nIDEvent);
    afx_msg LRESULT OnControlMessage(WPARAM wParam, LPARAM lParam);
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()


private:
    Impl*  m_Impl;

};

}//namespace GUI

}//namespace Dapfor


