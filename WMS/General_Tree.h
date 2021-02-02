#pragma once
#include <string>
#include <vector>
using namespace std;
typedef string Itemtype;
struct GeneralNode
{
	int usedMemory = 0;
	Itemtype item; // gabriel -> folder6
	vector<GeneralNode*> Tfolder;
};


