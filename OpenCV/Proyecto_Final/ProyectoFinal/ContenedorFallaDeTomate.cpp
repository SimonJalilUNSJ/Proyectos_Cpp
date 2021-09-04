/*
 * ContenedorFallaDeTomate.cpp
 *
 *  Created on: 20/06/2019
 *      Author: Simon Jalil y Pablo Pelaez
 */
#include "tomate.h"

using namespace std;

//SOBRECARGA DEL METODO SORT PARA ORDENAR POR PORCENTAJE TOTAL DE FALLA DEL TOMATE, DE MAYOR A MENOR.
struct SortMayorMenorFalla{

	inline bool operator()(FallaDeTomate& i1,FallaDeTomate& i2){
			return(i1.fallaGeneralTomate() > i2.fallaGeneralTomate());
	}
};

//SOBRECARGA DEL METODO SORT PARA ORDENAR POR PORCENTAJE TOTAL DE FALLA DEL TOMATE, DE MENOR A MAYOR.
struct SortMenorMayorFalla{

	inline bool operator()(FallaDeTomate& i1,FallaDeTomate& i2){
				return(i1.fallaGeneralTomate() < i2.fallaGeneralTomate());
		}
};

//SOBRECARGA DEL METODO SORT PARA ORDENAR POR FECHA. DE LA MAS RECIENTE A LA MENOS RECIENTE.
struct SortMenorMayorFecha{
//Este metodo ordena las llantas por fechas desde la menos reciente a la mas reciente
			inline bool operator()(FallaDeTomate &i1, FallaDeTomate &i2){
				return(i1.fecha < i2.fecha);
			}

};

//SOBRECARGA DEL METODO SORT PARA ORDENAR POR FECHA. DE LA MENOS RECIENTE A LA MAS RECIENTE.
struct SortMayorMenorFecha{
//Este metodo ordena las llantas por fechas desde la mas reciente a la menos reciente
			inline bool operator()(FallaDeTomate  &i1, FallaDeTomate &i2){

			return(i1.fecha>i2.fecha);
			}
};

void ContenedorFallaDeTomate::addFalla(FallaDeTomate &falla){
	contenedor.push_back(falla);
}

void ContenedorFallaDeTomate::ordenar(CriterioOrd& ref){
	switch (ref){
		case POR_ABERRACION_MAYOR_A_MENOR:
				sort(contenedor.begin(),contenedor.end(),SortMayorMenorFalla());
				break;

		case POR_ABERRACION_MENOR_A_MAYOR:
				sort(contenedor.begin(),contenedor.end(),SortMenorMayorFalla());
				break;
		case POR_FECHA_MAYOR_A_MENOR:
				sort(contenedor.begin(),contenedor.end(),SortMayorMenorFecha());
				break;
		case POR_FECHA_MENOR_A_MAYOR:
				sort(contenedor.begin(),contenedor.end(),SortMenorMayorFecha());
				break;
	}
}

void operator<<(ostream& os,ContenedorFallaDeTomate & i1){
	for(unsigned int i = 0; i < i1.contenedor.size(); i++){
		cout<<"\nTomate n°: "<<i+1<<" la totalidad de area dañada es del: %"<<i1.contenedor[i].fallaGeneralTomate();
	}
}


ofstream& operator<<(ofstream& ofs,ContenedorFallaDeTomate &i1)
{

	ofs << "Informe de las caracteristicas de los tomates procesados:\n";

	for(unsigned int i = 0 ; i<i1.contenedor.size() ; i++){
		ofs << "\nEl tomate n: "<<i+1<<" contiene un %"<< i1.contenedor[i].fallaGeneralTomate()<<" de daño en la totalidad del mismo.";
	}
	return ofs;
}
