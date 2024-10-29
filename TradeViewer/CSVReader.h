#pragma once
#include <afx.h>        // CFile, CString, etc.
#include <vector>       // std::vector

class CSVReader
{
public:
    // Constructor 1: Read from a CSV file
    CSVReader(const CString& filePath);

    // Constructor 2: Copy constructor
    CSVReader(const CSVReader& other);

    // Return the title row
    const std::vector<CString>& GetTitle() const;

    // Return the data rows
    const std::vector<std::vector<CString>>& GetData() const;

private:
    std::vector<CString> m_title;                    // Title row
    std::vector<std::vector<CString>> m_data;        // Data rows

    // Read data from the CSV file
    void ReadFromFile(const CString& filePath);

    // Parse a single line from the CSV file
    std::vector<CString> ParseLine(const std::string& line);
};