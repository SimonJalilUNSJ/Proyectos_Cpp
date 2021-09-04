/*
 * matrizDoble2D.cpp
 *
 *  Created on: 1 sep. 2021
 *      Author: simon
 */

#include <iostream>
#include "matrizDoble2D.h"
#include "utilidades.h"

using namespace std;

void construirMatriz(matrizDoble2D& m, int filas, int cols){
	m = matrizDoble2D(filas, matrizDoble1D(cols,0));
}

void leerMatriz(matrizDoble2D& m){
	for(size_t fila = 0; fila < m.size(); ++fila){
		for(size_t col = 0; col < m[fila].size(); col++){
			cout << "m[" << fila << "][" << col << "]";
			leerDouble(m[fila][col]);
		}
	}
}

void leerMatrizIt(matrizDoble2D& m){
	matrizDoble2D::iterator ifilas;
	matrizDoble1D::iterator	icols;
	size_t fila, col;

	for(fila = 0, ifilas = m.begin(); ifilas != m.end(); ifilas++, fila++){
		for(col = 0, icols = (*ifilas).begin(); icols != (*ifilas).end(); icols++, col++){
			cout << "m[" << fila << "][" << col << "]";
			leerDouble(m[fila][col]);
		}
	}
}

void leerMatrizC(matrizDoble2D& m){
	int f = 0, c = 0;
	for (matrizDoble1D& fila : m){
		for(double& e : fila){
			cout << "m[" << f << "][" << c++ << "]";
			leerDouble(e);
		}
		f++; c = 0;
	}
}

void mostrarMatriz(matrizDoble2D& m){
	for(size_t fila = 0; fila < m.size(); ++fila){
		for(size_t col = 0; col < m[fila].size(); col++){
			cout<< m[fila][col] << " ";
		}
		cout << endl;
	}
}

void mostrarMatrizIt(matrizDoble2D& m){
	matrizDoble2D::iterator ifilas;
	matrizDoble1D::iterator icols;

	for(ifilas = m.begin(); ifilas != m.end(); ifilas++){
		for(icols = (*ifilas).begin(); icols != (*ifilas).end(); icols++){
			cout << *icols << " ";
		}
		cout << endl;
	}
}

void mostrarMatrizC(matrizDoble2D& m){
	for (matrizDoble1D fila : m){
		for(double e : fila){
			cout << e << " ";
		}
		cout << endl;
	}
}
