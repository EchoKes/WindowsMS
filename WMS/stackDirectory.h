/*
Team Member: Gabriel Goh
Student ID: S10198258E
Group: 11
*/


// Stack.h � Specification of Stack (Pointer-based implementation)
#pragma once
#include <iostream>
#include "General_Tree.h"
using namespace std;
typedef GeneralNode stackItemType;

class Stack
{
private:
	struct Node
	{
		stackItemType ItemNode;   // to store data
		Node* next;  // to point to next node
	};
	Node* topNode;
	int top;

public:
	Stack();		// constructor
	~Stack();		// destructor
	//Pushing Item as struct to stack:Gabriel
	//Pre:none
	//Post:Stack adds item, top++.
	//Return:Returns true
	bool push(stackItemType& ItemNode);
	//Remove Item in stack:Gabriel
	//Pre:TopNode have to be pointed to a node.
	//Post:Stack removes item, top--.
	//Return:Returns true
	bool pop();
	//Remove specific Item in stack:Gabriel
	//Pre:Item exist in stack
	//Post:Stack removes item, top--.
	//Return:Returns true
	bool pop(stackItemType& ItemNode);
	//Get the item of Stack:Gabriel
	//Pre:TopNode have to be pointed to a node.
	//Post:none
	//Return:none since its void
	void getTop(GeneralNode& t);
	//Check if stack is empty:Gabriel
	//Pre:none
	//Post:none
	//Return:Returns true
	bool isEmpty();
	//Display stack:Gabriel
	//Pre:Stack is not empty
	//Post:display stack items
	//Return:none since its void
	void displayInOrder(string& direcPath);
	//Display stack in order of insertion:Gabriel
	//Pre:Stack is not empty, put stack into back stack
	//Post:display stack items
	//Return:none since its void
	void displayInOrderOfInsertion(string& direcPath);
};
