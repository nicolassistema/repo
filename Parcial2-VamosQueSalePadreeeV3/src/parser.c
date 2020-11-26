/*
 * parser.c
 *
 *  Created on: 14 nov. 2020
 *      Author: nico
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Afiches.h"
#include "Cliente.h"
#include "LinkedList.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* Puntero al archivo a ser descargado
 * \param pArrayListEmployee LinkedList* Puntero a la lista a ser cargada
 * \return int (-1) ERROR  0) OK
 *
 */
int parser_ClienteFromText(FILE* pFile , LinkedList* pArrayListCliente)
{
		int retorno = -1;
		Cliente* auxEmployee;
		char auxiliarId[4096];
		char auxiliarNombre[4096];
		char auxiliarApellido[4096];
		char auxiliarCuit[4096];
		char auxiliarCantidad[4096];
		int contadorEClientes=0;

		if(pFile != NULL && pArrayListCliente != NULL)
		{

				do
				{

					if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxiliarId,auxiliarNombre,auxiliarApellido,auxiliarCuit,auxiliarCantidad) == 5)
					{
						if(cliente_newParametrosTxt(auxiliarId,auxiliarNombre,auxiliarApellido,auxiliarCuit,auxiliarCantidad) >= 0)
						{
							auxEmployee = (Cliente*) cliente_newParametrosTxt(auxiliarId,auxiliarNombre,auxiliarApellido,auxiliarCuit,auxiliarCantidad);
							if(ll_add(pArrayListCliente,auxEmployee)==0)
							{
							retorno = 0;
							contadorEClientes++;

							}

						}
					}
				}while(!feof(pFile));
		}
		printf("Se cargaron %d empleados\n",contadorEClientes);
		return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.dat (modo binario).
 *
 * \param pFile FILE* Puntero al archivo a ser descargado
 * \param pArrayListEmployee LinkedList* Puntero a la lista a ser cargada
 * \return int (-1) ERROR  0) OK
 *
 */


int parser_AfichesFromText(FILE* pFile , LinkedList* pArrayListAfiches)
{
		int retorno = -1;
		Afiche* auxAfiches;

	    char idAux[4096];
	    char idClienteAux[4096];
		char nombreArchivoAux[4096];
		char cantidadAfichesAux[4096];
		char zonaAux [4096];
		char estadoNumAux[4096];
		int contadorEAfiches=0;

		if(pFile != NULL && pArrayListAfiches != NULL)
		{
				do
				{
					if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,idClienteAux,nombreArchivoAux,cantidadAfichesAux,zonaAux,estadoNumAux) == 6)
					{
						if(afiche_newParametrosTxt(idAux,idClienteAux,nombreArchivoAux,cantidadAfichesAux,zonaAux,estadoNumAux) >= 0)
						{
							auxAfiches = (Afiche*) afiche_newParametrosTxt(idAux,idClienteAux,nombreArchivoAux,cantidadAfichesAux,zonaAux,estadoNumAux);
							if(ll_add(pArrayListAfiches,auxAfiches)==0)
							{
							retorno = 0;
							contadorEAfiches++;

							}
						}
					}
				}while(!feof(pFile));
		}
		printf("Se cargaron %d afiches\n",contadorEAfiches);
		return retorno;
}

