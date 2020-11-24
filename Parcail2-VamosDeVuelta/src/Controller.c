#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"
#include <string.h>
#include "Cliente.h"
#include "Afiches.h"


#define LEN_AUX 128

static int idMaximoEncontrado(LinkedList* pArrayListCliente, int* idMaximo);



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Nombre del archivo a cargar
 * \param pArrayListEmployee LinkedList* Puntero del tipo LinkedList* a la lista donde se guardará la información
 * \return int 0 si salió OK o (-1) ERROR
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListCliente)
{
	int retorno = -1;
	FILE *pArch;
	if(path != NULL && pArrayListCliente != NULL)
	{

		pArch = fopen(path, "rw");
		if(pArch != NULL && parser_ClienteFromText(pArch,pArrayListCliente)==0)
		{
			printf("Archivo cargado existosamente\n");
			retorno = 0;
			fclose(pArch);
		}
		else

			printf("El archivo no puede abrirse\n");
	}

	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.dat (modo binario).
 *
 * \param path char* Nombre del archivo a cargar
 * \param pArrayListEmployee LinkedList* Puntero del tipo LinkedList* a la lista donde se guardará la información
 * \return int 0 si salió OK o (-1) ERROR
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListCliente)
{
	int retorno = -1;
	FILE *pArch;
	if(path != NULL && pArrayListCliente != NULL)
	{

		pArch = fopen(path, "rb");
		if(pArch != NULL && parser_ClienteFromBinary(pArch,pArrayListCliente)==0)
		{
			printf("Archivo cargado existosamente\n");
			retorno = 0;
			fclose(pArch);
		}
		else

			printf("El archivo no puede abrirse\n");
	}

	return retorno;
}
/** \brief Alta de empleados
 * \param pArrayListEmployee LinkedList* Puntero a la lista del tipo LinkedList* donde será añadido el empleado
 * \return int Retorna 0 OK o (-1) ERROR
 *
 */
int controller_addCliente(LinkedList* pArrayListCliente)
{
	int retorno=-1;
	Cliente* pAuxiliarCliente;
	char auxNombre[LEN_AUX];
	char auxApellido[LEN_AUX];
	char cuitAux[LEN_AUX];
	int idAux;

	if(pArrayListCliente != NULL)
	{
		if(!(utn_getNombre(auxNombre, LEN_AUX,"Ingrese nombre\n", "Valor incorrecto\n",2)) &&
		   !(utn_getNombre(auxApellido, LEN_AUX,"Ingrese apellido\n", "Valor incorrecto\n",2)) &&
		   !(utn_getCuit(cuitAux, LEN_AUX,"Ingrese cuittt\n", "Valor incorrecto\n",2)) &&
		   !(cli_cuitIsInList(pArrayListCliente, cuitAux)))
		{
			if(ll_len(pArrayListCliente) == 0)
			{
				idAux = 0;
			}
			else
			{
				idMaximoEncontrado(pArrayListCliente, &idAux);
				idAux = idAux + 1;
			}
			if(cliente_newParametros(idAux,auxNombre,cuitAux,auxApellido) >= 0)
			{
				pAuxiliarCliente = (Cliente*)cliente_newParametros(idAux,auxNombre,cuitAux,auxApellido);
				ll_add(pArrayListCliente,pAuxiliarCliente);
				retorno = 0;
				printf("Cliente creado correctamente en la ubicación %d\n", idAux);
			}
		}else
		  {
		    printf("\nEL CUIT YA EXISTE. INTENTE NUEVAMENTE\n");
		  }
	}
	return retorno;
}




/** \brief Alta de empleados
 * \param pArrayListEmployee LinkedList* Puntero a la lista del tipo LinkedList* donde será añadido el empleado
 * \return int Retorna 0 OK o (-1) ERROR
 *
 */
