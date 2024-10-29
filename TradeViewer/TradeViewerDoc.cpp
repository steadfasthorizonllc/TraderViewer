
// TradeViewerDoc.cpp : implementation of the CTradeViewerDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TradeViewer.h"
#endif

#include "TradeViewerDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTradeViewerDoc

IMPLEMENT_DYNCREATE(CTradeViewerDoc, CDocument)

BEGIN_MESSAGE_MAP(CTradeViewerDoc, CDocument)
END_MESSAGE_MAP()

CTradeViewerDoc::CTradeViewerDoc()
{
    //if (m_csvReader == NULL)
    {
        CString tempStr = _T("hundo.csv");
        m_csvReader = new CSVReader(tempStr);

        // Retrieve the data rows
        const std::vector<std::vector<CString>>& data = m_csvReader->GetData();
        for (size_t i = 0; i < data.size(); ++i)
        {
            CTradeViewerData* trade = new CTradeViewerData();
            m_Container.push_back(trade);

            const std::vector<CString>& row = data[i];
            for (size_t j = 0; j < row.size(); ++j)
            {
                trade->m_Data.push_back(row[j]);
            }
        }
    }
}

CTradeViewerDoc::~CTradeViewerDoc()
{
}

BOOL CTradeViewerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

const CTradeViewerDoc::Container& CTradeViewerDoc::GetContainer() const
{
    return m_Container;
}

void CTradeViewerDoc::UpdateData()
{
    m_Container.clear();
    //m_Container.push_back(new CTradeViewerData(_T("object 1"), 1, 1234567890, 1.32));
    UpdateAllViews(NULL);
}

// CTradeViewerDoc serialization

void CTradeViewerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CTradeViewerDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CTradeViewerDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CTradeViewerDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CTradeViewerDoc diagnostics

#ifdef _DEBUG
void CTradeViewerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTradeViewerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTradeViewerDoc commands
