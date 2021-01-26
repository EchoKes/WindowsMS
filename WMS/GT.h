#pragma once
using namespace std;
#include "General_Tree.h"

class GT {
private:
	GeneralNode* root;
public:
	GT() {}
	int size;
	//insert
	void insert(Itemtype item);
	void insert(GeneralNode*& root, Itemtype item);
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
};
