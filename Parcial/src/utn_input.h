/*
 ============================================================================
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */

#ifndef UTN_INPUT_H_
#define UTN_INPUT_H_

int utn_getInt(int* pResultado); //utilizada en utn_getNumero
int utn_verificadorDeNumeros(char* cadena,int limite);//utilizada en utn_getInt
int utn_getNumero(char* mensaje,char* mensajeError,int* pResultado,int minimo,int maximo,int reintentos);
int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);
int utn_myGets(char* cadena, int longitud);
int utn_getFloat(float* pFloat);// utilizada en utn_getNumeroFloat
int utn_esFlotante(char* array,int limite); // utilizada en utn_getFloat
int utn_getString(char* pResultado,int longitud); //utilizada en utn_getCadena
int utn_esSoloLetras(char* pResultado,int limite); //utilizada en utn_getString
int utn_esAlfaNumericoSinCaracteres(char* pResultado);
int utn_esTelefono(char str[]);
int utn_getNombre (char *mensaje, char *mensajeError, char *pNombre, int longitud, int reintentos);
int utn_getAceptaRechaza (char *mensaje, char *mensajeError, char yes, char no);
int utn_idIncremental(void);
int utn_idIncremental2(void);
int utn_getAlfanumerico (char *mensaje, char *mensajeError, char *pNombre, int longitud, int reintentos);
int utn_getIntLong(long long int* pResultado);
int utn_getNumeroLong(char* mensaje,char* mensajeError,long long int* pResultado,long long int minimo,long long int maximo,int reintentos);
#endif /* UTN_INPUT_H_ */
