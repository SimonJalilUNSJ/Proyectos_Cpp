/*
 * main3.cpp
 *
 *  Created on: 1 sep. 2021
 *      Author: simon
 */

/*
 * En este proyecto se puede ver como se trabaja con matrices de dos
 * dimensiones.
 */

#include "utilidades.h"
#include "matrizDoble2D.h"

int main(void){
	int opcion = 0;
	static const char* opciones[] = {
			"Construir matriz",
			"Leer matriz",
			"Mostrar matriz",
			"Finalizar"
	};

	const int num_opciones = sizeof(opciones) / sizeof(char *);

	enum op {Construir = 1, Leer, Mostrar, Finalizar};

	matrizDoble2D m;
	int filas, cols;

	do{
		system("clear");
		opcion = crearMenu(opciones, num_opciones);
		switch(opcion){
		case Construir:
			if(!m.empty()){
				cout << "Ya existe una matriz. ¿Desesa destruirla? ";
				if (si_no() == 'n')
					break;
			}
			do{
				cout << "N° de filas de la matriz ";
				leerInt(filas);
			}while(filas < 1);
			do{
				cout << "N° de columnas de la matriz ";
				leerInt(cols);
			}while(cols < 1);
			construirMatriz(m,filas,cols);
			cout << "Matriz construida\n";
			getchar();
			break;

		case Leer:
			if(m.empty())
				cout << "No existe una matriz\n";
			else
				leerMatrizC(m);
				//LeerMatrizIt(m);
			getchar();
			break;

		case Mostrar:
			if(m.empty())
				cout << "No existe una matriz\n";
			else
				mostrarMatriz(m);
				//mostrarMatrizIt(m);
			getchar();
			break;

		case Finalizar:
			break;
		}
	}while(opcion != Finalizar);

	return 0;
}
