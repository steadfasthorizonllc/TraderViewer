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
#include <Dapfor/GUI/ICustomDraw.h>
#include <Dapfor/GUI/Types.h>

namespace Dapfor
{
namespace GUI
{

//////////////////////////////////////////////////////////////////////////
///\brief Default implementation of ICustomDraw interface.
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  CCustomDraw CustomDraw.h Dapfor/GUI/CustomDraw.h
/// \file CustomDraw.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CCustomDraw : public ICustomDraw
{
public:
    CCustomDraw(bool bAutoDelete = false); //!< Constructor

    // Called to draw a header in CGrid.
    virtual void DrawHeader(CHeaderPaintInfo& paintInfo, const CPaintContext& paintContext, UINT paintFilter);

    // Called to draw a column in CGrid.
    virtual void DrawColumn(CColumnPaintInfo& paintInfo, const CPaintContext& paintContext, UINT paintFilter);

    // Called to draw a line. 
    virtual void DrawLine(CGridLine& line, const CPaintContext& paintContext, UINT paintFilter);

    // Called to draw a cell. 
    virtual void DrawCell(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter);
    
    // Provides a default line paint format. The user can specify his preferred format for each line in CGrid.
    virtual const ILinePaintFormat& GetLinePaintFormat(const Common::CDataObject* pDO, HITEM hItem, ContextType contextType, int nRow) const;

    // Provides a default cell paint format. The user can specify his preferred format for each cell in CGrid.
    virtual const ICellPaintFormat& GetCellPaintFormat(const CColumn* column, const Common::CDataObject* pDO, HITEM hItem, ContextType contextType, int nRow) const;

    // Calculates an optimal height of a header.
    virtual int GetOptimalHeaderHeight(CHeaderPaintInfo& paintInfo, const CPaintContext& paintContext, UINT paintFilter) const;

    // Calculates an optimal height of a row.
    virtual int GetOptimalRowHeight(CFont* font, CDC& dc) const;
    
    // Calculates an optimal width of a cell taking into account a font, hierarchy, text size...
    virtual int GetOptimalCellWidth(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) const;


    /// IAutoDelete implementation. The function always returns true.
    virtual bool AutoDelete() const;

private:
    bool m_AutoDelete;

};

}//namespace GUI

}//namespace Dapfor

