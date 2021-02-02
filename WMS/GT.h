#pragma once
using namespace std;
#include "General_Tree.h"
#include "stackDirectory.h"

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
	//Traverse the tree inorder
	void inorder();
	void inorder(GeneralNode* t);
	//Traverse the tree inorder
	void preorder();
	void preorder(GeneralNode* t);
	//Traverse the tree inorder
	void postorder();
	void postorder(GeneralNode* t);
	//check if the trees is empty
	bool isEmpty();
	//Using recursion to get the parent node of the current node
	GeneralNode getParentNode(Itemtype item);
	GeneralNode getParentNode(GeneralNode* t, Itemtype item);
	//Display Childen of node
	void showChildrenOfCurrentNode();
	void showChildrenOfCurrentNode(GeneralNode* t,int n);
	//Traverse to selected node
	void traverseToChild(Itemtype fileName);
	void traverseToChild(GeneralNode* t,Itemtype fileName);
	//Traverse backwards to previous file or folder
	void traverseBackwards();
	void traverseBackwards(GeneralNode* t);
};
