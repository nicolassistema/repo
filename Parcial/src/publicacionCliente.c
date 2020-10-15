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


/*
 * publicacionCliente_chargeArray :
 * pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * mensaje : El mensaje que imprime para pedir un valor.
 * mensajeError: El mensaje que imprime si el rango no es valido.
 * minimo : valor minimo valido (inclusive)
 * maximo : valor maximo valido (inclusive)
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */



int publicacionCliente_chargeArray (Publicacion *listP, int lenP,Cliente *listC, int lenC)
{
	Publicacion auxPublicacion;
	int retorno = -1;

	cliente_headerArray();
	cliente_printArray(listC, QTY_CLIENTE);
	if (listP != NULL && lenP > 0)
	{
////////////////////	////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		do
		{
			utn_getNumero("Ingrese id del Cliente: ",
					"\nError al ingresar. Por favor ",
					&auxPublicacion.idCliente, 0, 100, 5);

			if (cliente_findArrayById(listC, lenC, auxPublicacion.idCliente)
					== -1)
			{
				printf("\nEL ID NO EXISTE! INGRESE EL ID CORRECTO!\n");
			}
		} while (cliente_findArrayById(listC, lenC, auxPublicacion.idCliente)
				== -1);
	}
	if (utn_getNumero("Ingrese numero de rubro: ",
			"\nError al ingresar. Por favor ", &auxPublicacion.numeroRubro, 0,
			99999, 5) != 0)
	{
		return -1;
	}
	if (utn_getAlfanumerico("Ingrese texto: ", "\nError al ingresar.\n",
			auxPublicacion.texto, LONG_NAME_PUBLICACION, 5) != 0)
	{
		return -1;
	}

	if (utn_getAceptaRechaza("\nAcepta el ingreso? s/n: ",
			"ERROR al ingresar opcion. \n", 's', 'n') == 1)
	{
		auxPublicacion.id = utn_idIncremental2();
		auxPublicacion.estPubli = ACTIVA;
		strcpy(auxPublicacion.descripcionEstado, "ACTIVA");
		if (publicacion_addArray(listP, lenP,
				auxPublicacion.id, ///////NO TOCAR////////////////////////
				auxPublicacion.idCliente, auxPublicacion.numeroRubro,
				auxPublicacion.estPubli, auxPublicacion.descripcionEstado,
				auxPublicacion.texto
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
				) == 0)
		{
			retorno = 0;
		}
		publicacion_printForId(listP, lenP, auxPublicacion.id);
		printf("\n*****************************************************");
		printf("\n                    ALTA EXITOSA!                  \n");
		printf("*****************************************************\n\n");
	}
	else
	{
		retorno = 0;
	}

	return retorno;
}

/*
 * obtenerIdClienteXIdPublicacion : borrado de publicacion
 * pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * mensaje : El mensaje que imprime para pedir un valor.
 * mensajeError: El mensaje que imprime si el rango no es valido.
 * minimo : valor minimo valido (inclusive)
 * maximo : valor maximo valido (inclusive)
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */


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




 /*
  * borradoEnCascadaCLientePublicacion : borrado de publicacion
  * pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
  * mensaje : El mensaje que imprime para pedir un valor.
  * mensajeError: El mensaje que imprime si el rango no es valido.
  * minimo : valor minimo valido (inclusive)
  * maximo : valor maximo valido (inclusive)
  * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
  * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
  *
  */

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


/*
 * prepararParaPublicacion_pausada : borrado de publicacion
 * pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * mensaje : El mensaje que imprime para pedir un valor.
 * mensajeError: El mensaje que imprime si el rango no es valido.
 * minimo : valor minimo valido (inclusive)
 * maximo : valor maximo valido (inclusive)
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */


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


/*
 * reanudarPublicacionForId : borrado de publicacion
 * pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * mensaje : El mensaje que imprime para pedir un valor.
 * mensajeError: El mensaje que imprime si el rango no es valido.
 * minimo : valor minimo valido (inclusive)
 * maximo : valor maximo valido (inclusive)
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */

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



