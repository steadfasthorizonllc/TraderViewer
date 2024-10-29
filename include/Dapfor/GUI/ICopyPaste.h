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

namespace Dapfor
{
namespace GUI
{

class CGrid;
class CPasteTarget;

//////////////////////////////////////////////////////////////////////////
///\brief Interface to copy contents of CGrid to the clipboard.
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  ICopyPaste ICopyPaste.h Dapfor/GUI/ICopyPaste.h
/// \file ICopyPaste.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API ICopyPaste : virtual public IAutoDelete
{
public:
    ///Available clipboard operations
    enum OperationType
    {
        clipboardUndefined,     //!< Undefined clipboard operation
        clipboardCopy,          //!< Copy
        clipboardCut,           //!< Cut 
    };

public:
    ///Copies a content of CGrid to the clipboard
    virtual bool Copy(const CGrid& grid) = 0;

    ///Cuts a content of CGrid to the clipboard
    virtual bool Cut(const CGrid& grid) = 0;

    ///Pastes the clipboard data to CGrid.
    virtual bool Paste(CPasteTarget& pasteTarget) = 0;
};

}//namespace GUI

}//namespace Dapfor

