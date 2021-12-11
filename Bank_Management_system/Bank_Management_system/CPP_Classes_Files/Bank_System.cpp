#include "../Header_Files/Bank_System.h"
#include <iostream>
#include <fstream>

using namespace std;

void Bank_System :: Greet()
{
	//..Welcome text
	//..Basic function to represent the welcome text at the start
	cout << "\n\n\t\t\t\t   Welcome to Bank Management System	  " << endl;
	cout << "\t\t\t\t._____________________________________." << endl;
}

int Bank_System::Signup()
{
	//Username and password section
	cout << "\tUser-name: ";
	cin >> User_name;

	while (true)
	{
		cout << "\n\tPassword: ";
		cin >> Password;
		//reconfirm the password entered by the user
		cout << "\tReconfirm the Password: ";
		cin >> Re_Confirm;
		//if (Re_Confirm == Password)
		if (strcmp(Re_Confirm, Password) == 0)
		{
			//..Sign up was successful
			cout << "\tSign up successfull , Welcome to the bank management system" << endl;
			break;
		}
		else
		{
			//..Wrong password entered for reconfirmation
			cout << "\n\n\tThe password entered for re-confirmation does not match with the passord in the first coloumn !!!" << endl;
		}
	}

	//..Write text in Text_Code.txt file 
	fstream new_file;
	new_file.open("C:\\Users\\advai\\OneDrive\\Documents\\GitHub\\Bank_Management_System\\Bank_Management_system\\Bank_Management_system\\Test_Files\\User_Login_Info.txt", ios::out | ios::app);
	if (!new_file)
	{
		cout << "New file creation failed";
	}
	else
	{
		new_file << User_name << "\n" << Password << endl;
		new_file.close();
	}

	return 0;
}

int Bank_System::Login(char username[30], char password[30])
{
	//..Login Logic Memeber function
	//..Read Username and Password from the Text_Code.txt file
	fstream _read;
	_read.open("C:\\Users\\advai\\OneDrive\\Documents\\GitHub\\Bank_Management_System\\Bank_Management_system\\Bank_Management_system\\Test_Files\\User_Login_Info.txt", ios::in);
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

		//..Compare the username and password 
		if (strcmp(user_name, username) == 0)
		{
			//..If username matches 
			if (strcmp(Pass_word, password) == 0) {
				//..if password matches 
				cout << "\n\tuser loged in Successfully" << endl;
			}
			else {
				//..Wrong Password
				cout << "\n\tWrong Password" << endl;
				exit(0);
			}
		}
		else
		{
			//..Wrong Username No user found 
			cout << "\n\tUser not found" << endl;
			exit(0);
		}
	}
	return 0;
}