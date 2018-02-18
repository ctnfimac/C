// gcc main.c -o main.out
#include <stdio.h>
#include <stdlib.h>

struct registro{
	char nombre[20];
	char apellido[20];
	int matricula;
}est;


int main(){
  int cont  = 0 ;
  system("cls");
  /*printf("\nNombre:");
  gets(est.nombre);
  printf("Apellido:");
  gets(est.apellido);
  printf("Legajo:");
  scanf("%c",&est.matricula);
 */
  FILE * archivo;

  archivo = fopen("texto.txt","r");

  if( archivo == NULL ){
  	printf("No se pudo leer el archivo archivo.txt\n");
  	exit(1);
  } 
 
  fread( &est, sizeof(est), 1, archivo);
  while(!feof(archivo)){
  	
  	printf("\nnombre: %s\nApellido: %s \nMatricula: %d", est.nombre, est.apellido, est.matricula );
    fread( &est, sizeof(est), 1, archivo);
  }
  

  printf("\nDatos leidos...\n");

  fclose(archivo);
  return 0;
}


