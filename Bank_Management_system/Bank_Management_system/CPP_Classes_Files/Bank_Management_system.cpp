/*This is a Bank Management System project
It is used to Keep the records of clients, employee etc in Bank....
The system provides the access to the customer to
	1) Create an account,
	2) Deposit cash
	3) Withdraw the cash from their account, also to view reports of all accounts present.
The system is developed with the following functions added in it
	1) Modify any account. Income account to savings account/De-materialized Account
	2) Application forms.
		1. Apply for different services like:
		2. Credit card
		3. Debit Card
		4. Cheque
		5. Loan Application
		6. Tax Invoice receipt etc.
It also supports generating new and discarding old accounts.
Bank Balance Inquiry is also supported.
Skill sets, logics and algorithms used in the system are:
	1) Classes and Objects
	2) Inheritance of classes and member functions
	3) Pointers and Arrays
	4) File Operations and Data Handling
	5) Searching and Sorting
	6) Database (SQLite)
	7) Linked Lists Single
	8) Comments
	11) Dynamic Memory Allocation [malloc function]
Additional use Git-hub is done to professionalize the work and make is easily accessible to all and also helps the entire team to work on it simultaneously.
*/
//..#defines and libraries that are used in this project


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
#include "../Header_Files/Bank_System.h"
#include "../Header_Files/Bank_Staff.h"
#include "../Header_Files/Display.h"
#include "../Header_Files/Account_Modificatons.h"
#include "../Header_Files/Form_Applications.h"
#include "../Header_Files/Money_Transaction.h"
#include "../Header_Files/Main_menu.h"
#include "../Header_Files/Balance_Inquiry.h"
#include "../Header_Files/Tax_Invoice.h"
#include "../Header_Files/bankdb.h"
#include "../Header_Files/Node.h"
#include "../Header_Files/Entity.h"
#include <direct.h>

using namespace std;


