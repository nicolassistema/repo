/*
 * Employee.c
 *
 *  Created on: 14 nov. 2020
 *      Author: nico
 */


#include "Afiches.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"

#define LEN_AUX 128

static int isValidNombre(char* cadena,int longitud);
static int esNumerica(char* cadena, int limite);

/**
 * \brief Crea un espacio de memoria para un empleado
 * \param Void No recibe par�metros
 * \return Retorna un puntero al espacio de memoria donde ser� guardado el empleado
 *
 */

Afiche* afiche_new(void)
{
	Afiche* auxiliarP = NULL;
	auxiliarP = (Afiche*) malloc(sizeof(Afiche));
	return auxiliarP;
}

/**
 * \brief Crea un empleado conociendo sus par�metros
 * \param idStr char* Puntero id
 * \param nombreStr char* Puntero al nombre
 * \param horasTrabajadasStr char* Puntero a horasTrabajadas
 * \param sueldo char* Puntero a sueldo
 * \return Retorna un puntero al espacio de memoria donde ser� guardado el empleado
 *
 */

Afiche* afiche_newParametrosTxt(char* idStr,char* idClienteStr,char* nombreArchivoStr,
		char* cantidadAfichesStr, char* zonaStr, char* estadoNumStr)
{
	Afiche* this = NULL;
	this = afiche_new();
	if(this != NULL && idClienteStr != NULL && nombreArchivoStr != NULL && cantidadAfichesStr > 0 && zonaStr != NULL && estadoNumStr != NULL)
	{
		if(	afiche_setIdClienteTxt(this, idClienteStr) == -1 ||
			afiche_setIdTxt(this,idStr) == -1 ||
			afiche_setNombreArchivo(this, nombreArchivoStr) == -1 ||
			afiche_setCantidadAfichesTxt(this, cantidadAfichesStr) == -1 ||
			afiche_setZona(this, zonaStr) == -1 ||
			afiche_setEstadoNumTxt(this, estadoNumStr))
		{
			afiche_delete(this);
			this = NULL;
		}
	}
	return this;
}

/**
 * \brief Crea un empleado conociendo sus par�metros reales
 * \param id int Id con el que se cargar� el empleado
 * \param nombre char* Puntero al nombre
 * \param horasTrabajadasStr int  HorasTrabajadas con las que se cargar� el empleado
 * \param sueldo int Sueldo con el que se cargar� el empleado
 * \return Retorna un puntero al espacio de memoria donde ser� guardado el empleado
 *
 */

Afiche* afiche_newParametros(int id,int idCliente,char* nombreArchivo,
		int cantidadAfiches, char* zona, int estadoNum)
{
	Afiche* this = NULL;
	this = afiche_new();
	if(this != NULL && nombreArchivo != NULL  && zona != NULL)
	{
		if(	afiche_setIdCliente(this, idCliente) == -1 ||
			afiche_setId(this,id) == -1 ||
			afiche_setNombreArchivo(this, nombreArchivo) == -1 ||
			afiche_setCantidadAfiches(this, cantidadAfiches) == -1 ||
			afiche_setZona(this, zona) == -1 ||
			afiche_setEstadoNum(this, estadoNum) == -1)

		{
			afiche_delete(this);
			this = NULL;
		}
	}
	return this;
}


/**
 * \brief Elimina el empleado pasado por par�metro
 * \param this Employee* Puntero al empleado a eliminar
 * \return void
 */


