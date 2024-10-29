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

namespace Dapfor
{

namespace GUI
{

//////////////////////////////////////////////////////////////////////////
///\brief Helper class that facilitates some edit in place operations.
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  CEditInPlaceHelper EditInPlaceHelper.h Dapfor/GUI/EditInPlaceHelper.h
/// \file EditInPlaceHelper.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CEditInPlaceHelper
{
public:
    /// Gets an appropriate format.
    static const Common::CFormat*  GetAppropriateFormat(const Common::CDataObject* pDO, const CColumn* column);
    
    ///Finds the next cell to start edit in place
    static IEditInPlace::NavigationTarget FindNextNavigationTarget(const CEditInPlaceContext& context, IEditInPlace::StopReason stopReason);
    
    ///Adjusts CEdit control to cell size and position, sets a font of CGrid and focus.
    static void  AdjustControl(const CEditInPlaceContext& context, CEdit* editBox);

    ///Adjusts CComboBox control to cell size and position, sets a font of CGrid and focus.
    static CEmbeddedControlParams AdjustControl(const CEditInPlaceContext& context, CComboBox* comboBox);
    
    ///Adjusts CEdit style to a cell alignment.
    static UINT  AdjustEditBoxStyle(const Common::CFormat* format, const CColumn* column);
    

private:
    CEditInPlaceHelper();
};



}//namespace GUI

}//namespace Dapfor


