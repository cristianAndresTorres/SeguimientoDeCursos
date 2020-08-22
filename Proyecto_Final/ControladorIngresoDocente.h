#ifndef CONTROLADORINGRESODOCENTE_H
#define CONTROLADORINGRESODOCENTE_H
#include "Profesor.h"
#include "ControladorAsignatura.h"



class ControladorIngresoDocente{
	BASEDEDATOS<Profesor> BDListaProfesores;
	IngresoAsignatura ingresoAsignatura;
	
	
	public :
		static int claveDocente;
		static int claveXCorte;
		//static int claveTema;
		ControladorIngresoDocente(){
		};		
		void menuProfesor();
		void ingresarProfesor();
		void registrarProfesor();
		void menuIngreso(Profesor profeRegistro);
		void ingresaInfoAsig(Profesor profesor);
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
	Profesor profesor;
	int cedula;
	do{
		//----------------------------------------
		//Verificar el usuario
		cout<<"------------Ingreso Docente------------"<<endl;
		cout<<"Ingrese el numero del documento de identificacion : ";
		cin>>cedula;
		//Validacion------------------------------
		profesor = BDListaProfesores.buscar(cedula);
		if(profesor.cedula==0){
			cout<<"Acceso denegado"<<endl;
			menuProfesor();
		}
	}while(profesor.cedula==0);
	cout<<"El usuario "<<profesor.nombres<<" "<<profesor.apellidos<<" "<<" ingreso corectamente =)"<<endl;
	menuIngreso(profesor);
	
	
	
}	
void ControladorIngresoDocente::registrarProfesor(){
	Profesor profeRegistro;
	int cedula;
	string apellidos;
	string nombres;
	int numTotalClases;
	cout<<"----------------Registro Docente----------------"<<endl;
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
	//Insertar un nuevo profesor a la lista de profesores
	BDListaProfesores.insertar(profeRegistro.cedula, profeRegistro);
	claveDocente++;
}

void ControladorIngresoDocente::menuIngreso(Profesor profeRegistro){
	int opcion;
	do{
		cout<<"_______________Menu ingreso_______________"<<endl;
		cout<<"1. Consultar informacion   "<<endl;
		cout<<"2. Modificar informacion   "<<endl;
		cout<<"3. Ingresar informacion de una materia"<<endl;
		cout<<"4. Enviar archivo por corte"<<endl;
		cout<<"5. Salir"<<endl;	
		cout<<"Ingrese la opcion : ";
		cin>>opcion;
	}while(!((opcion==1)||(opcion==2)||(opcion==3)||(opcion==4))||(opcion==5));
	
	switch(opcion) {
		case 1:
			break;
		case 2:
			break;
		case 3:
				ingresaInfoAsig(profeRegistro);
			break;	
		case 4:
			break;			
		default:
			cout<<"Error"<<endl;
	}

}		

void ControladorIngresoDocente::ingresaInfoAsig(Profesor profesor){
	ingresoAsignatura.menuAsignatura(profesor);
	/*
	Asignatura a = profesor.listaAsignaturasPro.buscar(10);
	cout<<"Hola estrellita "<<endl;
	cout<<a.nombreAsignatura;*/
}

#endif
