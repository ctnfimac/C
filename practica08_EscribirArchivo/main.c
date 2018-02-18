// gcc main.c -o main.out
#include <stdio.h>
#include <stdlib.h>

struct registro{
	char nombre[20];
	char apellido[20];
	int matricula;
}est;


int main(){
  
  system("cls");
  printf("Nombre:");
  gets(est.nombre);
  printf("Apellido:");
  gets(est.apellido);
  printf("Legajo:");
  scanf("%d",&est.matricula);

  FILE * archivo;

  archivo = fopen("texto.txt","w");

  if( archivo == NULL ){
  	printf("No se puede abrir el archivo archivo.txt\n");
  	exit(1);
  } 

  fwrite( &est, sizeof(est), 1, archivo);
  //fprintf( archivo , est.nombre );
  //fprintf( archivo , est.apellido );
  printf("\nDatos guardados...\n");

  fclose(archivo);
  return 0;
}


