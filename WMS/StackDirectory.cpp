#include "stackDirectory.h"
using namespace std;
Stack::Stack() { Node* topNode = NULL; top = -1; }
Stack::~Stack() {}

bool Stack::push(stackItemType item)
{
	bool success = !isEmpty();
	if (!success)
	{
		Node* newNode = new Node;
		newNode->ItemNode = item;
		newNode->next = NULL;
		topNode = newNode;
	}
	else
	{
		Node* newNode = new Node;
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
		Node* tempNode = new Node;
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
		Node* tempNode = new Node;
		tempNode = topNode;
		topNode = topNode->next;
		tempNode->next = NULL;
		delete tempNode;
		top--;
		return true;
	}
}
void Stack::getTop(GeneralNode& t)
{
	bool success = !isEmpty();
	if (success)
	{
		GeneralNode* tempNode = new GeneralNode;
		tempNode->item = topNode->ItemNode.item;
		tempNode->Tfolder = topNode->ItemNode.Tfolder;
		tempNode->usedMemory = topNode->ItemNode.usedMemory;
		t = *tempNode;
	}
}
void Stack::displayInOrder()
{
	bool success = !isEmpty();
	Node* temp = new Node;
	temp = topNode;
	cout << "Current Directory:"<<endl;
	if (success)
	{
		for (int i = -1; i < top;i++)
		{
			cout << temp->ItemNode.item +"/";
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
	Node* temp = new Node;
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