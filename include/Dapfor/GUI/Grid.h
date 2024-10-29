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
#include <Dapfor/GUI/TooltipSettings.h>
#include <Dapfor/GUI/IEditInPlace.h>
#include <Dapfor/GUI/EditInPlaceSettings.h>
#include <Dapfor/GUI/HighlightSettings.h>
#include <Dapfor/GUI/EmbeddedControlParams.h>
#include <Dapfor/GUI/Appearance.h>
#include <Dapfor/GUI/BackgroundImage.h>
#include <Dapfor/GUI/DragDropSettings.h>
#include <Dapfor/GUI/CopyPasteSettings.h>
#include <Dapfor/GUI/PrintSettings.h>
#include <Dapfor/GUI/Header.h>
#include <Dapfor/GUI/SortInfo.h>

#include <vector>

//Forward declarations
class CImageList;

namespace Dapfor
{

namespace Common
{
class CDataObject;
class CValue;
}

namespace GUI
{
class CHeader;
class IGridFilter;
class ICustomDraw;
class ICopyPaste;
class IDragDrop;
class CDragSource;
class IKeyManager;
class CHighlightSettings;
class CColorBlend;
class ITooltip;
class ITooltipCtrl;
class IForEach;
class CColumn;
class CEmbeddedControlAdapter;

//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief This class implements full featured thread-safe hierarchical list control.
///
/// \par Introduction
///
/// The grid is intended for working with data of almost any type. Such data is the object of 
/// usual C++ classes with the set of Get- and Set- methods that can be called by their identifiers. 
/// These identifiers are declared together with a class. To be able to insert such objects 
/// into the grid, the class should inherit from Common::CDataObject which permits 
/// to call the function by its identifier. These objects are displayed in the grid by using the binding mechanism. 
/// The rows of the grid correspond to objects of your classes and columns to their functions.
///
/// The grid supports automatic updating, sorting, highlighting and filtration 
/// of the objects for each value modification. To benefit from this, it is recommended to implement 
/// Common::CDataOnject::ISink interface that can fire notifications to the grid.
///
/// The grid enables simultaneous use of objects of different classes. The only condition is that types 
/// of values returned by the functions should be the same. It is not so critical for 
/// data painting and highlighting but for sorting it is required to compare values of one type.
///
/// \par Purpose of contexts
///
/// The grid has two graphical contexts: fixed and scrollable. These contexts have been implemented
/// because it is not possible to set just a number of 'frozen' rows in the hierarchical grid. 
/// Indeed, the quantity of such rows is not constant and may vary depending on whether the children are expanded 
/// or collapsed. Furthermore, data objects can be automatically filtered in the IGridFilter interface.
///
///
/// \par Handles & lines in the grid
///
/// As mentioned above, the grid works with C++ objects. One data object can be inserted into 
/// one grid multiple times. Handles were organized for unique identification of object location in the grid. 
/// Handles take part in all grid operations. They also store information about hierarchy, selection, 
/// filtration, time of the last updating and so on. Sometimes a handle may be invisible on the screen. 
/// It can be filtered by IGridFilter interface or hidden by its parent. Such handle doesn't have a 
/// corresponding grid line. Handles can be easily detached from the grid with all hierarchy 
/// and inserted to any other point or grid.
///
///
/// \par Focus
///
/// Focus is designed to define the cursor location during navigation and lines selection in the grid. 
/// Grid may have only one focused line. As the grid can support multiple contexts,
/// the focused context is the context where the focused line is located.
///
///
/// \par Appearance
///
/// Grid appearance is stored in an object of CAppearance type. Data drawing operation gets all colors from this object. 
/// All painting information is passed through ICustomDraw interface where it can be freely redefined. 
///
/// \par Tooltips
///
/// A tooltip is designed to enhance application functionality for instances when information that must be 
/// provided to the user cannot be displayed entirely. 
/// Functionally the tooltip has two interfaces. The first interface is designed to 
/// manage a pop-up window, its color, location and so on. The second interface is designed to manage 
/// the content displayed in the window. GUI library provides two types of tooltips: 
/// - A tooltip that shows information in the small popup window as a plain text or an html text in the 
///   popup browser.
/// - Embedded tooltip. When a part of a text in a cell becomes invisible, the remaining text 
/// is automatically displayed in the tooltip above the cell with the same font.
///
/// \par Copy & paste
///
/// Copy & paste enables you to move data within one grid, between grids or between applications. 
/// The grid enables you to export data to such applications as Excel and Word. In addition to standard clipboard 
/// formats, GUI library has new formats that enable hierarchical information maintenance and also support moving data 
/// between different applications with data serialization where it is possible. The programmer 
/// can customize the copy & paste mechanism at any moment.
/// To control copy/paste process the grid provides ICopyPaste interface and its default 
/// implementation in CCopyPaste class.
///
/// \par Drag and Drop
///
/// The grid provides default Drag & drop implementation. It is possible to move selected lines inside one grid, 
/// between grids or between applications. Moreover, at any moment a programmer can customize drag & drop 
/// behavior for his own purposes. To indicate the dropping place, the grid illuminates the lines between which data 
/// will be inserted. However, it is not enough for hierarchical data because the hierarchy level remains 
/// unknown. Our grid can indicate this hierarchical level thus enabling you to clearly specify the 
/// user's wishes concerning data insertion to the desired position.
/// All drag and drop steps are conducted though IDragDrop interface where they can be totally redefined.
///
///
/// \par Sorting
///
/// This is one of automated services that greatly simplify programming and at the same 
/// time improve application quality. If data is updated (notification from Common::CDataObject::ISink 
/// interface or UpdateRow(), UpdateItem() or UpdateDataObject() functions call), the grid automatically searches 
/// a new position according to sorting and hierarchy rules. Information about sorting is stored in the header. 
/// If the header is changed, sorting is also updated. 
/// Sorting can be single and multiple on one or several grid columns. Single click with the left mouse button 
/// on the header column switches single sorting on. Second click inverts the sorting direction. 
/// Multiple sorting is possible with mouse click with Ctrl key pressed. 
/// The second click with Ctrl key held changes sorting direction in the column where the click was made. 
/// To cancel sorting it's enough to click on the header with the left mouse button while holding 
/// Shift key. Of course it is possible to control sorting by programming means.
///
///
/// \par Data filtration
///
/// The grid supports automated data filtration. A grid line is considered filtered if the 
/// operator () of IGridFilter interface returns true. 
/// If the line is filtered, neither the line nor its children can be visible. The visibility check 
/// is carried out at C++ object insertion, at its updating through 
/// Common::CDataObject::ISink interface, at UpdateRow(), UpdateItem() or UpdateDataObject() functions 
/// call and in some other cases.
/// 
///
/// \par Navigation and keyboard
///
/// All navigation management is placed in the external module that opens virtually unlimited possibilities 
/// to manage keyboard events. All navigation is collected in the implementation of 
/// IKeyManager interface. We offer the default implementation in the CKeyManager class. You can get an object of
/// this class by calling CPreferences::GetDefaultKeyManager().
/// 
/// \par Printing
///
/// The grid enables you to print its content on a printer and also has a 'print preview' option. 
/// There are various scaling levels and a possibility to choose either a portrait or a landscape mode.
///
/// \par Built in controls
///
/// Traditionally so called drawing of either control directly at the place of grid cells location is 
/// used to implement 'edit in place' possibilities. 
/// The controls themselves are created in the moment when 
/// the user clicks in a grid cell. Usually the range of such controls is rather limited and depends 
/// on grid developer. The necessity to use real controls or controls of outside developer scope may often arise.
/// In such case it is required to keep a track of control location, its movements, size and visibility changes 
/// according to scrollbar location, filtration, cell size, hierarchy position, etc. Implementation
/// of control positioning code is a difficult and laborious task for the programmer. To 
/// simplify development of the resulting application the grid provides a convenient service for positioning 
/// almost any controls above the grid. The programmer just needs to assign the cell to which a control 
/// has to be attached and specify some control settings. It is important to note that the grid doesn't 
/// manage control's life time. The programmer is fully responsible for creating and deleting 
/// controls. The grid only conducts control positioning relative to a grid cell.
///
///
/// \par Edit in place
///
/// The grid provides a very simple and useful positioning service for almost any MFC controls with navigation 
/// between them. In most cases buttons, check boxes, and other elements are not real controls but only images. 
/// Basically, such 'controls' are supplied together with grids and their number and functionality may be limited. 
/// Moreover, such approach does not allow the use of already existing solutions or third-party libraries. 
/// For real controls it is necessary to handle control location and size according to the number of elements in the grid and 
/// scrollbar positions, and also to manage their visibility (for filtration, expand/collapse and row 
/// deleting). This is not a trivial task and some difficulties may arise during its fulfillment. 
/// We offer the solution that enables you to attach almost any MFC control to any cell, and the grid handles 
/// the positioning and visibility of the controls itself.
///
///
/// \par Serialization
///
/// Serialization in CArchive is a useful grid feature. Position, column colors, user preferences and other items 
/// are serialized. The grid is designed in such a way that new grid versions are be compatible with 
/// archives made in previous versions. 
///
///
/// \par Thread safety
///
/// The grid was designed to work in a heavy multi-threaded environment. Almost all functions are thread-safe. 
/// They use both synchronous and asynchronous mechanisms with or without blocking the calling thread. 
/// Inserting, removing, getting etc. block the calling thread. Any data updating operations are processed via
/// the asynchronous mechanism. The calling thread does not wait for the end of updating operation. 
/// Many updating operations may occur at the same time. In this case the dead-lock between %GUI and non-%GUI threads is 
/// not possible.
///
/// To display information in cells, the grid needs to retrieve values from your business objects. There are 
/// two thread-safe modes to do it:
/// - CPreferences::DirectCall: The grid asks for values in the %GUI thread each time when it needs to paint 
///   cells or scroll lines. It is up to you to protect your business data (the grid is thread safe). 
///   This mode is more productive than the other one. It has low CPU loading and low memory consumption.
/// - CPreferences::MemoryBuffer: During each update the grid copies values and formats them in the calling thread 
/// and then no longer calls methods of your objects. The grid gets all information from the local cache. 
/// This mode is less productive but more secure.
/// 
/// \class CGrid Grid.h Dapfor/GUI/Grid.h
///
/// Read \ref DataObjectIntro "What is a data object?" article to get more information about binding.
///
/// The article \ref howtoinstall "How to install the MFC grid and compile the first application?" explains all 
/// steps of installing and compiling your first application.
///
/// \par Example:
///
/// How to create the grid:
/// \code
/// class CDemoView : public CView
/// {
///   ...
///      afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
///      afx_msg void OnSize(UINT nType, int cx, int cy);
///   private:
///      Dapfor::GUI::CGrid m_Grid;
/// };
///
/// int CDemoView::OnCreate(LPCREATESTRUCT lpCreateStruct)
/// {
///    ...
///    //Initialize the grid
///    m_Grid.Create(0, 0, WS_VISIBLE|WS_CHILD, CRect(), this, 1000);
///   
///    //Create a header:
///    Dapfor::GUI::CHeader* header = new Dapfor::GUI::CHeader(true);
///
///    //Add some columns to the header. Field identifiers should be the same as declared in the data object
///    //For more information see "How to install my first application"
///    header->Add(new Dapfor::GUI::CColumn(CDemoClass::FidPrice,  _T("Field1"), 190));
///
///    //Set the header to the grid     
///    m_Grid.SetHeader(header);
///
///    ...
///    return 0;
/// }
///
/// void CDemoView::OnSize(UINT nType, int cx, int cy) 
/// {
///     CMDIChildWnd::OnSize(nType, cx, cy);
///
///     //Fit the grid to the client's area
///     CRect rc;
///     GetClientRect(rc);
///     m_Grid.MoveWindow(rc);
/// }
///
///
/// //Declaration of some C++ class:
///  class CDemoClass : public Common::CDataObject
///  {
///  public:
///      enum 
///      {
///         FidPrice,
///      };
///      ...
///      double GetPrice() const;
///      ...
///  };
///
///  //This code adds C++ objects to the grid:
///  CDemoClass* obj = new CDemoClass();
///  m_Grid.Add(obj);
///
/// \endcode 
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CGrid : public CWnd
{
public:
    CGrid();
    virtual ~CGrid(void);

    // Addition, deleting, positioning, enumeration
    HITEM               Add(Common::CDataObject* pDO, HITEM hParent = GI_SCROLLABLE_ROOT, HITEM hInsertAfter = GI_LAST);
    bool                Delete(HITEM hItem);
    int                 Delete(const Common::CDataObject* pDO);
    bool                Delete(int nRow, ContextType contextType = ScrollableContext);
    void                DeleteAll(ContextType contextType = AllContexts);
    Handles             GetHandles(const Common::CDataObject* pDO, 
                                   bool                       visibleOnly, 
                                   ContextType                contextType = AllContexts) const;
    Handles             GetHandles(ContextType  contextType = AllContexts) const; // Get a copy of all handles, inserted into the grid
    


    bool                Attach(HITEM hItem, HITEM hParent, HITEM hInsertAfter = GI_LAST);
    bool                Detach(HITEM hItem);

    bool                Exists(HITEM hItem) const;
    bool                Exists(const Common::CDataObject* pDO) const;
    unsigned int        GetRowCount(ContextType contextType = ScrollableContext) const;
    void                ForEach(IForEach& functional, HITEM startFrom = GI_FIRST);
    void                ForEachVisible(IForEach& functional, HITEM startFrom = GI_FIRST);

    bool                MoveBefore(HITEM movingItem, HITEM parentPosition, HITEM position);
    bool                MoveAfter(HITEM movingItem, HITEM parentPosition, HITEM position);


    //Getting and setting formatted and non-formatted data
    Common::CValue      GetValue(HITEM hItem, Common::FID fid) const;
    bool                SetValue(HITEM hItem, Common::FID fid, const Common::CValue& value);
    TString             GetFormattedStlString(HITEM hItem, Common::FID fid, const Common::CFormat* format = 0) const;
    bool                SetFormattedStlString(HITEM hItem, Common::FID fid, const TString& str, const Common::CFormat* format = 0);

#ifndef DF_NOT_MFC
    CString             GetFormattedMfcString(HITEM hItem, Common::FID fid, const Common::CFormat* format = 0) const;
    bool                SetFormattedMfcString(HITEM hItem, Common::FID fid, const CString& str, const Common::CFormat* format = 0);
#endif//DF_NOT_MFC


    //Functions to work with hierarchy
    bool                IsExpanded(HITEM hItem) const;
    Handles             GetChildren(HITEM hItem, bool visibleOnly) const;
    bool                HasChildren(HITEM hItem) const;
    int                 GetHierarchicalLevel(HITEM hItem) const;
    HITEM               GetParent(HITEM hItem) const;
    void                Expand(HITEM hItem, bool withChildren);
    void                Expand(const Common::CDataObject* pDO, bool withChildren);
    void                Collapse(HITEM hItem, bool withChildren);
    void                Collapse(const Common::CDataObject* pDO, bool withChildren);
	void				ShowAlwaysPlusMinus(bool show);
	bool				IsPlusMinusAlwaysVisible() const;


    //Data objects and rows search in the grid
    int                 GetRow(HITEM hItem) const;
    int                 GetRow(const Common::CDataObject* pDO) const;
    ContextType         GetContextType(HITEM hItem) const;
    ContextType         GetContextType(const Common::CDataObject* pDO) const;
    HITEM               GetItem(int nRow, ContextType contextType = ScrollableContext) const;
    HITEM               GetItem(const Common::CDataObject* pDO) const;
    HITEM               GetItem(CPoint point) const;
    HITEM               GetPreviousItem(HITEM hItem, bool jumpBetweenContexts = true) const;
    HITEM               GetNextItem(HITEM hItem, bool jumpBetweenContexts = true) const;
    Common::CDataObject*       GetDataObject(HITEM hItem);
    const Common::CDataObject* GetDataObject(HITEM hItem) const;
    Common::CDataObject*       GetDataObject(int nRow, ContextType contextType = ScrollableContext);
    const Common::CDataObject* GetDataObject(int nRow, ContextType contextType = ScrollableContext) const;

    

    //Visibility, placement and bounds
    int                 GetFirstVisibleRow() const;
    int                 GetLastVisibleRow(ContextType contextType = ScrollableContext) const;
    
    void                SetFirstVisibleRow(int nRow);
    void                SetFirstVisibleItem(HITEM hItem);
    void                SetFirstVisibleItem(const Common::CDataObject* pDO);
    
    void                EnsureVisible(int nRow);
    void                EnsureVisible(HITEM hItem);
    void                EnsureVisible(const Common::CDataObject* pDO);
    
    bool                IsVisible(HITEM hItem) const;
    bool                IsVisible(const Common::CDataObject* pDO) const;
    
    bool                IsInVisibleRect(HITEM hItem);
    bool                IsInVisibleRect(const Common::CDataObject* pDO);
    bool                IsInVisibleRect(int nRow, ContextType contextType);

    CRect               GetContextVisibleRect(ContextType contextType) const;
    CRect               GetContextVirtualRect(ContextType contextType) const;
    
    CRect               GetLineVisibleRect(HITEM hItem) const;
    CRect               GetLineVisibleRect(const Common::CDataObject* pDO) const;
    
    CRect               GetLineVirtualRect(HITEM hItem) const;
    CRect               GetLineVirtualRect(const Common::CDataObject* pDO) const;
    
    CRect               GetCellVisibleRect(HITEM hItem, Common::FID fid) const;
    CRect               GetCellVisibleRect(const Common::CDataObject* pDO, Common::FID fid) const;
    
    CRect               GetCellVirtualRect(HITEM hItem, Common::FID fid) const;
    CRect               GetCellVirtualRect(const Common::CDataObject* pDO, Common::FID fid) const;

    int                 GetLinesPerPage(bool forward = true) const;
    int                 GetItemHeight(HITEM hItem) const;
    void                SetItemHeight(HITEM hItem, int height);


    //Selection
    void                AllowSelection(bool bEnable);
    bool                CanSelect() const;
    void                AllowMultiSelection(bool bEnable);
    bool                CanMultiSelect() const;
    void                AllowSelectContext(ContextType contextType = AllContexts);
    bool                CanSelectContext(ContextType contextType) const;
    int                 GetSelectedCount() const;
    bool                Select(int nRow, ContextType contextType, bool bSelect);
    bool                Select(HITEM hItem, bool bSelect);
    bool                Select(const Common::CDataObject* pDO, bool bSelect);
    Selection           GetSelection(ContextType contextType) const;
    bool                IsSelected(int nRow, ContextType contextType) const;
    bool                IsSelected(HITEM hItem) const;
    bool                IsSelected(const Common::CDataObject* pDO) const;
    void                SelectAll();
    void                ClearSelection();
    void                AllowMouseTrackSelection(bool bEnable);
    bool                CanMouseTrackSelection() const;
        
    //Focus
    void                AllowFocusContext(ContextType contextType = AllContexts);
    bool                CanFocusContext(ContextType contextType) const;
    bool                SetFocusedRow(int nRow, ContextType contextType);
    int                 GetFocusedRow() const;
    ContextType         GetFocusedContext() const;
    


    //Updating
    void                UpdateRow(int nRow, ContextType contextType, Common::FID fid);
    void                UpdateItem(HITEM hItem, Common::FID fid);
    void                UpdateDataObject(const Common::CDataObject* pDO, Common::FID fid);
    int                 GetTimeElapsedSinceLastUpdate(int nRow, ContextType contextType, Common::FID fid) const;
    int                 GetTimeElapsedSinceLastUpdate(HITEM hItem, Common::FID fid) const;
    
    void                InvalidateRow(int nRow, ContextType contextType, int spanTime = 0);
    void                InvalidateRow(HITEM hItem, int spanTime = 0);
    void                InvalidateRow(const Common::CDataObject* pDO, int spanTime = 0);

    void                InvalidateCell(int nRow, ContextType contextType, Common::FID fid, int spanTime = 0);
    void                InvalidateCell(HITEM hItem, Common::FID fid, int spanTime = 0);
    void                InvalidateCell(const Common::CDataObject* pDO, Common::FID fid, int spanTime = 0);


    //Notifications
    void                AllowNotifications(bool bAllow);
    bool                IsNotificationsAllowed() const;

    //////////////////////////////////////////////////////////
    //Appearance
    //////////////////////////////////////////////////////////
    CAppearance&        GetAppearance();
    const CAppearance&  GetAppearance() const;
    void                SetAppearance(const CAppearance& appearance);

    //Background images
    const CBackgroundImage& GetBackgroundImage() const;
    void                    SetBackgroundImage(const CBackgroundImage& settings);


    //Fonts
    void                SetFont(CFont* font, BOOL bRedraw = TRUE);
    CFont*              GetFont() const;


    //ImageList to draw images in cell
    CImageList*         SetImageList(CImageList* imageList, bool stretchImage = false);
    CImageList*         GetImageList() const;
    void                AllowStretchImageInCell(bool stretch);
    bool                CanStretchImageInCell() const;


    //Context separator
    void                AllowDrawContextSeparator(bool bDraw);
    bool                CanDrawContextSeparator() const;
    void                SetContextSeparatorHeight(int nHeight);
    int                 GetContextSeparatorHeight() const;

    //Highlighting
    void                      AllowHighlight(bool bAllow);
    bool                      CanHighlight() const;
    const CHighlightSettings& GetHighlightSettings() const;
    CHighlightSettings&       GetHighlightSettings();
    void                      SetHighlightSettings(const CHighlightSettings& settings);


    //Custom draw & painting
    ICustomDraw*        SetCustomDraw(ICustomDraw* customDraw);
    ICustomDraw*        GetCustomDraw() const;
    void                SetPaintFilter(UINT paintFilter = defaultPaintFilter);
    UINT                GetPaintFilter() const;
    void                SetFlickerFreeDrawing(bool enable);
    bool                GetFlickerFreeDrawing() const;
    int                 GetOptimalRowHeight(ContextType contextType) const;
	void                SetOptimalRowHeight(ContextType contextType, int height);
    int                 GetOptimalCellWidth(int nRow, ContextType contextType, Common::FID fid) const;
    int                 GetOptimalColumnWidth( ContextType contextType, Common::FID fid) const;
    

    // Headers
    CHeader*            SetHeader(CHeader* newHeader);
    CHeader*            GetHeader();
    const CHeader*      GetHeader() const;
    void                ShowHeader();
    void                HideHeader();
    bool                IsHeaderVisible() const;
    virtual void        ShowHeaderDialog();
    const CColumn*      GetColumn(CPoint pt) const;
    const CColumn*      GetNavigationColumn() const ;
    const CColumn*      GetHierarchicalColumn() const ;


    void                AdjustColumnByFid(Common::FID fid);
    void                AdjustColumnByIndex(int index);
    void                AdjustAllColumns();
    int                 GetOptimalHeaderHeight() const;
    void                EnsureColumnVisible(Common::FID fid);


    // Tooltips
    void                    EnableTooltip(bool enable = true);
    bool                    IsTooltipEnabled() const;
    const ITooltipCtrl*     GetTooltipCtrl();
    ITooltipCtrl*           SetTooltipCtrl(ITooltipCtrl* control);
    const ITooltip*         GetTooltip() const;
    ITooltip*               SetTooltip(ITooltip* tooltip);
    const CTooltipSettings& GetTooltipSettings() const;
    CTooltipSettings&       GetTooltipSettings();
    void                    SetTooltipSettings(const CTooltipSettings& settings);

    //Displays partially visible text of small cells
    void                    EnableInPlaceTooltip(bool bEnable = true);
    bool                    IsInPlaceTooltipEnabled() const;
    CTooltipSettings&       GetInPlaceTooltipSettings();
    void                    SetInPlaceTooltipSettings(const CTooltipSettings& settings);
    const ITooltipCtrl*     GetInPlaceTooltipCtrl() const;
    ITooltipCtrl*           SetInPlaceTooltipCtrl(ITooltipCtrl* control);


    //Copy/cut/paste
    bool                      Copy();
    bool                      Cut();
    bool                      Paste();
    bool                      Paste(HITEM hParent, HITEM hInsertAfter);
    ICopyPaste*               SetCopyPaste(ICopyPaste* copyPaste);
    ICopyPaste*               GetCopyPaste() const;
    
    const CCopyPasteSettings& GetCopyPasteSettings() const;
    CCopyPasteSettings&       GetCopyPasteSettings();
    void                      SetCopyPasteSettings(const CCopyPasteSettings& settings);
    
    void                      AllowCopyPaste(bool bAllow);
    bool                      IsCopyPasteAllowed() const;


    //Drag & drop
    IDragDrop*               SetDragDrop(IDragDrop* dragDrop);
    IDragDrop*               GetDragDrop() const;
    const CDragDropSettings& GetDragDropSettings() const;
    CDragDropSettings&       GetDragDropSettings();
    void                     SetDragDropSettings(const CDragDropSettings& settings);
    void                     AllowDragAndDrop(bool bAllow);
    bool                     IsDragAndDropAllowed() const;
    CDragImage               CreateDragImage(const Handles& handles, ContextType contextType, const CHeader* header) const;

    
    //Sorting
    void                AllowSort(bool bEnable);
    bool                CanSort() const;
    void                AllowMultiSort(bool bEnable);
    bool                CanMultiSort() const;
    void                SetSortedContext(ContextType contextType = AllContexts);
    ContextType         GetSortedContext() const;
    void                ResetSort( bool redraw = true );
    void                SetSort(int level, CSortInfo sortInfo, bool applyImmediatelly = true);
    CSortInfo           GetSort(int level) const;
    void                UpdateSort();
    int                 GetSortLevels() const;

    
    //Data filtration
    IGridFilter*        SetFilter(IGridFilter* filter);
    IGridFilter*        GetFilter() const;
    void                UpdateFilter();


    
    //Keyboard management
    IKeyManager*        SetKeyManager(IKeyManager* keyManager);
    IKeyManager*        GetKeyManager() const;


    //Navigation
    void                AllowNavigation(ContextType contextType = AllContexts);
    bool                CanNavigate(ContextType contextType) const;
    void                NavigateUp(bool bShift, bool bCtrl);
    void                NavigateDown(bool bShift, bool bCtrl);
    void                NavigatePageUp(bool bShift, bool bCtrl);
    void                NavigatePageDown(bool bShift, bool bCtrl);
    void                NavigateHome(bool bShift, bool bCtrl);
    void                NavigateEnd(bool bShift, bool bCtrl);

    void                ResetScroll();
    

    // Printing operations
    void                PrintPreview(const CPrintSettings& settings);
    void                Print(const CPrintSettings& settings, CPrintInfo* printInfo = 0);




    //Embedded controls
    CEmbeddedControlAdapter* AttachControl(CWnd* control, HITEM hItem, Common::FID fid, const CEmbeddedControlParams& params = CEmbeddedControlParams());
    bool                     DetachControl(CWnd* control);
    bool                     DetachControl(HITEM hItem, Common::FID fid, bool bDestroy);
    bool                     HasControl(HITEM hItem, Common::FID fid) const;
    bool                     HasControl(int nRow, ContextType contextType, Common::FID fid) const;

    
    //Edit in place
    IEditInPlace*               SetEditInPlace(IEditInPlace* editInPlace);
    IEditInPlace*               GetEditInPlace() const;
    bool                        CanStartEditInPlace(HITEM hItem, Common::FID fid, IEditInPlace::StartReason reason) const;
    bool                        StartEditInPlace(HITEM hItem, Common::FID fid, IEditInPlace::StartReason reason = IEditInPlace::ActivateOnUserStart);
    bool                        StopEditInPlace(IEditInPlace::StopReason reason, bool postMessage = false);
    CWnd*                       GetEditInPlaceControl() const;
    const CEditInPlaceSettings& GetEditInPlaceSettings() const;
    CEditInPlaceSettings&       GetEditInPlaceSettings();
    void                        SetEditInPlaceSettings(const CEditInPlaceSettings& settings);

    //Serialization
    virtual void Serialize(CArchive& ar);
    static int   GetSerializeVertion();

protected:
    //{{AFX_MSG(CGrid)
    afx_msg int     OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void    OnDestroy();
    afx_msg void    OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    afx_msg void    OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    afx_msg LPARAM  OnDispatchTSMessage(WPARAM wParam, LPARAM lParam);
    afx_msg void    OnPaint();
    afx_msg BOOL    OnEraseBkgnd(CDC* pDC);
    afx_msg void    OnSize(UINT nType, int cx, int cy);
    afx_msg void    OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void    OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg BOOL    OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
    afx_msg void    OnTimer(DF_ON_TIMER_TYPE id);
    afx_msg LRESULT OnSetFont(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnGetFont(WPARAM wParam, LPARAM lParam);
    //}}AFX_MSG

    //{{AFX_VIRTUAL(CGrid)
    virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
    virtual BOOL    OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
    virtual BOOL    PreCreateWindow(CREATESTRUCT& cs);
    virtual void    PreSubclassWindow();
    virtual BOOL    PreTranslateMessage(MSG* pMsg);
    //}}AFX_VIRTUAL

private:
    DECLARE_MESSAGE_MAP()
    DECLARE_SERIAL(CGrid)

    class CGridImpl; 

private:
    CGrid(const CGrid&);
    CGrid& operator = (const CGrid&);
    CGridImpl* m_Impl;
};

}//namespace GUI

}//namespace Dapfor

