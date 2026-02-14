#ifndef __CSVFILE_H__
#define __CSVFILE_H__

#include <string>
#include <vector>

#if _MSC_VER
    #include <unordered_map>
#else
    #include <map>
#endif

////////////////////////////////////////////////////////////////////////////////
/// \class cCsvAlias
/// \brief CSV To reduce index problems that occur when files are modified 
/// alias object .
///
/// for example 0 This column is A Includes information about , 1 This column is B About 
/// It was included ...
///
/// <pre>
/// int a = row.AsInt(0);
/// int b = row.AsInt(1);
/// </pre>
///
/// Meanwhile C When a column containing content about , hard coded 
/// 1 I need to find the number and fix it. , This is a fairly error-prone task. . 
///
/// <pre>
/// int a = row.AsInt(0);
/// int c = row.AsInt(1);
/// int b = row.AsInt(2); <-- You need to pay attention to this part one by one .
/// </pre>
/// 
/// If you process this part as a string, you can slightly reduce the maintenance effort. 
/// there is .
////////////////////////////////////////////////////////////////////////////////

class cCsvAlias
{
private:
#if _MSC_VER
    typedef std::unordered_map<std::string, size_t> NAME2INDEX_MAP;
    typedef std::unordered_map<size_t, std::string> INDEX2NAME_MAP;
#else
    typedef std::map<std::string, size_t> NAME2INDEX_MAP;
    typedef std::map<size_t, std::string> INDEX2NAME_MAP;
#endif

    NAME2INDEX_MAP m_Name2Index;  ///< Names to use instead of cell indices
    INDEX2NAME_MAP m_Index2Name;  ///< erroneous alias Additional maps to check


public:
    /// \brief constructor
    cCsvAlias() {} 

    /// \brief destructor
    virtual ~cCsvAlias() {}


public:
    /// \brief When accessing a cell , Register a name to use instead of a number .
    void AddAlias(const char* name, size_t index);

    /// \brief Delete all data .
    void Destroy();

    /// \brief Convert numeric index to name .
    const char* operator [] (size_t index) const;

    /// \brief Convert name to numeric index .
    size_t operator [] (const char* name) const;


private:
    /// \brief No copy constructors
    cCsvAlias(const cCsvAlias&) {}

    /// \brief Assignment operator prohibited
    const cCsvAlias& operator = (const cCsvAlias&) { return *this; }
};


////////////////////////////////////////////////////////////////////////////////
/// \class cCsvRow 
/// \brief CSV A class that encapsulates one line of a file
///
/// CSV The default format is one visible cell in Excel. ',' Separated by letters .
/// but , Special characters used in cells ',' Text or '"' When text is entered , 
/// The shape changes slightly strangely . Here is an example of the change: .
/// 
/// <pre>
/// What it looks like in Excel | actual CSV What appears in the file
/// ---------------------+----------------------------------------------------
/// ItemPrice            | ItemPrice
/// Item,Price           | "Item,Price"
/// Item"Price           | "Item""Price"
/// "ItemPrice"          | """ItemPrice"""
/// "Item,Price"         | """Item,Price"""
/// Item",Price          | "Item"",Price"
/// </pre>
/// 
/// As an example, you can see the following: .
/// - inside the cell ',' or '"' When text is entered , on the left and right of the cell '"' A character appears .
/// - inside the cell '"' The text is 2 replaced by a dog .
///
/// \sa cCsvFile
////////////////////////////////////////////////////////////////////////////////

class cCsvRow : public std::vector<std::string>
{
public:
    /// \brief default constructor
    cCsvRow() {}

    /// \brief destructor
    ~cCsvRow() {}


public:
    /// \brief data in that cell int return as type .
    int AsInt(size_t index) const { return atoi(at(index).c_str()); }

    /// \brief data in that cell double return as type .
    double AsDouble(size_t index) const { return atof(at(index).c_str()); }

    /// \brief Returns the data of the cell as a string .
    const char* AsString(size_t index) const { return at(index).c_str(); }

    /// \brief Cell data with the corresponding name int return as type .
    int AsInt(const char* name, const cCsvAlias& alias) const {
        return atoi( at(alias[name]).c_str() ); 
    }

    /// \brief Cell data with the corresponding name int return as type .
    double AsDouble(const char* name, const cCsvAlias& alias) const {
        return atof( at(alias[name]).c_str() ); 
    }

    /// \brief Returns cell data with the corresponding name as a string. .
    const char* AsString(const char* name, const cCsvAlias& alias) const { 
        return at(alias[name]).c_str(); 
    }


private:
    /// \brief No copy constructors
    cCsvRow(const cCsvRow&) {}

    /// \brief Assignment operator prohibited
    const cCsvRow& operator = (const cCsvRow&) { return *this; }
};


