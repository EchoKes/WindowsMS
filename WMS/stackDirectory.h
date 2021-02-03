// Stack.h – Specification of Stack (Pointer-based implementation)
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
	bool push(stackItemType ItemNode);
	bool pop();
	bool pop(stackItemType& ItemNode);
	void getTop(GeneralNode& t);
	bool isEmpty();
	void displayInOrder(string& direcPath);
	void displayInOrderOfInsertion(string& direcPath);
};
