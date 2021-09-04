/*
 * main.h
 *
 *  Created on: 1 sep. 2021
 *      Author: simon
 */

#ifndef UTILIDADES_H_
#define UTILIDADES_H_

#include "utilidades.h"
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

bool leerDouble(double& dato);
bool leerInt(int& dato);
bool leerCadena(char* dato, int n);
int crearMenu(const char* opMenu[], int num_opciones);
char si_no(void);


#endif /* UTILIDADES_H_ */
