/*
 ============================================================================
 Name        : 0.c
 Author      : Nicolas Letticugna - 1H
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <conio.h>
#include "cliente_HarcodArray.h"
#include "arrayCliente.h"
#include "publicacion_HarcodArray.h"
#include "arrayPublicacion.h"
#include "utn_input.h"



int main(void) {
setbuf(stdout,NULL);
int opcion;

Cliente cliente_list[QTY_CLIENTE];
Publicacion publicacion_list[QTY_PUBLICACION];
publicacion_initArray(publicacion_list, QTY_PUBLICACION);
publicacion_hardcodDatosArray(publicacion_list, QTY_PUBLICACION_HARDCOD_TEST);
cliente_initArray(cliente_list, QTY_CLIENTE);
cliente_HardcodDatosArray(cliente_list, QTY_CLIENTE_HARDCOD_TEST);
  do
    {
      printf ("\n*********"
	      "\n* MENU  *"
	      "\n*********"
///////////////////////////////////////////////////////MODIFICABLE//////////////////////////////////////////////////////////////////////
	    "\n1-Alta de cliente\n"
	      "2-Modificacion de cliente\n"
	      "3-Baja de cliente\n"
	      "4-Informar\n"
	      "5-Salir\n\n");
///////////////////////////////////////////////////////MODIFICABLE//////////////////////////////////////////////////////////////////////

      if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 5, 3) != -1)//MODIFICAR EN CASO AGREGAR O QUITAR OPCIONES
	{
	  switch (opcion)
	    {
	    case 1:

	      if (cliente_flagLimite (cliente_list, QTY_CLIENTE) != -1)
		{
		  if (cliente_searchFree (cliente_list, QTY_CLIENTE) == TRUE)
		    {
		      printf ("\n*****************************************************");
		      printf ("\n            ALTA DE CLIENTE    *********************\n");
		      printf ("*****************************************************\n");
		      if (cliente_chargeArray (cliente_list, QTY_CLIENTE) != 0)
			{
			  printf ("\n*****************************\n");
			  printf ("\nSE TERMINARON LOS REINTENTOS!\n");
			  printf ("\n*****************************\n");
			}
		    }
		}
	      else
		{
		  printf ("\n*******************************************\n");
		  printf ("\nLA CANTIDAD DE CLIENTES LLEGO A SU LIMITE!\n");
		  printf ("\n*******************************************\n");
		}

	      break;
	    case 2:
	      if (cliente_flagLimite (cliente_list, QTY_CLIENTE) != 0)
		{
		  printf ("\n*****************************************************");
		  printf ("\n***************    MODIFICAR CLIENTE   ***************\n");
		  printf ("*****************************************************\n");
		  if (cliente_updateArray (cliente_list, QTY_CLIENTE) != 0)
		    {
		      printf ("\n******\n");
		      printf ("\nERROR!\n");
		      printf ("\n******\n");
		    }
		}
	      else
		{
		  printf ("\n*****************************************\n");
		  printf ("\nNO HAY CLIENTES CARGADOS PARA MODIFICAR!\n");
		  printf ("\n*****************************************\n");

		}
	      break;//
	    case 3:
	    	//APLICAR BORRADO EN CASCADA/////////////////////////////////////////////////
	      if (cliente_flagLimite (cliente_list, QTY_CLIENTE) != 0)
	      	{
		  printf ("\n*****************************************************");
		  printf ("\n*************      BAJA DE CLIENTE   *****************\n");
		  printf ("*****************************************************\n");
	      if(cliente_prepareForDelete (cliente_list,QTY_CLIENTE)==-1)
		{
		  printf ("\n******\n");
		  printf ("\nERROR!\n");
		  printf ("\n******\n");
		}
	      	}
	      else
	      		{
		  printf ("\n****************************************\n");
		  printf ("\nNO HAY CLIENTES CARGADOS PARA ELIMINAR!\n");
		  printf ("\n****************************************\n");
	      		}
	      break;
	    case 4:
//	      if (publicacion_flagLimite (publicacion_list, QTY_PUBLICACION) != 0)
//	        {
		 printf ("\n*****************************************************");
		 printf ("\n*****************    INFORMAR    ********************\n");
		 printf ("*****************************************************\n");
/*	      if(cliente_sortArray(cliente_list, QTY_CLIENTE, 1) == -1)
		{
		  printf ("\n******\n");
		  printf ("\nERROR!\n");
		  printf ("\n******\n");
		}*/
		 publicacion_headerArray();
		 publicacion_printArray(publicacion_list, QTY_PUBLICACION);
		 cliente_headerArray();
		 cliente_printArray(cliente_list, QTY_CLIENTE);
/*	      printf ("\n*****************************************************\n");
	      printf ("TOTAL DE LOS SALARIOS: ");
	      printf ("%.2f",cliente_sumaTotal(cliente_list, QTY_CLIENTE));
	      printf ("\nPROMEDIO DE LOS SALARIOS: ");
	      printf ("%.2f",cliente_promedio(cliente_list, QTY_CLIENTE));
      	      printf ("\nCANTIDAD DE ENTIDAD QUE SUPERAN EL PROMEDIO: ");
	      printf ("%d",cliente_cantidadSuperiorAlPromedio(cliente_list, QTY_CLIENTE));
	      printf ("\n*****************************************************\n");*/
//	     	}
//	      else
//			{
//		  printf ("\n***************************************\n");
//		  printf ("\nNO HAY ENTIDAD CARGADOS PARA MOSTRAR!\n");
//		  printf ("\n***************************************\n");
//			}
	      break;
	    case 5:
	      printf("\nEL PROGRAMA SE CERRO CON EXITO!\n");
	      system ("pause");
	      return EXIT_SUCCESS;
	      break;
	    default:
	      break;
	    }
	}
      else
	{
	  printf ("\n*****************************\n");
	  printf ("\nSE TERMINARON LOS REINTENTOS!\n");
	  printf ("\n*****************************\n");
	  //return EXIT_SUCCESS;
	}
    }
  while (opcion != 5);

	return EXIT_SUCCESS;
}
