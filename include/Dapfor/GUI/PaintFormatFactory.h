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

namespace Dapfor
{
namespace GUI
{

//Forward declarations
class ICellPaintFormat;
class ILinePaintFormat;
class IColumnPaintFormat;
class IHeaderPaintFormat;

//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Enables creation of an instance of a specified format by its string name.
///
/// \version <b>1.0.0.0</b> Initial version
/// 
/// \class  CPaintFormatFactory PaintFormatFactory.h Dapfor/GUI/PaintFormatFactory.h
/// \file PaintFormatFactory.h
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CPaintFormatFactory
{
public:
    //Type declarations
    
    /// Pointer to the function that creates an instance of the format that derives from ICellPaintFormat
    typedef ICellPaintFormat*   (*pfnCellFormatCreate)();   

    /// Pointer to the function that creates an instance of the format that derives from ILinePaintFormat
    typedef ILinePaintFormat*   (*pfnLineFormatCreate)();   
    
    /// Pointer to the function that creates an instance of the format that derives from IColumnPaintFormat
    typedef IColumnPaintFormat* (*pfnColumnFormatCreate)(); 
    
    /// Pointer to the function that creates an instance of the format that derives from IHeaderPaintFormat
    typedef IHeaderPaintFormat* (*pfnHeaderFormatCreate)();

public:

    ///Registers a new format that implements ICellPaintFormat interface
    static bool RegisterCellFormat(const CString& className, pfnCellFormatCreate f)
    {
        bool result = InternalRegisterCellPaintFormat(className, f);

        // Another format with the same name has already been added to the factory. 
        // To prevent the ambiguity it is recommended to use namespace in the format declaration.
        // Ex: 
        //    DF_IMPLEMENT_CELL_PAINT_FORMAT(MyNamespace::CMyFormat);
        ASSERT(result);
        
        return result;
    }

    ///Registers a new format that implements ILinePaintFormat interface
    static bool RegisterLineFormat(const CString& className, pfnLineFormatCreate f)
    {
        bool result = InternalRegisterLinePaintFormat(className, f);

        // Another format with the same name has already been added to the factory. 
        // To prevent the ambiguity it is recommended to use namespace in the format declaration.
        // Ex: 
        //    DF_IMPLEMENT_LINE_PAINT_FORMAT(MyNamespace::CMyFormat);
        ASSERT(result);
        
        return result;
    }

    ///Registers a new format that implements IColumnPaintFormat interface
    static bool RegisterColumnFormat(const CString& className, pfnColumnFormatCreate f)
    {
        bool result = InternalRegisterColumnPaintFormat(className, f);

        // Another format with the same name has already been added to the factory. 
        // To prevent the ambiguity it is recommended to use namespace in the format declaration.
        // Ex: 
        //    DF_IMPLEMENT_COLUMN_PAINT_FORMAT(MyNamespace::CMyFormat);
        ASSERT(result);
        
        return result;
    }

    ///Registers a new format that implements IHeaderPaintFormat interface
    static bool RegisterHeaderFormat(const CString& className, pfnHeaderFormatCreate f)
    {
        bool result = InternalRegisterHeaderPaintFormat(className, f);

        // Another format with the same name has already been added to the factory. 
        // To prevent the ambiguity it is recommended to use namespace in the format declaration.
        // Ex: 
        //    DF_IMPLEMENT_HEADER_PAINT_FORMAT(MyNamespace::CMyFormat);
        ASSERT(result);
        
        return result;
    }
    

    /// Creates an instance of a format that implements ICellPaintFormat interface
    static ICellPaintFormat*   CreateCellPaintFormat(const CString& className);

    /// Creates an instance of a format that implements ILinePaintFormat interface
    static ILinePaintFormat*   CreateLinePaintFormat(const CString& className);

    /// Creates an instance of a format that implements IColumnPaintFormat interface
    static IColumnPaintFormat* CreateColumnPaintFormat(const CString& className);

    /// Creates an instance of a format that implements IHeaderPaintFormat interface
    static IHeaderPaintFormat* CreateHeaderPaintFormat(const CString& className);

private:
    static bool InternalRegisterCellPaintFormat(const CString& className, pfnCellFormatCreate f);
    static bool InternalRegisterLinePaintFormat(const CString& className, pfnLineFormatCreate f);
    static bool InternalRegisterColumnPaintFormat(const CString& className, pfnColumnFormatCreate f);
    static bool InternalRegisterHeaderPaintFormat(const CString& className, pfnHeaderFormatCreate f);

private:
    struct Impl;
    friend Impl;
};

}

}//namespace Dapfor
