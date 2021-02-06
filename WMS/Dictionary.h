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

	int hash(KeyType key);

	// add a new item with the specified key to the Dictionary
	// pre : none
	// post: new item is added to the Dictionary
	//       size of Dictionary is increased by 1
	bool add(KeyType newKey, ItemType newItem);

	// remove an item with the specified key in the Dictionary
	// pre : key must exist in the Dictionary
	// post: item is removed from the Dictionary
	//       size of Dictionary is decreased by 1
	void remove(KeyType key, ItemType item);

	// Advanced function to rehash the table for better search optimisation
	// pre : none
	// post: none
	// return the new table
	void rehash();

	// get an item with the specified key in the Dictionary (retrieve)
	// pre : key must exist in the dictionary
	// post: none
	// return the item with the specified key from the Dictionary
	ItemType get(KeyType key);

	vector<ItemType> getList(KeyType key);

	// removes specified key in the Dictionary and insert existing key with new itemtype 
	// pre : key must exist in the dictionary
	// post: itemtype of key must be changed
	// return a success/failure result from this method
	void update(KeyType ekey, ItemType eItem, KeyType nKey,  ItemType nItem);

	// check if the Dictionary is empty
	// pre : none
	// post: none
	// return true if the Dictionary is empty; otherwise returns false
	bool isEmpty();

	// check the size of the Dictionary
	// pre : none
	// post: none
	// return the number of items in the Dictionary
	int getLength();

	//------------------- Other useful functions -----------------

	// display the items in the Dictionary
	void print();

	// void replace(KeyType key, ItemType item);
	// bool contains(KeyType key);
};