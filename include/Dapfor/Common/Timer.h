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

#include <Dapfor/Common/Common.h>

namespace Dapfor
{

namespace Common
{

//////////////////////////////////////////////////////////////////////////
/// \brief Singleton. It manages the timers in its own thread.
/// 
/// When the timer expires, the appropriate subscriber is notified by calling ICallBack::OnExpire
/// \note The notification comes in the timer's thread.
///
/// \class CTimer Timer.h <Dapfor/Common/Timer.h>
////////////////////////////////////////////////////////////////////////// 
class DF_COMMON_API CTimer
{
public:
    ///Callback interface to be called when a timer expires.
    struct ICallBack
    {
        virtual void OnExpire(int timerId) = 0; //!< Called when a timer expires.
    };

public:
    static bool StartTimer(ICallBack* callBack, int timerId, unsigned int elapsedTime);
    static bool StopTimer(ICallBack* callBack, int timerId);

    static void Initialize();
    static void UnInitialize();

private:
    struct Impl;
    friend Impl;

};

}//namespace Common

}//namespace Dapfor

