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

class CAutomat; 


//////////////////////////////////////////////////////////////////////////
/// \brief Abstract job to be executed in CAutomat
/// 
/// Automat calls ProcessJob in its own thread and then destroys the job object.
///
/// \class CJob Job.h <Dapfor/Common/Job.h>
//////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CJob
{
public:
    virtual ~CJob(); //!< Virtual destructor

    /// This function is called to execute a job in CAutomat thread.
    virtual void ProcessJob(CAutomat* automat) = 0; 
};

}//namespace Common

}//namespace Dapfor

