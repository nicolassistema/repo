#include "Cliente.h"

int controller_loadFromText(char* path , LinkedList* pArrayListCliente);
int controller_loadFromBinary(char* path , LinkedList* pArrayListCliente);
int controller_addCliente(LinkedList* pArrayListCliente);
int controller_editCliente(LinkedList* pArrayListCliente);
int controller_removeCliente(LinkedList* pArrayListCliente);
int controller_ListCliente(LinkedList* pArrayListCliente);
int controller_sortCliente(LinkedList* pArrayListCliente);
int controller_saveAsText(char* path , LinkedList* pArrayListCliente);
int controller_saveAsBinary(char* path , LinkedList* pArrayListCliente);
int controller_buscarPorIdArray(LinkedList* pArrayListCliente, int id);
int controller_sortClientebyID(LinkedList* pArrayListCliente);
int controller_containsElemento(LinkedList* pArrayListCliente, Cliente* cliente);
