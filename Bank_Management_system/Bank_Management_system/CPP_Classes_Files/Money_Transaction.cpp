#include "../Header_Files/Money_Transaction.h"
#include "../Header_Files/Bank_System.h"
#include "../Header_Files/Main_menu.h"
#include<iostream>
#include <fstream>

using namespace std;

Main_menu Object;

int Money_Transaction::DepositAmount() {

	Option = 1;
	//.. Check if the pin is correct 
	fstream _read;
	_read.open("Test_Files//User_Login_Info.txt", ios::in);
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

		if (strcmp(Pass_word, Password) == 0) {
			while (Ask != 0)
			{
				cout << "\tEnter 1 to see the Account details and BAnk Balance before depostiting money or enter 0 to continue: " << endl;
				cin >> Ask;
				if (Ask == 1)
				{
					Before_Transaction();
					Deposit();
					Ask = 0;
				}
				else if (Ask == 0)
				{
					Ask = 0;
					return 0;
				}
				else if (Ask != 1 && Ask != 0)
				{
					cout << "Wrong input entered" << endl;
				}
			}
		}
		else
		{
			//..if pin is wrong
			return -1;
		}
	}
}
int Money_Transaction::TransferAmount() {

	Option = 2;
	fstream _read;
	_read.open("Test_Files//User_Login_Info.txt", ios::in);
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

		while (Ask != 0)
		{

			cout << "\tEnter 1 to see the Account details and Bank Balance before transfering the money or enter 0 to continue: " << endl;
			cin >> Ask;

			if (Ask == 1)
			{
				Before_Transaction();
				if (strcmp(Pass_word, Password) == 0) { //..check if the pin s correct
					if (AccountNo1 > Amount) { //..check if the amount to be transfered is less than the Bank Balance 
						Transfer();
						break;
					}
					else
					{
						//..if bank balance is less than the transferring amount 
						return -2;
					}
					Ask = 0;
				}
				else
				{
					//..if the pin is wrong
					return -1;
				}
			}
			else if (Ask == 0) {
				if (strcmp(pincode, Password) == 0) { //..check if the pin s correct
					if (AccountNo1 > Amount) { //..check if the amount to be transfered is less than the Bank Balance 
						Transfer();
						break;
					}
					else
					{
						//..if bank balance is less than the transferring amount 
						return -2;
					}
				}
				else
				{
					//..if the pin is wrong
					return -1;
				}
			}
			else if (Ask != 1 && Ask != 0)
			{
				cout << "Wrong Input. " << endl;
			}
		}
	}
}
int Money_Transaction::WithdrawAmount() {

	Option = 3;
	while (true){
		fstream _read;
		_read.open("Test_Files//User_Login_Info.txt", ios::in);
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

			while (Ask != 0)
			{
				cout << "\tEnter 1 to see the Account details and Bank Balance before Withdrawing the money or enter 0 to continue: " << endl;
				cin >> Ask;
				if (Ask == 1)
				{
					Before_Transaction();
					if (strcmp(Pass_word, Password) == 0) {//..check if the pin is correct
						Input = Withdraw();
						if (Input == 0)
						{
							return 0;
							break;
						}
						else if (Input == -1)
						{
							return -1;
						}
					}
					else
					{
						//..if the pin is wrong
						return -2;
					}
					Ask = 0;
				}
				else if (Ask == 0) {
					if (strcmp(Pass_word, Password) == 0) {//..check if the pin is correct
						Input = Withdraw();
						if (Input == 0)
						{
							return 0;
							break;
						}
						else if (Input == -1)
						{
							return -1;
						}
					}
					else
					{
						//..if the pin is wrong
						return -2;
					}
				}
				else if (Ask != 0 && Ask != 1)
				{
					cout << "Wrong number entered." << endl;
				}
			}
		}
	}
}

void Money_Transaction::Transfer()
{
	for (unsigned short num = 0; num <= 15; num++)
	{
		if (Acc_num_Data[num] == AccountNo1)
		{
			Acc_Balance_Data[num] = Acc_Balance_Data[num] - Amount;
			for (unsigned short number = 0; number <= 15; number++)
			{
				if (Acc_num_Data[number] == AccountNo2)
				{
					Acc_Balance_Data[number] = Acc_Balance_Data[number] + Amount;
					Object.Line_func(1);
					cout << "\n\tAccount Name : "<< Acc_User_Name_Data[num] << " Account number : " << AccountNo1 << " Account Balance : " << Acc_Balance_Data[num] << endl;
					cout << "\tAccount Name : " << Acc_User_Name_Data[number] << " Account number : " << AccountNo2 << " Account Balance : " << Acc_Balance_Data[number] << endl;
					Object.Line_func(0);
					break;
				}
			}
		}
		else
		{
			continue;
		}
	}
}

int Money_Transaction::Withdraw()
{
	for (unsigned short num = 0; num <= 15; num++)
	{
		if (Acc_num_Data[num] == AccountNo1)
		{
			if (Acc_Balance_Data[num] > Amount)
			{
				Acc_Balance_Data[num] = Acc_Balance_Data[num] - Amount;
				Object.Line_func(1);
				cout << "\tCollect your amount : " << Amount << endl;
				cout << "\tAccount Name : " << Acc_User_Name_Data[num] << "\n\tAccount number : " << AccountNo1 << "\n\tAccount Balance : " << Acc_Balance_Data[num] << endl;
				Object.Line_func(0);
				return 0;
			}
			else if (Acc_Balance_Data[num] < Amount)
			{
				return -1;
			}
			
		}
		else
		{
			continue;
		}
	}
}

int Money_Transaction::Deposit()
{
	for (unsigned short num = 0; num <= 15; num++)
	{
		if (Acc_num_Data[num] == AccountNo1)
		{
			if (Acc_Balance_Data[num] > Amount)
			{
				Acc_Balance_Data[num] = Acc_Balance_Data[num] + Amount;
				Object.Line_func(1);
				cout << "\t" << Amount << " Deposited Successfully." << endl;;
				cout << "\tAccount Name : " << Acc_User_Name_Data[num] << "\n\tAccount number : " << AccountNo1 << "\n\tAccount Balance : " << Acc_Balance_Data[num] << endl;
				Object.Line_func(0);
				return 0;
			}
			else if (Acc_Balance_Data[num] < Amount)
			{
				return -1;
			}

		}
		else
		{
			continue;
		}
	}
}

void Money_Transaction::Before_Transaction()
{
	if (Option == 1 || Option == 3)
	{
		for (unsigned short num = 0; num <= 15; num++)
		{
			if (Acc_num_Data[num] == AccountNo1)
			{
				cout << "\tAccount Name : " << Acc_User_Name_Data[num] << "\n\tAccount number : " << AccountNo1 << "\n\tAccount Balance : " << Acc_Balance_Data[num] << endl;
				break;
			}
		}
	}
	else if (Option == 2)
	{
		for (unsigned short num = 0; num <= 15; num++)
		{
			if (Acc_num_Data[num] == AccountNo1)
			{
				Object.Line_func(1);
				cout << "\n\tAccount Name : " << Acc_User_Name_Data[num] << " Account number : " << AccountNo1 << " Account Balance : " << Acc_Balance_Data[num] << endl;
				for (unsigned short number = 0; number <= 15; number++)
				{
					if (Acc_num_Data[number] == AccountNo2)
					{
						cout << "\tAccount Name : " << Acc_User_Name_Data[number] << " Account number : " << AccountNo2 << " Account Balance : " << Acc_Balance_Data[number] << endl;
						Object.Line_func(0);
						break;
					}
				}
			}
		}
	}
}