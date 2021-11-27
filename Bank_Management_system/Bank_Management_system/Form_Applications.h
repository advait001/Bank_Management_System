#pragma once
#include<iostream>
class Form_Applications 
{
public:
	char name[20];
	unsigned int PhnNo;
	unsigned short Age;
	unsigned int AccNumber;
	unsigned int aadharNumber;
	unsigned int SalarySlipNo;
	char PanCardNO[20];
	unsigned int LoanAmount;
	char Reason[30];
	unsigned short Loan_Interest_Rate = 6; //..6%
	unsigned int Loan_Principle_Amount;
	unsigned short Loan_Time_Period;
	unsigned int Salary;
	unsigned int Loan_Interest_Amount;
	unsigned int Total_Amount;
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
	unsigned short TotalTime;
	unsigned int Return_Total_Time;
	unsigned int TotalMoneyToBePaidPerMonth;
	unsigned short N;
	char Others[30];
public:
	void PersonalInformation();
	void CreditCard();
	void DebitCard();
	void ChequeBook();
	void Loan(unsigned short TotalTime);
	int Conversions();
	int ReasonForTakingLoan();
};

