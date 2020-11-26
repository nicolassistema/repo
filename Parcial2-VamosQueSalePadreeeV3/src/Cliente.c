/*
 * Employee.c
 *
 *  Created on: 14 nov. 2020
 *      Author: nico
 */


#include "Cliente.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"

#define LEN_AUX 128

static int isValidNombre(char* cadena,int longitud);
static int esNumerica(char* cadena, int limite);

/**
 * \brief Crea un espacio de memoria para un empleado
 * \param Void No recibe parámetros
 * \return Retorna un puntero al espacio de memoria donde será guardado el empleado
 *
 */

Cliente* cliente_new(void)
{
	Cliente* auxiliarP = NULL;
	auxiliarP = (Cliente*) malloc(sizeof(Cliente));
	return auxiliarP;
}

/**
 * \brief Crea un empleado conociendo sus parámetros
 * \param idStr char* Puntero id
 * \param nombreStr char* Puntero al nombre
 * \param horasTrabajadasStr char* Puntero a horasTrabajadas
 * \param sueldo char* Puntero a sueldo
 * \return Retorna un puntero al espacio de memoria donde será guardado el empleado
 *
 */

Cliente* cliente_newParametrosTxt(char* idStr,char* nombreStr,char* apellidoStr, char* cuitStr, char* cantidadVentas)
{
	Cliente* this = NULL;
	this = cliente_new();
	if(this != NULL && nombreStr != NULL && apellidoStr != NULL && cuitStr > 0)
	{
		if(	cliente_setNombre(this,nombreStr) == -1 ||
			cliente_setIdTxt(this,idStr) == -1 ||
			cliente_setCuit(this,cuitStr) == -1 ||
			cliente_setApellido(this, apellidoStr) == -1||
			cliente_setCantidadAfichesClienteTxt(this, cantidadVentas) == -1)
		{
			cliente_delete(this);
			this = NULL;
		}
	}
	return this;
}

/**
 * \brief Crea un empleado conociendo sus parámetros reales
 * \param id int Id con el que se cargará el empleado
 * \param nombre char* Puntero al nombre
 * \param horasTrabajadasStr int  HorasTrabajadas con las que se cargará el empleado
 * \param sueldo int Sueldo con el que se cargará el empleado
 * \return Retorna un puntero al espacio de memoria donde será guardado el empleado
 *
 */

Cliente* cliente_newParametros(int id, char* nombre,char* cuit, char* apellido, int cantidadVentas)
{
	Cliente* this = NULL;
	this = cliente_new();
	if(this != NULL && nombre != NULL && apellido != NULL && cuit != NULL)

	{
		if(	cliente_setId(this, id) == -1 ||
			cliente_setNombre(this, nombre) == -1 ||
			cliente_setCuit(this, cuit) == -1 ||
			cliente_setApellido(this, apellido) == -1 ||
			cliente_setCantidadAfichesCliente(this, cantidadVentas) == -1)
		{
			cliente_delete(this);
			this = NULL;
		}
	}
	return this;
}


/**
 * \brief Elimina el empleado pasado por parámetro
 * \param this Employee* Puntero al empleado a eliminar
 * \return void
 */


