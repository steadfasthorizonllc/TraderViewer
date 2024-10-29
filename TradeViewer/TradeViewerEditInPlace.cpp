#include "StdAfx.h"
#include "TradeViewerEditInPlace.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//Dapfor::Common::CLongEnumFormat::Item customItems[] =
//{
//    {CTradeViewerData::Paris,     _T("Modified Paris")},
//    {CTradeViewerData::Toronto,   _T("Modified Toronto")},
//    {CTradeViewerData::NewYork,   _T("Modified New York")},
//    {CTradeViewerData::Tokio,     _T("Modified Tokio")},
//    {CTradeViewerData::Frankfurt, _T("Modified Frankfurt")},
//    {CTradeViewerData::London,    _T("Modified London")},
//};


//Pass 'true' to the base class. In this case this interface will be destroyed
//automatically in the destructor of the CGrid
CTradeViewerEditInPlace::CTradeViewerEditInPlace() : Dapfor::GUI::CEditInPlace(true)
{
    //m_Format = new Dapfor::Common::CLongEnumFormat(customItems, sizeof(customItems)/sizeof(customItems[0]));
    //
    ////Also, you can modify your format. 
    ////If the user selects this text, the data object will get 100 in the Set-method
    //(*m_Format)[100] = _T("100 as string");
}

CTradeViewerEditInPlace::~CTradeViewerEditInPlace()
{
    //delete m_Format;
}

bool CTradeViewerEditInPlace::AttachControl(Dapfor::GUI::CEditInPlaceContext& context,
                                       Dapfor::GUI::IEditInPlace::StartReason startReason, 
                                       const Dapfor::Common::CFormat* format)
{

    //Here we will change a content of the drop down control
    //if(context.GetColumn()->GetFid() == CTradeViewerData::FidSomeEnum)
    //{
    //    //Instead of the default format we will set the our one
    //    return CEditInPlace::AttachControl(context, startReason, m_Format); 
    //}
    
    return CEditInPlace::AttachControl(context, startReason, format);
}


//Change behavior when user ends edit in place operation
bool CTradeViewerEditInPlace::CanApply(Dapfor::GUI::CEditInPlace::StopReason reason) const
{
    switch(reason)
    {
        //Set a new value to the data object when the next operations occur
    case Dapfor::GUI::CEditInPlace::LostFocus:
    case Dapfor::GUI::CEditInPlace::KeyUp:
    case Dapfor::GUI::CEditInPlace::KeyDown:
    case Dapfor::GUI::CEditInPlace::KeyLeft:
    case Dapfor::GUI::CEditInPlace::KeyRight:
    case Dapfor::GUI::CEditInPlace::KeyTab:
    case Dapfor::GUI::CEditInPlace::KeyShiftTab:
    case Dapfor::GUI::CEditInPlace::KeyCtrlTab:
        return true;
        
    default:
        //Otherwise, the default implementation will apply a new value in case of the next events:
        //(KeyReturn, ComboSelEndOk, MouseLBDblClick and UserStop)
        return CEditInPlace::CanApply(reason);
    }
}
