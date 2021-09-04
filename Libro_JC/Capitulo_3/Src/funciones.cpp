/*
 * funciones.cpp
 *
 *  Created on: 31 ago. 2021
 *      Author: simon
 */
#include "main.h"

complejo sumar(const complejo& a, const complejo& b){
	complejo temp;
	temp.real = a.real + b.real;
	temp.imag = a.imag + b.imag;
	return temp;
}

complejo restar(const complejo& a, const complejo& b){
	complejo temp;
	temp.real = a.real - b.real;
	temp.imag = a.imag - b.imag;
	return temp;
}

complejo multiplicar(const complejo& a, const complejo& b){
	complejo temp;
	temp.real = a.real * b.imag - a.real * b.imag;
	temp.imag = a.real * b.imag + a.imag * b.real;
	return temp;
}

complejo dividir(const complejo& a, const complejo& b){
	complejo temp;
	double denom, numer1, numer2;

	denom = pow(b.real,2) + pow(b.imag,2);
	if(denom != 0){
		numer1 = a.real * b.real + a.imag * b.imag;
		numer2 = a.imag * b.real + a.real * b.imag;

		temp.real = numer1 / denom;
		temp.imag = numer2 / denom;
	}else{
		temp.real = 0;
		temp.imag = 0;
		cout << "Error: Division por cero.\n";
	}
	return temp;
}

double argumento(const complejo& a){
	if(a.real != 0)
		return atan(a.imag/a.real);
	else{
		cout << "Error: Division por cero.\n";
		return 0;
	}
}

double modulo(const complejo& a){
	return (sqrt(pow(a.real,2) + pow(a.imag,2)));
}

void DFT(vector<complejo>& X, const vector<double>& x){
	int n, k, N = x.size();
	double t, pi = 3.14;
	complejo a, b;

	for(k = 0; k < N; k++){
		X[k].real = 0;
		X[k].imag = 0;

		for(n = 0; n < N; n++){
			a.real = x[n];
			a.imag = 0;

			t = k * 2 * pi / N * n;

			b.real = cos(-t);
			b.imag = sin(-t);

			b = multiplicar(a, b);
			X[k] = sumar(X[k],b);
		}
	}
}

void imprimirComplejo(const complejo& a){
	cout << "(" << a.real << " , " << a.imag << ")" << endl;
}

