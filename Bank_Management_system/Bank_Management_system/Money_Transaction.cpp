#include "Money_Transaction.h"
#include "Bank_System.h"
#include<iostream>
#include <fstream>

using namespace std;

int Money_Transaction::DepositAmount() {

	//.. Check if the pin is correct 
	ifstream in("Text_Code.txt");
	char Username[30];
	char Password[30];
	in >> Username;
	in >> Password;
	if (strcmp(pincode,Password)==0){
		BankBalance = BankBalance + Amount;
		return 0;
	}
	else
	{
		//..if pin is wrong
		return - 1;
	}
}
int Money_Transaction::TransferAmount() {
	while(true){
		ifstream in("Text_Code.txt");
		char Username[30];
		char Password[30];
		in >> Username;
		in >> Password;
		if (strcmp(pincode, Password)) { //..check if the pin s correct
			if (AccountNo1 > Amount) { //..check if the amount to be transfered is less than the Bank Balance 
				AccountNo1 = AccountNo1 - Amount;
				AccountNo2 = AccountNo2 + Amount;
				return 0;
				break;
			}
			else {
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
}
int Money_Transaction::WithdrawAmount() {
	while (true){
		ifstream in("Text_Code.txt");
		char Username[30];
		char Password[30];
		in >> Username;
		in >> Password;
		if (strcmp(pincode, Password)) {//..check if the pin is correct
			if (BankBalance >= Amount){//..check if the amount you want to withdraw is available
			BankBalance = BankBalance - Amount;
			return 0;
			break;
			}
			else
			{
				//..if the amount you want to withdraw is not available
				return -1;
			}
		}
		else
		{
			//..if the pin is wrong
			return -2;
		}
	}
}

//**CHANGES TO BE DONE IN THE CODE 
//..Addtional changes are to be don after merging the code 
//1. change the pin system and get the pin from the user 
//2. change the account money transfer system and apply it to the actual accounts 