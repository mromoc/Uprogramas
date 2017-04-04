#include <stdio.h>
#include <stdlib.h>

//Plantilla creada para poder guiarme, 2016, 2°semestre.

typedef struct Nodo
{
	int inf;
	struct Nodo *siguiente;
}*pNodo,*Pila;


void Agregar(Pila *p)
{
	int numero;
	
	pNodo nuevapila;
	printf("NUMERO:");scanf("%i",&numero);
	nuevapila=(pNodo)malloc(sizeof(struct Nodo));
	nuevapila->inf=numero;
	nuevapila->siguiente=(*p);
	(*p)=nuevapila;
}

int Eliminar(Pila *p)
{
	if ((*p)==NULL)
	{
		printf("No hay pila \n\n");
	}
	else
	{
		pNodo nodo;	
		nodo=(*p);
		if (nodo==NULL)
		{
			return 0;
		}
		(*p)=nodo->siguiente;
		free(nodo);
	}
}

int main()
{
	int opcion;
	Pila p=NULL;
	while (opcion !=5)
	{
		
		printf("1.-Agregar elemento \n");
		printf("2.-Eliminar tope \n");
		printf("3.-Retorna elemento de tope \n");
		printf("4.-Destruir pila \n");
		printf("5.-Salir \n");
		printf("Ingresa Opcion:");
		scanf("%i",&opcion);
		
		system("clear");
		if (opcion ==1){Agregar(&p);}
		if (opcion ==2){Eliminar(&p);}
		if (opcion ==3)
		{
			if (p==NULL)
			{
				printf("No hay Pila \n\n");
			}
			else
			{
				printf("Tope: %i \n\n",p->inf);	
			}
		}
		if (opcion==4)
		{
			while (p!=NULL)
			{
				Eliminar(&p);
			}
			printf("Pila elimanda \n\n");
		}
	}
}
