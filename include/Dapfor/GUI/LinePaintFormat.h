/////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2007-2010 Dapfor
//                                                                         
// This file is part of the Dapfor software, and may only be used, modified, and distributed 
// under the terms of the Dapfor LICENSE AGREEMENT FOR MFC GRID SOFTWARE.
// (See accompanying file lisense.txt or open the license at http://www.dapfor.com/license_agreement_v2.aspx)
// By continuing to use, modify, or distribute this file you indicate that you have read the license 
// and fully understand and accept it.
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __GUI_GRID_LINE_PAINT_FORMAT__H
#define __GUI_GRID_LINE_PAINT_FORMAT__H

#include <Dapfor/GUI/ILinePaintFormat.h>

namespace Dapfor
{
namespace GUI
{

//////////////////////////////////////////////////////////////////////////
///\brief Default implementation of ILinePaintFormat interface.
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  CLinePaintFormat LinePaintFormat.h Dapfor/GUI/LinePaintFormat.h
/// \file LinePaintFormat.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CLinePaintFormat : public ILinePaintFormat
{
public:
    CLinePaintFormat();
    ~CLinePaintFormat();

    // Paints a line in CGrid.
    virtual void DrawLine(CGridLine& line, const CPaintContext& paintContext, UINT paintFilter, ICustomDraw* customDraw) const;

private:
    DF_DECLARE_LINE_PAINT_FORMAT();
};


}//namespace GUI

}//namespace Dapfor

#endif //__GUI_GRID_LINE_PAINT_FORMAT__H
