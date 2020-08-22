#ifndef CLASE_H
#define CLASE_H
#include "Asignatura.h"
struct Clase {
	//Datos
	//Ambos datos se recuperan de la estructura profesor
	int cedulaProfesor;
	int cantidadClasesDocente;
	Asignatura *grupoAsignatura; //Del mismo profesor
	Clase *claseSiguiente; //De otro profesor
};
#endif
