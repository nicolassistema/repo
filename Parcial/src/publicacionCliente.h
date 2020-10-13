/*
 * publicacionCliente.h
 *
 *  Created on: 12 oct. 2020
 *      Author: nico
 */

#ifndef PUBLICACIONCLIENTE_H_
#define PUBLICACIONCLIENTE_H_


//Punto 4
int publicacionCliente_chargeArray (Publicacion *listP, int lenP,Cliente *listC, int lenC);

//Punto 5
void obtenerIdClienteXIdPublicacion(Publicacion *listP, int lenP,Cliente *listC, int lenC, int *idCliente, int idPublicidad);
int prepararParaPublicacion_pausada (Publicacion *listP, int lenP,Cliente *listC, int lenC);
void pausarPublicacionForId(Publicacion *listP, int lenP, int id);

//Punto 6
void reanudarPublicacionForId(Publicacion *listP, int lenP, int id);
int prepararParaPublicacion_reanudar (Publicacion *listP, int lenP,Cliente *listC, int lenC);



//Punto 7
void  publicacionXid(Publicacion *listP, int lenP,Cliente *listC, int lenC, int *id);
void imprimirClientes(Publicacion *listP, int lenP,Cliente *listC, int lenC);
int imprimaProductoElegido(Publicacion *listP, int lenP, int id);

//punto4
void publicacionesPorCLiente(Publicacion * listP, int lenP,Cliente * listC, int lenC, int id);
int borradoEnCascadaCLientePublicacion(Publicacion * listP, int lenP,Cliente * listC, int lenC);
void publicacionesPorCLienteABorrar(Publicacion * listP, int lenP,Cliente * listC, int lenC, int id);


//Punto 8





#endif /* PUBLICACIONCLIENTE_H_ */
