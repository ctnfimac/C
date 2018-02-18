
int verificaFigura( float a , float b, float c);
int tipoDeTriangulo( float a , float b, float c);
float perimetroTriangulo(float a , float b, float c);
float areaTriangulo(float a , float b, float c, int tipo);



/*--------------------------------------------------------------------
	si regresa 1 es un triangulo equilatero
	si regresa 2 es un triangulo isosceles
	si regresa 3 es un triangulo escaleno
	si regresa 0 hay algun error
/*--------------------------------------------------------------------*/
int tipoDeTriangulo( float a , float b, float c){
	int dato = 0 ;

	if( a == b && a == c ){
		dato = 1 ;
	}else if(a == b && a != c || a == c && a != b || b == c && b != a  ){
		dato = 2 ;
	}else if( a!=b & b!=c ){
		dato = 3 ;
	}
	return dato;
}


/*--------------------------------------------------------------------
	si regresa 1 es un triangulo 
	si regresa 0 no es un triangulo
/*--------------------------------------------------------------------*/
int verificaFigura( float a , float b, float c){
	int dato ;
	dato = ( (a + b) > c  &&  (a + c) > b  && (b + c) > a )?  1 : 0 ;
	return dato;
}


/*--------------------------------------------------------------------
	devuelve el perimetro de un triangulo
/*--------------------------------------------------------------------*/
float perimetroTriangulo(float a , float b, float c){
	return a + b + c ;
}




/*--------------------------------------------------------------------
	devuelve el área de un triangulo
/*--------------------------------------------------------------------*/
float areaTriangulo(float a , float b, float c, int tipo){
 float area , s ;
  switch(tipo){
  	
  	case 1:
       area = ( a * b) / 2 ;
  	   break;
  	
  	case 2:
  	   if( a == b){
          s = pow( pow(a,2) - pow(c/2,2), 0.5);
    	  area = (c * s )/2;
    	}else if( a == c ){
    	  s = pow( pow(a,2) - pow(b/2,2),0.5);
    	  area = (b * s )/2;
        }else if( b == c ){
    	  s = pow( pow(b,2) - pow(a/2,2),0.5);
    	  area = (a * s )/2;
        }
  	   break;

  	 case 3:
  	    //para el area uso la formula de herón
  	    s = (a + b + c) / 2 ; //no es la s
        area = pow( s * ( s - a ) *( s - b ) * ( s - c ), 0.5 );
  	 	break;
  	 default:
  	 	break;
  }

  return area;
}