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
#include <Dapfor/GUI/IAutoDelete.h>
#include <Dapfor/GUI/Grid.h>

namespace Dapfor
{
namespace GUI
{

class CGrid;

//////////////////////////////////////////////////////////////////////////
///\brief Interface to filter data objects in CGrid.
///
/// \version <b>2.0.0</b> Initial version
///
/// \class  IGridFilter IGridFilter.h Dapfor/GUI/IGridFilter.h
/// \file   IGridFilter.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API IGridFilter : virtual public IAutoDelete 
{
public:
    /// Verifies whether the data object inserted in CGrid is filtered. 
    /// \param[in] grid Reference to a grid
    /// \param[in] item Handle accociated with the data object inserted in CGrid.
    /// \param[in] pDO Pointer to a data object.
    /// \return true if the item should be filtered. Otherwise false.
    virtual bool operator () (const CGrid& grid, const HITEM  item, const Common::CDataObject* pDO) = 0;
};


}//namespace GUI

}//namespace Dapfor

