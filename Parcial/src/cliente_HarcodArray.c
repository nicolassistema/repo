/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */
#include "cliente_HarcodArray.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <conio.h>
#include "arrayCliente.h"



void cliente_HardcodDatosArray(Cliente list[], int len)
{
    int i;

    int idCliente[QTY_CLIENTE_HARDCOD_TEST] = {1,2,3,4,5};/////////NO TOCAR////////
    int estadoCleinte[QTY_CLIENTE_HARDCOD_TEST]= {FALSE,FALSE,FALSE,FALSE,FALSE};/////////NO TOCAR////////
    char nombre_Cliente[QTY_CLIENTE_HARDCOD_TEST][LONG_NAME_CLIENTE]= {"Nicolas","Nicolas","Pedro","Juan","Marcelo"};
    char apellido_Cliente[QTY_CLIENTE_HARDCOD_TEST][LONG_NAME_CLIENTE]= {"Letticugna","Dominguez","Gonzalez","Dominguez","Dominguez"};
    long long int cuit [QTY_CLIENTE_HARDCOD_TEST] = {20323205109,20323205119,20323205129,20323205139,20323205149};


    for(i=0; i<len; i++)
        {
            list[i].id = idCliente[i];/////////NO TOCAR////////
            list[i].isEmpty = estadoCleinte[i];/////////NO TOCAR////////
            strcpy(list[i].nombre, nombre_Cliente[i]);
            strcpy(list[i].apellido, apellido_Cliente[i]);
            list[i].cuit = cuit[i];


        }
}
