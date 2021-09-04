/*
 * CCoche.h
 *
 *  Created on: 19 jul. 2021
 *      Author: simon1
 */

#ifndef CCOCHE_H_
#define CCOCHE_H_

#include <iostream>
#include <string>

using namespace std;

class CCoche{
private:
	string marca;
	string modelo;
	string color;
	unsigned char marcha;

public:
	//Constructores
	CCoche();
	CCoche(string marc, string mod, string col);

	//Interfas de asignacion
	void asignarMarca(string mar);
	void asignarModelo(string mod);
	void asignarColor(string col);
	void asignarMarcha(int mar);

	//Interfaz de estados de atributos
	string obtenerMarca(void);
	string obtenerModelo(void);
	string obtenerColor(void);
	int obtenerMarcha(void);
	void estado(void);

	//Otros metodos
	void arrancarMotor(void);
	void apagarMotor(void);
	void acelerar(void);
	void frenar(void);
	void pararMotor();
};

#endif /* CCOCHE_H_ */