int controller_addAfiche(LinkedList* pArrayListAfiches,LinkedList* pArrayListAClientes)
{
	int retorno=-1;
	Afiche* pAuxiliarAfiche;
	int idAux;
	int idCliente;
	char nombreArchivo[LEN_AUX];
	int cantidadAfiches;
	char zona[LEN_AUX];
	char estado[LEN_AUX];
	int estadoNum;


	if(pArrayListAfiches != NULL)
	{

	    controller_ListCliente(pArrayListAClientes);
		if(
		    !(utn_getNumero(&idCliente, "Ingrese el di cliente\n", "Valor incorrecto\n", 0, 99999, 3))&&
		    !(utn_getNombre(nombreArchivo, LEN_AUX,"Ingrese nombre archivo\n", "Valor incorrecto\n",2)) &&
		   !(utn_getNombre(zona, LEN_AUX,"Ingrese zona\n", "Valor incorrecto\n",2)) &&
//		   !(utn_getNombre(estado, LEN_AUX,"Ingrese estado\n", "Valor incorrecto\n",2)) &&



		   !(cli_IdIsInList(pArrayListAClientes, &idCliente)))
		{
			if(ll_len(pArrayListAfiches) == 0)
			{
				idAux = 0;
			}
			else
			{
				idMaximoEncontrado(pArrayListAfiches, &idAux);
				idAux = idAux + 1;
			}

			strncpy(estado,"A cobrar",sizeof(estado));
			afiche_setEstado(pArrayListAfiches, estado);
			afiche_imprimir(pArrayListAfiches);

			if(afiche_newParametros(idAux,idCliente,nombreArchivo,cantidadAfiches,zona,estado,estadoNum) >= 0)
			{
			    pAuxiliarAfiche = (Afiche*)afiche_newParametros(idAux,idCliente,nombreArchivo,cantidadAfiches,zona,estado,estadoNum);
				ll_add(pArrayListAfiches,pAuxiliarAfiche);
				retorno = 0;
				printf("Afiche creado correctamente en la ubicación %d\n", idAux);
			}
		}else
		  {
		    printf("\nNo existe cleinte con ese id. INTENTE NUEVAMENTE\n");
		  }
	}
	return retorno;
}


/** \brief Modificar datos de empleado
 * \param pArrayListEmployee LinkedList* Puntero a la lista del tipo LinkedList* donde será modificado el empleado
 * \return int Retorna 0 OK o (-1) ERROR
 *
 */
