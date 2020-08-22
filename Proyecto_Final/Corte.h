#ifndef CORTE_H
#define CORTE_H
#include "Actividad.h"
struct Corte {
		int claveCorte;
		int numCorte;
		int porcentajeCorte =0;
		//De acuerdo a la cantidad de actividades se asigna el valor
		BASEDEDATOS<Actividad> listActDifXCor; //Actividad 1-2-3....n por corte
};
#endif




