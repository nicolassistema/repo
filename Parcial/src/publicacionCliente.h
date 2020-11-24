/*
 * publicacionCliente.h
 *
 *  Created on: 12 oct. 2020
 *      Author: nico
 */

#ifndef PUBLICACIONCLIENTE_H_
#define PUBLICACIONCLIENTE_H_


typedef struct
{
    int idCliente;
    int cantPublicacion;
} AuxEstruct;


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
//(A)
void CalcularAvisosClientes(Publicacion* listP,int lenP, Cliente* listC,int lenC, int *autCliente);

//(B)
int sumarPausadosPublicacionesClientes(Publicacion* listP,int lenP,int *salida);
//(C)
void calcularRubroPublicaciones(Publicacion* listP,int lenP,int *autRubro);





void auxClientePublicacion (AuxEstruct *clientePublicacion, Cliente *listC, int lenC);
void contadorClientePubliciacacion (AuxEstruct *clientePublicacion,int lenC, Publicacion *listP,int lenP);
void ContadorClienteMascota (AuxEstruct *clientePublicacion,int lenC, Publicacion *listP,int lenP);

void MostrarClientesConSusPublicaciones(Publicacion* listP,int lenP, Cliente* listC,int lenC);


void ordernarPorCantPublicaciones(Publicacion* listP,int lenP, Cliente* listC,int lenC);


void HardcodeoAuxClientePublicacion (AuxEstruct *listCAux, Cliente *listC, int lenC, Publicacion *listP, int lenP);
void clienteArrayToBuffer(Cliente* listC,Cliente *listPBuffer,int lenC);
void publicacionArrayToBuffer(Publicacion* listP,Publicacion *listPBuffer,int lenP);

void ClienteConMasAvisosActivos(Publicacion* listP,int lenP, Cliente* listC,int lenC, int *autCliente);
void ClienteConMasAvisosPausados(Publicacion* listP,int lenP, Cliente* listC,int lenC, int *autCliente);





#endif /* PUBLICACIONCLIENTE_H_ */
