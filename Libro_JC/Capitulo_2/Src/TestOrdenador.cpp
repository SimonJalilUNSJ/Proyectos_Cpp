/*
 * TestOrdenador.cpp
 *
 *  Created on: 16 jul. 2021
 *      Author: simon
 */

#include "COrdenador.h"

int main(){
	COrdenador miOrdenador;

	miOrdenador.asignarMarca("Dell");
	miOrdenador.asignarPeso(1.5);
	miOrdenador.asignarProcesador("Intel Celeron");

	miOrdenador.pantallaOn();
	miOrdenador.encenderOrdenador();
	miOrdenador.estado();

	miOrdenador.cargarApp();

	miOrdenador.pantallaOff();

	miOrdenador.apagarOrdenador();
	miOrdenador.estado();

	return 0;
}

