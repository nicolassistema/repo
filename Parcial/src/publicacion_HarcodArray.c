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
    int idCliente[QTY_PUBLICACION_HARDCOD_TEST] = {1,4,5,5,1};/////////NO TOCAR////////
    char texto[QTY_PUBLICACION_HARDCOD_TEST][LONG_NAME_PUBLICACION]= {"Vendo marido, poco uso","Paloma solitaria busca nido confortable.","Busco perro y suegra perdidos. Recompensa por el perro.","Cambio pastor alemán por uno que hable español.","Cambio suegra por víbora. Pago la diferencia."};
    int numeroRubro[QTY_PUBLICACION_HARDCOD_TEST] = {9,15,8,8,5};
    int estadoPublicacion[QTY_PUBLICACION_HARDCOD_TEST] = {PAUSADA,PAUSADA,PAUSADA,ACTIVA,PAUSADA};
    char descripcionestadoPublicacion[QTY_PUBLICACION_HARDCOD_TEST][10] = {"PAUSADA","PAUSADA","PAUSADA","ACTIVA","PAUSADA"};



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
