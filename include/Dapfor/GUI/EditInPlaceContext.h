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
#include <Dapfor/GUI/Column.h>

namespace Dapfor
{

namespace Common
{
class CFormat;
}

namespace GUI
{
class CGrid;

//////////////////////////////////////////////////////////////////////////
/// \brief Contains nested information such as reference to CGrid, cell position etc. to perform edit in place.
///
/// \version <b>2.0.0</b> Initial version
///
/// \class  CEditInPlaceContext EditInPlaceContext.h Dapfor/GUI/EditInPlaceContext.h
/// \file EditInPlaceContext.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CEditInPlaceContext
{
public:
    ///Constructor
    CEditInPlaceContext(CGrid&  grid,
                        HITEM   item,
                        Common::CDataObject* pDO,
                        const CColumn* column);

    inline CGrid&                     GetGrid();               //!< Reference to a grid object.
    inline const CGrid&               GetGrid() const;         //!< Reference to a grid object. Const version.
    inline HITEM                      GetItem() const;         //!< Gets a handle of a line in CGrid.
    inline Common::CDataObject*       GetDataObject();         //!< Gets an underlying data object.
    inline const Common::CDataObject* GetDataObject() const;   //!< Gets an underlying data object. Const version.
    inline const CColumn*             GetColumn() const;       //!< Gets a column.

private:
    CGrid&                 m_Grid;
    HITEM                  m_Item;
    Common::CDataObject*   m_DO;
    const CColumn*         m_Column;
};


//Inline functions
inline CGrid&                     CEditInPlaceContext::GetGrid()              {return m_Grid;}
inline const CGrid&               CEditInPlaceContext::GetGrid() const        {return m_Grid;}
inline HITEM                      CEditInPlaceContext::GetItem() const        {return m_Item;}
inline Common::CDataObject*       CEditInPlaceContext::GetDataObject()        {return m_DO;}
inline const Common::CDataObject* CEditInPlaceContext::GetDataObject() const  {return m_DO;}
inline const CColumn*             CEditInPlaceContext::GetColumn() const      {return m_Column;}


}//namespace GUI

}//namespace Dapfor
