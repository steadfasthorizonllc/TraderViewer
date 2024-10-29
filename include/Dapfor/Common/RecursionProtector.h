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

/////////////////////////////////////////////////////////////////////////////
/// \brief The class is destined to detect a function recursive call. 
///
/// Each object of CRecursionProtector class contains a counter, which is incremented 
/// by Enter() call and it is decremented by Leave() call. 
/// Initially, the counter value is equal to 0. As soon as the counter value exceeds 1,
/// CrecursionException() is raised. This class is designed for work in one thread. 
/// If it is necessary to detect a recursion in a multi-threaded application, 
/// CThreadRecursionProtector class should be applied.
/// 
/// \class CRecursionProtector RecursionProtector.h <Dapfor/Common/RecursionProtector.h>
/////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CRecursionProtector
{
public:
    ///\brief Exception is raised when recursion is detected.
    struct DF_COMMON_API CRecursionException : public CommonException
    {
        ///Constructor
        CRecursionException(const char* msg) : CommonException(msg)
        {
        }
    };

public:
    CRecursionProtector();          //!< Constructor
    virtual ~CRecursionProtector(); //!< Virtual destructor

    virtual void Enter();           //!< Increments an internal counter.
    virtual void Leave();           //!< Decrements an internal counter.

private:
    CRecursionProtector(const CRecursionProtector&);
    CRecursionProtector& operator = (const CRecursionProtector&);

    int m_Counter;
};


/////////////////////////////////////////////////////////////////////////////
/// \brief Helper, that automatically calls CRecursionProtector::Enter() in its constructor
/// and in the destructor it calls CRecursionProtector::Leave().
/// 
/// \class CRecursionChecker RecursionProtector.h <Dapfor/Common/RecursionProtector.h>
/////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CRecursionChecker
{
public:
    CRecursionChecker(CRecursionProtector& protector);  //!< Constructor
    ~CRecursionChecker();                               //!< Destructor

private:
    CRecursionProtector& m_Protector;
};

}

}
