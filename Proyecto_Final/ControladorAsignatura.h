//--------------------------------------------------
#ifndef CONTROLADORASIGNATURA_H
#define CONTROLADORASIGNATURA_H
#include "IngresoActividadCorte.h"
#include "Asignatura.h"
#include "Profesor.h"

class IngresoAsignatura{
	public :
		//static int claveTema;
		IngresoAsignatura(){
		};	
		void menuAsignatura(Profesor profesor);	
		void ingresarInfoAsignatura(Profesor profesor);
		void actualizarInfoXAsignatura(Profesor profesor);
};

void IngresoAsignatura::menuAsignatura(Profesor profesor){
	int opcion;
	do{
	
		cout<<endl<<"_________________Menu asignatura_________________"<<endl;
		cout<<"1. Ingresar informacion de la Asignatura."<<endl;
		cout<<"2. Actualizar informacion de la Asignatura"<<endl;
		cout<<"3. Salir."<<endl;
		cout<<"Ingreso la opcion : ";
		cin>>opcion;
	}while(!((opcion==1)||(opcion==2)||(opcion==3)));
	//------------------------------------------------------
	switch(opcion) {
		case 1:
			ingresarInfoAsignatura(profesor);
			break;
		case 2:
			actualizarInfoXAsignatura(profesor);
			break;	
	default:
		cout<<"Error";
	}
}
void IngresoAsignatura::ingresarInfoAsignatura(Profesor profesor){
	int cantidadCorte; 
	string nombreAsignatura;
	int grupoAsignatura;
	Asignatura asignatura;
	int opcion;
	
	cout<<"Ingrese el nombre de la asignatura : ";
	cin>>nombreAsignatura;
	cout<<"Ingrese el codigo de la asignatura : ";
	cin>>grupoAsignatura;
	cout<<endl<<"Cuantos cortes va a tener la materia : ";
	cin>>cantidadCorte;
	//-----------------------------------
	asignatura.nombreAsignatura = nombreAsignatura;
	asignatura.grupoAsignatura = grupoAsignatura;
	asignatura.cantidadCorte = cantidadCorte;
	//-----------------------------------
	do{
		cout<<"Desea ingresar la informacion de cada corte : "<<endl;
		cout<<"1. Si\n2. No\n";
		cout<<"Ingrese la opcion : ";
		cin>>opcion;
	}while(!((opcion==1)||(opcion==2)));
	//---------------------------------------------------
	
	if(opcion==1){
		IngresoActividadCorte ingresoXCorte;
		for(int j=0; j<cantidadCorte; j++){
			Corte corte= ingresoXCorte.menuActividades();
			asignatura.listaCortesXAsig.insertar(corte.claveCorte,corte);
		}
	}else{
		cout<<"Error";
	}
	profesor.listaAsignaturasPro.insertar(asignatura.grupoAsignatura, asignatura);	
}
	
void IngresoAsignatura::actualizarInfoXAsignatura(Profesor profesor){
	int grupoAsignatura;
	cout<<"Ingrese el codigo de la asignatura : ";
	cin>>grupoAsignatura;
	//-----------------------------------------------
	//Verificar que exita la materia y del mismo profesor
	//-----------------------------------------------
}


#endif
