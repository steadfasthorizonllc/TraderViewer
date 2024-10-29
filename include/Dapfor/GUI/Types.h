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

#pragma warning(disable : 4786) //the identifier was truncated to '255' characters in the debug information

#include <Dapfor/Common/Types.h>
#include <Dapfor/GUI/Types.h>
#include <Dapfor/GUI/GUI_Export.h>
#include <vector>

//////////////////////////////////////////////////////////////////////////
//Forward declarations


class CImageList;

//The void OnTimer() method is defined differently in VC6 and VC8, VC9...
#if (_MSC_VER >= 1400) //VC8, VC9...
    #define DF_ON_TIMER_TYPE UINT_PTR
    #define DF_DOMODAL_TYPE INT_PTR
#else //VC6
    #define DF_ON_TIMER_TYPE UINT
    #define DF_DOMODAL_TYPE int
#endif 


namespace Dapfor
{

    namespace Common
    {
        class CDataObject;
    }//namespace Common


    namespace GUI
    {

        typedef Common::TString TString;   //!< wide STL string


        class CGridItem;
        typedef class CGridItem FAR* HITEM;


        typedef std::vector<HITEM>  Handles;
        typedef Handles             Selection;


        //Pseudo items
        const HITEM GI_SCROLLABLE_ROOT  = ((HITEM)(__int64)0xFFFF0000);  //!< Root item of the scrollable context
        const HITEM GI_FIXED_ROOT       = ((HITEM)(__int64)0xFFFF0001);  //!< Root item of the non-scrollable context
        const HITEM GI_FIRST            = ((HITEM)(__int64)0xFFFF0002);  //!< The first item 
        const HITEM GI_LAST             = ((HITEM)(__int64)0xFFFF0003);  //!< The last item 



        /// Type of the context
        enum ContextType
        {
            ///Undefined context. 
            UndefinedContext    = 0x00,

            /// Non-scrollable context.
            FixedContext        = 0x01, 

            /// Scrollable context.
            ScrollableContext   = 0x02, 

            /// Both fixed and scrollable contexts
            AllContexts         = FixedContext | ScrollableContext,
        };




        //Paint 
        enum PaintFilter    
        {
            drawNothing                     = 0x00,     //!< Draws nothing
            drawText                        = 0x01,     //!< Draws text in the grid
            drawImage                       = 0x02,     //!< Draws image in a cell
            drawHeaderImage                 = 0x04,     //!< Draws image in a column
            drawBackground                  = 0x08,     //!< Draws grid background
            drawSelection                   = 0x10,     //!< Blends selection with foreground and background colors for selected lines.
            drawSelectionFrame              = 0x20,     //!< Draws a frame around selected lines
            drawColumnSort                  = 0x40,     //!< Blends column sorting with foreground and background colors.
            drawMouseTrackSelection         = 0x80,     //!< Draws an area, selected by mouse with pressed left button
            drawFocusedRow                  = 0x100,    //!< Blends focus with foreground and background colors for selected lines.
            drawFocusedRowFrame             = 0x200,    //!< Draws a frame around the focused line
            drawHighlight                   = 0x400,    //!< Draws highlighting
            drawDropPosition                = 0x800,    //!< Draws indicators helping to drop a clipboard content
            drawDropParentPosition          = 0x1000,   //!< Draws an indicator helping to select a hierarchical level during drop operation
            drawHierarchy                   = 0x2000,   //!< Draws a hierarchy. Each child is shifted relatively to its parent
            drawCollapseExpandIcon          = 0x4000,   //!< Draws collapse/expand icons
            drawHierarchicalLines           = 0x8000,   //!< Draws hierarchical lines
            drawHorizontalLines             = 0x10000,  //!< Draws horizontal lines between lines
            drawVerticalLines               = 0x20000,  //!< Draws vertical lines between columns
            drawEmbeddedControlBackground   = 0x40000,  //!< Forces an embedded MFC control to blend its background color with one of the cell


            drawEverything  = drawText | drawImage | drawHeaderImage| drawBackground |  //Text, Image & background
            drawSelection | drawSelectionFrame |                                        //Selection
            drawMouseTrackSelection |                                                   //Mouse track selection
            drawFocusedRow | drawFocusedRowFrame |                                      //Focus
            drawColumnSort |                                                            //Column sorting
            drawHighlight |                                                             //Highlighting
            drawDropPosition | drawDropParentPosition |                                 //Drag & drop
            drawHierarchy |drawCollapseExpandIcon | drawHierarchicalLines |             //Hierarchy
            drawHorizontalLines | drawVerticalLines |                                   //Vertical & horizontal lines
            drawEmbeddedControlBackground |
            drawHorizontalLines | drawVerticalLines,                                    //Vertical & horizontal lines


            defaultPaintFilter = drawEverything,
        };


        //////////////////////////////////////////////////////////////////////////
        /// Image for drag and drop operations
        struct CDragImage
        {
            CDragImage() : m_ImageList(0), m_XOffset(0), m_YOffset(0) {}

            CImageList* m_ImageList;//!< Pointer to the image
            int         m_XOffset;  //!< Distance between the left position of the bitmap and the x-position of the cursor.
            int         m_YOffset;  //!< Distance between the top position of the bitmap and the y-position of the cursor.
        };




        /// GUI constants
        ///
        enum GUIConstants
        {
            MaxSortColumns = 5,         //!< maximum count of sorted columns
        };



        //Sort information
        class CSortInfo;

        /// Contains information about all sort levels.
        typedef std::vector<CSortInfo> SortContainer;


        struct DF_GUI_API ProductInfo
        {
            static CString GetVersion();
            static CString GetProductName();
            static CString GetCompanyName();
            static CString GetCopyright();
        };

    }//namespace GUI

}//namespace Dapfor

