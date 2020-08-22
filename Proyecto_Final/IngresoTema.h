//--------------------------------------------------
#ifndef INGRESOTEMA_H
#define INGRESOTEMA_H

#include "Tema.h"
#include "Tarea.h"
#include "Corte.h"
#include <conio.h>
#include "BASEDEDATOS.h"
#include <limits>

using namespace std;

//Controlador ingreso Temas
class ControladorIngresoTema{
	BASEDEDATOS<Tema> bdTemas;
	public :
		static int claveTema;
		static int claveTarea;
		//static int claveTema;
		ControladorIngresoTema(){
		};		
		void ingresarTemario(void);
		void mostrarTemario();
		BASEDEDATOS<Tarea> crearTarea();
		BASEDEDATOS<Tarea> asignarPuntosTarea();
		BASEDEDATOS<Tarea> asignarUnicoPTarea();
};
int ControladorIngresoTema::claveTema = 1;
int ControladorIngresoTema::claveTarea = 1;

//---------------------------------------------------
void  ControladorIngresoTema::ingresarTemario(void){
	Tema tema;
	
	int cantidadTemas;
	int indiceTema;
	string nombreTema;
	cout<<endl<<"___________________Temas_____________________"<<endl;
	cout<<endl<<"Ingrese la cantidad de temas : ";
	cin>>cantidadTemas;
	cout<<endl;
	for(int i=0; i<cantidadTemas; i++){
		cout<<"Tema "<<(i+1)<<endl;
		cout<<"Ingrese el nombre del tema : ";
		cin>>nombreTema;
		cout<<"Ingrese el indice del tema : ";
		cin>>indiceTema;
		//----------------------------------
		tema.nombreTema = nombreTema;
		tema.indiceTema = indiceTema;
		tema.codigoTema = claveTema;
		//----------------------------------
		bdTemas.insertar(tema.codigoTema, tema);
		claveTema++;
	}
}
//---------------------------------------------------
void  ControladorIngresoTema::mostrarTemario(){
	Tema tema;
	//obtiene la clave del primer tema
	int primerClaveTema = bdTemas.primero()->clave;
	cout<<endl<<"___________________Mostrando Temario_____________________"<<endl;
	while(primerClaveTema!=std::numeric_limits<int>::max()){
		tema = bdTemas.buscar(primerClaveTema);
		cout<<"Clave         :"<<tema.codigoTema;
		cout<<endl<<"Nombre tema   :"<<tema.nombreTema;
		cout<<endl<<"Indice        :"<<tema.indiceTema;
		primerClaveTema=bdTemas.nodoSiguiente(primerClaveTema)->clave;
		cout<<endl;
		cout<<"----------------------------"<<endl;
	}
}
//---------------------------------------------------------------
BASEDEDATOS<Tarea> ControladorIngresoTema::crearTarea(){
	int opcion;
	do{	
		cout<<endl<<"________________Asignar Tarea/s a la actividad________________"<<endl;
		cout<<"Opciones para asignar tareas :"<<endl;
		cout<<"1) Unica tarea por la actividad "<<endl;
		cout<<"2) Mas de una tarea por la actividad "<<endl;
		cout<<"Ingrese la opcion : ";
		cin>>opcion;
	}while(!((opcion==1)||(opcion==2)));
 cout<<"----------------------------"<<endl;
	switch(opcion){
		case 1 :
				return asignarUnicoPTarea();
			break;
		case 2 :
				return asignarPuntosTarea();
			break;	
		default:
			cout<<"Error";
	}
}

BASEDEDATOS<Tarea> ControladorIngresoTema::asignarUnicoPTarea(){
	BASEDEDATOS<Tarea> listaTarea;
	Tema auxTema;
	int codigoTema,cantTareas;
	Tarea tarea;
	
	cout<<"Tarea por valor de 100"<<endl;
	cout<<"Ingrese el codigo del tema : ";
	cin>>codigoTema;
	
	auxTema = bdTemas.buscar(codigoTema);
	if(auxTema.codigoTema==0){
		cout<<endl<<"No existe ese tema";
	}else{
		tarea.nombreTema =  auxTema.nombreTema;
		tarea.codigoTema = auxTema.codigoTema;
		tarea.claveTarea = claveTarea;
		tarea.porcentaje = 100;
		claveTarea++;
		cout<<endl<<"Se ingreso correctamente la Tarea"<<endl;
		cout<<tarea.nombreTema<<endl;
		cout<<tarea.codigoTema<<endl;
		cout<<tarea.claveTarea<<endl;
		cout<<tarea.porcentaje<<endl;
		listaTarea.insertar(tarea.claveTarea,tarea);
		return listaTarea;	
	}
}

BASEDEDATOS<Tarea>  ControladorIngresoTema::asignarPuntosTarea(){
	int claveTema, cantTareas;
	int porcentajePunto,codigoTema;
	Tema auxTema;
	Tarea auxTarea;
	
	BASEDEDATOS<Tarea> listaTarea;
	
	cout<<"Ingrese la cantidad de puntos a realizar por la tarea : ";
	cin>>cantTareas;
	//Se agregan cantidad de puntos a la tarea 
	for(int j=0; j<cantTareas; j++){
		 cout<<"Ingrese el codigo del tema : ";
		 cin>>codigoTema;
		 //-------------------------------------------------------
		 auxTema = bdTemas.buscar(codigoTema);
		if(auxTema.codigoTema==0){
			cout<<endl<<"No existe ese tema";
		}else{
			cout<<"Ingrese el valor del porcentaje para el punto "<<j+1<<" de la actividad :";
			cin>>porcentajePunto;
			
			auxTarea.nombreTema =  auxTema.nombreTema;
			auxTarea.codigoTema = auxTema.codigoTema;
			auxTarea.claveTarea = claveTarea;
			auxTarea.porcentaje = porcentajePunto;
			claveTarea++;
			cout<<endl<<"Se ingreso correctamente el punto de la Tarea"<<endl;	
			//-------------------------------------------------------
			listaTarea.insertar(auxTarea.claveTarea, auxTarea);
			auxTarea = 	listaTarea.buscar(auxTarea.claveTarea);
			cout<<auxTarea.nombreTema<<endl;
			cout<<auxTarea.codigoTema<<endl;
			cout<<auxTarea.claveTarea<<endl;
			cout<<auxTarea.porcentaje<<endl;
		}
	}
	return listaTarea;	
}
//-------------------------------------------------------------------------------
#endif
