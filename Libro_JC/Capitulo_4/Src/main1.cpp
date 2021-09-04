/*
 * main.cpp
 *
 *  Created on: 1 sep. 2021
 *      Author: simon
 */
#include "utilidades.h"

/*1) Realizar un programa que lea y almacene una lista de valores introducida por el teclado.
 * Una vez leida, buscara los valores máximo y mínimo, y los imprimira.
 *
 * */
int main(){
	vector<double> dato;	//Matriz de datos vacia

	//Entrada de datos
	cout << "Introducir datos. Finalizar con eof (Ctrl+z). \n";
	int i = 0;
	cout << "dato[" << i++ << "] = ";
	double valor;

	bool datoDouble = leerDouble(valor);
	while(datoDouble){
		dato.push_back(valor);
		cout << "dato[" << i++ << "] = ";
		datoDouble = leerDouble(valor);
	}

	//Encontrar los valores maximo y minimo
	int nElementos = dato.size(); //Numero de elementos de la matriz
	float max, min;
	if(! dato.empty()){
		max = min = dato[0];
		for (i = 0; i< nElementos; i++){
			if(dato[i] > max)
				max = dato[i];
			if(dato[i] < min)
				min = dato[i];
		}

		//Escribir resultados
		cout << "Valores maximo: " << max
			 << ", valor minimo: " << min << endl;
	}else {
		cout << "No hay datos.\n";
	}
}



