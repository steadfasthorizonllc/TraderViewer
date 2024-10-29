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
#include <Dapfor/GUI/IClipboardFormat.h>

namespace Dapfor
{
namespace GUI
{

class CGrid;

//////////////////////////////////////////////////////////////////////////
///\brief Local data format to process drag and drop and copy/paste operations
/// inside of an application. 
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  CLocalDataFormat LocalDataFormat.h Dapfor/GUI/LocalDataFormat.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CLocalDataFormat : public IClipboardFormat
{
public:
    /// Constructor 
    CLocalDataFormat();

    /// Virtual destructor
    ~CLocalDataFormat();

    // Prepares data for serialization to the clipboard.
    virtual void Prepare(const Handles& handles, const CHeader& header);

    // Gets byte size for storing data in the binary buffer
    virtual long GetSerializationSize() const;

    // Serializes data to the binary buffer
    virtual void Serialize(void* buffer, const CGrid& grid, ContextType contextType, long userData) const;

    // Clears temporary data, created during a serialization process.
    virtual void Clear();
    
    /// Gets a clipboard format identifier (Registered with 'Dapfor.LocalDataFormat' name)
    virtual int  GetFormatId() const;

    // Deserializes data from the clipboard and tries to restore grid handles with its hierarchy.
    virtual bool Deserialize(const void* buffer, 
                             long        bufSize, 
                             const IObjectImporter* importer, 
                             IClipboardFormat::RestoredInfo& restoredInfo);

    


    /// Gets clipboard format identifier (Registered with 'Dapfor.LocalDataFormat' name)
    static int   LocalDataFormatFormatId();

private:
    CLocalDataFormat(const CLocalDataFormat&);
    CLocalDataFormat& operator = (const CLocalDataFormat&);


    struct Impl;
    Impl* m_Impl;
};

}

}//namespace Dapfor

