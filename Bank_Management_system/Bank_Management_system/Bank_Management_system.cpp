#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
#include "Bank_System.h"
#include "Bank_Staff.h"
#include "Display.h"
#include "Account_Modificatons.h"
#include "Form_Applications.h"
#include "Money_Transaction.h"
#include "Main_menu.h"
#include "Balance_Inquiry.h"
#include "Tax_Invoice.h"
#include "bankdb.h"

using namespace std;

void main()
{
	//..Definitions 
	unsigned short number;
	char username[30];
	char password[30];
	char Re_Confirm[30];
	unsigned int Staff_ID;
	short returned_value;
	short continue_code;
	short Call_func_return;
	//..Declarations
	short returned_the_value = 0;

	//..For Personal details in form application
	unsigned int Return_Total_Time;


	//..Make Systems of the class
	Bank_System System;
	Bank_Staff Staff;
	User_Display screen;
	Money_Transaction Money_Trans;
	Account_Modifications Acc_Modification;
	Form_Applications Form;
	Main_menu Menu_;
	Balance_Inquiry Balance_;
	Tax_Invoice Tax;

	//intialize database
	InitDB();

	//..Greet function called 
	System.Greet();

	//________________________________________..Login and sign-up code..________________________________________
	//..Working for a single persons use currently..

	cout << "\n\t1) Login (existing user) \n\t2) Sign-up (new user)\n\t3) Bank Management Login (bank Staff)\n\t4) Enter 0 to Exit\n" << endl;
	cout << "\t"; cin >> number;

	//..Personal details of the user 
	if (number == 2){

		cout << "\n\tEnter the following details to sign-up as a new user in our bank." << endl;
		cout << "\n\tFirst Name: ";
		cin >> System.name;
		cout << "\tPhone number: ";
		cin >> System.Phone_Number;
		cout << "\tEmail-ID: ";
		cin >> System.Email;
		cout << "\tAge: ";
		cin >> System.age;

		//..write the personal details in the "Personal_Details.txt" file 
		ofstream write("Personal_Details.txt");
		write << System.name << "\n" << System.Phone_Number << "\n" << System.Email << "\n" << System.age << endl;

	System.Signup();
	}
	else if (number == 0)
	{
		exit(0);
	}
	//..Login code..
	//..Take the user-name and password from the user and enter into the Login member function
	else if (number == 1) {
		cout << "\n\tUser-name: ";
		cin >> username;
		cout << "\tPassword: ";
		cin >> password;
		System.Login(username,password);
	}
	else if (number == 3) 
	{
		//..sign up code 
		cout << "\n\t1) Login \n\t2) Sign-up\n";
		unsigned short num;
		cout << "\t";
		cin >> num;
		
		//..login or sign up 
		if (num == 1)
		{
			cout << "\n\tUser-name: ";
			cin >> username;
			cout << "\tPassword: ";
			cin >> password;

			//..check whether the password and the reconfirmed password match with each other 
			returned_the_value = Staff.Login(username, password);
			if (returned_the_value == 0)
			{
				//..username and password matched successfully
				cout << "\n\tuser log in Successful" << endl;
				screen.User_Detail_display();
			}
			else if (returned_the_value == -1)
			{
				//..username matched but password is wrong 
				cout << "\n\tWrong Password" << endl;
				exit(0);
			}
			else if (returned_the_value == -2)
			{
				//..user not found , wrong user-name 
				cout << "\n\tUser not found" << endl;
				exit(0);
			}
		}
		//..Signup code for staff member 
		else if (num == 2)
		{
			char Username_[30];
			char Pass_word[30];

			cout << "\n\tEnter the following details to sign-up as a new staff member in our bank." << endl;
			cout << "\n\tFirst Name: ";
			cin >> Staff.name;
			cout << "\tPhone number: ";
			cin >> Staff.Phone_Number;
			cout << "\tStaff-ID: ";
			cin >> Staff_ID;
			cout << "\tAge: ";
			cin >> Staff.age;

			ofstream write("Staff_Personal_Details.txt");
			write << Staff.name << "\n" << Staff.Phone_Number << "\n" << Staff_ID << "\n" << Staff.age << endl;

			cout << "\tUser-name: ";
			cin >> Username_;
			cout << "\n\tPassword: ";
			cin >> Pass_word;
			cout << "\tReconfirm the Password: ";
			cin >> Re_Confirm;

				returned_the_value = Staff.Bank_Signup_ID(Username_,Pass_word,Re_Confirm);
				if (returned_the_value == 0)
				{
					cout << "\tSign up successful , Welcome to the bank management system" << endl;
					screen.User_Detail_display();
				}
				else if (returned_the_value == -1)
				{
					cout << "\n\n\tThe password entered for re-confirmation does not match with the password in the first coloumn !!!" << endl;
					exit(0);
				}
		}
	}
	//..________________________________________Login and Signup Code end..________________________________________

	
	continue_code = Menu_.Call_Function();
	//_______________________________________________________..Money transaction code..___________________________________________________
	//..Money transaction menu
	if (continue_code == 1) {

		Call_func_return = Menu_.Withdraw_money();

		if (Call_func_return == 1) {
			//..Deposit Amount
			cout << "--------------------------------------------------------------------------------------------------------------------------------\n";
			cout << "\tEnter Your Account Number : ";
			cin >> Money_Trans.AccountNo1;

			cout << "\tEnter Amount You Want To Deposit : ";
			cin >> Money_Trans.Amount;

			cout << "\tEnter Your PIN : ";
			cin >> Money_Trans.PIN;

			returned_value = Money_Trans.DepositAmount();
			if (returned_value == 0)
			{
				cout << "\tTransaction successful" << endl;
				screen.User_Detail_display();
					
			}
			else if (returned_value == -1)
			{
				cout << "\tTransaction failed due to wrong pin entered" << endl;
					
			}
		}
		//..Transfer Amount 
		if (Call_func_return == 2) {
			cout << "-----------------------------------------------------------------------------------------------------------------------------\n";
			cout << "\tAccount No From *: ";
			cin >> Money_Trans.AccountNo1;

			cout << "\tAccount No To *:";
			cin >> Money_Trans.AccountNo2;

			cout << "\tEnter Amount You want to Transfer : ";
			cin >> Money_Trans.Amount;

			cout << "\tEnter Your PIN : ";
			cin >> Money_Trans.PIN;

			returned_value = Money_Trans.TransferAmount();
			if (returned_value == 0)
			{
				cout << "\tTransaction Successful" << endl;
				screen.User_Detail_display();
					
			}
			else if (returned_value == -1)
			{
				cout << "\tTransaction failed due to wrong pin entered" << endl;
					
			}
			else if (returned_value == -2) {
				cout << "\tDue To Insufficient Bank Balance Money Cannot Be Transferred";
					
			}
			//..Transfer Amount Case end
		}
		//..Withdraw Amount 
		if (Call_func_return == 3) {
			cout << "----------------------------------------------------------------------------------------------------------------------------\n";
			cout << "\tEnter Your Account No : ";
			cin >> Money_Trans.AccountNo1;

			cout << "\tEnter Amount You Want to WithDraw :";
			cin >> Money_Trans.Amount;

			cout << "\tEnter Your PIN : ";
			cin >> Money_Trans.PIN;

			returned_value = Money_Trans.WithdrawAmount();
			if (returned_value == 0) {
				cout << "\tCollect Your Cash" << endl;
					
			}
			else if (returned_value == -1) {
				cout << "\tDue To Insufficient Bank Balance Money Cannot Be Withdrawn";
					
			}
			else if (returned_value == -2) {
				cout << "\tWrong pin , Please try again." << endl;
					
			}
		}
		cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
		//..Withdraw Amount case end
		//_______________________________________________________..Money transaction code end..___________________________________________________
	}
	else if (continue_code == 2) {
		//..Account Modification Menu
		//________________________________________________________Account Modification code starts _________________________________

		Call_func_return = Menu_.Account_Modification_menu();

		if (Call_func_return == 1) {
			//..Account Type
			cout << "\tChange From Current Account To Savings Account.." << endl;

			cout << "\tEnter The Amount Of Money You Want To Transfer From Current Account To Savings Account : ";
			cin >> Acc_Modification.TransferAmount;

			returned_value = Acc_Modification.AccountType();
			if (returned_value == -2) {
				cout << "\tInvalid Input";
					
			}

			else if (returned_value == -1) {

				cout << "\tInsufficient Balance for Money Transfer";
					
			}
			else {
				cout << "\tyour money as been transfered \n\n" << endl;

				cout << "\t--enter the time period you are going to keep the money in the savings account--\n " << endl;

				cout << "\tdays : ";
				cin >> Acc_Modification.Days;

				cout << "\tmonths :";
				cin >> Acc_Modification.Months;

				cout << "\tyears : ";
				cin >> Acc_Modification.Years;

				Acc_Modification.ConversionAndFinalAmount(returned_value);

				cout << "----Calculating Total Number of Days the Account Holder is going to keep the Money Amount in the Savings Account----" << endl;
					
			}
			//..Account Type Ends
		}
		else if (Call_func_return == 2) {
			//..Account Details
			cout << "\tAccount Number :";
			cin >> Acc_Modification.AccountNo;

			cout << "\tAccount Holder Name : ";
			cin >> Acc_Modification.CustomerName;

			cout << "\tBranch Name : ";
			cin >> Acc_Modification.BranchName;

			Acc_Modification.AccountDetails();
				

			///..Account Details Ends
		}

		else if (Call_func_return == 3) {
			//..User Details

			cout << "\tName : ";
			cin >> Acc_Modification.Name;

			cout << "\tAddress : ";
			cin >> Acc_Modification.Address;

			cout << "\tPhone Number : ";
			cin >> Acc_Modification.PhoneNo;

			cout << "\tDate of Birth (DD/MM/YEAR): ";
			cin >> Acc_Modification.day >> Acc_Modification.month >> Acc_Modification.year;

			cout << "\tAaDhar Number : ";
			cin >> Acc_Modification.AadharNo;

			cout << "\tEmail Id : ";
			cin >> Acc_Modification.EmailId;

			Acc_Modification.UserDetails();
				
			//..User Details Ends
		}
		else
		{
			cout << "\tInvalid Input";
				
		}
		//________________________________________________________Account Modification code ends _________________________________
	}
	else if (continue_code == 3) {
		//________________________________________________________Form Application code starts____________________________________

		Call_func_return = Menu_.Form_Application_menu();

		//..Credit Code
		if (Call_func_return == 1) {
			cout << "\tEnter the Following Details in Order to Apply for Credit Card \n\n" << endl;

			Form.CreditCard();

			cout << "\tYou Will be Notified for Further Procedure or Application Approval" << endl;
				
		}
		else if (Call_func_return == 2) {
			cout << "\tEnter the Following Details in Order to Apply for Debit Card \n\n" << endl;

			Form.DebitCard();

			cout << "\tYou Will be Notified for Further Procedure or Application Approval" << endl;
				
		}
		else if (Call_func_return == 3) {
			cout << "\tEnter the Following Details in Order to Apply for Cheque Book \n\n" << endl;

			Form.ChequeBook();

			cout << "\tYou Will be Notified for Further Procedure or Application Approval" << endl;
				
		}
		else if (Call_func_return == 4) {
			cout << "\tEnter the Following Details in Order to Apply for Loan \n\n" << endl;

			Form.PersonalInformation();

			cout << "\tEnter Your Salary : ";
			cin >> Form.Salary;

			cout << "\tLoan Amount : ";
			cin >> Form.Loan_Amount;

			cout << "\tDays : ";
			cin >> Form.Days;

			cout << "\tMonths : ";
			cin >> Form.Months;

			cout << "\tYears : ";
			cin >> Form.Years;
			Return_Total_Time = Form.Conversions();

			Form.Loan(Return_Total_Time);

			cout << "\tYour Principal Amount : " << Form.Loan_Amount << endl;
			cout << "\tYour Interest Amount : " << Form.Interest_Amount << endl;
			cout << "\tTotal Amount You have Pay : " << Form.Total_Amount << endl;

			cout << "\tMoney To Be Paid Per Month : " << Form.EMI_Amount << endl;

			cout << "------Reason For Taking Loan------ " << endl;
			cout << "\t1.Educational Loan : " << endl;
			cout << "\t2.Personal Loan : " << endl;
			cout << "\t3.Car Loan : " << endl;
			cout << "\t4.Home Loan : " << endl;
			cout << "\t5.Business Loan : " << endl;
			cout << "\t6.Others" << endl;
			cin >> Form.N;

			Form.ReasonForTakingLoan();

			cout << "\t-----Loan Against What-----" << endl;
			cout << "\t1.Against Home" << endl;
			cout << "\t2.Against Car" << endl;
			cout << "\t3.Against Property" << endl;
			cout << "\t4.Against Business Shares" << endl;
			cout << "\t5.Others" << endl;
			cin >> Form.N1;

			Form.LoanAgainstWhat();
				
		}
		else {
			cout << "\tInvalid Input";
				
		}
	}
	//________________________________________________________Balance Inquiry code starts____________________________________
	else if (continue_code == 7)
		{
		cout << "Enter the Account number to see its Balance" << endl;
		Balance_.Account_List();
		cin >> Balance_.Account_number;
		Balance_.Show_Balance();
		}
	//________________________________________________________Balance Inquiry code ends____________________________________

	//________________________________________________________Tax Invoice code starts____________________________________
	else if (continue_code == 8)
	{
		cout << "\t----- Tax Invoice ----- " << endl;

		cout << "Name : ";
		cin >> Tax.Name1;

		cout << "Income : ";
		cin >> Tax.Income;

		cout << "Phone Number : ";
		cin >> Tax.PhnNo;

		cout << "Age : ";
		cin >> Tax.Age;

		cout << "AaDhar No : ";
		cin >> Tax.aadharNumber;

		cout << "Pan Card Number : ";
		cin >> Tax.PanCardNO;

		cout << "Gender M / F / T : ";
		cin >> Tax.Gender;
		Tax.Tax_Invoice_Slab();
	}
	//________________________________________________________Tax Invoice code ends____________________________________
	else
	{
	cout << "No function found on number : " << continue_code << endl;
	}
	
}