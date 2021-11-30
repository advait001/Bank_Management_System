#include <iostream>
#include <fstream>
#include "Balance_Inquiry.h"
#include "Main_menu.h"

using namespace std;

void Balance_Inquiry:: Show_Balance()
{
	//..Take Account_Number input 
	for (unsigned short num = 0; num <= Array_Size; num++)
	{
		if (Acc_num_Data[num] == Account_number)
		{
			Display_Output(num);
		}
	}

}

void Balance_Inquiry::Display_Output(unsigned short num)
{
	Line_func(1);
	cout << "| Account Holder Name: " << Acc_User_Name_Data[num] << endl;
	cout << "| Account Number : " << Account_number << endl;
	cout << "| Account Balance : " << Acc_Balance_Data[num] << endl;
	Line_func(0);
}

void Balance_Inquiry::Account_List()
{
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