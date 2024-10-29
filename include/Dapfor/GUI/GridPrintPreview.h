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

class CGrid;
class CPrintSettings;

//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Print preview dialog
///
/// It is intended for displaying grid contents in the way they are printed. 
/// This dialogue enables visual display of up to three pages with grid contents and
/// size customization. Grid contents can also be scaled while 
/// being displayed on the printer. It is possible to set scale by means of PrinterZoom enumeration 
/// or by directly calling SetPrinterZoom() function with transfering it  double type parameter. 
/// When the given parameter equals 1, scaling is not applied. Besides, the dialogue gives 
/// the opportunity of adjusting the printer before printing, choosing paper type and image type 
/// and can also be used to start printing.
/// 
/// \class  CGridPrintPreview GridPrintPreview.h Dapfor/GUI/GridPrintPreview.h
/// \file GridPrintPreview.h
//////////////////////////////////////////////////////////////////////////////////////////////
class CGridPrintPreview : public CDialog
{
public:

    /// 
    enum ScreenZoom
    {
        OnePage,
        TwoPages,
        ThreePages,
        Zoom33,
        Zoom50,
        Zoom75,
        Zoom100,
        Zoom150,
        Zoom200,
        Zoom400,
    };

    enum PrinterZoom
    {
        PrinterZoomAuto,
        PrinterZoom10,
        PrinterZoom25,
        PrinterZoom50,
        PrinterZoom75,
        PrinterZoom100,
        PrinterZoom150,
        PrinterZoom200,
        PrinterZoom500,
    };

public:
    /// Constructor
    CGridPrintPreview(CGrid& grid, const CPrintSettings& settings, CPrintInfo* printInfo = 0, bool destroyOnClose = true);
    virtual ~CGridPrintPreview();               //!< Virtual destructor
    
    bool       CreatePrintPreview(CWnd* parent);//!< Initializes a dialog
    int        GetPagesCount();                 //!< Total pages to be printed
    void       Print();                         //!< Prints grid contents
    void       PrintSetup();                    //!< Opens a printer setup dialog
    void       Close();                         //!< Closes a current dialog

    ScreenZoom GetScreenZoom() const;           //!< Gets a current screen zoom
    void       SetScreenZoom(ScreenZoom zoom);  //!< Sets a new screen zoom

    double     GetPrinterZoom() const;          //!< Gets a printer zoom
    void       SetPrinterZoom(double zoom);     //!< Sets a new printer zoom
    void       SetPrinterZoom(PrinterZoom zoom);//!< Sets a new printer zoom, where the value is one of PrinterZoom enumeration

    CGrid&     GetGrid();                       //!< Gets the grid

protected:
    //{{AFX_MSG(CGridPrintPreview)
    afx_msg int     OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void    OnSize(UINT nType, int cx, int cy);
    afx_msg void    OnPaint();
    afx_msg BOOL    OnEraseBkgnd(CDC* pDC);
    afx_msg void    OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    afx_msg void    OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    afx_msg void    OnClose();
    //}}AFX_MSG


    DECLARE_MESSAGE_MAP()
private:
    CGridPrintPreview(const CGridPrintPreview&);
    CGridPrintPreview& operator = (const CGridPrintPreview&);

    struct Impl;
    Impl* m_Impl;

};

}//namespace GUI

}//namespace Dapfor
