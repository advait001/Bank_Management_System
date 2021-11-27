#include "Bank_Staff.h"
#include <iostream>
#include <fstream>

using namespace std;

int Bank_Staff::Bank_Signup_ID(char username [30],char password [30],char Re_Confirm [30])
{
	//..the data that will accessible to only bank officials 
	//..Bank management login creation
	//..Signup code for bank management staff
	if (strcmp(Re_Confirm, password) == 0)
	{
		//..Confirmed password is Correct
		//..wirte the username and password in the directory
		ofstream write("Bank_Staff.txt");
		write << username << "\n" << password;

		return 0;
	}
	else
	{
		//..reconfirmed Password is incorect
		return -1;
	}
	
	return 0;
}

int Bank_Staff::Login(char username[30], char password[30])
{
	//..read the username and password from the Bank_staff.txt file 
	ifstream in("Bank_Staff.txt");
	char Read[30];
	char PWD[30];
	in >> Read;
	in >> PWD;

	if (strcmp(Read, username) == 0)
	{
		//..compare the username in the text file with the username entered
		if (strcmp(PWD, password) == 0)
			//.. Username matched login confirmed
			return 0;
		else
			//..wrong passsword
			return -1;
	}
	else
	{
		//..user not found
		return -2;
	}
	return 0;
}
