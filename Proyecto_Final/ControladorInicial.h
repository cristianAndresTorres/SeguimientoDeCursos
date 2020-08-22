#ifndef CONTROLADORINICIAL_H
#define CONTROLADORINICIAL_H
#include "Clase.h"
#include "BASEDEDATOS.h"
#include "ControladorIngresoDocente.h"
class ControladorInicial{
	BASEDEDATOS<Clase> bdMaterias;
	ControladorIngresoDocente docente;
	public :
		static int claveClase;
		ControladorInicial(){
		};	
		void menuInicial();
		void menuAdministrador();
		void menuProfesor();
		void funcionesAdminitrador();
		void agregarMaterias();
};

int ControladorInicial::claveClase = 1;
//----------------------------------------------------
void ControladorInicial::menuInicial(){
	int opcion;
	do{
		cout<<"___________Login______________"<<endl;
		cout<<"1. Administrador"<<endl;
		cout<<"2. Profesor"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"Ingrese la opcion : ";
		cin>>opcion;
	}while(!((opcion==1)||(opcion==2)||(opcion==3)));	
	cout<<endl;
	switch(opcion) {
		case 1:
			menuAdministrador();
			break;
		case 2:
			menuProfesor();
			break;		
		default:
			cout<<"Error";
	}
}
//--------------------------------------------------------------------------
void ControladorInicial::menuAdministrador(){
	int clave;
	cout<<"________________Administrador________________"<<endl;
	cout<<"Ingrese la clave : ";
	cin>>clave;
	if(clave==123){
		cout<<"Ingreso correctamente"<<endl;
		funcionesAdminitrador();
	}else{
		cout<<"Clave incorrecta"<<endl;
		menuInicial();
	}
	
}

void ControladorInicial::funcionesAdminitrador(){
	int opcion;
	do{
		cout<<"-------------------------------------"<<endl;
		cout<<"¿Que desea realizar?"<<endl;
		cout<<"1. Consultar"<<endl;
		cout<<"2. Ingresar asignaturas"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"Ingrese la opcion : ";
		cin>>opcion;
	}while(!((opcion==1)||(opcion==2)||(opcion==3)));
	
	switch(opcion) {
		case 1:
			break;
		case 2:
			agregarMaterias();
			break;		
		default:
			cout<<"Error";
	}	
}
void ControladorInicial::agregarMaterias(){
	Clase clase;
	string nombreMateria;
	int identificadorMaT;
	int opcion;
	do{
		cout<<"Ingrese el nombre de la Materia                    : ";
		cin>>nombreMateria;
		cout<<"Ingrese el identificador de acceso para la Materia : ";
		cin>>identificadorMaT;

		//Se agrega a la lista
		clase = bdMaterias.buscar(identificadorMaT);
		if(clase.idMateria==0){
			cout<<"Se ingreso correctamente "<<endl;
			clase.idMateria = identificadorMaT;
			clase.nombreMateria = nombreMateria;
			bdMaterias.insertar(clase.idMateria, clase);
			//Verificacion si se inserto en la base de datos.
			clase = bdMaterias.buscar(clase.idMateria);
			cout<<"Datos materia ingresada : "<<endl;
			cout<<clase.nombreMateria<<endl;
			cout<<clase.idMateria<<endl;
		}else{
			cout<<"Ya existe"<<endl;
		}
		//------------------------------------------
		cout<<"................................................"<<endl;
		cout<<"Desea ingresar otra Materia SI(1)/NO(2) : ";
		cin>>opcion;
	}while(opcion==1);
}
//--------------------------------------------------------------------------

void ControladorInicial::menuProfesor(){
	docente.menuProfesor();
}
#endif
