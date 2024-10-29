
// TradeViewerView.cpp : implementation of the CTradeViewerView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TradeViewer.h"
#endif

#include "TradeViewerDoc.h"
#include "TradeViewerView.h"

#include "TradeViewerData.h"
#include "TradeViewerEditInPlace.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTradeViewerView

IMPLEMENT_DYNCREATE(CTradeViewerView, CView)

BEGIN_MESSAGE_MAP(CTradeViewerView, CView)
	// Standard printing commands
    ON_WM_CREATE()
    ON_WM_SIZE()
    ON_WM_ERASEBKGND()
    ON_WM_DESTROY()
    ON_WM_TIMER()
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTradeViewerView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTradeViewerView construction/destruction

CTradeViewerView::CTradeViewerView()
{
	// TODO: add construction code here
}

CTradeViewerView::~CTradeViewerView()
{
}

BOOL CTradeViewerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
    cs.style |= WS_HSCROLL;
	return CView::PreCreateWindow(cs);
}

int GetVisibleRowCount(Dapfor::GUI::CGrid& m_Grid, Dapfor::GUI::HITEM handle)
{
    // Step 1: Get the height of the client area of the grid
    CRect clientRect;
    m_Grid.GetClientRect(&clientRect);  // Get the size of the visible area (client area)
    
    int gridHeight = clientRect.Height();  // Get the height of the grid's client area

    // Step 2: Get the height of each row
    int rowHeight = m_Grid.GetItemHeight(handle);  // Get the height of a single row (assuming uniform height)

    // Step 3: Calculate how many rows can be displayed
    int visibleRowCount = gridHeight / rowHeight;

    return visibleRowCount;  // Return the number of visible rows
}

// CTradeViewerView drawing
void CTradeViewerView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	CTradeViewerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

    //for(CTradeViewerDoc::Container::const_iterator it = GetDocument()->GetContainer().begin(); 
    //                                               it != GetDocument()->GetContainer().end(); 
    //                                               ++it)
    //{
    //    Dapfor::GUI::HITEM handle = m_Grid.Add(*it);
    //
    //    // Get the number of rows that can be displayed at once
    //    int visibleRowCount = GetVisibleRowCount(m_Grid, handle);
    //
    //    // Get the total number of rows in the grid
    //    int rowCount = m_Grid.GetRowCount();
    //
    //    // Calculate the first visible row, ensuring the last row is visible
    //    int firstVisibleRow = 0;
    //    if (rowCount > visibleRowCount)
    //    {
    //        firstVisibleRow = rowCount - visibleRowCount;  // Scroll to the row that will show the last row in view
    //    }
    //
    //    // Scroll to the calculated first visible row
    //    m_Grid.SetFirstVisibleRow(firstVisibleRow);
    //}
    //
    //Invalidate();
    //UpdateWindow();
}

void CTradeViewerView::OnDraw(CDC* /*pDC*/)
{
	CTradeViewerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: add draw code for native data here

    int rowCount = m_Grid.GetRowCount();
    if (rowCount > 0)
    {
        //m_Grid.SetScrollPos(SB_VERT, rowCount - 1);
    }
}

// CMyFirstApplicationView message handlers
int CTradeViewerView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CView::OnCreate(lpCreateStruct) == -1)
        return -1;

    //Initialize the grid
    m_Grid.Create(0, 0, WS_VISIBLE|WS_CHILD, CRect(), this, 1000);

    //Create some header. The value 'true' in the constructor indicates, that the header will be owned by the grid and
    //the grid will handle the life time of the header. This means, that the grid will destroy the header in its destructor.
    Dapfor::GUI::CHeader* header = new Dapfor::GUI::CHeader(true);
    
    //Add some columns. To show values, returned by functions, defined in CTestClass, 
    //we will use identifiers, declared in this class.
    CTradeViewerDoc* pDoc = GetDocument();
    if (pDoc->m_csvReader != NULL)
    {
        // Retrieve the title row
        const std::vector<CString>& title = pDoc->m_csvReader->GetTitle();
        for (size_t i = 0; i < title.size(); ++i)
        {
            CString cstr = title[i];
            std::wstring wstr(cstr);
            header->Add(new Dapfor::GUI::CColumn(i, wstr, 60));
        }
    }

    //Set the header
    m_Grid.SetHeader(header);
    
    //Initialize background colors
    m_Grid.GetAppearance().SetBackEvenColor(RGB(255, 255, 255));
    m_Grid.GetAppearance().SetBackOddColor(RGB(240, 240, 240));
    
    //Start edit in place with single click
    m_Grid.GetEditInPlaceSettings().SetActivationType(Dapfor::GUI::CEditInPlaceSettings::mouseClick);

    
    //Add objects from the document to the grid...
    for(CTradeViewerDoc::Container::const_iterator it = GetDocument()->GetContainer().begin(); 
                                                   it != GetDocument()->GetContainer().end(); 
                                                   ++it)
    {
        Dapfor::GUI::HITEM handle = m_Grid.Add(*it);
    }

    ////Here you can set your sort rules.
    ////A small tweak: click on the header with left mouse button to change the sort direction
    ////The click with pressed Ctrl button adds/changes multiple sort
    ////The click with pressed Shift button to cancels the sort
    //m_Grid.SetSort(0, Dapfor::GUI::CSortInfo(CTradeViewerData::FidSomeLong, false));  //Sort by the first column
    //m_Grid.SetSort(1, Dapfor::GUI::CSortInfo(CTradeViewerData::FidSomeInt64, true));  //This line add a multiple sort by the second column
    //
    ////Select rows 3 and 4
    //m_Grid.Select(3, Dapfor::GUI::ScrollableContext, true);
    //m_Grid.Select(4, Dapfor::GUI::ScrollableContext, true);
    //
    ////Select a row in the grid that corresponds to the sixth element in the container.
    ////Note, that you don't need to find the row in the grid. 
    ////Be sure that this is more efficient than linear search even in the grids with huge number of elements.
    //m_Grid.Select(GetDocument()->GetContainer()[6], true);

    m_Grid.SetEditInPlace(new CTradeViewerEditInPlace());

    return 0;
}

void CTradeViewerView::OnSize(UINT nType, int cx, int cy)
{
    //Adjust the grid to client rectangles
    CView::OnSize(nType, cx, cy);
    CRect rc;
    GetClientRect(rc);

    m_Grid.MoveWindow(rc);
}

BOOL CTradeViewerView::OnEraseBkgnd(CDC* pDC)
{
    
    //To avoid flickering we don't handle this message in the base class
    return TRUE;
    //return CView::OnEraseBkgnd(pDC);
}

void CTradeViewerView::OnDestroy()
{
    //Remove all values from the grid. Note, that the grid doesn't handle the life time of inserted objects and doesn't 
    //destroy them.
    m_Grid.DeleteAll();

    CView::OnDestroy();
}

// CTradeViewerView printing


void CTradeViewerView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTradeViewerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTradeViewerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTradeViewerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTradeViewerView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTradeViewerView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTradeViewerView diagnostics

#ifdef _DEBUG
void CTradeViewerView::AssertValid() const
{
	CView::AssertValid();
}

void CTradeViewerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTradeViewerDoc* CTradeViewerView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTradeViewerDoc)));
	return (CTradeViewerDoc*)m_pDocument;
}
#endif //_DEBUG


// CTradeViewerView message handlers
