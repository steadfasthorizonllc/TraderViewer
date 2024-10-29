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

#include <Dapfor/GUI/IHeaderPaintFormat.h>

namespace Dapfor
{
namespace GUI
{

//////////////////////////////////////////////////////////////////////////
///\brief Default implementation of IHeaderPaintFormat interface.
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  CHeaderPaintFormat HeaderPaintFormat.h Dapfor/GUI/HeaderPaintFormat.h
/// \file HeaderPaintFormat.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CHeaderPaintFormat : public IHeaderPaintFormat
{
public:
    CHeaderPaintFormat();   //!< Constructor
    ~CHeaderPaintFormat();  //!< Destructor

    // Draws a header in CGrid.
    virtual void DrawHeader(CHeaderPaintInfo& paintInfo, const CPaintContext& paintContext, UINT paintFilter, ICustomDraw* customDraw) const;

private:
    DF_DECLARE_HEADER_PAINT_FORMAT();
};

}//namespace GUI

}//namespace Dapfor

