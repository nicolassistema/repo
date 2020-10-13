/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */

#ifndef PUBLICACION_H_
#define PUBLICACION_H_

#define TRUE 1
#define FALSE 0
#define ACTIVA 1
#define PAUSADA 0
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
#define LONG_NAME_PUBLICACION 64
#define QTY_PUBLICACION 1000
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////

struct
{
int id;
int isEmpty;
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
int idCliente;
int numeroRubro;
int estPubli;
char descripcionEstado[10];
char texto[LONG_NAME_PUBLICACION];


}typedef Publicacion;//SOLO SE DEBE HACER REFACTOR EN EL NOMBRE DE LA ENTIDAD
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////


//FUNCIONES MODIFICABLES
int publicacion_initArray(Publicacion* list, int len); ////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////

int publicacion_addArray(Publicacion* list, int len, int id,////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		      int idCliente,
     	      int numeroRubro,
			  int estPubli,
			  char * descripcionEstadoPubli,
			  char* texo
///////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		      );
int publicacion_printArray(Publicacion* list, int length);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int publicacion_sortArray(Publicacion* list, int len, int order);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
void publicacion_headerArray(void);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int publicacion_printForId  (Publicacion *list, int len, int id);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int publicacion_chargeArray (Publicacion* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int publicacion_updateArray (Publicacion* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
float publicacion_sumaTotal(Publicacion* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
float publicacion_promedio(Publicacion* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int publicacion_cantidadSuperiorAlPromedio(Publicacion* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////






//FUNCIONES NO MODIFICABLES
int publicacion_findArrayById (Publicacion *list, int len, int id);
int publicacion_removeArray(Publicacion* list, int len, int id);
int publicacion_searchFree (Publicacion* list, int len);
int  publicacion_bufferToArray (Publicacion* list, Publicacion * , int len, int id);
int publicacion_arrayToBuffer(Publicacion *list,Publicacion *listBuffer, int len, int id);
int publicacion_deleteArray (Publicacion* list, int len);
int publicacion_flagLimite(Publicacion* list, int len);
int publicacion_prepareForDelete (Publicacion *list, int len);
int publicacion_isEmpty(Publicacion* list, int limit, int index);
int publicacion_buscarIndiecePorId (Publicacion *list, int len, int idBuscar, int *pIndice);



//Punto 5

int publicacion_isPaused(Publicacion* list, int limit, int id);
int publicacion_printForIdSinHeader  (Publicacion *list, int len, int id);

#endif /* PUBLICACION_H_ */
