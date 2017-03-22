#include <stdio.h>
#include <stdlib.h>
 
int main () 
{
	char Frase[] = "Hola Mundo.";
	int i=0, contador=0;
    while (Frase[i]!='.')
    {
        if (Frase[i]==' ')
        {
            contador++;
        }
    	i++;
    }
    printf(" tiene %i palabras\n",contador+1);
    printf("Frase: %s ",Frase);
}
