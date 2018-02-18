//gcc main.c -o main.out
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Empresa{
  char presidente[25];
  char dni[10];
  int  edad;
  long int telefono;
  char web[15];
};

struct Trabajador{
	char nombre[20];
	char puesto[16];
	int antiguedad;
};

struct Empresa fimac;
struct Trabajador empleado[2];


int main(){
	int i;
	system("cls");
	strcpy(fimac.presidente ,"Christian Peralta");
	strcpy(fimac.dni,"33333333");
	fimac.edad = 30;
	fimac.telefono = 1561870920;
	strcpy(fimac.web , "www.fimac.com.ar");

  printf("Presidente: %s\n", fimac.presidente);
	printf("web: %s\n", fimac.web);
	printf("dni: %s\n", fimac.dni);
	printf("edad: %d\n", fimac.edad);
	printf("telefono: %li\n", fimac.telefono);
    //ingreso de datos de los empleados por teclado
    for( i= 0 ; i < 2 ; i++){
    	printf("\nEmpleado %d\n", i+1);
    	printf("ingrese Nombre y Apellido:");
    	gets(empleado[i].nombre);
    	printf("ingrese puesto de trabajo:");
    	gets(empleado[i].puesto);
    	printf("Ingrese anios de antiguedad:");
    	scanf("%d", &empleado[i].antiguedad);
    	fflush(stdin);
    }
    for( i= 0 ; i < 2 ; i++){
    	printf("\nEmpleado %d\n", i+1);
    	printf("Nombre y Apellido: %s\n", empleado[i].nombre);
    	printf("Puesto de trabajo: %s\n", empleado[i].puesto);
    	printf("Anios de antiguedad: %d\n\n", empleado[i].antiguedad);
    }
	return(0);
}