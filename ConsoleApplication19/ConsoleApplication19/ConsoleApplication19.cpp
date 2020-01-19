#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
void print(vector<vector<int>> matrizans) {
	for (int a = 0; a < matrizans.size(); a++) {
		for (int e = 0; e < matrizans.size(); e++) {
			cout << matrizans[a][e] << " ";
		}
		cout << endl;
	}
	system("pause");
}
vector<vector<int>> multiplicacion(vector<vector<int>> matrizz, vector<vector<int>> matrizzz,bool v)
{
	vector<vector<int>>  matrizans, matriz[2] = { matrizz,matrizzz };
	/*matriz[0] = { {1,2},{2,0} };
	matriz[1] = { {9,10},{10,4} };*/
	matrizans.resize(matriz[0].size());
	if (matriz[1].size() == matriz[0][0].size()) {
		for (int e = 0; e < matriz[0].size(); e++) {
			for (int i = 0; i < matriz[0].size(); i++) {
				matrizans[e].resize(matriz[0].size());
				matrizans[e][i] = 0;
				for (int o = 0; o < matriz[0][0].size(); o++) {
					matrizans[e][i] += matriz[0][e][o] * matriz[1][o][i];
				}
			}
		}
	}
	else {
		cout << "esto no se puede !#@&%$" << endl;
		return{ {} };
	}
	if (v) {
		print(matrizans);
	}
	return matrizans;
}
void multiplicacion() {
	vector<vector<int>> matriz[2];
	int columnas, filas;
	for (int a = 0; a < 2; a++) {
		cout << "cuantas filas tiene la matriz " << a + 1 << endl;
		cin >> columnas;
		cout << "cuantas columnas tiene la matriz " << a + 1 << endl;
		cin >> filas;
		matriz[a].resize(columnas);
		for (int e = 0; e < columnas; e++) {
			matriz[a][e].resize(filas);
			for (int i = 0; i < filas; i++) {
				cin >> matriz[a][e][i];
			}
		}
	}
	multiplicacion(matriz[0],matriz[1],true);
}
void potencia() {
	vector<vector<int>> matriz, laotra, matrizans;
	int tamal,potencia;
	cout << "tamaño de tu matriz" << endl;
	cin >> tamal;
	matriz.resize(tamal);
	laotra.resize(tamal);
	for (int e = 0; e < tamal; e++) {
		matriz[e].resize(tamal);
		laotra[e].resize(tamal);
		for (int i = 0; i < tamal; i++) {
			cin >> matriz[e][i];
			if (e == i) {
				laotra[e][i] = 1;
			}
			else {
				laotra[e][i] = 0;
			}
		}
	}
	cout << "a que potencia la quieres elevar: ";
	cin >> potencia;
	for (int a = 0; a < potencia; a++) {
		laotra = multiplicacion(matriz,laotra,false);
	}
	print(laotra);
}
int main() {
	cout << "matriz por matriz:1,matriz elevada ala x:2"<<endl;
	int a;
	cin >> a;
	switch (a) {
	case 1:
		multiplicacion();
		break;
	case 2:
		potencia();

	}
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