void cliente_delete(Cliente* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/**
 * \brief Cambia el nombre del empleado pasado por parámetro
 * \param this Employee* Puntero al empleado a modificar
 * \param nombre char* Puntero al nombre que se cambiará
 * \return int (-1) ERROR y (0) OK
 */

int envio_setZonaDestino(Cliente* this,char* nombreProducto)
{
	int retorno = -1;
	if(this != NULL && nombreProducto != NULL)
	{
		if(isValidNombre(nombreProducto,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->nombre,nombreProducto,NOMBRE_LEN);
		}
	}
	return retorno;
}

/**
 * \brief Se obtiene el nombre del empleado pasado por parámetro
 * \param this Employee* Puntero al empleado
 * \param nombre char* Puntero al nombre del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int cliente_setNombre(Cliente* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(isValidNombre(nombre,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->nombre,nombre,NOMBRE_LEN);
		}
	}
	return retorno;
}




int cliente_getNombre(Cliente* this,char* nombreProducto)
{
	int retorno = -1;
	if(this != NULL && nombreProducto != NULL)
	{
		retorno = 0;
		strncpy(nombreProducto,this->nombre,NOMBRE_LEN);
	}
	return retorno;
}

int cliente_setApellido(Cliente* this,char* apellido){

	int retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		if(isValidNombre(apellido,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->apellido,apellido,NOMBRE_LEN);
		}
	}
	return retorno;



}
int cliente_getApellido(Cliente* this,char* apellido){

	int retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		retorno = 0;
		strncpy(apellido,this->apellido,NOMBRE_LEN);
	}
	return retorno;


}

/**
 * \brief Se cambiará el id del empleado pasado por parámetro
 * \param this Employee* Puntero al empleado
 * \param id int ID que se cargará al empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int cliente_setId(Cliente* this,int idProducto)
{
	int retorno = -1;
	if(this != NULL && idProducto >= 0)
	{
		retorno = 0;
		this->id = idProducto;
	}
	return retorno;
}

/**
 * \brief Se cambiará el id del empleado pasado por parámetro
 * \param this Employee* Puntero al empleado
 * \param id char* Puntero al ID que se cargará al empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int cliente_setIdTxt(Cliente* this,char* idProducto)
{
	int retorno = -1;
	if(this != NULL && idProducto != NULL)
	{
		if(esNumerica(idProducto,10))
		{
			retorno = 0;
			this->id = atoi(idProducto);
		}
	}
	return retorno;
}

/**
 * \brief Se obtendrá el id del empleado pasado por parámetro
 * \param this Employee* Puntero al empleado
 * \param id int* Puntero al ID que se obtendrá del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */


int cliente_getId(Cliente* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}


/**
 * \brief Se obtendrá el id del empleado pasado por parámetro
 * \param this Employee* Puntero al empleado
 * \param id char* Puntero al ID que se obtendrá del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int cliente_getIdTxt(Cliente* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		sprintf(id,"%d",this->id);
	}
	return retorno;
}

/**
 * \brief Se cambiarán las horas trabajadas del empleado pasado por parámetro
 * \param this Employee* Puntero al empleado
 * \param horasTrabajadas int Cantidad de horas trabajadas que se cargará en el empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int cliente_setCuit(Cliente* this,char* cuit)
{
	int retorno = -1;
		if(this != NULL && cuit != NULL)
		{
			if(isValidNombre(cuit,NOMBRE_LEN))
			{
				retorno = 0;
				strncpy(this->cuit,cuit,NOMBRE_LEN);
			}
		}
		return retorno;
}


/**
 * \brief Se cambiarán las horas trabajadas del empleado pasado por parámetro
 * \param this Employee* Puntero al empleado
 * \param horasTrabajadas char* Puntero a la cantidad de horas trabajadas que se cargará en el empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */



/**
 * \brief Se obtendrán las horas trabajadas del empleado pasado por parámetro
 * \param this Employee* Puntero al empleado
 * \param horasTrabajadas int* Puntero a la cantidad de horas trabajadas que se obtendrá del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */


int cliente_getCuit(Cliente* this,char* cuit)
{
	int retorno = -1;
if(this != NULL && cuit != NULL)
{
	retorno = 0;
	strncpy(cuit,this->cuit,NOMBRE_LEN);
}
return retorno;
}



int cliente_setCantidadAfichesCliente(Cliente* this,int cantidadAfichesCliente){

	int retorno = -1;
	if(this != NULL && cantidadAfichesCliente >= 0)
	{
		retorno = 0;
		this->cantidadAfichesCliente = cantidadAfichesCliente;
	}
	return retorno;


}
int cliente_setCantidadAfichesClienteTxt(Cliente* this,char* cantidadAfichesCliente){

	int retorno = -1;
	if(this != NULL && cantidadAfichesCliente != NULL)
	{
		if(esNumerica(cantidadAfichesCliente,10))
		{
			retorno = 0;
			this->cantidadAfichesCliente = atoi(cantidadAfichesCliente);
		}
	}
	return retorno;




}
int cliente_getCantidadAfichesCliente(Cliente* this,int* cantidadAfichesCliente){

	int retorno = -1;
	if(this != NULL && cantidadAfichesCliente != NULL)
	{
		retorno = 0;
		*cantidadAfichesCliente = this->cantidadAfichesCliente;
	}
	return retorno;



}
int cliente_getCantidadAfichesClienteTxt(Cliente* this,char* cantidadAfichesCliente){


	int retorno = -1;
	if(this != NULL && cantidadAfichesCliente != NULL)
	{
		retorno = 0;
		sprintf(cantidadAfichesCliente,"%d",this->cantidadAfichesCliente);
	}
	return retorno;

}








/**********************************************************************/

/**
 * \brief Verifica si la cadena ingresada es un nombre valido, teniendo en cuenta guines y espacios
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int isValidNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
		    if((cadena[i] < 'a' || cadena [i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z')  && (cadena[i] < '0' || cadena[i] > '9')
		                       && (cadena[i] != '.' || cadena[0] == '.') && (cadena[i] != '-' || cadena[0] == '-'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}

/**
 * \brief Imprime los datos de un Empleado
 * \param pElemento Puntero al Empleado que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cliente_imprimir(Cliente* this)
{
	int retorno=-1;
	char idAux[LEN_AUX];
	char nombre[LEN_AUX];
	char apellido[LEN_AUX];
	char cuit[LEN_AUX];

	if(this != NULL)
	{
		retorno = 0;
		cliente_getIdTxt(this,idAux);
		cliente_getNombre(this,nombre);
		cliente_getApellido(this, apellido);
		cliente_getCuit(this, cuit);

		printf("ID: %10s - Nombre %10s - Apellido: %10s - Cuit %10s\n",idAux
																	   ,nombre
																	   ,apellido
																	   ,cuit);
		retorno = 0;
	}
	return retorno;
}



/**
 * \brief Imprime los datos de un Empleado
 * \param pElemento Puntero al Empleado que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cliente_imprimirGral(void* this)
{
	int retorno=-1;
	Cliente* auxElemento = (Cliente*) this;
	char idAux[LEN_AUX];
	char cuitAux[LEN_AUX];
	char apellidoAux[LEN_AUX];
	char nombreAux[NOMBRE_LEN];

	if(this != NULL)
	{
		retorno = 0;
		cliente_getIdTxt(auxElemento,idAux);
		cliente_getNombre(auxElemento,nombreAux);
		cliente_getApellido(this, apellidoAux);
		cliente_getCuit(auxElemento,cuitAux);

		printf("ID: %10s -Nombre:  %10s - Apellido: %10s - Cuit:  %10s\n",idAux
																	   ,nombreAux
																	   ,apellidoAux
																	   ,cuitAux);
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Ordena por nombre
 * \param EmpUno void* Puntero al Empleado que se busca ordenar
 * \param EmpDos void* Puntero al Empleado que se busca ordenar
 * \return int Retorna 0 (Si ambos parámetros son iguales)
 * 					   1 (Si EmpDos es mayor)
 * 					   -1 (Si EmpUno es mayor)
 */


int cliente_ordenarNombre(void* EmpUno, void* EmpDos)
{
	int retorno = 0;
	char auxNombre[NOMBRE_LEN];
	char auxNombreDos[NOMBRE_LEN];
	Cliente* auxUno;
	Cliente* auxDos;

		auxUno = (Cliente*)EmpUno;
		auxDos = (Cliente*)EmpDos;
		if(auxUno != NULL && auxDos != NULL)
		{

			if(cliente_getNombre(auxUno,auxNombre)== 0 &&
				cliente_getNombre(auxDos,auxNombreDos)== 0)
			{
				 if(strncmp(auxNombre,auxNombreDos,NOMBRE_LEN)>0)
				 {
					 retorno = -1;
				 }
				 else if(strncmp(auxNombre,auxNombreDos,NOMBRE_LEN) < 0)
				{
					retorno = 1;
				}
			}
		}
	return retorno;
}


/**
 * \brief Ordena por ID
 * \param EmpUno void* Puntero al Empleado que se busca ordenar
 * \param EmpDos void* Puntero al Empleado que se busca ordenar
 * \return int Retorna 0 (Si ambos parámetros son iguales)
 * 					   -1 (Si auxDos es mayor)
 * 					   1 (Si auxUno es mayor)
 */


int cliente_ordenarID(void* auxUno, void* auxDos)
{
	int retorno = 0;
	int auxIntUno;
	int auxIntDos;

	Cliente* auxiliarEmpl;
	Cliente* auxEmple;

	auxiliarEmpl = (Cliente*) auxUno;
	auxEmple = (Cliente*) auxDos;

	cliente_getId(auxiliarEmpl,&auxIntUno);
	cliente_getId(auxEmple,&auxIntDos);

	if(auxIntUno>auxIntDos)
	{
		retorno = 1;
	}
	else if(auxIntUno<auxIntDos)
	{
		retorno = -1;
	}
	return retorno;
}

/**
 * \brief Calcula Total
 * \param EmpUno void* Puntero al elemento que se busca clasificar
 * \return int Retorna -1 (ERROR)
 * 					    1(OK)
 */



/**
 * \brief Informa horas bajo criterio
 * \param EmpUno void* Puntero al elemento que se busca clasificar
 * \return int Retorna -1 (ERROR)
 * 					    1(OK CRITERO)
 * 					    0(NO CRITERIO)
 */





/**
 * \brief Compara sueldos Total
 * \param EmpUno void* Puntero al elemento que se busca clasificar
 * \return int Retorna -1 (ERROR)
 * 					    auxValor(OK)
 */




/**
 * \brief Informa horas bajo criterio
 * \param EmpUno void* Puntero al elemento que se busca clasificar
 * \return int Retorna -1 (ERROR)
 * 					    1(OK CRITERO)
 * 					    0(NO CRITERIO)
 */


int calcularElementos(void* auxElemento)
{
	int retorno = -1;

	if(auxElemento != NULL)
	{
		retorno = 1;
	}	else
	{
		retorno = 0;
	}
	return retorno;
}






/**
 * \brief Verifica si existe un cuit dado en la lista de clientes
 * \param listClient LinkedList* puntero al listado de clientes
 * \param cuit char* cuit a buscar si ya existe
 * \return Return (0) FALSE si no existe (1) TRUE si lo encontro
 */
int cli_cuitIsInList(LinkedList* listClient, char* cuit)
{
	int result = 0;
	int i;
	char bufferCuit[LEN_AUX];
	Cliente* pClient;

	if(listClient !=  NULL && cuit != NULL)
	{
		for (i = 0; i < ll_len(listClient); i++)
		{
			pClient = (Cliente*)ll_get(listClient,i);
			if(pClient!= NULL)
			{
				cliente_getCuit(pClient,bufferCuit);
				if (strncmp(bufferCuit,cuit,LEN_AUX)==0)
				{
					result = 1;
					break;
				}
			}
		}
	}
	return result;
}





/**
 * \brief Verifica si existe un cuit dado en la lista de clientes
 * \param listClient LinkedList* puntero al listado de clientes
 * \param cuit char* cuit a buscar si ya existe
 * \return Return (0) FALSE si no existe (1) TRUE si lo encontro
 */
int cli_IdIsInList(LinkedList* listClient, int id)
{
	int result = -1;
	int i;
	int bufferId;
	Cliente* pClient;

	if(listClient !=  NULL)
	{
		for (i = 0; i < ll_len(listClient); i++)
		{
			pClient = (Cliente*)ll_get(listClient,i);
			if(pClient!= NULL)
			{
				cliente_getId(pClient,&bufferId);

				if (id == bufferId)
				{
					result = 0;
					break;
				}
			}
		}
	}
	return result;
}
