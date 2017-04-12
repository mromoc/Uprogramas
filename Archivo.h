#ifndef stdio_h
#include <stdio.h>
#define stdio_h
#endif

#ifndef stdlib_h
#include <stdlib.h>
#define stdio_h
#endif

void *crear ()
{
	FILE *f;
	f = fopen ("archivo.txt","w");
	if (f==NULL) printf("file error");
	fclose(f);
}

