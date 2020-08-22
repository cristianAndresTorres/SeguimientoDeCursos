#ifndef PROFESOR_H
#define PROFESOR_H
#include "Corte.h"
struct Profesor {
		//Datos
		int cedula;
		string apellidos;
		string nombres;
		int numTotalClases;
		BASEDEDATOS<Corte> listaCortesXPro;//De acuerdo a la cantidad de cortes se asigna el valor
		//Corte *cantidadCortes; //corte 1-2-3....n
};
#endif






