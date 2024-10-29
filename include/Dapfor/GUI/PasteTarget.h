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

namespace Dapfor
{
namespace GUI
{
class CGrid;

//////////////////////////////////////////////////////////////////////////
///\brief Indicates the location in the grid where a clipboard content should be inserted.
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  CPasteTarget PasteTarget.h Dapfor/GUI/PasteTarget.h
/// \file PasteTarget.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CPasteTarget
{
public:
    ///Constructor
    CPasteTarget(CGrid&         grid, 
                 HITEM          pasteParent, 
                 HITEM          pastePosition);

    ///Destructor
    ~CPasteTarget();


    /// Gets the grid where data is pasted
    CGrid& GetGrid() const;         

    /// Gets the parent handle that content is attached to
    HITEM  GetPasteParent() const;      

    /// Gets the position in a parent handle where content is pasted
    HITEM  GetPastePosition() const;    

    
private:
    CPasteTarget();
    CPasteTarget(const CPasteTarget&);
    CPasteTarget& operator = (const CPasteTarget&);

    struct Impl;
    Impl* m_Impl;
};


}//namespace GUI

}//namespace Dapfor

