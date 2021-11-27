#pragma once

class Bank_Staff
{
public :
public:
	char User_name[30];
	char Password[30];
	char Email[30];
	char Re_Confirm[30];
	char name[30];
	char Phone_Number[15];
	unsigned short age;

public:
	int Bank_Signup_ID(char username[30], char password [30], char Re_Confirm[30]);
	int Login(char username[30], char password[30]);
};

