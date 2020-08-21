#ifndef TAREA_H
#define TAREA_H
#include "Corte.h"
struct Tarea {
	//Datos
	int porcentaje;
	int codigoTema;
	string tipoTema;
	
	Tarea *pareja;//Siguiente tarea
};


#endif
