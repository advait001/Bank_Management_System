#pragma once
#include<iostream>


class Account_Modifications
{
public:
	//..For Account Type
	unsigned int CurrentBalance;
	unsigned int SavingsAccountBalance = 0;
	unsigned short InterestRate = 8;//.. for instance I've taken here  8 % of interest
	unsigned int TransferAmount;
	unsigned short TotalTime;//..TotalTime For Keeping the Money Into Saving Account(We Consider TotalTime in Days)
	unsigned int FinalAmount;
	unsigned short Days;
	unsigned short Months;
	unsigned short Years;
	unsigned short MonthConversion;//..For Calculating Months into Days
	unsigned short YearConversion;//..For Calculating Years into Days
	unsigned short OneYear = 365;//..365 days
	unsigned short num;
	unsigned short even;
	unsigned short odd;
	unsigned short TotalNumberOfDays;
	unsigned short NonLeapYear;
	unsigned short TotalLeapYear;
	//..For Account Details
	unsigned int AccountNo;
	char CustomerName [30];
	char BranchName [30];
	//..For User Details
	char Name [20];
	char Address[20];
	unsigned int PhoneNo;
	unsigned short day;
	unsigned short month;
	unsigned short year;
	unsigned int AadharNo;
	char EmailId[30];
	//..For User Authority
public:
	int AccountType();
	int ConversionAndFinalAmount(unsigned int returned_value);
	void AccountDetails();
	void UserDetails();
	int Savings_Account_returns(unsigned int simple_interest, unsigned int SavingsAccountBalance);
	int Simple_Interest(unsigned int Principle_amount, unsigned short Interest_rate, unsigned short Days, unsigned short MonthConversion, unsigned short YearConversion);
};

