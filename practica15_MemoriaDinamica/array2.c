//gcc array2.c -o array2.out

/*
  @author: christian peralta

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void modificar(int *q);
int* modificar_direccion(int *q , int n);

int main(void){
	system("cls");

	int *p , x = 10 , y = 30;

	p = &x;

	printf("direccion:%d\n", p );
	printf("contendido:%d\n", *p );
	printf("x:%d\n", x );
	printf("\n");

	modificar(p);

	printf("\n");
	printf("direccion despues de funcion modificar():%d\n", p );
	printf("contendido despues de funcion modificar():%d\n", *p );
	printf("x:%d\n", x );
	printf("\n");

	printf("direccion:%d\n", p );
	printf("contendido:%d\n", *p );
	printf("\n");

    p = modificar_direccion( p , 2);
	printf("direccion nueva despues de funcion modificar_direccion():%d\n", p );
	//p = 40;
	printf("contendido nuevo despues de funcion modificar_direccion():%d\n", *p );
    printf("x:%d\n", x );
	//getch();
	return 0;
}


void modificar(int *q){
	printf("direccion:%d\n", q );
	printf("contendido:%d\n", *q );
	printf("\n");
	*q = 20;
	printf("direccion:%d\n", q );
	printf("contendido:%d\n", *q );
	printf("\n");
	q++;
	printf("direccion nueva:%d\n", q );
	printf("contendido nuevo:%d\n", *q );
}


int* modificar_direccion(int *q , int n){
   int i = 0;

   for( i = 0 ; i < n; i++ )
   		q++;
    *q = 30;
   	return q;
}