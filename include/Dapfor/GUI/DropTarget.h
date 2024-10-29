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
#include <Dapfor/GUI/DropPosition.h>

class COleDataObject;

namespace Dapfor
{
namespace GUI
{
class CGrid;

//////////////////////////////////////////////////////////////////////////
///\brief Contains the grid, position, and clipboard content to perform a drop operation.
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  CDropTarget DropTarget.h Dapfor/GUI/DropTarget.h
/// \file DropTarget.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CDropTarget
{
public:
    /// Constructor
    CDropTarget(CGrid&                  grid, 
                const CDropPosition&    dropPosition,
                COleDropTarget&         dropTarget,
                COleDataObject*         data,
                DWORD                   dwKeyState,
                CPoint                  point);
    
    ~CDropTarget();



    /// Gets the grid where data should be dropped
    CGrid&               GetGrid() const;       

    /// Gets a drop position inside of the grid
    const CDropPosition& GetDropPosition() const;

    /// MFC object that provides communication mechanism between the window and OLE libraries.
    COleDropTarget&      GetDropTarget() const; 
    
    /// Gets a clipboard content
    COleDataObject*      GetData() const;       

    /// Contains the state of the modifier keys. 
    DWORD                GetdwKeyState() const; 
    
    /// Gets the current location of the cursor in the client's coordinates.
    CPoint               GetPoint() const;      
    
private:
    CDropTarget();
    CDropTarget(const CDropTarget& );
    CDropTarget& operator = (const CDropTarget&);

    struct Impl;
    Impl* m_Impl;
};


}//namespace GUI

}//namespace Dapfor

