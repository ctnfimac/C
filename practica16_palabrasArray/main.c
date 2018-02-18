//gcc main.c -o main.out

/*
  @author: christian peralta
 http://maxus.fis.usal.es/fichas_c.web/08xx_PAGS/0801.html
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int datos[2][2];
char palabras[3][10];

int **ptr;
char **ptrc;

int main(void){
	int i;
    // para matriz de enteros
    datos[0][0] = 1 ;
    datos[0][1] = 2 ;
    datos[1][0] = 3 ;
    datos[1][1] = 4 ;

    
   

	ptr = (int **) malloc(sizeof(int*) * 2);//filas
   
	for( i = 0 ; i < 2 ; i++ ){
		ptr[i] = (int *)malloc(sizeof(int) * 2);//columnas
	}
	*ptr = &datos[0][0];
  	
  	printf("Valores de la matriz datos\n");
    for(i = 0 ; i < 4 ; i++)
      printf("ptr: %d\n", *(*ptr + i));
    
    // ***********para matriz de caracteres*************

    /*gets(palabras[0]);
    gets(palabras[1]);
    gets(palabras[2]);*/

    strcpy(palabras[0],"Christian");//10
    strcpy(palabras[1],"peralta");//8
    strcpy(palabras[2],"Fi-MaC");//7

  	ptrc = (char **)malloc(sizeof(char *) * 3);//filas
  	
  	ptrc[0] = (char *)malloc(sizeof(char)*10);//columnas
  	ptrc[1] = (char *)malloc(sizeof(char)*10);
  	ptrc[2] = (char *)malloc(sizeof(char)*10);
  	//*ptrc = &palabras[0][0];
  	strcpy((*ptrc) , "Christian");
  	strcpy((*ptrc+10) , "Peralta");
  	strcpy((*ptrc+20) , "Fi-MaC");

    //puts(palabras[0]);
    //puts(palabras[1]);
    //puts(palabras[2]);
  	//printf("%s\n",palabra[0]);
    //printf("palabra: %s\n", *(ptrc));
    /*printf("palabra: %s\n", *(ptrc+1));
    printf("palabra: %s\n", *(ptrc+2));*/
    printf("Valores de la matriz palabras\n");
    //for(i = 0 ; i < 3 ; i++)
    printf("ptrc: %s\n", *ptrc); 
   // printf("ptrc: %s\n", palabras[0]);
    printf("ptrc: %s\n", (*ptrc+10)); 
   // printf("ptrc: %s\n", palabras[1]);
    printf("ptrc: %s\n", (*ptrc+20)); 
    //printf("ptrc: %s\n", palabras[2]);  */
    //puts(*(ptrc + i));
    //puts(palabras[1]);
    //puts(palabras[2]);
	return 0;
}