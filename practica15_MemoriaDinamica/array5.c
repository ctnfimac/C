//gcc array5.c -o array5.out

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
//Vector *agrega_valor( Vector *v , int d );
void agrega_valor( Vector *v , int d );


int main(void){
	system("cls");

	Vector *miv ;
	size_t size;
	int i;

	//funaux( 3 );

	/*for( i = 0 ; i < 5 ; i++ )
		vector[i] = i;*/
	miv = vector_nuevo();


	//miv = agrega_valor( miv , 3 );
	//printf("n:%d\n", miv->n );
	

	//miv = agrega_valor( miv , 4 );
	//printf("n:%d\n", miv->n );

	//miv = agrega_valor( miv , 5 );
	//printf("n:%d\n", miv->n );

    agrega_valor( miv , 3 );
    agrega_valor( miv , 4 );
    agrega_valor( miv , 5 );

	printf("Valores en el vector\n");
	for( i = 0 ; i < miv->n ; i++ )
		printf("vector[%d]: %d\n", i, miv->valores[i] );
	free(miv);
	miv = NULL;
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


/*Vector *agrega_valor( Vector *v , int d ){
	int tope , *aux , i ;
	//printf("%d\n", v->n );
	tope = v->n + 1;

	v->valores = (int *) realloc( v->valores , tope*sizeof(int));
	v->n = tope;
	v->valores[tope-1] = d;
	
	return v;
}*/


/*Vector *agrega_valor( Vector *v , int d ){
	v->n++;//aumento una unidad al numero de posiciones n
	v->valores = (int *) realloc( v->valores , v->n * sizeof(int));//aumento el tamaño en 1 del array 'valores'
	v->valores[v->n-1] = d;//le doy el a la ultima posicion el valor ingresado
	return v;
}*/

void agrega_valor( Vector *v , int d ){
	v->n++;
	v->valores = (int *) realloc( v->valores , v->n * sizeof(int));
	v->valores[v->n-1] = d;
}