int controller_editCliente(LinkedList* pArrayListCliente)
{
	int retorno = -1;
	Cliente* auxCliente;
	int index;
	int auxID;
	int opcionAux;
	char auxNombre[LEN_AUX];
	char auxApellido[LEN_AUX];
	char cuitAux[LEN_AUX];


	if(pArrayListCliente != NULL)
	{
		controller_ListCliente(pArrayListCliente);
		if(!utn_getNumero(&auxID,"Ingrese el ID que desea editar\n","ID inválido\n",0,ll_len(pArrayListCliente), 2))
		{
			index = controller_buscarPorIdArray(pArrayListCliente, auxID);
			auxCliente = (Cliente*)ll_get(pArrayListCliente,index);
			if(auxCliente != NULL)
			{
				cliente_imprimir(auxCliente);


				if(!utn_getNumero(&opcionAux,"Confirma modificar el empleado? [0-NO/1-SI]\n","Opción inválida\n",0,1,2) && opcionAux == 1)
				{
					if(!(utn_getNombre(auxNombre, LEN_AUX,"Ingrese nombre\n", "Valor incorrecto\n",2)) &&
					   !(utn_getNombre(auxApellido, LEN_AUX,"Ingrese apellido\n", "Valor incorrecto\n",2)) &&
					   !(utn_getNombre(cuitAux, LEN_AUX,"Ingrese cuit\n", "Valor incorrecto\n",2)))
					{
					retorno = 0;
					cliente_setNombre(auxCliente, auxNombre);
					cliente_setCuit(auxCliente, cuitAux);
					cliente_setApellido(auxCliente,auxApellido);
					}
				}
			}
		}
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista a ser actualizada
 * \return int Retorna 0 OK o (-1) ERROR
 *
 */
int controller_removeCliente(LinkedList* pArrayListCliente)
{
	int retorno = -1;
	int auxID;
	int opcionAux;
	int index;
	Cliente* auxCliente;

	if(pArrayListCliente != NULL)
	{
		controller_ListCliente(pArrayListCliente);
		if(!utn_getNumero(&auxID,"Ingrese el ID que desea eliminar\n","ID inválido\n",0,ll_len(pArrayListCliente), 2))
		{
			index = controller_buscarPorIdArray(pArrayListCliente, auxID);
			auxCliente = (Cliente*)ll_get(pArrayListCliente,index);
			if(auxCliente != NULL)
			{
				cliente_imprimir(auxCliente);

				if(!utn_getNumero(&opcionAux,"Confirma eliminar el cliente? [0-NO/1-SI]\n","Opción inválida\n",0,1,2) && opcionAux == 1)
				{
					retorno = 0;
					ll_remove(pArrayListCliente,index);
					cliente_delete(auxCliente);
					printf("Cliente eliminado correctamente\n");
				}
			}
		}
	}
	return retorno;
}


/** \brief Listar empleados
 * \param pArrayListEmployee LinkedList* Puntero a la lista a ser impresa
 * \return int 0 OK, (-1) ERROR
 *
 */
int controller_ListCliente(LinkedList* pArrayListCliente)
{
	int retorno=-1;
	int i;
	Cliente* bufferpCliente;
	bufferpCliente = cliente_new();

	if(pArrayListCliente != NULL)
	{
		retorno=0;

		for(i=0;i<ll_len(pArrayListCliente);i++)
		{
			bufferpCliente = ll_get(pArrayListCliente,i);
			cliente_imprimir(bufferpCliente);
		}

	}
	return retorno;
}



/** \brief Ordenar empleados
 * \param pArrayListEmployee LinkedList* Puntero a la lista a ser ordenada
 * \return int 0 OK, (-1) ERROR
 *
 */


int controller_sortCliente(LinkedList* pArrayListCliente)
{
		int retorno = -1;
		int opcion;
	 	int (*cliente_pFordenarNombre)(void*, void*) = cliente_ordenarNombre;


		if(pArrayListCliente != NULL)
		{
			retorno=0;
			if(!utn_getNumero(&opcion,"Ingrese órden [1-descendente / 0-ascendente]\n","Valor inválido\n",0,1,2))
			{
				printf("Espere, se está cargando la lista\n");
				if(ll_sort(pArrayListCliente,cliente_pFordenarNombre,opcion)==0)
				{
					printf("Fue ordenado correctamente\n");
					retorno = 0;
					controller_ListCliente(pArrayListCliente);
				}
			}
		}

		return retorno;
}


/** \brief Ordenar empleados por ID
 * \param pArrayListEmployee LinkedList* Puntero a la lista a ser ordenada
 * \return int 0 OK, (-1) ERROR
 *
 */


int controller_sortClientebyID(LinkedList* pArrayListCliente)
{
		int retorno = -1;
		int opcion;
//	 	int (*employee_ordenarID)(void*, void*) = employee_pFordenarID;


		if(pArrayListCliente != NULL)
		{
			retorno=0;
			if(!utn_getNumero(&opcion,"Ingrese órden [1-ascendente / 0-descendente]\n","Valor inválido\n",0,1,2))
			{
				printf("Espere, se está cargando la lista\n");
				if(ll_sort(pArrayListCliente,cliente_ordenarID,opcion)==0)
				{
					printf("Fue ordenado correctamente\n");
					retorno = 0;
					controller_ListCliente(pArrayListCliente);
				}
			}
		}

		return retorno;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path char* Puntero al archivo a ser guardado
 * \param pArrayListEmployee LinkedList* Puntero a la lista a ser guardada
 * \return int 0 OK, (-1) ERROR
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListCliente)
{
	int retorno=-1;
	int i;
	FILE* fpArchivo;
	int auxiliarId;
	char auxiliarNombre[NOMBRE_LEN];
	char auxApellido[NOMBRE_LEN];
	char auxCuit[NOMBRE_LEN];
	Cliente* auxCliente;

	if(pArrayListCliente != NULL && path != NULL)
	{

		fpArchivo = fopen(path,"w");
		if(fpArchivo != NULL)
		{
			retorno=0;
			for(i=0;i<ll_len(pArrayListCliente);i++)
			{
				auxCliente = (Cliente*)ll_get(pArrayListCliente,i);
				if(auxCliente != NULL)
				{
					if(!cliente_getId(auxCliente,&auxiliarId) &&
					   !cliente_getNombre(auxCliente,auxiliarNombre) &&
					   !cliente_getCuit(auxCliente,auxCuit) &&
					   !cliente_getApellido(auxCliente,auxApellido))
					{
						fprintf(fpArchivo,"%d,%s,%s,%s\n",auxiliarId,auxiliarNombre,auxApellido,auxCuit);
					}
				}

			}
			fclose(fpArchivo);
			printf("Archivo guardado correctamente\n");

		}
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.dat (modo binario).
 * \param path char* Puntero al archivo a ser guardado
 * \param pArrayListEmployee LinkedList* Puntero a la lista a ser guardada
 * \return int 0 OK, (-1) ERROR
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListCliente)
{
	int retorno=-1;
		int i;
		FILE* fpArchivo;
		Cliente* auxCliente;
		int contadorCliente = 0;
		int len;

		if(pArrayListCliente != NULL && path != NULL)
		{
			len = ll_len(pArrayListCliente);

			fpArchivo = fopen(path,"wb");
			if(fpArchivo != NULL)
			{
				retorno=0;
				for(i=0;i<len;i++)
				{
					auxCliente = ll_get(pArrayListCliente, i);
					if(fwrite(auxCliente, sizeof(Cliente),1,fpArchivo)==1)
					{
						contadorCliente++;
					}
				}
				fclose(fpArchivo);
				printf("Archivo cargado correctamente\n");
				printf("Se guardaron %d clientes\n",contadorCliente);
			}
		}
		return retorno;
}



/**
 * \brief Busca un empleado por ID
 * \param pArrayListEmployee LinkedList* Puntero a la lista que será evaluada
 * \return int Devuelve la ubicacion donde se encuentra el ID(OK), (-1)ERROR, (-2)ID NO ENCONTRADO
 */


int controller_buscarPorIdArray(LinkedList* pArrayListCliente, int id)
{
	int retorno=-1;
	int i;
	int idAux;
	Cliente* auxCliente;

	if(pArrayListCliente != NULL && id >= 0)
	{
		retorno = -2;
		for(i=0;i<ll_len(pArrayListCliente);i++)
		{
			auxCliente = ll_get(pArrayListCliente,i);
			cliente_getId(auxCliente, &idAux);

			if( idAux == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}



/**
 * \brief Busca un empleado por ID
 * \param pArrayListEmployee LinkedList* Puntero a la lista que será evaluada
 * \return int Devuelve la ubicacion donde se encuentra el ID(OK), (-1)ERROR, (-2)ID NO ENCONTRADO
 */

static int idMaximoEncontrado(LinkedList* pArrayListCliente, int* idMaximo)
{
	int retorno = -1;
	int i;
	int flag = 0;
	int idAuxMaximo;
	int idAuxiliar;
	Cliente* auxiliarCliente;
	Cliente* auxClie;

	if(pArrayListCliente != NULL && idMaximo != NULL)
	{
		retorno=0;
		for(i=0;i<ll_len(pArrayListCliente);i++)
		{
			auxClie = ll_get(pArrayListCliente,i);
			cliente_getId(auxClie,&idAuxiliar);
			if(!flag)
			{
				auxiliarCliente = ll_get(pArrayListCliente,i);
				cliente_getId(auxiliarCliente,&idAuxMaximo);
				flag = 1;
			}
			else if(idAuxiliar > idAuxMaximo)
			{
				idAuxMaximo = idAuxiliar;
			}

		}
		*idMaximo = idAuxMaximo;

	}
	return retorno;
}

int controller_containsElemento(LinkedList* pArrayListCliente, Cliente* cliente )
{
	int retorno = -1;
	if(pArrayListCliente != NULL)
	{
		if(ll_contains(pArrayListCliente,cliente)==1)
		{
			printf("Cliente encontrado\n");
			retorno = 0;
		}
	}

	return retorno;
}
