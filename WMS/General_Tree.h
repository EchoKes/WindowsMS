#pragma once
#include <string>
#include <vector>
typedef string Itemtype;
using namespace std;
struct GeneralNode
{
	int usedMemory = 0;
	Itemtype item; // gabriel -> folder
	vector<GeneralNode*> Tfolder;
};


