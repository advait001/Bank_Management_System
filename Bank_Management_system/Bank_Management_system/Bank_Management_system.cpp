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
	//..Declarations
	short returned_the_value = 0;
	unsigned short ch1;

	//..For Personal details in form application
	unsigned short ch2;
	unsigned int Return_Total_Time;


	//..Make Systems of the class
	Bank_System System;
	Bank_Staff Obj;
	User_Display screen;
	Money_Transaction Object;
	Account_Modifications Object1;
	Form_Applications Object2;
	Main_menu Object3;


	//..Greet function called 
	System.Greet();

	//________________________________________..Login and signup code..________________________________________
	//..Working for a single persons use currently..

	cout << "\n\t1) Login (existing user) \n\t2) Sign-up (new user)\n\t3) Bank Management Login\n" << endl;
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

	//..Login code..
	//..Take the username and password from the user and enter into the Login member function
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
		cout << "\n\t1) Login \n\t2) Signup\n";
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

			//..check whehter the password and the reconfirmed password match with each other 
			returned_the_value = Obj.Login(username, password);
			if (returned_the_value == 0)
			{
				//..username and password matched successfully
				cout << "\n\tuser loged in Successfully" << endl;
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
				//..user not found , wrong username 
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
			cin >> Obj.name;
			cout << "\tPhone number: ";
			cin >> Obj.Phone_Number;
			cout << "\tStaff-ID: ";
			cin >> Staff_ID;
			cout << "\tAge: ";
			cin >> Obj.age;

			ofstream write("Staff_Personal_Details.txt");
			write << Obj.name << "\n" << Obj.Phone_Number << "\n" << Staff_ID << "\n" << Obj.age << endl;

			cout << "\tUsername: ";
			cin >> Username_;
			cout << "\n\tPassword: ";
			cin >> Pass_word;
			cout << "\tReconfirm the Password: ";
			cin >> Re_Confirm;

				returned_the_value = Obj.Bank_Signup_ID(Username_,Pass_word,Re_Confirm);
				if (returned_the_value == 0)
				{
					cout << "\tSign up successfull , Welcome to the bank management system" << endl;
					screen.User_Detail_display();
				}
				else if (returned_the_value == -1)
				{
					cout << "\n\n\tThe password entered for re-confirmation does not match with the passord in the first coloumn !!!" << endl;
					exit(0);
				}
		}
	}
	//..________________________________________Login and Signup Code end..________________________________________

	
	continue_code = Object3.Call_Function();
	//_______________________________________________________..Money transaction code..___________________________________________________
	//..Money transaction menu
	if (continue_code == 1) {
		//..repairing
		if (continue_code == 1) {
			//..Deposit Amount
			cout << "--------------------------------------------------------------------------------------------------------------------------------\n";
			cout << "\tEnter Your Account Number : ";
			cin >> Object.AccountNo1;

			cout << "\tEnter Amount You Want To Deposit : ";
			cin >> Object.Amount;

			cout << "\tEnter Your PIN : ";
			cin >> Object.PIN;

			returned_value = Object.DepositAmount();
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
		if (continue_code == 2) {
			cout << "-----------------------------------------------------------------------------------------------------------------------------\n";
			cout << "\tAccount No From *: ";
			cin >> Object.AccountNo1;

			cout << "\tAccount No To *:";
			cin >> Object.AccountNo2;

			cout << "\tEnter Amount You want to Transfer : ";
			cin >> Object.Amount;

			cout << "\tEnter Your PIN : ";
			cin >> Object.PIN;

			returned_value = Object.TransferAmount();
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
		if (continue_code == 3) {
			cout << "----------------------------------------------------------------------------------------------------------------------------\n";
			cout << "\tEnter Your Account No : ";
			cin >> Object.AccountNo1;

			cout << "\tEnter Amount You Want to WithDraw :";
			cin >> Object.Amount;

			cout << "\tEnter Your PIN : ";
			cin >> Object.PIN;

			returned_value = Object.WithdrawAmount();
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

		continue_code = Object3.Call_Function();

		if (continue_code == 1) {
			//..Account Type
			cout << "\tChange From Current Account To Savings Account.." << endl;

			cout << "\tEnter The Amount Of Money You Want To Transfer From Current Account To Savings Account : ";
			cin >> Object1.TransferAmount;

			returned_value = Object1.AccountType();
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
				cin >> Object1.Days;

				cout << "\tmonths :";
				cin >> Object1.Months;

				cout << "\tyears : ";
				cin >> Object1.Years;

				Object1.ConversionAndFinalAmount(returned_value);

				cout << "----Calculating Total Number of Days the Account Holder is going to keep the Money Amount in the Savings Account----" << endl;
					
			}
			//..Account Type Ends
		}
		else if (continue_code == 2) {
			//..Account Details
			cout << "\tAccount Number :";
			cin >> Object1.AccountNo;

			cout << "\tAccount Holder Name : ";
			cin >> Object1.CustomerName;

			cout << "\tBranch Name : ";
			cin >> Object1.BranchName;

			Object1.AccountDetails();
				

			///..Account Details Ends
		}

		else if (continue_code == 3) {
			//..User Details

			cout << "\tName : ";
			cin >> Object1.Name;

			cout << "\tAddress : ";
			cin >> Object1.Address;

			cout << "\tPhone Number : ";
			cin >> Object1.PhoneNo;

			cout << "\tDate of Birth (DD/MM/YEAR): ";
			cin >> Object1.day >> Object1.month >> Object1.year;

			cout << "\tAaDhar Number : ";
			cin >> Object1.AadharNo;

			cout << "\tEmail Id : ";
			cin >> Object1.EmailId;

			Object1.UserDetails();
				
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

		continue_code = Object3.Call_Function();
		//..Credit Code
		if (continue_code == 1) {
			cout << "\tEnter the Following Details in Order to Apply for Credit Card \n\n" << endl;

			Object2.CreditCard();

			cout << "\tYou Will be Notified for Further Procedure or Application Approval" << endl;
				
		}
		else if (continue_code == 2) {
			cout << "\tEnter the Following Details in Order to Apply for Debit Card \n\n" << endl;

			Object2.DebitCard();

			cout << "\tYou Will be Notified for Further Procedure or Application Approval" << endl;
				
		}
		else if (continue_code == 3) {
			cout << "\tEnter the Following Details in Order to Apply for Cheque Book \n\n" << endl;

			Object2.ChequeBook();

			cout << "\tYou Will be Notified for Further Procedure or Application Approval" << endl;
				
		}
		else if (continue_code == 4) {
			cout << "\tEnter the Following Details in Order to Apply for Loan \n\n" << endl;

			Object2.PersonalInformation();

			cout << "\tEnter Your Salary : ";
			cin >> Object2.Salary;

			cout << "\tLoan Amount : ";
			cin >> Object2.Loan_Amount;

			cout << "\tDays : ";
			cin >> Object2.Days;

			cout << "\tMonths : ";
			cin >> Object2.Months;

			cout << "\tYears : ";
			cin >> Object2.Years;
			Return_Total_Time = Object2.Conversions();

			Object2.Loan(Return_Total_Time);

			cout << "\tYour Principal Amount : " << Object2.Loan_Amount << endl;
			cout << "\tYour Interest Amount : " << Object2.Interest_Amount << endl;
			cout << "\tTotal Amount You have Pay : " << Object2.Total_Amount << endl;

			cout << "\tMoney To Be Paid Per Month : " << Object2.EMI_Amount << endl;

			cout << "------Reason For Taking Loan------ " << endl;
			cout << "\t1.Educational Loan : " << endl;
			cout << "\t2.Personal Loan : " << endl;
			cout << "\t3.Car Loan : " << endl;
			cout << "\t4.Home Loan : " << endl;
			cout << "\t5.Business Loan : " << endl;
			cout << "\t6.Others" << endl;
			cin >> Object2.N;
				
		}
		else {
			cout << "\tInvalid Input";
				
		}
	}
}