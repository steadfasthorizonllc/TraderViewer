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
/// \brief Print settings
///
/// \version <b>1.0.0.0</b> Initial version
/// 
/// \class  CPrintSettings PrintSettings.h Dapfor/GUI/PrintSettings.h
/// \file PrintSettings.h
//////////////////////////////////////////////////////////////////////////////////////////////
class DF_GUI_API CPrintSettings
{
public:
    CPrintSettings();                               //!< Constructor
    CPrintSettings(const CPrintSettings& settings); //!< Copy constructor
    ~CPrintSettings();                              //!< Destructor

    void    SetPrintHeader(bool enable);            //!< Enables grid header printing
    void    SetRepeatHeader(bool enable);           //!< Enables grid header printing on every page
    void    SetPrintFixedRows(bool enable);         //!< Enables printing of the grid's fixed context
    void    SetPrintScrollableRows(bool enable);    //!< Enables printing of the grid's scrollable context
    void    SetZoomFactor(double zoom);             //!< Sets a new zoom factor
    void    SetTopMargin(int margin);               //!< Sets a new margin in millemeters from the top of a page
    void    SetBottomMargin(int margin);            //!< Sets a new margin in millemeters from the bottom of a page
    void    SetLeftMargin(int margin);              //!< Sets a new margin in millemeters from the left of a page
    void    SetRightMargin(int margin);             //!< Sets a new margin in millemeters from the right of a page

    bool    GetPrintHeader() const;                 //!< Gets the value indicating whether the a grid's header can be printed
    bool    GetRepeatHeader() const;                //!< Indicates whether grid's header can be repeated on every page
    bool    GetPrintFixedRows() const;              //!< Indicates whether the grid can print its fixed content
    bool    GetPrintScrollableRows() const;         //!< Indicates whether the grid can print its scrollable content
    double  GetZoomFactor() const;                  //!< Gets a zoom factor
    int     GetTopMargin() const;                   //!< Gets a margin in millemeters from a top of the page
    int     GetBottomMargin() const;                //!< Gets a margin in millemeters from a bottom of the page
    int     GetLeftMargin() const;                  //!< Gets a margin in millemeters from a left of the page
    int     GetRightMargin() const;                 //!< Gets a margin in millemeters from a right of the page
    

    ///Operator =
    CPrintSettings& operator = (const CPrintSettings& settings);
private:

    struct Impl;
    Impl* m_Impl;

};




}

}//namespace Dapfor
