#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H
#include "BASEDEDATOS.h"
#include "Tarea.h"

struct Actividad {
		int claveActividad;
		//Datos
		//string tipoActividad; //(Quiz, Taller, Parcial, proyecto, exposicion).
		int porcentajeAct;
		//Si ya se realizo o no la actividad
		bool estado;
		//Apuntador a la lista de tareas
		BASEDEDATOS<BASEDEDATOS<Tarea>> listaTareasXAct;
				
};
#endif