/*
 * prepararParaPublicacion_reanudar : borrado de publicacion
 * pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * mensaje : El mensaje que imprime para pedir un valor.
 * mensajeError: El mensaje que imprime si el rango no es valido.
 * minimo : valor minimo valido (inclusive)
 * maximo : valor maximo valido (inclusive)
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */


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


/*
 * imprimaProductoElegido : borrado de publicacion
 * pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * mensaje : El mensaje que imprime para pedir un valor.
 * mensajeError: El mensaje que imprime si el rango no es valido.
 * minimo : valor minimo valido (inclusive)
 * maximo : valor maximo valido (inclusive)
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */


//Punto 7

int imprimaProductoElegido(Publicacion *listP, int lenP, int id)
{
	int retorno = -1;
	int i;

	for (i = 0; i < lenP; i++)
	{
		if (listP[i].id == id && listP[i].isEmpty == FALSE)
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
					,listP[i].id                  /////////NO TOCAR//////////////
					,listP[i].idCliente
					,listP[i].numeroRubro
					,listP[i].estPubli
					,listP[i].descripcionEstado
					,listP[i].texto);
			retorno = 0;
		}
	}
	return retorno;
}



/*
 * imprimirClientes : borrado de publicacion
 * pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * mensaje : El mensaje que imprime para pedir un valor.
 * mensajeError: El mensaje que imprime si el rango no es valido.
 * minimo : valor minimo valido (inclusive)
 * maximo : valor maximo valido (inclusive)
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */

void imprimirClientes(Publicacion *listP, int lenP,Cliente *listC, int lenC)
{
	int i;
	int j;
	int conPublicacionesActivas;

	for (i = 0; i < lenC; i++)
	{
		conPublicacionesActivas = 0;
		if (listC[i].id != 0)
		{
			cliente_printForId(listC, lenC, listC[i].id);
			publicacion_headerArray();

			for (j = 0; j < lenP; j++)
			{
				if (listC[i].isEmpty == FALSE&& listP[j].idCliente == listC[i].id)
				{
					conPublicacionesActivas++;
					imprimaProductoElegido(listP, lenP, listP[j].id);
				}
			}
			printf("\n%s %d\n\n\n", "Publicaciones activas",conPublicacionesActivas);
			printf("*********************************************************************************************");
		}
	}
}



/*
 * publicacionesPorCLiente : borrado de publicacion
 * pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * mensaje : El mensaje que imprime para pedir un valor.
 * mensajeError: El mensaje que imprime si el rango no es valido.
 * minimo : valor minimo valido (inclusive)
 * maximo : valor maximo valido (inclusive)
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */

//Punto 4
void publicacionesPorCLiente(Publicacion * listP, int lenP,Cliente * listC, int lenC, int id)
{
	int i;
	int j;
	publicacion_headerArray();
	for(i=0;i<lenC; i++)
	{
		if(listC[i].id == id && listC[i].isEmpty==FALSE )
		{
			for(j=0;j<lenP;j++)
			{
				if(listP[j].idCliente == listC[i].id && listP[j].isEmpty == FALSE )
				{
					publicacion_printForIdSinHeader  (listP, lenP, listP[j].id);
				}
			}
		}
	}
}




/*
 * publicacionesPorCLienteABorrar : borrado de publicacion
 * pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * mensaje : El mensaje que imprime para pedir un valor.
 * mensajeError: El mensaje que imprime si el rango no es valido.
 * minimo : valor minimo valido (inclusive)
 * maximo : valor maximo valido (inclusive)
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */


void publicacionesPorCLienteABorrar(Publicacion * listP, int lenP,Cliente * listC, int lenC, int id)
{
	int i;
	int j;

	for(i=0;i<lenC; i++)
	{
		if(listC[i].id == id && listC[i].isEmpty==FALSE )
		{
			for(j=0;j<lenP;j++)
			{
				if(listP[j].idCliente == listC[i].id && listP[j].isEmpty == FALSE )
				{
					publicacion_removeArray( listP, lenP, listP[j].id);
				}
			}
		}
	}
}





/*
 * borradoEnCascadaCLientePublicacion : borrado de publicacion
 * pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * mensaje : El mensaje que imprime para pedir un valor.
 * mensajeError: El mensaje que imprime si el rango no es valido.
 * minimo : valor minimo valido (inclusive)
 * maximo : valor maximo valido (inclusive)
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */

