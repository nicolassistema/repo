#ifndef afiche_H_INCLUDED
#define afiche_H_INCLUDED

#define NOMBRE_LEN 128
typedef struct
{
    int id;
    int idCliente;
    char nombreArchivo[NOMBRE_LEN];
    int cantidadAfiches;
    char zona [NOMBRE_LEN];
    char estado [NOMBRE_LEN];
    int estadoNum;
}Afiche;


Afiche* afiche_new(void);
Afiche* afiche_newParametrosTxt(char* idStr,char* idClienteStr,char* nombreArchivoStr,
		char* cantidadAfichesStr, char* zonaStr, char* estadoStr, char* estadoNumStr);
Afiche* afiche_newParametros(int id,int idCliente,char* nombreArchivo,
		int cantidadAfiches, char* zona, char* estado, int estadoNum);
void afiche_delete();

int afiche_setId(Afiche* this,int id);
int afiche_setIdTxt(Afiche* this,char* id);
int afiche_getId(Afiche* this,int* id);
int afiche_getIdTxt(Afiche* this,char* id);

int afiche_setIdCliente(Afiche* this,int idCliente);
int afiche_setIdClienteTxt(Afiche* this,char* idCliente);
int afiche_getIdCliente(Afiche* this,int* idCliente);
int afiche_getIdClienteTxt(Afiche* this,char* idCliente);


int afiche_setNombreArchivo(Afiche* this,char* nombreArchivo);
int afiche_getNombreArchivo(Afiche* this,char* nombreArchivo);

int afiche_setCantidadAfiches(Afiche* this,int cantidadAfiches);
int afiche_setCantidadAfichesTxt(Afiche* this,char* cantidadAfiches);
int afiche_getCantidadAfiches(Afiche* this,int* cantidadAfiches);
int afiche_getCantidadAfichesTxt(Afiche* this,char* cantidadAfiches);

int afiche_setZona(Afiche* this,char* zona);
int afiche_getZona(Afiche* this,char* zona);

int afiche_setEstado(Afiche* this,char* estado);
int afiche_getEstado(Afiche* this,char* estado);

int afiche_setEstadoNum(Afiche* this,int estadoNum);
int afiche_setEstadoNumTxt(Afiche* this,char* estadoNum);
int afiche_getEstadoNum(Afiche* this,int* estadoNum);
int afiche_getEstadoNumTxt(Afiche* this,char* estadoNum);



int afiche_imprimir(Afiche* this);

#endif // afiche_H_INCLUDED
