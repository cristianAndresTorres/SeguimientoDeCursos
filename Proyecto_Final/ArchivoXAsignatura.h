#ifndef ARCHIVOXASIGNATURA_H
#define ARCHIVOXASIGNATURA_H
#include "Archivo.h"

class IngresoArchivoXCorte{
	public :
		static int claveArchivo;
		IngresoArchivoXCorte(){
		};	
		void menuArchivoxCorte();
		archivo ingresarArchivoDelCorte();
		void actualizarInfoXArchivo();
			
};

int IngresoArchivoXCorte::claveArchivo = 1;
//----------------------------------------------------
Archivo IngresoArchivoXCorte::menuArchivoxCorte(){
	int opcion;
	do{
	
		cout<<endl<<"_________________Menu Archivo_________________"<<endl;
		cout<<"1. Ingresar informacion del archivo."<<endl;
		cout<<"2. Actualizar informacion del  archivo."<<endl;
		cout<<"3. Salir."<<endl;
	}while(!((opcion==1)||(opcion==2)||(opcion==3)));
	
	switch(opcion) {
		case 1:
			return ingresarArchivoDelCorte();
			break;
		case 2:
			actualizarInfoXArchivo();
			break;	
	default:
		cout<<"Error";
	}
}

Archivo IngresoArchivoXCorte::ingresarArchivoDelCorte(){
	Archivo archivo;
	
	string nombreDelArchivo;
	int opcion;
	
	cout<<"Ingrese el nombre del archivo : ";
	cin>>nombreDelArchivo;
	
	do{
		cout<<"Ingrese la extension del archivo :"<<endl;
		cout<<"1) .txt"<<endl;
		cout<<"2) .bin"<<endl;
		cout<<"Ingrese la opcion :";
		cin>>opcion;
	}while(!((opcion==1)||(opcion==2)));
	
	switch(opcion) {
		case 1:
			archivo.extensionArchivo = ".txt";
			break;
		case 2:
			archivo.extensionArchivo = ".bin";
			break;	 
	default:		
		cout<<"Error";
	}
	archivo.nombreDelArchivo = nombreDelArchivo;
	archivo.claveArchivo = claveArchivo;
		
	claveArchivo++;
	//--------------------------------------------
	//ubicacion
	//---------------------------------------------
	
	return archivo;
}

void IngresoArchivoXCorte::actualizarInfoXArchivo(){
	cout<<"ACtualizar archivos";
}






#endif
