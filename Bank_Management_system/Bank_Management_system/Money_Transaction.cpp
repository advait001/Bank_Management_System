#include "Money_Transaction.h"
#include "Bank_System.h"
#include<iostream>

using namespace std;

int Money_Transaction::DepositAmount() {

	while(true) {
		//.. Check if the pin is correct 
		if (pincode == PIN){
			BankBalance = BankBalance + Amount;
			return 0;
			break;
		}
		else
		{
			//..if pin is wrong
			return - 1;
		}
	}
}
int Money_Transaction::TransferAmount() {
	while(true){
		if (pincode == PIN){ //..check if the pin is correct
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
		if (pincode == PIN){//..check if the pin is correct
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