#pragma once
#include <vector>
#include <string>
using namespace std;
class nodo
{
	int value;
	string place;
	vector<nodo*> nodes;
	void addnode(nodo* a);
	friend class arbol;
public:
	nodo(int a, string e);
	nodo();
	~nodo();
};

