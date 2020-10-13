/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */

#ifndef ARRAYCLIENTE_H_
#define ARRAYCLIENTE_H_

#define TRUE 1
#define FALSE 0
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
#define LONG_NAME_CLIENTE 51
#define QTY_CLIENTE 100
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////

struct
{
int id;
int isEmpty;
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
//int idAux;
//int NUMERO1;
//int NUMERO2;
char nombre[LONG_NAME_CLIENTE];
char apellido[LONG_NAME_CLIENTE];
//float FLOTANTE1;
//float FLOTANTE2;
long long int cuit;


}typedef Cliente;//SOLO SE DEBE HACER REFACTOR EN EL NOMBRE DE LA ENTIDAD
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////


//FUNCIONES MODIFICABLES
int cliente_initArray(Cliente* list, int len); ////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////

int cliente_addArray(Cliente* list, int len, int id,////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
//		      int idAux,
		      char* NOMBRE1,
		      char* NOMBRE2,
//		      int NUMERO1,
//		      int NUMERO2,
//		      float FLOTANTE1,
//		      float FLOTANTE2,
		      long long int NUMERO_LARGO
///////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		      );
int cliente_printArray(Cliente* list, int length);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int cliente_sortArray(Cliente* list, int len, int order);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
void cliente_headerArray(void);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int cliente_printForId  (Cliente *list, int len, int id);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int cliente_chargeArray (Cliente* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int cliente_updateArray (Cliente* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
float cliente_sumaTotal(Cliente* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
float cliente_promedio(Cliente* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int cliente_cantidadSuperiorAlPromedio(Cliente* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////






//FUNCIONES NO MODIFICABLES
int cliente_findArrayById (Cliente *list, int len, int id);
int cliente_removeArray(Cliente* list, int len, int id);
int cliente_searchFree (Cliente* list, int len);
int cliente_bufferToArray (Cliente* list, Cliente * , int len, int id);
int cliente_arrayToBuffer(Cliente *list,Cliente *listBuffer, int len, int id);
int cliente_deleteArray (Cliente* list, int len);
int cliente_flagLimite(Cliente* list, int len);
int cliente_prepareForDelete (Cliente *list, int len);
int cliente_isEmpty(Cliente* list, int limit, int index);
int cliente_buscarIndiecePorId (Cliente *list, int len, int idBuscar, int *pIndice);
int cliente_isEmptyForId(Cliente* listC, int lenC, int id);


#endif /* ARRAYCLIENTE_H_ */
