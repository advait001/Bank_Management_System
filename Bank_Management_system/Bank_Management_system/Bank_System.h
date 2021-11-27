#pragma once

class Bank_System
{
public :
	char User_name[30];
	char Password[30];
	char Email[30];
	char Re_Confirm[30];
	char name[30];
	char Phone_Number[15];
	unsigned short age;

public:
	void Greet();
	int Signup();
	int Login(char username[30],char password[30]);
};