int borradoEnCascadaCLientePublicacion(Publicacion * listP, int lenP,Cliente * listC, int lenC)
{
    int retorno = -1;
    int idAux;

    if (listP!=NULL&& lenP>0&& listC != NULL && lenC>0)
    {
   	 cliente_headerArray();
     cliente_printArray(listC, QTY_CLIENTE);

        if(utn_getNumero ("Ingrese id del Cliente: ", "\nError al ingresar. Por favor ",&idAux, 0, 999, 5)!= -1)
        {
            	publicacionesPorCLiente(listP,lenP,listC,lenC, idAux);
            	if (utn_getAceptaRechaza ("\nAcepta el ingreso? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n')==1)
                {
            		publicacionesPorCLienteABorrar(listP,lenP,listC, lenC,  idAux);
            		cliente_removeArray(listC,lenC, idAux);
            		printf("\n*****************************************************");
            		printf("\n             BORRADO EXITOSO!\n");
            		printf("*****************************************************\n\n");
                }
                else
                {
                     printf("\n ERROR - No ingreso s / n (case sensitive)");
                }
         }
     }
    return retorno;
}



/*
 * CalcularAvisosClientes : calcular avisos cliente
 * pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * mensaje : El mensaje que imprime para pedir un valor.
 * mensajeError: El mensaje que imprime si el rango no es valido.
 * minimo : valor minimo valido (inclusive)
 * maximo : valor maximo valido (inclusive)
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */


//Punto 8

//(A) Cliente con más avisos.

void CalcularAvisosClientes(Publicacion* listP,int lenP, Cliente* listC,int lenC, int *autCliente)
{
	int i;
	int j;
	int contador;
	int max;
	int flag = 0;
	int clienteAMostrar;

	for (i = 0; i < lenC; i++)
	{
		contador = 0;
		if(listC[i].isEmpty == FALSE)
		{
			for(j=0;j<lenP;j++)
			{
				if(listC[i].id==listP[j].idCliente && listP[j].isEmpty == FALSE )
				{
					contador++;
				}
			}
		}
		if (contador > max || flag ==0)
			{
			max = contador;
				clienteAMostrar = listC[i].id;
				flag=1;
			}
	}
	*autCliente = clienteAMostrar;
}







/*
 * CalcularAvisosClientes : calcular avisos cliente
 * pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * mensaje : El mensaje que imprime para pedir un valor.
 * mensajeError: El mensaje que imprime si el rango no es valido.
 * minimo : valor minimo valido (inclusive)
 * maximo : valor maximo valido (inclusive)
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */



//b) Cliente con más avisos activos

void ClienteConMasAvisosActivos(Publicacion* listP,int lenP, Cliente* listC,int lenC, int *autCliente)
{
	int i;
	int j;
	int contador;
	int max;
	int flag = 0;
	int clienteAMostrar;

	for (i = 0; i < lenC; i++)
	{
		contador = 0;
		if(listC[i].isEmpty == FALSE)
		{
			for(j=0;j<lenP;j++)
			{
				if(listC[i].id==listP[j].idCliente && listP[j].isEmpty == FALSE && listP[j].estPubli == ACTIVA )
				{
					contador++;
				}
			}
		}
		if (contador > max || flag ==0)
			{
			max = contador;
				clienteAMostrar = listC[i].id;
				flag=1;
			}
	}
	*autCliente = clienteAMostrar;
}



//c) Cliente con más avisos pausados.

void ClienteConMasAvisosPausados(Publicacion* listP,int lenP, Cliente* listC,int lenC, int *autCliente)
{
	int i;
	int j;
	int contador = 0;
	int max;
	int flag = 0;
	int clienteAMostrar;

	for (i = 0; i < lenC; i++)
	{
		contador = 0;
		if(listC[i].isEmpty == FALSE)
		{
			for(j=0;j<lenP;j++)
			{
				if(listC[i].id==listP[j].idCliente && listP[j].isEmpty == FALSE && listP[j].estPubli == PAUSADA )
				{
					contador++;
				}
			}
		}
		if (contador > max || flag ==0)
			{
			max = contador;
				clienteAMostrar = listC[i].id;
				flag=1;
			}
	}
	*autCliente = clienteAMostrar;
}







//=============================================================================================================
/*
 * sumarPausadosPublicacionesClientes : sumar pausado publicacion cliente
 * pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * mensaje : El mensaje que imprime para pedir un valor.
 * mensajeError: El mensaje que imprime si el rango no es valido.
 * minimo : valor minimo valido (inclusive)
 * maximo : valor maximo valido (inclusive)
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */

//(B)
int sumarPausadosPublicacionesClientes(Publicacion* listP,int lenP,int *salida)
{
    int contador = 0;
    for(int j = 0 ; j < lenP;j++){

         if(listP[j].estPubli != 1  && listP[j].isEmpty == FALSE ){
                contador++;
          }
    }
    *salida = contador;
    return 0;
}


//(C) Rubro con mas avisos.
void calcularRubroPublicaciones(Publicacion* listP,int lenP,int *autRubro)
{
int contador = 0;
int rubroMax = 0;
int flag = 0;
int rubroAMostrar =0;
int i;
int j;

	for (i = 0; i < lenP; i++)
	{
		contador = 0;
		for (j = 0; j < lenP; j++)
		{
			if (listP[j].numeroRubro== i&& listP[j].isEmpty==FALSE && listP[j].estPubli == ACTIVA)
			{
				contador++;
			}
		}
		if (contador > rubroMax || flag == 0)
		{
			rubroAMostrar = i;
			rubroMax = contador;
			flag=1;
		}
	}
	*autRubro = rubroAMostrar;
}





//=============================================================================================================
/*
 * contadorClientePubliciacacionBiId : contador de publicaciones por id
 * mensaje : El mensaje que imprime para pedir un valor.
 * mensajeError: El mensaje que imprime si el rango no es valido.
 * minimo : valor minimo valido (inclusive)
 * maximo : valor maximo valido (inclusive)
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */
int  contadorClientePubliciacacionBiId (Cliente *listC,int lenC, Publicacion *listP,int lenP, int id)
{
    int i;
    int j;
    int contadorPublicacion = 0;
    int retorno = -1;

    for(i=0; i<lenC; i++)
    {
    	if(listC[i].id == id && listC[i].isEmpty == FALSE)
    	{
			for(j=0; j<lenP; j++)
				{
					if(listP[j].isEmpty==FALSE && listP[j].idCliente==listC[i].id)
					{
						contadorPublicacion++;
					}
				}
    	}retorno=contadorPublicacion;
    }
    return retorno;
}


//=============================================================================================================
/*
 * contadorClientePubliciacacionBiId : contador de publicaciones por id
 * mensaje : El mensaje que imprime para pedir un valor.
 * mensajeError: El mensaje que imprime si el rango no es valido.
 * minimo : valor minimo valido (inclusive)
 * maximo : valor maximo valido (inclusive)
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */

void MostrarClientesConSusPublicaciones(Publicacion* listP,int lenP, Cliente* listC,int lenC)
{
    int i;//clientes
    int j;//Publicaciones
    char flagTienePunlicacion;

    for(i=0; i<lenC; i++)
    {
       if(listC[i].isEmpty==FALSE)
       {
        printf("\n\nCliente: %s %s | Cantidad de publicaciones: %d"
        		"\n***********************************************", listC[i].nombre, listC[i].apellido,
		contadorClientePubliciacacionBiId (listC,lenC, listP,lenP, listC[i].id));
        flagTienePunlicacion='n';
        publicacion_headerArray();
        for(j=0; j<lenP; j++)
        {
            if(listP[j].isEmpty == FALSE && listP[j].idCliente== listC[i].id )
            {
            	printf(
            						" %-6d "
            						" %-10d "
            						"%-12d "
            						"%-12d "
            						"%-15s "
            						"%-13s "
            						" \n"
            						,listP[j].id
            						,listP[j].idCliente
            						,listP[j].numeroRubro
            						,listP[j].estPubli
            						,listP[j].descripcionEstado
            						,listP[j].texto);
            	flagTienePunlicacion='s';
            }
        }
        if(flagTienePunlicacion=='n')
        {
            printf("Este cliente no tiene publicaciones\n");
        }

       }
    }
}





/*
void MostrarClientesConSusPublicaciones(Publicacion* listP,int lenP, Cliente* listC,int lenC)
{
    int i;//clientes
    int j;//Publicaciones
    char flagTienePunlicacion;

    for(i=0; i<lenC; i++)
    {
       if(listC[i].isEmpty==FALSE)
       {
        printf("\n\nCliente: %s %s | Cantidad de publicaciones: %d"
        		"\n***********************************************", listC[i].nombre, listC[i].apellido,
		contadorClientePubliciacacionBiId (listC,lenC, listP,lenP, listC[i].id));
        flagTienePunlicacion='n';
        publicacion_headerArray();
        for(j=0; j<lenP; j++)
        {
            if(listP[j].isEmpty == FALSE && listP[j].idCliente== listC[i].id )
            {
            	printf(
            						" %-6d "
            						" %-10d "
            						"%-12d "
            						"%-12d "
            						"%-15s "
            						"%-13s "
            						" \n"
            						,listP[j].id
            						,listP[j].idCliente
            						,listP[j].numeroRubro
            						,listP[j].estPubli
            						,listP[j].descripcionEstado
            						,listP[j].texto);
            	flagTienePunlicacion='s';
            }
        }
        if(flagTienePunlicacion=='n')
        {
            printf("Este cliente no tiene publicaciones\n");
        }

       }
    }
}


*/









/*
void publicacionArrayToBuffer(Publicacion* listP,Publicacion *listPBuffer,int lenP)
{
	 int i;

	    for(i=0; i<lenP; i++)
	    {
	    	if(listP[i].isEmpty==FALSE)
	    	{
	    		listPBuffer[i].id =listP[i].id;
	    		listPBuffer[i].isEmpty=listP[i].isEmpty;
	    		listPBuffer[i].idCliente =listP[i].idCliente;
	    		listPBuffer[i].numeroRubro =listP[i].numeroRubro;
	    		listPBuffer[i].estPubli =listP[i].estPubli;
	    		strcpy(listPBuffer[i].descripcionEstado,listP[i].descripcionEstado);
	    		strcpy(listPBuffer[i].texto,listP[i].texto);
	    	}
	    }
}




void clienteArrayToBuffer(Cliente* listC,Cliente *listPBuffer,int lenC)
{
	 int i;

	    for(i=0; i<lenC; i++)
	    {
	    	if(listC[i].isEmpty==FALSE)
	    	{
	    		listPBuffer[i].id =listC[i].id;
	    		listPBuffer[i].isEmpty=listC[i].isEmpty;
	    	strcpy(listPBuffer[i].nombre ,listC[i].nombre);
	    	strcpy(listPBuffer[i].apellido ,listC[i].apellido);
	    		listPBuffer[i].cuit =listC[i].cuit;
	    	}
	    }
}
*/




/*
ordernarPorCantPublicaciones(Publicacion* listP,int lenP, Cliente* listC,int lenC)
{
	 int flagSwap;
	  int i;
	  int contador = 0;

	  int nuevoLimite;


AuxEstruct auxEstruct;
//AuxEstruct buffer;

//clienteArrayToBuffer(listC,&auxC,lenC);
//publicacionArrayToBuffer(listP,&auxP,lenP);
HardcodeoAuxClientePublicacion (&auxEstruct, listC, lenC,listP, lenP);



for(i=0;i<lenC;i++)
{

//printf("El valor de la cantidad: %d",auxEstruct[i].cantPublicacion);


}


do
	{
	  flagSwap = 0;

	  for (i = 0; i < nuevoLimite; i++)
	    {
	      contador++;
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      if (auxEstruct[i].cantPublicacion > auxEstruct[i+1].cantPublicacion)

////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////

//		  ||(0==strcmp (list[i].lastName, list[i + 1].lastName) &&
//		      (((list[i].sector > list[i + 1].sector)&&(order == 1))
//			  ||((list[i].sector < list[i + 1].sector) &&(order == 0)))))
		{
		  flagSwap = 1;
		  buffer = auxEstruct[i];
		  auxEstruct[i] = auxEstruct[i + 1];
		  auxEstruct[i + 1] = buffer;
		}
	    }
	  nuevoLimite--;
	}
   while (flagSwap);







}
*/
