#include "Cliente.h"


#define MAX 0
#define MIN 1
#define TO_CHARGE 1
#define CHARGED 2
#define CLIENT 1
int controller_loadFromTextCliente(char* path , LinkedList* pArrayListCliente);
int controller_loadFromTextAfiche(char* path , LinkedList* pArrayListCliente);
int controller_loadFromBinary(char* path , LinkedList* pArrayListCliente);
int controller_addCliente(LinkedList* pArrayListCliente);
int controller_addAfiche(LinkedList* pArrayListAfiches,LinkedList* pArrayListAClientes);
int controller_editCliente(LinkedList* pArrayListCliente);
int controller_removeCliente(LinkedList* pArrayListCliente);
int controller_ListCliente(LinkedList* pArrayListCliente);
int controller_ListAfiche(LinkedList* pArrayListafiche);
int controller_sortCliente(LinkedList* pArrayListCliente);
int controller_saveAsTextCliente(char* path , LinkedList* pArrayListCliente);
int controller_saveAsTextAfiche(char* path , LinkedList* pArrayListAfiche);
int controller_saveAsBinary(char* path , LinkedList* pArrayListCliente);
int controller_buscarPorIdArray(LinkedList* pArrayListCliente, int id);
int controller_sortClientebyID(LinkedList* pArrayListCliente);
int controller_containsElemento(LinkedList* pArrayListCliente, Cliente* cliente);
int info_qtySalesById(LinkedList* listSale, int* qty,int choice,int id);
int info_CantVentasXCliente(LinkedList* pArrayListAfiche, LinkedList* pArrayListCliente, int choice);
void* buscarPorId(LinkedList* list, int id,int choiceList);
int afiche_compararStatus(void* this, void* arg);
int controller_editAfiche(LinkedList* pArrayListAfiche, LinkedList* pArrayListCliente);
int controller_editAficheAcobrar(LinkedList* pArrayListAfiche, LinkedList* pArrayListCliente);
int controller_InfoACobrar(LinkedList* pArrayListAfiche, LinkedList* pArrayListCliente);
int controller_InfoCobrado(LinkedList* pArrayListAfiche, LinkedList* pArrayListCliente);
int controller_InfoMayor(LinkedList* pArrayListAfiche, LinkedList* pArrayListCliente);
