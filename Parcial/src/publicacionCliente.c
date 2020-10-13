/*
 * publicacionCliente.c
 *
 *  Created on: 12 oct. 2020
 *      Author: nico
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





int publicacionCliente_chargeArray (Publicacion *listP, int lenP,Cliente *listC, int lenC)
{
  Publicacion auxPublicacion;
  int retorno = -1;

  cliente_headerArray();
  cliente_printArray(listC, QTY_CLIENTE);
  if (listP != NULL && lenP > 0)
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
	  if(publicacion_addArray (listP, lenP,
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
	  publicacion_printForId  (listP,lenP, auxPublicacion.id);
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



 void obtenerIdClienteXIdPublicacion(Publicacion *listP, int lenP,Cliente *listC, int lenC, int *idCliente, int idPublicidad)
 {
	int i;
	int j;
	for (i = 0; i < lenP; i++)
	{
		if (idPublicidad == listP[i].id && listP[i].isEmpty == FALSE)
		{
			for (j = 0; j < lenC; j++)
			{
				if (listP[i].idCliente == listC[j].id && listC[i].isEmpty == FALSE && listP[i].isEmpty == FALSE)
				{
					*idCliente = listC[j].id;
				}
			}
		}
	}
}

 //Punto 5////////////////////////////////////
void pausarPublicacionForId(Publicacion *listP, int lenP, int id)
{
	int i;

	for(i=0;i<lenP;i++)
	{
		if(listP[i].id == id && listP[i].isEmpty == FALSE )
		{
			listP[i].estPubli = PAUSADA;
			strcpy(listP[i].descripcionEstado,"PAUSADA");
		}

	}
}




int prepararParaPublicacion_pausada (Publicacion *listP, int lenP,Cliente *listC, int lenC)
{
	int retorno = -1;
	int bufferID;
	int bufferIdCliente;

	if (listP != NULL && lenP > 0)
	{
		utn_getNumero("Ingrese id de la publicacion: ","\nError al ingresar. Por favor ", &bufferID, 0, 999, 5);
		obtenerIdClienteXIdPublicacion(listP, lenP, listC, lenC,&bufferIdCliente, bufferID);

		if (publicacion_findArrayById(listP, lenP, bufferID) != -1)
		{
			if (publicacion_isPaused(listP, lenP, bufferID) != 0)
			{
				printf("\nCLIENTE\n");
				printf("***********\n");
				cliente_printForId(listC, lenC, bufferIdCliente);

				printf("\nPUBLICACION DEL CLIENTE\n");
				printf("**************************\n");
				publicacion_printForId(listP, lenP, bufferIdCliente);
				retorno = utn_getAceptaRechaza("\nAcepta Pausar Publicacion? s/n: ","ERROR al ingresar opcion. \n", 's', 'n');
				if (retorno == 1)
				{
					pausarPublicacionForId(listP, lenP, bufferID);
					retorno = 1;
					printf("\n*****************************************************");
					printf("\n             PAUSADO EXITOSO!\n");
					printf("*****************************************************\n\n");
				}
			}
			else
			{
				printf("\nNo se puede Pausar por que la publicacion se encuentra pausada\n");
			}
		}
		else
		{
			printf("\nEl ID NO existe\n");
		}
	}

	return retorno;
}



//Punto 6////////////////////////////////////
void reanudarPublicacionForId(Publicacion *listP, int lenP, int id)
{
	int i;

	for(i=0;i<lenP;i++)
	{
		if(listP[i].id == id && listP[i].isEmpty == FALSE )
		{
			listP[i].estPubli = ACTIVA;
			strcpy(listP[i].descripcionEstado,"ACTIVA");
		}

	}
}


int prepararParaPublicacion_reanudar (Publicacion *listP, int lenP,Cliente *listC, int lenC)
{
	int retorno = -1;
	int bufferID;
	int bufferIdCliente;

	if (listP != NULL && lenP > 0)
	{
		utn_getNumero("Ingrese id de la publicacion: ","\nError al ingresar. Por favor ", &bufferID, 0, 999, 5);
		obtenerIdClienteXIdPublicacion(listP, lenP, listC, lenC,&bufferIdCliente, bufferID);

		if (publicacion_findArrayById(listP, lenP, bufferID) != -1)
		{
			if (publicacion_isPaused(listP, lenP, bufferID) != 1)
			{
				printf("\nCLIENTE\n");
				printf("***********\n");
				cliente_printForId(listC, lenC, bufferIdCliente);

				printf("\nPUBLICACION DEL CLIENTE\n");
				printf("**************************\n");
				publicacion_printForId(listP, lenP, bufferIdCliente);
				retorno = utn_getAceptaRechaza("\nAcepta reanudar Publicacion? s/n: ","ERROR al ingresar opcion. \n", 's', 'n');
				if (retorno == 1)
				{
					reanudarPublicacionForId(listP, lenP, bufferID);
					retorno = 1;
					printf("\n*****************************************************");
					printf("\n             PAUSADO EXITOSO!\n");
					printf("*****************************************************\n\n");
				}
			}
			else
			{
				printf("\nNo se puede reanudar por que la publicacion se encuentra Activa\n");
			}
		}
		else
		{
			printf("\nEl ID NO existe\n");
		}
	}
	return retorno;
}




//Punto 7


/*
int imprimirPublicacionesAcitvasXId(Publicacion *listP, int lenP,Cliente *listC, int lenC, int id)
{
	int retorno = -1;
	int i;
	int j;

	if (listP != NULL && listP > 0)
	{
		for (i = 0; i < lenP; i++)
		{
			if (listP[i].id == id && listP[i].isEmpty == FALSE)
					//&& listP[i].estPubli == ACTIVA)
			{

				for (j = 0; j < lenC; j++)
				{
					if (listC[j].id == listP[i].idCliente)
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
										    ,listP[i].id/////////NO TOCAR//////////////
										    ,listP[i].idCliente
										    ,listP[i].numeroRubro
											,listP[i].estPubli
											,listP[i].descripcionEstado
											,listP[i].texto
										   );
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}
*/


