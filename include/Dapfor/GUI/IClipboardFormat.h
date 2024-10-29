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
#include <vector>

namespace Dapfor
{
namespace Common
{
class CDataObject;
}

//Forward declarations
namespace GUI
{

class CHeader;
class CGrid;
class IObjectImporter;

//////////////////////////////////////////////////////////////////////////
///\brief Serializes and deserializes handles to lines in CGrid to/from the clipboard.
///
/// \version <b>1.0.0.0</b> Initial version
///
/// \class  IClipboardFormat IClipboardFormat.h Dapfor/GUI/IClipboardFormat.h
/// \file IClipboardFormat.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API IClipboardFormat
{
public:
    /// Source type
    enum SourceType
    {
        Local,  //!< Data has been copied from the same address space
        Remote, //!< Data has been copied to the clipboard by another application. The case of import data.
    };

    /// Container to store imported (created by Common::CTypeFactory) data objects 
    typedef std::vector<Common::CDataObject*> DataObjects;
    
    ///This structure keeps data with their hierarchy, deserialized from the clipboard.
    struct RestoredInfo
    {
        RestoredInfo();

        CGrid*          m_Grid;             //!< Valid pointer to the grid that puts data to the clipboard (Inside of an application)
        ContextType     m_ContextType;      //!< Context that is a data source
        GUI::Handles    m_Handles;          //!< List of deserialized handles. 
        DataObjects     m_CreatedObjects;   //!< List of the data objects, imported from other applications.
        SourceType      m_SourceType;       //!< Indicates which applications put data to the clipboard. Local - the same, Remote - other one.
        int             m_FormatId;         //!< Clipboard format identifier
        UINT            m_userData;         //!< User defined data (not for all clipboard formats). 
    };
public:
    virtual ~IClipboardFormat();    //!< Virtual destructor

    /// Prepares data for serialization to the clipboard.
    virtual void Prepare(const Handles& handles, const CHeader& header) = 0;

    /// Gets the size in bytes needed to store data to a binary buffer
    virtual long GetSerializationSize() const = 0;

    /// Serializes data to a binary buffer
    virtual void Serialize(void* buffer, const CGrid& grid, ContextType contextType, long userData) const = 0;

    /// Clears temporary data created during a serialization process.
    virtual void Clear() = 0;

    /// Gets clipboard format identifier (CF_TEXT, CF_BITMAP or already registered user-defined format)
    virtual int GetFormatId() const = 0;

    /// Deserializes data from the clipboard and tries to restore grid handles with their hierarchy.
    virtual bool Deserialize(const void* buffer, long bufSize, const IObjectImporter* importer, RestoredInfo& restoredInfo) = 0;

    /// Creates a new handle that initially is not attached to the grid.
    static HITEM CreateHandle(Common::CDataObject* pDO, HITEM hParent);
};



}//namespace GUI

}//namespace Dapfor

