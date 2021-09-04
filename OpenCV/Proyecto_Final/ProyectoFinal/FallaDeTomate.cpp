/*
 * ContenedorFallaDeTomate.cpp
 *
 *  Created on: 20/06/2019
 *      Author: Simon Jalil y Pablo Pelaez
 */
#include "tomate.h"

using namespace std;

void FallaDeTomate::setFecha(time_t&currentDate){
	fecha = currentDate;
	cout <<"\nSon los segundos "<<currentDate;
}

void FallaDeTomate::setAreaTomate(float &area){
	areaTomate = area;
}

void FallaDeTomate::nuevaAberracion(float &area){
	aberracion.push_back(area);
	cout<<"\n\nEl porcentaje de aberracion encontrada respecto al area del tomate es del %"<<(area*100)/areaTomate;
}

unsigned int FallaDeTomate::numFallas() const{
	return aberracion.size();
}

float FallaDeTomate::fallaGeneralTomate()const{
	float sumArea = 0.0;
	for(unsigned int i = 0 ; i<aberracion.size() ; i++){
		sumArea += aberracion[i];
	}
	return (sumArea*100)/areaTomate;
}


void FallaDeTomate::limparFalla(){
	areaTomate = 0.0;
	aberracion.clear();
}

istream& operator>>(istream& is, FallaDeTomate& falla){

	float aux;
	is >>  aux;
	falla.nuevaAberracion(aux);
	return is;
}

ostream& operator<< (ostream& os, FallaDeTomate& falla)
{
	os <<"\nLa cantidad de fallas presente en el tomate son: "<<falla.numFallas()<<" siendo el porcentaje de fallas en el tomate de: %"<<falla.fallaGeneralTomate();
	return os;
}



