//gcc array.c -o  array.out

/*
  @author: christian peralta

*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> 


int main(void){
	
 	int *p , k[10], *q , i, tamanio = 0 , aux;
 	Vector *v;
 	size_t size;

 	system("cls");
 	q = (int *) malloc(4*sizeof(int));
;
 	q[0] = 1;
 	q[1] = 2;
 	q[2] = 3;
 	q[3] = 4;
 
 	size = _msize(q);
 	printf("tamanio del vector: %d bytes\n", size );
 	printf("numero de posiciones del vector: %d \n", size / sizeof(int));
    for( i = 0 ; i < 4; i++){
    	printf("%d\n", q[i]);
    }
    printf("\n");

    //redimensiono
    q = (int *) realloc( q , 8*sizeof(int));
    q[4] = 10;
 	q[5] = 11;
 	q[6] = 12;
 	q[7] = 13;

    size = _msize(q);
 	printf("tamanio del vector: %d bytes\n", size );
 	printf("numero de posiciones del vector: %d \n", size / sizeof(int));

 	for( i = 0 ; i < 8; i++){
    	printf("%d\n", q[i]);
    }

    printf("%d\n", q);//posicion de memoria
 	free(q);
 	//free(p);
	return 0;
 	
}