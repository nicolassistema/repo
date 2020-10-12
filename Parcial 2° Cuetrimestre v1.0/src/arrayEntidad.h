/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */

#ifndef ARRAYENTIDAD_H_
#define TEMPLATE_H_

#define TRUE 1
#define FALSE 0
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
#define LONG_NAME_TEMPLATE 51
#define QTY_TEMPLATE 100
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////

struct
{
int id;
int isEmpty;
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
int idAux;
int NUMERO1;
int NUMERO2;
char NOMBRE1[LONG_NAME_TEMPLATE];
char NOMBRE2[LONG_NAME_TEMPLATE];
float FLOTANTE1;
float FLOTANTE2;
long long int NUMERO_LARGO;


}typedef Template;//SOLO SE DEBE HACER REFACTOR EN EL NOMBRE DE LA ENTIDAD
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////


//FUNCIONES MODIFICABLES
int template_initArray(Template* list, int len); ////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////

int template_addArray(Template* list, int len, int id,////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		      int idAux,
		      char* NOMBRE1,
		      char* NOMBRE2,
		      int NUMERO1,
		      int NUMERO2,
		      float FLOTANTE1,
		      float FLOTANTE2,
		      long long int NUMERO_LARGO
///////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		      );
int template_printArray(Template* list, int length);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int template_sortArray(Template* list, int len, int order);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
void template_headerArray(void);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int template_printForId  (Template *list, int len, int id);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int template_chargeArray (Template* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int template_updateArray (Template* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
float template_sumaTotal(Template* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
float template_promedio(Template* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int template_cantidadSuperiorAlPromedio(Template* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////






//FUNCIONES NO MODIFICABLES
int template_findArrayById (Template *list, int len, int id);
int template_removeArray(Template* list, int len, int id);
int template_searchFree (Template* list, int len);
int  template_bufferToArray (Template* list, Template * , int len, int id);
int template_arrayToBuffer(Template *list,Template *listBuffer, int len, int id);
int template_deleteArray (Template* list, int len);
int template_flagLimite(Template* list, int len);
int template_prepareForDelete (Template *list, int len);
int template_isEmpty(Template* list, int limit, int index);
int template_buscarIndiecePorId (Template *list, int len, int idBuscar, int *pIndice);



#endif /* ARRAYENTIDAD_H_ */
