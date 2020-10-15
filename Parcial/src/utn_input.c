/*
 ============================================================================
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */
/*Prototipo con resumen rapido
 int utn_getInt(int* pResultado); //utilizada en utn_getNumero
 int utn_verificadorDeNumeros(char* cadena,int limite);//utilizada en utn_getInt
 int utn_myGets(char* cadena,int longitud);//utilizada en utn_getInt, utn_getFloat y utn_getString
 int utn_getFloat(float* pFloat);// utilizada en utn_getNumeroFloat
 int utn_esFlotante(char* array,int limite); // utilizada en utn_getFloat
 int utn_getString(char* pResultado,int longitud); //utilizada en utn_getCadena
 int utn_esSoloLetras(char* pResultado,int limite); //utilizada en utn_getString
 int utn_esAlfaNumerica(char* pResultado);
 int utn_esTelefono(char str[]);
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <conio.h>
#include "utn_input.h"

/*
 * utn_getNumero : pide al usuario un numero entero
 * pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * mensaje : El mensaje que imprime para pedir un valor.
 * mensajeError: El mensaje que imprime si el rango no es valido.
 * minimo : valor minimo valido (inclusive)
 * maximo : valor maximo valido (inclusive)
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */
int utn_getNumero(char* mensaje,char* mensajeError,int* pResultado,int minimo,int maximo,int reintentos)
{
  int retorno = -1;
  int bufferInt;
  int resultadoScan;

  if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
      && minimo <= maximo && reintentos > 0)
    {
      do
	{
	  printf ("%s", mensaje);
	  fflush (stdin);
	  resultadoScan = utn_getInt (&bufferInt);
	  if (resultadoScan == 1 && bufferInt >= minimo && bufferInt <= maximo)
	    {
	      *pResultado = bufferInt;
	      retorno = 0;
	      break;
	    }
	  else
	    {
	      reintentos--;
	      if (reintentos != 0)
		{
		  printf ("\nQUEDAN [%d] REINTENTOS\n", reintentos);
		  printf ("%s", mensajeError);
		}
	    }
	}
      while (reintentos != 0);
    }
  return retorno;
}

//=============================================================================================================
/*
 * utn_getNumeroLong : pide al usuario un numero entero
 * pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * mensaje : El mensaje que imprime para pedir un valor.
 * mensajeError: El mensaje que imprime si el rango no es valido.
 * minimo : valor minimo valido (inclusive)
 * maximo : valor maximo valido (inclusive)
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 **/

int utn_getNumeroLong(char* mensaje,char* mensajeError,long long int* pResultado,long long int minimo,long long int maximo,int reintentos)
{
  int retorno = -1;
  long long int bufferInt;
  int resultadoScan;

  if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
    {
      do
	{
	  printf ("%s", mensaje);
	  fflush (stdin);
	  resultadoScan = utn_getIntLong (&bufferInt);
	  if (resultadoScan == 1 && bufferInt >= minimo && bufferInt <= maximo)
	 //   if (resultadoScan == 1)
	    {
	      *pResultado = bufferInt;
	      retorno = 0;
	      break;
	    }
	  else
	    {
	      reintentos--;
	      if (reintentos != 0)
		{
		  printf ("\nQUEDAN [%d] REINTENTOS\n", reintentos);
		  printf ("%s", mensajeError);
		}
	    }
	}
      while (reintentos != 0);
    }
  return retorno;
}

//=============================================================================================================
/**
* esNumerica: Verifica si la cadena ingresada es numerica
* cadena: cadena de caracteres a ser analizada
* limite: limite de la cadena
* Retorno: 1 (verdadero) si la cadena es numerica , 0 (falso) si no y -1 en caso de ERROR de parametro
*
*/
 int utn_verificadorDeNumeros (char *pResultado, int longitud)
{
  int retorno;
  int i = 0;

  if (pResultado != NULL && longitud >0)
    {
      if(pResultado[0] == '-')
      		{
      			i = 1;
      		}
      for (;pResultado[i] != '\0'; i++)
	{
	  if (pResultado[i] >= '0' && pResultado[i] <= '9')
	    {
	      retorno = 0;
	    }
	  else
	    {
	      retorno = -1;
	      break;
	    }
	}
    }
  return retorno;
}

