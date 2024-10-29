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
#include <Dapfor/GUI/IEditInPlace.h>
#include <vector>

namespace Dapfor
{

namespace Common
{
class CFormat;
class CDataObject;
}


namespace GUI
{
class CColumn;
class CGrid;
class CPaintContext;
class CGridCell;
class IControlReflector;

//////////////////////////////////////////////////////////////////////////
///\brief Contains a list of reflectors that create, populate and handle specified MFC controls 
///  during edit in place operations. 
///
/// The factory determines the order of reflectors. Reflectors are listed in this order below:
///
/// \n CBoolReflector
/// \n CLongEnumReflector
/// \n CInt64DateReflector
/// \n CLongMsecTimeReflector
/// \n CLongDateTimeReflector
/// \n CCharReflector
/// \n CUCharReflector
/// \n CShortReflector
/// \n CUShortReflector
/// \n CLongReflector
/// \n CULongReflector
/// \n CInt64Reflector
/// \n CFloatReflector
/// \n CDoubleReflector
/// \n CDefaultReflector
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  CEditInPlaceFactory EditInPlaceFactory.h Dapfor/GUI/EditInPlaceFactory.h
/// \file EditInPlaceFactory.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CEditInPlaceFactory
{
public:
    ///Container of reflectors
    typedef std::vector<IControlReflector*> Reflectors;

public: 
    static void AddReflector(IControlReflector* reflector);         //!< Adds a new reflector
    static void DeleteReflector(const Common::CFormat* format);//!< Removes all the reflectors that match to the format
    static void DeleteAllReflectors();                              //!< Removes all reflectors
    
    ///Looks for the reflector that matches to the specified format.
    static IControlReflector* GetReflector(const Common::CFormat* format);
    
    ///Gets a list of all reflectors
    static Reflectors& GetReflectors();

private:
    struct Impl;
    friend struct Impl;
};


}//namespace GUI

}//namespace Dapfor

