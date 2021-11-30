#include "CppSQLite3.h"
#include <iostream>
#include <string>

//..Database management file 
// SQLite servers and databse has been used and deployed in the code 
//.. SQLite files and funtions are placed into the folder named sqlite3 with .sln file 
//.. this databases uses the x86 architecture 
//.. this database is linked with the "CppSQLite3.h" header file


//..namespace declaration
using namespace std;

//..Object for the database is created
CppSQLite3DB Data_Base;

bool GetDatabase(const string& dbPath)
{
    try {
        //..Database accessed successfully 
        Data_Base.open(dbPath.c_str());
        return true;
    }
    catch (CppSQLite3Exception& e)
    {
        //..Unable to open the Database file 
        cout << ("Cannot open database: ") << dbPath << ("\n");
        return false;
    }
}

void IssueQuery(const string& querystring, const string& field1)
{
    try 
    {
        CppSQLite3Query q = Data_Base.execQuery(querystring.c_str());
        while (!q.eof()) {
            string temp2(q.fieldValue(field1.c_str()));
            //TRACE(temp2 + _T("\n"));
            q.nextRow();
        }
    }
    catch (CppSQLite3Exception& e)
    {
        //..Query entered doesn't match with the parameters and hence cannot be executed 
        cout << ("Cannot execute query: ") << querystring << ("\n");
    }
}

void InitDB()
{
    //..Databse file named bank.db will be created in the background on runtime 
    //..Query will be called and stored using the GetDatabase Function
    if(GetDatabase("bank.db"))
        IssueQuery("SELECT * FROM emp", "empname");
}

//CppSQLite3DB db;
//
//bool GetDatabase(const string& dbPath)
//{
//    try {
//        db.open(dbPath.c_str());
//        return true;
//    }
//    catch (CppSQLite3Exception& e)
//    {
//        cout << ("Cannot open database: ") << dbPath << ("\n");
//        return false;
//    }
//}
//
//void IssueQuery(const string& querystring, const string& field1)
//{
//    try
//    {
//        CppSQLite3Query q = db.execQuery(querystring.c_str());
//        while (!q.eof()) {
//            string temp2(q.fieldValue(field1.c_str()));
//            //TRACE(temp2 + _T("\n"));
//            q.nextRow();
//        }
//    }
//    catch (CppSQLite3Exception& e)
//    {
//        cout << ("Cannot execute query: ") << querystring << ("\n");
//    }
//}
//
//void InitDB()
//{
//    if (GetDatabase("bank.db"))
//        IssueQuery("SELECT * FROM emp", "empname");
//}