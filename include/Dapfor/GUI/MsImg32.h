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

class CImageList;

namespace Dapfor
{
namespace GUI
{

//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Helper class to perform image and color manipulations
///
/// \version <b>1.0.0.0</b> Initial version
/// 
/// \class  CMsImg32 MsImg32.h Dapfor/GUI/MsImg32.h
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CMsImg32
{
public:
    /// Blends two colors with a transparency coefficient
    static COLORREF  AlphaBlend(COLORREF sourceColor, COLORREF colorAlpha, unsigned char alpha);

    /// Displays bitmaps with transparent or semitransparent pixels.
    static bool AlphaBlend( CDC& dc, const CRect& rect, COLORREF color, BYTE alpha);

    /// Helps to load 32-bit color image from resources
    static bool Load32BitImage(CImageList& imageList, UINT resourceId, bool useMask, COLORREF maskColor);

    /// Indicates that alpha-blend & gradient services are available
    static bool IsAvailable();

    /// Fills rectangle and triangle structures.
    static BOOL GradientFill(HDC hdc,                   //!< handle to DC
                             PTRIVERTEX pVertex,        //!< array of vertices
                             ULONG dwNumVertex,         //!< number of vertices
                             PVOID pMesh,               //!< array of gradients
                             ULONG dwNumMesh,           //!< size of gradient array
                             ULONG dwMode               //!< gradient fill mode
                             ); 
    
    /// Displays the bitmaps that have transparent or semitransparent pixels.
    static BOOL AlphaBlend( HDC hdcDest,                 //!< handle to destination DC
                            int nXOriginDest,            //!< x-coord of upper-left corner
                            int nYOriginDest,            //!< y-coord of upper-left corner
                            int nWidthDest,              //!< destination width
                            int nHeightDest,             //!< destination height
                            HDC hdcSrc,                  //!< handle to source DC
                            int nXOriginSrc,             //!< x-coord of upper-left corner
                            int nYOriginSrc,             //!< y-coord of upper-left corner
                            int nWidthSrc,               //!< source width
                            int nHeightSrc,              //!< source height
                            BLENDFUNCTION blendFunction  //!< alpha-blending function
                            );


    ///\brief Performs a bit-block transfer of the color data corresponding to a rectangle of pixels from a 
    ///specified source device context into a destination device context.
    static BOOL TransparentBlt(HDC hdcDest,             //!< handle to destination DC
                               int xDest,               //!< x-coord of destination upper-left corner
                               int yDest,               //!< y-coord of destination upper-left corner
                               int nDestWidth,          //!< width of destination rectangle
                               int nDestHeight,         //!< height of destination rectangle
                               HDC hdcSrc,              //!< handle to source DC
                               int xSrc,                //!< x-coord of source upper-left corner
                               int ySrc,                //!< y-coord of source upper-left corner
                               int nSrcWidth,           //!< width of source rectangle
                               int nSrcHeight,          //!< height of source rectangle
                               UINT clrTransparent
                               );


private:
    struct Impl;
    friend Impl;
};

}//namespace GUI

}//namespace Dapfor

