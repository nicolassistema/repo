/*
 * informe.h
 *
 *  Created on: 26 nov. 2020
 *      Author: nico
 */

#ifndef INFORME_H_
#define INFORME_H_

int informes_findClienteConMasAfiches(LinkedList* pArrayListVentas,LinkedList* pArrayListClientes);
int informes_encontrarMayorOMenor(LinkedList* pArrayListVentas,LinkedList* pArrayListClientes,int mayor);
int informes_encontrarClienteConMasVentas (LinkedList*pArrayListVentas,LinkedList*pArrayListClientes);
int informes_encontrarClienteConMenosVentas (LinkedList*pArrayListVentas,LinkedList*pArrayListClientes);
int informes_cantidadAfichesporId(void*pElemento, int id);

#endif /* INFORME_H_ */
