/*
 * main2.cpp
 *
 *  Created on: 1 sep. 2021
 *      Author: simon
 */

/*
 * En este ejemplo se analizan la validacion de entrada de datos
 * y su posterior lectura.
 * */

#include "utilidades.h"

int main(void){
	int i = 0;
	double d = 0.0;
	char cad[40];

	int opcion = 0;
	static const char* opciones[] = {
		"Leer un int",
		"Leer un double",
		"Leer una cadena",
		"Finalizar"
	};

	const int num_opciones = sizeof(opciones) / sizeof(char *);
	enum op {LeerInt = 1, LeerDouble, LeerCadena, Finalizar};

	do{
		system("clear");
		opcion = crearMenu(opciones, num_opciones);
		switch(opcion){
			case LeerInt:
				if(leerInt(i))
					cout << i << endl;
				else
					cout << "eof\n";
				getchar();
				break;

			case LeerDouble:
				if(leerDouble(d))
					cout << d << endl;
				else
					cout << "eof\n";
				getchar();
				break;

			case LeerCadena:
				if(leerCadena(cad, sizeof(cad)))
					cout << cad << endl;
				else
					cout << "eof\n";
				getchar();
				break;

			case Finalizar:
				break;
		}
	}while(opcion != Finalizar);
}
