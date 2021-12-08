#pragma once
#include "Bank_System.h"
#include "Balance_Inquiry.h"
#include<iostream>

class Money_Transaction : public Bank_System , private Balance_Inquiry //..multi-level level inheritance given
{
public :
	char pincode[30]; //..pin to be taken
	unsigned int  AccountNo1;//This is for user
	unsigned int  AccountNo2;//This is for person receiving amount
	//unsigned short PIN;
	unsigned int Amount;
	unsigned int BankBalance;
	unsigned short Input;
	unsigned short Option;
	unsigned short Ask = 1;
public:
	//..Function Declaration
	int DepositAmount();
	int TransferAmount();
	int WithdrawAmount();
	void Transfer();
	int Withdraw();
	int Deposit();
	void Before_Transaction();
};

//..CHANGES TO BE DONE IN THE CODE 
//..Addtional changes are to be don after merging the code 
//1. change the pin system and get the pin from the user 
//2. change the account money transfer system and apply it to the actual accounts 
