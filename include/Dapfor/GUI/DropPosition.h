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

//////////////////////////////////////////////////////////////////////////
///\brief  Indicates the location where clipboard content should be dropped.
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  CDropPosition DropPosition.h Dapfor/GUI/DropPosition.h
/// \file DropPosition.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CDropPosition
{
public:
    //Constructors
    CDropPosition();
    CDropPosition(const CDropPosition& dropPosition);
    CDropPosition(ContextType dropContext,
                  int         dropIndex,            
                  bool        dropAfter,
                  int         dropParentIndex);

    ~CDropPosition();

    /// Gets context type where items should be dropped
    ContextType  GetDropContext() const;    
    
    /// Gets zero-based index in context, where handles are dropped    
    int          GetDropIndex() const;      

    /// Indicates whether a drop is occurred before or after the specified index
    bool         GetDropAfter() const;      
    
    /// Specifies index of a parent, to which clipboard content should be attached
    int          GetDropParentIndex() const;

    CDropPosition& operator = (const CDropPosition& position);
private:
    struct Impl;
    Impl* m_Impl;
};


};

}//namespace Dapfor
