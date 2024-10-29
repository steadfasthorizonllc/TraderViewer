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
#include <Dapfor/GUI/DropPosition.h>


class CImageList;
class CBitmap;

namespace Dapfor
{
namespace GUI
{

class CGrid;
class CHeader;

//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Paint-related information
///
/// \version <b>1.0.0.0</b> Initial version
/// 
/// \class  CPaintContext PaintContext.h Dapfor/GUI/PaintContext.h
/// \file PaintContext.h
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CPaintContext
{
public:
    /// Constructor
    CPaintContext(const CGrid&          grid,
                  const CHeader*        header,
                  const CRect&          clipRect,
                  CDC&                  dc,
                  const CDropPosition&  dropPosition,
                  const CRect&          mouseSelection,
                  ContextType           focusedContext,
                  int                   focusedRow,
                  CImageList*           imageList,
                  bool                  stretchImage,
                  CBitmap*              backgroundImage,
                  const CRect&          backgroundImageRc
                 );
    CPaintContext(const CPaintContext& paintContext);    //!< Copy constructor


    inline const CGrid&     GetGrid() const;             //!< Gets a reference to the grid
    inline const CHeader*   GetHeader() const;           //!< Gets a header
    inline const CRect&     GetClipRect() const;         //!< Gets the clipped rectangle, extracted from CDC
    inline CDC&             GetDC() const;               //!< Gets device context
    const  CDropPosition&   GetDropPosition() const;     //!< Gets a drop position
    inline const CRect&     GetMouseSelection() const;   //!< Gets a mouse selection
    inline ContextType      GetFocusedContext() const;   //!< Gets CGrid context which holds a focus.
    inline int              GetFocusedRow() const;       //!< Gets a focused row in focused context
    inline CImageList*      GetImageList() const;        //!< Gets a default image list to draw icons in cells of CGrid
    inline bool             GetStretchImage() const;     //!< Indicates whether icons in cells should be stretched.
    inline CBitmap*         GetBackgroundImage() const;  //!< Gets a background image
    inline const CRect&     GetBackgroundImageRc() const;//!< Gets bounds of a background image


private:
    const CGrid&            m_Grid;
    const CHeader*          m_Header;
    CRect                   m_ClipRect;
    CDC&                    m_DC;
    CDropPosition           m_DropPosition;
    CRect                   m_MouseSelection;
    ContextType             m_FocusedContext;
    int                     m_FocusedRow;
    CImageList*             m_ImageList;
    bool                    m_StretchImage;
    CBitmap*                m_BackgroundImage;
    CRect                   m_BackgroundImageRc;
};


inline const CGrid&     CPaintContext::GetGrid() const                  {return m_Grid;}
inline const CHeader*   CPaintContext::GetHeader() const                {return m_Header;}
inline const CRect&     CPaintContext::GetClipRect() const              {return m_ClipRect;}
inline CDC&             CPaintContext::GetDC() const                    {return m_DC;}
inline const CDropPosition&  CPaintContext::GetDropPosition() const     {return m_DropPosition;}
inline const CRect&     CPaintContext::GetMouseSelection() const        {return m_MouseSelection;}
inline ContextType      CPaintContext::GetFocusedContext() const        {return m_FocusedContext;}
inline int              CPaintContext::GetFocusedRow() const            {return m_FocusedRow;}
inline CImageList*      CPaintContext::GetImageList() const             {return m_ImageList;}
inline bool             CPaintContext::GetStretchImage() const          {return m_StretchImage;}
inline CBitmap*         CPaintContext::GetBackgroundImage() const       {return m_BackgroundImage;}
inline const CRect&     CPaintContext::GetBackgroundImageRc() const     {return m_BackgroundImageRc;}


}//namespace GUI

}//namespace Dapfor

