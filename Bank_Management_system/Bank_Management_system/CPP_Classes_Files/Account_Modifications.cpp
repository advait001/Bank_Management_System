#include "../Header_Files/Account_Modificatons.h"
#include<iostream>
#include <fstream>

using namespace std;

int Account_Modifications::AccountType() {
	if (CurrentBalance > TransferAmount) {
		//..Updating your account balances
		CurrentBalance = CurrentBalance - TransferAmount;
		SavingsAccountBalance = SavingsAccountBalance + TransferAmount;
		return SavingsAccountBalance;
	}
	else {
		//..if There's not a sufficient amount of money in the Current Account
		return -1;
	}
}

int Account_Modifications::ConversionAndFinalAmount(unsigned int returned_value)
{
	//..calculate using simple interest 
	//..simple interest formula = principle amount * interest rate * time /100
	SavingsAccountBalance = returned_value;
	unsigned int Simple_interest;
	unsigned int Final_Amount_savings = 0;
		
			//..This Logic is for Month Conversion 
			if (Months % 2 == 0) { //..4
			//..Month Conversion into Days if User Enter a Odd Number 
				num = Months / 2;
				even = num * 30;
				odd = num * 31;
				MonthConversion = even + odd;

			}
			else if (Months % 2 != 0) {
				//..Month Conversion into Days if User Enter a Even Number 
				Months = Months - 1;
				num = Months / 2;
				even = num * 30;
				odd = num * 31;
				MonthConversion = even + odd + 31;

			}
			//..This Logic is for Year Conversion 
			if (Years < 4) {
				//..Normal Year Conversion into days
				YearConversion = OneYear * Years;

			}
			else if (Years % 4 == 0) {
				//..Conversion for Leap Year into days
				TotalLeapYear = Years / 4;
				NonLeapYear = Years - TotalLeapYear;
				YearConversion = (NonLeapYear * 365) + (TotalLeapYear * 366);
			
			}
			//..Adding Total Number Of days
			TotalNumberOfDays = MonthConversion + YearConversion + Days;
			unsigned int temp = SavingsAccountBalance;
			TotalTime = TotalNumberOfDays / 90;

			//..simple interest formula 
			Simple_interest = Simple_Interest(SavingsAccountBalance, InterestRate, Days, MonthConversion, YearConversion);
			Final_Amount_savings = Savings_Account_returns(Simple_interest, SavingsAccountBalance);
		
	SavingsAccountBalance = Final_Amount_savings;
	return 0;
}
void Account_Modifications::AccountDetails() {

	fstream new_file;
	new_file.open("Test_Files//Account_Details.txt", ios::out | ios::app);
	if (!new_file)
	{
		cout << "New file creation failed";
	}
	else
	{
		new_file << AccountNo << "\n" << CustomerName << "\n" << BranchName << endl;
		new_file.close();
	}
}
void Account_Modifications::UserDetails() {
//..For Noting Down the Details the User Enter
	fstream write("UserAccountDetails.txt");
	write << Name << "\n" << Address << "\n" << PhoneNo << "\n" << day << "\t" << month << "\t" << year << "\n" << AadharNo << "\n" << EmailId << endl;

	fstream new_file;
	new_file.open("Test_Files//User_Account_Details.txt", ios::out | ios::app);
	if (!new_file)
	{
		cout << "New file creation failed";
	}
	else
	{
		new_file << Name << "\n" << Address << "\n" << PhoneNo << "\n" << day << "\n" << month << "\n" << year << "\n" << AadharNo << "\n" << EmailId << endl;
		new_file.close();
	}
}

int Account_Modifications::Savings_Account_returns(unsigned int simple_interest, unsigned int SavingsAccountBalance)
{
	//..show total Savings Account balance after adding the interest amount 
	//.. show the total amount of interest gained on the saving account balance 
	//..calculate and show the principle amount on which the interest was gained 
	unsigned int total_amount = 0;
	total_amount = simple_interest + SavingsAccountBalance;

	cout << "Total amount of money you got as interest : " << simple_interest << endl;
	cout << "Your principle amount invested in the savings account was : " << SavingsAccountBalance << endl;
	cout << "Your total balance in the savings account is : " << total_amount << endl;
	return total_amount;
}

int Account_Modifications :: Simple_Interest(unsigned int Principle_amount, unsigned short Interest_rate, unsigned short Days, unsigned short MonthConversion, unsigned short YearConversion) 
{
	//..simple interest conversion 
	//..principle amount * interest rate * time /100
	unsigned int simple_interest = 0;
	unsigned int total_time = (Days + MonthConversion + YearConversion)/90;
	simple_interest = (Principle_amount * Interest_rate * total_time) / 100;
	return simple_interest;
}