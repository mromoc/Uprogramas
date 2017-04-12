#ifndef stdio_h
#include <stdio.h>
#define stdio_h
#endif

#ifndef stdlib_h
#include <stdlib.h>
#define stdio_h
#endif

#ifndef lista_h
#include "Lista.h"
#define lista_h
#endif

#ifndef Archivo_h
#include "Archivo.h"
#define Archivo_h
#endif

#ifndef Ordenamiento_h
#include "Ordenamiento.h"
#define Ordenamiento_h
#endif

int main()
{
	int *A;
	A=malloc(sizeof(int));
	FILE *archivo=crear();
	pLista *L=Iniclista();
	AgregarInicio(L,9);
	AgregarInicio(L,8);
	AgregarInicio(L,7);
	AgregarInicio(L,6);
	AgregarInicio(L,4);
	AgregarInicio(L,1);
	Imprimir(L);
	ConvertirArreglo(L,A);
	Ordenamiento (A, 0, L->longitud-1);	
	printf("Arreglo Ordenado\n\n\n");
	MostrarArreglo(L,A);
	AgregarInicio(L,0);
	AgregarInicio(L,11);
	AgregarInicio(L,65);
	AgregarInicio(L,122);
	AgregarInicio(L,41);
	AgregarInicio(L,16);
	Imprimir(L);
	ConvertirArreglo(L,A);
	Ordenamiento (A, 0, L->longitud-1);	
	MostrarArreglo(L,A);
}

