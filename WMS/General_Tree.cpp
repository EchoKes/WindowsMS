/*
Team Members: Gabriel Goh, Kester Yeo
Student ID: S10198258E, S10185261A
Group: 11

take note of updateRecursive() function as it updates the path of
the child nodes if the parent node's path is changed. 
*/


#include "GT.h"
#include <iostream>
using namespace std;

static Dictionary d;

GT::GT()
{
	root = NULL;
	CurrentNode = NULL;
	CurrentDirectory;
}
void GT::insertChildren(Itemtype item)
{
	if(root ==NULL)
	{
		insertChildren(root, item,1);
	}
	else{ insertChildren(CurrentNode, item,0); }
	
}
void GT::insertChildren(GeneralNode*& t, Itemtype item,int n)
{
	ItemType direc;
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
	ItemType direc;
	bool isExist = true;
	ItemType directoryPath;
	for (int i = 0;i < t->usedMemory;i++)
	{
		if (t->TParent[i]->item == fileName)
		{
			CurrentNode = t->TParent[i];
			CurrentDirectory.push(*CurrentNode);
			CurrentDirectory.displayInOrderOfInsertion(direc);
			cout << "You are currently in " + fileName<<endl;
			isExist = true;
			break;
			
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
bool GT::updateRecursive(GeneralNode* n)
{	
	cout << "General Node item: " << n->item << endl;
	cout << "TParent size: " << n->TParent.size() << endl;
	cout << "Used Memory: " << n->usedMemory << endl;
	// base case
	if (n->TParent.size() == 0)
	{
		return true;
	}
	//Recursion
	else 
	{
		KeyType item;
		ItemType path;
		ItemType ePath;
		int numOfChilds = n->TParent.size();
		for (int i = 0; i < numOfChilds; i++)
		{
			item = n->TParent[i]->item;
			traverseToChild(n->item);
			CurrentDirectory.displayInOrderOfInsertion(path);
			for (ItemType x : d.getList(item))
			{
				if (x.find(n->item)) {
					ePath = x;
					path += item;
					d.remove(item, ePath);
					d.add(item, path);
					break;
				}

			}
			updateRecursive(n->TParent[i]);
		}
	}
	
}
void GT::updateCurrent(ItemType item)
{
	updateCurrent(CurrentNode,item);
}
void GT::updateCurrent(GeneralNode* t,ItemType item)
{
	ItemType direc;
	ItemType eKey;
	ItemType ePath;
	eKey = t->item;
	t->item = item;
	CurrentDirectory.displayInOrderOfInsertion(ePath);
	CurrentDirectory.pop();
	CurrentDirectory.push(*t);
	CurrentNode = t;
	CurrentDirectory.displayInOrderOfInsertion(direc);
	//Kester update here the new key is item and the path is direc
	d.update(eKey, ePath, item, direc);
	updateRecursive(t);
}
void GT::deleteChildren(ItemType childrenName)
{
	deleteChildren(CurrentNode,childrenName);
}
void GT::deleteChildren(GeneralNode* t, ItemType childrenName)
{
	ItemType direc;
	for (int i = 0;i < t->usedMemory;i++)
	{
		if (t->TParent[i]->item == childrenName)
		{
			if (t->TParent[i]->TParent.size() != 0)
			{
				cout << "\nUnable to delete children as it contains " << t->TParent[i]->TParent.size() << " file(s)." << endl;
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
				direc += childrenName + "/";
				d.remove(childrenName, direc);
			}
		}
	}
}

void GT::searchFile(KeyType key) {
	for (auto x : d.getList(key))
	{
		cout << x << endl;
	}
	cout << endl;
}