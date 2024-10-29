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
#include <Dapfor/GUI/IAutoDelete.h>
#include <Dapfor/GUI/IObjectImporter.h>
#include <vector>

namespace Dapfor
{
namespace GUI
{

class CDragSource;
class CDropTarget;
class CGrid;

//////////////////////////////////////////////////////////////////////////
///\brief Drag and drop interface. 
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  IDragDrop IDragDrop.h Dapfor/GUI/IDragDrop.h
/// \file IDragDrop.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API IDragDrop : virtual public IAutoDelete
{
public:
    virtual ~IDragDrop(); //!< Virtual destructor

    /// Called to perform a drag operation. 
    virtual DROPEFFECT DoDrag(CDragSource& dragSource) = 0;

    /// Called by CGrid when the cursor is dragged into a window for the first time.
    virtual DROPEFFECT OnDragEnter(const CDropTarget& dropTarget) = 0;
    
    /// Called by CGrid when the cursor is dragged over a window.
    virtual DROPEFFECT OnDragOver(const CDropTarget& dropTarget) = 0;

    /// Called by CGrid when a drop operation is about to occur.
    virtual BOOL OnDrop(const CDropTarget& dropTarget, DROPEFFECT dropEffect) = 0;

    ///Called by the framework when the cursor leaves a window during a dragging operation.
    virtual void OnDragLeave(const CGrid& grid) = 0;

    ///The function indicates whether data can be dropped to a specified location.
    virtual bool CanDrop(const CDropTarget& dropTarget) const = 0;

};

}//namespace GUI

}//namespace Dapfor

