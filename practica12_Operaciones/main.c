// gcc main.c -o main.out
#include<stdio.h>
#include<stdlib.h>
#include"operaciones.h"


int main(void)
{

  int num1 , num2, opcion;

  system("cls");
  printf("Ingrese un numero:");
  scanf("%d", &num1);
  printf("Ingrese otro numero:");
  scanf("%d", &num2);

  printf("Elija la operacion a realizar:  1-sumar | 2-restar | 3-multiplicar | 4-Dividir\n");
  printf("Opcion:");
  scanf("%d", &opcion);


  switch(opcion){
  	case 1:
  		printf("Resultado: %d\n", operacion(suma,num1,num2));
  	    break;
  	case 2:
  		printf("Resultado: %d\n", operacion(resta,num1,num2));
  	    break;
  	case 3:
  		printf("Resultado: %d\n", operacion(multiplicacion,num1,num2));
  	    break;
  	case 4:
  		printf("Resultado: %d\n", operacion(division,num1,num2));
  	    break;
  	default:
  	  printf("opcion incorrecta\n");
  	  break;
  }
  
  return 0;
}


