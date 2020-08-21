#ifndef TAREA_H
#define TAREA_H
#include "Corte.h"
struct Tema {
	//Datos
	//Codigo de referencia para x asignatura
	int codigoTema;
	string nombreTema;
	int indiceTema; //Tema a tratar por cada asignatura
	Tema *temaSiguiente;
};
#endif
