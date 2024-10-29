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

#include <Dapfor/GUI/Types.h>
#include <Dapfor/GUI/GUI_Export.h>
#include <Dapfor/GUI/PaintFormatFactory.h>

namespace Dapfor
{
namespace GUI
{
class CPaintContext;
class CGridCell;
class ICustomDraw;

//////////////////////////////////////////////////////////////////////////
///\brief Interface to paint a cell in CGrid.
///
/// This format paints the following elements: background, text, icons, selection, 
/// focus, +/- signs for unrolling and rolling up the hierarchy. Moreover, when embedded controls are used,
/// a part of painting can be handed over to those controls. GUI library provides a number of those 
/// interface implementations that can be used to paint a grid cell. It is also possible to implement a personal 
/// format that allows to totally redefine painting in the grid. From a practical point of view it is reasonable
/// to redefine ICellPaintFormat for radically new data presentation in the grid. In most cases where
/// it is required to just change text or background colors, forbid selection or focus painting 
/// and also customize a font or highlighting for each cell the easiest way is to redefine 
/// ICustomDraw interface that is the central point for passing all information necessary for painting.  
///
/// \version <b>1.0.0</b> Initial version
///
/// \class  ICellPaintFormat ICellPaintFormat.h Dapfor/GUI/ICellPaintFormat.h
/// \file ICellPaintFormat.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API ICellPaintFormat
{
public:
    virtual ~ICellPaintFormat(); //!< virtual destructor
    
    /// Paints a cell in CGrid.
    virtual void DrawCell(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) const = 0;

    /// Gets an effective background color of a cell after blending
    virtual COLORREF GetBackColor(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) const = 0;
    
    /// Gets an effective foreground color of a cell after blending
    virtual COLORREF GetForeColor(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) const = 0;

    /// Gets an optimal width of a cell.
    virtual int GetOptimalCellWidth(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) const = 0;

    /// Gets the rectangle, occupied by the icon painted in a cell.
    virtual CRect GetImageRect(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) const = 0;

    /// Gets cell bounds where a text can be drawn.
    virtual CRect GetTextRect(CGridCell& cell, const CPaintContext& paintContext, UINT paintFilter) const = 0;

    ///Gets a clone of a format.
    virtual ICellPaintFormat* Clone() const = 0;


    //Serialization

    ///Indicates whether an object of a class that implements ICellPaintFormat can be serialized.
    virtual BOOL    IsSerializableType() const;

    ///Gets a format name.
    virtual CString GetFormatName() const;

    ///Serializes an object to the archive.
    virtual void    Serialize(CArchive& ar);
};

}//namespace GUI

}//namespace Dapfor

//Macros to declare a type that can be serialized

/// \def DF_DECLARE_CELL_PAINT_FORMAT()
/// \brief Declares a format as serializable.
#define DF_DECLARE_CELL_PAINT_FORMAT()              \
public:                                             \
    static GUI::ICellPaintFormat* CreateFormat();   \
    virtual BOOL IsSerializableType() const;        \
    virtual CString GetFormatName() const;          \
    static  CString GetFormatClassName();           \
    struct Dummy { Dummy(); };                      \
    friend Dummy;                                   \
    static Dummy m_Dummy;                           


/// \def DF_IMPLEMENT_CELL_PAINT_FORMAT(_name)
/// \brief Implements serializable format.
/// \n _name  Class name. To prevent ambiguity, use namespace in the format declaration.
#define DF_IMPLEMENT_CELL_PAINT_FORMAT(_name)                               \
    GUI::ICellPaintFormat* _name::CreateFormat() {return new _name;}        \
    BOOL _name::IsSerializableType() const {return TRUE;}                   \
    CString _name::GetFormatName() const{return #_name;}                    \
    CString _name::GetFormatClassName() {return #_name;}                    \
    _name::Dummy::Dummy()                                                   \
    {                                                                       \
        GUI::CPaintFormatFactory::RegisterCellFormat(#_name, CreateFormat); \
    }                                                                       \
    _name::Dummy m_Dummy;



