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
#include <Dapfor/Common/DataObject.h>

namespace Dapfor
{

namespace Common
{


//////////////////////////////////////////////////////////////////////////
/// \brief This class organizes aggregation relations between data objects.
/// 
/// CDelegate makes it possible to organize aggregation relations between data objects. 
/// In this case all events are forwarded from the aggregated object on the behalf of the delegate. 
/// It is convenient, if there are several various classes representing entirely different functionalities.
/// If the delegate is inserted into the grid, this delegate stands as a proxy between the grid and the aggregated 
/// object. In case of inheritance from the delegate, identification of their own tables of functions in 
/// descendant the class is possible. When the delegate object is required for data, search of functions is 
/// performed firstly in the inheritance path and then in the aggregate object. When a new aggregated object is set, 
/// subscription for sending of the events from the object takes place. When an event is received, it
/// is transferred to the subscribers on the behalf of the delegate object. Therefore, the delegate object 
/// and the aggregated object appear as a single entity.
///
/// \class CDelegate Delegate.h <Dapfor/Common/Delegate.h>
///
/// \par Example
/// \include delegate.example
///
/// \file Delegate.h
//////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CDelegate : public CDataObject
{
public:
    CDelegate(CDataObject* aggregate, bool owner);                  //!< Constructor
    virtual ~CDelegate();                                           //!< Destructor

    virtual const Field        GetField(FID fid) const;             //!< Gets a field by its identifier
    virtual void               GetAllFields(Fields& fields) const;  //!< Gets all the fields available in CDelegate and the aggregated object
    virtual void               GetAllFids(Fids& fids) const;        //!< Gets all the identifiers available in CDelegate and the aggregated object
    
    virtual CDataObject*       SetAggregate(CDataObject* aggregate); //!< Sets a new aggregated object
    virtual CDataObject*       GetAggregate();                       //!< Gets an aggregated object
    virtual const CDataObject* GetAggregate() const;                 //!< Gets an aggregated object

private:
    //Point implementation interface
    class Impl;
    Impl* m_Impl;
};


}//namespace Common

}//namespace Dapfor



