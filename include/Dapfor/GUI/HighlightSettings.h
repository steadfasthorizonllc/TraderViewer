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
/// \brief Highlighting related information
///
/// \version <b>1.0.0.0</b> Initial version
/// 
/// \Example:
/// \include grid.highlighting.example
///
/// \class CHighlightSettings HighlightSettings.h Dapfor/GUI/HighlightSettings.h
/// \file HighlightSettings.h
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CHighlightSettings
{
public:
    /// Highlight modes
    /// 
    enum Mode
    {
        InverseColor,           //!< Inverses background and foreground colors during a highlight period.
        ForeColor,              //!< Replaces text color in a cell with the specified foreground color during highlight period.
        BackColor,              //!< Replaces cell background with the specified background color during highlight period.
        ForeBackColor,          //!< Replaces text and background in a cell together with foreground and background colors during highlight period.
        AlphaBlendForeColor,    //!< Performs alpha blending of text in a cell with a specified foreground color during highlight period.
        AlphaBlendBackColor,    //!< Performs alpha blending of cell background with the specified background color during highlight period.
        AlphaBlendForeBackColor,//!< Performs alpha blending of text and background in a cell together with specified foreground and background colors during highlight period.
        FadingForeColor,        //!< Highlights text in a cell during highlight period with a fading effect.
        FadingBackColor,        //!< Highlights cell background during highlight period with a fading effect.
        FadingForeBackColor,    //!< Highlights text and background in a cell together during highlight period with a fading effect.
    };

public:
    //Constructors
    CHighlightSettings();       
    CHighlightSettings(const CHighlightSettings& settings);
    CHighlightSettings(int      highlightPeriod,
                     COLORREF   foreColor,
                     COLORREF   backColor,
                     BYTE       foreAlpha,
                     BYTE       backAlpha,
                     int        fadingSpan,
                     Mode       mode);


    inline int      GetHighlightPeriod() const; //!< Time interval in milliseconds during which a cell is highlighted.
    inline COLORREF GetForeColor()       const; //!< Gets the foreground color.
    inline COLORREF GetBackColor()       const; //!< Gets the background color.
    inline BYTE     GetForeAlpha()       const; //!< Alpha-blend coefficient for the foreground color
    inline BYTE     GetBackAlpha()       const; //!< Alpha-blend coefficient for the background color
    inline int      GetFadingSpan()      const; //!< Time interval between two color modifications to implement a fading effect. Has sense only for Fading mode.
    inline Mode     GetMode()            const; //!< Gets a highlight mode


    inline void     SetHighlightPeriod(int period); //!< Sets a new highlight period
    inline void     SetForeColor(COLORREF color);   //!< Sets a new foreground color
    inline void     SetBackColor(COLORREF color);   //!< Sets a new background color
    inline void     SetForeAlpha(BYTE alpha);       //!< Sets a new foreground alpha coefficient
    inline void     SetBackAlpha(BYTE alpha);       //!< Sets a new background alpha coefficient
    inline void     SetFadingSpan(int span);        //!< Sets a new time interval between two color modifications. Makes sense only for Fading mode.
    inline void     SetMode(Mode mode);             //!< Sets a new highlight mode


    static int GetSerializeVertion();               //!< Gets serialization version
    void       Serialize(CArchive& ar);             //!< Serializes/deserializes this object to/from the archive.

private:
    int         m_HighlightPeriod;
    COLORREF    m_ForeColor;
    COLORREF    m_BackColor;
    BYTE        m_ForeAlpha;
    BYTE        m_BackAlpha;
    int         m_FadingSpan;
    Mode        m_Mode;
};

inline int      CHighlightSettings::GetHighlightPeriod()        const {return m_HighlightPeriod;} 
inline COLORREF CHighlightSettings::GetForeColor()              const {return m_ForeColor;}
inline COLORREF CHighlightSettings::GetBackColor()              const {return m_BackColor;}
inline BYTE     CHighlightSettings::GetForeAlpha()              const {return m_ForeAlpha;}
inline BYTE     CHighlightSettings::GetBackAlpha()              const {return m_BackAlpha;}
inline int      CHighlightSettings::GetFadingSpan()             const {return m_FadingSpan;}
inline CHighlightSettings::Mode CHighlightSettings::GetMode()   const {return m_Mode;}


inline void     CHighlightSettings::SetHighlightPeriod(int period) {m_HighlightPeriod = period;}
inline void     CHighlightSettings::SetForeColor(COLORREF color)   {m_ForeColor = color;}
inline void     CHighlightSettings::SetBackColor(COLORREF color)   {m_BackColor = color;}
inline void     CHighlightSettings::SetForeAlpha(BYTE alpha)       {m_ForeAlpha = alpha;}
inline void     CHighlightSettings::SetBackAlpha(BYTE alpha)       {m_BackAlpha = alpha;}
inline void     CHighlightSettings::SetFadingSpan(int span)        {m_FadingSpan = span;}
inline void     CHighlightSettings::SetMode(Mode mode)             {m_Mode = mode;}



}//namespace GUI

}//namespace Dapfor
