// nota num max 65535 para vector tipo unsigned int
// ejemplo : pasar numero 83 base 10 a base 2
//
//   128     64     32    16    8    4    2    1
//
//    0       1      0     1    0    0    1    1   resultado binario
//
//   83 >= 128 ?  no entonces en la posicion 128 pongo un 0
//   83 >= 64  ?  si entonces en la posicion 64 pongo un 1 y resto 84 - 64 = 19
//   19 >= 32  ?  no entonces en la posicion 32 pongo un 0
//   19 >= 16  ?  si entonces en la posicion 16 pongo un 1 y resto 19 - 16 = 3
//   3  >= 8   ?  no entonces en la posicion 8 pongo un 0
//   19 >= 4   ?  no entonces en la posicion 34 pongo un 0
//    3 >= 2   ?  si entonces en la posicion 2 pongo un 1 y resto 3 - 2 = 1
//    1 >= 1   ?  si entonces en la posicion 1 pongo un 1 


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20

int main(void){
	system("cls");
	int entrada, i = 0 , flag = 0 , tope;
	float indices[MAX] = {0};
		
	printf("***Conversion de numero decimal a numero binario***\n");
	printf("El programa finaliza ingresando el numero -1\n\n");
	
	printf("Ingrese un numero:");
	scanf("%d",&entrada);
	
	while( entrada != -1 ){
	
	//cargo los indices	
	while( flag!= 1){
		if( pow(2,i) <= entrada){
			indices[i] = pow(2,i);
			i++;
		}else{
			flag = 1 ;
		}
	}	

	if( entrada < 0 ){
		printf("¡el valor ingresado es incorrecto!\n");
	}else{
		printf("Resultado:");
		
		for( tope = i - 1 ; tope >= 0 ; tope-- ){
			if( entrada >= indices[tope]){
				printf("1");
			    entrada = entrada - indices[tope];
			}else  printf ("0");
		}
			
	  }
	  
	 printf("\n\nIngrese un numero:");
	 scanf("%d",&entrada);
    }
	printf("\nfin del programa");
	getch();
	return 0;
}
