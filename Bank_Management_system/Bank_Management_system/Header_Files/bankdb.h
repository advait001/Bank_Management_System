#pragma once
#include <string>

//..Database SQLite Header file

using namespace std;

//..Functions Used 
bool GetDatabase(const string& dbPath);
void IssueQuery(const string& querystring, const string& field1);
void InitDB();