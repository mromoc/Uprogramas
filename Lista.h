#ifndef stdio_h
#include <stdio.h>
#define stdio_h
#endif

#ifndef stdlib_h
#include <stdlib.h>
#define stdio_h
#endif

typedef struct Nodo
{
	int inf;
	struct Nodo *anterior,*siguiente;
}pNodo;

typedef struct Lista
{
	int longitud;
	pNodo *primero,*ventana,*ultimo;
}pLista;

pLista *Iniclista()
{
	pLista *L;
	L =malloc(sizeof(pLista));
	L->longitud = 0;
	L->primero = L->ventana = L->ultimo = NULL;
	return (L);
}


int AgregarInicio(pLista *L, int numero)
{
	pNodo *nuevo;
	nuevo=malloc(sizeof(pNodo)); /*Pedir memoria*/
	nuevo->inf = numero;
	nuevo->anterior = nuevo->siguiente = NULL;	
	L->ventana=L->ultimo;
	if(L->longitud==0)
	{
		L->ventana=L->ultimo=L->primero=nuevo;
	}
	else
	{
		L->ventana->siguiente=L->ultimo=nuevo;
		nuevo->anterior=L->ventana;
	}
	L->ventana=nuevo;
	L->longitud++;
	
}

int Imprimir(pLista *L)
{
	int i=1;
	L->ventana=L->primero;
	if(L->longitud == 0){printf("Error no hay lista \n\n");}
	else
	{
		printf("LISTA:");
		while (i<=L->longitud)
		{
			printf("| %i ",L->ventana->inf);
			L->ventana=L->ventana->siguiente;
			i++;	
		}	
		printf("|\n\n");
	}
	printf("Longitud: %i \n",L->longitud);
}

void ConvertirArreglo(pLista *L,int A[])
{
	int i;
	i=0;
	L->ventana=L->primero;
	while (i<L->longitud)
	{
		A[i]=L->ventana->inf;
		L->ventana=L->ventana->siguiente;
		i++;
	}
}

int MostrarArreglo(pLista *L, int A[])
{
	int i;
	for (i=0; i !=L->longitud; i++)
	printf ("A[%i] = %d \n",i, A[i]);
	return (i);
}
