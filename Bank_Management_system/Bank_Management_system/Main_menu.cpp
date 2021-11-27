#include "Main_menu.h"
#include <iostream>
#include <fstream>

using namespace std;

int Main_menu::Menu()
{
	//..code pending
	cout << ".________________________________________________." << endl;
	cout << "|                   Main Menu" << endl;
	cout << "|\t1.Transactions and Transfer Money" << endl;
	cout << "|\t2.Modification of accounts" << endl;
	cout << "|\t3.Application Forms" << endl;
	cout << "|\t4.Close Account" << endl;
	cout << "|\t5.Open New Account" << endl;
	cout << "|\t6.Customer Service Help desk" << endl;
	cout << "|\t7.Offers" << endl;
	cout << "|________________________________________________." << endl;

	cin >> Main_menu_select;

	if (Main_menu_select == 1)
	{
		Withdraw_money();
	}
	else if (Main_menu_select == 2)
	{
		Account_Modification_menu();
	}
	else if (Main_menu_select == 3)
	{
		Form_Application_menu();
	}
	else
	{
		return 0;
	}
}

int Main_menu::Call_Function()
{
	cout << "Enter 1 to go back to the main menu or Enter 0 to exit throught the code" << endl;
	cin >> _Call;

	if (_Call == 0)
	{
		return 0;
	}
	else if (_Call == 1)
	{ //..Code to be continued
		Menu();
		return 0;
	}
}

int Main_menu::Withdraw_money()
{
	cout << "\n\t1.Deposit Amount\n" << endl;
	cout << "\t2.Transfer Amount\n" << endl;
	cout << "\t3.Withdraw Amount\n" << endl;
	cin >> Input;

	return Input;
}

int Main_menu::Account_Modification_menu()
{
	cout << "1. Change Account Type\n" << endl;
	cout << "2. Change Account Details\n" << endl;
	cout << "3. Change User Details\n" << endl;
	
	cin >> Input;
	return Input;
}

int Main_menu::Form_Application_menu()
{
	cout << "1.Credit Card" << endl;
	cout << "2.Debit Card" << endl;
	cout << "3.Cheque Book" << endl;
	cout << "4.Apply For Loan" << endl;

	cin >> Input;
	return Input;
}