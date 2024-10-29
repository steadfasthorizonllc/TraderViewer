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
#include <Dapfor/GUI/HighlightSettings.h>

namespace Dapfor
{
namespace GUI
{

//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Contains painting information like colors, font, bounds, text adjustment.
///
/// \version <b>1.0.0.0</b> Initial version
/// 
/// \class  CPaintInfo PaintInfo.h Dapfor/GUI/PaintInfo.h
/// \file PaintInfo.h
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CPaintInfo
{
public:
    // Constructors
    CPaintInfo();   
    CPaintInfo(const CPaintInfo&          PaintInfo);   
    CPaintInfo(COLORREF                   foreColor,
                COLORREF                  backColor,
                CRect                     visibleRect,
                CRect                     virtualRect,
                CRect                     clipRect,
                CFont*                    font,
                int                       leftTextOffset,
                int                       rightTextOffset,
                const CHighlightSettings& settings);

    inline COLORREF     GetForeColor() const;       //!< Gets foreground color
    inline COLORREF     GetBackColor() const;       //!< Gets background color
    inline const CRect& GetVisibleRect() const;     //!< Gets a visible rectangle
    inline const CRect& GetVirtualRect() const;     //!< Gets a virtual rectangle
    inline const CRect& GetClipRect() const;        //!< Gets a clipped rectangle
    inline CFont*       GetFont() const;            //!< Gets a font
    inline int          GetLeftTextOffset() const;  //!< Gets an offset from the left of a virtual rectangle to paint a text
    inline int          GetRightTextOffset() const; //!< Gets an offset from the right of a virtual rectangle to paint a text
    inline const CHighlightSettings& GetHighlightSettings() const; //!< Gets highlight settings

    inline void SetForeColor(COLORREF color);       //!< Sets new foreground color
    inline void SetBackColor(COLORREF color);       //!< Sets new background color
    inline void SetVisibleRect(const CRect& rc);    //!< Sets a new visible rectangle
    inline void SetVirtualRect(const CRect& rc);    //!< Sets a new virtual rectangle
    inline void SetClipRect(const CRect& rc);       //!< Sets a new clipped rectangle
    inline void SetFont(CFont* font);               //!< Sets a new font
    inline void SetLeftTextOffset(int offset);      //!< Sets a new offset to the left of a virtual rectangle to paint a text
    inline void SetRightTextOffset(int offset);     //!< Sets a new offset to the right of a virtual rectangle to paint a text
    inline void SetHighlightSettings(const CHighlightSettings& settings); //!< Sets new highlight settings

private:
    COLORREF            m_ForeColor;
    COLORREF            m_BackColor;
    CRect               m_VisibleRect;
    CRect               m_VirtualRect;
    CRect               m_ClipRect;
    CFont*              m_Font;
    int                 m_LeftTextOffset;
    int                 m_RightTextOffset;
    CHighlightSettings  m_HighlightSettings;
};

inline COLORREF     CPaintInfo::GetForeColor() const    {return m_ForeColor;}
inline COLORREF     CPaintInfo::GetBackColor() const    {return m_BackColor;}
inline const CRect& CPaintInfo::GetVisibleRect() const  {return m_VisibleRect;}
inline const CRect& CPaintInfo::GetVirtualRect() const  {return m_VirtualRect;}
inline const CRect& CPaintInfo::GetClipRect() const     {return m_ClipRect;}
inline CFont*       CPaintInfo::GetFont() const         {return m_Font;}
inline int          CPaintInfo::GetLeftTextOffset() const   {return m_LeftTextOffset;}
inline int          CPaintInfo::GetRightTextOffset() const  {return m_RightTextOffset;}
inline const CHighlightSettings& CPaintInfo::GetHighlightSettings() const{return m_HighlightSettings;}

inline void CPaintInfo::SetForeColor(COLORREF color)    {m_ForeColor = color;}
inline void CPaintInfo::SetBackColor(COLORREF color)    {m_BackColor = color;}
inline void CPaintInfo::SetVisibleRect(const CRect& rc) {m_VisibleRect = rc;}
inline void CPaintInfo::SetVirtualRect(const CRect& rc) {m_VirtualRect = rc;}
inline void CPaintInfo::SetClipRect(const CRect& rc)    {m_ClipRect = rc;}
inline void CPaintInfo::SetFont(CFont* font)            {m_Font = font;}
inline void CPaintInfo::SetLeftTextOffset(int offset)   {m_LeftTextOffset = offset;}
inline void CPaintInfo::SetRightTextOffset(int offset)  {m_RightTextOffset = offset;}
inline void CPaintInfo::SetHighlightSettings(const CHighlightSettings& settings) {m_HighlightSettings = settings;}


}//namespace GUI

}//namespace Dapfor

