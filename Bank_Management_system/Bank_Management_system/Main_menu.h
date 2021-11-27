#pragma once
class Main_menu
{
public: 
	unsigned short _Call;
	unsigned short Input;
	unsigned short Main_menu_select;
public:
	int Menu();
	int Call_Function();

private:
	int Withdraw_money();
	int Account_Modification_menu();
	int Form_Application_menu();
};

