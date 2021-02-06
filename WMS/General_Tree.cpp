#include "GT.h"
#include "Dictionary.h"
#include <iostream>
using namespace std;
static Dictionary d;
GT::GT()
{
	root = NULL;
	CurrentNode = NULL;
	CurrentDirectory;
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
	string direc;
	if (t == NULL)
	{
		GeneralNode* newNode = new GeneralNode;
		newNode->item = item;
		t = newNode;
		if (n == 1)
		{
			CurrentNode = root;
		}
		CurrentDirectory.push(*CurrentNode); //root/
		CurrentDirectory.displayInOrderOfInsertion(direc);
		// Kester Add here item = nameoffile, direc = path
		//add here.
		d.add(item, direc);
		newNode=NULL;
		delete newNode;
	}
	else {
		bool valid;
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
			GeneralNode* AddNode = new GeneralNode;
			AddNode->item = item;
			t->TParent.push_back(AddNode);
			CurrentDirectory.displayInOrderOfInsertion(direc);
			direc +=item+"/";
			// Kester Add here item = nameoffile, direc = path
			//add here.
			d.add(item, direc);
			t->usedMemory++;
			CurrentNode = t;
			CurrentDirectory.pop();
			CurrentDirectory.push(*CurrentNode);
			AddNode = NULL;
			delete AddNode;
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
		cout << t->TParent[n]->item << endl;
		showChildrenOfCurrentNode(t, n - 1);
	}
}
void GT::traverseToChild(Itemtype fileName)
{
	traverseToChild(CurrentNode, fileName);
}
void GT::traverseToChild(GeneralNode* t,Itemtype fileName)
{
	string direc;
	bool isExist = true;
	string directoryPath;
	for (int i = 0;i < t->usedMemory;i++)
	{
		if (t->TParent[i]->item == fileName)
		{
			CurrentNode = t->TParent[i];
			CurrentDirectory.push(*CurrentNode);
			CurrentDirectory.displayInOrderOfInsertion(direc);
			cout << "You are currently in " + fileName<<endl;
			break;
			isExist = true;
		}
		else
		{
			isExist = false;
		}
	}
	if (isExist == false)
	{
		cout << "There is no such folder/file"<<endl;
	}
}
void GT::traverseBackwards()
{
	GeneralNode* newNode = new GeneralNode;
	CurrentDirectory.getTop(*newNode);
	if (newNode->item == root->item)
	{
		cout << "There is no files/folder to go back to!" << endl;
	}
	else
	{ 
		CurrentDirectory.pop();
		CurrentDirectory.getTop(*newNode);
		traverseBackwards(newNode);
	}
	
	
}
void GT::traverseBackwards(GeneralNode* t)
{
	CurrentNode = t;
	cout << "You are currently in " + t->item << endl;
}
void GT::updateCurrent(ItemType item)
{
	updateCurrent(CurrentNode,item);
}
void GT::updateCurrent(GeneralNode* t,ItemType item)
{
	string direc;
	t->item = item;
	CurrentDirectory.pop();
	CurrentDirectory.push(*t);
	CurrentNode = t;
	CurrentDirectory.displayInOrderOfInsertion(direc);
	//Kester add here the new key is item and the path is direc
}
void GT::deleteChildren(ItemType childrenName)
{
	deleteChildren(CurrentNode,childrenName);
}
void GT::deleteChildren(GeneralNode* t, ItemType childrenName)
{
	string direc;
	for (int i = 0;i < t->usedMemory;i++)
	{
		if (t->TParent[i]->item == childrenName)
		{
			if (t->TParent[i]->TParent.size() != 0)
			{
				cout << "Unable to delete children as it contains " << t->TParent[i]->TParent.size() << " file(s)." << endl;
			}
			else
			{
				t->TParent.erase(t->TParent.begin() + i);
				t->usedMemory--;
				cout << "1 item deleted."<<endl;
				CurrentNode = t;
				CurrentDirectory.pop();
				CurrentDirectory.push(*CurrentNode);
				CurrentDirectory.displayInOrderOfInsertion(direc);
				//Kester childrenName = ur hash, direc is path.
			}
		}
	}
}
