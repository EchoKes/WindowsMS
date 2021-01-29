#pragma once
#include <string>
typedef string Itemtype;
using namespace std;
struct GeneralNode
{
	int size = 3;
	int usedMemory = 0;
	Itemtype item; // gabriel -> folder
	GeneralNode* Tfolder[3];
	
};


