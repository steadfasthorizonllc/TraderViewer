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

class CImageList;

namespace Dapfor
{
namespace GUI
{

class CGrid;
class CHeader;

//////////////////////////////////////////////////////////////////////////
///\brief Grid items source in drag & drop clipboard operations.
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  CDragSource DragSource.h Dapfor/GUI/DragSource.h
/// \file DragSource.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CDragSource
{
public:
    ///Constructor
    CDragSource(const CGrid& grid,
                ContextType contextType,
                Handles& items,
                const CHeader* header);

    /// Virtual destructor
    virtual ~CDragSource();


    /// Gets a reference to the grid from which data is taken
    const CGrid&     GetGrid() const;       

    /// Gets the context where the drag operation occurs.
    ContextType      GetContextType() const;    
    
    /// Gets a list of handles to be serialized to the clipboard
    Handles&         GetItems();            
    
    /// Gets a list of handles to be serialized to the clipboard. Const version.
    const Handles&   GetItems() const;      
    
    /// Gets an image of dragged items
    CDragImage       GetDragImage() const;  

    /// Gets a header of the grid
    const CHeader*   GetHeader() const;     


    /// Sets new drag image
    CDragImage       SetDragImage(const CDragImage& dragImage); 

    /// Sets a new context type(s)
    void             SetContextType(ContextType contextType);   
    
    /// Sets a new header
    void             SetHeader(const CHeader* header);          

private:
    CDragSource();
    CDragSource(const CDragSource&);
    CDragSource& operator = (const CDragSource&);


    struct Impl;
    Impl* m_Impl;
};


}//namespace GUI

}//namespace Dapfor

