#include "Bank_System.h"
#include <iostream>
#include <fstream>

using namespace std;

void Bank_System :: Greet()
{
	//..Welcome text
	//..Basic function to represent the welccome text at the start
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
	ofstream write("Text_Code.txt");
	write << User_name << "\n" << Password;
	
	return 0;
}

int Bank_System::Login(char username[30], char password[30])
{
	//..Login Logic Memeber function
	//..Read Username and Password from the Text_Code.txt file
	ifstream in("Text_Code.txt");
	char Read[30];
	char PWD[30];
	in >> Read;
	in >> PWD;

	//..Compare the username and password 
	if (strcmp(Read, username) == 0)
	{
		//..If username matches 
		if (strcmp(PWD, password) == 0){
			//..if password matches 
			cout << "\n\tuser loged in Successfully" << endl;
		}
		else{
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
	return 0;
}