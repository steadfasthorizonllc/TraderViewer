#pragma once
#include "afxwin.h"
#include <vector>
#include <string>

class CAddColumnDialog : public CDialog
{
    DECLARE_DYNAMIC(CAddColumnDialog)

public:
    CAddColumnDialog(const CString& filePath, const CString& section, CWnd* pParent = nullptr);
    virtual ~CAddColumnDialog();

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_ADD_COLUMN };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL OnInitDialog();  // Initialize dialog

    DECLARE_MESSAGE_MAP()

public:
    CButton m_btnSave;
    CButton m_btnCancel;
    CCheckListBox m_checkboxList;  // ListBox control containing checkboxes

    std::vector<CString> m_columnNames; // Column names from the INI file
    std::vector<int> m_columnStates; // Checkbox states from the INI file

    afx_msg void OnBnClickedButtonSave();
    afx_msg void OnBnClickedButtonCancel();

    CString m_filePath;
    CString m_section;

    void LoadColumnsFromIniFile(); // Function to load from INI file
    void SaveColumnsToIniFile();
};
