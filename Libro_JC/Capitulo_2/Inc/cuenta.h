/*
 * cuenta.h
 *
 *  Created on: 16 jul. 2021
 *      Author: simon
 */

#ifndef CUENTA_H_
#define CUENTA_H_

#include <iostream>
 #include <string>

using namespace std;

class CCuenta{
	private:
			string nombre;
			string cuenta;
			double saldo;
			double tipoDeInteres;

	public:
			CCuenta();
			CCuenta(string nom, string cue, double sal, double tipo);
			void asignarNombre(string nom);
			string obtenerNombre();
			void asignarCuenta(string cue);
			string obtenerCuenta();
			double obtenerSaldo();
			void ingreso(double cantidad);
			void reintegro(double cantidad);
			void asignarTipoDeInteres(double tipo);
			double obtenerTipoDeInteres();
};

class CCuentaDeAhorro : public CCuenta{
	//Atributos
	private:
			double cuotaMantenimiento;

	//Metodos
	public:
			CCuentaDeAhorro();
			CCuentaDeAhorro(string nom, string cue, double sal,
							double tipo, double mant);
			void asignarCuotaMantenimiento(double cantidad);
			double obtenerCuotaManten();
			void reintegro(double cantidad);
};


#endif /* CUENTA_H_ */
