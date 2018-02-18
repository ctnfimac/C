//gcc main.c -o main.out

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRADO_MAX 4

int main(void){

	int grado , i = 0, coeficientes[GRADO_MAX], raiz ,resto = 0 ;

	system("cls");
	printf("/-------------------------------------------------------------------------\n");
	printf("\n  Calcular El resto de un polinomio del tipo:  \n\n");
	printf("                r(x) =  ax^n + bx^(n-1) + ...... +cx^0 \n");
	printf("                        -------------------------------\n");
	printf("                                  x - a \n\n");
	printf("/-------------------------------------------------------------------------*/\n");
	
	printf("\n Ingrese el grado del polinomio:");
	scanf("%d",&grado);
	for( i ; i <= grado; i++){
		printf("ingrese coficiente del termino ax^%d:" , i );
		scanf("%d", &coeficientes[i]);
	}
    
    printf("Ingrese el termino independiente (a) del divisor: ");
    scanf("%d",&raiz);


    //calculo resto

    if( raiz == 0 ) resto = coeficientes[0];
    else {
    	for( i = 0 ; i <= grado ; i++)
    	   resto = resto + coeficientes[i] * pow(raiz,i);
    }
    
    printf("El resto es= %d\n", resto);
   
	return 0;
}