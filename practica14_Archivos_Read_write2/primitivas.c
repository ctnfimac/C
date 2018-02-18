#include "ctnlibreria.h"

typedef struct Persona Persona;



struct Persona{
	char nombre[20];
	int edad;
};


/*-------------------------------------------------------------------------

 Convierte una cadena a letras minusculas

 -------------------------------------------------------------------------*/
void strTolower(char *palabra){
	int i = 0  ;
	
	for( i = 0 ; i < strlen(palabra); i++ )
		palabra[i] = tolower(palabra[i]);
	palabra[i] = '\0';
	
}



/*-------------------------------------------------------------------------

 handler , menu de opciones

 -------------------------------------------------------------------------*/
void handler(char *opcion){
	if(!strcmp(opcion,"agregar")){
		agregar();
	}else if(!strcmp(opcion,"mostrar")){
		mostrar();
	}else if(!strcmp(opcion,"buscar")){
		buscar();
	}else if(!strcmp(opcion,"eliminar")){
		borrar();
	}else if(!strcmp(opcion,"salir")){
		printf("Eligio la opcion salir\n");
	}else{
		printf("Error! opcion incorrecta\n");
	}
}


/*-------------------------------------------------------------------------

 Agregar clientes 

 -------------------------------------------------------------------------*/
void agregar(void){

	Persona persona;
    FILE *archivo;

	archivo = fopen("clientes.txt","a+");
	if( archivo == NULL){
		printf("\nNo se pudo abrir el archivo");
		exit(1);
	}
	printf("Ingrese nombre:");
	gets(persona.nombre);
	fflush(stdin);
	printf("Ingrese Edad:");
	scanf("%d",&persona.edad);
	fflush(stdin);

	fwrite(&persona, sizeof(persona), 1, archivo);
	fclose(archivo);
}


/*-------------------------------------------------------------------------

 Mostrar por pantalla los clientes existentes 

 -------------------------------------------------------------------------*/
void mostrar(void){

	Persona persona;
    FILE *archivo;

	archivo = fopen("clientes.txt","r");
	if( archivo == NULL){
		printf("\nNo se pudo abrir el archivo");
		exit(1);
	}
     
    fread(&persona, sizeof(persona), 1, archivo);
    while(!feof(archivo)){
    	printf("\nUsuario:%s  Edad:%d", persona.nombre, persona.edad);
    	fread( &persona, sizeof(persona), 1, archivo);
    }
	fclose(archivo);
}


/*-------------------------------------------------------------------------

 Buscar un cliente por su nombre y mostrar sus datos 

 -------------------------------------------------------------------------*/
void buscar(void){
  Persona persona;
  FILE *archivo = fopen("clientes.txt","r");
  char buscar[20];

  if( archivo == NULL ){
  	printf("\nERROR!,No se pudo abrir el archivo");
  	exit(1);
  }

  printf("Ingrese el nombre de la persona que quiere buscar:");
  gets(buscar);

  fread( &persona, sizeof(persona), 1, archivo);
  while(!feof(archivo)){
  	if( !strcmp(persona.nombre,buscar)){
  		printf("\nUsuario:%s , Edad:%d\n", persona.nombre, persona.edad );
  	}
  	fread( &persona, sizeof(persona), 1, archivo);
  }
  fclose(archivo);
}


/*-------------------------------------------------------------------------

 Borra los datos de un cliente al ingresar su nombre 

 -------------------------------------------------------------------------*/
void borrar(void){
	FILE *archivo = fopen("clientes.txt","r+");
	FILE *copia = fopen("copia.txt","w");
	char dato[20];
	Persona pcopia, persona;

	if( archivo == NULL  || copia == NULL){
		printf("Error al intentar de abrir los archivos\n");
		exit(1);
	}

	printf("Ingrese el nombre de la persona que quiere borrar:");
    gets(dato);
    fflush(stdin);
    
    //copio un nuevo archivo sin los datos del cliente al eliminar
    fread(&persona,sizeof(persona),1,archivo);
    while(!feof(archivo)){
    
    	if(strcmp(persona.nombre,dato)){//si el nombre es distnto al ingresado
    		strcpy(pcopia.nombre,persona.nombre);
    		pcopia.edad = persona.edad;
    		fwrite(&pcopia, sizeof(pcopia), 1, copia);
    	}
    	fread(&persona,sizeof(persona),1,archivo);	
    }
     fclose(archivo);
     fclose(copia);
   

    //copio el archivo de copia a el original
    archivo = fopen("clientes.txt","w");
	copia = fopen("copia.txt","r+");

	fread(&pcopia,sizeof(pcopia),1,copia);
    while(!feof(copia)){
    	strcpy( persona.nombre , pcopia.nombre );
    	persona.edad = pcopia.edad ;
    	fwrite(&persona, sizeof(persona), 1, archivo);
    	fread(&pcopia,sizeof(pcopia),1,copia);	
    }

    fclose(archivo);
    fclose(copia);
}