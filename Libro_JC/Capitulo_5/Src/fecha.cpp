/*
 * fecha.cpp
 *
 *  Created on: 2 sep. 2021
 *      Author: simon
 */
#include "fecha.h"

Cfecha::Cfecha(int dd, int mm, int aaaa) : dia{dd}, mes{mm}, anyo{aaaa}{
	if(! fechaValida(dd, mm, aaaa)){
		cout << "Fecha incorrecta. Se asigna 01/01/2001";
		dia 	= 1;
		mes		= 1;
		anyo 	= 2001;
	}
}

bool Cfecha::anyoBisiesto(int aaaa) const{
	return (((aaaa % 4 == 0) && (aaaa % 100 != 0)) || (aaaa % 400 == 0));
}

bool Cfecha::fechaValida(int dd, int  mm, int aaaa) const{
	bool diaCorrecto, mesCorrecto, anyoCorrecto;
	anyoCorrecto	= (aaaa >= 1582);
	mesCorrecto 	= (mm >= 1) && (mm <= 12);
	switch(mm){
	case 2:
		if(anyoBisiesto(aaaa))
			diaCorrecto = (dd >= 1 && dd <= 29);
		else
			diaCorrecto	= (dd >= 1 && dd <= 28);
		break;
	case 4: case 6: case 9: case 11:
		diaCorrecto = (dd >= 1 && dd <= 30);
		break;
	default:
		diaCorrecto = (dd >= 1 && dd <= 31);
	}
	return (diaCorrecto && mesCorrecto && anyoCorrecto);
}

/* Todo esto se suplanta con un prototipo con argumentos preestablecidos.
bool Cfecha::asignarFecha(void){
	//Por omision asignar fecha actual
	struct tm* fh;
	time_t segundos;

	time(&segundos);
	fh = localtime(&segundos);

	dia 	= fh->tm_mday;	//Dia del 1 al 31.
	mes 	= fh->tm_mon + 1;	//Mes de 0 a 11
	anyo 	= fh-> tm_year + 1900; //Año -1900
	return true;
}

bool Cfecha::asignarFecha(int dd){
	asignarFecha();
	if(! fechaValida(dd, mes, anyo)){
		cout << "Fecha incorrecta. Se asigna 01/01/2001.\n";
		dia 	= 1;
		mes 	= 1;
		anyo 	= 2001;
		return false;
	}
	dia = dd;
	return true;
}

bool Cfecha::asignarFecha(int dd, int mm){
	asignarFecha();
	if(! fechaValida(dd, mm, anyo)){
		cout << "Fecha incorrecta. Se asigna 01/01/2001.\n";
		dia 	= 1;
		mes 	= 1;
		anyo 	= 2001;
		return false;
	}
	dia = dd;
	mes = mm;
	return true;
}
*/

bool Cfecha::asignarFecha(int dd, int mm, int aaaa){
	struct tm* fh;
	time_t segundos;

	time(&segundos);
	fh = localtime(&segundos);

	if(aaaa == 0 && mm == 0 && dd == 0) //Cero argumentos
		dd = fh->tm_year;				//dia del 1 al 31
	if(aaaa == 0 && mm == 0)			//Un argumento
		mm = fh->tm_mon;
	if(aaaa == 0)						//Dos argumentos
		aaaa = fh->tm_year + 1900;		//Año - 1900
	if(! fechaValida(dd, mm, aaaa)){
		cout << "Fecha incorrecta. Se asigna 01/01/2001.\n";
		dia 	= 1;
		mes 	= 1;
		anyo 	= 2001;
		return false;
	}
	dia	 	= dd;
	mes 	= mm;
	anyo 	= aaaa;
	return true;
}

void Cfecha::obtenerFecha(int& dd, int& mm, int& aaaa)const{
	dd 		= dia;
	mm 		= mes;
	aaaa 	= anyo;
}

