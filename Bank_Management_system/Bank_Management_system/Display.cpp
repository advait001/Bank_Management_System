#include "Display.h"
#include <iostream>
#include <fstream>

using namespace std;

void User_Display::User_Detail_display()
{
	ifstream in("Personal_Details.txt");
	in >> name;
	in >> Phone_Number;
	in >> Email;

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