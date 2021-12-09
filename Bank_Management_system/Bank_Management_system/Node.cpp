#include "Node.h"
#include <iostream>
#include <fstream>

using namespace std;


//..Singly Linked lists used 
//..Head Assigned
Node* Head;

//traverse to last node and return it
Node* FindLastNode()
{
	if (Head == NULL)
		return NULL;

	Node* tempNode = Head;

	while (tempNode->Next != NULL)
		tempNode = tempNode->Next;

	return tempNode;
}

//Add new node to last in the linklist
void Node:: AddNode(Node* newNode)
{
	Node* LastNode = FindLastNode();

	if (LastNode == NULL)
		Head = newNode;
	else
		LastNode->Next = newNode;
	ofstream write("Create_Account_Information.txt");
	write << newNode;
}
void Node :: FindNode(char num[15])
{
	Node* tempNode = Head;

	while (tempNode != NULL)
	{
		if (strcmp(tempNode->Num, num) == 0)
		{
			cout << "Name " << tempNode->Name << " Num: " << tempNode->Num << " Balance: " << tempNode->balance << endl;
			break;
		}
		tempNode = tempNode->Next;
	}
	//if we reach till end
	if (tempNode == NULL)
		cout << "No account found";
}
//print all values
void Node :: PrintNodes()
{
	if (Head == NULL)
	{
		cout << "List is empty";
		return;
	}

	Node* tempNode = Head;

	while (tempNode != NULL)
	{
		cout << "Name " << tempNode->Name << " Num: " << tempNode->Num << " Balance: " << tempNode->balance << endl;
		tempNode = tempNode->Next;
	}
}
void Node :: AskDetailsAndAdd()
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	//ask details to user
	cout << "\n\tEnter Name: ";
	cin >> newNode->Name;
	cout << "\tEnter Account Number: ";
	cin >> newNode->Num;
	cout << "\tEnter Balance: ";
	cin >> newNode->balance;
	cout << "\n";
	newNode->Next = NULL;
	//add node in the linklist
	AddNode(newNode);
}
