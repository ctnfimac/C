//gcc array3.c -o array3.out

/*
  @author: christian peralta

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Vector Vector;

struct Vector
{
	int valores[2];
	int nelementos;
};


void vector_nuevo(Vector *v);

int main(void){
	system("cls");
	Vector v , *v2 ;
    size_t size;

	/*v.nelementos = 4;
	v.valores[0] = 1;*/
	printf("tamanio del array v: %d bytes\n", sizeof(v) );

	v2 = (Vector *) calloc(4,sizeof(Vector));
	size = _msize(v2);
	printf("tamanio del array que apunta v2: %d bytes\n", size );

	free(v2);
	v2 = NULL;
	size = _msize(v2);
	printf("tamanio, despues de liberar, del array que apunta v2: %d bytes\n", size );

	return 0;
}


