#include "Bank_System.h"
#include <iostream>
#include <fstream>

using namespace std;

void Bank_System :: Greet()
{
	cout << "\n\n\t\t\t\t   Welcome to Bank Management System	  " << endl;
	cout << "\t\t\t\t._____________________________________." << endl;
}

int Bank_System::Signup()
{
	//Username and password section
	cout << "\tUsername: ";
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
			cout << "\tSign up successfull , Welcome to the bank management system" << endl;
			break;
		}
		else
		{
			cout << "\n\n\tThe password entered for re-confirmation does not match with the passord in the first coloumn !!!" << endl;
		}
	}

	ofstream write("Text_Code.txt");
	write << User_name << "\n" << Password;
	
	return 0;
}

int Bank_System::Login(char username[30], char password[30])
{
	ifstream in("Text_Code.txt");
	char Read[30];
	char PWD[30];
	in >> Read;
	in >> PWD;

	if (strcmp(Read, username) == 0)
	{
		if (strcmp(PWD, password) == 0)
			cout << "\n\tuser loged in Successfully" << endl;
		else
			cout << "\n\tWrong Password" << endl;
	}
	else
	{
		cout << "\n\tUser not found" << endl;
	}
	return 0;
}