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

class DF_COMMON_API CLog
{
public:
    enum Severity
    {
        InfoLevel,
        DebugLevel,
        ErrorLevel,
        FatalLevel,
    };

    struct DF_COMMON_API ILogger
    {
        virtual ~ILogger() {}
        virtual void Log(Severity severity, long time, int threadId, const TString& message) = 0;
    };

public:
    static void Info(const TString& message, ...);
    static void AddLogger(ILogger* logger);


private:
    struct Impl;
    friend Impl;
};

}//namespace Common

}


