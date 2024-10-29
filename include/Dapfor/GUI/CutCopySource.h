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
#include <Dapfor/GUI/ICopyPaste.h>

#include <vector>

namespace Dapfor
{
namespace GUI
{
class CGrid;
class IClipboardFormat;
class CHeader;

//////////////////////////////////////////////////////////////////////////
///\brief Grid items source in copy or cut clipboard operations.
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  CCutCopySource CutCopySource.h Dapfor/GUI/CutCopySource.h
/// \file CutCopySource.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CCutCopySource
{
public:
    ///List of the clipboard formats
    typedef std::vector<IClipboardFormat*> Formats;

public:
    ///Constructor
    CCutCopySource(const CGrid& grid, 
                   const CHeader* header, 
                   ContextType contextType, 
                   GUI::Handles& handles, 
                   const Formats& formats, 
                   ICopyPaste::OperationType operationType);

    ~CCutCopySource();


    /// Gets the grid where items are copied/cut from
    const CGrid&   GetGrid() const;                     
    
    /// Gets a header of the grid
    const CHeader* GetHeader() const;                       
    
    /// Gets enumeration of contexts that participated in the copy/cut operation 
    ContextType    GetContextType() const;              
    
    /// Gets sorted item handles to be serialized to the clipboard
    GUI::Handles&  GetHandles();                            
    
    /// Gets a list of the clipboard formats
    Formats&       GetFormats();                            

    /// Gets operation type
    ICopyPaste::OperationType GetOperationType() const;             

    /// Sets a new header
    void SetHeader(const CHeader* header);                          
    
    /// Sets new enumeration of contexts that participated in the copy/cut operation 
    void SetContextType(ContextType contextType);                   

    /// Sets a new operation type
    void SetOperationType(ICopyPaste::OperationType operationType); 
    
private:
    CCutCopySource();
    CCutCopySource(const CCutCopySource&);
    CCutCopySource& operator = (const CCutCopySource&);

    struct Impl;
    Impl* m_Impl;
};


}//namespace GUI

}//namespace Dapfor

