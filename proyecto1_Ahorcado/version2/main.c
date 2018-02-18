//gcc main.c -o main.out
//gcc -o miexe main.c

/*
  @author: christian peralta
  @brief: Juego del ahorcado version 2
  @details: _el programa elige de forma aleatoria entre 5 palabras ya establecidas
			_la posibilidad de equivocarse son de 5 veces

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#define INTENTOS 5
#define ingresar printf("\n\nIngresa una letra (luego enter):") 
#define incorrecto printf("\n\t\tmala eleccion!!!\n\n")
#define true 1
#define false 0

void imprimeDatos(char *c, int n);
void agregaLetraIncorrecta(char word, char *c);
int agregaLetraCorrecta(char word, char *c, char *d, int n);
int verificaPalabras(char *c, char *d, int n);
int verificaLetra( char letra , char *c, int n );
void presentacion(void);



int main(void){
	char letra, palabra[6] = "fimac";//{'f','i','m','a','c','\0'};
	char palabras[8][15] = {"fimac","valor","segagenesis","murcielago","gorilas","computadora","programacion","matematicas"};
	char letras_incorrectas[15] = {'\0'} ;
	char letras_correctas[15] = {'\0'};
	int intentos = 0, indice = 0 , i , tamanio_palabra;
	int gano = 0, letraRepetida, indicepalabra;

     

	system("cls");
	 // Semilla de rand();  
     srand(time(NULL)); 
     indicepalabra = rand() % 8 ;
     //printf("tamanio del vector: %d \n", strlen(palabras[indicepalabra]));

     //cargo las letras correctas
     for( i = 0 ; i <  strlen(palabras[indicepalabra]) ; i++)
     	letras_correctas[i] = '_';

     //printf("%s\n",palabras[indicepalabra] );
     /*printf("hay letra: %d \n", verificaLetra('b', palabras[0], strlen(palabras[indicepalabra])));
     printf("hay letra: %d \n", verificaLetra('o', palabras[4], strlen(palabras[indicepalabra])));
     printf("hay letra: %d \n", verificaLetra('s', palabras[3], strlen(palabras[indicepalabra])));*/

     /*for( i = 0 ; i <  strlen(palabras[indicepalabra]) ; i++)
     	printf("%c ",letras_correctas[i]);*/
	//printf("valor: %d\n", rand()%5);
	
	presentacion();
	printf(" \n\n\n");
	printf("letras incorrectas: ");
	imprimeDatos(letras_incorrectas, sizeof(letras_incorrectas));
	printf("\npalabra a formar: ");
	imprimeDatos(letras_correctas, strlen(letras_correctas));
   
    tamanio_palabra = strlen(palabras[indicepalabra]) ;

 	while( intentos < INTENTOS && gano == 0){
 		ingresar;
	    scanf("%c", &letra);
        system("cls");
        presentacion();
 		if( verificaLetra(letra , palabras[indicepalabra] , tamanio_palabra ) == false ){
 			incorrecto;
 			agregaLetraIncorrecta(letra, letras_incorrectas);
 			intentos++;
 		}else{
 			printf("\n\t\tmuy bien, la letra es correcta!!!\n\n");
 			letraRepetida = agregaLetraCorrecta(letra, letras_correctas, palabras[indicepalabra], tamanio_palabra);
 			if( letraRepetida == 1){
 				printf("Esa letra ya fue ingresada!!!\n");
 				intentos++;
 			}
 		}
 		fflush(stdin);
 		printf("letras incorrectas: ");
		imprimeDatos(letras_incorrectas, sizeof(letras_incorrectas));
		printf("\npalabra a formar: ");
		imprimeDatos(letras_correctas, tamanio_palabra);
		printf("\n");

		gano = verificaPalabras( letras_correctas , palabras[indicepalabra] , tamanio_palabra );
 	}
 	system("cls");
 	if( gano == true ) printf("\n\n\t\tFelicidades Gano!! la palabra es: %s \n\n", palabras[indicepalabra]);
 	else printf("\n\n\t\tPerdio!!! suerte para la proxima \n\n");
	
	getch();
	return 0;
}



void presentacion(void){
	printf("***********************************************************\n");
	printf("**                Juego del ahorcado                     **\n");
	printf("**                                                       **\n");
	printf("**              Forme la palabra correcta                **\n");
    printf("**       Puede cometer hasta %d intentos erroneos         **\n",INTENTOS);
	printf("***********************************************************\n");
}


void agregaLetraIncorrecta(char word, char *c){
	int i;
	
	for ( i = 0; c[i] != '\0'; i++);
	c[i] = word;
}



int agregaLetraCorrecta(char word, char *c, char *d, int n){
	int i, contador = 0;//contador indica cuantas veces esta la letra en la palabra
	
   
    for( i = 0 ; i < n ; i++){
    	if( d[i] == word &&  c[i] == word){
    		return 1;//quiere decir que la letra ya fue ingresada
    	}

    	if( d[i] == word &&  c[i] != word){
    		c[i] = word;
    		//return 0;//quiere decir que la letra ya fue ingresada
    	}
    }
 
   return 0; 
}



int verificaPalabras(char *c, char *d , int n){
	int i;

	for( i = 0 ; i < n ; i++ ){
		if( c[i] != d[i]) return 0;
	}
	return 1;
}

int verificaLetra( char letra , char *c , int n){
	int i  ;

	for( i = 0 ; i < n ; i++ ){
		if( c[i] == letra ) return true;
	}

	return false;
}

void imprimeDatos(char *c, int n){
	int i;

	for( i = 0 ; i < n ; i++){
		if( c[i] != '\0') printf("%c ", c[i]);
	}
}


