/*
 * parser.c
 *
 *  Created on: 14 nov. 2020
 *      Author: nico
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		int contadorEClientes=0;

		if(pFile != NULL && pArrayListCliente != NULL)
		{
				do
				{
					if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxiliarId,auxiliarNombre,auxiliarApellido,auxiliarCuit)== 4)
					{
						if(cliente_newParametrosTxt(auxiliarId,auxiliarNombre,auxiliarApellido,auxiliarCuit) >= 0)
						{
							auxEmployee = (Cliente*) cliente_newParametrosTxt(auxiliarId,auxiliarNombre,auxiliarApellido,auxiliarCuit);
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
int parser_ClienteFromBinary(FILE* pFile , LinkedList* pArrayListCliente)
{
	int retorno = -1;
		Cliente* auxPCliente;
		Cliente auxCliente;
		char auxiliarId[4096];
		char auxiliarNombre[4096];
		char auxiliarCuit[4096];
		char auxiliarApellido[4096];
		int contadorClientes=0;

		if(pFile != NULL && pArrayListCliente != NULL)
		{
			if(pFile != NULL)
			{

				do
				{
					if(fread(&auxCliente,sizeof(Cliente),1, pFile)==1)
					{
		                sprintf(auxiliarId, "%d", auxCliente.id);
		                strcpy(auxiliarNombre, auxCliente.nombre);
		                sprintf(auxiliarCuit, "%d",auxCliente.cuit);
		                sprintf(auxiliarApellido,  auxCliente.apellido);

						if(cliente_newParametrosTxt(auxiliarId,auxiliarNombre,auxiliarCuit,auxiliarApellido) >= 0)
						{
							auxPCliente = (Cliente*) cliente_newParametrosTxt(auxiliarId,auxiliarNombre,auxiliarCuit,auxiliarApellido);
							if(ll_add(pArrayListCliente,auxPCliente)==0)
							{
								retorno = 0;
								contadorClientes++;
							}

						}
					}
				}while(!feof(pFile));
			}
		}
		printf("Se cargaron %d clientes\n",contadorClientes);
		return retorno;
}
