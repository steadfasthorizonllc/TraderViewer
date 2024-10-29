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

namespace Dapfor
{
namespace GUI
{

class CPaintContext;
class CPaintInfo;
class CGridLine;
class CGridCell;
class CColorBlend;


//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Helper that implements the most frequent painting routines.
///
/// \version <b>1.0.0.0</b> Initial version
/// 
/// \class  CPaintHelper PaintHelper.h Dapfor/GUI/PaintHelper.h
/// \file PaintHelper.h
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CPaintHelper
{
public:
    ///Rectangle side
    enum EnSide
    {
        Left    = 0x01, //!< top
        Top     = 0x02, //!< left
        Bottom  = 0x04, //!< bottom
        Right   = 0x08, //!< right
    };

public:
    ///Paints background of a cell
    static void DrawBackground(CRect cellRc, COLORREF color, const CPaintContext& paintContext);
    
    ///Paints a part of the rectangle, selected by the mouse with pressed left button in a cell.
    static void DrawMouseTrackSelection(CRect cellRc, CColorBlend color, COLORREF borderColor, const CPaintContext& paintContext);

    ///Paints text in a cell.
    static void DrawText(const TString& text, COLORREF color, const CRect& textRc, UINT style, const CPaintInfo& paintInfo, const CPaintContext& paintContext);

    ///Paints a part of selection around selected lines.
    static void DrawSelectionFrame(const CGridCell& cell, COLORREF frameColor, const CPaintContext& paintContext);

    ///Paints a part of focused frame around a focused line.
    static void DrawFocus(const CGridCell& cell, COLORREF color, const CPaintContext& paintContext);

    ///Paints +/- icons in a cell.
    static void DrawCollapseExpandIcon(const CGridCell& cell, COLORREF color, const CPaintContext& paintContext);

    ///Paints hierarchical lines in a cell.
    static void DrawHierarchicalLines(const CGridCell& cell, COLORREF color, const CPaintContext& paintContext);

    ///Paints a flat separator between two grid lines which indicates where a clipboard content should be inserted.
    static void DrawDropPosition(const CGridCell& cell, COLORREF color, const CPaintContext& paintContext);

    ///Paints a hierarchical cursor that indicates the parent to which a clipboard content should be attached.
    static void DrawDropParentPosition(const CGridCell& cell, COLORREF color, const CPaintContext& paintContext);

    ///Paints vertical lines between columns
    static void DrawVerticalLines(const CGridCell& cell, COLORREF color, const CPaintContext& paintContext);

    ///Paints horizontal lines between rows
    static void DrawHorizontalLines(const CGridCell& cell, COLORREF color, const CPaintContext& paintContext);
    
    ///Paints an icon in a cell
    static void DrawImage(const CGridCell& cell, const CPaintContext& paintContext, const CRect& rc, COLORREF backcolor, bool transparent);

    ///Indicates whether a specified visible handle is the last for its parent.
    static bool IsLastLevelItem(HITEM item);

    ///Indicates whether a line has underlying visible children that can be collapsed or expanded.
    static bool CanShowExpandOrCollapseIcon(const CGridLine& line, const CPaintContext& paintContext);

    ///Gets the result of blending of background and selection colors.
    static CColorBlend GetSelectionColorBlend(const CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);

    ///Gets the result of blending of background and focused item colors.
    static CColorBlend GetFocusedRowColorBlend(const CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);
    
    ///Gets the result of blending of background and sorted column colors.
    static CColorBlend GetSortedColumnColorBlend(const CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);

    ///Gets the result of blending of foreground and highlighted item colors.
    static CColorBlend GetHighlightForeColorBlend(const CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);

    ///Gets the result of blending of background and highlighted item colors.
    static CColorBlend GetHighlightBackColorBlend(const CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);

    ///Gets resulting background color after blending with highlighting, sorting, selection and focusing colors.
    static COLORREF GetResultingBackColor(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);

    ///Gets resulting text color after blending with highlighting, sorting, selection and focusing colors.
    static COLORREF GetResultingTextColor(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);

    ///Gets a rectangle inside of the cell, available to painting. 
    static CRect GetCellPaintableRectangle(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);

private:
    CPaintHelper();
    CPaintHelper(const CPaintHelper& helper);
    CPaintHelper& operator = (const CPaintHelper&);
};


}//namespace GUI

}//namespace Dapfor

