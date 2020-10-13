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
#include "publicacionCliente.h"
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
    	  "4-Publicar\n"
    	  "5-Pausar publicacion\n"
    	  "6-Reanudar publicacion\n"
    	  "7-Imprimir Clientes\n"
    	  "8-Informar\n"
	      "9-Informar general\n"
	      "10-Salir\n\n");
///////////////////////////////////////////////////////MODIFICABLE//////////////////////////////////////////////////////////////////////

      if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 10, 3) != -1)//MODIFICAR EN CASO AGREGAR O QUITAR OPCIONES
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
		  printf ("\n*********  Modificar datos de cliente  ************\n");
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
	      break;
	    case 3:
//********************************************************************************************************************************************************//
/////////APLICAR BORRADO EN CASCADA////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//********************************************************************************************************************************************************//
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

/*
	      if (publicacion_flagLimite (publicacion_list, QTY_PUBLICACION) != 0)
	     	      	{
	     		  printf ("\n*****************************************************");
	     		  printf ("\n*************      BAJA DE CLIENTE   *****************\n");
	     		  printf ("*****************************************************\n");
	     	      if(publicacion_prepareForDelete (publicacion_list,QTY_PUBLICACION)==-1)
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
	     	      		*/
//********************************************************************************************************************************************************//
/////////APLICAR BORRADO EN CASCADA////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//********************************************************************************************************************************************************//
	      break;
	    case 4:
		 printf ("\n*****************************************************");
		 printf ("\n*****************    PUBLICAR   ********************\n");
		 printf ("*****************************************************\n");
		 publicacionCliente_chargeArray (publicacion_list, QTY_PUBLICACION,cliente_list,QTY_CLIENTE);
	      break;
	    case 5:
	   		 printf ("\n*****************************************************");
	   		 printf ("\n**************    PAUSAR PUBLICACION  ***************\n");
	   		 printf ("*****************************************************\n");
	   		prepararParaPublicacion_pausada (publicacion_list, QTY_PUBLICACION,cliente_list,QTY_CLIENTE);

	   	      break;
	    case 6:
	   		 printf ("\n*****************************************************");
	   		 printf ("\n************    REANUDAR PUBLICACION    *************\n");
	   		 printf ("*****************************************************\n");
	   		prepararParaPublicacion_reanudar (publicacion_list, QTY_PUBLICACION,cliente_list,QTY_CLIENTE);

	   	      break;
	    case 7:
	   		 printf ("\n*****************************************************");
	   		 printf ("\n*********    IMPRIMIR CLIENTES    *****************\n");
	   		 printf ("*****************************************************\n");
	   		imprimirClientes (publicacion_list, QTY_PUBLICACION,cliente_list,QTY_CLIENTE);
	   	// imprimaProductoElegido(publicacion_list,QTY_PUBLICACION, 1);
	   	      break;
	    case 8:
	   		 printf ("\n*****************************************************");
	   		 printf ("\n*****************    INFORMAR    ********************\n");
	   		 printf ("*****************************************************\n");


	   	      break;
	    case 9:
	    	///BORRAR LUEGO DE FINALZAR DESARROLLO////////////////////////////////////
		   		 printf ("\n*****************************************************");
		   		 printf ("\n************    INFORMAR GENERAL     *************\n");
		   		 printf ("*****************************************************\n");
		   		 publicacion_headerArray();
		   		 publicacion_printArray(publicacion_list, QTY_PUBLICACION);
		   		 cliente_headerArray();
		   		 cliente_printArray(cliente_list, QTY_CLIENTE);
		   	      break;

	    case 10:
	      printf("\nEL PROGRAMA SE CERRO CON EXITO!\n");
	      system ("pause");
	      return EXIT_SUCCESS;
	      break;
	    default:
	      break;
	    }
	}//
      else
	{
	  printf ("\n*****************************\n");
	  printf ("\nSE TERMINARON LOS REINTENTOS!\n");
	  printf ("\n*****************************\n");
	  //return EXIT_SUCCESS;
	}
    }
  while (opcion != 10);

	return EXIT_SUCCESS;
}