int imprimaProductoElegido(Publicacion *listP, int lenP, int id)
{
    int retorno = -1;
int i;

    for(i=0;i<lenP;i++)
    {
        if(listP[i].id==id && listP[i].isEmpty == FALSE)
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

                                          //  ,list[id].isEmpty
                                            ,listP[i].id/////////NO TOCAR//////////////
                                            ,listP[i].idCliente
                                            ,listP[i].numeroRubro
                                            ,listP[i].estPubli
                                            ,listP[i].descripcionEstado
                                            ,listP[i].texto
                                           );
         retorno = 0;
        }

    }

return retorno;
}

/*
void  publicacionXid(Publicacion *listP, int lenP,Cliente *listC, int lenC, int *id)
{
	int i;

	for (i = 0; i < lenP; i++)
	{
		if (id == listP[i].id && listP[i].isEmpty == FALSE)
		{
			imprimirPublicacionesAcitvasXId(listP,lenP,listC, lenC, listP[i].id);
		}
	}
}
*/


/*
imprimirClientes(Publicacion *listP, int lenP,Cliente *listC, int lenC)
{
int i;
int j;
int n;
int id;

	if (listP != NULL && lenP > 0)
		{


		for (i = 0; i < lenC; i++)
				{

			for (j = 0; j < lenP; j++)
						{
				         if (listC[i].isEmpty == FALSE && listP[j].idCliente == listC[i].id)
							{
				        	 cliente_printForId  (listC,lenC,  listC[i].id);
								break;
							}
						}


			for (n = 0; n <= lenC; n++)
					{
						if (listC[n].isEmpty == FALSE && listP[j].idCliente == listC[n].id)
						{


//								printf("\nIMPRIMO CANTIDAD DE VECES POR CLIENTE\n");



							publicacion_headerArray();


							id = listP[j].id;
							if (publicacion_findArrayById (listC, lenC,  id) != -1)
							{
								imprimirPublicacionesAcitvasXId(listP,lenP,listC, lenC, listP[j].id);
							}
							else
							{
								printf("\nEl ID NO existe\n");
							}

						}
					}
				}
		}
}

*/


imprimirClientes(Publicacion *listP, int lenP,Cliente *listC, int lenC)
{

int i;
int j;
int conPublicacionesActivas;

        for (i = 0; i < lenC; i++)
                {
                conPublicacionesActivas = 0;

                if(listC[i].id!=0){
                            cliente_printForId  (listC,lenC,  listC[i].id);
                            publicacion_headerArray();
                            int mostroAlguno = 0;
                            for (j = 0; j < lenP; j++)
                                        {
                                           if (listC[i].isEmpty == FALSE && listP[j].idCliente == listC[i].id )
                                                    {
                                                        mostroAlguno = 1;
                                                        conPublicacionesActivas++;

                                                        imprimaProductoElegido(listP,lenP, listP[j].id);
                                                    }
                                        }
                                if(mostroAlguno==0){
                                }

                               printf("\n%s %d\n\n\n","Publicaciones activas",conPublicacionesActivas);
                               printf("*********************************************************************************************");
                }

                }
}
































