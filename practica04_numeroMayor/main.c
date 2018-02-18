//gcc main.c -o main.out
#include <stdio.h>
#include <stdlib.h>

#define CANT_MAX 5

void mayor();
void menor();
void ordenar();

int main(){
 
 	int opcion;
 	system("cls");
 	printf("\nElige una opcion:\n1->calcular mayor\n2->calcular menor\n3->ordenar valores mayor a menor\nopcion:"); 
 	scanf("%d", &opcion); 
 	switch(opcion){
 		case 1:
 			mayor();
 			break;
 		case 2:
 			menor();
 			break;
 		case 3:
 			ordenar();
 			break;
 		default:
 			printf("\nOpcion incorrecta\n");
 			break;
 	} 
	return(0);
}

/*----------------------------------------------------------------------------------
  devuelve el numero mayor ingresado
 ----------------------------------------------------------------------------------*/
void mayor(){
	int valor, i, max ;
    int flag = 0 ;
	for( i = 0 ; i < CANT_MAX ; i++){
    	printf("Ingrese un valor:");
    	scanf("%d",&valor);
    	if( flag != 0 ) max = ( valor > max ) ?  valor : max ; 
    	else{
    		flag = 1;
    		max = valor;
    	} 
    }
    printf("\nEl valor maximo ingresado fue: %d\n", max);
}

/*----------------------------------------------------------------------------------
  devuelve el numero menor ingresado
 ----------------------------------------------------------------------------------*/
void menor(){
	int valor, i, min, flag = 0 ;

	for( i = 0 ; i < CANT_MAX ; i++){
    	printf("Ingrese un valor:");
    	scanf("%d",&valor);
    	if( flag != 0 ) min = ( valor < min ) ?  valor : min ; 
    	else{
    		flag = 1;
    		min = valor;
    	} 
    }
    printf("\nEl valor minimo ingresado fue: %d\n", min);
}


/*----------------------------------------------------------------------------------
  devuelve grupo de numeros ingresados de mayor a menor
 ----------------------------------------------------------------------------------*/
void ordenar(){
	int input[CANT_MAX] , i, j, aux ;
    
    //ingreso datos
	for( i = 0 ; i < CANT_MAX ; i++){
    	printf("Ingrese valor vector[%d]:",i);
    	scanf("%d",&input[i]);
    }
    /*for( i = 0 ; i < CANT_MAX ; i++){
    	printf("\ninput[%d]: %d",i,input[i]);
    }*/

    //los ordeno
    for( i=0 ; i < CANT_MAX - 1; i++){
    	for( j = i + 1 ; j < CANT_MAX ; j++){
    		if( input[j] > input[i]){
    			aux = input[i];
    			input[i] = input[j];
    			input[j] = aux ;
    		}
    	}
    }

    printf("\nValores ordenados de mayor a menor:\n");
    for( i = 0 ; i < CANT_MAX ; i++){
    	printf("\ninput[%d]: %d",i,input[i]);
    }
    
}