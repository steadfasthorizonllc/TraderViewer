#include "StdAfx.h"
#include "TradeViewerData.h"

#include <Dapfor/Common/LongDateFormat.h>
#include <Dapfor/Common/LongEnumFormat.h>


//Declare mapping to present enumeration as a string
//Dapfor::Common::CLongEnumFormat::Item status[] =
//{
//    {CTradeViewerData::Paris,     _T("Paris")},
//    {CTradeViewerData::Toronto,   _T("Toronto")},
//    {CTradeViewerData::NewYork,   _T("New York")},
//    {CTradeViewerData::Tokio,     _T("Tokio")},
//    {CTradeViewerData::Frankfurt, _T("Frankfurt")},
//    {CTradeViewerData::London,    _T("London")},
//};



//Field map implementation. Here you declare the properties of the class that will be accessible from the grid.
//Each property has an unique identifier, and optionally may have a name, Get-function, Set-function and a format 
//to convert value, returned by the Get- function to string and vice-versa.
DF_BEGIN_FIELD_MAP(CTradeViewerData)
    DF_MFC_STRING_ID(TIME, _T(""), &CTradeViewerData::GetTIME, 0, 0)
    DF_MFC_STRING_ID(SYMBOL, _T(""), &CTradeViewerData::GetSYMBOL, 0, 0)
    DF_MFC_STRING_ID(PRICE, _T(""), &CTradeViewerData::GetPRICE, 0, 0)
    DF_MFC_STRING_ID(NET_CHANGE, _T(""), &CTradeViewerData::GetNET_CHANGE, 0, 0)
    DF_MFC_STRING_ID(SIZE, _T(""), &CTradeViewerData::GetSIZE, 0, 0)
    DF_MFC_STRING_ID(EXCH, _T(""), &CTradeViewerData::GetEXCH, 0, 0)
    DF_MFC_STRING_ID(BID, _T(""), &CTradeViewerData::GetBID, 0, 0)
    DF_MFC_STRING_ID(BID_SIZE, _T(""), &CTradeViewerData::GetBID_SIZE, 0, 0)
    DF_MFC_STRING_ID(BID_EXCHANGE, _T(""), &CTradeViewerData::GetBID_EXCHANGE, 0, 0)
    DF_MFC_STRING_ID(ASK, _T(""), &CTradeViewerData::GetASK, 0, 0)
    DF_MFC_STRING_ID(ASK_SIZE, _T(""), &CTradeViewerData::GetASK_SIZE, 0, 0)
    DF_MFC_STRING_ID(ASK_EXCHANGE, _T(""), &CTradeViewerData::GetASK_EXCHANGE, 0, 0)
    DF_MFC_STRING_ID(SIDE, _T(""), &CTradeViewerData::GetSIDE, 0, 0)
    DF_MFC_STRING_ID(VOLUME, _T(""), &CTradeViewerData::GetVOLUME, 0, 0)
    DF_MFC_STRING_ID(OPEN_INTEREST, _T(""), &CTradeViewerData::GetOPEN_INTEREST, 0, 0)
    DF_MFC_STRING_ID(OPEN_PRICE, _T(""), &CTradeViewerData::GetOPEN_PRICE, 0, 0)
    DF_MFC_STRING_ID(HIGH_PRICE, _T(""), &CTradeViewerData::GetHIGH_PRICE, 0, 0)
    DF_MFC_STRING_ID(LOW_PRICE, _T(""), &CTradeViewerData::GetLOW_PRICE, 0, 0)
    DF_MFC_STRING_ID(TRADE_CONDITION, _T(""), &CTradeViewerData::GetTRADE_CONDITION, 0, 0)
    DF_MFC_STRING_ID(BID_EXCHANGE_2, _T(""), &CTradeViewerData::GetBID_EXCHANGE_2, 0, 0)
    DF_MFC_STRING_ID(ASK_EXCHANGE_2, _T(""), &CTradeViewerData::GetASK_EXCHANGE_2, 0, 0)
    DF_MFC_STRING_ID(BID_PRICES, _T(""), &CTradeViewerData::GetBID_PRICES, 0, 0)
    DF_MFC_STRING_ID(ASK_PRICES, _T(""), &CTradeViewerData::GetASK_PRICES, 0, 0)
    DF_MFC_STRING_ID(BID_SIZES, _T(""), &CTradeViewerData::GetBID_SIZES, 0, 0)
    DF_MFC_STRING_ID(ASK_SIZES, _T(""), &CTradeViewerData::GetASK_SIZES, 0, 0)

    //
    ////Normally you can't use the same identifier twice. If you uncomment the line below you'll give 
    ////'Assertion failed' dialog box. This permits you detect non-obvious errors as soon as possible.
    ////DF_LONG_ID(FidName, _T("Long"), &CTradeViewerData::GetSomeLong, 0, 0)
    //
    //DF_LONG_ID(FidSomeLong, _T("Long"), &CTradeViewerData::GetSomeLong, &CTradeViewerData::SetSomeLong, 0)
    //DF_INT64_ID(FidSomeInt64, _T("Int64"), &CTradeViewerData::GetSomeInt64, &CTradeViewerData::SetSomeInt64, 0)
    //DF_DOUBLE_ID(FidSomeDouble, _T("Double"), &CTradeViewerData::GetSomeDouble, &CTradeViewerData::SetSomeDouble, 0)
    //
    ////This field represents the date
    //DF_LONG_ID(FidSomeDate, _T("Date"), &CTradeViewerData::GetSomeDate, &CTradeViewerData::SetSomeDate, new CLongDateFormat(CLongDateFormat::short_date));
    //DF_ENUM_ID(FidSomeEnum, _T("City"), &CTradeViewerData::GetSomeEnum, &CTradeViewerData::SetSomeEnum, DF_ENUM_FORMAT(status));
