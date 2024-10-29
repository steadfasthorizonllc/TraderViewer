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

#include <Dapfor/GUI/CellPaintFormat.h>

namespace Dapfor
{
namespace GUI
{

//////////////////////////////////////////////////////////////////////////
///\brief Draws a progress bar for numeric-type fields. 
/// 
/// The format can be applied to fields of the following types: char, unsigned char, short, unsigned short,
/// long, unsigned long, __int64.
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  CProgressCellPaintFormat ProgressCellPaintFormat.h Dapfor/GUI/ProgressCellPaintFormat.h
/// \file ProgressCellPaintFormat.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CProgressCellPaintFormat : public CCellPaintFormat
{
public:
    ///Constructor
    CProgressCellPaintFormat(COLORREF color, long lower = 0, long upper = 100);

    ///Draws a cell
    virtual void DrawCell(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) const;

protected:
    ///Draws a scroll bar
    virtual void OnDrawText(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);

private:
    COLORREF m_Color;
    long m_Lower;
    long m_Upper;
};



}//namespace GUI

}//namespace Dapfor
