#include "CppSQLite3.h"
#include <iostream>
#include <string>

using namespace std;

CppSQLite3DB db;

bool GetDatabase(const string& dbPath)
{
    try {
        db.open(dbPath.c_str());
        return true;
    }
    catch (CppSQLite3Exception& e)
    {
        cout << ("Cannot open database: ") << dbPath << ("\n");
        return false;
    }
}

void IssueQuery(const string& querystring, const string& field1)
{
    try 
    {
        CppSQLite3Query q = db.execQuery(querystring.c_str());
        while (!q.eof()) {
            string temp2(q.fieldValue(field1.c_str()));
            //TRACE(temp2 + _T("\n"));
            q.nextRow();
        }
    }
    catch (CppSQLite3Exception& e)
    {
        cout << ("Cannot execute query: ") << querystring << ("\n");
    }
}

void InitDB()
{
    if(GetDatabase("bank.db"))
        IssueQuery("SELECT * FROM emp", "empname");
}