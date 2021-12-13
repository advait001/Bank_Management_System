#pragma once
class Node
{
public:
	//data part
	char Name[30];
	char Num[15];
	int balance;
	unsigned long DEL_ACC_NUM;
	//pointer to next
	Node* Next;

public:
	//..Memeber function Defined 

	void WriteAccountsToFile();
	void AddNode(Node* newNode); //..Add nodes to the end
	void PrintNodes(); //..Prints the list of Accounts Added 
	void ReadFromFile(); //This will read file and append nodes
	bool DeleteNode(char num[15]); //..Searches According to the given Input
	Node* FindNode(char num[15]); //..Searches According to the given Input
	Node* AskDetailsAndAdd(); //..Take the user details input 
};

