//gcc array5.2.c -o array5.2.out

/*
  @author: christian peralta

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Vector Vector;

struct Vector{
	int *valores;
	int n;
};

Vector *vector_nuevo(void);
void vector_agregar( Vector *v , int d );
void vector_mostrar(Vector *v);
int vector_tamanio(Vector *v);
void vector_liberar(Vector *v);
int vector_extraer(Vector *v);


int main(void){
	system("cls");

	Vector *miv ;
	int i;

	miv = vector_nuevo();



    vector_agregar( miv , 3 );
    vector_agregar( miv , 4 );
    vector_agregar( miv , 5 );
    vector_agregar( miv , 2 );
    vector_agregar( miv , -3 );
    vector_agregar( miv , -6 );
    vector_agregar( miv , -3 );
    vector_agregar( miv , -6 );
    vector_mostrar(miv);
    printf("Tamanio del vector: %d\n", vector_tamanio(miv) );

    printf("valor extraido:%d\n", vector_extraer(miv) );
    printf("dato:%d\n", miv->valores[7]);
    vector_mostrar(miv);

    vector_agregar( miv , 30 );
    printf("dato:%d\n", miv->valores[7]);
    vector_mostrar(miv);
	/*printf("Valores en el vector\n");
	for( i = 0 ; i < miv->n ; i++ )
		printf("vector[%d]: %d\n", i, miv->valores[i] );*/

	printf("Tamanio del vector: %d\n", vector_tamanio(miv) );
	
	vector_liberar(miv);
	//printf("Tamanio del vector: %d\n", vector_tamanio(miv) );
	return 0;
}


//Funciones
Vector *vector_nuevo(void){
	Vector *v;
	v = (Vector *) malloc(sizeof(Vector));
	v->valores = NULL;
	v->n = 0;
	return v;
}


void vector_agregar( Vector *v , int d ){
	v->n++;
	v->valores = (int *) realloc( v->valores , v->n * sizeof(int));
	v->valores[v->n-1] = d;
}


void vector_mostrar(Vector *v){
	int i;
	printf("Valores en el vector\n\n");
	for( i = 0 ; i < v->n ; i++ )
		printf("vector[%d]: %d\n", i, v->valores[i] );
}



int vector_tamanio(Vector *v){
	return v->n;
}


void vector_liberar(Vector *v){
	free(v->valores);
	free(v);
	v = NULL;
}


//falta hacer que elimine el ultimo lugar
int vector_extraer(Vector *v){
	int valor ;

	valor = v->valores[v->n - 1] ;
	v->valores[v->n - 1] = '\0';
	v->n = v->n - 1 ;
	v->valores = (int *) realloc( v->valores , v->n * sizeof(int));

	return valor;
}