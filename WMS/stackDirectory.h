// Stack.h � Specification of Stack (Pointer-based implementation)
#pragma once
#include <iostream>
#include "General_Tree.h"
using namespace std;
typedef GeneralNode stackItemType;

class Stack
{
private:
	struct GeneralNode
	{
		stackItemType ItemNode;   // to store data
		GeneralNode* next;  // to point to next node
	};
	GeneralNode* topNode;
	int top;

public:
	Stack();		// constructor
	~Stack();		// destructor
	bool push(stackItemType ItemNode);
	bool pop();
	bool pop(stackItemType& ItemNode);
	void getTop(stackItemType& ItemNode);
	bool isEmpty();
	void displayInOrder();
	void displayInOrderOfInsertion();
};
