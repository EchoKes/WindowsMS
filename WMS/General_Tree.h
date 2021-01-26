#pragma once

typedef int Itemtype;

struct GeneralNode
{
	Itemtype item; 
	GeneralNode* firstChild;
	GeneralNode* nextSibling;
};