////////////////////////////////////////////////////////////////////////////////
/// \class cCsvFile
/// \brief CSV(Comma Seperated Values) file read/write class to do
///
/// <b>sample</b>
/// <pre>
/// cCsvFile file;
///
/// cCsvRow row1, row2, row3;
/// row1.push_back("ItemPrice");
/// row1.push_back("Item,Price");
/// row1.push_back("Item\"Price");
///
/// row2.reserve(3);
/// row2[0] = "\"ItemPrice\"";
/// row2[1] = "\"Item,Price\"";
/// row2[2] = "Item\",Price\"";
///
/// row3 = "\"ItemPrice\"\"Item,Price\"Item\",Price\"";
///
/// file.add(row1);
/// file.add(row2);
/// file.add(row3);
/// file.save("test.csv", false);
/// </pre>
///
/// \todo Don't just read from a file , Functions that read from a memory source 
/// It seems like it should be there .
////////////////////////////////////////////////////////////////////////////////

class cCsvFile
{
private:
    typedef std::vector<cCsvRow*> ROWS;

    ROWS m_Rows; ///< row collection


public:
    /// \brief constructor
    cCsvFile() {}

    /// \brief destructor
    virtual ~cCsvFile() { Destroy(); }


public:
    /// \brief of the given name CSV load the file .
    bool Load(const char* fileName, const char seperator=',', const char quote='"');

    /// \brief What you have CSV Save to file .
    bool Save(const char* fileName, bool append=false, char seperator=',', char quote='"') const;

    /// \brief Delete all data from memory .
    void Destroy();

    /// \brief Returns the row at the corresponding index .
    cCsvRow* operator [] (size_t index);

    /// \brief Returns the row at the corresponding index .
    const cCsvRow* operator [] (size_t index) const;

    /// \brief Returns the number of rows .
    size_t GetRowCount() const { return m_Rows.size(); }


private:
    /// \brief No copy constructors
    cCsvFile(const cCsvFile&) {}

    /// \brief Assignment operator prohibited
    const cCsvFile& operator = (const cCsvFile&) { return *this; }
};


////////////////////////////////////////////////////////////////////////////////
/// \class cCsvTable
/// \brief CSV Table data is often loaded using a file. , This class is 
/// This is a utility class created to make that task easier. .
///
/// CSV When loading a file , I need to access cells using numbers. , CSV 
/// When the file format changes , These numbers need to be changed . This works quite well 
/// It requires concentration and , Error prone . Therefore, in numbers 
/// Although it is slightly slower, it is better to access it as a string rather than accessing it. .
///
/// <b>sample</b>
/// <pre>
/// cCsvTable table;
///
/// table.alias(0, "ItemClass");
/// table.alias(1, "ItemType");
///
/// if (table.load("test.csv"))
/// {
///     while (table.next())
///     {
///         std::string item_class = table.AsString("ItemClass");
///         int         item_type  = table.AsInt("ItemType"); 
///     }
/// }
/// </pre>
////////////////////////////////////////////////////////////////////////////////

class cCsvTable
{
public :
    cCsvFile  m_File;   ///< CSV file object
private:
    cCsvAlias m_Alias;  ///< Object for converting string to cell index
    int       m_CurRow; ///< Row number currently being traversed


public:
    /// \brief constructor
    cCsvTable();

    /// \brief destructor
    virtual ~cCsvTable();


public:
    /// \brief of the given name CSV load the file .
    bool Load(const char* fileName, const char seperator=',', const char quote='"');

    /// \brief When accessing a cell , Register a name to use instead of a number .
    void AddAlias(const char* name, size_t index) { m_Alias.AddAlias(name, index); }

    /// \brief Go to next line .
    bool Next();

    /// \brief Returns the cell number of the current row .
    size_t ColCount() const;

    /// \brief using the index int Returns cell value as type .
    int AsInt(size_t index) const;

    /// \brief using the index double Returns cell value as type .
    double AsDouble(size_t index) const;

    /// \brief using the index std::string Returns cell value as type .
    const char* AsStringByIndex(size_t index) const;

    /// \brief using cell name int Returns cell value as type .
    int AsInt(const char* name) const { return AsInt(m_Alias[name]); }

    /// \brief using cell name double Returns cell value as type .
    double AsDouble(const char* name) const { return AsDouble(m_Alias[name]); }

    /// \brief using cell name std::string Returns cell value as type .
    const char* AsString(const char* name) const { return AsStringByIndex(m_Alias[name]); }

    /// \brief alias Delete all data including .
    void Destroy();


private:
    /// \brief returns the current row .
    const cCsvRow* const CurRow() const;

    /// \brief No copy constructors
    cCsvTable(const cCsvTable&) {}

    /// \brief Assignment operator prohibited
    const cCsvTable& operator = (const cCsvTable&) { return *this; }
};

#endif //__CSVFILE_H__
