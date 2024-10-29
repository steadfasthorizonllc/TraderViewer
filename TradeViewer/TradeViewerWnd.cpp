
#include "stdafx.h"

#include "Resource.h"
#include "MainFrm.h"
#include "TradeViewer.h"
#include "TradeViewerWnd.h"
#include "ColumnSelectionDialog.h"
#include "AddColumnDialog.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
// CResourceViewBar

CTradeViewerWnd::CTradeViewerWnd()
    : m_pTradeViewerView(nullptr)  // Initialize pointer to null
{
}

CTradeViewerWnd::~CTradeViewerWnd()
{
}

BEGIN_MESSAGE_MAP(CTradeViewerWnd, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_SETFOCUS()
	ON_COMMAND(ID_COLUMNS, OnColumns)
	ON_UPDATE_COMMAND_UI(ID_COLUMNS, OnUpdateColumns)
	ON_COMMAND(ID_ADD_COLUMN, OnAddColumn)
	ON_UPDATE_COMMAND_UI(ID_ADD_COLUMN, OnUpdateAddColumn)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResourceViewBar message handlers

void CTradeViewerWnd::AdjustLayout()
{
    if (GetSafeHwnd() == NULL)
    {
        return;
    }

    CRect rectClient;
    GetClientRect(rectClient);

    int cyTlb = m_wndToolBar.CalcFixedLayout(FALSE, TRUE).cy;
    m_wndToolBar.SetWindowPos(NULL, rectClient.left, rectClient.top, rectClient.Width(), cyTlb, SWP_NOACTIVATE | SWP_NOZORDER);

    if (m_pTradeViewerView != nullptr)
    {
        m_pTradeViewerView->SetWindowPos(nullptr, rectClient.left, rectClient.top + cyTlb, 
            rectClient.Width(), rectClient.Height(), SWP_NOZORDER | SWP_NOACTIVATE);
    }
}

int CTradeViewerWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_wndToolBar.Create(this, AFX_DEFAULT_TOOLBAR_STYLE, IDR_PROPERTIES);
	m_wndToolBar.LoadToolBar(IDR_TRADEVIEWER, 0, 0, TRUE /* Is locked */);
	m_wndToolBar.CleanUpLockedImages();
	m_wndToolBar.LoadBitmap(theApp.m_bHiColorIcons ? IDB_TRADEVIEWER_HC : IDR_TRADEVIEWER, 0, 0, TRUE /* Locked */);

	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);
	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() & ~(CBRS_GRIPPER | CBRS_SIZE_DYNAMIC | CBRS_BORDER_TOP | CBRS_BORDER_BOTTOM | CBRS_BORDER_LEFT | CBRS_BORDER_RIGHT));
	m_wndToolBar.SetOwner(this);

	// All commands will be routed via this control , not via the parent frame:
	m_wndToolBar.SetRouteCommandsViaFrame(FALSE);

	AdjustLayout();
	return 0;
}

void CTradeViewerWnd::CreateTradeViewerView(CCreateContext* pContext)
{
    // Ensure that the view is created inside the pane
    if (m_pTradeViewerView == nullptr)
    {
        m_pTradeViewerView = (CTradeViewerView*)RUNTIME_CLASS(CTradeViewerView)->CreateObject();
        if (!m_pTradeViewerView)
        {
            TRACE0("Failed to create TradeViewerView\n");
            return;
        }

        // Create the view as a child of the pane
        if (!m_pTradeViewerView->Create(nullptr, nullptr, AFX_WS_DEFAULT_VIEW,
            CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, pContext))
        {
            TRACE0("Failed to create view window\n");
            delete m_pTradeViewerView;
            m_pTradeViewerView = nullptr;
            return;
        }

        // Adjust layout after the view is created
        AdjustLayout();
    }
}

void CTradeViewerWnd::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	AdjustLayout();
}

void CTradeViewerWnd::OnSetFocus(CWnd* pOldWnd)
{
	CDockablePane::OnSetFocus(pOldWnd);
    if (m_pTradeViewerView != nullptr)
    {
        m_pTradeViewerView->SetFocus();
    }
}

void CTradeViewerWnd::OnColumns()
{
    CColumnSelectionDialog dlg(_T("columns.ini"), _T("TradeViewer-Default"));
    if (dlg.DoModal() == IDOK)
    {
        Dapfor::GUI::CHeader* header = m_pTradeViewerView->m_Grid.GetHeader();
        for (size_t i = 0; i < dlg.m_columnStates.size(); i++)
        {
            Dapfor::GUI::CColumn* column = header->GetColumnByIndex(i);
            if (column != NULL)
            {
                if (dlg.m_columnStates[i] != 0)
                {
                    column->SetVisible(true);
                }
                else
                {
                    column->SetVisible(false);
                }
            }
        }
    }
}

void CTradeViewerWnd::OnUpdateColumns(CCmdUI* pCmdUI)
{

}

void CTradeViewerWnd::OnAddColumn()
{
    CAddColumnDialog dlg(_T("columns.ini"), _T("TradeViewer-Default"));
    if (dlg.DoModal() == IDOK)
    {
        // Save logic here
    }
}

void CTradeViewerWnd::OnUpdateAddColumn(CCmdUI* pCmdUI)
{

}