/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================

 */
#include "arrayPublicacion.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <conio.h>
#include "utn_input.h"




/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int publicacion_initArray(Publicacion list[], int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		    list[i].isEmpty = TRUE;/////////NO TOCAR////////
		    list[i].id = 0;/////////NO TOCAR////////
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		    list[i].idCliente = 0;/////////NO TOCAR////////
		    list[i].numeroRubro = 0;
		    list[i].estPubli = -1;
		    strcpy(list[i].descripcionEstado,"PAUSADO");
		    strcpy(list[i].texto,"VACIO");
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		}
		retorno = 0;
	}
	return retorno;
}



/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int publicacion_addArray(Publicacion* list, int len, int id,
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		      int idCliente,
      		      int numeroRubro,
   		          int estPubli,
				  char* descripcionEstadoPubli,
				  char* texto
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		      )
{
  int i;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (publicacion_isEmpty (list, len, i) == 1)
	    {
	      list[i].id = id;
	      list[i].isEmpty = FALSE;
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      list[i].idCliente = idCliente;/////////NO TOCAR////////
	      list[i].numeroRubro = numeroRubro;
          list[i].estPubli = estPubli;
          strcpy(list[i].descripcionEstado,descripcionEstadoPubli);
          strcpy(list[i].texto,texto);


////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      return 0;
	    }
	}
    }
  return -1;
}




/*
 * headerEmployee : Imprimie en una linea
 * -
 *
 * Retorno: -
 *
 */
void publicacion_headerArray(void)

{
    printf("\n"
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	    "%*s"
	    "%*s"
	    "%*s"
	    "%*s"
    	"%*s"
	    "%*s",
	   -5, " ID",
	   -13, " ID CLIENTE",
	   -14," NUM RUBRO",
	   -12," ESTADO PUBL.",
	   -12," DESC EST. PUBL.",
	   -12," TEXTO"
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	   "\n-----------------------------------------------------\n");
}



/** \brief imprime el array a partir del id
 *
 * \param list Employee*
 * \param length int
 * \param id int
 * \return 0 si esta ok - -1 si no
 *
 */
int publicacion_printForId  (Publicacion *list, int len, int id)
{
  int retorno = -1;
  int i;
  	if(list != NULL && len > 0)
  	{
  	    publicacion_headerArray();
  		for( i=0;i<len;i++)
  		{
  			if(list[i].id == id && list[i].isEmpty == FALSE &&
  			    ///Se agrega una condicion mas por si lo que trae es basura
  			    list[i].estPubli != -1)
  			{
  				printf(
//  				       " %-6d "
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
  				       "%-12d " ///NO TOCAR///////
  				       "%-12d "
  				       "%-10d "
  				       "%-13d "
  					   "%-13s "
  				       "%-13s "
  				       "\n"

  				 //   ,list[i].isEmpty
  				   ,list[i].id ///NO TOCAR///////
				   ,list[i].idCliente
				   ,list[i].numeroRubro
				   ,list[i].estPubli
				   ,list[i].descripcionEstado
				   ,list[i].texto


////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
				    );
  			}
  		}
  		retorno = 0;
  	}
 return retorno;
}




/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int publicacion_removeArray(Publicacion* list, int len, int id)
{
  int i;
  int retorno;

  if (list != NULL && len > 0 && id > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].id == id)
	    {
	      list[i].isEmpty = TRUE;
	      strcpy(list[i].descripcionEstado,"PAUSADA");
	      list[i].estPubli = -1;
	      retorno = 0;
	    }
	}
    }
 return retorno;
}




/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int publicacion_findArrayById (Publicacion *list, int len, int id)
{
  int i;
  int retorno = -1;

  if (list != NULL && len > 0 && id != 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].id == id)
	    {
	      retorno = id;
	      break;
	    }
	}
    }
return retorno;
}





/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
/*
int publicacion_sortArray(Publicacion* list, int len, int order)
{
  int flagSwap;
  int i;
  int contador = 0;
  int retorno = -1;
  Publicacion buffer;
  int nuevoLimite;

  if (list != NULL && len >= 0)
    {
      nuevoLimite = len - 1;
      do
	{
	  flagSwap = 0;

	  for (i = 0; i < nuevoLimite; i++)
	    {
	      contador++;
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      if ((order == 0 && strcmp (list[i].NOMBRE1, list[i + 1].NOMBRE1) < 0)||
		  (order == 1 && strcmp (list[i].NOMBRE1, list[i + 1].NOMBRE1) > 0))
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		  //*******************En caso de ordenamiento por 2 condiciones, descomentar lo de abajo
//		  ||(0==strcmp (list[i].lastName, list[i + 1].lastName) &&
//		      (((list[i].sector > list[i + 1].sector)&&(order == 1))
//			  ||((list[i].sector < list[i + 1].sector) &&(order == 0)))))
		{
		  flagSwap = 1;
		  buffer = list[i];
		  list[i] = list[i + 1];
		  list[i + 1] = buffer;
		}
	    }
	  nuevoLimite--;
	}
      while (flagSwap);
      retorno = contador;
    }
  return retorno;
}
*/