//=============================================================================================================
/*
 * utn_getInt: pide un texto al usuario, lo almacena como cadena, valida y convierte el texto a numero y lo devuelve como int
 * presultado: puntero numero entero
 * Retorno: devuelve un 1 si esta todoOK. Devuelve 0 si hubo un error.
 *
 */
 int utn_getInt(int* pResultado)
{
	int retorno = 0;
	char buffer[64];
	if(pResultado != NULL){

		if(utn_myGets(buffer,sizeof(buffer)) != -1 && utn_verificadorDeNumeros(buffer,sizeof(buffer)) != -1){
			*pResultado = atoi(buffer);
			retorno = 1;
		}
	}
	return retorno;
}


 //=============================================================================================================
 /*
  * utn_getIntLong: pide un texto al usuario, lo almacena como cadena, valida y convierte el texto a numero y lo devuelve como int
  * presultado: puntero numero entero
  * Retorno: devuelve un 1 si esta todoOK. Devuelve 0 si hubo un error.
  *
  */

 int utn_getIntLong(long long int* pResultado)
{
	int retorno = 0;
	char buffer[30];
//	long long int prueba;
	if(pResultado != NULL){

		if(utn_myGets(buffer,sizeof(buffer)) != -1 && utn_verificadorDeNumeros(buffer,sizeof(buffer)) != -1){

		    *pResultado = atoll(buffer);
		     retorno = 1;


		}
	}
	return retorno;
}



//=============================================================================================================
/**
* utn_myGets: Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un máximo de ' longitud - 1' caracteres .
* cadena: Puntero al espacio de memoria donde se copiara la cadena obtenida
* longitud:  Define el tamaño de cadena
* Retorno: 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*
*/
int utn_myGets(char* cadena, int longitud)
{
	int retorno = 1;
	char bufferString[longitud];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}

			if(strlen(bufferString) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}

//=============================================================================================================
/*
 * utn_getNumeroFloat : Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * mensaje : El mensaje que imprime para pedir un valor.
 * mensajeError: El mensaje que imprime si el rango no es valido.
 * minimo : valor minimo valido (inclusive)
 * maximo : valor maximo valido (inclusive)
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */
int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
  int retorno = -1;
  float bufferFloat;
  int resultadoScan;

  if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
      && minimo <= maximo && reintentos > 0)
    {
      do
	{
	  printf ("%s", mensaje);
	  fflush (stdin);
	  resultadoScan = utn_getFloat (&bufferFloat);
	  if (resultadoScan != -1 && bufferFloat >= minimo && bufferFloat <= maximo)
	    {
	      *pResultado = bufferFloat;
	      retorno = 0;
	      break;
	    }
	  else
	    {
	      reintentos--;
	      if (reintentos != 0)
		{
		  printf ("\nQUEDAN [%d] REINTENTOS\n", reintentos);
		  printf ("%s", mensajeError);
		}
	    }
	}
      while (reintentos != 0);
    }
  return retorno;
}
//=============================================================================================================
/*
 * utn_getFloat: verifica si la cadena ingresada es flotante
 * pFloat: puntero numero float
 * Retorno: devuelve un 1 si esta todoOK. Devuelve 0 si hubo un error.
 *
 */
 int utn_getFloat(float* pFloat)
{
	int retorno = -1;
	char bufferFloat[64];

	if(pFloat != NULL){
		fflush(stdin);
		if(!utn_myGets(bufferFloat,sizeof(bufferFloat)) && utn_esFlotante(bufferFloat,sizeof(bufferFloat))!=-1)
		  {
			*pFloat = atof(bufferFloat);
			retorno = 0;
		}
	}

	return retorno;
}

