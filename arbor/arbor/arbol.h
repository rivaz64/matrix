#pragma once
#include "nodo.h"
#include "trip.h"
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
class arbol
{
	nodo* trunk;
	nodo* temp;
	vector<nodo*> places;
	int search(string );
public:
	arbol();
	void first(string);
	void add(trip);
	void poner(string, string, int);
	~arbol();
};

