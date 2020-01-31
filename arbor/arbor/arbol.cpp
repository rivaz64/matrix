#include "arbol.h"


arbol::arbol()
{
}

void arbol::first(string a)
{
	trunk = new nodo();
	trunk->place = a;
	places.push_back(trunk);
}

void arbol::add(trip a)
{
	for (int e = 0; e < places.size(); e++) {
		if (places[e]->place == a.inicio) {
			temp = new nodo(a.distancia, a.destino);
			places[e]->addnode(temp);
			places.push_back(temp);
			break;
		}
	}
	
}

void arbol::poner(string a, string e, int i)
{

}

arbol::~arbol()
{
}
