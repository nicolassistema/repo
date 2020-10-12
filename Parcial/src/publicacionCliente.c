/*
 * publicacionCliente.c
 *
 *  Created on: 12 oct. 2020
 *      Author: nico
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <conio.h>
#include "cliente_HarcodArray.h"
#include "arrayCliente.h"
#include "publicacion_HarcodArray.h"
#include "arrayPublicacion.h"
#include "publicacionCliente.h"
#include "utn_input.h"





int publicacionCliente_chargeArray (Publicacion *listP, int lenP,Cliente *listC, int lenC)
{
  Publicacion auxPublicacion;
  int retorno = -1;

  cliente_headerArray();
  cliente_printArray(listC, QTY_CLIENTE);
  if (listP != NULL && lenP > 0)
    {
////////////////////	////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
      if (utn_getNumero ("Ingrese id del Cliente: ", "\nError al ingresar. Por favor ", &auxPublicacion.idCliente, 0, 999, 5)!= 0)
      		{
      		  return -1;
      		}
      if (utn_getNumero ("Ingrese numero de rubro: ", "\nError al ingresar. Por favor ", &auxPublicacion.numeroRubro, 0, 99999, 5)!= 0)
		{
		  return -1;
		}
      if (utn_getAlfanumerico ("Ingrese texto: ",  "\nError al ingresar.\n", auxPublicacion.texto, LONG_NAME_PUBLICACION, 5) != 0)
     		{
     		  return -1;
     		}

      if (utn_getAceptaRechaza ("\nAcepta el ingreso? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n')==1)
	{
    	  auxPublicacion.id = utn_idIncremental ();
    	  auxPublicacion.estPubli = ACTIVA;
    	  strcpy(auxPublicacion.descripcionEstado,"ACTIVA");
	  if(publicacion_addArray (listP, lenP,
			  auxPublicacion.id,///////NO TOCAR////////////////////////
			  auxPublicacion.idCliente,
			  auxPublicacion.numeroRubro,
			  auxPublicacion.estPubli,
			  auxPublicacion.descripcionEstado,
			  auxPublicacion.texto
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
				)==0)
	  {
	      retorno = 0;
	  }
	  publicacion_printForId  (listP,lenP, auxPublicacion.id);
	  printf ("\n*****************************************************");
          printf ("\n                    ALTA EXITOSA!                  \n");
	  printf ("*****************************************************\n\n");
	}
      else
	{
	  retorno = 0;
	}
    }
  return retorno;
}
