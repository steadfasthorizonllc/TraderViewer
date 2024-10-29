#pragma once

#include "TradeViewerData.h"
#include <Dapfor/GUI/EditInPlace.h>
#include <Dapfor/Common/LongEnumFormat.h>


class CTradeViewerEditInPlace : public Dapfor::GUI::CEditInPlace
{
public:
    //Constructor
    CTradeViewerEditInPlace();
    ~CTradeViewerEditInPlace();
    
    virtual bool  AttachControl(Dapfor::GUI::CEditInPlaceContext& context,
                                Dapfor::GUI::IEditInPlace::StartReason startReason, 
                                const Dapfor::Common::CFormat* format);
    
    
    //Overrides the CEditInPlace's method
    virtual bool CanApply(Dapfor::GUI::CEditInPlace::StopReason reason) const;

private:
    Dapfor::Common::CLongEnumFormat* m_Format;
};
