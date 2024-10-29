#pragma once

#include <string>
#include <Dapfor/Common/DataObject.h>

//The objects of this class can be used directly in the MFC grid. Note, that this is an ordinary class 
//the objects of which can be used anywhere in your application. The base class CDataObject adds only a possibility to 
//use the objects of this class in the grid
class CTradeViewerData : public Dapfor::Common::CDataObject
{
public:
    //The functions, declared below can be called by the MFC grid. To call them we use a mapping table 
    //(one per class, not per object). The Get- and Set- functions are grouped in properties. Each property
    //has a numeric identifier. The same numeric identifiers are used in columns of the grid.
    //You can freely use identifiers like 1, 2, 3... But the best practice is to use the enumeration! In this case
    //many verifications are done at compile time, the code become more comprehensible and safe.
    enum Fields
    {
        TIME,
        SYMBOL,
        PRICE,
        NET_CHANGE,
        SIZE,
        EXCH,
        BID,
        BID_SIZE,
        BID_EXCHANGE,
        ASK,
        ASK_SIZE,
        ASK_EXCHANGE,
        SIDE,
        VOLUME,
        OPEN_INTEREST,
        OPEN_PRICE,
        HIGH_PRICE,
        LOW_PRICE,
        TRADE_CONDITION,
        BID_EXCHANGE_2,
        ASK_EXCHANGE_2,
        BID_PRICES,
        ASK_PRICES,
        BID_SIZES,
        ASK_SIZES
    };


    //enum City
    //{
    //    Paris,
    //    Toronto,
    //    NewYork,
    //    Tokio,
    //    Frankfurt,
    //    London,
    //};


public:
    //CTradeViewerData(CString vName, long vLong, __int64 vInt64, double vDouble);
    CTradeViewerData();
    ~CTradeViewerData();

    //Some functions. The grid will call them through the mapping, declared below
    CString GetTIME() const;
    CString GetSYMBOL() const;
    CString GetPRICE() const;
    CString GetNET_CHANGE() const;
    CString GetSIZE() const;
    CString GetEXCH() const;
    CString GetBID() const;
    CString GetBID_SIZE() const;
    CString GetBID_EXCHANGE() const;
    CString GetASK() const;
    CString GetASK_SIZE() const;
    CString GetASK_EXCHANGE() const;
    CString GetSIDE() const;
    CString GetVOLUME() const;
    CString GetOPEN_INTEREST() const;
    CString GetOPEN_PRICE() const;
    CString GetHIGH_PRICE() const;
    CString GetLOW_PRICE() const;
    CString GetTRADE_CONDITION() const;
    CString GetBID_EXCHANGE_2() const;
    CString GetASK_EXCHANGE_2() const;
    CString GetBID_PRICES() const;
    CString GetASK_PRICES() const;
    CString GetBID_SIZES() const;
    CString GetASK_SIZES() const;

    //Some set functions. The grid will call them while edit in place operations
    //void SetSomeLong(long v);
    //void SetSomeInt64(__int64 v);
    //void SetSomeDouble(double v);
    //void SetSomeDate(long v);
    //void SetSomeEnum(City city);


//private:
    //Some variables
    //CString m_Name;
    //long    m_Long;
    //__int64 m_Int64;
    //double  m_Double;
    //long    m_Date;
    //City    m_City;

    std::vector<CString> m_Data;

private:
    //To make the functions visible by the grid, we declare the field map - the list of properties (Get- & Set functions)
    DF_DECLARE_FIELD_MAP();
};
