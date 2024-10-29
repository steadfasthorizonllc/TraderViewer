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

//Forward declarations
class CSyncObject;

//////////////////////////////////////////////////////////////////////////
/// \brief An instance of CLock class automatically acquires CSyncObject in the 
/// constructor and releases it in the destructor.
///
/// \include sync_object.example 
///
/// \class CLock Lock.h <Dapfor/Common/Lock.h>
//////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CLock
{
public:
    CLock(CSyncObject& syncObject); //!< Constructor
    ~CLock();                       //!< Destructor

private:
    //private constructors & methods to prevent from unwanted use
    CLock(const CLock&);
    CLock& operator = (const CLock&);

private:
    CSyncObject& m_SyncObject;      // Reference to a synchronization object.
};

}//namespace Common

}//namespace Dapfor


