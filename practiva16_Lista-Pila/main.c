//gcc main.c -o main.out

/*
  @author: christian peralta

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Lista Lista;
typedef struct Nodo Nodo;

struct Lista
{
	Nodo *raiz;	
};

struct Nodo
{
	int info;
    Nodo *sig;
};

Lista *lista_nueva(void);
void lista_agregar(Lista *n, int dato);
int lista_extraer(Lista *n);

int main(void){
	Lista *milista;
	system("cls");
	milista = lista_nueva();
	/*if(milista != NULL) printf("No es null\n");
	else printf("Es null\n");*/
	lista_agregar( milista, 4);
	printf("%d\n", milista->raiz->info);
	lista_agregar( milista, 10);
	printf("%d\n", milista->raiz->info);
	printf("%d\n", milista->raiz->sig->info);

	printf("Valor extraido: %d\n", lista_extraer(milista));
	printf("Valor extraido: %d\n", lista_extraer(milista));
	/*if(milista != NULL) printf("No es null\n");
	else printf("Es null\n");*/
	//printf("%d\n", milista->info);
	free(milista);
	milista = NULL;
	return 0;
}


Lista *lista_nueva(void){
	Lista *L;
	L = (Lista *) malloc(sizeof(Lista));
	L->raiz = NULL;
	return L;
}

void lista_agregar(Lista *L, int dato){

	Lista *n;

	if( L->raiz == NULL ){
		L->raiz = (Nodo *) malloc(sizeof(Nodo));
		L->raiz->info = dato;
		L->raiz->sig = NULL;
	}else{
		n = L;
		printf("Ya no es null\n");
		//printf("%d\n", n->raiz->info );
		n->raiz->sig = (Nodo *)malloc(sizeof(Nodo));
		n->raiz->sig = L->raiz;
		n->raiz->info = dato;
		printf("%d\n", n->raiz->info );
		L = n;
	}
}


int lista_extraer(Lista *L){
	int dato;
	Lista *n;
	dato = L->raiz->info;
    

	n->raiz = (Nodo *) malloc(sizeof(Nodo));
	n->raiz = L->raiz->sig;

	printf("nueva info:%d\n", n->raiz->sig->info);
	printf("nueva info:%d\n", n->raiz->info);
	//n = L->raiz->sig;

	
	return dato;
}