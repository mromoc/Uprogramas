#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
	int dato;
	struct Nodo *siguiente, *anterior;
}pNodo;

struct Nodo *primero=NULL;
struct Nodo *ultimo=NULL;

int Agregar(pNodo *nuevo,int numero)
{
	nuevo=malloc(sizeof(pNodo));
	nuevo->siguiente=nuevo->anterior=NULL;
	nuevo->dato=numero;
	if(primero==NULL)
	{
		primero=ultimo=nuevo;
	}
	else
	{
		ultimo->siguiente=nuevo;
		ultimo=nuevo;		
	}	
}

int main()
{
	pNodo *nuevo;
	Agregar(nuevo,NULL);
	Agregar(nuevo,7);
	nuevo=primero;
	while(nuevo!=NULL)
	{
		printf("\n %i",nuevo->dato);
		nuevo=nuevo->siguiente;
	}
}