//=============================================================================================================
/*
 * utn_esFlotante: Verifica si la cadena ingresada es flotante
 * cadena: cadena de caracteres a ser analizada
 * limite: limite de la cadena
 * Retorno: 1 (verdadero) si la cadena es flotante , 0 (falso) si no y -1 en caso de ERROR de parametro
 *
 */
 int utn_esFlotante(char* array,int limite)
{
  int retorno = 0;
  int i = 0;
  int contador = 0;

  if (array != NULL && limite >0)
    {
      if(array[0] == '-')
      		{
      			i = 1;
      		}
      for (; array[i] != '\0'; i++)
	{
	  if(array[i] == '.')
	    {
	      contador++;
	     }
	  if ((array[i] >= '0' && array[i] <= '9' && contador <= 1) || array[i] <= '.' )
	    {
	      retorno = 0;
	    }
	  else
	    {
	      retorno = -1;
	      break;
	    }
	}
    }
  return retorno;
}

//=====================================================================================
/*
 * utn_esSoloLetras: Recibe una cadena de caracteres y devuelve 1 en caso de que el texto este compuesto solo por letras y/o espacio
 * pResultado: cadena de caracteres
 * Retorno: devuelve un 1 si esta todoOK. Devuelve 0 si hubo un error.
 *
 */
 int utn_esSoloLetras(char* pResultado,int limite)
{
	int retorno = 0;
	int i= 0;
	int contador = 0;
	if(pResultado != NULL && limite > 0)
	  {

	    do{
			if((pResultado[i] < 'a' || pResultado[i] > 'z') && (pResultado[i] < 'A' || pResultado[i] > 'Z') && pResultado[i] != ' ')
			{
			    retorno =  -1;
				break;
				contador ++;
			}


		i++;
	    }while(i <= limite && pResultado[i] != '\0');
	 }
	/*printf("\n LO QUE DEVUELVE EL [contadorIteracion] DE utn_esSoloLetras: %d\n",contadorEo());
	printf("\n LO QUE DEVUELVE EL [CONTADOR] DE utn_esSoloLetras: %d\n",contador);
	printf("\n LO QUE DEVUELVE EL [RETORNO] DE utn_esSoloLetras: %d\n",retorno);*/

	return retorno;
}

//=====================================================================================
/*
 * utn_getString: pide un texto al usuario, lo almacena como cadena, valida y lo devuelve
 * presultado: puntero a  array de caracter
 * longitud: tamaño del array
 * Retorno: devuelve un 1 si esta todoOK. Devuelve 0 si hubo un error.
 *
 */
 int utn_getString(char* pResultado,int longitud)
{
  int retorno = 0;
  char buffAux[1000];
  if (pResultado != NULL && longitud > 0)
    {
      fflush (stdin);
      if (utn_myGets (buffAux, sizeof(buffAux)) != -1)
	{
	  strncpy (pResultado, buffAux, longitud);
	  retorno = 1;
	}
    }
  return retorno;
}

//=====================================================================================
/*
 * utn_esAlfaNumerica: Recibe una cadena de caracteres y devuelve 1 en caso de que el texto este compuesto solo por letras y/o espacio y/o numeros
 * pResultado: cadena de caracteres
 * Retorno: devuelve un 1 si esta todoOK. Devuelve 0 si hubo un error.
 *
 */

int utn_esAlfaNumericoSinCaracteres(char* pResultado)
{
  int retorno = 1;
  int i;

  if (pResultado != NULL)
    {
      for (i = 0; pResultado[i] != '\0'; i++)
	{
	  if ((pResultado[i] != ' ')
	      && (pResultado[i] < 'a' || pResultado[i] > 'z')
	      && (pResultado[i] < 'A' || pResultado[i] > 'Z')
	      && (pResultado[i] < '0' || pResultado[i] > '9'))
	    {
	      retorno = 0;
	      break;
	    }
	}
    }
  return retorno;
}

