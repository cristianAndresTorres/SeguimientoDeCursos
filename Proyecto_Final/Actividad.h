#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H
#include "Tarea.h"

struct Actividad {
		//Datos
		string tipoActividad; //(Quiz, Taller, Parcial, proyecto, exposicion).
		int porcentajeAct;
		//Apuntador a la lista de tareas
		Tarea *arregloTareas;
				
};


#endif

