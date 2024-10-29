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

class CColumnPaintInfo;
class CPaintContext;

//////////////////////////////////////////////////////////////////////////
///\brief Interface to paint a header in CGrid.
///
/// \version <b>1.0.0</b> Initial version
///
/// \class  IColumnPaintFormat IColumnPaintFormat.h Dapfor/GUI/IColumnPaintFormat.h
/// \file IColumnPaintFormat.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API IColumnPaintFormat
{
public:
    virtual ~IColumnPaintFormat(); //!< Virtual destructor
    
    /// Draws a column in a header
    virtual void DrawColumn(CColumnPaintInfo& paintInfo, const CPaintContext& paintContext, UINT paintFilter) const = 0;

    ///Gets a clone of an object
    virtual IColumnPaintFormat* Clone() const = 0;


    
    ///Indicates whether the object of the class which implements IColumnPaintFormat is serializable.
    virtual BOOL    IsSerializableType() const;

    ///Gets a format name.
    virtual CString GetFormatName() const;

    ///Serializes an object to the archive.
     virtual void    Serialize(CArchive& ar);
};



}//namespace GUI

}//namespace Dapfor

//Helpers to declare a serializable type

/// \def DF_DECLARE_COLUMN_PAINT_FORMAT()
/// \brief Declares a column format as a serializable type.
#define DF_DECLARE_COLUMN_PAINT_FORMAT()            \
public:                                             \
    static GUI::IColumnPaintFormat* CreateFormat(); \
    virtual BOOL IsSerializableType() const;        \
    virtual CString GetFormatName() const;          \
    static  CString GetFormatClassName();           \
    struct Dummy { Dummy(); };                      \
    friend Dummy;                                   \
    static Dummy m_Dummy;                           


/// \def DF_IMPLEMENT_COLUMN_PAINT_FORMAT(_name)
/// \brief Implements a serializable type.
/// \n _name  Class name. To prevent ambiguity, use namespace in the format declaration.
#define DF_IMPLEMENT_COLUMN_PAINT_FORMAT(_name)                                 \
    GUI::IColumnPaintFormat* _name::CreateFormat() {return new _name;}          \
    BOOL _name::IsSerializableType() const {return TRUE;}                       \
    CString _name::GetFormatName() const{return #_name;}                        \
    CString _name::GetFormatClassName() {return #_name;}                        \
    _name::Dummy::Dummy()                                                       \
    {                                                                           \
        GUI::CPaintFormatFactory::RegisterColumnFormat(#_name, CreateFormat);   \
    }                                                                           \
    _name::Dummy m_Dummy;