//=====================================================================================
/*
 * \brief 	inicializa un array de flotantes
 * \param pArray Puntero al array
 * \param longitud Define el tamaño del array
 * \param valorInicial Es el valor a ser cargado en todas las posiciones del array
 * \returtn retorna 0 {EXITO} o -1 {ERROR}
 */
int utn_initArrayFlotante(float pArray[],int longitud, float valorInicial)
{
  int retorno = -1;
  int i;

  if (pArray != NULL && longitud > 0)
    {
      for (i = 0; i < longitud; i++)
	{
	  pArray[i] = valorInicial;
	}
      retorno = 0;
    }
  return retorno;
}

//=====================================================================================
/*
 * \brief 	inicializa un array de enteros
 * \param pArray Puntero al array
 * \param longitud Define el tamaño del array
 * \param valorInicial Es el valor a ser cargado en todas las posiciones del array
 * \returtn retorna 0 {EXITO} o -1 {ERROR}
 */
int utn_initArrayEntero(int pArray[],int longitud, int valorInicial)
{
  int retorno = -1;
  int i;

  if (pArray != NULL && longitud > 0)
    {
      for (i = 0; i < longitud; i++)
	{
	  pArray[i] = valorInicial;
	}
      retorno = 0;
    }
  return retorno;
}

//=====================================================================================
/*
 * \brief 	imprime un array de flotantes
 * \param pArray Puntero al array
 * \param longitud Define el tamaño del array
 * \returtn retorna 0 {EXITO} o -1 {ERROR}
 */
int utn_imprimeArrayFlotante(float pArray[],int longitud)
{
  int retorno = -1;
  int i;

  if (pArray != NULL && longitud > 0)
    {
      for (i = 0; i < longitud; i++)
	{
	  printf ("\nIndice: [%d] - Valor: %.2f", i, pArray[i]);
	}
      retorno = 0;
    }
  return retorno;
}

//=====================================================================================
/*
 * \brief 	imprime un array de enteros
 * \param pArray Puntero al array
 * \param longitud Define el tamaño del array
 * \returtn retorna 0 {EXITO} o -1 {ERROR}
 */
int utn_imprimeArrayEntero (int pArray[], int longitud)
{
  int retorno = -1;
  int i;

  if (pArray != NULL && longitud > 0)
    {
      for (i = 0; i < longitud; i++)
	{
	  printf ("\nIndice: [%d] - Valor: %d", i, pArray[i]);
	}
      retorno = 0;
    }
  return retorno;
}

//=====================================================================================
//Metodo optimizado
/*
 *brief  Imprime a modo DEBUG la informacion de un array de enteros
 *param  miArray Es el puntero al arrary ser ordenado
 *param  SIZE Es la longitud del array
 *return 0 si es ok o -1 para indicar error
 */
int utn_ordenarArray (int miArray[], int SIZE)
{
  int flagSwap;
  int i;
  int contador = 0;
  int retorno = -1;
  int buffer;
  int nuevoLimite;

  if (miArray != NULL && SIZE >= 0)
    {
      nuevoLimite = SIZE - 1;
      do
	{
	  flagSwap = 0;
	  for (i = 0; i < nuevoLimite; i++)
	    {
	      contador++;
	      if (miArray[i] < miArray[i + 1])
		{
		  flagSwap = 1;
		  buffer = miArray[i];
		  miArray[i] = miArray[i + 1];
		  miArray[i + 1] = buffer;
		}
	    }
	  nuevoLimite--;
	}
      while (flagSwap);
      retorno = contador;
    }
  return retorno;
}

