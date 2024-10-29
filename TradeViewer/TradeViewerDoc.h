
// TradeViewerDoc.h : interface of the CTradeViewerDoc class
//


#pragma once

#include "TradeViewerData.h"
#include "CSVReader.h"

class CTradeViewerDoc : public CDocument
{
protected: // create from serialization only
	CTradeViewerDoc();
	DECLARE_DYNCREATE(CTradeViewerDoc)

// Attributes
public:
    //Declaration of the container. This container will keep pointers to the objects of CTestObject class
    typedef std::vector<CTradeViewerData*> Container;
    const Container& GetContainer() const;

    CSVReader* m_csvReader;

// Operations
public:
    void UpdateData();

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CTradeViewerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
    Container m_Container;

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
