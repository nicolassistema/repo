/*
 * LinkedList.c
 *
 *  Created on: 14 nov. 2020
 *      Author: nico
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */


static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;

    if(this!=NULL && nodeIndex>-1 && nodeIndex<ll_len(this))
    {
        pNode = this->pFirstNode;

        for(i=0; i<nodeIndex; i++)
        {
            pNode = pNode->pNextNode;
        }
    }
    return pNode;
}




/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
/*
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* auxNode = NULL;
    Node* auxNodeDos = NULL;

    if(this != NULL && nodeIndex >= 0)
    {
    	auxNode = (Node*) malloc(sizeof(Node));
    	auxNodeDos = (Node*) malloc(sizeof(Node));

    	if(auxNode != NULL && auxNodeDos != NULL)
    	{

			auxNode->pElement = pElement;
			this->size++;
			returnAux = 0;

			if(nodeIndex == 0 )
			{
				auxNode->pNextNode = this->pFirstNode;
				this->pFirstNode = auxNode;
			}
			else if(nodeIndex == ll_len(this))
			{
				auxNodeDos = getNode(this, nodeIndex-1);
				auxNodeDos->pNextNode = auxNode;
				auxNode->pNextNode = NULL;
			}
			else
			{
				auxNodeDos = getNode(this, nodeIndex);
				auxNode->pNextNode = auxNodeDos;
				auxNodeDos = getNode(this, nodeIndex-1);
				auxNodeDos->pNextNode = auxNode;
			}
    	}
    }
    return returnAux;
}

*/

static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node * nodoNuevo = (Node*)malloc(sizeof(Node));
    Node * nodoPrevio;
    if (this!=NULL && nodoNuevo!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))
    {
    	nodoNuevo->pElement=pElement;
		if (nodeIndex==0)
		{
			nodoNuevo->pNextNode = this->pFirstNode;
			this->pFirstNode=nodoNuevo;
		}
		else
		{
			nodoPrevio=getNode(this, nodeIndex-1);
			nodoNuevo->pNextNode=nodoPrevio->pNextNode;
			nodoPrevio->pNextNode=nodoNuevo;
		}
		this->size++;
		returnAux=0;
    }
    return returnAux;
}





