#ifndef INGRESOACTIVIDADCORTE_H
#define INGRESOACTIVIDADCORTE_H

#include "Corte.h"
#include <conio.h>
#include <iostream>
#include "BASEDEDATOS.h"
#include "IngresoTema.h"
#include <limits>

#include "Tarea.h"


using namespace std;

class IngresoActividadCorte{
	ControladorIngresoTema controladorTema;
	BASEDEDATOS<Corte> listaCortesXse;
	
	public :
		static int IDActividad;
		static int IDCorte;
		static int IDActividadPAQ;
		
		IngresoActividadCorte(){	
		};	
		Corte menuActividades();	
};
int IngresoActividadCorte::IDActividad = 1;
int IngresoActividadCorte::IDCorte=1;
int IngresoActividadCorte::IDActividadPAQ=1;

Corte IngresoActividadCorte::menuActividades(){
	Corte cortePeriodo;
	int opcion;
	int j;
	int porcentaje, repeticionActividad;
	do{
		cout<<endl<<"___________Actividades_________"<<endl;
		cout<<"1. Quiz"<<endl;
		cout<<"2. Taller"<<endl;
		cout<<"3. Parcial"<<endl;
		cout<<"4. Proyecto"<<endl;
		cout<<"5. Exposicion"<<endl;
		cout<<"6. finalizar"<<endl;
		cout<<"Escoja las actividades a realizar por corte : ";
		cin>>opcion;
		if(opcion==1 || opcion==2|| opcion==3|| opcion==4 || opcion==5){
			cout<<"................................................................................................."<<endl;
			cout<<"Ingrese porcentaje total que coresponde al mismo tipo de actividad "<<opcion<<" en el corte : ";
			cin>>porcentaje;
			cout<<"Ingrese el numero total de veces que se realizara la actividad "<<opcion<<" :";
			cin>>repeticionActividad;
			
			Actividad actividad;
			
			actividad.porcentajeAct = porcentaje;
			actividad.claveActividad = IDActividad;
			
			controladorTema.ingresarTemario();
			for(j=0; j<repeticionActividad; j++){
				controladorTema.mostrarTemario();
				//Se agregan tareas a la misma actividad en que este
				actividad.listaTareasXAct.insertar(IDActividad,controladorTema.crearTarea());
				IDActividad++;
			}	
			cortePeriodo.listActDifXCor.insertar(IDActividadPAQ,actividad);
			cortePeriodo.porcentajeCorte = cortePeriodo.porcentajeCorte+porcentaje;
			IDActividadPAQ++;
		}
	}while(opcion!=6);	
	cortePeriodo.claveCorte = IDCorte;
	listaCortesXse.insertar(IDCorte, cortePeriodo);
	IDCorte++;
	
	return cortePeriodo;
}	


#endif
	
