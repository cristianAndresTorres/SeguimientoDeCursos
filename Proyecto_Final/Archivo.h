#ifndef ARCHIVO_H
#define ARCHIVO_H

//Archivos de consolidado de notas por corte
struct Archivo {
		//Datos
		string nombreDelArchivo; 
		string ubicacionDelArchivo;
		
		Archivo *archivoSiguiente;
				
};


#endif
