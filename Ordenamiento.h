#ifndef stdio_h
#include <stdio.h>
#define stdio_h
#endif

#ifndef stdlib_h
#include <stdlib.h>
#define stdio_h
#endif

//Divide el array en 2 sublistas

int Dividir (int *num, int menor, int mayor){
	int izq, dch, temp;
	izq = menor;
	dch = mayor;
	while (izq < dch) {
		while (num[dch] > num[menor])
			dch--;
		while ((izq < dch) && (num[izq] <= num[menor]))
			izq++;
		if (izq < dch) {
			temp = num[izq];
			num[izq] = num[dch];
			num[dch] = temp;
		}
	}
	temp = num[dch];
	num[dch] = num[menor];
	num[menor] = temp;
	return dch;
}

void Quicksort (int *num, int menor, int mayor){
	int medio;
	if (menor < mayor) {
		medio = Dividir (num, menor, mayor);
		Quicksort (num, menor, medio-1);
		Quicksort (num, medio+1, mayor);
	}
}

