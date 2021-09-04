/*
 * cuenta.cpp
 *
 *  Created on: 16 jul. 2021
 *      Author: simon
 */

#include "cuenta.h"

CCuenta::CCuenta(){
	saldo = 0;
	tipoDeInteres = 0;
}

CCuenta::CCuenta(string nom, string cue, double sal, double tipo){
	asignarNombre(nom);
	asignarCuenta(cue);
	saldo = 0;
	ingreso(sal);
	asignarTipoDeInteres(tipo);
}

void CCuenta::asignarNombre(string nom){
	if(nom.length() == 0){
		cout << "Error: cadena vacia\n";
		return;
	}
	nombre = nom;
}

string CCuenta::obtenerNombre(){
	return nombre;
}

void CCuenta::asignarCuenta(string cue){
	if(cue.length() == 0){
		cout << "Error: cadena vacia\n";
		return;
	}
	cuenta = cue;
}

string CCuenta::obtenerCuenta(){
	return cuenta;
}

double CCuenta::obtenerSaldo(){
	return saldo;
}

void CCuenta::ingreso(double cantidad){
	if(cantidad < 0){
		cout << "Error: cantidad negativa\n";
		return;
	}
	saldo = saldo + cantidad;
}

void CCuenta::reintegro(double cantidad){
	if (saldo - cantidad < 0){
		cout << "Error : no dispone de saldo\n";
		return;
	}
	saldo = saldo - cantidad;
}

void CCuenta::asignarTipoDeInteres(double tipo){
	if(tipo < 0){
		cout << "Error: tipo de interes no valido\n";
		return;
	}
	tipoDeInteres = tipo;
}

double CCuenta::obtenerTipoDeInteres(){
	return tipoDeInteres;
}

CCuentaDeAhorro::CCuentaDeAhorro(){
	cuotaMantenimiento = 0;
}

CCuentaDeAhorro::CCuentaDeAhorro(string nom, string cue, double sal,
		double tipo, double mant) : CCuenta(nom, cue, sal, tipo){
	asignarCuotaMantenimiento(mant);
}

void CCuentaDeAhorro::asignarCuotaMantenimiento(double cantidad){
	if(cantidad < 0){
		cout << "Error: cantidad negativa\n";
		return;
	}
	cuotaMantenimiento = cantidad;
}

double CCuentaDeAhorro::obtenerCuotaManten(){
	return cuotaMantenimiento;
}

void CCuentaDeAhorro::reintegro(double cantidad){
	double saldo = obtenerSaldo();
	double tipoDeInteres = obtenerTipoDeInteres();

	if(tipoDeInteres >= 3.5){
		if(saldo - cantidad < 1500){
			cout << "Error: no dispone de esa cantidad\n";
			return;
		}
		//Invocar al metodo reintegro de la clase base,
		//tambien llamada superclase
		CCuenta::reintegro(cantidad);
	}
}



