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
int opcion2;
int clienteMasAvisos;
int cantAvisosPausados;
int rubroConMasAvisos;
int cantAvisosActivos;
int cantMasAvisosPausados;

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


      if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 10, 3) != -1)
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
			  if (cliente_flagLimite (cliente_list, QTY_CLIENTE) != 0)
			  	  {
				  printf ("\n*****************************************************");
				  printf ("\n*********       Baja de cliente        ************\n");
				  printf ("*****************************************************\n");
				  borradoEnCascadaCLientePublicacion(publicacion_list, QTY_PUBLICACION,cliente_list,QTY_CLIENTE);
			  	  }
					  else
					  {
					  printf ("\n*****************************************\n");
					  printf ("\nNO HAY CLIENTES CARGADOS PARA DAR DE BAJA!\n");
					  printf ("\n*****************************************\n");
					  }
	        break;
	    case 4:
	    	 if (cliente_flagLimite (cliente_list, QTY_CLIENTE) != 0)
	    	 {
	    	 printf ("\n*****************************************************");
			 printf ("\n*****************    PUBLICAR   ********************\n");
			 printf ("*****************************************************\n");
			 publicacionCliente_chargeArray (publicacion_list, QTY_PUBLICACION,cliente_list,QTY_CLIENTE);
	    	 }
	    	 	 else
	    	 	 	 {
	    			  printf ("\n*****************************************\n");
	    			  printf ("\nNO HAY CLIENTES CARGADOS PARA CARGAR PUBLICACIONES!\n");
	    			  printf ("\n*****************************************\n");
	    			  }
			 break;
	    case 5:
	    	 if (publicacion_flagLimite (publicacion_list, QTY_PUBLICACION) != 0)
	    	 	 {
				 printf ("\n*****************************************************");
				 printf ("\n**************    PAUSAR PUBLICACION  ***************\n");
				 printf ("*****************************************************\n");
				 prepararParaPublicacion_pausada (publicacion_list, QTY_PUBLICACION,cliente_list,QTY_CLIENTE);
	    		 }
	    	 	 	 else
	    	 	    	 {
	    	 	    	  printf ("\n*****************************************\n");
	    	 	    	  printf ("\nNO HAY PUBLICACIONES CARGADAS PARA PASUAR!\n");
	    	 	    	  printf ("\n*****************************************\n");
	    	 	    	 }
	   	      break;
	    case 6:
	    	  if (publicacion_flagLimite (publicacion_list, QTY_PUBLICACION) != 0)
	    	  	  {
	    		  printf ("\n*****************************************************");
	    		  printf ("\n************    REANUDAR PUBLICACION    *************\n");
	    		  printf ("*****************************************************\n");
	    		  prepararParaPublicacion_reanudar (publicacion_list, QTY_PUBLICACION,cliente_list,QTY_CLIENTE);
	    		  }
	    	 	  	  else
	    	  	      	  {
	    	  	    	  printf ("\n*****************************************\n");
	    	  	    	  printf ("\nNO HAY PUBLICACIONES CARGADAS PARA REANUDAR!\n");
	    	  	    	  printf ("\n*****************************************\n");
	    	  	    	  }
	   	      break;
	    case 7:
	    	  if (cliente_flagLimite (cliente_list, QTY_CLIENTE) != 0)
	    	  	  {
	    	  	  printf ("\n*****************************************************");
	    	  	  printf ("\n*********    IMPRIMIR CLIENTES    *****************\n");
	    	  	  printf ("*****************************************************\n");

	    	  	MostrarClientesConSusPublicaciones(publicacion_list, QTY_PUBLICACION,cliente_list,QTY_CLIENTE);
	    		  }
	    	  	  	  else
	    	  	      	  {
	    	  	    	  printf ("\n*****************************************\n");
	    	  	    	  printf ("\nNO HAY CLIENTES CARGADOS PARA MOSTRAR!\n");
	    	  	    	  printf ("\n*****************************************\n");
	    	  	    	  }
	   	      break;
	    case 8:
	    	  if (cliente_flagLimite (cliente_list, QTY_CLIENTE) != 0)
	    	  	  {
					 printf ("\n*****************************************************");
					 printf ("\n*****************    INFORMAR    ********************\n");
					 printf ("*****************************************************\n");
					 do{
						printf (  "\n*********"
								  "\n* MENU  *"
								  "\n*********"
								  "\n1-Cliente con más avisos.\n"
								  "2-Cantidad de avisos pausados.\n"
								  "3-Rubro con mas avisos.\n"
								  "4-Salir\n\n");

									if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion2, 1, 4, 3) != -1)
												{
													switch (opcion2)
													{
														case 1:
															printf ("\n*****************************************************");
															printf ("\n********    Cliente con mas avisos   ********\n");
															printf ("*****************************************************\n");
															CalcularAvisosClientes(publicacion_list, QTY_PUBLICACION,cliente_list,QTY_CLIENTE, &clienteMasAvisos);
															printf("\nEL CLIENTE CON MAS AVISOS ES EL: %d\n", clienteMasAvisos	);
															cliente_printForId(cliente_list,QTY_CLIENTE, clienteMasAvisos);

															break;
														case 2:
															printf ("\n*****************************************************");
															printf ("\n********    Cantidad de avisos pausados   ********\n");
															printf ("*****************************************************\n");
															sumarPausadosPublicacionesClientes(publicacion_list, QTY_PUBLICACION, &cantAvisosPausados);
															printf("\nLA CANTIDAD DE AVISOS PAUSADOS ES DE : %d\n", cantAvisosPausados);
															break;
														case 3:
															printf ("\n*****************************************************");
															printf ("\n************   Rubro con mas avisos.   ************\n");
															printf ("*****************************************************\n");
															calcularRubroPublicaciones(publicacion_list, QTY_PUBLICACION, &rubroConMasAvisos);
															printf("\nEL RUBRO CON MAS PUBLICACIONES ES EL: %d\n", rubroConMasAvisos);
															break;
													}
												}
					  }while(opcion2!=4);
					 break;
					  return EXIT_SUCCESS;
									  }
									  else
										  {
										  printf ("\n*****************************************\n");
										  printf ("\nNO HAY CLIENTES CARGADOS PARA MOSTRAR INFORMACION!\n");
										  printf ("\n*****************************************\n");
										  }
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

		   		MostrarClientesConSusPublicaciones(publicacion_list, QTY_PUBLICACION,cliente_list,QTY_CLIENTE);




		   		ClienteConMasAvisosActivos(publicacion_list, QTY_PUBLICACION,cliente_list,QTY_CLIENTE, &cantAvisosActivos);
				printf("\nCLIENTE CON MAS AVISOS ACTIVOS: %d\n", cantAvisosActivos);
				cliente_printForId(cliente_list,QTY_CLIENTE, cantAvisosActivos);



				ClienteConMasAvisosPausados(publicacion_list, QTY_PUBLICACION,cliente_list,QTY_CLIENTE, &cantMasAvisosPausados);
				printf("\nCLIENTE CON MAS AVISOS PAUSADOS: %d\n", cantMasAvisosPausados);
				cliente_printForId(cliente_list,QTY_CLIENTE, cantMasAvisosPausados);


		   	      break;

	    case 10:
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
	}
    }while (opcion != 10);
	return EXIT_SUCCESS;
}


