/*
 * main.h
 *
 *  Created on: 31 ago. 2021
 *      Author: simon
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct complejo{

	double real, imag;
};

complejo sumar(const complejo& a, const complejo& b);
complejo restar(const complejo& a, const complejo& b);
complejo multiplicar(const complejo& a, const complejo& b);
complejo dividir(const complejo& a, const complejo& b);
double argumento(const complejo& a);
double modulo(const complejo& a);
void DFT(vector<complejo>& X, const vector<double>& x);
void imprimirComplejo(const complejo& a);


#endif /* MAIN_H_ */
