#ifndef CLASE_H
#define CLASE_H
#include "Profesor.h"
struct Clase {
	int idMateria=0;
	string nombreMateria;
	BASEDEDATOS<Profesor> listaProXClase;//Lista de profesores para una misma clase
};
#endif
