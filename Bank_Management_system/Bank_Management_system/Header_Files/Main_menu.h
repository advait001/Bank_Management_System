#pragma once
#include "Entity.h"

class Main_menu : public Entity 
{
	//..Definitions called 
public: 
	unsigned short _Call;
	unsigned short Input;
	unsigned short Main_menu_select;
	unsigned short Value;
	unsigned short Main_return_value;
	unsigned short Upper_or_Lower;
	//..Member function called
public:
	int Menu();
	int Call_Function();
	int Withdraw_money();
	int Account_Modification_menu();
	int Form_Application_menu();
	static void Line_func(unsigned short Upper_or_Lower);
};

