#include<iostream>
#include<vector>
#include"trip.h"
#include "arbol.h"
#include<algorithm>
#include<map>
#include"graph.h"
using namespace std;
int main() {
	map<string, map<string, int>> grafo;
	vector<string> usados;
	string inicio;
	string end;
	arbol tree;
	double distancia;
	bool z,x;
	while (true) {
		cin >> inicio >> end >> distancia;
		if (inicio == "|")
			break;
		x = true;
		z = true;
		for (map<string, map<string, int>>::iterator i = grafo.begin(); i != grafo.end();i++) {
			if (i->first == inicio) {
				grafo[inicio].insert({ end, distancia });
				x = false;

			}
			if (i->first == end) {
				grafo[end].insert({ inicio, distancia });
				z = false;
			}
		}
		if (x) {
			grafo.insert({ inicio, { {end,distancia} } });
		}
		if (z) {
			grafo.insert({ end, { {inicio,distancia} } });
		}
	}
	tree.first(grafo.begin()->first);
	usados.push_back(grafo.begin()->first);
	trip este;
	for (int z = 1; z < grafo.size();z++) {
		este = { "","",-1 };
		for (int a = 0; a < usados.size(); a++) {
			for (map<string, int>::iterator i = grafo[usados[a]].begin(); i != grafo[usados[a]].end(); i++) {
				if (este.distancia == -1 || i->second < este.distancia) {
					este = { usados[a],i->first,i->second };
				}
			}
		}
		for (int a = 0; a < usados.size(); a++) {
			for (map<string, int>::iterator i = grafo[usados[a]].begin(); i != grafo[usados[a]].end(); i++) {
				if (este.destino == i->first) {
					grafo[usados[a]].erase(este.destino);
					break;
				}
			}
			for (map<string, int>::iterator i = grafo[este.destino].begin(); i != grafo[este.destino].end(); i++) {
				if (usados[a] == i->first) {
					grafo[este.destino].erase(usados[a]);
					break;
				}
			}
		}
		tree.add(este);
		usados.push_back(este.destino);
		cout << este.inicio << este.destino << este.distancia<<endl;
		
	}
	system("pause");
}