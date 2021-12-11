#include "../Header_Files/Bank_Staff.h"
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
		fstream new_file;
		new_file.open("Test_Files//Bank_Staff.txt", ios::out | ios::app);
		if (!new_file)
		{
			cout << "New file creation failed";
		}
		else
		{
			new_file << username << "\n" << password << endl;
			new_file.close();
		}

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
	fstream _read;
	_read.open("Test_Files//Bank_Staff.txt", ios::in);
	if (!_read)
	{
		cout << "No such file directiry found" << endl;
	}
	else
	{
		char user_name[30];
		char Pass_word[30];

		_read >> user_name;
		_read >> Pass_word;

		_read.close();

		if (strcmp(user_name, username) == 0)
		{
			//..compare the username in the text file with the username entered
			if (strcmp(Pass_word, password) == 0)
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
	}
	return 0;
}
