#ifndef ASIGNATURA_H
#define ASIGNATURA_H
#include "Archivo.h"
struct Asignatura {
	//Datos
	string nombreAsignatura;
	int grupoAsignatura;
	
	Archivo *notasDelCorte;
	
	Asignatura * siguienteAsignatura;//Para el mismo docente
};
#endif
