
#pragma once
#include "TradeViewerView.h"

class CTradeViewerToolBar : public CMFCToolBar
{
public:
    virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler)
    {
        CMFCToolBar::OnUpdateCmdUI((CFrameWnd*) GetOwner(), bDisableIfNoHndler);
    }

    virtual BOOL AllowShowOnList() const { return FALSE; }
};

class CTradeViewerWnd : public CDockablePane
{
// Construction
public:
	CTradeViewerWnd();

	void AdjustLayout();

    // Function to create and attach view to this pane
    void CreateTradeViewerView(CCreateContext* pContext);

// Attributes
public:

protected:
    CTradeViewerToolBar m_wndToolBar;
    CTradeViewerView* m_pTradeViewerView;  // Pointer to the view

// Implementation
public:
	virtual ~CTradeViewerWnd();

protected:
	afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);

	afx_msg void OnColumns();
	afx_msg void OnUpdateColumns(CCmdUI* pCmdUI);

	afx_msg void OnAddColumn();
	afx_msg void OnUpdateAddColumn(CCmdUI* pCmdUI);

	DECLARE_MESSAGE_MAP()
};

