/*
 ============================================================================
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */
#include "publicacion_HarcodArray.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <conio.h>
#include "arrayPublicacion.h"



void publicacion_hardcodDatosArray(Publicacion* list, int len)
{
    int i;
    int idPublicacion[QTY_PUBLICACION_HARDCOD_TEST] = {1,2,3,4,5};/////////NO TOCAR////////
    int isEmpty[QTY_PUBLICACION_HARDCOD_TEST]= {FALSE,FALSE,FALSE,FALSE,FALSE};/////////NO TOCAR////////
    int idCliente[QTY_PUBLICACION_HARDCOD_TEST] = {1,1,3,4,5};/////////NO TOCAR////////
    char texto[QTY_PUBLICACION_HARDCOD_TEST][LONG_NAME_PUBLICACION]= {"Neumatico para coches","Venta de Barbijos","Sepelios","Venta de sarlanga","Mecanico MARCELO"};
    int numeroRubro[QTY_PUBLICACION_HARDCOD_TEST] = {9,10,15,8,5};
    int estadoPublicacion[QTY_PUBLICACION_HARDCOD_TEST] = {ACTIVA,ACTIVA,ACTIVA,ACTIVA,ACTIVA};
    char descripcionestadoPublicacion[QTY_PUBLICACION_HARDCOD_TEST][10] = {"ACTIVA","ACTIVA","ACTIVA","ACTIVA","ACTIVA"};



    for(i=0; i<len; i++)
        {
            list[i].id = idPublicacion[i];/////////NO TOCAR////////
            list[i].isEmpty = isEmpty[i];/////////NO TOCAR////////
            list[i].idCliente = idCliente[i];
            strcpy(list[i].texto, texto[i]);
            list[i].numeroRubro = numeroRubro[i];
            list[i].estPubli = estadoPublicacion[i];
            strcpy(list[i].descripcionEstado, descripcionestadoPublicacion[i]);




        }
}
