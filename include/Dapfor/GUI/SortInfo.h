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

#include <Dapfor/GUI/Types.h>
#include <Dapfor/GUI/GUI_Export.h>

namespace Dapfor
{
namespace GUI
{

//////////////////////////////////////////////////////////////////////////
/// \brief Contains sorting related information
///
/// It is intended for storing information about sorting. The grid supports up to 5 levels of sorting 
/// (up to 5 columns simultaneously may be used for sorting). The set of �SortInfo objects is stored in the header. 
/// When the grid replaces the header, it automatically sorts lines according to the new rules. 
/// Besides, when the grid adds lines, gets notifications from ISink interface and calls functions... 
/// it automatically replaces a line to the corresponding location. 
///
/// It is important to note, that definition of lines locations in the grid is carried out  while comparing the 
/// unformatted values returned while calling data object functions by the identifier. It excludes the mistakes 
/// arising at comparing formatted strings (for example dates). To ensure correct data comparing, the returned 
/// values should have identical types.
///
/// \class  CSortInfo SortInfo.h Dapfor/GUI/SortInfo.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CSortInfo
{
public:
    CSortInfo(Common::FID fid, bool reverseSort);          //!< Constructor
    CSortInfo(const CSortInfo& sortInfo);                       //!< Copy constructor


    inline void             SetFid(Common::FID fid);       //!< Sets a new field identifier
    inline Common::FID GetFid() const;                     //!< Gets field identifier

    inline void             SetReverseSort(bool bReverse);      //!< Reverses sorting
    inline bool             GetReverseSort() const;             //!< Gets the value indicating whether sorting is reversed


    inline bool operator == (const CSortInfo& sortInfo) const;  //!< Equality operator

    virtual void            Serialize(CArchive& ar);            //!< Serializes data to/from the archive
    static int              GetSerializeVersion();              //!< Serialization version

private:
    Common::FID m_Fid;
    bool             m_ReverseSort;
};


//Inline functions


inline void CSortInfo::SetFid(Common::FID fid) 
{
    m_Fid = fid;
}

inline void CSortInfo::SetReverseSort(bool bReverse) 
{
    m_ReverseSort = bReverse;
}

inline Common::FID CSortInfo::GetFid() const 
{
    return m_Fid;
}

inline bool CSortInfo::GetReverseSort() const 
{
    return m_ReverseSort;
}

inline bool CSortInfo::operator == (const CSortInfo& sortInfo) const
{
    return (m_Fid == sortInfo.m_Fid) && (m_ReverseSort == sortInfo.m_ReverseSort);
}


} //namespace GUI

}//namespace Dapfor
