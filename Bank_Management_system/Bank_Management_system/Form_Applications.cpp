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
	cout << "Enter the amount of loan you want: ";
	cin >> Loan_Amount;
	cout << "Enter the salary you earn every month: ";
	cin >> Salary;
	if (Loan_Amount > MIN_Amount && Loan_Amount < MAX_Amount)
	{
		//..Calculation part 
		Interest_Amount = (Interest_Rate * Loan_Amount) / 100;
		Total_Amount = Interest_Amount + Loan_Amount;
		EMI_Amount = Total_Amount / TotalTime;
		if (Salary > EMI_Amount)
		{
			cout << ".___________________________________________________________________________." << endl;
			cout << "|  Loan Granted..." << endl;
			cout << "|  Loan Amount Granted: " << Loan_Amount << endl;
			cout << "|  Interest Rate: " << Interest_Rate << endl;
			cout << "|  Total number of days: " << TotalTime << endl;
			cout << "|  EMI money to be given every month: " << EMI_Amount << endl;
			cout << "|  Total amount to be returned: " << Total_Amount << endl;
			cout << ".___________________________________________________________________________." << endl;
		}
		else
		{
			cout << "Loan cannot be granted as your salary amount is less than the amount to be paid every month." << endl;
		}
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
void Form_Applications::ReasonForTakingLoan() {
	ofstream write("Loan_Related_Details.txt");
	write << "Salary : " << Salary << "\n" << "Total Loan Amount : " << Total_Amount << "\n" << "Loan Principle Amount : " << Loan_Amount << "\n" << "Loan Interest Amount : " << Interest_Amount << "\n" << "Total Money to be paid per month : " << EMI_Amount << endl;
	for (int i = 0; i < 1; i++) {
		if (N == 1) {
			write << "Reason : " << Reason2[i];
		}
		else if (N == 2) {
			write << "Reason : " << Reason2[i + 1];
		}
		else if (N == 3) {
			write << "Reason : " << Reason2[i + 2];
		}
		else if (N == 4) {
			write << "Reason : " << Reason2[i + 3];
		}
		else if (N == 5) {
			write << "Reason : " << Reason2[i + 4];
		}
		else if (N == 6) {
			cout << "Mention your reason : ";
			cin >> others;
			write << "Reason : " << others;
		}
	}
}
void Form_Applications::LoanAgainstWhat() {
	ofstream write("Loan_Related_Details.txt", ios::app);
	for (int i = 0; i < 1; i++) {
		if (N1 == 1) {
			write << "Loan Against : " << LoanAgainst[i] << endl;
			cout << "Home Registration Number : ";
			cin >> RegistrationNo;
			write << "Registration Number : " << RegistrationNo;
		}
		else if (N1 == 2) {
			write << "Loan Against : " << LoanAgainst[i + 1] << endl;
			cout << "Car Registration Number : ";
			cin >> RegistrationNo;
			write << "Registration Number : " << RegistrationNo;
		}
		else if (N1 == 3) {
			write << "Loan Against : " << LoanAgainst[i + 2] << endl;
			cout << "Property Registration Number : ";
			cin >> RegistrationNo;
			write << "Registration Number : " << RegistrationNo;
		}
		else if (N1 == 4) {
			write << "Loan Against : " << LoanAgainst[i + 3] << endl;
			cout << "Business Shares Serve Number : ";
			cin >> RegistrationNo;
			write << "Serve Number : " << RegistrationNo;
		}
		else if (N1 == 5) {
			cout << "Specify Loan Against What : ";
			cin >> Others1;
			write << "Loan Against : " << Others1 << endl;
			cout << "Serial Number Or Registration Number : ";
			cin >> RegistrationNo;
			write << "Serial Number / Registration Number : " << RegistrationNo;
		}
	}
}