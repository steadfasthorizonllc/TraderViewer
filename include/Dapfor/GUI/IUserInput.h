/////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2007-2010 Dapfor
//                                                                         
// This file is part of the Dapfor software, and may only be used, modified, and distributed 
// under the terms of the Dapfor LICENSE AGREEMENT FOR MFC GRID SOFTWARE.
// (See accompanying file lisense.txt or open the license at http://www.dapfor.com/license_agreement_v2.aspx)
// By continuing to use, modify, or distribute this file you indicate that you have read the license 
// and fully understand and accept it.
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __GUI_I_USER_INPUT__H
#define __GUI_I_USER_INPUT__H

#include <Dapfor/GUI/GUI_Export.h>

namespace Dapfor
{
namespace GUI
{

class DF_GUI_API IUserInput
{
public:
    virtual ~IUserInput() {};
    
    /// Called when the user input message like WM_MOUSEMOVE, WM_KEYDOWN, WM_SIZE, WM_HSCROLL... occured:
    /// \param[in] message  Message identifier
    /// \param[in] wParam  Specifies additional message information. Contents of this parameter depend on the value of the message parameter
    /// \param[in] lParam  Specifies additional message information. Contents of this parameter depend on the value of the message parameter
    virtual bool OnMessage(UINT message, WPARAM wParam, LPARAM lParam, LRESULT& result) = 0;
};


}//namespace GUI

}//namespace Dapfor

#endif //__GUI_I_USER_INPUT__H
