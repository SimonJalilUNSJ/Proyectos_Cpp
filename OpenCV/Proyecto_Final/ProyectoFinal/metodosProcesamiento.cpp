/*
 * ContenedorFallaDeTomate.cpp
 *
 *  Created on: 20/06/2019
 *      Author: Simon Jalil y Pablo Pelaez
 */
#include "tomate.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <ctime>

#include <algorithm>
#include <iostream>

using namespace std;

int auxThresh;

Procesamiento::Procesamiento() {

	area = 0.0;
	thresh = 20;
	maxThresh = 255;
	MaxU = 0.0;
	MinU = 0.0;
	thresh1 = 1;
}

int Procesamiento::cargarDatosTomates(){

	int ordenacion;


	cv::FileStorage fs("datosParaCargarTomate.yml", cv::FileStorage::READ);
		if (!fs.isOpened())
		{
			throw( ERR_YML_FILE );
		}


		fs["umbralMax"] >> MaxU;
		fs["umbralMin"] >> MinU;
		fs["thresh1"] >> thresh1;
		fs["Ordenacion"]>> ordenacion;

		return ordenacion;
}


void Procesamiento::TreshCalib() {

	cv::threshold(frame,mask, thresh, maxThresh, cv::THRESH_BINARY);
	imshow("IMAGEN_DE_CALIBRACION", mask);
	auxThresh = thresh;
	float umbralMax(1.2*140000) , umbralMin (0.8*140000);

	cv::FileStorage fs("datosParaCargarTomate.yml", cv::FileStorage::WRITE);

	fs << "umbralMax" << umbralMax;
	fs << "umbralMin" << umbralMin;
	fs<<"threshcalib"<<auxThresh;
	fs << "Ordenacion Fecha Mayor a Menor"<<int(POR_ABERRACION_MAYOR_A_MENOR);
	fs << "Ordenacion Fecha Menor a Mayor"<<int(POR_ABERRACION_MENOR_A_MAYOR);
	fs << "Ordenacion por fecha Mayor a Menor"<<int(POR_FECHA_MAYOR_A_MENOR);
	fs << "Ordenacion por fecha Menor a Mayor"<<int(POR_FECHA_MENOR_A_MAYOR);
	fs << "Ordenacion"<<int(POR_ABERRACION_MAYOR_A_MENOR);
	fs.release();

}

void Procesamiento::onTrackbarThreshCalib(int dato, void *ptr) {
	Procesamiento* adPtr = (Procesamiento*)ptr;
	adPtr->TreshCalib();

}


void Procesamiento::ordenaAreas(vector<float>&areas) {
	float aux;

	for (unsigned int i = 0; i < areas.size(); i++) {
		for (unsigned int j = 0; j < areas.size() - 1; j++) {
			if (areas[j] < areas[j + 1]) {
				aux = areas[j];
				areas[j] = areas[j + 1];
				areas[j + 1] = aux;
			}
		}
	}
}

