/*
 * test.cpp
 *
 *  Created on: 2 sep. 2021
 *      Author: simon
 */

#include "fecha.h"

void leerFecha(int&, int&, int&);
void visualizarFecha(Cfecha& fecha);

int main(void){
	Cfecha fecha;
	int dd = 0, mm = 0, aaaa = 0;
	bool fechaValida = true;
	do{
		leerFecha(dd,mm,aaaa);
		//fechaValida = fecha.asignarFecha(dd, mm, aaaa);
		fechaValida = fecha.asignarFecha(dd, mm);
	}while(! fechaValida);
	visualizarFecha(fecha);
}

void leerFecha(int& dia, int& mes, int& anyo){
	cout << "dia:	"; cin >> dia;
	cout << "mes:	"; cin >> mes;
	cout << "año:	"; cin >> anyo;
}

void visualizarFecha(Cfecha& fecha){
	int dd, mm, aaaa;
	fecha.obtenerFecha(dd, mm, aaaa);
	cout << dd << "/" << mm << "/" << aaaa << "\n";
}
