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

namespace Dapfor
{
namespace GUI
{

//////////////////////////////////////////////////////////////////////////
/// \brief Interface to iterate items in the CGrid.
///
/// \par ThreadSafety:
/// The operator () will be always called in the %GUI thread.
///
/// \version <b>2.0.0</b> Initial version
///
/// \par Example
/// \include foreach.example
///
/// \class  IForEach IForEach.h Dapfor/GUI/IForEach.h
/// \file IForEach.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API IForEach
{
public:
    /// Called to perform some operations on items in the grid.
    /// \param[in] grid Reference to CGrid object
    /// \param[in] item Handle associated with the data object.
    /// \param[in] pDO Pointer to the data object.
    /// \return False if no more iterations are needed. Otherwise true.
    virtual bool operator () (CGrid& grid, HITEM item, Common::CDataObject* pDO) = 0;
};

}//namespace GUI

}//namespace Dapfor