DF_END_FIELD_MAP()

CTradeViewerData::CTradeViewerData()
{
}

CTradeViewerData::~CTradeViewerData()
{
}

CString CTradeViewerData::GetTIME() const { return m_Data[TIME]; }
CString CTradeViewerData::GetSYMBOL() const { return m_Data[SYMBOL]; }
CString CTradeViewerData::GetPRICE() const { return m_Data[PRICE]; }
CString CTradeViewerData::GetNET_CHANGE() const { return m_Data[NET_CHANGE]; }
CString CTradeViewerData::GetSIZE() const { return m_Data[SIZE]; }
CString CTradeViewerData::GetEXCH() const { return m_Data[EXCH]; }
CString CTradeViewerData::GetBID() const { return m_Data[BID]; }
CString CTradeViewerData::GetBID_SIZE() const { return m_Data[BID_SIZE]; }
CString CTradeViewerData::GetBID_EXCHANGE() const { return m_Data[BID_EXCHANGE]; }
CString CTradeViewerData::GetASK() const { return m_Data[ASK]; }
CString CTradeViewerData::GetASK_SIZE() const { return m_Data[ASK_SIZE]; }
CString CTradeViewerData::GetASK_EXCHANGE() const { return m_Data[ASK_EXCHANGE]; }
CString CTradeViewerData::GetSIDE() const { return m_Data[SIDE]; }
CString CTradeViewerData::GetVOLUME() const { return m_Data[VOLUME]; }
CString CTradeViewerData::GetOPEN_INTEREST() const { return m_Data[OPEN_INTEREST]; }
CString CTradeViewerData::GetOPEN_PRICE() const { return m_Data[OPEN_PRICE]; }
CString CTradeViewerData::GetHIGH_PRICE() const { return m_Data[HIGH_PRICE]; }
CString CTradeViewerData::GetLOW_PRICE() const { return m_Data[LOW_PRICE]; }
CString CTradeViewerData::GetTRADE_CONDITION() const { return m_Data[TRADE_CONDITION]; }
CString CTradeViewerData::GetBID_EXCHANGE_2() const { return m_Data[BID_EXCHANGE_2]; }
CString CTradeViewerData::GetASK_EXCHANGE_2() const { return m_Data[ASK_EXCHANGE_2]; }
CString CTradeViewerData::GetBID_PRICES() const { return m_Data[BID_PRICES]; }
CString CTradeViewerData::GetASK_PRICES() const { return m_Data[ASK_PRICES]; }
CString CTradeViewerData::GetBID_SIZES() const { return m_Data[BID_SIZES]; }
CString CTradeViewerData::GetASK_SIZES() const { return m_Data[ASK_SIZES]; }

//CString CTradeViewerData::GetName() const         {return m_Name;}
//long    CTradeViewerData::GetSomeLong() const     {return m_Long;}
//__int64 CTradeViewerData::GetSomeInt64() const    {return m_Int64;}
//double  CTradeViewerData::GetSomeDouble() const   {return m_Double;}
//long    CTradeViewerData::GetSomeDate() const     {return m_Date;}
//CTradeViewerData::City    CTradeViewerData::GetSomeEnum() const {return m_City;}
//
//
//void CTradeViewerData::SetSomeLong(long v)
//{
//    m_Long = v;
//
//    //Send notification to the grid. Each grid will automatically update the cell, sort and filter the row if needed.
//    NotifyUpdate(FidSomeLong);
//}
//void CTradeViewerData::SetSomeInt64(__int64 v)
//{
//    m_Int64 = v;
//    
//    //Send notification to the grid. Each grid will automatically update the cell, sort and filter the row if needed.
//    NotifyUpdate(FidSomeInt64);
//}
//void CTradeViewerData::SetSomeDouble(double v)
//{
//    m_Double = v;
//    
//    //Send notification to the grid. Each grid will automatically update the cell, sort and filter the row if needed.
//    NotifyUpdate(FidSomeDouble);
//}
//void CTradeViewerData::SetSomeDate(long v)
//{
//    m_Date = v;
//    
//    //Send notification to the grid. Each grid will automatically update the cell, sort and filter the row if needed.   
//    NotifyUpdate(FidSomeDate);
//}
//
//void CTradeViewerData::SetSomeEnum(City city)
//{
//    m_City = city;
//
//    NotifyUpdate(FidSomeEnum);
//}
