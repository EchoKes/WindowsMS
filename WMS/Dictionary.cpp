#include <iostream>
#include "Dictionary.h" 
using namespace std;


Dictionary::Dictionary() {
	Node* topNode = NULL;
	items.resize(MAX_SIZE);

	for (int i = 0; i < MAX_SIZE; i++) {
		items[i] = NULL;
	}
	size = 0;
}

Dictionary::~Dictionary() {}

int Dictionary::hash(KeyType key) {
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

bool Dictionary::add(KeyType key, ItemType item) {
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

	if (topNode == NULL) {
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

void Dictionary::remove(KeyType key, ItemType item){
	int index = hash(key);
	Node* current = items[index];

	if (current->key == key && current->item == item) {
		items[index] = current->next;
		current = NULL;
		delete current;
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

ItemType Dictionary::get(KeyType key) {
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

// case for when programme allows adding of the same files in different directories
vector<ItemType> Dictionary::getList(KeyType key) {
	vector<ItemType> itemList;
	int index = hash(key);
	topNode = items[index];
	Node* current = topNode;

	while (current != NULL)
	{
		if (current->key == key)
		{
			itemList.push_back(current->item);
		}
		current = current->next;
	}

	return itemList;
}

bool isPrime(int current, int divisor) {
	if (current % divisor == 0)
		return false;
	if (divisor * divisor > current)
		return true;
	return isPrime(current, divisor + 1);
}

int nextPrime(int current) {
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

void Dictionary::update(KeyType eKey, ItemType eItem, KeyType nKey, ItemType nItem) {
	remove(eKey, eItem);
	add(nKey, nItem);
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


bool Dictionary::isEmpty() {
	return (bool(size));
}

void Dictionary::print() {
	for (Node* n : items) {
		if (n != NULL) {
			Node* current = n;
			while (current != NULL) {
				cout << current->key << ", " << current->item << "	";
				current = current->next;
			}
			cout << endl;
		}
		else {
			cout << "\b";
		}	
	}
}

//
//int main()
//{
//	Dictionary d;
//	string array[5] = { "john1.txt", "john2.txt", "john3.txt", "john4.txt", "john5.txt" };
//
//	for (string s : array)
//	{
//		d.add(s, "root/" + s);
//	}
//	d.add("john5.txt", "root/testPath");
//	cout << "Test Case 1: Showing of all items" << endl;
//	d.print();
//	cout << endl;
//	//cout << d.get("john5.txt");
//	cout << "Test Case 2: Showing of all paths in selected filename" << endl;
//	for (auto x : d.getList("john5.txt"))
//	{
//		cout << x << endl;
//	}
//	cout << endl;
//
//	/*d.remove("john5.txt", "root/john5.txt");
//	cout << "Test Case 3: Deletion of john5.txt with path value of root/john5.txt" << endl;
//	d.print();
//	cout << endl;*/
//	d.rehash();
//	cout << "Test Case 4: Showing of all items after rehash" << endl;
//	d.print();
//	cout << endl;
//	d.update("john3.txt", "root/john3.txt", "john5.txt", "root/john5.txt");
//	d.print();
//
//
//	return 0;
//}