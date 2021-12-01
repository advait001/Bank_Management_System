#pragma once
#include "Bank_System.h"
#include<iostream>

class Money_Transaction : public Bank_System //..single level inheritance given
{
public :
	static const int pincode = 1234; // **this is to be removed when the code gets merged with the login details part 
public:
	unsigned short  AccountNo1;//This is for user
	unsigned short  AccountNo2;//This is for person receiving amount
	unsigned short PIN;
	unsigned int Amount;
	unsigned int BankBalance;
public:
	//..Function Declaration
	int DepositAmount();
	int TransferAmount();
	int WithdrawAmount();
};

//..CHANGES TO BE DONE IN THE CODE 
//..Addtional changes are to be don after merging the code 
//1. change the pin system and get the pin from the user 
//2. change the account money transfer system and apply it to the actual accounts 
