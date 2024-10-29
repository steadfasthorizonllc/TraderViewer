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

namespace Dapfor
{
namespace GUI
{

class CColumn;
class CHeaderPaintInfo;

//////////////////////////////////////////////////////////////////////////
/// \brief Information for drawing a column. 
///
/// \class  CColumnPaintInfo ColumnPaintInfo.h Dapfor/GUI/ColumnPaintInfo.h
/// \file ColumnPaintInfo.h
//////////////////////////////////////////////////////////////////////////
class CColumnPaintInfo
{
public:
    ///State of a column
    enum State
    {
        Normal,     //!< Normal state
        Hot,        //!< Mouse is over the column
        Pressed,    //!< Left mouse button is pressed on the column
    };

public:
    ///Constructor
    CColumnPaintInfo(CHeaderPaintInfo& headerPaintInfo, 
                     const CColumn* column, 
                     CRect visibleRect, 
                     CRect virtualRect, 
                     State state,
                     CFont* font, 
                     int    imageIndex,
                     COLORREF textColor);

    inline const CHeaderPaintInfo&  GetHeaderPaintInfo() const; //!< Gets header-related information
    inline const CColumn*           GetColumn() const;          //!< Gets the column that the information is associated with
    inline State                    GetState() const;           //!< Gets a column state
    inline const CRect&             GetVisibleRect() const;     //!< Gets visible column bounds
    inline const CRect&             GetVirtualRect() const;     //!< Gets virtual column bounds
    inline CFont*                   GetFont() const;            //!< Gets the font that is used to draw a text in a column
    inline COLORREF                 GetTextColor() const;       //!< Gets text color


private:
    CHeaderPaintInfo&   m_HeaderPaintInfo;
    const CColumn*      m_Column;
    CRect               m_VisibleRect;
    CRect               m_VirtualRect;
    State               m_State;
    CFont*              m_Font;
    int                 m_ImageIndex;
    COLORREF            m_TextColor;
};


inline const CHeaderPaintInfo&  CColumnPaintInfo::GetHeaderPaintInfo() const {return m_HeaderPaintInfo;}
inline const CColumn*           CColumnPaintInfo::GetColumn() const          {return m_Column;}
inline CColumnPaintInfo::State  CColumnPaintInfo::GetState() const           {return m_State;}
inline const CRect&             CColumnPaintInfo::GetVisibleRect() const     {return m_VisibleRect;}
inline const CRect&             CColumnPaintInfo::GetVirtualRect() const     {return m_VirtualRect;}
inline CFont*                   CColumnPaintInfo::GetFont() const      {return m_Font;}
inline COLORREF                 CColumnPaintInfo::GetTextColor() const {return m_TextColor; }


}//namespace GUI

}//namespace Dapfor

