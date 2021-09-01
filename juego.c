#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "animos.h"
#include "defendiendo_torres.h"
#include "utiles.h"
#include "jugar.h"
#include "comandos.h"
const static int COMANDO_JUGAR = 0;
const static int COMANDO_RANKING = 1;
const static int COMANDO_CREAR_CAMINO = 2;
const static int COMANDO_CREAR_CONFIG = 3;
const static int COMANDO_REPETICION = 4;
const static int COMANDOS_MIN = 2;
const static int ERROR = -1;

int main (int argc, char * argv[]){
	
	configuracion_t configuracion;
	char archivos[MAX_CANT_ARCHIVOS][MAX_LETRAS];
	char comandos_jugador[MAX_CANT_COMANDOS][MAX_LETRAS];
	srand((unsigned)time(NULL));

	int orden = leer_comandos(argc, &(*argv), comandos_jugador);
	if(orden == COMANDO_JUGAR){	
		comandos_jugar(comandos_jugador, argc, archivos, configuracion);
	}else if(orden == COMANDO_RANKING){
		comandos_ranking(comandos_jugador, argc, archivos);
	}else if(orden == COMANDO_CREAR_CAMINO){
		if(argc <= COMANDOS_MIN){
			printf("no ingreso archivo.\n");
			return ERROR;
		}
		comando_crear_caminos(comandos_jugador, archivos);
	}else if(orden == COMANDO_CREAR_CONFIG){
		if(argc <= COMANDOS_MIN){
			printf("no ingreso archivo.\n");
			return ERROR;
		}
		comandos_configuracion(comandos_jugador, archivos, &configuracion);
	}else if(orden == COMANDO_REPETICION){
		if(argc <= COMANDOS_MIN){
			printf("no ingreso archivo.\n");
			return ERROR;
		}
		comandos_repeticion(comandos_jugador, archivos, argc);
	}else{
		return ERROR;
	}	
return 0;
}