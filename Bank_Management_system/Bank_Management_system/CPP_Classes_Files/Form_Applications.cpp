#include "../Header_Files/Form_Applications.h"
#include<iostream>
#include<fstream>

using namespace std;

 void Form_Applications::PersonalInformation()
 {

	 //..Same Function used for credit, debit, cheque book, and loan application
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

	//..File Operations for noting down details

	fstream new_file;
	new_file.open("C:\\Users\\advai\\OneDrive\\Documents\\GitHub\\Bank_Management_System\\Bank_Management_system\\Bank_Management_system\\Test_Files\\User_Account_Info.txt", ios::out | ios::app);
	if (!new_file)
	{
		cout << "New file creation failed";
	}
	else
	{
		new_file << "Name: " << name << "\n" << "Phone number : " << PhnNo << "\n" << "Account Number : " << AccNumber << "\n" << "Salary Slip number : " << SalarySlipNo<< "\n" << "AaDhar Number : " << aadharNumber << "\n" << "Pan Card Number : " << PanCardNO << endl;
		new_file.close();
	}
}
void Form_Applications:: CreditCard () 
{
	//..Calling same function as above
	PersonalInformation();
}
void Form_Applications :: DebitCard()
{
	//..Calling same function as above
	PersonalInformation();
}
void Form_Applications::ChequeBook()
{
	//..Calling same function as above
	PersonalInformation();
}
void Form_Applications ::Loan(unsigned short TotalTime)
{
	if (Loan_Amount > MIN_Amount && Loan_Amount < MAX_Amount)//..Comparing Loan Amount 
	{
		//..Compound Interest
		Interest_Amount = (Interest_Rate * Loan_Amount) / 100;//..For Knowing the interest amount 
		Total_Amount = Interest_Amount + Loan_Amount;//..Total Amount That we have to pay adding interest amount and loan amount 
		EMI_Amount = Total_Amount / TotalTime;//..Calculations for money to be paid per month 
		if (Salary > EMI_Amount)//..comparing salary with EMI amount 
		{//..Printing Details 
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
			//..If the if condition is not satisfied
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
	//..Using File Operation for writing down the details related to loan

	fstream new_file;
	new_file.open("Test_Files//Loan_Details.txt", ios::out | ios::app);
	if (!new_file)
	{
		cout << "New file creation failed";
	}
	else
	{
		new_file << "Salary : " << Salary << "\n" << "Total Loan Amount : " << Total_Amount << "\n" << "Loan Principle Amount : " << Loan_Amount << "\n" << "Loan Interest Amount : " << Interest_Amount << "\n" << "Total Money to be paid per month : " << EMI_Amount << endl;
		new_file.close();
	}
	for (int i = 0; i < 1; i++) {
		if (N == 1) {
			new_file << "Reason : " << Reason2[i];
		}
		else if (N == 2) {
			new_file << "Reason : " << Reason2[i + 1];
		}
		else if (N == 3) {
			new_file << "Reason : " << Reason2[i + 2];
		}
		else if (N == 4) {
			new_file << "Reason : " << Reason2[i + 3];
		}
		else if (N == 5) {
			new_file << "Reason : " << Reason2[i + 4];
		}
		else if (N == 6) {
			cout << "Mention your reason : ";
			cin >> others;
			new_file << "Reason : " << others;
		}
	}
}
void Form_Applications::LoanAgainstWhat() {
	//..File Operation for writing down the details of Loan Against Part
	fstream new_file;
	new_file.open("C:\\Users\\advai\\OneDrive\\Documents\\GitHub\\Bank_Management_System\\Bank_Management_system\\Bank_Management_system\\Test_Files\\Loan_Related_Details.txt", ios::out | ios::app);
	if (!new_file)
	{
		cout << "New file creation failed";
	}
	else
	{
		for (int i = 0; i < 1; i++)
		{
			if (N1 == 1) {
				new_file << "Loan Against : " << LoanAgainst[i] << endl;
				cout << "Home Registration Number : ";
				cin >> RegistrationNo;
				new_file << "Registration Number : " << RegistrationNo;
			}
			else if (N1 == 2) {
				new_file << "Loan Against : " << LoanAgainst[i + 1] << endl;
				cout << "Car Registration Number : ";
				cin >> RegistrationNo;
				new_file << "Registration Number : " << RegistrationNo;
			}
			else if (N1 == 3) {
				new_file << "Loan Against : " << LoanAgainst[i + 2] << endl;
				cout << "Property Registration Number : ";
				cin >> RegistrationNo;
				new_file << "Registration Number : " << RegistrationNo;
			}
			else if (N1 == 4) {
				new_file << "Loan Against : " << LoanAgainst[i + 3] << endl;
				cout << "Business Shares Serve Number : ";
				cin >> RegistrationNo;
				new_file << "Serve Number : " << RegistrationNo;
			}
			else if (N1 == 5) {
				cout << "Specify Loan Against What : ";
				cin >> Others1;
				new_file << "Loan Against : " << Others1 << endl;
				cout << "Serial Number Or Registration Number : ";
				cin >> RegistrationNo;
				new_file << "Serial Number / Registration Number : " << RegistrationNo;
			}
			new_file.close();
		}
	}
}