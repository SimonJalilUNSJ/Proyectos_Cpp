/*
 * matrizDoble2D.h
 *
 *  Created on: 1 sep. 2021
 *      Author: simon
 */

#ifndef MATRIZDOBLE2D_H_
#define MATRIZDOBLE2D_H_

#include <vector>

using namespace std;

typedef vector<vector<double>> matrizDoble2D;
typedef vector<double> matrizDoble1D;

void construirMatriz(matrizDoble2D& m, int filas, int cols);

void leerMatriz(matrizDoble2D& m);
void leerMatrizIt(matrizDoble2D& m);
void leerMatrizC(matrizDoble2D& m);

void mostrarMatriz(matrizDoble2D& m);
void mostrarMatrizIt(matrizDoble2D& m);
void mostrarMatrizC(matrizDoble2D& m);

#endif /* MATRIZDOBLE2D_H_ */