void afiche_delete(Afiche* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/**
 * \brief Cambia el nombre del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado a modificar
 * \param nombre char* Puntero al nombre que se cambiar�
 * \return int (-1) ERROR y (0) OK
 */

int afiche_setZona(Afiche* this,char*  zona)
{
	int retorno = -1;
	if(this != NULL && zona != NULL)
	{
		if(isValidNombre(zona,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->zona,zona,NOMBRE_LEN);
		}
	}
	return retorno;
}

int afiche_getZona(Afiche* this,char* zona){


	int retorno = -1;
	if(this != NULL && zona != NULL)
	{
		retorno = 0;
		strncpy(zona,this->zona,NOMBRE_LEN);
	}
	return retorno;

}

/**
 * \brief Se obtiene el nombre del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param nombre char* Puntero al nombre del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */


int afiche_setNombreArchivo(Afiche* this,char* nombreArchivo){

	int retorno = -1;
	if(this != NULL && nombreArchivo != NULL)
	{
		if(isValidNombre(nombreArchivo,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->nombreArchivo,nombreArchivo,NOMBRE_LEN);
		}
	}
	return retorno;


}



/**
 * \brief Se cambiar� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id int ID que se cargar� al empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */


int afiche_getNombreArchivo(Afiche* this,char* nombreArchivo)
{
	int retorno = -1;
	if(this != NULL && nombreArchivo != NULL)
	{
		retorno = 0;
		strncpy(nombreArchivo,this->nombreArchivo,NOMBRE_LEN);



	}
	return retorno;

}

/**
 * \brief Se cambiar� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id int ID que se cargar� al empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int afiche_setId(Afiche* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}

/**
 * \brief Se cambiar� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id char* Puntero al ID que se cargar� al empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int afiche_setIdTxt(Afiche* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		if(esNumerica(id,10))
		{
			retorno = 0;
			this->id = atoi(id);
		}
	}
	return retorno;
}

/**
 * \brief Se obtendr� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id int* Puntero al ID que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */


int afiche_getId(Afiche* this,int* id)
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
 * \brief Se obtendr� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id char* Puntero al ID que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int afiche_getIdTxt(Afiche* this,char* id)
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
 * \brief Se obtendr� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id char* Puntero al ID que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */
int afiche_setIdCliente(Afiche* this,int idCliente){

	int retorno = -1;
	if(this != NULL && idCliente >= 0)
	{
		retorno = 0;
		this->idCliente = idCliente;
	}
	return retorno;

}

/**
 * \brief Se obtendr� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id char* Puntero al ID que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */
int afiche_setIdClienteTxt(Afiche* this,char* idCliente){

	int retorno = -1;
	if(this != NULL && idCliente != NULL)
	{
		if(esNumerica(idCliente,10))
		{
			retorno = 0;
			this->idCliente = atoi(idCliente);
		}
	}
	return retorno;

}

/**
 * \brief Se obtendr� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id char* Puntero al ID que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */
int afiche_getIdCliente(Afiche* this,int* idCliente){

	int retorno = -1;
	if(this != NULL && idCliente != NULL)
	{
		retorno = 0;
		*idCliente = this->idCliente;
	}
	return retorno;

}


/**
 * \brief Se obtendr� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id char* Puntero al ID que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int afiche_getIdClienteTxt(Afiche* this,char* idCliente){

	int retorno = -1;
	if(this != NULL && idCliente != NULL)
	{
		retorno = 0;
		sprintf(idCliente,"%d",this->idCliente);
	}
	return retorno;

}


/**
 * \brief Se obtendr� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id char* Puntero al ID que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */
int afiche_setCantidadAfiches(Afiche* this,int cantidadAfiches){

	int retorno = -1;
	if(this != NULL && cantidadAfiches >= 0)
	{
		retorno = 0;
		this->cantidadAfiches = cantidadAfiches;
	}
	return retorno;

}





/**
 * \brief Se obtendr� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id char* Puntero al ID que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */
int afiche_setCantidadAfichesTxt(Afiche* this,char* cantidadAfiches){

	int retorno = -1;
	if(this != NULL && cantidadAfiches != NULL)
	{
		if(esNumerica(cantidadAfiches,10))
		{
			retorno = 0;
			this->cantidadAfiches = atoi(cantidadAfiches);
		}
	}
	return retorno;
}



/**
 * \brief Se obtendr� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id char* Puntero al ID que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */
int afiche_getCantidadAfiches(Afiche* this,int* cantidadAfiches){

	int retorno = -1;
	if(this != NULL && cantidadAfiches != NULL)
	{
		retorno = 0;
		*cantidadAfiches = this->cantidadAfiches;
	}
	return retorno;
}




/**
 * \brief Se obtendr� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id char* Puntero al ID que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */
int afiche_getCantidadAfichesTxt(Afiche* this,char* cantidadAfiches){

	int retorno = -1;
	if(this != NULL && cantidadAfiches != NULL)
	{
		retorno = 0;
		sprintf(cantidadAfiches,"%d",this->cantidadAfiches);
	}
	return retorno;
}



/**
 * \brief Se obtendr� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id char* Puntero al ID que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */
int afiche_setEstadoNum(Afiche* this,int estadoNum){

	int retorno = -1;
	if(this != NULL && estadoNum >= 0)
	{
		retorno = 0;
		this->estadoNum = estadoNum;
	}
	return retorno;
}



/**
 * \brief Se obtendr� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id char* Puntero al ID que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */
int afiche_setEstadoNumTxt(Afiche* this,char* estadoNum){

	int retorno = -1;
	if(this != NULL && estadoNum != NULL)
	{
		if(esNumerica(estadoNum,10))
		{
			retorno = 0;
			this->estadoNum = atoi(estadoNum);
		}
	}
	return retorno;
}



/**
 * \brief Se obtendr� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id char* Puntero al ID que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */
int afiche_getEstadoNum(Afiche* this,int* estadoNum){

	int retorno = -1;
	if(this != NULL && estadoNum != NULL)
	{
		retorno = 0;
		*estadoNum = this->estadoNum;
	}
	return retorno;
}



/**
 * \brief Se obtendr� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id char* Puntero al ID que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */
int afiche_getEstadoNumTxt(Afiche* this,char* estadoNum){


	int retorno = -1;
	if(this != NULL && estadoNum != NULL)
	{
		if(esNumerica(estadoNum,10))
		{
			retorno = 0;
			this->estadoNum = atoi(estadoNum);
		}
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
			if(cadena[i] != '-' && cadena[i] != ' ' &&(cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
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
int afiche_imprimirGral(void* this)
{
	int retorno=-1;
	//Afiche* auxElemento = (Afiche*) this;
	char idAux[LEN_AUX];
	char nombreArchivo[LEN_AUX];
	int cantidadAfiche;
	char zona[NOMBRE_LEN];
	char estado[LEN_AUX];
	int idCliente;

	if(this != NULL)
	{
		retorno = 0;
		afiche_getIdTxt(this,idAux);
		afiche_getNombreArchivo(this,nombreArchivo);
		afiche_getCantidadAfiches(this, &cantidadAfiche);
		afiche_getZona(this, zona);
		afiche_getEstadoNumTxt(this, estado);
		afiche_getIdCliente(this, &idCliente);

		if(strncmp(estado,"1",sizeof(estado)) == 0){
			strncpy(estado,"A Cobrar",sizeof(estado));
		}else{
			strncpy(estado,"Cobrado",sizeof(estado));
		}
		printf("ID: %10s - Id Cliente %10d  - Nombre archivos %10s - Cantidad Afiches: %10d - Zona %10s - Estado %10s\n",idAux
																			   ,&idCliente
																			   ,nombreArchivo
																			   ,&cantidadAfiche
																			   ,zona
																			   ,estado);
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Ordena por nombre
 * \param EmpUno void* Puntero al Empleado que se busca ordenar
 * \param EmpDos void* Puntero al Empleado que se busca ordenar
 * \return int Retorna 0 (Si ambos par�metros son iguales)
 * 					   1 (Si EmpDos es mayor)
 * 					   -1 (Si EmpUno es mayor)
 */


int afiche_ordenarNombre(void* EmpUno, void* EmpDos)
{
	int retorno = 0;
	char auxNombre[NOMBRE_LEN];
	char auxNombreDos[NOMBRE_LEN];
	Afiche* auxUno;
	Afiche* auxDos;

		auxUno = (Afiche*)EmpUno;
		auxDos = (Afiche*)EmpDos;
		if(auxUno != NULL && auxDos != NULL)
		{

			if(afiche_getNombreArchivo(auxUno,auxNombre)== 0 &&
				afiche_getNombreArchivo(auxDos,auxNombreDos)== 0)
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
 * \return int Retorna 0 (Si ambos par�metros son iguales)
 * 					   -1 (Si auxDos es mayor)
 * 					   1 (Si auxUno es mayor)
 */


int afiche_ordenarID(void* auxUno, void* auxDos)
{
	int retorno = 0;
	int auxIntUno;
	int auxIntDos;

	Afiche* auxiliarEmpl;
	Afiche* auxEmple;

	auxiliarEmpl = (Afiche*) auxUno;
	auxEmple = (Afiche*) auxDos;

	afiche_getId(auxiliarEmpl,&auxIntUno);
	afiche_getId(auxEmple,&auxIntDos);

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




/** \brief Reduce la lista a un Entero
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param int * prResutlado -> puntero donde devuelve el valor final
 * \param int idCliente -> idcliente al cual se le quiere hacer el rduce
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                               ( 0) Si ok
 */


int calcularElementosAfiches(void* auxElemento)
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
 * \brief Imprime los datos de un Empleado
 * \param pElemento Puntero al Empleado que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int afiche_imprimir(Afiche* this)
{
	int retorno=-1;
	char idAux[LEN_AUX];
	char idCliente[LEN_AUX];
	char nombreArchivo[LEN_AUX];
	char cantidadAfiches[LEN_AUX];
	char zona[LEN_AUX];
	int estado;
	char estadoOut[LEN_AUX];


	if(this != NULL)
	{
		retorno = 0;
		afiche_getIdTxt(this, idAux);
		afiche_getIdClienteTxt(this, idCliente);
		afiche_getNombreArchivo(this, nombreArchivo);
		afiche_getCantidadAfichesTxt(this, cantidadAfiches);
		afiche_getZona(this, zona);
		afiche_getEstadoNum(this, &estado);

		if(estado==0){
			strncpy(estadoOut,"A Cobrar",sizeof(estadoOut));
		}else{

			strncpy(estadoOut,"Cobrado",sizeof(estadoOut));
		}
		printf("ID: %10s - Id Cliente: %10s - Nombre Afiche: %10s - Cantidad Afiche: %10s - Zona: %10s - Estado:  %10s \n",idAux
																	   ,idCliente
																	   ,nombreArchivo
																	   ,cantidadAfiches
																	   ,zona
																	   ,estadoOut);
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
int afiche_imprimirPorId(Afiche* this, int idAfiche)
{
	int retorno=-1;
	int idAux;
	char idCliente[LEN_AUX];
	char nombreArchivo[LEN_AUX];
	char cantidadAfiches[LEN_AUX];
	char zona[LEN_AUX];
	int estado;
	char estadoOut[LEN_AUX];

	if (afiche_getId(this, &idAux)==0 && idAux == idAfiche)
	{
		retorno = 0;
		afiche_getId(this, &idAux);
		afiche_getIdClienteTxt(this, idCliente);
		afiche_getNombreArchivo(this, nombreArchivo);
		afiche_getCantidadAfichesTxt(this, cantidadAfiches);
		afiche_getZona(this, zona);
		afiche_getEstadoNum(this, &estado);

		if(estado==0){
			strncpy(estadoOut,"A Cobrar",sizeof(estadoOut));
		}else{

			strncpy(estadoOut,"Cobrado",sizeof(estadoOut));
		}
		printf("ID: %10d - Id Cliente: %10s - Nombre Afiche: %10s - Cantidad Afiche: %10s - Zona: %10s - Estado:  %10s \n",idAux
																	   ,idCliente
																	   ,nombreArchivo
																	   ,cantidadAfiches
																	   ,zona
																	   ,estadoOut);
		retorno = 0;
	}
	return retorno;
}





/** \brief Reduce la lista a un Entero
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param int * prResutlado -> puntero donde devuelve el valor final
 * \param int idCliente -> idcliente al cual se le quiere hacer el rduce
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                               ( 0) Si ok
 */
int afiche_imprimirUno(void* this)
{
	int retorno=-1;

	Afiche* auxAfiche;

	char idAux[LEN_AUX];
	char idCliente[LEN_AUX];
	char nombreArchivo[LEN_AUX];
	char cantidadAfiches[LEN_AUX];
	char zona[LEN_AUX];
	char estado[LEN_AUX];




	if(this != NULL)
	{
		retorno = 0;

		auxAfiche = (Afiche*)this;

		afiche_getIdTxt(auxAfiche, idAux);
		afiche_getIdClienteTxt(auxAfiche, idCliente);
		afiche_getNombreArchivo(auxAfiche, nombreArchivo);
		afiche_getCantidadAfichesTxt(auxAfiche, cantidadAfiches);
		afiche_getZona(auxAfiche, zona);
		afiche_getEstadoNumTxt(auxAfiche, estado);


		if(strncmp(estado,"0",sizeof(estado)) != 0){

			strncpy(estado,"A Cobrar",sizeof(estado));
		}else{

			strncpy(estado,"Cobrado",sizeof(estado));

		}

		printf("ID: %10s - Id Cliente: %10s - Nombre Afiche: %10s - Cantidad Afiche: %10s - Zona: %10s - Estado:  %10s \n",idAux
																	   ,idCliente
																	   ,nombreArchivo
																	   ,cantidadAfiches
																	   ,zona
																	   ,estado);
		retorno = 0;
	}
	return retorno;
}




/** \brief Reduce la lista a un Entero
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param int * prResutlado -> puntero donde devuelve el valor final
 * \param int idCliente -> idcliente al cual se le quiere hacer el rduce
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                               ( 0) Si ok
 */

int afiche_FiltrarNoCobrados(LinkedList* pArrayListAfiches){

	int retorno = -1;
	Afiche* auxAfiche;
	int auxEstado;

	auxAfiche = afiche_new();


	for(int i = 0; i< ll_len(pArrayListAfiches);i++){

		auxAfiche = ll_get(pArrayListAfiches, i);

		afiche_getEstadoNum(auxAfiche, &auxEstado);

		if(auxEstado == 0){


			afiche_imprimir(auxAfiche);
			retorno = 0;
		}
	}


	return retorno;

}


/** \brief Reduce la lista a un Entero
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param int * prResutlado -> puntero donde devuelve el valor final
 * \param int idCliente -> idcliente al cual se le quiere hacer el rduce
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                               ( 0) Si ok
 */

int ventas_findMaxAfiches (LinkedList * pArrayListVentas)
{
	int retorno =-1;
	int maxAfiches;
	int estado;
	int cantidadAfichesAux;
	int idAux;
	Afiche * ventasAux;
	for (int i = 0; i<ll_len(pArrayListVentas);i++)
	{
		ventasAux = ll_get(pArrayListVentas, i);
		afiche_getCantidadAfiches(ventasAux, &cantidadAfichesAux);
		afiche_getEstadoNum(ventasAux, &estado);
		if ((estado > 0 && cantidadAfichesAux>=maxAfiches))
		{
			maxAfiches = cantidadAfichesAux;
			//retorno = i+1;
			afiche_getId(ventasAux, &idAux);
			retorno = idAux;
		}
	}
	return retorno;
}







/**
 * \brief Verifica si existe un cuit dado en la lista de clientes
 * \param listClient LinkedList* puntero al listado de clientes
 * \param cuit char* cuit a buscar si ya existe
 * \return Return (0) FALSE si no existe (1) TRUE si lo encontro
 */
int afiche_IdCobradoEnLista(LinkedList* listaAfiches, int id)
{
	int retortno = -1;
	int i;
	int bufferId;
	Afiche* pAfiche;

	if(listaAfiches !=  NULL)
	{
		for (i = 0; i < ll_len(listaAfiches); i++)
		{
			pAfiche = (Afiche*)ll_get(listaAfiches,i);
			if(pAfiche!= NULL)
			{
				afiche_getId(pAfiche,&bufferId);

				if (id == bufferId && pAfiche->estadoNum == 0)
				{
					retortno = 0;
					break;
				}
			}
		}
	}
	return retortno;
}













