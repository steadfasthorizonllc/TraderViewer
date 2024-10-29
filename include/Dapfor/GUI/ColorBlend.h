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
///\brief Contains color information and its transparency level. Used in alpha-blend operations.
///
/// \class  CColorBlend ColorBlend.h Dapfor/GUI/ColorBlend.h
/// \file ColorBlend.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CColorBlend
{
public:
    CColorBlend();                                              //!< Default constructor 
    CColorBlend(const CColorBlend& colorBlend);                 //!< Copy constructor
    CColorBlend(COLORREF color, unsigned char opacity);         //!< Constructor

    inline COLORREF         GetColor() const;                   //!< Gets the color used in alpha-blend operations
    inline unsigned char    GetOpacity() const;                 //!< Gets opacity level. 0-transparent, 255-opaque
    inline void             SetColor(COLORREF color);           //!< Sets a new color 
    inline void             SetOpacity(unsigned char opacity);  //!< Sets a new opacity level. 0-transparent, 255-opaque

    static int GetSerializeVertion();                           //!< Current serialization version
    void       Serialize(CArchive& ar);                         //!< Serializes the object to/from the archive

private:
    COLORREF        m_Color;        // Color that is used in the alpha-blend operation
    unsigned char   m_Opacity;      // 0..255; 0-transparent, 255-opaque
};

inline COLORREF      CColorBlend::GetColor() const                  {return m_Color;}
inline unsigned char CColorBlend::GetOpacity() const                {return m_Opacity;}
inline void          CColorBlend::SetColor(COLORREF color)          {m_Color = color;}
inline void          CColorBlend::SetOpacity(unsigned char opacity) {m_Opacity = opacity;}

}

}//namespace Dapfor


