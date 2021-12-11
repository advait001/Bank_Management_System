#include <iostream>
#include <fstream>
#include "../Header_Files/Balance_Inquiry.h"
#include "../Header_Files/Main_menu.h"

using namespace std;

void Balance_Inquiry:: Show_Balance()
{
	//..Take Account_Number input 
	//..Binary searching used .
	for (unsigned short num = 0; num <= Array_Size; num++)
	{
		if (Acc_num_Data[num] == Account_number)
		{
			//..Display representation output
			Display_Output(num);
			break;
		}
	}

}

void Balance_Inquiry::Display_Output(unsigned short num)
{
	//..Dsiplay Function
	//..Dislpays the account balance in a representable format
	Line_func(1);//..Line function used 
	cout << "| Account Holder Name: " << Acc_User_Name_Data[num] << endl;
	cout << "| Account Number : " << Account_number << endl;
	cout << "| Account Balance : " << Acc_Balance_Data[num] << endl;
	Line_func(0); //..Line function close 
	//..Inheritance used from class main menu
}

void Balance_Inquiry::Account_List()
{
	//..this function prints the Account number list from the Database
	Line_func(1);
	cout << "|\tAccount Number List" << endl;
	for (int num = 1; num <= 9; num++)
	{
		for (int i = 0;i <= 8;i++)
		{
			cout << "| 20014800" << num << endl;
			break;
		}
	}
	for (int num = 10; num <= 15; num++)
	{
		for (int i = 9;i <= 14;i++)
		{
			cout << "| 2001480" << num << endl;
			break;
		}
	}
	Line_func(0);
}

void Balance_Inquiry::Ask_Account_List()
{
	while (input != 0)
	{
	cout << "\tEnter 1 to see the Account numbers list or enter 0 to to continue: ";
	cin >> input;
		if (input == 1)
		{
			Account_List();
			input = 0;
		}
		else if (input == 0)
		{
			return;
		}
		else
		{
			cout << "\tWrong input !!!";
		}
	}
}
