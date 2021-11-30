#include "Display.h"
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

	//..Print the details of the text file in an ordered manner 
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