/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================

 */
#include "arrayEntidad.h"

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
int template_initArray(Template list[], int len)
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
		    list[i].idAux = 0;/////////NO TOCAR////////
		    strcpy(list[i].NOMBRE1,"VACIO");
		    strcpy(list[i].NOMBRE2,"VACIO");
		    list[i].NUMERO1 = 0;
		    list[i].NUMERO2 = 0;
		    list[i].FLOTANTE1 = 0.00;
		    list[i].FLOTANTE2 = 0.00;
		    list[i].NUMERO_LARGO = 00000000000000;
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
int template_addArray(Template* list, int len, int id,
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		      int idAux,
      		      char* NOMBRE1,
     		      char* NOMBRE2,
      		      int NUMERO1,
      		      int NUMERO2,
      		      float FLOTANTE1,
      		      float FLOTANTE2,
      		      long long int NUMERO_LARGO
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		      )
{
  int i;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (template_isEmpty (list, len, i) == 1)
	    {
	      list[i].id = id;
	      list[i].isEmpty = FALSE;
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      list[i].idAux = idAux;/////////NO TOCAR////////
	      strcpy(list[i].NOMBRE1,NOMBRE1);
	      strcpy(list[i].NOMBRE2,NOMBRE2);
	      list[i].NUMERO1 = NUMERO1;
	      list[i].NUMERO2 = NUMERO2;
	      list[i].FLOTANTE1 = FLOTANTE1;
	      list[i].FLOTANTE2 = FLOTANTE2;
	      list[i].NUMERO_LARGO = NUMERO_LARGO;
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
void template_headerArray(void)

{
    printf("\n"
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	    "%*s"
	    "%*s"
	    "%*s"
	    "%*s"
	    "%*s"
	    "%*s"
	    "%*s"
	    "%*s"
	    "%*s",
	   -7, " ID",
	   -10, " ID AUX",
	   -14," NUMERO1",
	   -14," NUMERO2",
	   -12," NOMBRE1",
	   -12," NOMBRE2",
	   -12," FLOTANTE1",
	   -12," FLOTANTE2",
	     0," NUMERO_LARGO"
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
int template_printForId  (Template *list, int len, int id)
{
  int retorno = -1;
  int i;
  	if(list != NULL && len > 0)
  	{
  	    template_headerArray();
  		for( i=0;i<len;i++)
  		{
  			if(list[i].id == id && list[i].isEmpty == FALSE &&
  			    ///Se agrega una condicion mas por si lo que trae es basura
  			    list[i].NUMERO1 > 0)
  			{
  				printf(
  				       " %-6d "
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
  				       "%-12d " ///NO TOCAR///////
  				       "%-12d "
  				       "%-10d "
  				       "%-13s "
  				       "%-13s "
  				       "%-12.2f "
  				       "%-12.2f "
  				       "%lld"
  				       "\n"

  				 //   ,list[i].isEmpty
  				   ,list[i].id ///NO TOCAR///////
				   ,list[i].idAux
				   ,list[i].NUMERO1
				   ,list[i].NUMERO1
				   ,list[i].NOMBRE1
				   ,list[i].NOMBRE2
				   ,list[i].FLOTANTE1
				   ,list[i].FLOTANTE2
				   ,list[i].NUMERO_LARGO
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
int template_removeArray(Template* list, int len, int id)
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
int template_findArrayById (Template *list, int len, int id)
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
int template_sortArray(Template* list, int len, int order)
{
  int flagSwap;
  int i;
  int contador = 0;
  int retorno = -1;
  Template buffer;
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
		/*  ||(0==strcmp (list[i].lastName, list[i + 1].lastName) &&
		      (((list[i].sector > list[i + 1].sector)&&(order == 1))
			  ||((list[i].sector < list[i + 1].sector) &&(order == 0)))))*/
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



/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int template_printArray(Template* list, int length)
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
				    "%-13s "
				    "%-13s "
				    "%-12.2f "
				    "%-12.2f "
				    "%-30lld"
				    " \n"

				  //  ,list[i].isEmpty
				    ,list[i].id/////////NO TOCAR//////////////
				    ,list[i].idAux
				    ,list[i].NUMERO1
				    ,list[i].NUMERO1
				    ,list[i].NOMBRE1
				    ,list[i].NOMBRE2
				    ,list[i].FLOTANTE1
				    ,list[i].FLOTANTE2
				    ,list[i].NUMERO_LARGO
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
int template_searchFree (Template *list, int len)
{
  int i;
  int retorno = FALSE;

  if (list != NULL && list > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (template_isEmpty (list, len, i) == 1)
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
int template_isEmpty(Template* list, int limit, int index)
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
int template_chargeArray (Template *list, int len)
{
  Template auxTemplate;
  int retorno = -1;


  if (list != NULL && len > 0)
    {
////////////////////	////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
      if (utn_getNumero ("Ingrese id Auxiliar: ", "\nError al ingresar. Por favor ", &auxTemplate.idAux, 0, 999, 5)!= 0)
      		{
      		  return -1;
      		}
      if (utn_getNombre ("Ingrese NOMBRE1: ", "\nError al ingresar.\n", auxTemplate.NOMBRE1, LONG_NAME_TEMPLATE, 5) != 0)
		{
		  return -1;
		}
      if (utn_getNombre ("Ingrese NOMBRE2: ", "\nError al ingresar.\n", auxTemplate.NOMBRE2, LONG_NAME_TEMPLATE, 5) != 0)
		{
		  return -1;
		}
      if (utn_getNumero ("Ingrese NUMER1: ", "\nError al ingresar. Por favor ", &auxTemplate.NUMERO1, 0, 99999, 5)!= 0)
		{
		  return -1;
		}
      if (utn_getNumero ("Ingrese NUMER2: ", "\nError al ingresar. Por favor ", &auxTemplate.NUMERO2, 0, 99999, 5)!= 0)
		{
		  return -1;
		}
      if (utn_getNumeroFloat (&auxTemplate.FLOTANTE1, "Ingrese FLOTANTE1: ", "\nError al ingresar. Por favor ", 1, 9999999, 5)!= 0)
      		{
		  return -1;
      		}
      if (utn_getNumeroFloat (&auxTemplate.FLOTANTE2, "Ingrese FLOTANTE2: ", "\nError al ingresar. Por favor ", 1, 9999999, 5)!= 0)
           	{
           	  return -1;
           	}
      if (utn_getNumeroLong ("Ingrese NUMERO LARGO: ", "\nError al ingresar. Por favor ", &auxTemplate.NUMERO_LARGO, 20010000000, 20999999999, 5)!= 0)
     		{
     		  return -1;
     		}
      if (utn_getAceptaRechaza ("\nAcepta el ingreso? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n')==1)
	{
	  auxTemplate.id = utn_idIncremental ();
	  if(template_addArray (list, len,
				auxTemplate.id,///////NO TOCAR////////////////////////
				auxTemplate.idAux,
				auxTemplate.NOMBRE1,
				auxTemplate.NOMBRE2,
				auxTemplate.NUMERO1,
				auxTemplate.NUMERO2,
				auxTemplate.FLOTANTE1,
				auxTemplate.FLOTANTE2,
				auxTemplate.NUMERO_LARGO
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
int template_arrayToBuffer(Template *list,Template *listBuffer, int len, int id)
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
int template_bufferToArray(Template *list, Template *listBuffer, int len, int id)
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
int template_updateArray (Template *list, int len)
{
  int bufferID;
  int retorno = -1;
  int opcion;
  Template auxTemplate;

  if (list != NULL && len > 0)
    {
      utn_getNumero ("\nIngrese ID del empleado: ", "\nError al ingresar. ", &bufferID, 1, QTY_TEMPLATE, 5);
      if (template_findArrayById (list, len, bufferID) != -1)
	{
	  retorno = 0;
	  template_arrayToBuffer(list, &auxTemplate,  len,  bufferID);
	  do
	     {
	      template_printForId  (&auxTemplate,len,  bufferID);
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      printf ("\n"
		      "1-ID AUXILIAR\n"
		      "2-NOMBRE1\n"
		      "3-NOMBRE2\n"
		      "4-NUMERO1\n"
		      "5-NUMERO2\n"
		      "6-FLOTANTE1\n"
		      "7-FLOTANTE2\n"
		      "8-NUMERO_LARGO\n"
	      	      "9-Aceptar Cambios\n"//////NO TOCAR////////////////////////
	      	      "10-Salir\n"//////NO TOCAR////////////////////////
		  );

	       if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 10, 3) != -1)
	 	{
	 	  switch (opcion)
	 	    {
	 	   case 1:
  	 	      printf ("\n"
  	 		  "ID AUXILIAR"
  	 		  "\n******\n");
  	 	   if (utn_getNumero ("Ingrese id Auxiliar: ", "\nError al ingresar. Por favor ", &auxTemplate.idAux, 0, 999, 5)!= 0)
  	 	    	{
  	 	    	  return -1;
  	 	    	}
  	 	      break;
	 	    case 2:
	 	      printf ("\n"
	 		  "NOMBRE1"
	 		  "\n******\n");

	 	     if (utn_getNombre ("Ingrese NOMBRE1: ",  "\nError al ingresar.\n", auxTemplate.NOMBRE1, LONG_NAME_TEMPLATE, 5) != 0)
	 	    	{
	 	    	  return -1;
	 	    	}
	 	      break;
	 	    case 3:
	 	      printf ("\n"
	 		  "NOMBRE2"
	 		  "\n********\n");
	 	     if (utn_getNombre ("Ingrese NOMBRE2: ",  "\nError al ingresar.\n", auxTemplate.NOMBRE2, LONG_NAME_TEMPLATE, 5) != 0)
	 	     	 {
	 	     	   return -1;
	 	     	 }
	 	      break;
	 	    case 4:
			printf ("\n"
				"NUMERO1"
				"\n********\n");
			 if (utn_getNumero ("\nIngresar NUMERO1: ","\nOpcion Invalida. ", &auxTemplate.NUMERO1, 1, 99999999, 3) != -1)
			  {
			    return -1;
			  }
			break;
	 	   case 5:
	 	        printf ("\n"
				"NUMERO2"
				"\n********\n");
	 	       if (utn_getNumero ("\nIngresar NUMERO2: ","\nOpcion Invalida. ", &auxTemplate.NUMERO2, 1, 99999999, 3) != -1)
			  {
			    return -1;
			  }
			break;
	 	    case 6:
	 	      printf ("\n"
	 		  "FLOTANTE1"
	 		  "\n**********\n");
	 	     if (utn_getNumeroFloat (&auxTemplate.FLOTANTE1, "Ingrese FLOTANTE1: ", "\nError al ingresar. Por favor ", 1, 9999999, 5)!= 0)
	 	     	{
	 	     	  return -1;
	 	     	}
	 	    break;
	 	   case 7:
 	   	 	 printf ("\n"
   	 		  "FLOTANTE2"
   	 		  "\n**********\n");
   	 	     if (utn_getNumeroFloat (&auxTemplate.FLOTANTE2, "Ingrese FLOTANTE2: ", "\nError al ingresar. Por favor ", 1, 9999999, 5)!= 0)
   	 	     	{
   	 	     	  return -1;
   	 	     	}
	 	      break;

	 	  case 8:
 	 	        printf ("\n"
			"NUMERO LARGO"
			"\n********\n");
 	 	      if (utn_getNumeroLong ("Ingrese NUMERO LARGO: ", "\nError al ingresar. Por favor ", &auxTemplate.NUMERO_LARGO, 0, 99999999999999, 5)!= 0)
 	 		 {
 			   return -1;
 			 }
             	     break;
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	 	   case 9:
	 		 if(utn_getAceptaRechaza ("\nGrabar cambios? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n')==1)
	 		   {
	 		    template_bufferToArray (list, &auxTemplate,  len, bufferID);
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
	   while (opcion != 10);

	  if(opcion == 10)
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
int template_prepareForDelete (Template *list, int len)
{
  int retorno = -1;
  int bufferID;

  if (list != NULL && len > 0)
    {
      utn_getNumero ("\nIngrese ID de la ENTIDAD: ", "\nError al ingresar. ", &bufferID, 1, QTY_TEMPLATE, 5);
      if (template_findArrayById (list, len, bufferID) != -1)
	{
	  template_printForId (list, len, bufferID);
	  retorno = utn_getAceptaRechaza ("\nAcepta eliminar ENTIDAD? s/n: ", "ERROR al ingresar opcion. \n", 's','n');
	  if (retorno == 1)
	    {
	      template_removeArray (list, len, bufferID);
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
float template_sumaTotal (Template *list, int len)
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


/** \brief obtiene el promedio
 *
 * \param list Employee*
 * \param length int
 * \usa la funcion sumaTotal para sumar
 * \return 0 si esta ok - -1 si no
 *
 */
float template_promedio(Template* list, int len)
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
      retorno = template_sumaTotal (list, len) / contador;
    }
  return retorno;
}



/** \brief obtiene la cantidad superior al promedio
 *
 * \param list Employee*
 * \param length int
 * \usa la funcion promedio para obtener el promedio
 * \return 0 si esta ok - -1 si no
 *
 */
int template_cantidadSuperiorAlPromedio(Template* list, int len)
{

  int i;
  int retorno = -1;
  int contador = 0;
  float aux;

  aux = template_promedio (list, len);
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



/** \brief recorre el array y devuelve si esta full o si esta vacio
 *
 * \param list Employee*
 * \param length int
 * \usa la funcion promedio para obtener el promedio
 * \return 0 si esta vacio - > 0 si contiene datos- -1 si no
 *
 */
int template_flagLimite(Template* list, int len)
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






int template_buscarIndiecePorId (Template* list, int len, int idBuscar, int* pIndice)
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




