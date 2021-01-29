#include "GT.h"
#include <iostream>
using namespace std;

GT::GT()
{
	root = NULL;
	CurrentNode = NULL;

}
void GT::insertFolder(Itemtype item)
{
	if(root ==NULL)
	{
		insertFolder(root, item,1);
	}
	else{ insertFolder(CurrentNode, item,0); }
	
}
void GT::insertFolder(GeneralNode*& t, Itemtype item,int n)
{	
	if (t == NULL)
	{
		GeneralNode* newNode = new GeneralNode;
		newNode->item = item;
		newNode->Tfolder[0] = NULL;
		newNode->Tfolder[1] = NULL;
		newNode->Tfolder[2] = NULL;
		t = newNode;
		if (n == 1)
		{
			CurrentNode = root;
		}
		
	}
	else {
		bool valid;
		bool full;
		if (t->item.length() > 5)
		{
			if (t->item.substr(t->item.length() - 4,t->item.length()) == ".txt")
			{
				cout << "Unable to create folder or file under file" << endl;
				valid = false;
			}
			else
			{
				valid = true;
			}
			
		}
		else { valid = true; }
		if (valid)
		{
			for (int i = 0; i < t->size;i++)
			{
				if (t->Tfolder[i] == NULL) // root{size = 3, item = "gabriel", Tfolder{size="", item = 0x00000;size="", item = 0x00000;size="", item = 0x00000},Tfile}
				{
					full = false;
					insertFolder(t->Tfolder[i], item,n);
					t->usedMemory++;
					break;
				}
				full = true;
			}
			cout << full<<endl;
		}
		
		
	}
}
bool GT::isEmpty() { return (root == NULL); }
void GT::showChildrenOfCurrentNode()
{
	int n = CurrentNode->usedMemory;
	showChildrenOfCurrentNode(CurrentNode, n-1);
}
void GT::showChildrenOfCurrentNode(GeneralNode* t,int n)
{
	//base case 
	if (n == -1)
	{
		cout << "";
	}
	//recursive
	else
	{
		cout << t->Tfolder[n]->item << endl;
		showChildrenOfCurrentNode(t, n - 1);
	}
}
void GT::traverseToChild(Itemtype fileName)
{
	traverseToChild(CurrentNode, fileName);
}
void GT::traverseToChild(GeneralNode* t,Itemtype fileName)
{
	bool isExist;
	for (int i = 0;i < t->usedMemory;i++)
	{
		if (t->Tfolder[i]->item == fileName)
		{
			CurrentNode = t->Tfolder[i];
			cout << "You are currently in " + fileName<<endl;
			isExist = true;
		}
		else
		{
			isExist = false;
		}
	}
	if (isExist == false)
	{
		cout << "There is no such folder/file";
	}
}
//GeneralNode GT::getParentNode(Itemtype target)
//{
//	return getParentNode(root, target);
//}
//GeneralNode GT::getParentNode(GeneralNode* t,Itemtype target)
//{
//	//base case
//	if (t->Tfile->item || t->Tfolder[0]->item == target)
//	{
//		return t;
//	}
//	//recursion
//	else
//	{
//
//	}
//}
//void GT::inorder() 
//{
//	if (isEmpty())
//		cout << "No item found" << endl;
//	else
//		inorder(root);
//}
//void GT::inorder(GeneralNode* t)
//{
//	if (t != NULL)
//	{
//		inorder(t->Tfolder[0]); //recursive to change previous node to this node
//		cout << t->item << endl;
//	}
//}