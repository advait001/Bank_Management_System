#include "Account_Handling.h"
#include "Form_Applications.h"
#include <iostream>
#include <fstream>

using namespace std;

struct Node {
	int balance;
	char *Name;
	char *AccNum;
	Node* next;
};

// only for the 1st Node
void Account_Handling :: initNode(struct Node* head, int n) {
	head->balance = n;
	head->next = NULL;
}

// apending
void Account_Handling::addNode(struct Node* head,char _name[30],char num[15], int _balance) {
	Node* newNode = new Node;
	newNode->balance = _balance;
	newNode->Name = _name;
	newNode->AccNum = num;
	newNode->next = NULL;

	Node* cur = head;
	while (cur) {
		if (cur->next == NULL) 
		{
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

void Account_Handling::insertFront(struct Node** head, char _name[30], char num[15], int _balance) {
	Node* newNode = new Node;
	newNode->balance = _balance;
	newNode->Name = _name;
	newNode->AccNum = num;
	newNode->next = *head;
	*head = newNode;
}

struct Node* searchNode(struct Node* head, char num[15]) {
	Node* cur = head;
	while (cur) {
		if (cur->AccNum == num) 
		{
			return cur;
			cur = cur->next;
		}
	}
	cout << "No Node with Account number: " << num << " in list.\n";
}

void Account_Handling::display(struct Node* head) {
	Node* list = head;
	while (list) {
		cout << list->balance << " ";
		list = list->next;
	}
	cout << endl;
	cout << endl;
}

void Account_Handling::In_System_Accounts()
{

}