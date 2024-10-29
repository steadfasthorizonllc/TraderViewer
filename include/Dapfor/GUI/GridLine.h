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
#include <Dapfor/GUI/PaintInfo.h>

namespace Dapfor
{
namespace GUI
{

class CGrid;

//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Line-related paint information
///
/// \version <b>1.0.0.0</b> Initial version
/// 
/// \class  CGridLine GridLine.h Dapfor/GUI/GridLine.h
/// \file GridLine.h
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CGridLine
{
public:
    ///Constructor
    CGridLine(const CPaintInfo&  paintInfo,
              ContextType        contextType,
              int                row,
              HITEM              item,
              bool               isPreviusRowSelected,
              bool               isNextRowSelected);

    ///Copy constructor
    CGridLine(const CGridLine& line);


    inline const CPaintInfo&        GetPaintInfo() const;        //!< Gets paint info
    inline CPaintInfo&              GetPaintInfo();              //!< Gets paint info. Const version.

    inline ContextType              GetContextType() const;      //!< Gets a context type where the data object was inserted.
    inline int                      GetRow() const;              //!< Gets a zero-based index in the specified context
    inline HITEM                    GetItem() const;             //!< Gets an item handle
    bool                            IsRowSelected() const;       //!< Indicates whether a line is selected
    inline bool                     IsPreviusRowSelected() const;//!< Indicates whether the previous line is selected. 
    inline bool                     IsNextRowSelected() const;   //!< Indicates whether the next line is selected. 
    long                            GetHierarchicalLevel() const;//!< Gets a zero-based level of the line in the hierarchy
    bool                            IsExpanded() const;          //!< Indicates whether a line is expanded. 
    const Common::CDataObject* GetDataObject() const;       //!< Returns the related data object

private:
    CPaintInfo          m_PaintInfo;
    ContextType         m_ContextType;
    int                 m_Row;
    HITEM               m_Item;
    bool                m_IsPreviusRowSelected;
    bool                m_IsNextRowSelected;
};


inline const CPaintInfo& CGridLine::GetPaintInfo() const
{
    return m_PaintInfo;
}
inline CPaintInfo&    CGridLine::GetPaintInfo()
{
    return m_PaintInfo;
}
inline ContextType CGridLine::GetContextType() const
{
    return m_ContextType;
}
inline int   CGridLine::GetRow() const
{
    return m_Row;
}
inline HITEM CGridLine::GetItem() const
{
    return m_Item;
}

inline bool CGridLine::IsPreviusRowSelected() const
{
    return m_IsPreviusRowSelected;
}

inline bool CGridLine::IsNextRowSelected() const
{
    return m_IsNextRowSelected;
}


}//namespace GUI

}//namespace Dapfor

