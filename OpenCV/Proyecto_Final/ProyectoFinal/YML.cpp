/*
 * ContenedorFallaDeTomate.cpp
 *
 *  Created on: 20/06/2019
 *      Author: Simon Jalil y Pablo Pelaez
 */

#include "tomate.h"

using namespace std;


void generaYML(){

	float umbralMax(1.2*140000) , umbralMin (0.8*140000);
	int thresh1 = 85;

	cv::FileStorage fs("datosParaCargarTomate.yml", cv::FileStorage::WRITE);

	fs << "umbralMax" << umbralMax;
	fs << "umbralMin" << umbralMin;
	fs << "thresh1" << thresh1;
	fs << "Ordenacion Fecha Mayor a Menor"<<int(POR_ABERRACION_MAYOR_A_MENOR);
	fs << "Ordenacion Fecha Menor a Mayor"<<int(POR_ABERRACION_MENOR_A_MAYOR);
	fs << "Ordenacion por fecha Mayor a Menor"<<int(POR_FECHA_MAYOR_A_MENOR);
	fs << "Ordenacion por fecha Menor a Mayor"<<int(POR_FECHA_MENOR_A_MAYOR);
	fs << "Ordenacion"<<int(POR_ABERRACION_MAYOR_A_MENOR);
	fs.release();

}


