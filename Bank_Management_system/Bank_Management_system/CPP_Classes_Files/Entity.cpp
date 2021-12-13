#include "../Header_Files/Entity.h"
#include <iostream>

using namespace std;

void Entity::Tabs(unsigned short num)
{
	if (num == 1)
	{
		cout << "\t|" << endl;
	}
	else if (num == 2)
	{
		cout << "\t\t|" << endl;
	}
	else if (num == 3)
	{
		cout << "\t\t\t|" << endl;
	}
	else if (num == 4)
	{
		cout << "\t\t\t\t|" << endl;
	}
}

void Entity::Lines(unsigned short parameter)
{
	if (parameter == 1)
	{
		cout << "_______________________________________________________" << endl;
	}
	else if (parameter == 2)
	{
		cout << "______________________________________________________________________________________________________________" << endl;
	}
}