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

#include <Dapfor/GUI/IAutoDelete.h>
#include <Dapfor/GUI/GUI_Export.h>
#include <Dapfor/GUI/Column.h>

namespace Dapfor
{
namespace GUI
{

class CGrid;

//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief This class implements the header
///
/// Stores columns and allows their handling and also stores the necessary information for sorting lines in the grid. 
/// All the columns inserted in the header have the identifiers corresponding to the identifiers of data object fields. 
/// The given identifiers should not repeat. While replacing headers in the grid, data objects contents can be presented 
/// in absolutely another way. 
///
/// The header allows to do columns invisible, to replace them, to organize unscrolling columns. Also the header stores 
/// the information about sorting. While setting a new header the grid automatically makes line sorting according to 
/// the rules set in the header. Up to five levels of sorting (up to five columns which take part) are possible. 
/// At defining a line location in the grid there is a comparison of the unformatted values returned by 
/// data objects fields. This also considers hierarchical structure of the grid. 
///
/// When columns are added to the header, there is a subscription to dispatch events which are transferred in the grid then. 
/// Also the header can generate its own events and notify the subscribers. 
///
/// It is also important to note, that almost all the functions of CHeader class are thread-safe and can be called 
/// from any thread. All events are sent in such a way, that at the moment of their sending synchronizing objects of 
/// such type as critical section or mutex are not occupied.
/// 
/// \class  CHeader Header.h Dapfor/GUI/Header.h
/// \file Header.h
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CHeader : public IAutoDelete
                      , public CObject
{
public:
    typedef std::vector<CColumn*> Columns;

    ///Notification type
    enum NotificationType
    {
        ColumnAdded,            //!< A new column has been added to the header
        ColumnRemoved,          //!< A column has been removed from the header
        ColumnResized,          //!< Column size has been changed
        ColumnModified,         //!< Some values in the column have been modified
        ColumnVisibleChanged,   //!< The visibility of the column has been changed
        ColumnMoved,            //!< The column has been moved
        
        FixedCountChanged,      //!< The count of fixed columns is changed
        SortChanged,            //!< Sorting is modified
        NavigationColumnChanged,//!< Navigation column has been changed
        HeaderHeightChanged,    //!< Height of the header has been changed
        FontChanged,            //!< Header font has been changed
        ImageListChanged,       //!< Images list to show that icons in columns are changed
    };

    /// Interface to receive notifications about the header state modification
    struct INotify
    {
        virtual void OnHeaderModified(const CHeader* header, const CColumn* column, NotificationType type) = 0;
    };


public:
    //Constructors & destructor
    CHeader(bool autoDelete = true);
    CHeader(const CHeader& header, bool autoDelete = true);
    virtual ~CHeader();

    //Adding/removing columns
    virtual bool      Add(CColumn* column);
    virtual bool      Remove(Common::FID fid);
    virtual void      RemoveAll();

    //Column count and fixed columns
    virtual long      GetColumnCount() const;
    virtual long      GetVisibleColumnCount() const;
    virtual void      SetFixedColumnsCount(int fixedColumnsCount);
    virtual int       GetFixedColumnsCount() const;
    virtual bool      IsFixed(Common::FID fid) const;

    //Visibility
    virtual bool      ShowColumn(Common::FID fid);
    virtual bool      HideColumn(Common::FID fid);

    //Column moving & sizing
    virtual bool      CanMoveFixedColumns() const;
    virtual bool      CanMoveScrollableColumns() const;
    virtual bool      CanResizeColumn() const;
    virtual void      AllowFixedColumnMove(bool enable);
    virtual void      AllowScrollableColumnMove(bool enable);
    virtual void      AllowColumnResize(bool enable);
    virtual bool      MoveBefore(Common::FID toMove, Common::FID before);
    virtual bool      MoveAfter(Common::FID toMove, Common::FID after);
    virtual bool      MoveToPosition(Common::FID toMove, int position);
    virtual bool      MoveToVisiblePosition(Common::FID toMove, int position);

    
    //Fid to index and vice versa
    virtual CColumn*  GetColumnByIndex(int index) const;
    virtual CColumn*  GetVisibleColumnByIndex(int index) const;
    virtual CColumn*  GetColumnByFid(Common::FID fid) const;
    virtual CColumn*  GetVisibleColumnByFid(Common::FID fid) const;
    virtual int       GetColumnIndex(Common::FID fid) const;
    virtual int       GetVisibleColumnIndex(Common::FID fid) const;
    
    virtual CColumn*  GetFirstColumn() const;
    virtual CColumn*  GetFirstVisibleColumn() const;
    virtual CColumn*  GetLastColumn() const;
    virtual CColumn*  GetLastVisibleColumn() const;


    //Position and dimensions
    virtual CColumn*  HitTest(const CGrid& grid, CPoint point) const;
    virtual CRect     GetVirtualRect(const CGrid& grid, Common::FID fid) const;
    virtual CRect     GetVisibleRect(const CGrid& grid, Common::FID fid) const;
    virtual int       GetHeaderHeight() const;
    virtual void      SetHeaderHeight(int height);
    virtual int       GetFixedColumnWidth() const;
    virtual int       GetScrollableColumnWidth() const;

    //Navigation column
    virtual void      SetNavigationColumn(int column);
    virtual int       GetNavigationColumn() const;

    //Hierarchical columns
    virtual const CColumn* GetHierarchicalColumn() const;
    virtual bool           SetHierarchicalColumn(Common::FID fid);


    ///Sort functions
    virtual void      AllowSort(bool enable);
    virtual bool      CanSort() const;
    virtual void      AllowMultiSort(bool enable);
    virtual bool      CanMultiSort() const;
    virtual void      SetSort(int level, CSortInfo sortInfo); 
    virtual CSortInfo GetSort(int level) const;
    virtual int       GetSortLevels() const;
    virtual void      ResetSort();

    //Font and images
    virtual CFont*      SetFont(CFont* font);
    virtual CFont*      GetFont() const;
    
    virtual CImageList* SetImageList(CImageList* imageList);
    virtual CImageList* GetImageList() const;


    //Notifications
    void                Subscribe(INotify* callBack);
    void                Unsubscribe(INotify* callBack);

    //Serialization
    virtual void        Serialize(CArchive& ar);
    static int          GetSerializeVersion();


    //IAutoDelete implementation.
    virtual bool      AutoDelete() const;

private:
    DECLARE_SERIAL(CHeader)

private:
    struct Impl;
    Impl* m_Impl;
};

}

}//namespace Dapfor
