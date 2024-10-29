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
/// \brief Edit in place settings.
///
/// \version <b>2.0.0</b> Initial version
///
/// \class  CEditInPlaceSettings EditInPlaceSettings.h Dapfor/GUI/EditInPlaceSettings.h
/// \file EditInPlaceSettings.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CEditInPlaceSettings
{
public:
    /// Action type that begins edit in place in a cell
    enum ActivationType
    {
        mouseClick,         //!< Starts edit in place when the user clicks on a cell.
        mouseDblClick,      //!< Starts edit in place when the user double clicks on a cell.

        defaultActivation = mouseDblClick,
    };

public:
    CEditInPlaceSettings(); //!< Constructor
    
    
    inline bool           IsEnabled() const;                     //!< Indicates whether edit in place is enabled.
    inline ActivationType GetActivationType() const;             //!< Gets an activation type.
    inline bool           CanActivateOnThumbClick() const;       //!< Indicates, whether CGrid can start edit in place in a cell on the control thumb click
    inline bool           CanDrawHotFrame() const;               //!< Indicates that CGrid can draw a frame around a hot editable cell
    inline bool           CanDrawHotThumb() const;               //!< Indicates that CGrid can draw a specified picture in a hot editable cell.
    inline bool           CanDrawThumbsAlways() const;           //!< Indicates that CGrid can draw control-specified pictures for all editable controls.
    inline COLORREF       GetFrameColor()   const;               //!< Gets a frame color.
    inline bool           CanUseNavigation() const;              //!< Indicates whether CGrid can use navigation between editable controls.

    inline void           SetEnabled(bool bEnable);              //!< Enables edit in place
    inline void           SetActivationType(ActivationType type);//!< Sets a new activation type
    inline void           SetActivateOnThumbClick(bool bCan);    //!< Enables activation when the user clicks on the control thumb.
    inline void           SetDrawHotFrame(bool bCan);            //!< Enables drawing a frame around a hot cell.
    inline void           SetDrawHotThumb(bool bCan);            //!< Enables drawing control-specified thumbs.
    inline void           SetDrawThumbsAlways(bool bCan);        //!< Enables drawing control-specified thumbs in each editable cell.
    inline void           SetFrameColor(COLORREF color);         //!< Sets a frame color
    inline void           SetUseNavigation(bool bUse);           //!< Enables to navigate between editable controls.

    static int GetSerializeVertion();                            //!< Gets a serialization version
    void       Serialize(CArchive& ar);                          //!< Serializes/deserializes data to/from the archive.

protected:
    bool            m_Enable;
    ActivationType  m_ActivationType;
    bool            m_ActivateOnThumbClick;
    COLORREF        m_FrameColor;
    bool            m_DrawHotFrame;
    bool            m_DrawHotThumb;
    bool            m_DrawThumbsAlways;
    bool            m_UseNavigation;
};


inline bool     CEditInPlaceSettings::IsEnabled()   const               {return m_Enable;}
inline CEditInPlaceSettings::ActivationType CEditInPlaceSettings::GetActivationType() const {return m_ActivationType;}
inline bool     CEditInPlaceSettings::CanActivateOnThumbClick() const   {return m_ActivateOnThumbClick;}
inline bool     CEditInPlaceSettings::CanDrawHotFrame() const           {return m_DrawHotFrame;}
inline bool     CEditInPlaceSettings::CanDrawHotThumb() const           {return m_DrawHotThumb;}
inline bool     CEditInPlaceSettings::CanDrawThumbsAlways() const       {return m_DrawThumbsAlways;}
inline COLORREF CEditInPlaceSettings::GetFrameColor()   const           {return m_FrameColor;}
inline bool     CEditInPlaceSettings::CanUseNavigation() const          {return m_UseNavigation;}

inline void CEditInPlaceSettings::SetEnabled(bool bEnable)              {m_Enable = bEnable;}
inline void CEditInPlaceSettings::SetActivationType(ActivationType type){m_ActivationType = type;}
inline void CEditInPlaceSettings::SetActivateOnThumbClick(bool bCan)    {m_ActivateOnThumbClick = bCan;}
inline void CEditInPlaceSettings::SetDrawHotFrame(bool bCan)            {m_DrawHotFrame = bCan;}
inline void CEditInPlaceSettings::SetDrawHotThumb(bool bCan)            {m_DrawHotThumb = bCan;}
inline void CEditInPlaceSettings::SetDrawThumbsAlways(bool bCan)        {m_DrawThumbsAlways = bCan;}
inline void CEditInPlaceSettings::SetFrameColor(COLORREF color)         {m_FrameColor = color;}
inline void CEditInPlaceSettings::SetUseNavigation(bool bUse)           {m_UseNavigation = bUse;}



}//namespace GUI

}//namespace Dapfor


