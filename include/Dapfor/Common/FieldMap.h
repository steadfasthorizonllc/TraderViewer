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
#include "assert.h"

namespace Dapfor
{

namespace Common
{

class CDataObject;
class CField;

/////////////////////////////////////////////////////////////////////////////
/// \brief Contains a table of the fields of the class, inheriting from CDataObject. 
///
/// Fields are stored in a table in the form of key-value. An integer identifier is the key and an 
/// object of CField is the value. If the number of the fields is more than 50, then it is 
/// recommended to initialize a hash in order to accelerate an access to the data of the object. 
/// The class, that derives from CDataObject, can have only one table. The key in the table must be unique and 
/// it can't be equal to Common::allFields (-1) or Common::fieldNotSpecified (-2). 
/// If there is an inheritance chain, identifiers can be the same in different classes, but within one class, 
/// they must be unique. For the field identifiers it is recommended to use enumerations.
/// There are some advantages of enumerations:
/// \n 1. Friendly named identifiers instead of numeric values.
/// \n 2. Identifiers can be grouped in class, to which they relate
/// \n 3. These enumerations can be easily used in field declarations.
/// \n 4. The same enumerations can be used in columns of GUI::CGrid.
/// \n 5. If enumerations are used, the application does not depend on numeric value changes.
///
/// CFiemdMap is responsible for the live time of CField objects that are destroyed in the destructor of CFiemdMap.
/// \par Thread safety:
///     The table that is declared with DF_DECLARE_FIELD_MAP(), DF_BEGIN_FIELD_MAP() etc. is static and 
///     it is not changed at runtime. This table is initialized during the application start. 
///     CFieldMap is not thread-safe, but if it is declared as a static table, it is possible to read the fields
///     from different threads.
///
/// \class CFieldMap FieldMap.h <Dapfor/Common/FieldMap.h>
/// \file FieldMap.h
/////////////////////////////////////////////////////////////////////////////
class DF_COMMON_API CFieldMap
{
public:
    typedef std::set<CField*> Fields; //!< list of the fields, declared in the field map

public:
    CFieldMap();                                    //!< constructor
    CFieldMap(CFieldMap* pParentMap);               //!< Constructor that is applied in the inheritance chain
    virtual ~CFieldMap();                           //!< Frees all resources. It also destroys all declared fields.

    ///Declares a new field
    inline bool AddField(FID fid, CField* pField)   
    {
        bool result = InternalAddField(fid, pField);

        // Field with the same identifier has already been declared. 
        // Try to change the field identifier in the declaration macros.
        // Ex.
        //
        // file: MyDataObject.h
        //
        //  class CMyDataObject
        //  {
        //  public:
        //   ...
        //      enum Fields
        //      {
        //         ...
        //         Price     = 1000,
        //         Quantity,    
        //         ...
        //      };
        //
        //      double  GetPrice() const            {...}
        //      void    SetPrice(double newPrice)   {...}
        //   ...
        //  };
        //
        //
        // file: MyDataObject.cpp
        //
        // DF_BEGIN_FIELD_MAP(CMyDataObject)
        //    DF_DOUBLE_ID(Price, "Price", &CMyDataObject::GetPrice, &CMyDataObject::SetPrice, 0)
        //    ...
        // DF_END_FIELD_MAP()
        //
        assert(result); 
        
        return result;
    }

    CField*          GetField(FID fid) const;               //!< Gets a declared field by its identifier
    void             GetAllFields(Fields& fields) const;    //!< Gets a list of all declared fields

    CFieldMap*       GetParentMap();                        //!< Gets a field map of the parent class in the inheritance chain.
    const CFieldMap* GetParentMap() const;                  //!< Gets a field map of the parent class, const version.

    void             InitHash();                            //!< Initializes hash
    

private:
    CFieldMap(const CFieldMap&);
    CFieldMap& operator = (const CFieldMap&);
    bool             InternalAddField(FID fid, CField* pField); 

    //Point implementation interface
    struct Impl;
    Impl* m_Impl;
};


}//namespace Common

}//namespace Dapfor


