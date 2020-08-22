#ifndef ASIGNATURA_H
#define ASIGNATURA_H
#include "Archivo.h"
struct Asignatura {
	//Datos
	string nombreAsignatura;
	int grupoAsignatura;
	int cantidadCorte;
	
	Archivo *notasDelCorte;
	
	BASEDEDATOS<Corte> listaCortesXAsig;//Para el mismo docente
	
};
#endif
