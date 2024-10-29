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
#include <Dapfor/Common/Thread.h>
#include <Dapfor/Common/Job.h>

namespace Dapfor
{

namespace Common
{

class CJob;

//////////////////////////////////////////////////////////////////////////
/// \brief CAutomat is targeted for asynchronous CJob processing.
/// 
/// CAutomat is targeted for asynchronous processing of jobs, presented in the form of CJob class. 
/// The automat can receive jobs from any thread and process them in its own thread. 
/// Implementation of this class enables optimal use of processor resources, and if there are no jobs,
/// the automat virtually doesn't consume processor resources at all. To put a job in the queue CAutomat::PushJob() 
/// function is called. While receiving a job, the automat wakes up, puts job to the queue 
/// and calls CJob::ProcessJob method in its own thread. When the job is processed, the automat deletes 
/// the object of CJob class. If there are no more jobs in the queue, the automat "falls asleep" again. 
/// The main difference between CAutomat and CThread classes is that the automat does not consume processor 
/// resources, when it does not process a job.
///
/// \class CAutomat Automat.h <Dapfor/Common/Automat.h>
///
/// \par Thread safety.
/// All functions of CAutomat class are thread safe.
///
/// \include automat.example
///
/// \file Automat.h
//////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CAutomat : public CThread
{
public:
    CAutomat(const TString& threadName = TString());    //!< Constructor
    virtual ~CAutomat();                                //!< Virtual destructor

    void PushJob(CJob* job);                    //!< Puts a job to the internal queue. The function is not blocking.

    virtual void Start();                       //!< Starts the automat's thread.
    virtual void Stop();                        //!< Asks the thread to stop.
    virtual void Wait(int interval = Infinite); //!< Waits for the thread to exit.


protected:
    /// Called to execute a job in the automat's thread. After processing, the job is destroyed.
    virtual void OnExecuteJob(CJob* job);               
    
    /// Frees processor resources by calling ::WaitForSingleObject function and waits for the next job. 
    virtual void WaitNextJob(unsigned int interval);    
    
    /// Main routine.
    virtual int  Run();

private:
    //Point implementation interface
    struct Impl;
    Impl* m_Impl;
};


}

}//namespace Dapfor

