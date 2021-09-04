	/*
 * Matriz_Dinamica.cpp
 *
 *  Created on: 15 jul. 2021
 *      Author: simon
 */
#include <iostream>
#include <vector>

using namespace std;

struct matriz2d{
	double **p;
	int filas;
	int cols;
};

bool construirMatriz(matriz2d& m);
void leerMatriz(matriz2d& m);
void mostrarMatriz(matriz2d& m);
void destruirMatriz(matriz2d& m);
int crearMenu(const char* opMenu[], int num_opciones);

int main(){
	int opcion = 0;
	static const char* opciones[] =
	{
			"Construir matriz",
			"Leer matriz",
			"Mostrar matriz",
			"Destruir matriz",
			"Finalizar"
	};

	const int num_opciones = sizeof(opciones) / sizeof(char*);

	matriz2d m{nullptr,0,0};

	do{
		system("clear");
		opcion = crearMenu(opciones, num_opciones);

		enum op {Construir = 1, Leer, Mostrar, Destruir, Finalizar};

		switch (opcion){
			case Construir:
				if(m.p != nullptr){
					cout << "Ya existe una matriz. Destruyala para crear otra.\n";
					system("pause");
					break;
				}

				do{
					cout << "N° de filas de la matriz : "; cin >> m.filas;
				}while(m.filas < 1);

				do{
					cout << "N° de columnas de la matriz : "; cin >> m.cols;
				}while(m.cols < 1);

				if(!construirMatriz(m)){
					cout << "No se pudos contruir la matriz. \n";
					return -1;
				}
				cout << "Matriz construida\n";
				system ("pause");
				break;

			case Leer:
				if(m.p == nullptr)
					cout << "No existe la matriz\n";
				else
					leerMatriz(m);
				system ("pause");
				break;

			case Mostrar:
				if(m.p == nullptr)
					cout << "No existe la matriz\n";
				else
					mostrarMatriz(m);
				system("pause");
				break;

			case Destruir:
				if(m.p == nullptr)
					cout << "Matriz Destruida\n";
				else{
					destruirMatriz(m);
					cout << "Matriz Destruida\n";
				}
				system("pause");
				break;

			case Finalizar:
				if (m.p == nullptr)
					destruirMatriz(m);
				break;
		}

	}while (opcion != 5);
}
/*	matriz2d m;
	do{
		cout << "N° de filas de la matriz: ";
		cin >> m.filas;
	}while(m.filas < 1);

	do{
		cout << "N° de columnas de la matriz: ";
		cin >> m.cols;
	}while(m.cols < 1);

	if(!construirMatriz(m)){
		cout << "No se pudo contruir la matriz .\n";
		return -1;
	}

	leerMatriz(m);
	mostrarMatriz(m);
	destruirMatriz(m);
	cout << endl;
	return 0;
}
*/

bool construirMatriz(matriz2d &m){
	m.p = (double**) new (nothrow) double*[m.filas];
	if(m.p == nullptr) return false;	//error

	//Iniciar matriz de punteros
	fill(m.p, m.p + m.filas,nullptr);

	//Construir filas
	for (int f = 0; f < m.filas; ++f){
		m.p[f] = (double *) new (nothrow) double*[m.cols];
		if(m.p[f] == nullptr){ //Error, liberar memoria asignada
			destruirMatriz(m);
			return false;
		}
		//Iniciar la fila a cero
		fill(m.p[f],m.p[f] + m.cols,0);
	}
	return true;
}

void destruirMatriz(matriz2d& m){
	if(m.p == nullptr) return;
	for(size_t f = 0; m.p[f] != nullptr && f < (size_t) m.filas; ++f)
		delete[] m.p[f]; 	//filas
	delete[] m.p;			//Matriz de punteros
	m.p = nullptr;
}

void leerMatriz(matriz2d& m){
	if(m.p == nullptr) return;
	for(size_t f = 0; f < (size_t) m.filas; ++f){
		for(size_t c = 0; c < (size_t) m.cols; ++c){
			cout << "m[" << f << "][" << c << "]:" ;
			cin >> m.p[f][c];
		}
	}
}

void mostrarMatriz(matriz2d& m){
	if(m.p == nullptr) return;
	for(size_t f = 0; f < (size_t) m.filas; ++f){
		for(size_t c = 0; f < (size_t) m.cols; ++c)
			cout << m.p[f][c] << " ";
		cout << endl;
	}
}

int crearMenu(const char* opMenu[], int num_opciones){
	int opcion;
	system("clear");

	//Presentar el menu
	cout << "\nElija una opcion:\n" << endl;
	for(int i = 0 ; i < num_opciones; i++)
		cout << "\t" << i + 1 << ". " << opMenu[i] << endl;

	//Elegir una opcion y verificar que es correcta
	do{
		cout << ">>";
		cin >> opcion;
		if(opcion < 1 || opcion > num_opciones)
			cout << "Opcion incorrecta\n" << endl;
	}while(opcion < 1 || opcion > num_opciones);
	return opcion;
}



