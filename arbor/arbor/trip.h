#pragma once
#include <string>
using namespace std;
class trip
{
public:
	string inicio;
	string destino;
	double distancia;
	trip();
	trip(string a, string e, int i) :inicio(a), destino(e), distancia(i) {};
	~trip();
};

