/*
 * utilidades.cpp
 *
 *  Created on: 1 sep. 2021
 *      Author: simon
 */
#include "utilidades.h"

//Leer un doble. Devuelve:
//true si se leyó un dato de tipo double
//false si EOF (se pulso Ctrl+z)
bool leerDouble(double& dato){
	bool fail = false, eof = false;
	do{
		cin >> dato;
		//Limpiar '\n'. Sólo se ejecuta si no hay error
		cin.ignore(numeric_limits<int>::max(), '\n');
		fail = cin.fail();
		eof = cin.eof(); //estado
		if(eof){
			cin.clear();
			return false;	//Se pulso Ctrl+Z
		}
		if(fail){
			cout << "error: dato no valido\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	}while(fail);
	return true;
}

/*Leer un int. Devuelve:
 * true si se leyó un dato de tipo int
 * false si EOF (se pulso Ctrl+D)
 * */
bool leerInt(int& dato){
	bool fail = false, eof = false;
	do{
		cout << ">> ";
		cin >> dato;
		//Limpiar '\n'. Solo se ejecuta si no hay error
		cin.ignore(numeric_limits<int>::max(), '\n');
		fail = cin.fail();
		eof = cin.eof();	//Estado
		if(eof){
			cin.clear();
			return false;	//Se pulso Ctrl+D
		}
		if(fail){
			cout << "Error: dato no valido\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(),'\n');
		}
	}while(fail);
	return true;
}


//Leer una cadena de n-1 caracteres como maximo
bool leerCadena(char* dato, int n){
	bool fail = false, eof = false;
	do{
		cout << ">> ";
		cin.getline(dato, n ,'\n');
		//Si se introducen n o mas caracteres
		//fail() devuelve true
		fail = cin.fail();
		eof = cin.eof();	//Estado
		if(eof){
			cin.clear();
			return false;
		}
		if(fail){
			cout << "Error: dato no válido\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	}while(fail);
	return false;
}

int crearMenu(const char* opMenu[], int num_opciones){
	int opcion;
	system("clear");	//Limpia pantalla
	//Presentar el menu
	cout << "\nElija una opcion:\n" << endl;
	for(int i = 0; i < num_opciones; i++)
		cout <<"\t" << i + 1 << ". " << opMenu[i] << endl;
	do{
		leerInt(opcion);
		if(opcion < 1 || opcion > num_opciones)
			cout << "Opcion incorrecta\n" << endl;
	}while(opcion < 1 || opcion > num_opciones);
	return opcion;
}

char si_no(void){
	char respuesta = 'n';
	do{
		cout << "s/n >> ";
		respuesta = tolower(cin.get());
		cin.ignore(numeric_limits<int>::max(), '\n');
	}while(respuesta != 's' && respuesta != 'n');
	return respuesta;
}
