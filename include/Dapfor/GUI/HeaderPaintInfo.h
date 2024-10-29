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

class CImageList;

namespace Dapfor
{
namespace GUI
{

class CColumn;

//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Header related paint information
///
/// \version <b>1.0.0.0</b> Initial version
/// 
/// \class  CHeaderPaintInfo HeaderPaintInfo.h Dapfor/GUI/HeaderPaintInfo.h
/// \file HeaderPaintInfo.h
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CHeaderPaintInfo
{
public:
    /// indicates the position at which a column should be dropped.
    enum DropPosition
    {
        None,   //!< No column is actually dragged
        Begin,  //!< Dragged column should be dropped before the current column
        End,    //!< Dragged column should be dropped after the current column
    };

public:
    /// Constructor
    CHeaderPaintInfo(const CColumn* hotColumn, 
                     const CColumn* dropColumn, 
                     DropPosition   dropPosition,
                     bool mouseCaptured, 
                     CFont* font, 
                     CImageList* imageList,
                     COLORREF textColor);

    
    inline const CColumn* GetHotColumn() const;     //!< Gets the hot column i.e. the actual column over which the mouse cursor is located
    inline const CColumn* GetDropColumn() const;    //!< Gets the column that is actually dragging.
    inline DropPosition   GetDropPosition() const;  //!< Gets a position relative to the hot column where a dragged column should be inserted.
    inline bool           IsMouseCaptured() const;  //!< Specifies whether mouse is captured by the header.
    inline CFont*         GetFont() const;          //!< Gets the font used for drawing text.
    inline CImageList*    GetImageList() const;     //!< Gets an image list to draw icons in the header
    inline COLORREF       GetTextColor() const;     //!< Gets a text color

private:
    const CColumn*  m_HotColumn;
    const CColumn*  m_DropColumn;
    DropPosition    m_DropPosition;
    bool            m_MouseCaptured;
    CFont*          m_Font;
    CImageList*     m_ImageList;
    COLORREF        m_TextColor;
};

inline const CColumn* CHeaderPaintInfo::GetHotColumn() const {return m_HotColumn;}

inline const CColumn* CHeaderPaintInfo::GetDropColumn() const {return m_DropColumn;}

inline CHeaderPaintInfo::DropPosition CHeaderPaintInfo::GetDropPosition() const {return m_DropPosition;}

inline bool CHeaderPaintInfo::IsMouseCaptured() const {return m_MouseCaptured;}

inline CFont*   CHeaderPaintInfo::GetFont() const      {return m_Font;}

inline CImageList* CHeaderPaintInfo::GetImageList() const {return m_ImageList;}

inline COLORREF CHeaderPaintInfo::GetTextColor() const {return m_TextColor; }


}//namespace GUI

}//namespace Dapfor

