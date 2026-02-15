#include "stdafx.h"
#include "CsvReader.h"
#include <fstream>
#include <algorithm>

#ifndef Assert
    #include <assert.h>
    #define Assert assert
    #define LogToFile (void)(0);
#endif

namespace
{
    /// For parsing state enumerated value
    enum ParseState
    {
        STATE_NORMAL = 0, ///< general state
        STATE_QUOTE       ///< Status after quotation marks
    };

    /// Returns a string by removing spaces on the left and right sides. .
    std::string Trim(std::string str)
    {
        str = str.erase(str.find_last_not_of(" \t\r\n") + 1);
        str = str.erase(0, str.find_first_not_of(" \t\r\n"));
        return str;
    }

    /// \brief Change all letters in a given sentence to lowercase .
    std::string Lower(std::string original)
    {
        std::transform(original.begin(), original.end(), original.begin(), tolower);
        return original;
    }
}

////////////////////////////////////////////////////////////////////////////////
/// \brief When accessing a cell , Register a name to use instead of a number .
/// \param name cell name
/// \param index cell index
////////////////////////////////////////////////////////////////////////////////
void cCsvAlias::AddAlias(const char* name, size_t index)
{
    std::string converted(Lower(name));

    Assert(m_Name2Index.find(converted) == m_Name2Index.end());
    Assert(m_Index2Name.find(index) == m_Index2Name.end());

    m_Name2Index.insert(NAME2INDEX_MAP::value_type(converted, index));
    m_Index2Name.insert(INDEX2NAME_MAP::value_type(index, name));
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Delete all data .
////////////////////////////////////////////////////////////////////////////////
void cCsvAlias::Destroy()
{
    m_Name2Index.clear();
    m_Index2Name.clear();
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Convert numeric index to name .
/// \param index numeric index
/// \return const char* name
////////////////////////////////////////////////////////////////////////////////
const char* cCsvAlias::operator [] (size_t index) const
{
    INDEX2NAME_MAP::const_iterator itr(m_Index2Name.find(index));
    if (itr == m_Index2Name.end())
    {
	sys_err("cCsvAlias: cannot find suitable conversion for index %u", (DWORD)index);
        Assert(false && "cannot find suitable conversion");
        return NULL;
    }

    return itr->second.c_str();
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Convert name to numeric index .
/// \param name name
/// \return size_t numeric index
////////////////////////////////////////////////////////////////////////////////
size_t cCsvAlias::operator [] (const char* name) const
{
    NAME2INDEX_MAP::const_iterator itr(m_Name2Index.find(Lower(name)));
    if (itr == m_Name2Index.end())
    {
        sys_err("cCsvAlias: cannot find suitable conversion for name %s", name);
	Assert(false && "cannot find suitable conversion");
        return 0;
    }

    return itr->second;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief of the given name CSV load the file .
/// \param fileName CSV file name
/// \param seperator Character to use as field separator . The default is ',' am .
/// \param quote Characters to use for quotation marks . The default is '"' am .
/// \return bool If you loaded it safely true, If not false
////////////////////////////////////////////////////////////////////////////////
bool cCsvFile::Load(const char* fileName, const char seperator, const char quote)
{
    Assert(seperator != quote);

    std::ifstream file(fileName, std::ios::in);
    if (!file) return false;

    Destroy(); // Delete existing data

    cCsvRow* row = NULL;
    ParseState state = STATE_NORMAL;
    std::string token = "";
    char buf[2048+1] = {0,};

    while (file.good())
    {
        file.getline(buf, 2048);
        buf[sizeof(buf)-1] = 0;

        std::string line(Trim(buf));
        if (line.empty() || (state == STATE_NORMAL && line[0] == '#')) continue;
        
        std::string text  = std::string(line) + "  "; // farthing lookahead That's why I'm adding it .
        size_t cur = 0;

        while (cur < text.size())
        {
            // The current mode is QUOTE When in mode ,
            if (state == STATE_QUOTE)
            {
                // '"' There are two types of characters .
                // 1. The ones on the left and right of the cell that notify you if there are special characters inside the cell.
                // 2. inside the cell '"' character '"' 2 replaced by dog
                // Of these, the one on the left in the first case is CSV If the file is normal , 
                // unconditionally STATE_NORMAL is caught in .
                // Therefore, what is at stake here is 1 In the case of the right side of , 2 It's just a case of earning .
                // 2 In this case, unconditionally '"' character 2 They appear one by one . but 1 number of times
                // Not on the right . If you write code based on this, ...
                if (text[cur] == quote)
                {
                    // The next character is '"' If it's a text , i.e. continuous '"' If it's a text 
                    // This is inside the cell '"' characters have been replaced .
                    if (text[cur+1] == quote)
                    {
                        token += quote;
                        ++cur;
                    }
                    // The next character is '"' Unless it's a text 
                    // present '"' This character can be said to signal the end of a cell. .
                    else
                    {
                        state = STATE_NORMAL;
                    }
                }
                else
                {
                    token += text[cur];
                }
            }
            // The current mode is NORMAL When in mode ,
            else if (state == STATE_NORMAL)
            {
                if (row == NULL)
                    row = new cCsvRow();

                // ',' If you encounter a character, it means the end of the cell. .
                // Put it in the cell list as a token , Initialize the token .
                if (text[cur] == seperator)
                {
                    row->push_back(token);
                    token.clear();
                }
                // '"' If you encounter a text message , QUOTE switch to mode .
                else if (text[cur] == quote)
                {
                    state = STATE_QUOTE;
                }
                // If it is another regular character, it is appended to the current token. .
                else
                {
                    token += text[cur];
                }
            }

            ++cur;
        }

        // The last cell is at the end ',' Since there are no characters, you need to add them here. .
        // step , parse first lookahead That's why I removed the two space characters. .
        if (state == STATE_NORMAL)
        {
            Assert(row != NULL);
            row->push_back(token.substr(0, token.size()-2));
            m_Rows.push_back(row);
            token.clear();
            row = NULL;
        }
        else
        {
            token = token.substr(0, token.size()-2) + "\r\n";
        }
    }

    return true;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief What you have CSV Save to file .
/// \param fileName CSV file name
/// \param append true In case of , Append to existing file . false In case 
/// Delete the existing file contents , write a new one .
/// \param seperator Character to use as field separator . The default is ',' am .
/// \param quote Characters to use for quotation marks . The default is '"' am .
/// \return bool If you saved it safely true, If an error occurs false
////////////////////////////////////////////////////////////////////////////////
bool cCsvFile::Save(const char* fileName, bool append, char seperator, char quote) const
{
    Assert(seperator != quote);

    // Creates a file with appropriate flags according to the output mode. .
    std::ofstream file;
    if (append) { file.open(fileName, std::ios::out | std::ios::app); }
    else { file.open(fileName, std::ios::out | std::ios::trunc); }

    // If you can't open the file , false returns .
    if (!file) return false;

    char special_chars[5] = { seperator, quote, '\r', '\n', 0 };
    char quote_escape_string[3] = { quote, quote, 0 };

    // traversing every row ...
    for (size_t i=0; i<m_Rows.size(); i++)
    {
        const cCsvRow& row = *((*this)[i]);

        std::string line;

        // Traversing all tokens in a row ...
        for (size_t j=0; j<row.size(); j++)
        {
            const std::string& token = row[j];

            // general ('"' or ',' does not contain ) 
            // If it's a token, just save it. .
            if (token.find_first_of(special_chars) == std::string::npos)
            {
                line += token;
            }
            // If a token contains special characters, place them on the left and right sides of the string. '"' Attach ,
            // inside the string '"' should be made into two .
            else
            {
                line += quote;

                for (size_t k=0; k<token.size(); k++)
                {
                    if (token[k] == quote) line += quote_escape_string;
                    else line += token[k];
                }

                line += quote;
            }

            // unless it is the last cell ',' must be added to the end of the token. .
            if (j != row.size() - 1) { line += seperator; }
        }

        // output a line .
        file << line << std::endl;
    }

    return true;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Delete all data from memory .
////////////////////////////////////////////////////////////////////////////////
void cCsvFile::Destroy()
{
    for (ROWS::iterator itr(m_Rows.begin()); itr != m_Rows.end(); ++itr)
        delete *itr;

    m_Rows.clear();
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Returns the row at the corresponding index .
/// \param index index
/// \return cCsvRow* the row
////////////////////////////////////////////////////////////////////////////////
cCsvRow* cCsvFile::operator [] (size_t index)
{
    Assert(index < m_Rows.size());
    return m_Rows[index];
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Returns the row at the corresponding index .
/// \param index index
/// \return const cCsvRow* the row
////////////////////////////////////////////////////////////////////////////////
const cCsvRow* cCsvFile::operator [] (size_t index) const
{
    Assert(index < m_Rows.size());
    return m_Rows[index];
}

////////////////////////////////////////////////////////////////////////////////
/// \brief constructor
////////////////////////////////////////////////////////////////////////////////
cCsvTable::cCsvTable()
: m_CurRow(-1)
{
}

////////////////////////////////////////////////////////////////////////////////
/// \brief destructor
////////////////////////////////////////////////////////////////////////////////
cCsvTable::~cCsvTable()
{
}

////////////////////////////////////////////////////////////////////////////////
/// \brief of the given name CSV load the file .
/// \param fileName CSV file name
/// \param seperator Character to use as field separator . The default is ',' am .
/// \param quote Characters to use for quotation marks . The default is '"' am .
/// \return bool If you loaded it safely true, If not false
////////////////////////////////////////////////////////////////////////////////
bool cCsvTable::Load(const char* fileName, const char seperator, const char quote)
{
    Destroy();
    return m_File.Load(fileName, seperator, quote);
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Go to next line .
/// \return bool If you have safely moved on to the next line true and return , no more
/// If there is no row to skip false returns .
////////////////////////////////////////////////////////////////////////////////
bool cCsvTable::Next()
{
    // 20 If you call it about a billion times, an overflow will occur. ... It'll be okay ?
    return ++m_CurRow < (int)m_File.GetRowCount() ? true : false;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Returns the cell number of the current row .
/// \return size_t Cell number in current row
////////////////////////////////////////////////////////////////////////////////
size_t cCsvTable::ColCount() const
{
    return CurRow()->size();
}

////////////////////////////////////////////////////////////////////////////////
/// \brief using the index int Returns cell value as type .
/// \param index cell index
/// \return int cell value
////////////////////////////////////////////////////////////////////////////////
int cCsvTable::AsInt(size_t index) const
{
    const cCsvRow* const row = CurRow();
    Assert(row);
    Assert(index < row->size());
    return row->AsInt(index);
}

////////////////////////////////////////////////////////////////////////////////
/// \brief using the index double Returns cell value as type .
/// \param index cell index
/// \return double cell value
////////////////////////////////////////////////////////////////////////////////
double cCsvTable::AsDouble(size_t index) const
{
    const cCsvRow* const row = CurRow();
    Assert(row);
    Assert(index < row->size());
    return row->AsDouble(index);
}

////////////////////////////////////////////////////////////////////////////////
/// \brief using the index std::string Returns cell value as type .
/// \param index cell index
/// \return const char* cell value
////////////////////////////////////////////////////////////////////////////////
const char* cCsvTable::AsStringByIndex(size_t index) const
{
    const cCsvRow* const row = CurRow();
    Assert(row);
    Assert(index < row->size());
    return row->AsString(index);
}

////////////////////////////////////////////////////////////////////////////////
/// \brief alias Delete all data including .
////////////////////////////////////////////////////////////////////////////////
void cCsvTable::Destroy()
{
    m_File.Destroy();
    m_Alias.Destroy();
    m_CurRow = -1;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief returns the current row .
/// \return const cCsvRow* If there is a current accessible row,
/// returns a pointer , If there are no more accessible rows NULL second 
/// return .
////////////////////////////////////////////////////////////////////////////////
const cCsvRow* const cCsvTable::CurRow() const
{
    if (m_CurRow < 0)
    {
        Assert(false && "call Next() first!");
        return NULL;
    }
    else if (m_CurRow >= (int)m_File.GetRowCount())
    {
        Assert(false && "no more rows!");
        return NULL;
    }

    return m_File[m_CurRow];
}

