//gcc main.c -o main.out
//gcc -o miexe main.c

/*EJECUTABLE CUANDO HAY VARIOS ARCHIVOS
Compilacion:

gcc -c miarchivo1.c          --> Esto genera miarchivo1.o
gcc -c miarchivo2.c          --> Esto genera miarchivo1.o
           .
           .
           .
gcc -c miarchivoN.c          --> Esto genera miarchivoN.o


Linkeo:

gcc -o nombre_del_ejecutable miarchivo1.o miarchi2.o ... miarchvoN.o    --> Esto linkea los *.o en un ejecutable!

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "triangulo.h"


int main(){
	system("cls");
	printf("\n\n\n/************************************************************************/\n\n");
    printf("Programa para Calcular el tipo de triangulo, area y perimetro\n");
    printf("\n/************************************************************************\n\n\n");

    float lado_a, lado_b, lado_c, area, perimetro, angulo_a, angulo_b, angulo_c , altura ;
    float numerador, denominador, cociente , aux;
    int flag = 0 ;

    printf("\nIngrese lado_a :");
    scanf("%f",&lado_a);

    printf("\nIngrese lado_b :");
    scanf("%f",&lado_b);

    printf("\nIngrese lado_c :");
    scanf("%f",&lado_c);
    
    if( verificaFigura( lado_a , lado_b, lado_c) != 1 ){
    	printf("\nLas medidas de los lados ingresados no pertenecen a un triangulo\n");
    }else{
    	//printf("\nEs un triangulo \n");
    	switch(tipoDeTriangulo( lado_a , lado_b, lado_c)){
    		case 0 :
    		 	printf("ERROR!!!\n");
    			break;
    		case 1 :
    			printf("\ntipo de triangulo segun sus lados: equilatero\n");
    			printf("\nEl area del triangulo es: %f \n",areaTriangulo(lado_a, lado_b, lado_c, 1) );
    			break;
    		case 2 :
    		    printf("\ntipo de triangulo segun sus lados: isosceles\n");
    		    printf("\nEl area del triangulo es: %f \n", areaTriangulo(lado_a, lado_b, lado_c, 2) );
    			break;
    		case 3 :
    		    printf("\ntipo de triangulo segun sus lados: escaleno\n");
    			printf("\nEl area del triangulo es: %f \n", areaTriangulo(lado_a, lado_b, lado_c, 3) );
    			break;
    		default:
    			break;
    	}
    	printf("\nEl perimetro del triangulo es: %f \n", perimetroTriangulo(lado_a, lado_b, lado_c) );
    }
  
    system("pause");
	return(0);
}

