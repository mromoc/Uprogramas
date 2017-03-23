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

int agregarfrase(pLista *L,char palabra[])
{
	
	pNodo *nuevo;
	nuevo=malloc(sizeof(pNodo));
	nuevo->cadena= palabra;
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
	int i;
	i=0;
	pLista aux;	
	L->ventana=L->primero;
	while(L->ventana!=NULL)
	{
		printf("%s ",L->ventana->cadena);
		L->ventana=L->ventana->siguiente;
		i++;
	}
	printf("\nHay %i palabras en esta frase \n",i);
}

int main()
{
	// con el parrafo comentado se puede teclear las frases (2) con la memoria necesaria
	//y estas se incluiran en la lista para posteriormente imprimirse
	
	/*char *Frase1,*Frase2;
	Frase1=malloc(sizeof(Frase1));
	printf("Ingrese la primera frase: ");
	scanf("%s",Frase1);
	Frase2=malloc(sizeof(Frase2));
	printf("Ingrese la segunda frase: ");
	scanf("%s",Frase2);*/
	
	// Otra forma es declarar las variables char, para despues pedir la memoria necesaria
	/*
	char *Frase1,*Frase2;
	Frase1=malloc(sizeof(Frase1));
	Frase1="hola";
	Frase2=malloc(sizeof(Frase2));
	Frase2="Mundo";
	*/
	char Frase1[] = "Hola";
	char Frase2[] = "Mundo";
	pLista *L=Iniciarlista();
	agregarfrase(L,Frase1);
	agregarfrase(L,Frase2);
	Imprimir(L);
}
