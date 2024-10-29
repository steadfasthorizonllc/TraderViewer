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
#include <Dapfor/GUI/ColorBlend.h>

namespace Dapfor
{
namespace GUI
{

////////////////////////////////////////////////////////////////////////////////////////
/// \brief The object of this class stores color preferences of the grid and permits to 
///        serialize/deserialize them to/from the archive.
///
/// \class CAppearance Appearance.h <Dapfor/GUI/Appearance.h>
///
/// \file Appearance.h
////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CAppearance
{
public: 
    CAppearance();                                                  //!< Constructor
    CAppearance(const CAppearance& appearance);                     //!< Copy constructor


    inline COLORREF             GetTextEvenColor() const;           //!< Gets even text color
    inline COLORREF             GetTextOddColor() const;            //!< Gets odd text color
    inline COLORREF             GetBackEvenColor() const;           //!< Gets even background color
    inline COLORREF             GetBackOddColor() const;            //!< Gets odd background color
    inline COLORREF             GetVerticalLinesColor() const;      //!< Gets color of vertical lines
    inline COLORREF             GetHorizontalLinesColor() const;    //!< Gets color of horizontal lines
    inline const CColorBlend    GetSelectedLineColor() const;       //!< Gets selected line color which is blended with background color
    inline const CColorBlend    GetFocusedLineColor() const;        //!< Gets focused line color which is blended with background color
    inline const CColorBlend    GetSortedColumnColor() const;       //!< Gets sorted column color which is blended with background color
    inline const CColorBlend    GetMouseSelectionColor() const;     //!< Gets color of the rectangle selected by the mouse which is blended with background color
    inline bool                 IsVerticalLinesEnabled() const;     //!< Indicates whether the grid can draw vertical lines between columns
    inline bool                 IsHorizontalLinesEnabled() const;   //!< Indicates whether the grid can draw horizontal lines between rows


    inline void         SetTextEvenColor(COLORREF color);           //!< Sets even text color
    inline void         SetTextOddColor(COLORREF color);            //!< Sets odd text color
    inline void         SetBackEvenColor(COLORREF color);           //!< Sets even background color
    inline void         SetBackOddColor(COLORREF color);            //!< Sets odd background color
    inline void         SetVerticalLinesColor(COLORREF color);      //!< Sets color of vertical lines
    inline void         SetHorizontalLinesColor(COLORREF color);    //!< Sets color of horizontal lines
    inline void         SetSelectedLineColor(CColorBlend color);    //!< Sets a new color for the selected line which is blended with background color
    inline void         SetFocusedLineColor(CColorBlend color);     //!< Sets a new color for the focused line which is blended with background color
    inline void         SetSortedColumnColor(CColorBlend color);    //!< Sets a new color for the sorted column which is blended with background color
    inline void         SetMouseSelectionColor(CColorBlend color);  //!< Sets a new color of the rectangle selected by the mouse which is blended with background color
    inline void         EnableVerticalLines(bool bEnable);          //!< Enables to draw vertical lines between columns
    inline void         EnableHorizontalLines(bool bEnable);        //!< Enables to draw horizontal lines between rows


    static int GetSerializeVertion();                               //!< Gets current serialization version
    void       Serialize(CArchive& ar);                             //!< Serializes/Deserializes data to/from the archive


private:
    COLORREF            m_TextEvenColor;
    COLORREF            m_TextOddColor;
    COLORREF            m_BackEvenColor;
    COLORREF            m_BackOddColor;
    COLORREF            m_VerticalLinesColor;
    COLORREF            m_HorizontalLinesColor;
    CColorBlend         m_SelectedLineColor;
    CColorBlend         m_FocusedLineColor;
    CColorBlend         m_SortedColumnColor;
    CColorBlend         m_MouseSelectionColor;

    bool                m_EnableVerticalLines;
    bool                m_EnableHorizontalLines;
};

inline COLORREF          CAppearance::GetTextEvenColor() const {return m_TextEvenColor;}
inline COLORREF          CAppearance::GetTextOddColor() const {return m_TextOddColor;}
inline COLORREF          CAppearance::GetBackEvenColor() const {return m_BackEvenColor;}
inline COLORREF          CAppearance::GetBackOddColor() const {return m_BackOddColor;}
inline COLORREF          CAppearance::GetVerticalLinesColor() const {return m_VerticalLinesColor;}
inline COLORREF          CAppearance::GetHorizontalLinesColor() const {return m_HorizontalLinesColor;}
inline const CColorBlend CAppearance::GetSelectedLineColor() const {return m_SelectedLineColor;}
inline const CColorBlend CAppearance::GetFocusedLineColor() const {return m_FocusedLineColor;}
inline const CColorBlend CAppearance::GetSortedColumnColor() const {return m_SortedColumnColor;}
inline const CColorBlend CAppearance::GetMouseSelectionColor() const {return m_MouseSelectionColor;}
inline bool              CAppearance::IsVerticalLinesEnabled() const {return m_EnableVerticalLines;}
inline bool              CAppearance::IsHorizontalLinesEnabled() const {return m_EnableHorizontalLines;}


inline void         CAppearance::SetTextEvenColor(COLORREF color) {m_TextEvenColor = color;}
inline void         CAppearance::SetTextOddColor(COLORREF color) {m_TextOddColor = color;}
inline void         CAppearance::SetBackEvenColor(COLORREF color) {m_BackEvenColor = color;}
inline void         CAppearance::SetBackOddColor(COLORREF color) {m_BackOddColor = color;}
inline void         CAppearance::SetVerticalLinesColor(COLORREF color) {m_VerticalLinesColor = color;}
inline void         CAppearance::SetHorizontalLinesColor(COLORREF color) {m_HorizontalLinesColor = color;}
inline void         CAppearance::SetSelectedLineColor(CColorBlend color) {m_SelectedLineColor = color;}
inline void         CAppearance::SetFocusedLineColor(CColorBlend color) {m_FocusedLineColor = color;}
inline void         CAppearance::SetSortedColumnColor(CColorBlend color) {m_SortedColumnColor = color;}
inline void         CAppearance::SetMouseSelectionColor(CColorBlend color) {m_MouseSelectionColor = color;}
inline void         CAppearance::EnableVerticalLines(bool    bEnable) {m_EnableVerticalLines = bEnable;}
inline void         CAppearance::EnableHorizontalLines(bool bEnable) {m_EnableHorizontalLines = bEnable;}



} //namespace GUI

}//namespace Dapfor

