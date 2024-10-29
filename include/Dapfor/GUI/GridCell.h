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

#include <string>

#include <Dapfor/GUI/GUI_Export.h>
#include <Dapfor/GUI/Types.h>
#include <Dapfor/GUI/PaintInfo.h>



class CImageList;

namespace Dapfor
{
namespace Common
{
    class CValue;
    class CFormat;
}

namespace GUI
{

class CGridLine;
class CColumn;
class CPaintInfo;

//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Cell-related paint information
///
/// \version <b>1.0.0.0</b> Initial version
/// 
/// \class  CGridCell GridCell.h Dapfor/GUI/GridCell.h
/// \file GridCell.h
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CGridCell
{
public:
    ///Constructor
    CGridCell(const CPaintInfo& paintInfo, const CGridLine& gridLine, const CColumn* column, CImageList* imageList, int imageId, bool stretchImage, const Common::CFormat* format);
    /// Copy constructor
    CGridCell(const CGridCell& cell);

    inline const CPaintInfo&            GetPaintInfo() const;           //!< Gets paint info
    inline CPaintInfo&                  GetPaintInfo();                 //!< Gets paint info. Const version.
    inline const CGridLine&             GetGridLine() const;            //!< Gets the line that contains a cell.
    inline const CColumn*               GetColumn() const;              //!< Gets a column
    inline CImageList*                  GetImageList() const;           //!< Gets an image list to draw images in a cell
    inline int                          GetImageId() const;             //!< Gets an index of an image in the image list
    inline bool                         GetStretchImage() const;        //!< Indicates whether an image is stretched to vertical size of cell.
    

    inline const Common::CFormat*       CetTextFormat() const;          //!< Gets text format to draw text in a cell
    inline void                         SetTextFormat(const Common::CFormat* format); //!< Sets a new text format to draw the text in a cell

#ifndef DF_NOT_MFC
    CString                             GetFormattedMfcString() const;     //!< Gets MFC string to show in a cell
#endif

    TString                             GetFormattedStlString() const;     //!< Gets STL string to show in a cell
    Common::CValue                      GetValue() const;                  //!< Gets non-formatted value retrieved from a field of a corresponded data object.

    inline void                         SetImageList(CImageList* imageList);  //!< Sets a new image list
    inline void                         SetImageId(int imageId);                    //!< Sets a new image index
    inline void                         SetStretchImage(bool stretch);              //!< Sets the new value that enables image stretching
    void                                RequestNextPaint(int msec);         //!< Request a new painting routine for the given cell after the specified time


private:
    CPaintInfo          m_PaintInfo;
    const CGridLine&    m_GridLine;
    const CColumn*      m_Column;
    CImageList*         m_ImageList;
    int                 m_ImageId;
    bool                m_StretchImage;
    const Common::CFormat* m_Format;
};

inline const CPaintInfo& CGridCell::GetPaintInfo() const
{
    return m_PaintInfo;
}
inline CPaintInfo&    CGridCell::GetPaintInfo()
{
    return m_PaintInfo;
}
inline const CGridLine& CGridCell::GetGridLine() const
{
    return m_GridLine;
}
inline const CColumn* CGridCell::GetColumn() const
{
    return m_Column;
}

inline CImageList* CGridCell::GetImageList() const
{
    return m_ImageList;
}

inline int CGridCell::GetImageId() const
{
    return m_ImageId;
}

inline bool CGridCell::GetStretchImage() const
{
    return m_StretchImage;
}

inline const Common::CFormat* CGridCell::CetTextFormat() const
{
    return m_Format;
}
inline void CGridCell::SetTextFormat(const Common::CFormat* format)
{
    m_Format = format;
}

inline void CGridCell::SetImageList(CImageList* imageList)
{
    m_ImageList = imageList;
}
inline void CGridCell::SetImageId(int imageId)
{
    m_ImageId = imageId;
}

inline void CGridCell::SetStretchImage(bool stretch)
{
    m_StretchImage = stretch;
}


}//namespace GUI

}//namespace Dapfor

