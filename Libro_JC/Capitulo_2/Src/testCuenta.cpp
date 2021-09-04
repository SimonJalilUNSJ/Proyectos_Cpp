/*
 * test.cpp
 *
 *  Created on: 16 jul. 2021
 *      Author: simon
 */

#include "cuenta.h"

using namespace std;

int main(){
	CCuenta cuenta01;
	CCuentaDeAhorro cuenta02("Un nombre", "Una cuenta", 6000, 3.5, 2);



	cuenta01.asignarNombre("Daniel");
	cuenta01.asignarCuenta("123451");
	cuenta01.asignarTipoDeInteres(2.5);

	cuenta01.ingreso(12000);
	cuenta01.reintegro(3000);

	cout << cuenta01.obtenerNombre() << "\n";
	cout << cuenta01.obtenerCuenta() << "\n";
	cout << cuenta01.obtenerSaldo() << "\n";
	cout << cuenta01.obtenerTipoDeInteres() << "\n";
	cout << endl;


	//Cobrar cuota de mantenimiento

	cuenta02.reintegro(cuenta02.obtenerCuotaManten());
	//Ingreso
	cuenta02.ingreso(6000);
	//Reintegro
	cuenta02.reintegro(10000);

	cout << cuenta02.obtenerNombre() << "\n";
	cout << cuenta02.obtenerCuenta() << "\n";
	cout << cuenta02.obtenerSaldo() << "\n";
	cout << cuenta02.obtenerTipoDeInteres() << "\n";
	cout << endl;

	return 0;
}


