#ifndef cliente_H_INCLUDED
#define cliente_H_INCLUDED


#include "LinkedList.h"

#define NOMBRE_LEN 128
typedef struct
{
    int id;
    char nombre[NOMBRE_LEN];
    char cuit[NOMBRE_LEN];
    char apellido [NOMBRE_LEN];

}Cliente;

Cliente* cliente_new(void);
Cliente* cliente_newParametrosTxt(char* idStr,char* nombreStr,char* cuitStr, char* apellidoStr);
Cliente* cliente_newParametros(int id, char* nombre, char* cuit, char* apellido);
void cliente_delete();

int cliente_setId(Cliente* this,int id);
int cliente_setIdTxt(Cliente* this,char* id);
int cliente_getId(Cliente* this,int* id);
int cliente_getIdTxt(Cliente* this,char* id);

int cliente_setNombre(Cliente* this,char* nombre);
int cliente_getNombre(Cliente* this,char* nombre);

int cliente_setCuit(Cliente* this,char* cuit);
int cliente_getCuit(Cliente* this,char* cuit);


int cliente_setApellido(Cliente* this,char* apellido);
int cliente_getApellido(Cliente* this,char* apellido);




int cliente_imprimir(Cliente* this);
int cliente_ordenarNombre(void* EmpUno, void* EmpDos);
int cliente_ordenarID(void* auxUno, void* auxDos);
int cliente_imprimirGral(void* this);
int calcularElementosHsMayoresA(void* auxElemento);
int calcularEmpleadosLiquidacion(void* auxElemento);
int compararSueldoPorValor(void* auxElemento, int valor,int index);
int calcularElementos(void* auxElemento);
int cli_cuitIsInList(LinkedList* listClient, char* cuit);
int cli_IdIsInList(LinkedList* listClient, int id);

#endif // cliente_H_INCLUDED
