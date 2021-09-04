/*
 * fecha.h
 *
 *  Created on: 2 sep. 2021
 *      Author: simon
 */

#ifndef FECHA_H_
#define FECHA_H_

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Cfecha{
	//Atributos
private:
	int dia, mes , anyo;
	//Metodos
protected:
	bool anyoBisiesto(int aaaa) const;
	bool fechaValida(int dia, int  mm, int aaaa) const;
public:
	/*Ejemplo perfecto para usar prototipos con argumentos preestablecidos
	bool asignarFecha(void);
	bool asignarFecha(int dd);
	bool asignarFecha(int dd, int mm);
	*/
	Cfecha(int dd = 1, int mm = 1, int aaaa = 2001);
	~Cfecha(){};
	bool asignarFecha(int dd = 0, int mm = 0, int aaaa = 0);
	void obtenerFecha(int& dd, int& mm, int& aaaa) const;
};




#endif /* FECHA_H_ */
