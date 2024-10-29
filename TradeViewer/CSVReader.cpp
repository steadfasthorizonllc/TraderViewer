#include "stdafx.h"
#include "CSVReader.h"
#include <fstream>      // std::ifstream
#include <sstream>      // std::istringstream

// Constructor 1: Read from a CSV file
CSVReader::CSVReader(const CString& filePath)
{
    ReadFromFile(filePath);
}

// Constructor 2: Copy constructor
CSVReader::CSVReader(const CSVReader& other)
{
    m_title = other.m_title;
    m_data = other.m_data;
}

// Return the title row
const std::vector<CString>& CSVReader::GetTitle() const
{
    return m_title;
}

// Return the data rows
const std::vector<std::vector<CString>>& CSVReader::GetData() const
{
    return m_data;
}

// Read data from the CSV file
void CSVReader::ReadFromFile(const CString& filePath)
{
    std::ifstream file(CT2A(filePath.GetString())); // Open the CSV file

    if (!file.is_open())
    {
        return;
    }

    std::string line;
    bool isFirstLine = true;

    // Read each line from the CSV file
    while (std::getline(file, line))
    {
        std::vector<CString> parsedLine = ParseLine(line);

        if (isFirstLine)
        {
            // The first line is the title row
            m_title = parsedLine;
            isFirstLine = false;
        }
        else
        {
            // The remaining lines are data rows
            m_data.push_back(parsedLine);
        }
    }

    file.close();
}

// Parse a single line from the CSV file
std::vector<CString> CSVReader::ParseLine(const std::string& line)
{
    std::vector<CString> parsedValues;
    std::istringstream ss(line);
    std::string token;

    // Split the string by the '|' character
    while (std::getline(ss, token, '|'))
    {
        parsedValues.push_back(CString(token.c_str()));
    }

    return parsedValues;
}
