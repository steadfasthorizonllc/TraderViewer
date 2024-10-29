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
//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Tooltip settings
///
/// \version <b>1.0.0.0</b> Initial version
/// 
/// \class  CTooltipSettings TooltipSettings.h Dapfor/GUI/TooltipSettings.h
/// \file TooltipSettings.h
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CTooltipSettings
{
public:
    ///Location relative to the cell where the tooltip should be displayed.
    enum Position
    {
        Top,        //!< on the top from the cell
        Bottom,     //!< on the bottom from the cell
        Left,       //!< on the left from the cell
        Right,      //!< on the right from the cell
    };

    ///Displaying mode
    enum Mode
    {
        Always,     //!< Always on the grid
        AutoPop,    //!< Is displayed when the mouse stays untouched on the cell for a specified amount of time.

        Default = AutoPop,

    } ;

public:
    //Constructors & destructor
    CTooltipSettings();
    CTooltipSettings(const CTooltipSettings& settings);
    ~CTooltipSettings();

    COLORREF GetBackColor() const;          //!< Gets a background color  
    COLORREF GetTextColor() const;          //!< Gets a text color    
    COLORREF GetBorderColor() const;        //!< Gets a color of the tooltip border
    int      GetDelay() const ;             //!< Gets delay in milliseconds for displaying the tooltip.
    int      GetDisappearDelay() const;     //!< Gets delay in milliseconds for withdrawing the tooltip.
    CSize    GetToolTipOffset() const;      //!< Gets the distance in pixels between the tooltip and a cell
    CSize    GetTextMargin() const;         //!< Gets an offset in pixels to display text inside of the tooltip
    Position GetPosition() const;           //!< Gets a position of the tooltip related to a cell
    Mode     GetMode() const;               //!< Gets a tooltip displaying mode
    
    void     SetBackColor(COLORREF color);  //!< Sets a new background color
    void     SetTextColor(COLORREF color);  //!< Sets a new text color
    void     SetBorderColor(COLORREF color);//!< Sets a new color of the border around the tooltip
    void     SetDelay(int span);            //!< Sets a new delay in milliseconds for displaying the tooltip.
    void     SetDisappearDelay(int span);   //!< Sets a new delay in milliseconds for withdrawing the tooltip.
    void     SetToolTipOffset(CSize sz);    //!< Sets a new distance in pixels between the tooltip and a cell
    void     SetTextMargin(CSize margin);   //!< Sets a new offset in pixels to display a text inside of the tooltip
    void     SetPosition(Position position);//!< Sets a new position of the tooltip related to a cell
    void     SetMode(Mode mode);            //!< Sets a new tooltip displaying mode

    static int GetSerializeVertion();       //!< Gets a serialization version
    void       Serialize(CArchive& ar);     //!< Serializes/deserializes data to/from the archive.

    ///Operator =
    CTooltipSettings& operator = (const CTooltipSettings& settings);

private:
    //Point implementation interface
    struct Impl;
    Impl* m_Impl;
};

}

}
