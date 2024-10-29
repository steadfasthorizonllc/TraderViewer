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
#include <Dapfor/GUI/IAutoDelete.h>

#include <Dapfor/GUI/HeaderPaintInfo.h>
#include <Dapfor/GUI/ColumnPaintInfo.h>
#include <Dapfor/GUI/PaintContext.h>
#include <Dapfor/GUI/GridLine.h>
#include <Dapfor/GUI/GridCell.h>
#include <Dapfor/GUI/Column.h>


namespace Dapfor
{
namespace GUI
{

class ILinePaintFormat;
class ICellPaintFormat;
class IHeaderPaintFormat;



//////////////////////////////////////////////////////////////////////////
///\brief Performs custom drawing in CGrid.
///
/// It is designed to customize drawing of all elements in the grid. 
/// This interface is the central point through which all information for drawing each grid element is passed. 
/// Grid functions are divided into three groups. The first group is for drawing headers, 
/// the second group is for drawing lines and cells and the third group returns optimal lines, columns 
/// and cells sizes calculated on the basis of grid settings, font size, size of text displayed 
/// in cells, hierarchy and so on.
///
/// The interface itself is not designed for direct manipulation of "device context", although 
/// nothing prevents to do so. Originally specialized formats were intended for this purpose. IHeaderPaintFormat header
/// and its default implementation CHeaderPaintFormat are used for painting. This format only calculates 
/// column size and location in the grid and hands over the painting task to IColumnPaintFormat via
/// ICustomDraw. Neither IHeaderPaintFormat nor ICustomDraw performs direct column painting.
///
/// The same mechanism is used for painting lines and cells. ICustomDraw passes all necessary information 
/// to ILinePaintFormat that calculates cell location in the grid and uses ICustomDraw to
/// pass the calculated information to ICellPaintFormat that performs painting directly. 
///
/// Such approach enables storage of all graphical information at one place and complete re-definition of
/// grid painting at any moment. When you need to redefine colors, font or icon to forbid displaying 
/// selection in some separate cells, ICustomDraw is the best choice.
/// As for calculation of optimal height or width of headers, lines and cells, formats can do this best 
/// of all because they know how will information be displayed on screen.
///
/// \version <b>1.0.0</b> Initial version
///
/// \class  ICustomDraw ICustomDraw.h Dapfor/GUI/ICustomDraw.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API ICustomDraw : virtual public IAutoDelete
{
public:
    ///Called to draw a header in CGrid.
    virtual void DrawHeader(CHeaderPaintInfo& paintInfo, const CPaintContext& paintContext, UINT paintFilter) = 0;

    ///Called to draw a column in CGrid.
    virtual void DrawColumn(CColumnPaintInfo& paintInfo, const CPaintContext& paintContext, UINT paintFilter) = 0;

    /// Called to draw a line. 
    virtual void DrawLine(CGridLine& line, const CPaintContext& paintContext, UINT paintFilter) = 0;

    /// Called to draw a cell. 
    virtual void DrawCell(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) = 0;

    /// Provides default line paint format. The user can specify his preferred format for each line in CGrid.
    virtual const ILinePaintFormat& GetLinePaintFormat(const Common::CDataObject* pDO, HITEM hItem, ContextType contextType, int nRow) const = 0;

    /// Provides default cell paint format. The user can specify his preferred format for each cell in CGrid.
    virtual const ICellPaintFormat& GetCellPaintFormat(const CColumn* column, const Common::CDataObject* pDO, HITEM hItem, ContextType contextType, int nRow) const = 0;

    /// Calculates optimal header height.
    virtual int GetOptimalHeaderHeight(CHeaderPaintInfo& paintInfo, const CPaintContext& paintContext, UINT paintFilter) const = 0;

    /// Calculates optimal row height.
    virtual int GetOptimalRowHeight(CFont* font, CDC& dc) const = 0;
    
    /// Calculates optimal cell width considering a font, hierarchy, text size...
    virtual int GetOptimalCellWidth(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) const = 0;
};

}//namespace GUI

}//namespace Dapfor



