#include "Form_Applications.h"
#include<iostream>
#include<fstream>

using namespace std;

 void Form_Applications::PersonalInformation()
 {

	cout << "Name :";
	cin >> name;

	cout << "Mobile Number : ";
	cin >> PhnNo;

	cout << "Age : ";
	cin >> Age;

	cout << "Account Number : ";
	cin >> AccNumber;

	cout << "Salary Slip Number : ";
	cin >> SalarySlipNo;

	cout << "AaDhar Number : ";
	cin >> aadharNumber;

	cout << "Pan Card Number : ";
	cin >> PanCardNO;

	ofstream write("UserAccountDetails.txt");
	write <<"Name : " << name << "\n" <<"Phone Number : "<< PhnNo << "\n" <<"Account Number : " << AccNumber << "\n" <<"Salary SLip No : " <<  SalarySlipNo << "\n" <<"AaDhar Number : "<< aadharNumber << "\n" <<"Pan Card Number : "<< PanCardNO << endl;

}
void Form_Applications:: CreditCard () 
{
	PersonalInformation();
}
void Form_Applications :: DebitCard()
{
	PersonalInformation();
}
void Form_Applications::ChequeBook()
{
	PersonalInformation();
}
void Form_Applications ::Loan(unsigned short TotalTime)
{
	if (Salary == 0 || Salary <= 10000)
	{
		if (LoanAmount == 8000 || LoanAmount <= 8000) 
		{
			//..To Find Total Amount After Adding Interest Amount
			Loan_Principle_Amount = LoanAmount;
			Loan_Interest_Amount = Loan_Interest_Rate * Loan_Principle_Amount / 100;
			Total_Amount = Loan_Principle_Amount + Loan_Interest_Amount;
			
			TotalMoneyToBePaidPerMonth = Total_Amount / TotalTime;

		}
		else 
		{
			cout << "No Eligibility Found" << endl;
		}
	}
	else if (Salary == 10000 || Salary <= 50000) 
	{
		if (LoanAmount == 50000 || LoanAmount <= 50000)
		{
			//..To Find Total Amount After Adding Interest Amount
			Loan_Principle_Amount = LoanAmount;
			Loan_Interest_Amount = Loan_Interest_Rate * Loan_Principle_Amount / 100;
			Total_Amount = Loan_Principle_Amount + Loan_Interest_Amount;

			TotalMoneyToBePaidPerMonth = Total_Amount / TotalTime;

		}
		else
		{
			cout << "No Eligibility Found" << endl;
		}
	}
	else if (Salary == 50000 || Salary <= 100000)
	{
		if (LoanAmount == 100000 || LoanAmount <= 100000)
		{
			//..To Find Total Amount After Adding Interest Amount
			Loan_Principle_Amount = LoanAmount;
			Loan_Interest_Amount = Loan_Interest_Rate * Loan_Principle_Amount / 100;
			Total_Amount = Loan_Principle_Amount + Loan_Interest_Amount;
	
			TotalMoneyToBePaidPerMonth = Total_Amount / TotalTime;

		}
		else {
			cout << "No Eligibility Found" << endl;
		}
	}
	else if (Salary == 100000 || Salary <= 1000000)
	{
		if (LoanAmount == 1000000 || LoanAmount <= 1000000)
		{
			//..To Find Total Amount After Adding Interest Amount
			Loan_Principle_Amount = LoanAmount;
			Loan_Interest_Amount = Loan_Interest_Rate * Loan_Principle_Amount / 100;
			Total_Amount = Loan_Principle_Amount + Loan_Interest_Amount;
			
			TotalMoneyToBePaidPerMonth = Total_Amount / TotalTime;

		}
		else
		{
			cout << "No Eligibility Found" << endl;
		}
	}//..Bug
	else
	{
		cout << "No Eligibility Found" << endl;
	}
}
int Form_Applications::Conversions()
{
	//..This Logic is for Month Conversion 
	if (Months % 2 == 0)
	{ //..4
	//..Month Conversion into Days if User Enter a Odd Number 
		num = Months / 2;
		even = num * 30;
		odd = num * 31;
		MonthConversion = even + odd;

	}
	else if (Months % 2 != 0) 
	{
		//..Month Conversion into Days if User Enter a Even Number 
		Months = Months - 1;
		num = Months / 2;
		even = num * 30;
		odd = num * 31;
		MonthConversion = even + odd + 31;

	}
	//..This Logic is for Year Conversion 
	if (Years < 4)
	{
		//..Normal Year Conversion into days
		YearConversion = OneYear * Years;

	}
	else if (Years % 4 == 0)
	{//..Changes to be Checked  7
		//..Conversion for Leap Year into days
		TotalLeapYear = Years / 4;
		NonLeapYear = Years - TotalLeapYear;
		YearConversion = (NonLeapYear * 365) + (TotalLeapYear * 366);
		//..2556
	}
	//..Adding Total Number Of days
	TotalNumberOfDays = MonthConversion + YearConversion + Days;
	TotalTime = TotalNumberOfDays / 30;

	return TotalTime;
}
int Form_Applications::ReasonForTakingLoan() {
	return 0;
}