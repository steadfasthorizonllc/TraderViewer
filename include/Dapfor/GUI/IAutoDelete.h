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

//////////////////////////////////////////////////////////////////////////
///\brief Determines whether the object that implements IAutoDelete interface
/// is destroyed by CGrid.
///
/// \version <b>2.0.0</b> Initial version
///
/// \class  IAutoDelete IAutoDelete.h Dapfor/GUI/IAutoDelete.h
/// \file IAutoDelete.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API IAutoDelete
{
public:
    virtual ~IAutoDelete();
    
    /// Indicates whether the object of the class derived from IAutoDelete interface
    /// is destroyed by CGrid. (Usually in the destructor of CGrid).
    virtual bool AutoDelete() const = 0;
};

}//namespace GUI

}//namespace Dapfor