/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int publicacion_printArray(Publicacion* list, int length)
{
	int retorno = -1;
	if(list != NULL && length > 0)
	{
		for(int i=0;i<length;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf(
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
				  //  " %-6d "
				    " %-6d "/////////NO TOCAR//////////////
				    " %-10d "
				    "%-12d "
					"%-12d "
					"%-15s "
					"%-13s "
				    " \n"

				  //  ,list[i].isEmpty
				    ,list[i].id/////////NO TOCAR//////////////
				    ,list[i].idCliente
				    ,list[i].numeroRubro
					,list[i].estPubli
					,list[i].descripcionEstado
					,list[i].texto
				   );
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
			}
		}
		retorno = 0;
	}
	return retorno;
}



/** \brief Buscar espacio libre en el array
 *
 * \param list Employee*
 * \param length int
 * Usa la funcion isEmpty para obtener
 * lugar vacio mediante un for que recorre el array
 * \return 1 si esta ok - 0 si no
 *
 */
int publicacion_searchFree (Publicacion *list, int len)
{
  int i;
  int retorno = FALSE;

  if (list != NULL && list > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (publicacion_isEmpty (list, len, i) == 1)
	    {
	      retorno = TRUE;
	      break;
	    }
	}
    }
  return retorno;
}





/** \brief Buscar espacio bacio en el array
 *
 * \param list Employee*
 * \param length int
 * \return 1 si esta ok - 0 si no
 *
 */
int publicacion_isEmpty(Publicacion* list, int limit, int index)
{
  int retorno = FALSE;
//  if (list != NULL && list > 0 && index < list)
    if (list != NULL && list > 0)
    {
      if (list[index].isEmpty == TRUE)
	{
	  retorno = TRUE;
	}
    }
  return retorno;
}



/** \brief conjunto  de funcione de entrada de datos por consola
 *
 * \param list Employee*
 * \param length int
 * usa la funcion utn_getNombre para obtener nombre o apelleido
 * usa la funcion utn_getNumeroFloat para obtener numero flotante
 * usa la funcion utn_getNumero para obtener numero entero
 * usa la funcion idIncremental para obtener id incremental
 * usa la funcion addEmployee para impactar los datos ingresados al array
 * \return 0 si esta ok - -1 si no
 *
 */
