//gcc main.c -o main.out

#include <stdio.h>
#include <stdlib.h>

#define DIG_MAX 10

void intToBin( int n);

int main(void){
	int n  ;
	system("cls");
	printf("\nIngrese un numero de 0-255 y que sea entero:");
	scanf("%d", &n);
	intToBin(n);
  return 0;
}

/*---------------------------------------------------------------------------
  imprime el valor binario de un numero entero
 -----------------------------------------------------------------------------*/
void intToBin( int n){
 int  i = 0 , j , array[DIG_MAX];
 /*if( n>=0 && n <= 255){
  int  bin[8]= {0,0,0,0,0,0,0,0} , resto, cociente = 0, contador = 1 ;
        
        resto = n % 2;
		cociente = n / 2;
		bin[0] = resto;
	
        while (cociente != 1){
        	resto = cociente % 2;
			cociente = cociente / 2;
			bin[contador] = resto;
			contador++;
        }
        bin[contador] = cociente;
		printf("\nnumero decimal: %d -> numero binario:%d%d%d%d%d%d%d%d \n", n, bin[7], bin[6] , bin[5] , bin[4] ,bin[3], bin[2] , bin[1] ,   bin[0]  );
	
	}else{
		printf("El valor ingresado no esta en el rango de valores admitidos!\n");
	}	*/

  while( n > 0){
  	array[i] = n % 2;
  	n = n / 2;
  	++i;
  }
  for( j = i  - 1 ; j >= 0 ; --j){
  	printf("%d", array[j] );
  }
}