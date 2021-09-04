/*
 * ContenedorFallaDeTomate.cpp
 *
 *  Created on: 20/06/2019
 *      Author: Simon Jalil y Pablo Pelaez
 */
#include "tomate.h"

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;

int main(int argc,char**argv) {
	//SI NECESITAMOS GENERAR EL ARCHIVO YML POR PRIMERA VEZ, SE DEBE DESCOMENTAR LAS SIGUIENTES DOS LINEAS.
	generaYML();
	return 1;

	//CREO OBJETOS PARA:
	Procesamiento proc;
	ContenedorFallaDeTomate contenedor;
	FallaDeTomate falla;

	//VECTOR PARA ALMACENAR LOS PATHS.
	vector <string> paths;
	int ordenacion;

	//METODO DE ORDENACION OBTENIDO DEL YML.
	ordenacion = proc.cargarDatosTomates();

	CriterioOrd criterio = CriterioOrd(ordenacion);

	//ABRO EL ARCHIVO CONTENEDOR DE PATHS DE IMAGENES.
	fstream arch;
	arch.open("UbicacionDeImagenes.txt");
	if(arch.fail()){
		cout<<"Error al abrir el archivo de texto."<<endl;
		return -1;
	}

	//ALMACENO EN EL VECTOR DE STRINGS LOS PATHS DE LAS IMAGENES A ANALIZAR.
	arch >> paths;


	for(unsigned int i = 0 ;i<paths.size(); i++ ){
		proc.limpiarProcesamiento();
		proc.guardaImg(paths[i]);
		proc.calculoArea(falla);
		proc.getResultado();
		contenedor.addFalla(falla);
	}

	cout << contenedor;

	contenedor.ordenar(criterio);
	cout << contenedor;

	//GUARDAMOS LOS RESULTADOS DEL CONTENEDOR EN ARCHIVO.
	ofstream informe;
	informe.open("INFORME");
	if(informe.fail()){
		informe.close();
		cout<<"\nError al abrir el archivo de informe."<<std::endl;
		return 1;
	}

	informe << contenedor;


	//REVISAR const!!!
}
