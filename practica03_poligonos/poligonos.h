#include <math.h>

#define N_POLIGONOS 13

char* tipoPoligono (int nlados);
float sumAngulosInternos(int nlados);
float perimetroPoligono(int nlados, float val_lados);
float areaPoligono(float perimetro, float val_lados);

 char* palabra[N_POLIGONOS] = {"Triangulo", "Cuadrilatero", "Pentagono",
                               "Hexagono", "Heptagono", "Octagono",
                                "Eneagono", "Decagono", "Endecagono", "Dodecagono", 
                                "Tridecagono", "Tetradecagono", "Pentadecagono"};




/*--------------------------------------------------------------------
	regresa el nombre del poligono segun su cantidad de lados
/*--------------------------------------------------------------------*/
char* tipoPoligono (int nlados){
  	return palabra[nlados-3];
}




/*--------------------------------------------------------------------
   regresa el valor de la sumatoria de los angulos internos del poligono
/*--------------------------------------------------------------------*/
float sumAngulosInternos(int nlados){
   float sAngulosInternos;

   sAngulosInternos = 180 * ( nlados - 2 );
   return sAngulosInternos;
}

/*--------------------------------------------------------------------
   regresa el valor del angulo interno del poligono
/*--------------------------------------------------------------------*/
float valAnguloInterno( float sum , int nlados){
	return (sum / nlados) ;
}

/*--------------------------------------------------------------------
   regresa el perimetro del poligono
/*--------------------------------------------------------------------*/
float perimetroPoligono(int nlados, float val_lados){
	return (nlados * val_lados);
}

/*--------------------------------------------------------------------
   regresa el area del poligono
/*--------------------------------------------------------------------*/
float areaPoligono(float perimetro, float val_lados){
	float apotema;

	apotema = pow( pow(val_lados,2) - pow(val_lados/2,2) , 0.5);
	return ( (perimetro * apotema) / 2 );
}