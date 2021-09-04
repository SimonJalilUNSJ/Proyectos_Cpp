/*
 * ContenedorFallaDeTomate.cpp
 *
 *  Created on: 20/06/2019
 *      Author: Simon Jalil y Pablo Pelaez
 */
#ifndef TOMATE_H_
#define TOMATE_H_

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <fstream>

const int ERR_YML_FILE(-1);
using namespace std;

void generaYML();

class FallaDeTomate
{
private:
    time_t fecha;
    float areaTomate;
    vector<float> aberracion;

public:
    void setFecha(time_t&);
    void setAreaTomate(float &);
    void nuevaAberracion(float &); //agrega una nueva aberracion al tomate y retorna la cantidad del template aberraciones.
    unsigned int numFallas() const;
    float fallaGeneralTomate()const;
    void limparFalla();

	//SOBRECARGA DEL OPERADOR SORT QUE ORDENA DE MENOR A MAYOR POR FECHA, DESDE LA FECHA MAS RECIENTE HASTA LA MENOS RECIENTE.
	friend struct SortMenorMayorFecha;
	//SOBRECARGA DEL OPERADOR SORT QUE ORDENA DE MAYOR A MENOR POR FECHA, DESDE LA MENOS RECIENTE HASTA LA MAS RECIENTE.
	friend struct SortMayorMenorFecha;

};

//SOBRECARGA DE OPERADORES DE ENTRADA SALIDA
istream& operator>>(istream& is, FallaDeTomate &);
ostream& operator<< (ostream& os, FallaDeTomate& falla);


class Procesamiento
{
private:
	int thresh;
	int maxThresh;
	float area,MaxU, MinU,thresh1;
	cv::Mat frame, imgGray, imgBinary, zonaTrabajo,mask;

public:
	//CONSTRUCTOR Y DESTRUCTOR.
	Procesamiento();
	~Procesamiento() {};

	//METODO PARA CARGAR LOTE DE IMAGENES.
	int cargarDatosTomates();

	//METODO DONDE SE EJECUTAN LOS TRACKBAR.
	void TreshCalib ();

	//METODO DONDE SE OBTIENE LA IMAGEN ANALIZADA FINAL.
	void getResultado() const;

	//METODOS DE USO DE TRACKBARS
	static void onTrackbarThreshCalib(int, void*);

	//METODOS DE OBTENCION DE AREA POR PASO DE CAMARA, O PASO DE IMAGEN FIJA.
	void calculoArea(FallaDeTomate &);

	//METODO DE ORDENACION
	void ordenaAreas(vector<float>&);

	//METODO PARA GUARDAR IMAGEN EN ARCHIVO JPG A PARTIR DE CAMARA.
	void guardaImg(string&);

	//METODO PARA OBTENER EL AREA DEL TOMATE.
	float getArea() const;

	//METODO PARA LIMPIAR OBJETO
	void limpiarProcesamiento();

};

//SOBRECARGA DEL OPERADOR DE INSERCION DE ENTRADA PARA ARCHIVOS.
fstream& operator>>(fstream &,vector<string>& );

enum CriterioOrd{POR_ABERRACION_MAYOR_A_MENOR = 1,POR_ABERRACION_MENOR_A_MAYOR,POR_FECHA_MAYOR_A_MENOR,POR_FECHA_MENOR_A_MAYOR};

class ContenedorFallaDeTomate{
    vector<FallaDeTomate> contenedor;
public:
    void addFalla(FallaDeTomate &);
    void ordenar(CriterioOrd&);

	//SOBRECARGA DEL OPERADOR SORT QUE ORDENA DE MAYOR A MENOR POR TAMAÑO DE FALLA.
	friend struct SortMayorMenorFalla;
	//SOBRECARGA DEL OPERADOR SORT QUE ORDENA DE MENOR A MAYOR POR TAMAÑO DE FALLA.
	friend struct SortMenorMayorFalla;
	//SOBRECARGA DE OPERADOR DE SALIDA HACIA PANTALLA.
	friend void operator<<(ostream& os,ContenedorFallaDeTomate &);
	//SOBRECARGA DE OPERADOR DE SALIDA HACIA ARCHIVOS.
	friend ofstream& operator<<(ofstream &,ContenedorFallaDeTomate &);

};



#endif /* TOMATE_H_ */

