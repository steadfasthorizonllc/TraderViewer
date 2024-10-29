#include "stdafx.h"
#include "TradeViewer.h"
#include "ColumnSelectionDialog.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(CColumnSelectionDialog, CDialog)

CColumnSelectionDialog::CColumnSelectionDialog(const CString& filePath, const CString& section, CWnd* pParent /*=nullptr*/)
    : CDialog(IDD_COLUMN_SELECTION, pParent)
{
    TCHAR buffer[MAX_PATH];
    DWORD length = GetCurrentDirectory(MAX_PATH, buffer);
    CString currentDirectory(buffer);

    m_filePath = currentDirectory + "\\" + filePath;
    m_section = section;
}

CColumnSelectionDialog::~CColumnSelectionDialog()
{
}

void CColumnSelectionDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);

    DDX_Control(pDX, IDC_CHECKBOX_LIST, m_checkboxList); // Link the CCheckListBox control
}

BEGIN_MESSAGE_MAP(CColumnSelectionDialog, CDialog)
    ON_BN_CLICKED(IDC_ALL, &CColumnSelectionDialog::OnBnClickedButtonAll)
    ON_BN_CLICKED(IDC_NONE, &CColumnSelectionDialog::OnBnClickedButtonNone)
    ON_BN_CLICKED(IDOK, &CColumnSelectionDialog::OnBnClickedButtonSave)
    ON_BN_CLICKED(IDCANCEL, &CColumnSelectionDialog::OnBnClickedButtonCancel)
END_MESSAGE_MAP()

BOOL CColumnSelectionDialog::OnInitDialog()
{
    CDialog::OnInitDialog();

    // Load columns from INI file
    LoadColumnsFromIniFile();

    // Dynamically add items to the list box with checkbox style
    for (size_t i = 0; i < m_columnNames.size(); ++i)
    {
        m_checkboxList.AddString(m_columnNames[i]); // Add each item to the listbox
        m_checkboxList.SetCheck(i, m_columnStates[i]); // Set the checkbox state (checked or unchecked)
    }

    return TRUE;
}

// Event handlers
void CColumnSelectionDialog::OnBnClickedButtonAll()
{
    // Check all checkboxes
    for (size_t i = 0; i < m_checkboxList.GetCount(); ++i)
    {
        m_checkboxList.SetCheck(i, TRUE); // Select all checkboxes
    }
}

void CColumnSelectionDialog::OnBnClickedButtonNone()
{
    // Uncheck all checkboxes
    for (size_t i = 0; i < m_checkboxList.GetCount(); ++i)
    {
        m_checkboxList.SetCheck(i, FALSE); // Unselect all checkboxes
    }
}

void CColumnSelectionDialog::OnBnClickedButtonSave()
{
    // Save logic (write back to the INI file or take other action)
    SaveColumnsToIniFile();
    EndDialog(IDOK);
}

void CColumnSelectionDialog::OnBnClickedButtonCancel()
{
    EndDialog(IDCANCEL);
}

void CColumnSelectionDialog::LoadColumnsFromIniFile()
{
    // Clear previous column names and states
    m_columnNames.clear();
    m_columnStates.clear();

    // Buffer to hold the key names
    TCHAR keyBuffer[4096] = {0};  // Buffer large enough to hold all keys
    DWORD bytesRead = GetPrivateProfileString(m_section, nullptr, nullptr, keyBuffer, sizeof(keyBuffer) / sizeof(TCHAR), m_filePath);

    // If no keys are found, exit
    if (bytesRead == 0)
    {
        AfxMessageBox(_T("No keys found in the specified section."));
        return;
    }

    // Pointer to traverse the keyBuffer
    TCHAR* keyPtr = keyBuffer;

    // Loop through all keys in the section
    while (*keyPtr != '\0')
    {
        // Get the value for the current key (1 or 0)
        int state = GetPrivateProfileInt(m_section, keyPtr, 0, m_filePath);

        // Convert the key (column name) to std::string and store it
        m_columnNames.push_back(CString(keyPtr));

        // Store the checkbox state (1 = checked, 0 = unchecked)
        m_columnStates.push_back(state);

        // Move to the next key in the buffer
        keyPtr += _tcslen(keyPtr) + 1;  // Move pointer to the next key
    }
}

void CColumnSelectionDialog::SaveColumnsToIniFile()
{
    // Update m_checkboxList to m_columnStates
    for (size_t i = 0; i < m_checkboxList.GetCount(); ++i)
    {
        m_columnStates[i] = m_checkboxList.GetCheck(i);
    }

    // Ensure we have both column names and states loaded
    if (m_columnNames.size() != m_columnStates.size())
    {
        AfxMessageBox(_T("Error: The number of column names and states does not match."));
        return;
    }

    // Iterate through the columns and save each one to the INI file
    for (size_t i = 0; i < m_columnNames.size(); ++i)
    {
        // Convert the state (1 or 0) to a CString
        CString stateStr;
        stateStr.Format(_T("%d"), m_columnStates[i]);

        // Write the key (column name) and value (state) to the INI file
        WritePrivateProfileString(m_section, m_columnNames[i], stateStr, m_filePath);
    }

    // Optionally, notify the user that saving is done (you can remove this if unnecessary)
    AfxMessageBox(_T("Data has been saved successfully."));
}
