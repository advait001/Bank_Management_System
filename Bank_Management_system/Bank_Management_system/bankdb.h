#pragma once
#include <string>
using namespace std;

bool GetDatabase(const string& dbPath);
void IssueQuery(const string& querystring, const string& field1);
void InitDB();