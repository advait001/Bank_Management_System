#pragma once
class Account_Handling 
{
	void display(struct Node* head);
	void insertFront(struct Node** head, char _name[30], char num[15], int _balance);
	void addNode(struct Node* head, char _name[30], char num[15], int _balance);
	void initNode(struct Node* head, int n);
	void In_System_Accounts();
};

