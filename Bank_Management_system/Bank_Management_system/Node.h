#pragma once
class Node
{
public:
	//data part
	char Name[30];
	char Num[15];
	int balance;

	//pointer to next
	Node* Next;

public:
	//..Memeber function Defined 

	void AddNode(Node* newNode); //..Add nodes to the end
	void FindNode(char num[15]); //..Searches According to the given Input
	void PrintNodes(); //..Prints the list of Accounts Added 
	void AskDetailsAndAdd(); //..Take the user details input 
};

