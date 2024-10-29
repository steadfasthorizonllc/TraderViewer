
// TradeViewerView.h : interface of the CTradeViewerView class
//

#pragma once
#include <Dapfor/GUI/Grid.h>
#include "TradeViewerDoc.h"

class CTradeViewerView : public CView
{
protected: // create from serialization only
	CTradeViewerView();
	DECLARE_DYNCREATE(CTradeViewerView)

// Attributes
public:
	CTradeViewerDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
    virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CTradeViewerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
public:
	Dapfor::GUI::CGrid m_Grid;

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);

    afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnDestroy();

	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TradeViewerView.cpp
inline CTradeViewerDoc* CTradeViewerView::GetDocument() const
   { return reinterpret_cast<CTradeViewerDoc*>(m_pDocument); }
#endif

