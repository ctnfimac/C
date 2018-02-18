//gcc main.c -o main.out
#include <stdio.h>
#include <stdlib.h>
#include "poligonos.h"

int main(){
 
 int nlados;
 float vlado ;
 char* name_poligonos;

 system("cls");
 printf("\n\n\n/************************************************************************/\n\n");
 printf("Programa para Calcular el tipo de Poligono regulares, area y perimetro\n");
 printf("\n/**************************************************************************/\n\n\n");
 
 printf("Ingrese la cantidad de lados del poligono (minimo 3 lados, maximo 15 lados): ");
 scanf("%d", &nlados);

 printf("Ingrese la medida del lado del poligono: ");
 scanf("%f", &vlado);

 if( nlados >= 3 && nlados <= 15){

    printf("\nTipo de poligono con %d lados: %s\n", nlados, tipoPoligono(nlados));
    printf("\nSumatoria de angulos internos: %f\n", sumAngulosInternos(nlados));
    printf("\nValor de los angulos internos del poligono: %f\n", valAnguloInterno(sumAngulosInternos(nlados),nlados) );
    printf("\nPerimetro del poligono: %f\n", perimetroPoligono(nlados,vlado));
    printf("\nArea del poligono: %f\n", areaPoligono(perimetroPoligono(nlados,vlado),nlados));
 }else{
 	printf("\nLa cantidad de lados ingresada es incorrecta\n");
 }
 //printf("%d\n", nlados);

 return(0);		
}