#pragma once
#include "Main_menu.h"

class Balance_Inquiry : public Main_menu
{
public:
	unsigned int Account_number;
private :
	static const unsigned short Array_Size = 15; //..Array Size defined 
	//..These are the number details and the account balace details of the user and the account holders name 
	unsigned int Acc_num_Data[Array_Size] = {200148001,200148002,200148003,200148004,200148005,200148006,200148007,200148008,200148009,200148010,200148011,200148012,200148013,200148014,200148015};
	unsigned int Acc_Balance_Data[Array_Size] = { 89400,21634,100000,250000,245000,10200,8000,40500,23400,100920,16000,170020,34000,42000,120000 };
	const char* Acc_User_Name_Data[100] = { "Ramesh","Suresh","Paresh","Ajay","Sanjay","Akshay","Sameer","Vinit","Vinay","Suraj","Amit","Arnav","Alok","Daniel","Aman"};
public :
	void Show_Balance(); //..Calculation function
	void Account_List(); //..Account holders function
private:
	void Display_Output(unsigned short num); //..Display representation function
};

