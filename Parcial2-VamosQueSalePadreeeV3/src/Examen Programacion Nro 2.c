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
	LinkedList* sublistaIII;
	LinkedList* sublista4;
	int subMenu;
	int to;
	int from;
	LinkedList* listaClientes = ll_newLinkedList();
	LinkedList* listaAfiches = ll_newLinkedList();

	controller_loadFromTextCliente("Clientes.txt",listaClientes);
	controller_loadFromTextAfiche("Afiches.txt",listaAfiches);



	 do{
	        	utn_getNumero(&option,"1. Agregar Cliente\n"
	        						  "2. Vender Afiches\n"
	        						  "3. Modificar venta\n" //FALTA PULIR
	        						  "4. Cobrar venta\n"
	        						  "5. Generar informe de cobros\n"
	        						  "6. Generar informe de deudas\n"
	        						  "7. Generar estadísticas\n"
	        			 	 	 	  ". *********************************************************\n"
	        						  "8. Salir\n",
	    							  "Opción inválida\n",
	    							  1,8,2);
	            switch(option)
	            {
	                case 1:
	                	if(controller_addCliente(listaClientes)!=-1)
	                	 	 {
	                			controller_saveAsTextCliente("Clientes.txt",listaClientes);
	                	 	 }
	                	else
	                	{
	                		printf("Archivo ya cargado\n");
	                	}
	                    break;
	                case 2:
		                 if(controller_addAfiche(listaAfiches,listaClientes)!= -1){
//								   controller_ListAfiche(listaAfiches);
							controller_saveAsTextAfiche("Afiche.txt",listaAfiches);
		                 }
	                    break;
	                case 3:
	                	if(controller_editAfiche(listaAfiches, listaClientes) != -1)
	                	{
	                		controller_saveAsTextAfiche("Afiche.txt", listaAfiches);
 		                }
	                	controller_ListAfiche(listaAfiches);
	                    break;
	                case 4:
	                	if(controller_editAficheAcobrar(listaAfiches, listaClientes) != -1)
						{
						  		controller_saveAsTextAfiche("Afiches.txt", listaAfiches);
						}
	                	controller_ListAfiche(listaAfiches);
	                    break;
	                case 5:

	                	sublistaIII=ll_clone(listaClientes);

	                	controller_InfoCobrado(listaAfiches, sublistaIII);

	                    break;
	                case 6:

	                	sublistaIII=ll_clone(listaClientes);
	                    controller_InfoACobrar(listaAfiches,sublistaIII);


	                    break;
	                case 7:

	                	do
	                				{
	                					if(utn_getNumero(&subMenu, "\n 1)Cliente con mas afiches vendidos\n "
	                							"2)Cliente con menos afiches vendidos \n"
	                							" 3)Venta con mas afiches vendidos\n", "error", 1, 4, 2) == 0)
	                					{
	                						switch (subMenu) {
	                							case 1:
	                								informes_encontrarClienteConMasVentas(listaAfiches,listaClientes);
	                								break;
	                							case 2:
	                								informes_encontrarClienteConMenosVentas(listaAfiches,listaClientes);
	                								break;
	                							case 3:
	                								informes_findClienteConMasAfiches(listaAfiches,listaClientes);
	                								break;
	                						}
	                					}

	                				}while (subMenu!=4);

	                    break;


	            }
	        }while(option != 8);
	    return 0;
	    return EXIT_SUCCESS;
	}


