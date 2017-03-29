#include <stdio.h>
#include <stdlib.h>
 

typedef struct Nodo{
    char *cadena;
    struct Nodo *siguiente;
}pNodo;

typedef  struct Lista{
    pNodo *ventana,*primero;
}pLista;

pLista *Iniciarlista()
{
	pLista *L;
	L=malloc(sizeof(pLista));
	L->ventana=L->primero=NULL;
	return (L);
}

int agregarfrase(pLista *L)
{
	char *palabra;
	palabra=malloc(sizeof(palabra));
	printf("Ingresar la frase:\n");
	scanf("%s",palabra);
	pNodo *nuevo;
	nuevo=malloc(sizeof(pNodo));
	nuevo->cadena=palabra;
	nuevo->siguiente=NULL;
	if(L->ventana==NULL)
	{
		L->ventana=L->primero=nuevo;
	}
	else
	{
		nuevo->siguiente=L->ventana->siguiente;
		L->ventana->siguiente=nuevo;
	}
	L->ventana=nuevo;
}

int Imprimir(pLista *L)
{
	pLista *aux;
	int i;
	i=0;
	aux = L->ventana;
	L->ventana=L->primero;
	while(L->ventana!=NULL)
	{
		printf("|%s ",L->ventana->cadena);
		L->ventana=L->ventana->siguiente;
		i++;
	}
	printf("|\nHay %i palabras en esta frase\n\n",i);
	L->ventana=aux;
}

int opciones()
{
	printf("1.- Ingresa tu frase\n");
	printf("2.- Imprimir lista\n");
	printf("0.- Salir\n");
}
int Instrucciones(int termino, int opcion,pLista *L)
{
	while(termino == 0)
	{
		opciones();
		printf("Opcion=");
		scanf("%i",&opcion);
		system("cls");
		if(opcion==1) agregarfrase(L);
		if(opcion==2) Imprimir(L);
		if(opcion==0) termino=1;
	}
}

int main()
{
	int termino,opcion;
	pLista *L=Iniciarlista();
	Instrucciones(termino,opcion,L);
}
