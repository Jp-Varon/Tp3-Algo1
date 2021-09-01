#ifndef __COMANDOS_H__
#define __COMANDOS_H__

#include "defendiendo_torres.h"
#include <stdbool.h>

#define MAX_CANT_COMANDOS 10
#define MAX_LETRAS 50
#define MAX_CANT_ARCHIVOS 10
/*
POST: devuelve un numero asociado a un comando. 
*/
int leer_comandos(int argc, char* argv[], char comandos_jugador[MAX_CANT_COMANDOS][MAX_LETRAS]);
/*
PRE: se debe hacer ingresado el nombre de la configuracion de dicho ranking.
POST: imprime por pantalla el ranking de la configuracion ingresada.
*/
void comandos_ranking(char comandos_jugador[MAX_CANT_COMANDOS][MAX_LETRAS], int argc, char archivos[MAX_CANT_ARCHIVOS][MAX_LETRAS]);
/*
PRE: se debe hacer ingresado el nombre del archivo a crear.
POST: crea un archivo de texto con los caminos creados por los usuarios.
*/
void comando_crear_caminos(char comandos_jugador[MAX_CANT_COMANDOS][MAX_LETRAS], char archivos[MAX_CANT_ARCHIVOS][MAX_LETRAS]);
/*
PRE: se debe hacer ingresado el nombre del archivo a crear.
POST: crea un archivo de texto con la configuracion creada por el usuario. 
*/
void comandos_configuracion(char comandos_jugador[MAX_CANT_COMANDOS][MAX_LETRAS], char archivos[MAX_CANT_ARCHIVOS][MAX_LETRAS], configuracion_t* configuracion);
/*
POST: juega el juego.
*/
void comandos_jugar(char comandos_jugador[MAX_CANT_COMANDOS][MAX_LETRAS], int argc, char archivos[MAX_CANT_ARCHIVOS][MAX_LETRAS], configuracion_t configuracion);
/*
PRE: se tuvo que haber jugado al juego y posteriormente terminado.
POST: calcula el en que posicion del ranking quedo el usuario en su respectiva 	
	configuracion.
*/
void calcular_ranking(int orcos_muertos, juego_t juego, char usuario[MAX_LETRAS], char archivo[MAX_LETRAS], configuracion_t configuracion);
/*
PRE: se tuvo que haber jugado al juego y posteriormente terminado.
POST: imprime por pantalla el juego guardado en un archivo binario.
*/
void comandos_repeticion(char comandos_jugador[MAX_CANT_COMANDOS][MAX_LETRAS], char archivos[MAX_CANT_COMANDOS][MAX_LETRAS], int argc);

#endif /*__COMANDOS_H__*/