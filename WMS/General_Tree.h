/*
Team Member: Gabriel Goh
Student ID: S10198258E
Group: 11
*/


#pragma once
#include <string>
#include <vector>
using namespace std;
typedef string Itemtype;
struct GeneralNode
{
	int usedMemory = 0;
	Itemtype item; // gabriel -> folder6
	vector<GeneralNode*> TParent;
};