void Procesamiento::calculoArea(FallaDeTomate &falla) {
	cv::Mat img = frame;
	bool calib;
	float threshcalib;
	vector<vector<cv::Point>> contornos;
	cv::Mat mask,mask_grey;

	//OBTENGO LA FECHA DE PROCESAMIENTO DE LA IMAGEN.
	time_t curr_time,seg_time;
	time(&seg_time);
	curr_time = time(NULL);
	char *tm = ctime(&curr_time);
	cout << "\n\nLa fecha del procesamiento de la imagen es: "<<tm;
	falla.setFecha(seg_time);

	//CALIBRACION (Opcional).
	cout<<"\n\nDesea ajustar el thresh de la imagen? SI/NO: "<<endl;
	cin>>calib;

	if(calib == 0 ){
		threshcalib=85;//VALOR ELEGIDO POR DEFECTO. ESTARA INCLUIDO EN EL MANUAL DE USO.
	}
	if(calib == 1) {
		cv::Mat imgCalib;
		imgCalib = cv::Mat::zeros(img.rows, img.cols, img.type());
		cv::namedWindow("IMAGEN_DE_CALIBRACION", cv::WINDOW_AUTOSIZE);
		cv::createTrackbar("threshCalibracion", "IMAGEN_DE_CALIBRACION", &thresh, maxThresh, Procesamiento::onTrackbarThreshCalib, (void*)this);
		char c = (char)cv::waitKey(0);
		if (c == 'g' || c == 'G') {
			cout<<"\nEl nuevo valor del thresh elegido es: "<<auxThresh<<endl;
			cv::destroyWindow("IMAGEN_DE_CALIBRACION");
			}
		threshcalib= auxThresh;
		}

	//REALIZO LA TRANSFORMACION A IMAGEN BINARIA.
	cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(imgGray, imgGray, cv::Size(3, 3), 1, 1);
	cv::threshold(imgGray,imgBinary,threshcalib,255,cv::THRESH_BINARY);
	
	//ENCUENTRO LOS CONTORNOS
	cv::findContours(imgBinary,contornos,cv::noArray(),cv::RETR_LIST, cv::CHAIN_APPROX_NONE);
	vector<float> areas(contornos.size());

	//DIBUJO LOS CONTORNOS EN LA IMAGEN ORIGINAL.
	cv::drawContours(frame, contornos, -1, cv::Scalar(0, 255, 255), 3);

	//ENCUENTRO EL AREA PARA CADA CONTORNO
	for (unsigned int i = 0; i < contornos.size(); i++) {
		areas[i] = contourArea(contornos[i], false);
	}


	//ORDENO EL VECTOR DE AREAS.
	cout << "\n AREAS ORDENADAS:\n";
	ordenaAreas(areas);

	for (unsigned int i = 0; i < areas.size(); i++) {
			cout << "\nEl Area N: " << i << " es: " << areas[i];
		}

	cout<<"\nEl máximo umbral es: "<<MaxU<<" y el mínimo umbral es:"<<MinU<<"\n";

	//LIMPIO EL OBJETO AREAS.
	falla.limparFalla();


	//SI EL CONTORNO DEL TOMATE CUMPLE CON LOS REQUISITOS DEL UMBRAL, SE ANALIZA LA MISMA, CASO CONTRARIO SE EXIGE OTRA MUESTRA.
	if(MaxU > areas[0] && MinU < areas[0]){

		falla.setAreaTomate(areas[0]);

		//OBSERVO SI LA IMAGEN TIENE PRESCENCIAS DE ABERRACIONES CON OTRO UMBRAL PARA PODER HACER PUSHBACK DE ELLAS.
		for(unsigned int i = 1; i<areas.size(); i++){
			if(areas[i]<9000 && areas[i]>250)
				falla.nuevaAberracion(areas[i]);
		}
		cout << falla;

		//REALIZO EL ENMASCARAMIENTO PARA OBTENER LA ZONA DE TRABAJO.
		mask = cv::Mat::zeros(img.rows, img.cols, img.type());
		zonaTrabajo = cv::Mat::zeros(img.rows, img.cols, img.type());

		cv::threshold(frame, mask, 100, maxThresh, cv::THRESH_BINARY);
		cv::bitwise_and(frame, mask, zonaTrabajo);
		cv::drawContours(mask, contornos, -1, cv::Scalar(0, 255, 255), 2);
		cv::namedWindow("Zona de trabajo", cv::WINDOW_AUTOSIZE);
		cv::imshow("Zona de trabajo", zonaTrabajo);
		cv::waitKey(0);
		cv::destroyWindow("Zona de trabajo");

		area = areas[0];

		cv::waitKey(0);

	}else{

		cout << "\nEl area del tomate es: " << areas[0];
		cout<<"\n\nEl tomate ingresado tiene un area que no corresponde al umbral calibrado. Vuelva a calibrar."<<endl;
		area = 1;
		falla.setAreaTomate(area);
		cv::waitKey(0);

	}
}


void Procesamiento::getResultado() const{
	cv::namedWindow("Resultado Final:",cv::WINDOW_AUTOSIZE);
	cv::imshow("Resultado Final:", frame);
	cv::waitKey(0);
	cv::destroyWindow("Resultado Final:");
}

void Procesamiento::guardaImg(string& path) {
	frame = cv::imread(path);
	if (frame.empty()){
		cout<<"Fallo al cargar la imagen."<<endl;
		exit(1);
	}
}

float Procesamiento::getArea()const{
	return area;
}


fstream& operator>>(fstream &arch,vector<string>& vec){
	string linea;
	while(getline(arch,linea)){
		vec.push_back(linea);
	}
	return arch;
}


void Procesamiento::limpiarProcesamiento(){
	thresh = 20;
	maxThresh = 255;
	area = 0;
}