//..Main Function
void main()
{
	//..Definitions 
	unsigned short number;
	char username[30];
	char password[30];
	char Re_Confirm[30];
	unsigned int Staff_ID;
	short returned_value;
	short continue_code = 1;
	short Call_func_return;
	unsigned short input = 1;
	unsigned short ReDirect = 1;
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
	Node Create;
	Entity Present;
	//intialise database
	InitDB();
	//read existing records from file
	Create.ReadFromFile();
	//..Greet function called 
	System.Greet();

	//________________________________________..Login and sign-up code..________________________________________
	//..Working for a single persons use currently..
	while (ReDirect != 0) 
	{
		cout << "\n\t0) Enter 0 to Exit" << endl;
		cout << "\t1) Login(existing user)" << endl;
		cout << "\t2) Sign - up(new user)" << endl;
		cout << "\t3) Bank Management Login(bank Staff) " << endl;
		cout << "\t4) Project Details" << endl;
		cout << "\n\t"; cin >> number;

		//..Personal details of the user 
		if (number == 2) {

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
			fstream new_file;
			new_file.open(FILE_PERSONAL_DETAILS, ios::out | ios::app);
			if (!new_file)
			{
				cout << "New file creation failed";
			}
			else
			{
				new_file << System.name << "\n" << System.Phone_Number << "\n" << System.Email << "\n" << System.age << endl;
				new_file.close();
			}

			System.Signup();

			cout << "Login with the registered username and Password" << endl;
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
			System.Login(username, password);
			ReDirect = 0;
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
					cout << "\n\tstaff log in Successful" << endl;
					screen.User_Detail_display();
					ReDirect = 0;
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

				fstream new_file;
				new_file.open(FILE_PERSONAL_DETAILS, ios::out | ios::app);
				if (!new_file)
				{
					cout << "New file creation failed";
				}
				else
				{
					new_file << Staff.name << "\n" << Staff.Phone_Number << "\n" << Staff_ID << "\n" << Staff.age << endl;
					new_file.close();
				}

				cout << "\tUser-name: ";
				cin >> Username_;
				cout << "\n\tPassword: ";
				cin >> Pass_word;
				cout << "\tReconfirm the Password: ";
				cin >> Re_Confirm;

				returned_the_value = Staff.Bank_Signup_ID(Username_, Pass_word, Re_Confirm);
				if (returned_the_value == 0)
				{
					cout << "\tSign up successful , Welcome to the bank management system" << endl;
					screen.User_Detail_display();
					cout << "Login with the registered username and password" << endl;
				}
				else if (returned_the_value == -1)
				{
					cout << "\n\n\tThe password entered for re-confirmation does not match with the password in the first coloumn !!!" << endl;
					exit(0);
				}
			}
		}
		else if (number == 4)
		{
			screen.Project_Details();
		}
	}
	//..________________________________________Login and Signup Code end..________________________________________


	//continue_code = Menu_.Call_Function();

	while (continue_code != 0)
	{
		continue_code = Menu_.Call_Function();
		//_______________________________________________________..Money transaction code..___________________________________________________
		//..Money transaction menu
		if (continue_code == 1) {

			Call_func_return = Menu_.Withdraw_money();

			if (Call_func_return == 1) {
				//..Deposit Amount
				cout << "--------------------------------------------------------------------------------------------------------------------------------\n";
				Balance_.Ask_Account_List();
				cout << "\tEnter Your Account Number : ";
				cin >> Money_Trans.AccountNo1;

				cout << "\tEnter Amount You Want To Deposit : ";
				cin >> Money_Trans.Amount;

				cout << "\tEnter password : ";
				cin >> Money_Trans.pincode;

				returned_value = Money_Trans.DepositAmount();
				if (returned_value == 0)
				{
					cout << "\tTransaction successful" << endl;

				}
				else if (returned_value == -1)
				{
					cout << "\tTransaction failed due to wrong password entered" << endl;

				}
			}
			//..Transfer Amount 
			if (Call_func_return == 2) {
				cout << "\t-----------------------------------------------------------------------------------------------------------------------------\n";
				Balance_.Ask_Account_List();
				cout << "\tAccount No From *: ";
				cin >> Money_Trans.AccountNo1;

				cout << "\tAccount No To *: ";
				cin >> Money_Trans.AccountNo2;

				cout << "\tEnter Amount You want to Transfer : ";
				cin >> Money_Trans.Amount;

				cout << "\tEnter password : ";
				cin >> Money_Trans.pincode;

				returned_value = Money_Trans.TransferAmount();
				if (returned_value == 0)
				{
					cout << "\tTransaction Successful" << endl;
					screen.User_Detail_display();

				}
				else if (returned_value == -1)
				{
					cout << "\tTransaction failed due to wrong password entered" << endl;

				}
				else if (returned_value == -2) {
					cout << "\tDue To Insufficient Bank Balance Money Cannot Be Transferred";

				}
				//..Transfer Amount Case end
			}
			//..Withdraw Amount 
			if (Call_func_return == 3) {
				cout << "----------------------------------------------------------------------------------------------------------------------------\n";
				Balance_.Ask_Account_List();
				cout << "\tEnter Your Account No : ";
				cin >> Money_Trans.AccountNo1;

				cout << "\tEnter Amount You Want to WithDraw :";
				cin >> Money_Trans.Amount;

				cout << "\tEnter password : ";
				cin >> Money_Trans.pincode;

				returned_value = Money_Trans.WithdrawAmount();
				if (returned_value == 0) {
					cout << "\tCollect Your Cash" << endl;

				}
				else if (returned_value == -1) {
					cout << "\tDue To Insufficient Bank Balance Money Cannot Be Withdrawn\n";

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
		
		else if (continue_code == 4)
		{
			cout << "\tPrinting the list of all accounts: \n" << endl;
			Create.PrintNodes();
		}

		//________________________________________________________Open new Account code Starts____________________________________
		else if (continue_code == 5)
		{
				//..Menu Loop
			while (input != 0)
			{
				//..Menu
				//_________________________________________________
				cout << "\n\t1: Create Account" << endl;
				cout << "\t2: Print Latest Account Generated List" << endl;
				cout << "\t3: Search Account" << endl;
				cout << "\t0: Exit \n" << endl;;
				cin >> input;
				//_________________________________________________

				if (input == 1)
				{
					Node* tempNode = Create.AskDetailsAndAdd();
					fstream new_file;
					new_file.open(FILE_ACCOUNT_INFO, ios::out | ios::app);
					if (!new_file)
					{
						cout << "New file creation failed";
					}
					else
					{
						new_file << tempNode->Name << endl << tempNode->Num << endl << tempNode->balance << endl;
						new_file.close();
					}
				}
				else if (input == 2)
				{
					Create.PrintNodes();
				}
				else if (input == 3)
				{
					char num[15];
					cout << "Enter Account number: ";
					cin >> num;
					Node* tempNode = Create.FindNode(num);
					if (tempNode == NULL)
						cout << "No account found";
					else
						cout << "Name " << tempNode->Name << " Num: " << tempNode->Num << " Balance: " << tempNode->balance << endl;
				}
				else if (input == 0)
				{
					break;
				}
				else
					cout << "Invalid input" << endl;

			}
		}
		//________________________________________________________Open new Account code Ends____________________________________
		else if (continue_code == 6)
		{
			unsigned short confirm = 1;
			char DEL_ACC_NUM[30];
			cout << "Enter the account number you want to delete: ";
			cin >> DEL_ACC_NUM;
			while (confirm != 0)
			{
				cout << "\nDo you confirm to delete the account ? All the data from the account will be deleted" << endl;
				cout << "Enter 1 to confirm delete and enter 0 to exit without deleting: " << endl;
				cin >> confirm;
				if (confirm == 1)
				{
					if (Create.DeleteNode(DEL_ACC_NUM) == true)
					{
						cout << "\nAccount Deleted ";
						Create.WriteAccountsToFile();
						confirm = 0;
					}
					else
					{
						cout << "\nAccount not found";
						confirm = 0;
					}
				}
				else if (confirm == 0)
				{
					cout << "\nExited Without deleting the account" << endl;
					exit(0);
				}
				else
				{
					cout << "Wrong input !!!" << endl;
				}
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

		cout << "Account Number : ";
		cin >> Tax.AccountNumber;

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
}