int publicacion_chargeArray (Publicacion *list, int len)
{
  Publicacion auxPublicacion;
  int retorno = -1;


  if (list != NULL && len > 0)
    {
////////////////////	////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
      if (utn_getNumero ("Ingrese id del Cliente: ", "\nError al ingresar. Por favor ", &auxPublicacion.idCliente, 0, 999, 5)!= 0)
      		{
      		  return -1;
      		}
      if (utn_getNumero ("Ingrese numero de rubro: ", "\nError al ingresar. Por favor ", &auxPublicacion.numeroRubro, 0, 99999, 5)!= 0)
		{
		  return -1;
		}
      if (utn_getAlfanumerico ("Ingrese texto: ",  "\nError al ingresar.\n", auxPublicacion.texto, LONG_NAME_PUBLICACION, 5) != 0)
     		{
     		  return -1;
     		}

      if (utn_getAceptaRechaza ("\nAcepta el ingreso? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n')==1)
	{
    	  auxPublicacion.id = utn_idIncremental ();
    	  auxPublicacion.estPubli = ACTIVA;
    	  strcpy(auxPublicacion.descripcionEstado,"ACTIVA");
	  if(publicacion_addArray (list, len,
			  auxPublicacion.id,///////NO TOCAR////////////////////////
			  auxPublicacion.idCliente,
			  auxPublicacion.numeroRubro,
			  auxPublicacion.estPubli,
			  auxPublicacion.descripcionEstado,
			  auxPublicacion.texto
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
				)==0)
	  {
	      retorno = 0;
	  }
	  printf ("\n*****************************************************");
          printf ("\n                    ALTA EXITOSA!                  \n");
	  printf ("*****************************************************\n\n");
	}
      else
	{
	  retorno = 0;
	}
    }
  return retorno;
}




/** \brief vuelca datos del array a un array auxiliar partiendo del id
 *
 * \param list Employee*
 * \param list Employee* --> array auxiliar
 * \param length int
 * \param id int
 * \return 0 si esta ok - -1 si no
 *
 */
int publicacion_arrayToBuffer(Publicacion *list,Publicacion *listBuffer, int len, int id)
{
  int retorno = -1;
    int i;
    	if(list != NULL && len > 0)
    	{
    	      for( i=0;i<len;i++)
    		{
    			if(list[i].id == id)
    			{
    			*listBuffer=list[i];
    			}
    		}
    		retorno = 0;
    	}
return retorno;
}




/** \brief vuelca datos del array auxiliar a un array  partiendo del id
 *
 * \param list Employee*
 * \param list Employee* --> array auxiliar
 * \param length int
 * \param id int
 * \return 0 si esta ok - -1 si no
 *
 */
int publicacion_bufferToArray(Publicacion *list, Publicacion *listBuffer, int len, int id)
{
  int i;
  int retorno = -1;
  if (list != NULL && listBuffer != NULL && len > 0)
    {

	for (i = 0; i < len; i++)
	  {
	    if (list[i].id == id)
	      {
		list[i] = *listBuffer;
		retorno = 0;
	      }
	  }
    }
  return retorno;
}




/** \brief conjunto  de funcione de entrada de datos por consola
 *
 * \param list Employee*
 * \param length int
 * usa la funcion utn_getNumero para ingresar id
 * usa la funcion findEmployeeById para buscar id
 * usa la funcion arrayToBuffer para volcar datos de un array a un array auxiliar por medio del id
 * usa la funcion printForId para imprimir el array  por medio del id
 *  usa la funcion utn_getNumero para obtener opcion
 * usa la funcion utn_getNombre para obtener nombre o apelleido
 * usa la funcion utn_getNumeroFloat para obtener numero flotante
 * usa la funcion utn_getNumero para obtener numero entero
 * usa la funcion utn_getAceptaRechaza para aceptar o rechazar ingreso de datos
 * usa la funcion idIncremental para obtener id incremental
 * usa la funcion bufferToArray para volcar datos de un array auxiliar a un array  por medio del id
 * \return 0 si esta ok - -1 si no
 *
 */
int publicacion_updateArray (Publicacion *list, int len)
{
  int bufferID;
  int retorno = -1;
  int opcion;
  Publicacion auxPublicacion;

  if (list != NULL && len > 0)
    {
      utn_getNumero ("\nIngrese ID del empleado: ", "\nError al ingresar. ", &bufferID, 1, QTY_PUBLICACION, 5);
      if (publicacion_findArrayById (list, len, bufferID) != -1)
	{
	  retorno = 0;
	  publicacion_arrayToBuffer(list, &auxPublicacion,  len,  bufferID);
	  do
	     {
	      publicacion_printForId  (&auxPublicacion,len,  bufferID);
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      printf ("\n"
		      "1-ID CLIENTE\n"
		      "2-NUMERO DE RUBRO\n"
	    	  "3-TEXTO\n"

	      	      "4-Aceptar Cambios\n"//////NO TOCAR////////////////////////
	      	      "5-Salir\n"//////NO TOCAR////////////////////////
		  );

	       if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 5, 3) != -1)
	 	{
	 	  switch (opcion)
	 	    {
	 	   case 1:
  	 	      printf ("\n"
  	 		  "ID CLIENTE"
  	 		  "\n******\n");
  	 	   if (utn_getNumero ("Ingrese id del cliente: ", "\nError al ingresar. Por favor ", &auxPublicacion.idCliente, 0, 999, 5)!= 0)
  	 	    	{
  	 	    	  return -1;
  	 	    	}
  	 	      break;

	 	    case 2:
			printf ("\n"
				"NUMERO DE RUBRO"
				"\n********\n");
			 if (utn_getNumero ("\nIngresar numero de rubro: ","\nOpcion Invalida. ", &auxPublicacion.numeroRubro, 1, 99999, 3) != -0)
			  {
			    return -1;
			  }
			break;
	 	    case 3:
 	 	 	printf ("\n"
 	 	 		"TEXTO"
 	 			"\n******\n");
 	 	     if (utn_getAlfanumerico ("Ingrese texto: ",  "\nError al ingresar.\n", auxPublicacion.texto, LONG_NAME_PUBLICACION, 5) != 0)
 	 	    	{
 	 	    	  return -1;
 	 	    	}
 	 	      break;

////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	 	   case 4:
	 		 if(utn_getAceptaRechaza ("\nGrabar cambios? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n')==1)
	 		   {
	 		    publicacion_bufferToArray (list, &auxPublicacion,  len, bufferID);
	 		    printf ("\n*************************************\n");
	 		    printf ("\nLOS CAMBIOS SE GRABARON EXITOSAMENTE!\n");
	 		    printf ("\n*************************************\n\n");
	 		   }
	 	      break;
	 	    }
	 	}
	       else
	 	{
	 	  printf ("\nSE TERMINARON LOS REINTENTOS\n");
	 	  system ("pause");
	 	  return EXIT_SUCCESS;
	 	}
	     }
	   while (opcion != 5);

	  if(opcion == 5)
	    {
	      return EXIT_SUCCESS;
	    }
	}
      else
	{
	  printf ("\nEl ID NO existe\n");
	}
    }
  return retorno;
}




/** \brief obtiene array por medio del id y luedo realiza baja logica del mismo
 *
 * \param list Employee*
 * \param length int
 * \usa la funcion utn_getNumero para obtener numero entero
 * \usa la funcion findEmployeeById para obtener array partiendo del id
 * \usa la funcion printForId imprime array partiendo del id
 * \usa la funcion utn_getAceptaRechaza para aceptar o rechazar ingreso de datos
 * \usa la funcion removeEmployee para realizar la baja logica
 * \param id int
 * \return 0 si esta ok - -1 si no
 *
 */
int publicacion_prepareForDelete (Publicacion *list, int len)
{
  int retorno = -1;
  int bufferID;

  if (list != NULL && len > 0)
    {
      utn_getNumero ("\nIngrese ID de la publicacion: ", "\nError al ingresar. ", &bufferID, 1, QTY_PUBLICACION, 5);
      if (publicacion_findArrayById (list, len, bufferID) != -1)
	{
	  publicacion_printForId (list, len, bufferID);
	  retorno = utn_getAceptaRechaza ("\nAcepta eliminar Publicacion? s/n: ", "ERROR al ingresar opcion. \n", 's','n');
	  if (retorno == 1)
	    {
	      publicacion_removeArray (list, len, bufferID);
	      retorno = 1;
	      printf ("\n*****************************************************");
	      printf ("\n             ELIMINACION EXITOSA!\n");
	      printf ("*****************************************************\n\n");
	    }
	}
      else
  	{
  	  printf ("\nEl ID NO existe\n");
  	}
    }
  return retorno;
}



/** \brief obtiene la suma de los valores del array
 *
 * \param list Employee*
 * \param length int
 * \return 0 si esta ok - -1 si no
 *
 */
/*
float publicacion_sumaTotal (Publicacion *list, int len)
{
  int i;
  float retorno = -1;
  float aux = 0;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].isEmpty == FALSE &&
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      list[i].FLOTANTE1 != FALSE
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      )
	    {
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      aux = aux + list[i].FLOTANTE1;
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	    }
	}
      retorno = aux;
    }
  return retorno;
}
*/

/** \brief obtiene el promedio
 *
 * \param list Employee*
 * \param length int
 * \usa la funcion sumaTotal para sumar
 * \return 0 si esta ok - -1 si no
 *
 */
/*
float publicacion_promedio(Publicacion* list, int len)
{
  int i;
  float retorno = -1;
  int contador = 0;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].isEmpty == FALSE &&
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      list[i].FLOTANTE1 != FALSE
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      )
	    {
	      contador++;
	    }
	}
      retorno = publicacion_sumaTotal (list, len) / contador;
    }
  return retorno;
}
*/


/** \brief obtiene la cantidad superior al promedio
 *
 * \param list Employee*
 * \param length int
 * \usa la funcion promedio para obtener el promedio
 * \return 0 si esta ok - -1 si no
 *
 */
/*
int publicacion_cantidadSuperiorAlPromedio(Publicacion* list, int len)
{

  int i;
  int retorno = -1;
  int contador = 0;
  float aux;

  aux = publicacion_promedio (list, len);
  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].isEmpty == FALSE &&
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      list[i].FLOTANTE1 > aux
///////////////////////////////////////////////////////MODIFICABLE//////////////////////////////////////////////////////////////////////
	      )
	    {
	      contador++;
	    }
	}
      retorno = contador;
    }
  return retorno;
}

*/

/** \brief recorre el array y devuelve si esta full o si esta vacio
 *
 * \param list Employee*
 * \param length int
 * \usa la funcion promedio para obtener el promedio
 * \return 0 si esta vacio - > 0 si contiene datos- -1 si no
 *
 */
int publicacion_flagLimite(Publicacion* list, int len)
{
  int retorno = -1;
  int i;
  int contador = 0;

  for (i = 0; i < len; i++)
    {
      if (i <= len && list[i].isEmpty == FALSE)
	{
	  contador++;
	}
    }
  if (contador == 0)
    {
      retorno = 0;
    }
  else if (contador > 0 && contador != len)
    {
      retorno = contador;
    }
  return retorno;
}






int publicacion_buscarIndiecePorId (Publicacion* list, int len, int idBuscar, int* pIndice)
{
  int retorno = -1;
  int i;

  if (list != NULL && len > 0 && pIndice != NULL)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].id == idBuscar)
	    {
		*pIndice = i;
		retorno = 0;
		break;
	    }
	}
    }
  return retorno;
}




