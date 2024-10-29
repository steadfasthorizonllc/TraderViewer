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

class CBitmap;

namespace Dapfor
{
namespace GUI
{

////////////////////////////////////////////////////////////////////////////////////////
/// \brief This class is destined to store a backgound image with information that determines
///        how is the image presented in the grid.
///
////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CBackgroundImage
{
public:
    ///Transformation mode
    enum Mode
    {
        Center,     //!< Bitmap is centered in the grid
        Stretch,    //!< Bitmap is fitted to the grid's size
        Scale,      //!< Bitmap is cloned in the grid

        Default = Stretch,
    };

public:
    CBackgroundImage();                 //!< constructor
    ~CBackgroundImage();                //!< destructor
    
    void     SetBitmap(CBitmap* image); //!< Sets a new bitmap  
    void     SetOpacity(BYTE opacity);  //!< Sets opacity value 
    void     SetMode(Mode mode);        //!< Sets transformation mode.

    CBitmap* GetBitmap() const;         //!< Gets the bitmap
    BYTE     GetOpacity() const;        //!< Gets opacity level.
    Mode     GetMode() const;           //!< Gets transformation mode

private:    
    CBitmap*    m_Image;
    BYTE        m_Opacity;              // 0..255; 0-opaque, 255-transparent
    Mode        m_Mode;
};



}//namespace GUI

}//namespace Dapfor

