#ifndef PROFESOR_H
#define PROFESOR_H
#include "Asignatura.h"

struct Profesor {
		//Datos
		int cedula=0;
		string apellidos;
		string nombres;
		int numTotalClases;
		BASEDEDATOS<Asignatura> listaAsignaturasPro;//De acuerdo a la cantidad de cortes se asigna el valor
		//Corte *cantidadCortes; //corte 1-2-3....n
};
#endif






