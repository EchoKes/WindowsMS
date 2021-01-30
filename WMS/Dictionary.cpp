#include <iostream>
#include "Dictionary.h" 
using namespace std;

Dictionary::Dictionary() {
	for (int i = 0; i < MAX_SIZE; i++) {
		items[i] = NULL;
	}
}

Dictionary::~Dictionary(){}

//This is the function to get the index of the file name so it can be inserted later on
int Dictionary::hash(KeyType key) {
	int total = 0;
	int n = key.length();
	
	for (int i = 0; i < n; i++) {
		char c = key.at(i);
		int ascChar = int(c);
		total += ascChar * (pow(n, n - 1));
		n -= 1;
	}

	return (total % MAX_SIZE);
}

bool Dictionary::add(KeyType key, ItemType item) {
	int index = hash(key);
	Node* current = items[index];
	Node* newNode = new Node;
	newNode->item = item;
	newNode->key = key;
	newNode->next = NULL;

	if (current == NULL) {
		items[index] = newNode;
	}
	else
	{
		current = items[index];
		if (current->key == key)
		{
			return false;
		}
		while (current->next != NULL)
		{
			current = current->next;
			if (current->key == key) 
			{
				return false;
			}
		}
		current->next = newNode;
	}
	size++;
	return true;
}

ItemType Dictionary::get(KeyType key) {
	string path = "not found";
	int index = hash(key);
	Node* current = items[index];
	if (current)
	{
		Node* temp = current;
		while(temp)
		{
			if (temp->key == key)
			{
				path = temp->item;
			}
		}
	}
	return path;
}

int Dictionary::getLength() {
	return size;
}

bool Dictionary::isEmpty() {
	return (bool(size));
}