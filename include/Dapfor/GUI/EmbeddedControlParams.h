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

namespace Dapfor
{
namespace GUI
{

//////////////////////////////////////////////////////////////////////////
/// \brief Parameters indicating how MFC control is attached to CGrid
/// 
/// \version <b>2.0.0</b> Initial version
///
/// \class  CEmbeddedControlParams EmbeddedControlParams.h Dapfor/GUI/EmbeddedControlParams.h
/// \file EmbeddedControlParams.h
//////////////////////////////////////////////////////////////////////////
class DF_GUI_API CEmbeddedControlParams
{
public:
    ///Indicates cell side, to which MFC control is attached
    enum Anchor
    {
        /// CGrid doesn't modify a size of the control. 
        /// The control is attached to the top left corner of the cell with the offset, 
        /// specified in the constructor.
        none    = 0x0,  

        /// The control is attached to the left of the cell
        left    = 0x1,  
        
        /// The control is attached to the top of the cell
        top     = 0x2,  
        
        /// The control is attached to the right of the cell
        right   = 0x4,  
        
        /// The control is attached to the bottom of the cell
        bottom  = 0x8,  
        
        /// The control is attached to all sides of the cell. In this case CGrid automatically changes 
        /// control size to fit to the cell bounds.
        all = left | top | right | bottom, 
    };
    
public:
    //Constructors
    CEmbeddedControlParams();
    CEmbeddedControlParams(const CEmbeddedControlParams& params);
    CEmbeddedControlParams(UINT anchor,             
                           int leftOffset,          
                           int topOffset,           
                           int rightOffset,         
                           int bottomOffset,        
                           bool invalidateControl); 
    

    inline UINT GetAnchor() const;              //!< Determines how MFC control is attached to a cell.
    inline int  GetLeftOffset() const;          //!< An offset at the left side of a cell.
    inline int  GetTopOffset() const;           //!< An offset at the top side of a cell.
    inline int  GetRightOffset() const;         //!< An offset at the right side of a cell.
    inline int  GetBottomOffset() const;        //!< An offset at the bottom side of a cell.
    inline bool GetInvalidateControl() const;   //!< Indicates that CGrid can invalidate MFC control when the field of the data object is modified.

    inline void SetAnchor(UINT anchor);                      //!< Sets a new position of MFC control relative to a cell
    inline void SetLeftOffset(int offset);                   //!< Sets a new offset from the left side of a cell.
    inline void SetTopOffset(int offset);                    //!< Sets a new offset from the top side of a cell.
    inline void SetRightOffset(int offset);                  //!< Sets a new offset from the right side of a cell.
    inline void SetBottomOffset(int offset);                 //!< Sets a new offset from the bottom side of a cell.
    inline void SetInvalidateControl(bool invalidateControl);//!< Enables CGrid to invalidate MFC control when the field of the data object is modified.

private:
    UINT    m_Anchor;
    int     m_LeftOffset;
    int     m_TopOffset;
    int     m_RightOffset;
    int     m_BottomOffset;
    bool    m_InvalidateControl;
};


//Inline functions
inline UINT CEmbeddedControlParams::GetAnchor() const           {return m_Anchor;}
inline int  CEmbeddedControlParams::GetLeftOffset() const       {return m_LeftOffset;}
inline int  CEmbeddedControlParams::GetTopOffset() const        {return m_TopOffset;}
inline int  CEmbeddedControlParams::GetRightOffset() const      {return m_RightOffset;}
inline int  CEmbeddedControlParams::GetBottomOffset() const     {return m_BottomOffset;}
inline bool CEmbeddedControlParams::GetInvalidateControl() const{return m_InvalidateControl;}

inline void CEmbeddedControlParams::SetAnchor(UINT anchor)      {m_Anchor = anchor;}
inline void CEmbeddedControlParams::SetLeftOffset(int offset)   {m_LeftOffset = offset;}
inline void CEmbeddedControlParams::SetTopOffset(int offset)    {m_TopOffset = offset;}
inline void CEmbeddedControlParams::SetRightOffset(int offset)  {m_RightOffset = offset;}
inline void CEmbeddedControlParams::SetBottomOffset(int offset) {m_BottomOffset = offset;}
inline void CEmbeddedControlParams::SetInvalidateControl(bool invalidateControl){m_InvalidateControl = invalidateControl;}


}

}//namespace Dapfor

