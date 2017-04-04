#include <stdio.h>
#define tam 9

int imprimir(int tablero[tam][tam])
{
	int x,y;
    printf("                  ");
    x=0;
    while (x < tam)
    {
    	y=0;
    	while (y < tam)
    	{
			printf(" %d ",tablero[y][x]);
    		if (y ==2 || y == 5)
    		{
    			printf("|");        
    		}
     		y++;     		
		}
    	if (x ==2 || x == 5)
    	{
		
        printf("\n                 --------------------------------");
    	}
        printf("\n                  ");
		x++;
	}
	printf("\n");
}



int llenar_tablero(int tablero[tam][tam])
{
    int y;
    FILE * archivo;
    archivo = fopen("sudokutab.txt","r");

    if(archivo == NULL)
    printf("Archivo no encontrado");
    else
    {
        y = 0;
        while(!feof(archivo))
        {
            fscanf(archivo,"%d %d %d %d %d %d %d %d %d",&(tablero[0][y]),&(tablero[1][y]),&(tablero[2][y]),&(tablero[3][y]),&(tablero[4][y]),&(tablero[5][y]),&(tablero[6][y]),&(tablero[7][y]),&(tablero[8][y]));
            y++;
        }
    }
    fclose(archivo);
}


int valido(int tablero[tam][tam],int columna, int fila, int num)
{
    int x,y;
    int j,i;
	y=0;
	while (y<tam)
	{
		if (tablero[columna][y]==num)
		{
			return 0;
		}
		y++;
	}
	x=0;
	while (x<tam)
	{
		if (tablero[x][fila]==num)
		{
			return 0;
		}
		x++;
	}
    if((columna < 3)&&(fila < 3))
    {
		j = i = 0;
	}
    if ((columna <= 5 && columna > 2)&&(fila < 3 && fila >= 0))
    {
        j = 3;
        i = 0;
    }
    if ((columna > 5)&&(fila < 3 && fila >= 0))
    {
        j = 6;
        i = 0;
    }
    if((columna<3)&&(fila<6 && fila >= 3))
    {
        j = 0;
        i = 3;
    }
    if((columna <= 5 && columna > 2)&& (fila<6 && fila >= 3) )
    {
		j = i = 3;
	}
    if( (columna > 5) && (fila<6 && fila >= 3))
    {
        j = 6;
        i = 3;
    }
    if((columna < 3) &&  (fila < 9 && fila > 5))
    {
        j = 0;
        i = 6;
    }
    if((columna <= 5 && columna > 2) &&  (fila < 9 && fila > 5))
    {
        j = 3;
        i = 6;
    }
    if((columna > 5) &&  (fila < 9 && fila > 5))
    {
		j = i = 6;
	}
	x=j;
	while (x<j+3)
	{
		y=i;
		while (y<i+3)
		{
			if (tablero[x][y]==num)
			{
				return 0;
			}
			y++;
		}
		x++;
	}
	return 1;
}


int buscar_espacio(int tablero[tam][tam],int x,int y, int *nx,int *ny)
{
    if (x<8)
    {
        *nx = x + 1;
        *ny = y;
    }else
    {
        *nx = 0;
        *ny = y + 1;
    }
    if (tablero[*nx][*ny] != 0)
    buscar_espacio(tablero,*nx,*ny,nx,ny);
}


int final(int tablero[tam][tam])
{
    int j,i;
	i=0;
	while (i<tam)
	{
		j=0;
		while (j<tam)
		{
			if (tablero[j][i]==0)
			{
				return 0;
			}
			j++;
		}
		i++;
	}
	return 1;
}

int jugar(int tablero[tam][tam], int x, int y)
{
     int num = 1,nx = 0,ny = 0;
     if (tablero[0][0] != 0)
     buscar_espacio(tablero,x,y,&nx,&ny);
     while(num <= 9)
	{
    	if ((valido(tablero,nx,ny,num))&&(nx < tam && nx >= 0 && ny < tam && ny >= 0))
    	{
	    	tablero[nx][ny] = num;
            if (final(tablero) == 0)
			{
            	jugar(tablero,nx,ny);
        	}
    	}
        num++;
    }
    if (final(tablero)== 0)
    {
    	tablero[x][y]= 0;
	}
}

int main()
{
    int tablero[tam][tam];
    llenar_tablero(tablero);
    imprimir(tablero);
    jugar(tablero,0,0);
    printf("                     Solucion:\n\n");
    imprimir(tablero);
}