/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && !addNode(this,ll_len(this),pElement))
	{
		returnAux = 0;
	}
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	auxNode =getNode(this,index);
    	returnAux = auxNode->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	auxNode = getNode(this,index);
    	if(auxNode != NULL)
    	{
    		auxNode->pElement = pElement;
    		returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* auxNode = NULL;
    Node* auxiliarAnt = NULL;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	auxNode = getNode(this,index);
    	auxiliarAnt = getNode(this,index-1);
    	if(index == 0)
    	{
    		this->pFirstNode = auxNode->pNextNode;
    	}
    	else
    	{
    		auxiliarAnt->pNextNode = auxNode->pNextNode;
    	}

    	free(auxNode);
    	this->size--;
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int flag;
    if(this != NULL)
    {
    	do
    	{
    		flag = ll_remove(this,ll_len(this)-1);
    	}while(flag != -1);
    	this->pFirstNode = NULL;
    	this->size = 0;
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	ll_clear(this);
    	free(this);
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int index=0;

    if(this != NULL)
    {
		for(index=0;index<ll_len(this);index++)
		{
			if(ll_get(this, index) == pElement)
			{
				returnAux = index;
				break;
			}
		}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_len(this)==0)
    	{
    		returnAux = 1;
    	}
    	else
		{
    		returnAux = 0;
		}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
    	if(addNode(this,index,pElement)==0)
    	{
			returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL && index >=0 && index <= ll_len(this))
    {
    	returnAux = ll_get(this,index);
    	if(returnAux != NULL)
    	{
    		ll_remove(this,index);
    	}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int index=0;

     if(this != NULL)
     {
    	returnAux= 0;
 		for(index=0;index<ll_len(this);index++)
 		{
 			if(ll_get(this, index) == pElement)
 			{
 				returnAux = 1;
 				break;
 			}
 		}
     }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int index=0;
    void* auxiliar = NULL;

     if(this != NULL && this2 != NULL)
     {
    	returnAux= 0;
 		for(index=0;index<ll_len(this2);index++)
 		{
 			auxiliar = ll_get(this,index);
 			if(ll_contains(this,auxiliar)==0)
 			{
 				returnAux = 0;
 				break;
 			}
 			else
 			{
 				returnAux = 1;
 			}
 		}
     }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int index=0;
    void* auxiliar = NULL;
    if(this != NULL && from >= 0 && to >= 0 && from < to && to <= ll_len(this)&& from <= ll_len(this))
    {
    	cloneArray = ll_newLinkedList();
    	for(index=from;index<to;index++)
		{
			auxiliar = ll_get(this,index);
			ll_add(cloneArray,auxiliar);
		}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL)
    {
    	cloneArray = ll_newLinkedList();
    	if(ll_subList(this,0,ll_len(this)) != NULL)
    	{
    		cloneArray = ll_subList(this,0,ll_len(this));
    	}
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int index;
    void* auxUno = NULL;
    void* auxDos = NULL;
    void* auxElemento;
    int flagSwap;
    int auxiliarF;
    int tamLista;

    if(this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
    	tamLista = ll_len(this)-1;
    	do
    	{
    		flagSwap = 0;

			for(index=0;index<tamLista;index++)
			{
				auxUno = ll_get(this,index);
				auxDos = ll_get(this,index+1);
				auxiliarF = pFunc(auxUno,auxDos);
				if((auxiliarF == -1 && order == 0) || (auxiliarF == 1 && order == 1))
				{
					flagSwap = 1;
					auxElemento = auxUno;
					ll_set(this,index,auxDos);
					ll_set(this,index+1,auxElemento);
				}
			}
			tamLista--;
    	}while(flagSwap);
    	returnAux = 0;
	}
    return returnAux;

}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int returnAux =-1;
    int index;
    void* auxElemento;

    if(this != NULL && pFunc != NULL )
    {
		for(index=0;index<ll_len(this);index++)
		{
			auxElemento = ll_get(this,index);
			if(pFunc(auxElemento)<0)
			{
				returnAux = -2;
				break;
			}
		}
    	returnAux = 0;
	}
    return returnAux;

}


/** \brief Filtra los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    int index;
    LinkedList* listaFiltrada = NULL;
    void* auxElemento;

    if(this != NULL && pFunc != NULL )
    {
    	listaFiltrada = ll_newLinkedList();
    	if(listaFiltrada != NULL)
    	{
			for(index=0;index<ll_len(this);index++)
			{
				auxElemento = ll_get(this,index);
				if(pFunc(auxElemento)==1)
				{
					ll_add(listaFiltrada,auxElemento);
				}
			}
    	}
	}
    return listaFiltrada;
}



/** \brief Cuenta los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_count(LinkedList* this, int (*pFunc)(void*))
{
    int index;
    void* auxElemento;
    int contador = 0;

    if(this != NULL && pFunc != NULL )
    {
			for(index=0;index<ll_len(this);index++)
			{
				auxElemento = ll_get(this,index);
				if(pFunc(auxElemento)==1)
				{
					contador++;
				}
			}
	}
    return contador;
}



/** \brief Cuenta los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_countAcumulador(LinkedList* this, int (*pFunc)(void*))
{
	int retorno = -1;
    int index;
    int sueldoAcum = 0;
    void* auxElemento = NULL;

    if(this != NULL && pFunc != NULL )
    {
			for(index=0;index<ll_len(this);index++)
			{
				auxElemento = ll_get(this,index);
				sueldoAcum+= pFunc(auxElemento);
			}
			retorno = sueldoAcum;
	}
    return retorno;

}


/** \brief Informa valor del elemento de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */

int ll_reduce(LinkedList* this, int (*pFunc)(void*, int, int))
{
	int index;
	void* auxElemento = NULL;
	int valor = 0;

	if(this != NULL && pFunc != NULL)
	{
		for(index=0;index < ll_len(this);index++)
		{
			auxElemento = ll_get(this, index);
			valor = pFunc(auxElemento,valor,index);
		}
	}

	return valor;
}



/** \brief Reduce la lista a un Entero
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param int * prResutlado -> puntero donde devuelve el valor final
 * \param int idCliente -> idcliente al cual se le quiere hacer el rduce
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                               ( 0) Si ok
 */

int ll_filter2(LinkedList * this, FunctionFilter pFunc, void* arg)
{
	int returnAux = -1;
	void* pAux;
	int i;

	if (this != NULL && pFunc != NULL)
	{
		for (i = ll_len(this) - 1; i >= 0; i--)
		{
			pAux = ll_get(this, i);
			if (pAux != NULL)
			{
				if (pFunc(pAux,arg) == 0)
				{
					returnAux = ll_remove(this, i);
				}
			}
		}
	}
	return returnAux;
}



/** \brief Recorre los elementos de la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param int indice -> indice a buscar donde el map se detendr� al encontrarlo en la lista
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                               ( 0) Si ok
 */
int ll_mapAndBreak(LinkedList* this, int (*pFunc)(void*, int),int id)
{
    int returnAux =-1;
    int len = ll_len(this);
    void* pElemento;

    if(this!=NULL)
    {
        for (int i = 0;i<len;i++)
        {
            pElemento=ll_get(this, i);
            if(pFunc(pElemento,id)==1)
            {
                returnAux=i;
                break;
            }
        }
    }
    return returnAux;
}



/** \brief Reduce la lista a un Entero
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param int * prResutlado -> puntero donde devuelve el valor final
 * \param int idCliente -> idcliente al cual se le quiere hacer el rduce
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                               ( 0) Si ok
 */

int ll_reduceIntbyID(LinkedList* this, int (*pFunc)(void*,int), int * pResultado, int idCliente)
{
    int returnAux =-1;
    int len = ll_len(this);
    void* pElemento;
    int resultado=0;
    if(this!=NULL)
    {

    	for (int i = 0;i<len;i++)
    	{
    		pElemento=ll_get(this, i);
    		resultado= resultado+pFunc(pElemento,idCliente);
    		*pResultado=resultado;
    		returnAux=0;
    	}
    }
    return returnAux;
}

