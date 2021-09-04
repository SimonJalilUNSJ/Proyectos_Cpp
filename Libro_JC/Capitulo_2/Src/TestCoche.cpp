/*
 * TestCoche.cpp
 *
 *  Created on: 19 jul. 2021
 *      Author: simon
 */
#include "CCoche.h"

int crearMenu(const char* opMenu[], int num_opciones);

int main(void){
	int opcion = 0;
	static const char* opciones[] ={
			"Arrancar Motor",
			"Acelerar",
			"Frenar",
			"Ver estado",
			"Apagar Motor",
			"Finalizar"
	};

	const int num_opciones = sizeof(opciones) / sizeof(char *);

	enum op {Arrancar = 1, Acelerar, Frenar, Estado, ApagarMotor, Finalizar};

	CCoche miCoche("Fiat", "1994", "Rojo");

	do{
		system("clear");
		opcion = crearMenu(opciones, num_opciones);

		switch(opcion){
		case Arrancar:
			miCoche.arrancarMotor();
			system("pause");
			break;
		case Acelerar:
			miCoche.acelerar();
			system("pause");
			break;
		case Frenar:
			miCoche.frenar();
			system("pause");
			break;
		case Estado:
			miCoche.estado();
			system("pause");
			break;
		case ApagarMotor:
			miCoche.apagarMotor();
			system("pause");
			break;
		case Finalizar:
			cout << "Finalizando..." << endl;
			break;
		}
	}while(opcion != Finalizar);

	return 0;
}

int crearMenu(const char* opMenu[], int num_opciones){
	int opcion;
	system("clear");

	//Presentar el menu
	cout << "\nElija una opcion:\n" << endl;
	for(int i = 0; i < num_opciones; i++)
		cout << "\t" << i+1 << ". " << opMenu[i] << endl;


	//Elegir una opcion y comprobar que es correcta.
	do{
		cout << "<<";
		cin >> opcion;

		if(opcion < 1 || opcion > num_opciones)
			cout << "Opcion incorrecta.\n" << endl;
	}while(opcion < 1 || opcion > num_opciones);
	return opcion;
}

