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

#include <Dapfor/GUI/ICellPaintFormat.h>

namespace Dapfor
{
namespace GUI
{

//////////////////////////////////////////////////////////////////////////
///\brief Default implementation of ICellPaintFormat interface. Performs painting of a cell in CGrid.
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  CCellPaintFormat CellPaintFormat.h Dapfor/GUI/CellPaintFormat.h
/// \file CellPaintFormat.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CCellPaintFormat : public ICellPaintFormat
{
public:

    // Paints a cell in CGrid.
    virtual void DrawCell(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) const;

    // Gets an effective background color of a cell after blending
    virtual COLORREF GetBackColor(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) const;
    
    // Gets an effective foreground color of a cell after blending
    virtual COLORREF GetForeColor(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) const;

    // Gets optimal width of a cell.
    virtual int GetOptimalCellWidth(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) const;

    // Gets the rectangle occupied by the icon painted in the cell.
    virtual CRect GetImageRect(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) const;

    // Gets cell bounds where a text can be drawn.
    virtual CRect GetTextRect(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) const;
    
    //Gets a clone of the format.
    virtual ICellPaintFormat* Clone() const;

protected:
    //Drawing functions
    virtual void OnDrawBackGround(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);
    virtual void OnDrawMouseSelection(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);
    virtual void OnDrawText(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);
    virtual void OnDrawImage(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);
    virtual void OnDrawFocusedLineFrame(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);
    virtual void OnDrawSelectedLineFrame(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);
    virtual void OnDrawHierarchy(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);
    virtual void OnDrawDropPosition(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);
    virtual void OnDrawDropParentPosition(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);
    virtual void OnDrawVerticalLines(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);
    virtual void OnDrawHorizontalLines(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);
    virtual void OnDrawEditInPlace(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);
    virtual void OnNextPaintRequest(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);

private:
    DF_DECLARE_CELL_PAINT_FORMAT();
};


}//namespace GUI

}//namespace Dapfor

