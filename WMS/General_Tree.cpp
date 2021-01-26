#include "GT.h"
#include <iostream>
using namespace std;

GT::GT()
{
	root = NULL;
	int size = 0;
}
void GT::insert(Itemtype item)
{
	insert(root, item);
}
void GT::insert(GeneralNode*& t, Itemtype item)
{
	
	if (t == NULL)
	{
		GeneralNode* newNode = new GeneralNode;
		newNode->item = item;
		newNode->TChild[0] = NULL;
		newNode->TChild[1] = NULL;
		newNode->TChild[2] = NULL;
		t = newNode;
		size++;
	}
	else {
		for (int i = 0; i < size;i++)
		{
			if (t->TChild[i] == NULL)
			{
				insert(t->TChild[i], item);
				break;
			}
		}
	}
}
bool GT::isEmpty() { return (root == NULL); }