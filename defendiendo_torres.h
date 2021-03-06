#ifndef __DEFENDIENDO_TORRES_H__
#define __DEFENDIENDO_TORRES_H__

#include <stdlib.h>
#include <stdio.h>

#include <stdbool.h>
#define MAX_CANT_COMANDOS 10
#define MAX_LETRAS 50
#define MAX_CANT_ARCHIVOS 10
#define MAX_NIVELES 4
#define MAX_LONGITUD_CAMINO 200
#define MAX_GRABACION 700
#define MAX_FILAS 30
#define MAX_COLUMNAS 30
#define MAX_LONGITUD_CAMINO 200
#define MAX_ENEMIGOS 500
#define MAX_DEFENSORES 50

typedef struct coordenada {
	int fil;
	int col;
} coordenada_t;

typedef struct defensor {
	char tipo;
	int fuerza_ataque;
	coordenada_t posicion;
} defensor_t;

typedef struct torres {
	int resistencia_torre_1;
	int resistencia_torre_2;
	int enanos_extra;
	int elfos_extra;
} torres_t;

typedef struct enemigo {
	int camino;
	int pos_en_camino;
	int vida;
} enemigo_t;

typedef struct nivel {
	coordenada_t camino_1[MAX_LONGITUD_CAMINO];
	int tope_camino_1;
	
	coordenada_t camino_2[MAX_LONGITUD_CAMINO];
	int tope_camino_2;

	defensor_t defensores[MAX_DEFENSORES];
	int tope_defensores;

	enemigo_t enemigos[MAX_ENEMIGOS];
	int tope_enemigos;

	int max_enemigos_nivel;
} nivel_t;

typedef struct juego {
	nivel_t nivel;
	torres_t torres;
	int nivel_actual;
	int critico_legolas;
	int critico_gimli;
	int fallo_legolas;
	int fallo_gimli;
} juego_t;


typedef struct vida_torres{
	int torre_uno;
	int torre_dos;	
}vida_torres_t;

typedef struct animos{
	int fallo;
	int critico;
}animos_t;

typedef struct defensor_extra{
	int cant_extra;
	int costo_torre_1;
	int costo_torre_2;
}defensor_extra_t;


typedef struct caminos{
	char archivo[MAX_LETRAS];
	coordenada_t camino_1_lvl_1[MAX_LONGITUD_CAMINO];
	int tope_camino_1_lvl_1;
	coordenada_t camino_2_lvl_2[MAX_LONGITUD_CAMINO];
	int tope_camino_2_lvl_2;
	coordenada_t camino_1_lvl_3[MAX_LONGITUD_CAMINO];
	int tope_camino_1_lvl_3;
	coordenada_t camino_2_lvl_3[MAX_LONGITUD_CAMINO];
	int tope_camino_2_lvl_3;
	coordenada_t camino_1_lvl_4[MAX_LONGITUD_CAMINO];
	int tope_camino_1_lvl_4;
	coordenada_t camino_2_lvl_4[MAX_LONGITUD_CAMINO];
	int tope_camino_2_lvl_4;
}caminos_t;

typedef struct configuracion{
	bool configuracion_defecto;
	vida_torres_t torres;
	int cant_enanos[MAX_NIVELES];
	int cant_elfos[MAX_NIVELES];
	defensor_extra_t enanos_extras;
	defensor_extra_t elfos_extras;
	animos_t animo_enanos;
	animos_t animo_elfos;
	float velocidad_juego;
	caminos_t caminos;
}configuracion_t;


/*
 * Inicializar?? el juego, cargando la informacion de las torres y
 * los ataques cr??ticos y fallo de Legolas y Gimli.
 * NO inicializar?? el primer nivel.
 */
void inicializar_juego(juego_t* juego, int viento, int humedad, char animo_legolas, char animo_gimli, configuracion_t configuracion);

/*
 * Recibe un juego con todas sus estructuras v??lidas. 
 * El juego se dar?? por ganado si el juego est?? en el ultimo nivel y ??ste ha sido terminado.
 * El juego se dar?? por perdido, si alguna de las torres llega a 0 en su resistencia.
 * Devolver??:
 * >  0 si el estado es jugando.
 * > -1 si el estado es perdido.
 * >  1 si el estado es ganado.
 */
int estado_juego(juego_t juego);

/*
 * Recibe un nivel con todas sus estructuras v??lidas. 
 * El nivel se dar?? por ganado cuando est??n TODOS los orcos de ese 
 * nivel muertos (esto es, con vida menor o igual a 0).
 * Devolver??:
 * >  0 si el estado es jugando.
 * >  1 si el estado es ganado.
 */
int estado_nivel(nivel_t nivel);

/* 
 * Agregar?? un defensor en el nivel recibido como parametro.
 * Devolver??:
 * >  0 si pudo agregar el defensor correctamente.
 * > -1 si no pudo (la coordenada es parte del camino de ese nivel, 
 * existe otro defensor, etc.)
 */
int agregar_defensor(nivel_t* nivel, coordenada_t posicion, char tipo);

/*
 * Jugar?? un turno y dejar?? el juego en el estado correspondiente.
 * Har??n su jugada enanos, elfos y orcos en ese orden.
 */
void jugar_turno(juego_t* juego);

/* 
 * Mostrar?? el mapa dependiendo del nivel en que se encuentra el jugador.
 */
void mostrar_juego(juego_t juego);

#endif /* __DEFENDIENDO_TORRES_H__ */
