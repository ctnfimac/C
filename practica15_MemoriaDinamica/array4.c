//gcc array4.c -o array4.out

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


Vector *vector_nuevo(void);
Vector *aumentar_tamanio(Vector *v);//medio al pedo


int main(void){
	system("cls");
	Vector *mivector;
	size_t size;

	mivector = vector_nuevo();

	mivector->nelementos = 4;
	mivector->valores[0] = 3;
	mivector->valores[1] = 2;
	

	printf("%d\n%d\n%d\n", mivector->nelementos, mivector->valores[0], mivector->valores[1] );
	size = _msize(mivector);
	printf("tamanio del puntero que apunta mivector: %d bytes\n", size );

	mivector = aumentar_tamanio(mivector);
	size = _msize(mivector);
	printf("tamanio del puntero que apunta mivector: %d bytes\n", size );
	mivector[1].nelementos = 10;
	mivector[1].valores[0] = 11;
	mivector[1].valores[1] = 12;
	printf("%d\n%d\n%d\n", mivector[1].nelementos, mivector[1].valores[0], mivector[1].valores[1] );

	mivector[4].nelementos = -10;
	mivector[4].valores[0] = -11;
	mivector[4].valores[1] = -12;

	//free(mivector);
	//mivector = NULL; //para eliminarlo completamente sino queda el valor de elementos
	//printf("%d\n%d\n%d\n", mivector->nelementos, mivector->valores[0], mivector->valores[1] );
	size = _msize(mivector);
	printf("(free) tamanio del puntero que apunta mivector: %d bytes\n", size );

	return 0;
}





Vector *vector_nuevo(void){
	Vector *aux;
	aux = (Vector *) malloc(sizeof(Vector));
	return aux;
}


Vector *aumentar_tamanio(Vector *v){
	v = (Vector *) realloc(v , 2 * sizeof(Vector));
	return v;
}