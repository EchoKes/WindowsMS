#include "stackDirectory.h"
using namespace std;
Stack::Stack() { GeneralNode* topNode = NULL; top = -1; }
Stack::~Stack() {}

bool Stack::push(stackItemType item)
{
	bool success = !isEmpty();
	if (!success)
	{
		GeneralNode* newNode = new GeneralNode;
		newNode->ItemNode = item;
		newNode->next = NULL;
		topNode = newNode;
	}
	else
	{
		GeneralNode* newNode = new GeneralNode;
		newNode->ItemNode = item;
		newNode->next = NULL;
		newNode->next = topNode;
		topNode = newNode;
	}
	top++;
	return true;

}
bool Stack::pop()
{
	bool success = !isEmpty();
	if (success)
	{
		GeneralNode* tempNode = new GeneralNode;
		tempNode = topNode;
		topNode = topNode->next;
		tempNode->next = NULL;
		delete tempNode;
		top--;
		return true;
	}
}
bool Stack::pop(stackItemType& ItemNode)
{
	bool success = !isEmpty();
	if (success)
	{
		GeneralNode* tempNode = new GeneralNode;
		tempNode = topNode;
		topNode = topNode->next;
		tempNode->next = NULL;
		delete tempNode;
		top--;
		return true;
	}
}
void Stack::getTop(stackItemType& ItemNode)
{
	bool success = !isEmpty();
	if (success)
	{
		ItemNode = topNode->ItemNode;
		cout << ItemNode.item;
	}
	cout << endl;
}
void Stack::displayInOrder()
{
	bool success = !isEmpty();
	GeneralNode* temp = new GeneralNode;
	temp = topNode;
	if (success)
	{
		for (int i = -1; i < top;i++)
		{
			cout << temp->ItemNode.item;
			temp = temp->next;
		}
		cout << endl;
	}

}
void Stack::displayInOrderOfInsertion()
{
	bool success = !isEmpty();
	Stack back_stack;
	stackItemType getType;
	GeneralNode* temp = new GeneralNode;
	temp = topNode;
	if (success)
	{
		for (int i = -1;i < top;i++)
		{
			back_stack.push(temp->ItemNode);
			temp = temp->next;
		}
		back_stack.displayInOrder();
		cout << endl;
	}
}
bool Stack::isEmpty()
{
	return (topNode == NULL);
}