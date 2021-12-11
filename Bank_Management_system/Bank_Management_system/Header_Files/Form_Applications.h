#pragma once
#include<iostream>
class Form_Applications 
{
public:
	char name[20];
	char PhnNo[30];
	unsigned short Age;
	char AccNumber;
	char aadharNumber;
	char SalarySlipNo;
	char PanCardNO[20];
	unsigned short Days;
	unsigned short Months;
	unsigned short Years;
	unsigned short MonthConversion;//..for calculating months into days
	unsigned short YearConversion;//..for calculating years into days
	unsigned short OneYear = 365;//..365 days
	unsigned short num;
	unsigned short even;
	unsigned short odd;
	unsigned short TotalNumberOfDays;
	unsigned short NonLeapYear;
	unsigned short TotalLeapYear;
	unsigned int Return_Total_Time;
	char others[30];
	unsigned short N; //..-->
	unsigned short N1;
	unsigned int Loan_Amount;
	unsigned int Salary;
	unsigned int Total_Amount;
	unsigned int Interest_Amount;
	unsigned int EMI_Amount;
	const unsigned int MAX_Amount = 1000000;
	const unsigned int MIN_Amount = 10000;
	const unsigned int Interest_Rate = 6;
	unsigned short TotalTime;
	const char* Reason2[100] = { "Educational Loan","Personal Loan","Car Loan","Home Loan","Business Loan" };//..Pointer
	const char* LoanAgainst[100] = { "Home","Car","Property","Business Shares" };//..Pointer
	char Others1[30];
	unsigned int RegistrationNo;
public:
	void PersonalInformation();
	void CreditCard();
	void DebitCard();
	void ChequeBook();
	void Loan(unsigned short TotalTime);
	int Conversions();
	void ReasonForTakingLoan();
	void LoanAgainstWhat();
};

