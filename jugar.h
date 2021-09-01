#ifndef __JUGAR_H__
#define __JUGAR_H__

#include "comandos.h"
#define MAX_CANT_ARCHIVOS 10
#define MAX_LETRAS 50
/*
PRE: se tuvo que haber ingresado el comando JUGAR.
POST muestra por pantalla el juego y permite jugarlo.
*/
void jugar_normal(int* viento, int* humedad, char* animo_legolas, char* animo_gimli, juego_t* juego, int* preguntar_defensor_extra, configuracion_t configuracion, bool grabar, char archivos[MAX_CANT_ARCHIVOS][MAX_LETRAS]);

#endif /*__JUGAR_H__*/