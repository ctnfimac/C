// gcc main.c -o main.out
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct registro{
	char nombre[20];
	char apellido[20];
	int matricula;
}est;


int main(){
  int cont  = 0 ;
  char nom[20];

  system("cls");

 /* printf("\nNombre:");
  gets(est.nombre);
  printf("Apellido:");
  gets(est.apellido);
  printf("Legajo:");
  scanf("%c",&est.matricula);
 */
  FILE * archivo;

  archivo = fopen("texto.txt","a+");

  if( archivo == NULL ){
  	printf("No se pudo abrir el archivo archivo.txt\n");
  	exit(1);
  } 
  printf("\nDigite el nombre que quiera buscar:");
  gets(nom);
// fwrite(&est ,sizeof(est),1,archivo);
  fread( &est, sizeof(est), 1, archivo);
  while(!feof(archivo)){
  	
  	if(strstr(nom,est.nombre) != NULL){
     printf("\nnombre: %s\nApellido: %s \nMatricula: %d", est.nombre, est.apellido, est.matricula );
     //fread( &est, sizeof(est), 1, archivo);
  	}else{
  		printf("No se encuentra la persona solicitada\n");
  		break;
  	}
  	fread( &est, sizeof(est), 1, archivo);
  }
  

  

  fclose(archivo);
  return 0;
}
