/*
 * Matriz.cpp
 *
 *  Created on: 15 jul. 2021
 *      Author: simon
 */
#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> construirMatriz(int filas, int columnas);
void leerMatriz(vector<vector<double>>& m);
void mostrarMatriz(vector<vector<double>>& m);

int main(){
	int filas, columnas;
	cout << "N° de filas de la matriz: ";
	cin >> filas;
	cout << "N° de columnas de la matriz: ";
	cin >> columnas;
	vector<vector<double>> m = construirMatriz(filas,columnas);
	leerMatriz(m);
	mostrarMatriz(m);
	cout << endl;
	return 0;
}

vector<vector<double>> construirMatriz(int filas, int columnas){
	vector<vector<double>> v(filas,vector<double>(columnas,0));
	return v;
}

void leerMatriz(vector<vector<double>>& m){
	//m representa una matriz de dos dimensiones.
	//m.size() es el numero de filas de m
	//m[f] es una fila de m (matriz unidimensional)
	//m[f].size() es el número de elemntos (columnas) de la fila f
	for(size_t f = 0; f < m.size(); ++f){
		for(size_t c = 0; c < m[f].size(); ++c){
			cout << "m[" << f << "][" << c << "]:" ;
			cin >> m[f][c];
		}
	}
}

void mostrarMatriz(vector<vector<double>>& m){
	for(auto v: m){
		for(auto e: v)
			cout << e << " ";
		cout << endl;
	}
}



