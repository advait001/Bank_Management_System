#include "Main_menu.h"
#include <iostream>
#include <fstream>

using namespace std;

void Main_menu::Line_func(unsigned short Upper_or_Lower)
{
	//..presentation code 
	if (Upper_or_Lower == 1){
		cout << "\n.___________________________________." << endl;
	}
	else if (Upper_or_Lower == 0)
	{
		cout << ".___________________________________.\n" << endl;
	}
	//..No calculations included
}

int Main_menu::Menu()
{
	//..code pending
	//..Main menu print
	cout << "\n\t.________________________________________________." << endl;
	cout << "\t|                   Main Menu" << endl;
	cout << "\t|\t1.Transactions and Transfer Money" << endl;
	cout << "\t|\t2.Modification of accounts" << endl;
	cout << "\t|\t3.Application Forms" << endl;
	cout << "\t|\t4.Close Account" << endl;
	cout << "\t|\t5.Open New Account" << endl;
	cout << "\t|\t7.Balance Inquiry" << endl;
	cout << "\t|\t8.Tax Invoice" << endl;
	cout << "\t|________________________________________________.\n" << endl;

	//..Main menu value is returned in Main_menu_select
	cin >> Main_menu_select;
	return Main_menu_select;
}

int Main_menu::Call_Function()
{
	//..call Function 
	//..this function is used to ask the user whether they want to go back to the main menu or exit the program 
	cout << "\n\tEnter 1 to go back to the main menu or Enter 0 to exit through the code" << endl;
	cin >> _Call;

	if (_Call == 0)
	{
		//..if the user wants to exit the program
		exit(0);
		return 0;
	}
	else if (_Call == 1)
	{
		//..if user wants to back to the main menu
		Main_return_value = Menu();
		return Main_return_value;
	}
	return -1;
}

int Main_menu::Withdraw_money()
{
	//..transaction money member function object selection menu
	Line_func(1);
	cout << "\t1.Deposit Amount\n" << endl;
	cout << "\t2.Transfer Amount\n" << endl;
	cout << "\t3.Withdraw Amount" << endl;
	Line_func(0);
	cin >> Input;

	return Input;
}

int Main_menu::Account_Modification_menu()
{
	//..Account modification member function object selection menu
	Line_func(1);
	cout << "1. Change Account Type" << endl;
	cout << "2. Change Account Details" << endl;
	cout << "3. Change User Details" << endl;
	Line_func(0);

	cin >> Input;
	return Input;
}

int Main_menu::Form_Application_menu()
{
	//..Form Application member function object selection menu
	Line_func(1);
	cout << "1.Credit Card" << endl;
	cout << "2.Debit Card" << endl;
	cout << "3.Cheque Book" << endl;
	cout << "4.Apply For Loan" << endl;
	Line_func(0);

	cin >> Input;
	return Input;
}