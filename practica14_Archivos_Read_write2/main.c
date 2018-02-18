//gcc main.c -o main.out

/*
  @author: christian peralta

*/

#include <stdio.h>
#include <stdlib.h>
#include "ctnlibreria.h"
#include "primitivas.c"



int main(void){
	system("cls");
	char opcion[10];
	

	printf("\nelija la operacion a realizar:");
	printf("\n1)Agregar\n2)Mostrar\n3)Buscar\n4)Eliminar\n5)salir\n");
	printf("Opcion:");

	gets(opcion); 
	fflush(stdin);
	strTolower(opcion);
	
	handler( opcion );

	printf("\n");
	return 0;
}


