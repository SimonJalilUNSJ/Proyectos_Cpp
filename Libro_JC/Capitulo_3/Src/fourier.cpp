/*
 * fourier.cpp
 *
 *  Created on: 31 ago. 2021
 *      Author: simon
 */

/*1) Se desea escribir un programa que calcule la DFT de una secuencia de numeros reales x[n]
 * a) Escribir funciones de sumar y multiplicar complejos
 * b) Escribir una funcion que calcule la DFT
 * c) Escribir un programa que lea del archivo estandar de entrada una secuencia de numeros reales y escriba en el archivo
 * estandar de salida una secuencia correspondiente a la DFT
 * */

/*2) Realizar un programa que permita sumar, restar, multiplicar y dividir complejos utilizando operadores
 * +, - , *, y /, asi como calcular el argumento y el modulo de un complejo
 * */

#include "main.h"

int main(void){
	complejo a,b, temp;

	//Crear la matriz que almacenara la secuencia de numeros reales.
	vector<double> x;

	//Introducir la secuencia de numeros reales.
	cout << "Introduzca los valores. Finalizar con eof\n";
	double n;
	while (cin >> n)
		x.push_back(n);

	//Crear la matriz de complejos
	vector<complejo>X(x.size());

	//Calcular la transformada discreta de fourier
	DFT(X,x);
	cout << "Resultado:\n";
	for(int n = 0; n < (int)X.size(); n++){
		cout << showpos << X[n].real << X[n].imag << "j\n";
	}

	//Ingresar dos numeros complejos
	cout << "Ingresar parte real de primer complejo\n";
	cin >> a.real;
	cout << "Ingresar parte imaginaria del primer complejo.\n";
	cin >> a.imag;

	cout << "Ingresar parte real de segundo complejo\n";
	cin >> b.real;
	cout << "Ingresar parte imaginaria del segundo complejo.\n";
	cin >> b.imag;

	temp = sumar(a, b);
	imprimirComplejo(temp);

	temp = restar(a, b);
	imprimirComplejo(temp);

	temp = multiplicar(a, b);
	imprimirComplejo(temp);

	temp = dividir(a, b);
	imprimirComplejo(temp);
}
