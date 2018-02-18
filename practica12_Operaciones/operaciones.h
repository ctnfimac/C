/*-------------------------------------------------------------------------

 Prototipos de funciones

 -------------------------------------------------------------------------*/

int operacion( int(*calculo)(int, int), int a , int b);
int suma(int a, int b);
int resta(int a, int b);
int multiplicacion(int a, int b);
int division(int a, int b);



/*-------------------------------------------------------------------------

 regresa operacion indicada en calculo

 -------------------------------------------------------------------------*/
int operacion( int(*calculo)(int, int), int a , int b)
{
  int resultado;
  resultado = calculo(a,b);
  return resultado;
}




/*-------------------------------------------------------------------------

 regresa la suma de dos numeros enteros

 -------------------------------------------------------------------------*/
int suma(int a, int b)
{
	return ( a + b );
}


/*-------------------------------------------------------------------------

 regresa la resta de dos numeros enteros

 -------------------------------------------------------------------------*/
int resta(int a, int b)
{
 	return ( a - b );
}


/*-------------------------------------------------------------------------

 regresa la multiplicacion de dos numeros enteros

 -------------------------------------------------------------------------*/
int multiplicacion(int a, int b)
{
	return ( a * b );
}


/*-------------------------------------------------------------------------

 regresa la division de dos numeros enteros

 -------------------------------------------------------------------------*/
int division(int a, int b)
{
	return ( a / b );
}



