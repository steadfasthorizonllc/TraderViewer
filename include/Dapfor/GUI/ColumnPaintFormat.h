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

#include <Dapfor/GUI/IColumnPaintFormat.h>

namespace Dapfor
{
namespace GUI
{

//////////////////////////////////////////////////////////////////////////
///\brief Default implementation of IColumnPaintFormat interface. Performs painting of a column in CGrid.
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  CColumnPaintFormat ColumnPaintFormat.h Dapfor/GUI/ColumnPaintFormat.h
/// \file ColumnPaintFormat.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CColumnPaintFormat : public IColumnPaintFormat
{
public:
    CColumnPaintFormat();   //!< Default constructor
    ~CColumnPaintFormat();  //!< Virtual destructor

    // Draws a column in the header
    virtual void DrawColumn(CColumnPaintInfo& paintInfo, const CPaintContext& paintContext, UINT paintFilter) const;

    // Gets a clone of the object
    virtual IColumnPaintFormat* Clone() const;

    /// Calculates a width, required by a sort icon.
    virtual int  GetRequiredSortInfoWidth() const;

    // Drawing functions
    virtual void DrawBackground(CColumnPaintInfo& paintInfo, const CPaintContext& paintContext, UINT paintFilter) const;
    virtual void DrawSort(CColumnPaintInfo& paintInfo, const CPaintContext& paintContext, UINT paintFilter) const;
    virtual void DrawText(CColumnPaintInfo& paintInfo, const CPaintContext& paintContext, UINT paintFilter) const;
    virtual void DrawImage(CImageList* imageList, int index, const CRect rc, CDC& dc) const;

private:
    DF_DECLARE_COLUMN_PAINT_FORMAT();
};

}//namespace GUI

}//namespace Dapfor


