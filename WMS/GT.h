#pragma once
using namespace std;
#include "General_Tree.h"
#include "stackDirectory.h"
#include "Dictionary.h"

class GT {
private:
	GeneralNode* root;
	GeneralNode* CurrentNode;
	Stack CurrentDirectory; 
	
public:
	GT();
	int size;
	int usedMemory;
	//insert folder
	void insertFolder(Itemtype folder);
	void insertFolder(GeneralNode*& root, Itemtype folder,int n);
	//check if the trees is empty
	bool isEmpty();
	//Display Childen of node
	void showChildrenOfCurrentNode();
	void showChildrenOfCurrentNode(GeneralNode* t,int n);
	//Traverse to selected node
	void traverseToChild(Itemtype fileName);
	void traverseToChild(GeneralNode* t,Itemtype fileName);
	//Traverse backwards to previous file or folder
	void traverseBackwards();
	void traverseBackwards(GeneralNode* t);
	//Deleting folder 
	void deleteCurrent();
	void deleteCurrent(GeneralNode* t);
	//updating current item 
	void updateCurrent(ItemType item);
	void updateCurrent(GeneralNode* t,ItemType item);
};
