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
#include <Dapfor/Common/Types.h>


namespace Dapfor
{
namespace Common
{

//////////////////////////////////////////////////////////////////////////
/// \brief Creates and controls a thread.
///
/// \class CThread Thread.h <Dapfor/Common/Thread.h>
//////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CThread
{
public:
    /// Used types
    enum
    {
        Infinite = 0xFFFFFFFF,                      //!< Infinite interval 
    };

public:
    virtual void    Start();                        //!< Starts a new thread
    virtual void    Stop();                         //!< Asks a thread to stop
    virtual void    Wait(int interval = Infinite);  //!< Waits for a thread to exit
    virtual TString GetThreadName() const;          //!< Returns the name of the thread, specified in the constructor.
    unsigned int    GetThreadId() const;            //!< Returns a thread identifier.


    virtual bool IsActive() const;                  //!< Indicates whether a thread is active.
    virtual bool IsStopping() const;                //!< Indicates whether the thread is asked to stop but hasn't stopped yet.
protected:
    CThread(const TString& threadName = TString()); //!< Constructor
    virtual ~CThread();                             //!< Virtual destructor. Releases all the resources used by CThread object.

    virtual int Run() = 0;                          //!< This function is called in a new thread.

private:
    //Point implementation interface
    struct Impl;                                
    friend Impl;
    Impl*  m_Impl;
};


}

}//namespace Dapfor


