/*
 * COrdenador.h
 *
 *  Created on: 16 jul. 2021
 *      Author: simon
 */

#ifndef CORDENADOR_H_
#define CORDENADOR_H_

#include <iostream>
#include <string>

using namespace std;

class COrdenador{
private:
	string marca;
	string procesador;
	float peso;
	bool encendido;
	bool pantalla;

public:
	COrdenador();
	void encenderOrdenador();
	void apagarOrdenador();
	void pantallaOff();
	void pantallaOn();
	void cargarApp();
	void estado();
	string obtenerMarca();
	void asignarMarca(string mar);
	void asignarProcesador(string pro);
	void asignarPeso(float pes);

};



#endif /* CORDENADOR_H_ */
