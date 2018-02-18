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
 

  system("cls");

  FILE *archivo, *archivo2 ;
  int resultado;

  archivo = fopen("texto.txt","a+");

  if( archivo == NULL ){
  	printf("No se pudo abrir el archivo archivo.txt\n");
  	exit(1);
  } 
 
  archivo2 = fopen("copiaArchivo.txt","a+");
  if(archivo2 == NULL){
    printf("Error en el archivo copiaArchivo.txt\n");
    exit(1);
  }
// fwrite(&est ,sizeof(est),1,archivo);
  //fread( &est, sizeof(est), 1, archivo);
  while(!feof(archivo)){
     resultado = fread( &est, sizeof(est), 1, archivo);
  	 if(resultado == 0 ) break;
     fwrite( &est , sizeof(est) , 1 , archivo2);
  }
  
  printf("Datos copiados...\n");
  

  fclose(archivo);
  fclose(archivo2);
  return 0;
}
