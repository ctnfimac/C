/*
  http://caniuse.com/
  https://www.emenia.es/flexbox-la-caja-flexible-css3/
  http://gnoma.es/blog/flexbox-interfaces-flexibles-css3/
*/

//gcc main.c -o main.out
//gcc -o miexe main.c

/*
  @author: christian peralta
  @brief: Juego del ahorcado
  @details: la palabra es fija en el programa si hace mas de 5 intentos erroneos pierde.
            por cada intento correcto o incorrecto se imprime la letra en consola.
            la palabra es "fimac"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INTENTOS 5
#define ingresar printf("\n\nIngresa una letra (luego enter):") 
#define incorrecto printf("\n\t\tmala eleccion!!!\n\n")
#define true 1
#define false 0

void imprimeDatos(char *c, int n);
void agregaLetraIncorrecta(char word, char *c);
int agregaLetraCorrecta(char word, char *c, char *d, int n);
int verificaPalabras(char *c, char *d, int n);
void presentacion(void);



int main(void){
	char letra, palabra[6] = {'f','i','m','a','c','\0'};
	char letras_incorrectas[10] = {'\0'} ;
	char letras_correctas[5] = {'_','_','_','_','_'};
	int intentos = 0, indice = 0 , i , tamanio_palabra;
	int gano = 0, letraRepetida;

	system("cls");
	presentacion();
	printf(" \n\n\n");
	printf("letras incorrectas: ");
	imprimeDatos(letras_incorrectas, sizeof(letras_incorrectas));
	printf("\npalabra a formar: ");
	imprimeDatos(letras_correctas, sizeof(letras_correctas));
   
    tamanio_palabra = sizeof(palabra) - 1 ;

 	while( intentos < INTENTOS && gano == 0){
 		ingresar;
	    scanf("%c", &letra);
        system("cls");
        presentacion();
 		if( letra != 'f' && letra != 'i' && letra != 'm' && letra != 'a' && letra != 'c' ){
 			incorrecto;
 			agregaLetraIncorrecta(letra, letras_incorrectas);
 			intentos++;
 		}else{
 			printf("\n\t\tmuy bien, la letra es correcta!!!\n\n");
 			letraRepetida = agregaLetraCorrecta(letra, letras_correctas, palabra, tamanio_palabra);
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

		gano = verificaPalabras( letras_correctas , palabra , tamanio_palabra );
 	}
 	system("cls");
 	if( gano == true ) printf("\n\n\t\tFelicidades Gano!! la palabra es: %s \n\n", palabra);
 	else printf("\n\n\t\tPerdio! la palabra era: %s \n\n", palabra);
	
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
	int i;
	
   
    for( i = 0 ; i < n ; i++){
    	if( d[i] == word &&  c[i] == word){
    		return 1;//quiere decir que la letra ya fue ingresada
    	}

    	if( d[i] == word &&  c[i] != word){
    		c[i] = word;
    		return 0;//quiere decir que la letra ya fue ingresada
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



void imprimeDatos(char *c, int n){
	int i;

	for( i = 0 ; i < n ; i++){
		if( c[i] != '\0') printf("%c ", c[i]);
	}
}


