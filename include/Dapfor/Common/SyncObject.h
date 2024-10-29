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
/// \brief Provides the functionality to protect objects against simultaneous access by two and more threads.
///        CSyncObject internally uses a critical section.
///
/// \class CSyncObject SyncObject.h <Dapfor/Common/SyncObject.h>
//////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CSyncObject
{
public:
    CSyncObject();          //!< Constructor
    ~CSyncObject();         //!< Destructor
    
    void Lock();            //!< The function waits for ownership of a critical section object.
    void UnLock();          //!< The function releases ownership of a critical section object

private:
    //private constructors & methods to prevent from unwanted use
    CSyncObject(const CSyncObject&);
    CSyncObject& operator = (const CSyncObject&);

private:
    //Point implementation interface
    struct CSyncObjectImpl;
    CSyncObjectImpl* m_Impl;
};


}//namespace Common

}//namespace Dapfor

