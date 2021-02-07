/*
Team Member: Kester Yeo
Student ID: S10185261A
Group: 11

Features to take note will be hash and rehashing function
as these 2 functions will determine if the searching's 
complexity will be better/worse.
*/


#include <iostream>
#include "Dictionary.h" 
using namespace std;


Dictionary::Dictionary() 
{
	Node* topNode = NULL;
	items.resize(MAX_SIZE);

	for (int i = 0; i < MAX_SIZE; i++) 
	{
		items[i] = NULL;
	}
	size = 0;
}

Dictionary::~Dictionary() {}

int Dictionary::hash(KeyType key) 
{
	int total = 0;
	int n = key.length();

	unsigned long int hash = 5381;
	int c;
	for(char x: key)
	{	
		c = x;
		hash = ((hash << 5) + hash) + c;
		/* hash * 33 + c */
	}

	return (hash % MAX_SIZE);
}

bool Dictionary::add(KeyType key, ItemType item) 
{
	int index = hash(key);
	//cout << index << endl;
	topNode = items[index];
	Node* newNode = new Node;
	newNode->item = item;
	newNode->key = key;
	newNode->next = NULL;

	//if (exceedChainLimit(index)) {
	//	rehash();
	//	//cout << MAX_SIZE << endl;
	//}

	if (topNode == NULL) 
	{
		items[index] = newNode;
	}
	else
	{
		Node* current = topNode;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
	size++;
	return true;
}

void Dictionary::remove(KeyType key, ItemType item)
{
	int index = hash(key);
	Node* current = items[index];

	if (current->key == key && current->item == item) 
	{
		items[index] = current->next;
		current = NULL;
		delete current;	// deallocate memory 
	}
	else {
		//cout << current->item << endl;
		while (current->next->key != key && current->next->item == item)
		{
			current = current->next;
		}
		Node* temp = current->next;
		current->next = current->next->next;
		temp = NULL;
		delete temp;
		size--;
	}
}

/* This function will not be in use as it has been confirmed that
the application will display a list of the paths with same file/folder
name. */
ItemType Dictionary::get(KeyType key) 
{
	string path = "not found";
	int index = hash(key);
	topNode = items[index];
	Node* current = topNode;

	while (current != NULL)
	{
		if (current->key == key)
		{
			path = current->item;
		}
		current = current->next;
	}

	return path;
}

bool Dictionary::getListHelper(Node* n, KeyType key, vector<ItemType> &list)
{
	if(n == NULL)
	{
		return true;
	}
	if (n->key == key)
	{
		list.push_back(n->item);	
	}
	if (n->next != NULL)
	{
		getListHelper(n->next, key, list);
	}
}

vector<ItemType> Dictionary::getList(KeyType key) 
{
	vector<ItemType> itemList;
	int index = hash(key);
	topNode = items[index];
	Node* current = topNode;

	// best case scenario for when there is only one node
	if(current->next == NULL)
	{
		itemList.push_back(current->item);
	} 
	else
	{
		 /*while (current != NULL)
		 {
		 	if (current->key == key)
		 	{
		 		itemList.push_back(current->item);
		 	}
		 	current = current->next;
		 }*/

		// recursive function to improve searching time complexity
		getListHelper(current, key, itemList);
	}

	return itemList;
}

// get an integer which will be the size and divisor 
// pre : none
// post: none
// return true when the current size is a prime; otherwise return false
bool isPrime(int current, int divisor) {
	if (current % divisor == 0)
		return false;
	if (divisor * divisor > current)
		return true;
	return isPrime(current, divisor + 1);
}

// get an integer which will be the size
// pre : none
// post: none
// recursive function that will get the next largest prime number
int nextPrime(int current) 
{
	while (!isPrime(current, 2))
	{
		current++;
	}
	return current;
}

void Dictionary::rehash() 
{
	vector<Node*>tempItems = items;
	MAX_SIZE = nextPrime(MAX_SIZE);	//Sets MAX_SIZE to next nearest prime number
	items.clear();								
	items.resize(MAX_SIZE);						
	
	for (int i = 0; i < tempItems.size(); i++)	//loop thru all the items in tempItems
	{
		while (tempItems[i]!=NULL)
		{
			KeyType k = tempItems[i]->key;
			ItemType v = tempItems[i]->item;
			add(k,v);	// add to original vector "items"
			tempItems[i] = tempItems[i]->next;
		}
	}
}

bool Dictionary::update(KeyType eKey, ItemType eItem, KeyType nKey, ItemType nItem) 
{
	remove(eKey, eItem);
	bool result = add(nKey, nItem) ? true : false;
	return result;
}

int Dictionary::getLength() {
	return size;
}

bool Dictionary::exceedChainLimit(int index) {
	int chain_size = 0;
	Node* temp = items[index];
	while (temp != NULL)
	{
		chain_size++;
		temp = temp->next;
	}
	bool result = (chain_size >= CHAIN_SIZE) ? true : false;
	return result;
}

bool Dictionary::isEmpty() 
{
	return (bool(size));
}

void Dictionary::print() 
{
	for (Node* n : items) 
	{
		if (n != NULL) 
		{
			Node* current = n;
			while (current != NULL) 
			{
				cout << current->key << ", " << current->item << "	";
				current = current->next;
			}
			cout << endl;
		}
		else 
		{
			cout << "\b";
		}	
	}
}
