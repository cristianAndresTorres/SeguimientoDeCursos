#ifndef CONTROLADORINGRESODOCENTE_H
#define CONTROLADORINGRESODOCENTE_H
#include "Profesor.h"
#include "IngresoActividadCorte.h";



class ControladorIngresoDocente{
	BASEDEDATOS<Profesor> BDListaProfesores;
	IngresoActividadCorte actividadXCorte;
	
	public :
		static int claveDocente;
		static int claveXCorte;
		//static int claveTema;
		ControladorIngresoDocente(){
		};		
		void menuProfesor();
		void ingresarProfesor();
		void registrarProfesor();
};
int ControladorIngresoDocente::claveDocente = 1;
int ControladorIngresoDocente::claveXCorte  = 1;

void ControladorIngresoDocente::menuProfesor(){
	int opcion;
	do{
		cout<<"__________________Menu Profesor__________________"<<endl;	
		cout<<"1. Ingresar  profesor "<<endl;
		cout<<"2. Registrar profesor "<<endl;
		cout<<"3.              salir "<<endl;
		cout<<"Que desea realizar :";
		cin>>opcion;
	}while(!((opcion==1)||(opcion==2)||(opcion==3)));
	
	switch(opcion) {
		case 1 :
			ingresarProfesor();
			break;
		case 2 :
			registrarProfesor();
			break;	
	default:
		cout<<"Error";
	}
}
void ControladorIngresoDocente::ingresarProfesor(){
	
}	
void ControladorIngresoDocente::registrarProfesor(){
	Profesor profeRegistro;
	int cedula;
	string apellidos;
	string nombres;
	int numTotalClases;
	cout<<"_________________Datos personales_______________"<<endl;
	cout<<"Ingrese el numero de su cedula 				: ";
	cin>>cedula;
	cout<<"Ingrese sus apellidos                  		: ";
	cin>>apellidos;
	cout<<"Ingrese sus nombres                          : ";
	cin>>nombres;
	cout<<"Ingrese el numero total de clases a su cargo : ";
	cin>>numTotalClases;
	
	profeRegistro.cedula = cedula;
	profeRegistro.apellidos = apellidos;
	profeRegistro.nombres = nombres;
	profeRegistro.numTotalClases = numTotalClases;
	//-----------------------------------------------------------------------------------
	profeRegistro.listaCortesXPro.insertar(claveXCorte,actividadXCorte.menuActividades());
	
	
	BDListaProfesores.insertar(claveDocente, profeRegistro);
}		





#endif
