#pragma once
class Main_menu
{
public: 
	unsigned short _Call;
	unsigned short Input;
	unsigned short Main_menu_select;
	unsigned short Value;
	unsigned short Main_return_value;
	unsigned short Upper_or_Lower;
public:
	int Menu();
	int Call_Function();

private:
	int Withdraw_money();
	int Account_Modification_menu();
	int Form_Application_menu();
	void Line_func(unsigned short Upper_or_Lower);
};

