//gcc practica1.c -o practica1.out

#include<stdio.h>


int main(){
  char nombre[15] , website[20];
  printf("Ingrese su Nombre: ");
  scanf("%s",nombre);

  printf("Ingrese el nombre de su sitio Web: ");
  scanf("%s" ,website);

  printf("Hola %s\n" , nombre);
  printf("su sitio web es: %s", website);
  
  return(0);
}