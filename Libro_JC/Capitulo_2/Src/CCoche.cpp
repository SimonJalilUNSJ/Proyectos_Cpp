/*
 * CCoche.cpp
 *
 *  Created on: 19 jul. 2021
 *      Author: simon
 */

#include "CCoche.h"

CCoche::CCoche(){
	marca = "Marca desconocida";
	modelo = "Modelo desconocido";
	color = "Color desconocido";
	marcha = 0;

}

CCoche::CCoche(string marc, string mod, string col){
	marca = marc;
	modelo = mod;
	color = col;
	marcha = 0;
}

void CCoche::asignarMarca(string mar){
	if(mar.length() == 0)
		marca = "Marca desconocida";
	else
		marca = mar;
}

void CCoche::asignarModelo(string mod){
	if(mod.length() == 0)
		modelo = "Modelo desconocido";
	else
		modelo = mod;
}

void CCoche::asignarColor(string col){
	if(col.length() == 0)
		color = "Color desconocido";
	else
		color = col;
}

void CCoche::asignarMarcha(int mar){
	if(mar < 0)
		marcha = 0;
	else
		marcha = mar;
}

string CCoche::obtenerMarca(void){
	return marca;
}

string CCoche::obtenerModelo(void){
	return modelo;
}

string CCoche::obtenerColor(void){
	return color;
}

int CCoche::obtenerMarcha(void){
	return marcha;
}

void CCoche::estado(void){
	cout << "\nEstado del coche:\n";
	cout << "Marca: "<< obtenerMarca() << "\n";
	cout << "Modelo: "<< obtenerModelo() << "\n";
	cout << "Color: "<< obtenerColor() << "\n";
	cout << "Marcha: "<< obtenerMarcha() << endl;
}

void CCoche::arrancarMotor(void){
	if(marcha > 0)
		cout << "El motor ya arranco\n";
	else{
		marcha = 1;
		cout << "Motor arrancado\n";
	}
}

void CCoche::apagarMotor(void){
	if (marcha == 0){
		cout << "El motor ya esta apagado." << endl;
		return;
	}

	if(marcha > 1)
		cout << "Debe estar en 1°" << endl;
	else{
		marcha = 0;
		cout << "Motor apagado" << endl;
	}
}

void CCoche::acelerar(void){
	if(marcha == 0)
		cout << "Necesita arrancar el motor\n";
	else if(marcha >= 5)
		cout << "El motor esta en su marcha maxima\n";
	else{
		marcha++;
		cout << "Marcha: " << obtenerMarcha() << endl;
	}
}

void CCoche::frenar(void){
	if(marcha == 0)
		cout << "El motor se encuentra apagado\n";
	else if (marcha == 1)
		cout << "Debe apagar el motor";
	else{
		marcha--;
		cout << "Marcha: " << obtenerMarcha() << endl;
	}
}

void CCoche::pararMotor(void){
	if(marcha == 0)
		cout << "El motor ya esta parado\n";
	else{
		marcha = 0;
		cout << "Motor frenado." << endl;
	}
}

