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
#include <Dapfor/Common/RecursionProtector.h>

namespace Dapfor
{

namespace Common
{

/////////////////////////////////////////////////////////////////////////////
/// \brief The class is destined to detect a function recursive call in multi-threaded applications. 
/// 
/// The protector has an individual counter for every thread. The function Enter() increments a counter that 
/// corresponds to the calling thread. As soon as the counter value exceeds 1,
/// CRecursionProtector::CRecursionException is raised. The function Leave() decrements the appropriate counter.
/// 
/// \par Thread safety
/// All functions are thread-safe.
///
/// \class CThreadRecursionProtector ThreadRecursionProtector.h <Dapfor/Common/ThreadRecursionProtector.h>
/// \file ThreadRecursionProtector.h
/////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CThreadRecursionProtector : public CRecursionProtector
{
public:
    CThreadRecursionProtector();            //!< Constructor 
    virtual ~CThreadRecursionProtector();   //!< Virtual destructor

    virtual void Enter();                   //!< Increments an internal counter for a calling thread.
    virtual void Leave();                   //!< Decrements an internal counter for a calling thread.

private:
    CThreadRecursionProtector(const CThreadRecursionProtector&);
    CThreadRecursionProtector& operator = (const CThreadRecursionProtector&);

    //Point implementation interface
    struct Impl;
    Impl* m_Impl;
};


}//namespace Common

}//namespace Dapfor
