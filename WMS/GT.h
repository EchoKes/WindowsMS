/*
Team Members: Gabriel Goh, Kester Yeo
Student ID: S10198258E, S10185261A
Group: 11

take note of updateRecursive() function as it updates the path of
the child nodes if the parent node's path is changed. 

Take note of the traverse backwards function as it does not need to go through O(n) to traverse accurately 

Take note of showChildrenInCurrentNode as it uses a recursion function
*/

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
	//Constructor 
	GT();
	//initialise variable size 
	int size;
	//initialise variable UsedMemory
	int usedMemory;
	//insert Children:Gabriel
	//Pre:none if root don't exist|root is called
	//Post:Root is instantiated, stack adds root|root->TParent adds a child and size increased by 1, ... 
	//root->UsedMemory Increase size by 1.
	//Return:none since void
	void insertChildren(Itemtype folder);
	void insertChildren(GeneralNode*& root, Itemtype folder,int n);
	//check if the trees is empty:Gabriel
	//Pre:Root is called.
	//Post:none
	//Return:Returns bool
	bool isEmpty();
	//Display Childen of node:Gabriel
	//Pre:Get the node of currentNode and the usedMemory of the currentNode as int.
	//Post:Displays children in currentNode->TParent[n] using recursion.
	//Return:none since void
	void showChildrenOfCurrentNode();
	void showChildrenOfCurrentNode(GeneralNode* t,int n);
	//Traverse to selected node:Gabriel
	//Pre:CurrentNode ->TParent.size() have to be more than 0.
	//Post:CurrentNode traverse to choosen child, display a message to notify the traversal to user.
	//Return:none since void
	void traverseToChild(Itemtype fileName);
	void traverseToChild(GeneralNode* t,Itemtype fileName);
	//Traverse backwards to previous file or folder:Gabriel
	//Pre:Get node-> item from stack that ref to parent node of currentNode.
	//Post:CurrentNode traverse backwards to parentNode, display a message to notify the traversal to user.
	//Return:none since void
	void traverseBackwards();
	void traverseBackwards(GeneralNode* t);
	//Deleting children:Gabriel
	//Pre:CurrentNode->TParent have to contain the file.
	//Post:CurrentNode->TParent position is erased, currentNode-> used memory decreased,Stack is updated, ....
	//Display message to notify user.
	//Return:none since void
	void deleteChildren(ItemType childrenName);
	void deleteChildren(GeneralNode* t, ItemType childrenName);
	//updating current item:Gabriel
	//Pre:CurrentNode is not null
	//Post:curretNode-> item is updated to new item, stack is updated, display message to notify user.
	//Return:none since void
	void updateCurrent(ItemType item);
	void updateCurrent(GeneralNode* t,ItemType item);
	//search for file:Kester
	void searchFile(KeyType item);
	//helper function to update recursively:Kester&Gabriel
	bool updateRecursive(GeneralNode* n);
};
