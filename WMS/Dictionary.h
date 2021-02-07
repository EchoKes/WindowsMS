/*
Team Member: Kester Yeo
Student ID: S10185261A
Group: 11

Features to take note will be hash and rehashing function
as these 2 functions will determine if the searching's 
complexity will be better/worse.
*/

#pragma once
#include <string>
#include <vector>
using namespace std;

//const int MAX_SIZE = 17;
static int MAX_SIZE = 4;
static int CHAIN_SIZE = 3;
typedef string KeyType;
typedef string ItemType;

class Dictionary
{
private:
	struct Node
	{
		KeyType	 key;   // search key
		ItemType item;	// data item
		Node* next;		// pointer pointing to next item with same search key
	};

	vector<Node*>items;
	Node* topNode;
	int	size;			// number of items in the Dictionary

public:

	// constructor
	Dictionary();

	// destructor
	~Dictionary();

	// calculates new index of key:Kester
	// pre : none
	// post: none
	// return the index
	int hash(KeyType key);

	// add a new item with the specified key to the Dictionary:Kester
	// pre : none
	// post: new item is added to the Dictionary
	// size of Dictionary is increased by 1
	bool add(KeyType newKey, ItemType newItem);

	// remove an item with the specified key in the Dictionary:Kester
	// pre : key must exist in the Dictionary
	// post: item is removed from the Dictionary
	// size of Dictionary is decreased by 1
	void remove(KeyType key, ItemType item);

	// Advanced function to rehash the table for better search optimisation:Kester
	// pre : none
	// post: none
	// return the new table
	void rehash();

	// get an item with the specified key in the Dictionary (retrieve):Kester
	// pre : key must exist in the dictionary
	// post: none
	// return the item with the specified key from the Dictionary
	ItemType get(KeyType key);

	// returns item with specified key given  :Kester
	// pre : none
	// post: none
	// return the item with the specified key from the Dictionary
	bool getListHelper(Node* n, KeyType key, vector<ItemType> &list);

	// get a vector of paths with the specified key in the Dictionary (retrieve):Kester
	// pre : key must exist in the dictionary
	// post: none
	// return the items with the specified key from the Dictionary
	vector<ItemType> getList(KeyType key);

	// removes specified key in the Dictionary and insert existing key with new itemtype :Kester
	// pre : key must exist in the dictionary
	// post: itemtype of key must be changed
	// return a success/failure result from this method
	bool update(KeyType ekey, ItemType eItem, KeyType nKey, ItemType nItem);

	// check if the Dictionary is empty:Kester
	// pre : none
	// post: none
	// return true if the Dictionary is empty; otherwise returns false
	bool isEmpty();

	// check the size of the Dictionary:Kester
	// pre : none
	// post: none
	// return the number of items in the Dictionary
	int getLength();

	// check if the chain size is exceeded:Kester
	// pre : none
	// post: none
	// return true if the number of nodes in chain is >= CHAIN_SIZE; otherwise returns false
	bool exceedChainLimit(int index);

	//------------------- Other useful functions -----------------

	// display the items in the Dictionary:Kester
	void print();

	// void replace(KeyType key, ItemType item);
	// bool contains(KeyType key);
};