//=====================================================================================
/**
 * \brief Verifica si el valor recibido contiene solo numeros, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int utn_esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}


//=====================================================================================
/*
 * utn_getNombre : pide al usuario un numero nombre
 * pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * mensaje : El mensaje que imprime para pedir un nombre.
 * mensajeError: El mensaje que imprime si el nombre no es valido.
 * longitud: la longitud del array
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un nombre valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */

int utn_getNombre (char *mensaje, char *mensajeError, char *pNombre, int longitud, int reintentos)
{
  char auxiliar[longitud];
  int retorno = -1;
  if (mensaje != NULL && mensajeError != NULL && pNombre != NULL && longitud > 0
      && reintentos > 0)
    {
      do
	{
	  printf (mensaje);
	  fflush (stdin);
	  if (utn_getString (auxiliar, longitud) != -1 && utn_esSoloLetras (auxiliar, longitud) != -1)
	    {
	      strncpy (pNombre, auxiliar, longitud);
	      retorno = 0;
	      break;
	    }
	  else
	    {
	      reintentos--;
	      if (reintentos != 0)
		{
		  printf ("\nQUEDAN [%d] REINTENTOS\n", reintentos);
		  printf ("%s", mensajeError);
		}
	    }
	}
      while (reintentos != 0);
    }
  return retorno;
}
//=====================================================================================
/*
 * utn_getNombre : pide al usuario un numero nombre
 * pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * mensaje : El mensaje que imprime para pedir un nombre.
 * mensajeError: El mensaje que imprime si el nombre no es valido.
 * longitud: la longitud del array
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un nombre valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */

int utn_getAlfanumerico (char *mensaje, char *mensajeError, char *pNombre, int longitud, int reintentos)
{
  char auxiliar[longitud];
  int retorno = -1;
  if (mensaje != NULL && mensajeError != NULL && pNombre != NULL && longitud > 0
      && reintentos > 0)
    {
      do
	{
	  printf (mensaje);
	  fflush (stdin);
	  if (utn_getString (auxiliar, longitud) != -1)
	    {
	      strncpy (pNombre, auxiliar, longitud);
	      retorno = 0;
	      break;
	    }
	  else
	    {
	      reintentos--;
	      if (reintentos != 0)
		{
		  printf ("\nQUEDAN [%d] REINTENTOS\n", reintentos);
		  printf ("%s", mensajeError);
		}
	    }
	}
      while (reintentos != 0);
    }
  return retorno;
}




//=====================================================================================
/*
 * utn_getAceptaRechaza : pide al usuario rechazar o aceptar
 * mensaje : El mensaje que imprime para pedir aceptar o rechazar.
 * mensajeError: El mensaje que imprime si el inngreso es invalido.
 * yes: parametro de entrada
 * no: parametro de entrada
 * Retorno: devuelve 1 o 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */

int utn_getAceptaRechaza (char *mensaje, char *mensajeError, char yes, char no)
{
  char entrada;
  int retorno = -1;

  printf (mensaje);
  do
    {
      fflush (stdin);
      if (scanf ("%c", &entrada) != 0)
	{
	  entrada = tolower (entrada);
	  if (entrada == yes || entrada == no)
	    {
	      switch (entrada)
		{
		case 's':
		  retorno = 1;
		  break;
		case 'n':
		  retorno = 0;
		  break;
		}
	    }
	  else
	    {
	      printf (mensajeError);
	      printf (mensaje);
	    }
	}
    }
  while (retorno == -1);
  return retorno;
}


//=====================================================================================
/*
 * idIncremental : Incrementa la variable estatica
 * -
 *
 * Retorno: -
 *
 */
int utn_idIncremental(void)
{
    static int id = 0;
    id++;
    return id;
}
//=====================================================================================
/*
 * idIncremental : Incrementa la variable estatica
 * -
 *
 * Retorno: -
 *
 */
int utn_idIncremental2(void)
{
    static int id2 = 0;
    id2++;
    return id2;
}


