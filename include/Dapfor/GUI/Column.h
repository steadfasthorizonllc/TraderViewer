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

//Forward declarations
namespace Common
{
    class CFormat;
}

namespace GUI
{

class ICellPaintFormat;
class IColumnPaintFormat;

//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief This class implements a column of the header
///
/// This class contains the necessary data for displaying columns in the grid. 
/// The grid works with C++ objects of almost any class. The only condition is that these 
/// classes should inherit from Common::CDataObject. The basic application of the given interface is to give 
/// the opportunity of receiving as unformatted so formatted values through data fields identifiers. 
/// Unformatted data consists of values of basic types (long, double...) returned by data object functions. 
/// These functions can be called through integer identifiers, and then the received unformatted value can be 
/// converted into a string and displayed in the corresponding grid cell. 
/// Each column contains an identifier, and if it corresponds to a data object field identifier, value of this field 
/// is displayed in a grid  cell via a system of formats. As mentioned above, data objects usually return an
/// unformatted value that cannot be displayed directly on the screen. The way of displaying depends on text format 
/// that converts the value into a string. The type of chosen format is defined by the following: 
/// First the format is searched in a grid column. If it is not found, the search occurs in the data fields table 
/// (Common::CFieldMap) of the corresponding object and if the format is still not found, the default format returned by 
/// Common::CFormat::GetDefaultFormat() function is used. A class object of a column contains such parameters as column width,
/// alignment of a text including an automatically defined one, depending on a field type, 
/// indexes of pictures for grid cells and for a header. A column can store graphic formats for an individual portrayal 
/// of cells within the bounds of a column, and also in a header. 
///
/// It's also possible to organize a subscription for receiving notifications from CColumn class object. 
/// When internal data changes occur, all subscribers recieve notifications. When a column is inserted to a header, 
/// there is an automatic subscription to events that are later transfered in the grid. This way, when
/// class Set-methods of a column is called, the grid updates screen contents in the appropriate way. 
///
/// It is also important to note, that almost all the functions of CColumn class are thread-safe and can be called 
/// from any thread. All events are sent in such a way that during sending such synchronizing objects 
/// as critical section or mutex are not occupied.
///
/// \version <b>2.1.0</b> Added ability to align images in cells
///
/// \class  CColumn Column.h Dapfor/GUI/Column.h
/// \file Column.h
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CColumn : public CObject
{
public:
    ///Text alignment
    enum Alignment
    {
        Auto,       //!< alignment depends on field type (long, string, double, etc...)
        Left,       //!< text is aligned to the left of the cell
        Right,      //!< text is aligned to the right of the cell
        Center,     //!< text is aligned in the center of the cell
    };

    ///Image alignment
    enum ImageAlignment
    {
        ImageLeft,      //!< image is shown to the left of the cell.
        ImageRight,     //!< image is shown to the right of the cell. 
        ImageCenter,    //!< image is shown in the center of the cell and over the text. 
    };

    
    /// Notification type
    enum NotificationType
    {
        NameChanged,             //!< Name of the column is changed
        WidthChanged,            //!< Width of the column is changed
        AlignmentChanged,        //!< Alignment type is changed
        DescriptionChanged,      //!< Column description is changed
        CellPaintFormatChanged,  //!< Cell painting format is changed
        ColumnPaintFormatChanged,//!< Column painting format is changed
        TextFormatChanged,       //!< Text format that converts non-formatted data to strings is changed
        CellImageChanged,        //!< Image list or index of the icon drawn in the cell is changed
        ColumnImageChanged,      //!< Image list or index of the icon drawn in the column is changed
        VisibleChanged,          //!< Visibility of the column is changed
        EditableChanged,         //!< Editable flag is changed

        ColumnDelete,            //!< Is sent in the destructor of CColumn object
    }; 

    /// Interface for receiving notifications about column state modification
    struct INotify
    {
        virtual void OnColumnModified(const CColumn* column, NotificationType type) = 0;
    };

public:
    // Constructors & destructors
    CColumn(Common::FID            fid, 
            const TString&              name, 
            int                         width, 
            Alignment                   alignment = Auto, 
            bool                        editable = false,
            int                         cellImageId = -1,
            int                         columnImageId = -1,
            const Common::CFormat* textFormat = 0, 
            const ICellPaintFormat*     cellPaintFormat = 0, 
            const IColumnPaintFormat*   columnPaintFormat = 0, 
            const TString&              description = _T(""));

    CColumn(const CColumn& column);
    virtual ~CColumn();

    //Get- methods

    Common::FID                 GetFid() const;              //!< Gets field identifier
    const TString&              GetName() const;             //!< Gets a column name
    int                         GetWidth() const;            //!< Gets a column width
    Alignment                   GetAlignment() const;        //!< Gets text alignment 
    bool                        IsEditable() const;          //!< Indicates whether cells belonging to this column can be editable.
    bool                        IsVisible() const;           //!< Indicates whether the column is visible.
    int                         GetCellImageId() const;      //!< Gets Zero-based index of the image to draw an icon in the cell.
    int                         GetColumnImageId() const;    //!< Gets Zero-based index of the image to draw an icon in the column. 
    const Common::CFormat*      GetTextFormat() const;       //!< Gets custom textual format to convert the non-formatted value to the formatted string
    const ICellPaintFormat*     GetCellPaintFormat() const;  //!< Gets the format to draw the cells belonged to this column.
    const IColumnPaintFormat*   GetColumnPaintFormat() const;//!< Gets custom format to draw this column.
    TString                     GetDescription() const;      //!< Gets the column description
    ImageAlignment              GetImageAlignement() const;  //!< Gets image alignment in cells

    
    //Set- methods
    void                        SetName(const TString& name);                     //!< Sets a new column name
    bool                        SetWidth(int columnWidth);                        //!< Sets a new column width
    void                        SetAlignment(Alignment alignment);                //!< Sets a new text alignment 
    void                        SetEditable(bool bEditable);                      //!< Allows cells to be editable
    void                        SetVisible(bool bVisible);                        //!< Shows or hides a column
    void                        SetCellImageId(int imageId);                      //!< Sets a new zero-based index of the image to draw an icon in the cell.
    void                        SetColumnImageId(int imageId);                    //!< Sets a new zero-based index of the image to draw an icon in the column. 
    const Common::CFormat*      SetTextFormat(const Common::CFormat* format);//!< Sets a new textual format to convert the non-formatted value to the formatted string
    const ICellPaintFormat*     SetCellPaintFormat(const ICellPaintFormat* cellPaintFormat);      //!< Sets a new format to draw the cells belonged to this column.
    const IColumnPaintFormat*   SetColumnPaintFormat(const IColumnPaintFormat* columnPaintFormat);//!< Sets a new format to draw this column.
    void                        SetDescription(const TString& description);       //!< Sets a new column description
    void                        SetImageAlignement(ImageAlignment alignment);      //!< Sets a new image alignment in cells

    //Subscription to events
    void                        Subscribe(INotify* callBack);  //!< Subscribes to events 
    void                        Unsubscribe(INotify* callBack);//!< Unsubscribes from events 

    //Serialization
    virtual void                Serialize(CArchive& ar);       //!< Serializes or deserializes data to/from the archive 
    static int                  GetSerializeVersion();         //!< Current serialization version.

    CColumn& operator = (const CColumn&);

protected:
    CColumn();

    /// Sends specified notification to all subscribers
    void                        Notify(NotificationType type);

private:
    DECLARE_SERIAL(CColumn)

private:
    struct Impl;
    Impl* m_Impl;
};


}

}//namespace Dapfor

