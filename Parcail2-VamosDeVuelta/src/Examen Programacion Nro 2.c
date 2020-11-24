/*
 ============================================================================
 Name        : Examen.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cliente.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Afiches.h"
#include "utn.h"

int main(void) {

	setbuf(stdout,NULL);
	int option = 0;
	int archivoCargado = 0;
	Cliente* auxCliente;
	Afiche* AuxAfiche;
	int auxIndice;
	int contadorAux;
	LinkedList* sublista;
	LinkedList* sublistaII;
	int to;
	int from;
	LinkedList* listaClientes = ll_newLinkedList();
	LinkedList* listaAfiches = ll_newLinkedList();




	 do{
	        	utn_getNumero(&option,"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
	        						  "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
	        						  "3. Alta de empleado\n" //FALTA PULIR
	        						  "4. Modificar datos de empleado\n"
	        						  "5. Baja de empleado\n"
	        						  "6. Listar empleados\n"
	        						  "7. Ordenar empleados por nombre\n"
	        						  "8. Ordenar empleados por ID\n"
	        						  "9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
	        						  "10. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
	        						  "11. Buscar empleado\n"
	        						  "12. Clonar lista\n"
	        						  "13. Crear sublista\n"
	        						  "14. Corroborar sublista\n"
	        						  "15. Filtrar por m�s de 300 horas trabajadas\n"
	        						  "16. El sueldo m�s alto\n"
	        						  "17. Liquidaci�n total mensual\n"
	        						  "18. Salir\n",
	    							  "Opci�n inv�lida\n",
	    							  1,18,2);
	            switch(option)
	            {
	                case 1:
	                	if(archivoCargado == 0)
	                	{
							if(!controller_loadFromText("Clientes.txt",listaClientes))
							{
								archivoCargado = 1;
							}
	                	}
	                	else
	                	{
	                		printf("Archivo ya cargado\n");
	                	}
	                    break;
	                case 2:
	                	if(archivoCargado == 0)
	                	{
							controller_loadFromBinary("data.dat",listaClientes);
							archivoCargado = 1;
	                    }
	                	else
						{
							printf("Archivo ya cargado\n");
						}
	                    break;
	                case 3:
	                	if(controller_addCliente(listaClientes)!=-1)
	                	  {
	                	    controller_saveAsText("data.dat",listaClientes);
	                	   }




	                    break;
	                case 4:
	                	controller_editCliente(listaClientes);
	                    break;
	                case 5:
	                	controller_removeCliente(listaClientes);
	                    break;
	                case 6:
	                	controller_ListCliente(listaClientes);
	                    break;
	                case 7:
	                	controller_sortCliente(listaClientes);
	                    break;
	                case 8:
	                	controller_sortClientebyID(listaClientes);
	                    break;
	                case 9:

	                  controller_addAfiche(listaAfiches);

	                	//controller_saveAsBinary("data.dat",listaClientes);
	                    break;
	                case 10:
	                	controller_saveAsText("data.csv",listaClientes);
	                	break;
	                case 11:
	                	utn_getNumero(&to,"Ingrese ID\n","ID incorrecto\n",0,ll_len(listaClientes),2);
	                	auxCliente = ll_get(listaClientes,to-1);
	                	controller_containsElemento(listaClientes,auxCliente);
						auxIndice = ll_indexOf(listaClientes,auxCliente);
						if(auxIndice != -1)
						{
							printf("El empleado se encuentra en el indice %d\n", auxIndice);
							cliente_imprimir(auxCliente);
						}
	                	break;
	                case 12:
	                	if(ll_clone(listaClientes) != NULL)
	                	{
	                		printf("Lista clonada\n");
	                		sublista = ll_clone(listaClientes);
	                		ll_map(sublista,cliente_imprimirGral);
	                	}
	                	break;
	                case 13:
	                	if(!utn_getNumero(&from,"Ingrese desde donde quiere crear la sublista\n"
	                					,"Valor incorecto\n", 0, ll_len(listaClientes),2) &&
										!utn_getNumero(&to,"Ingrese hasta donde quiere crear la sublista\n"
										,"Valor incorecto\n", 0, ll_len(listaClientes),2))
	                	{
							sublistaII = ll_subList(listaClientes,from-1,to);
							if(sublistaII != NULL)
							{
							ll_map(sublistaII,cliente_imprimirGral);
							contadorAux = ll_count(sublistaII,calcularElementos);
							printf("Sublista creada\n");
							printf("Hay %d empleados seleccionados\n\n",contadorAux);
							}
	                	}
	                	break;
	                case 14:
	                	if(ll_containsAll(listaClientes,sublistaII)==1)
	                	{
	                		printf("Los elementos de sublista est�n contenidos\n\n");
	                	}
	                	else if(ll_containsAll(listaClientes,sublistaII)==0)
	                	{
	                		printf("Al menos un elemento no est� contenido\n");
	                	}
	                	else
	                	{
	                		printf("La lista es NULL\n");
	                	}
	                	break;

	            }
	        }while(option != 18);
	    return 0;
	    return EXIT_SUCCESS;
	}


