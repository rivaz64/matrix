#include "nodo.h"




void nodo::addnode(nodo* a)
{
	nodes.push_back(a);
}

nodo::nodo(int a, string e)
{
	value = a;
	place = e;
}

nodo::nodo()
{
}

nodo::~nodo()
{
}
