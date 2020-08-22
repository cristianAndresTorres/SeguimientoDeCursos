#include <iostream>
#include <limits>
#include "IngresoTema.h"
#include "IngresoActividadCorte.h"
#include "ControladorAsignatura.h"
#include "ControladorIngresoDocente.h"
#include "ControladorInicial.h"

using namespace std;
int main(int argc, char** argv) {
	
	int imax = std::numeric_limits<int>::max();
	cout<<imax;
	
	string hola;
	
	/*ControladorIngresoTema p;
	p.ingresarTemario();
	p.mostrarTemario();
	p.crearTarea();*/
	/*IngresoActividadCorte p;
	p.menuActividades();*/
	/*	
	IngresoAsignatura a;
	a.ingresarInfoDelCorte();*/
	
	/*ControladorIngresoDocente doc;
	doc.menuProfesor();*/
	ControladorInicial c;
	c.menuInicial();
	
	
	
	return 0;
}
