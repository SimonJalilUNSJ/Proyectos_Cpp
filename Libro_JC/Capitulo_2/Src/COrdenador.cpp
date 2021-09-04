/*
 * COrdenador.cpp
 *
 *  Created on: 16 jul. 2021
 *      Author: simon
 */

#include "COrdenador.h"

COrdenador::COrdenador(){
	marca = "Marca desconocida";
	procesador = "Procesador Desconocido";
	peso = 0.0;
	encendido = false;
	pantalla = false;
}

void COrdenador::encenderOrdenador(){
	if(encendido){
		cout << "El ordenador ya esta encendido.\n";
	}else{
		encendido = true;
		pantalla = true;
		cout << "El ordenador ha sido encendido.\n";
	}
}

void COrdenador::apagarOrdenador(){
	if(!encendido)
		cout << "El ordenador ya esta apagado.\n";
	else{
		encendido = false;
		pantalla = false;
		cout << "El ordenador ha sido apagado.\n";
	}
}

void COrdenador::pantallaOn(){
	if(pantalla)
		cout << "\nLa pantalla ya esta activada.\n";
	else{
		pantalla = true;
		cout << "\nLa pantalla esta activada.\n";
	}
}

void COrdenador::pantallaOff(){
	if(!pantalla)
		cout << "\nLa pantalla ya esta apagada.\n";
	else{
		pantalla = true;
		cout << "\nLa pantalla esta apagada.\n";
	}
}

void COrdenador::estado(){
	cout << "\nEl estado del ordenador es el siguiente:\n";
	cout << "\nMarca: " << marca;
	cout << "\nProcesador: " << procesador;
	cout << "\nPeso: " << peso << " kg.\n";
	if(encendido)
		cout << "El ordenador esta encendido.\n";
	else
		cout << "El ordenador esta apagado.\n";
	if(pantalla)
		cout << "La pantalla esta activada.\n";
	else
		cout << "La pantalla esta desactivada.\n";
}

string COrdenador::obtenerMarca(void){
	return marca;
}

void COrdenador::asignarMarca(string mar){
	if(mar.length() == 0)
		marca = "Marca desconocida\n";
	else
		marca = mar;
}

void COrdenador::cargarApp(){
	if(encendido && pantalla)
		cout << "Cargar app...\n" << endl;
	else
		cout << "Pantalla o encendido apagados.\n";
}

void COrdenador::asignarProcesador(string pro){
	if(pro.length() == 0)
		procesador = "Procesador Desconocido";
	else
		procesador = pro;
}

void COrdenador::asignarPeso(float pes){
	if(peso < 0){
		cout << "Error en peso\n";
		peso = 0.0;
	}else
		peso = pes;
}
