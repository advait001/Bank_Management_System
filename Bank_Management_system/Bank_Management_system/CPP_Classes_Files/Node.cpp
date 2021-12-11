#include "../Header_Files/Node.h"
#include <iostream>
#include <fstream>

using namespace std;


//..Singly Linked lists used 
//..Head Assigned

Node* Head = NULL;

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
}

Node* Node :: FindNode(char num[15])
{
	Node* tempNode = Head;

	while (tempNode != NULL)
	{
		if (strcmp(tempNode->Num, num) == 0)
			return tempNode;
		//take next node
		tempNode = tempNode->Next;
	}
	//if we reach till end
	return NULL;
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
Node* Node :: AskDetailsAndAdd()
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

	return newNode;
}
void Node::ReadFromFile()
{
	fstream _read;
	_read.open("Test_Files//Create_New_Acc_Info.txt", ios::in);
	if (!_read)
	{
		cout << "No such existing records found" << endl;
	}
	else
	{
		char name[30];
		char num[15];
		char bal[10];

		while (!_read.eof())
		{
			//read one record (3 lines each)
			_read.getline(name, 30);
			_read.getline(num, 15);
			_read.getline(bal, 10);

			//if no name means file reading over
			if (strcmp(name, "") == 0)
				break;
			//copy(6, 100 - 6, name);

			//create note and append it
			Node* newNode = (Node*)malloc(sizeof(Node));
			strcpy_s(newNode->Name, name);
			strcpy_s(newNode->Num, num);
			newNode->balance = atoi( bal);
			newNode->Next = NULL;
			//add node in the linklist
			AddNode(newNode);

		}
		_read.close();
	}

}