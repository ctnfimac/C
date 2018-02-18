//gcc main.c -o main.out
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPEN_FILE abrirArchivo(char* filename, char tipo);

void agregar(void);
void leer(void);
void buscar(char*);

struct cliente{
	char nombre[20];
	char apellido[20];
	long int legajo;
	int  edad;
};

FILE *archivo;
struct cliente dato;

int main(void){

  int opcion;
  char buscador[20];

  system("cls");
  printf("\nElija la operacion a realizar:\n\n1-Agregar\n2-leer\n3-buscar\n0-salir\n\n");
  printf("Opcion:");
  scanf("%d",&opcion);
  fflush(stdin);
  while( opcion != 0){
  switch(opcion){
  	case 1:
  		agregar();
  		break;
  	case 2:
 		leer();
  		break;
  	case 3:
  	    printf("Ingrese nombre cliente a buscar:");
  		gets(buscador);
  		fflush(stdin);
  		buscar(buscador);
  		break;
  	default:
  		printf("Opcion incorrecta\n");
  		break;
  }
   printf("\nElija la operacion a realizar:\n\n1-Agregar\n2-leer\n3-buscar\n0-salir\n\n");
   printf("Opcion:");
   scanf("%d",&opcion);
   fflush(stdin);
 }
  printf("Fin del programa, hasta la proxima!\n");
  //printf("nombre:%s\napellido:%s\nlegajo:%ld\nedad:%d", dato.nombre , dato.apellido , dato.legajo, dato.edad);
  return 0;
}




void agregar(void){
  printf("Ingrese su nombre:");
  gets(dato.nombre);
  fflush(stdin);
  printf("Ingrese su apellido:");
  gets(dato.apellido);
  fflush(stdin);
  printf("Ingrese su legajo:");
  scanf("%ld",&dato.legajo);
  fflush(stdin);
  printf("Ingrese su edad:");
  scanf("%d", &dato.edad);
  

   archivo = fopen("clientes.txt","a+");
   if(archivo==NULL){
   	printf("Error! no se pudo abrir el archivo\n");
   	exit(1);
   }
   system("cls");
   if(fwrite( &dato , sizeof(dato) , 1 , archivo) > 0 )
   	 printf("Cliente ingresado correctamente\n");
   else printf("Error al querer ingresar el cliente en el archivo\n");
   
   fclose(archivo);
}




void leer(void){
   archivo = fopen("clientes.txt","r");
   if(archivo==NULL){
   	  printf("Error! no se pudo abrir el archivo\n");
   	  exit(1);
   }
   printf("Clientes en la base de datos:\n");
   fread( &dato , sizeof(dato) , 1 , archivo);
   while(!feof(archivo)){
   	 printf("\nNombre:%s\napellido:%s\nLegajo:%ld\nEdad:%d\n", dato.nombre, dato.apellido, dato.legajo, dato.edad );
   	 fread( &dato, sizeof(dato), 1 , archivo);
   }
   printf("\n");
   system("pause");
   system("cls");
}


void buscar(char buscador[]){
  archivo = fopen("clientes.txt","r");
  char flag = 0x00;

  if(archivo == NULL){
  	printf("Error! no se pudo abrir el archivo clientes.txt\n");
  	exit(1);
  }

  fread( &dato , sizeof(dato) , 1 , archivo);
  fflush(stdin);
  while(!feof(archivo)){
  	if( strcmp(dato.nombre, buscador) == 0 ){
  		printf("Persona encontrada!\n");
  		printf("%s %s legajo:%ld edad:%d\n", dato.nombre, dato.apellido, dato.legajo , dato.edad );
  		flag = 0x01;
  	}
  	  fread( &dato , sizeof(dato) , 1 , archivo);
  	  fflush(stdin);
  }
  if(flag == 0x00) printf("No se encontro ningun cliente con el nombre %s \n", buscador);
  fclose(archivo);
}



void abrirArchivo(char filename[], char tipo){

}