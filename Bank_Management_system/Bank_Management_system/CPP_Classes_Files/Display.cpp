#include "../Header_Files/Display.h"
#include <iostream>
#include <fstream>

using namespace std;

//..Simple display function created to show the Account Balance of the user 

void User_Display::User_Detail_display()
{
	//..Read the Details in the Personal_Details.txt text file 
	ifstream in("Personal_Details.txt");
	in >> name;
	in >> Phone_Number;
	in >> Email;

	//..Print the details of the text file in an ordered manner z
	cout << "._______________________________________________________________________." << endl;
	cout << "|																		" << endl;
	cout << "|																		" << endl;
	cout << "|	Name: " << name << endl;
	cout << "|	Phone Number: " << Phone_Number<< endl;
	cout << "|  \tEmail ID: " << Email << "\tBank Balance: " << endl; // bank balance to be added over here once the code merges
	cout << "|	Bank Balance: "<< endl;
	cout << "|																		" << endl;
	cout << "|																		" << endl;
	cout << "._______________________________________________________________________." << endl;
}

void User_Display::Project_Details()
{
	cout << "\t\tProject Detials\n" << endl;
	cout << "\tThis project is made by SHANTANU DOIFODE , ADVAIT KHAIRNAR , NINAD KARDE AND GAURAV KUCHEKAR.\n" << endl;
	cout << "\tThis is a Bank Management System project" << endl;
	cout << "\tIt is used to Keep the records of clients, employee etc in Bank...." << endl;
	cout << "\tThe system provides the access to the customer to" << endl;
	cout << "\t\t1) Create an account," << endl;
	cout << "\t\t2) Deposit cash" << endl;
	cout << "\t\t3) Withdraw the cash from their account, also to view reports of all accounts present." << endl;
	cout << "\tThe system is developed with the following functions added in it" << endl;
	cout << "\t\t1) Modify any account.Income account to savings account / De - materialized Account" << endl;
	cout << "\t\t2) Application forms." << endl;
	cout << "\t\t\t1. Apply for different services like :" << endl;
	cout << "\t\t\t\t2. Credit card" << endl;
	cout << "\t\t\t3. Debit Card" << endl;
	cout << "\t\t\t4. Cheque" << endl;
	cout << "\t\t\t5. Loan Application" << endl;
	cout << "\t\t\t6. Tax Invoice receipt etc." << endl;
	cout << "\tIt also supports generating new and discarding old accounts." << endl;
	cout << "\tBank Balance Inquiry is also supported." << endl;
	cout << "\tSkill sets, logicsand algorithms used in the system are :" << endl;
	cout << "\t\t1) Classesand Objects" << endl;
	cout << "\t\t2) Inheritance of classesand member functions" << endl;
	cout << "\t\t3) Pointersand Arrays" << endl;
	cout << "\t\t4) File Operationsand Data Handling" << endl;
	cout << "\t\t5) Searchingand Sorting" << endl;
	cout << "\t\t6) Database(SQLite)" << endl;
	cout << "\t\t7) Linked Lists Single" << endl;
	cout << "\t\t8) Comments" << endl;
	cout << "\t\t11) Dynamic Memory Allocation[malloc function]" << endl;
	cout << "\t\tAdditional use Git - hub is done to professionalize the work and make is easily accessible to all and also helps the entire team to work on it simultaneously.\n\n" << endl;
}