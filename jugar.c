#include "jugar.h"
#include "animos.h"
#include "utiles.h"
#include "comandos.h"
#include <string.h>
#define MAX_COMANDO 30
#define MAX_CANT_COMANDOS 10
#define MAX_CANT_ARCHIVOS 10
#define MAX_LETRAS 50
const static int FILA_TORRE_1_LVL_1 = 7;
const static int COL_TORRE_1_LVL_1 = 0;
const static int FILA_ENTRADA_LVL_1 = 0;
const static int COL_ENTRADA_LVL_1 = 14;
const static int FILA_TORRE_2_LVL_2 = 7;
const static int COL_TORRE_2_LVL_2 = 14;
const static int FILA_ENTRADA_LVL_2 = 14;
const static int COL_ENTRADA_LVL_2 = 0;
const static int FILA_TORRE_1_LVL_3 = 19;
const static int COL_TORRE_1_LVL_3 = 4;
const static int FILA_TORRE_2_LVL_3 = 19;
const static int COL_TORRE_2_LVL_3 = 14;
const static int FILA_ENTRADA_1_LVL_3 = 0;
const static int COL_ENTRADA_1_LVL_3 = 0;
const static int FILA_ENTRADA_2_LVL_3 = 0;
const static int COL_ENTRADA_2_LVL_3 = 19;
const static int FILA_ENTRADA_1_LVL_4 = 19;
const static int COL_ENTRADA_1_LVL_4 = 0;
const static int FILA_ENTRADA_2_LVL_4 = 19;
const static int COL_ENTRADA_2_LVL_4 = 19;
const static int FILA_TORRE_1_LVL_4 = 0;
const static int COL_TORRE_1_LVL_4 = 4;
const static int FILA_TORRE_2_LVL_4 = 0;
const static int COL_TORRE_2_LVL_4 = 15; 
const static int MAX_TABLERO_CHICO = 15;
const static int MAX_TABLERO_GRANDE = 20;
const static int PRIMER_NIVEL = 1;
const static int SEGUNDO_NIVEL = 2;
const static int TERCER_NIVEL = 3;
const static int CUARTO_NIVEL = 4;
const static int INICIO_MAPA = 0;
const static int ERROR = -1;
const static int CONTADOR_INICIAL = 0;
const static int INICIO_CAMINO = 0;
const static int CONSE_DEF_EXTRA = 50;
const static int MAX_DEF_PRIMER_LVL = 5;
const static int MAX_DEF_SEGUNDO_LVL = 5;
const static int MAX_DEF_TERCER_LVL = 6;
const static int MAX_DEF_CUARTO_LVL = 8;
const static int INCONCLUSO = 0;
const static int MIN_ORCOS_DEF_EXTRA_1 = 25;
const static int MIN_ORCOS_DEF_EXTRA_2 = 50;
const static int NULO = 0;
const static int MAX_ENEMIGOS_SEGUNDO_LVL = 200;
const static int MAX_ENEMIGOS_TERCER_LVL = 300;
const static int MAX_ENEMIGOS_CUARTO_LVL = 500;
const static int PREG_LVL_BAJOS = 4;
const static int PREG_LVL_3 = 6;
const static int PREG_LVL_4 = 10;
const static int MUERTE_DE_ORCO = 0;
const static int DERROTA = -1;
const static int VICTORIA = 1;
const static char AFIRMATIVO_MAY = 'Y';
const static char NEGATIVO_MAY = 'N';
const static char ENANOS = 'G';
const static char ELFOS = 'L';
/*
POST: imprime por pantalla las opciones que tiene el usuario en el menu.
*/
void opciones(int *respuesta){
	printf("1)Comenzar juego.\n");
	printf("2)Responder preguntas.\n");
	printf("3)EXIT.\n");
	scanf(" %i", &(*respuesta));
}
/*
POST: devolvera true si es que la respuesta coincide con el parametro dado, caso contrario,
	devolvera false. 
*/
bool letra_valida(char respuesta){
	return((respuesta == AFIRMATIVO_MAY) || (respuesta == NEGATIVO_MAY));
}

/*
POST: imprime por pantalla las caracteristicas del nivel que se esta por jugar.
*/
void presentar_nivel(int nivel_actual){
	char respuesta;
	
	if(nivel_actual == PRIMER_NIVEL){
		printf("                          NIVEL 1!!!\n");
		printf("los orcos ingresaran por la parte derecha del tablero, y la torre sera\n");
		printf("defendida inicialmente por 5 enanos, los cuales seran posicionados por el\n");
		printf("jugador. Cada 25 orcos ingresados en el camino, se tendra la posibilidad\n");
		printf("de agregar un enano extra, a costa de restarle 50 puntos a la torre 1.\n");
		printf("El objetivo es defender la torre 1 con exito de la invasion de orcos\n");
		printf("Presione una letra para continuar:\n");
		scanf(" %c", &respuesta);
		system("clear");
	}else if(nivel_actual == SEGUNDO_NIVEL){
		printf("                          NIVEL 2\n");
		printf("los orcos ingresaran por la parte izquierda del tablero, y la torre sera\n");
		printf("defendida inicialmente por 5 elfos, los cuales seran posicionados por el\n");
		printf("jugador. Cada 50 orcos ingresados en el camino, se tendra la posibilidad\n");
		printf("de agregar un elfo extra, a costa de restarle 50 puntos a la torre 2.\n");
		printf("El objetivo es defender la torre 2 con exito de la invasion de orcos\n");
		printf("Presione una letra para continuar:\n");
		scanf(" %c", &respuesta);
		system("clear");
	}else if(nivel_actual == TERCER_NIVEL){
		printf("                          NIVEL 3\n");
		printf("los orcos ingresaran por la parte de arriba del tablero, en dos caminos, y las torres seran\n");
		printf("defendidas inicialmente por 6 defensores, 3 enanos y 3 elfos, los cuales seran posicionados por el\n");
		printf("jugador, donde primero se colocaran los enanos y despues los elfos. Cada 50 orcos ingresados en el camino, se tendra la posibilidad\n");
		printf("de agregar un elfo o un enano extra, a costa de restarle 50 puntos a la torre 1 en caso de ser un enano o 50 puntos a la torre 2 en caso de ser un elfo.\n");
		printf("El objetivo es defender las dos torres con exito de la invasion de orcos\n");
		printf("Presione una letra para continuar:\n");
		scanf(" %c", &respuesta);
		system("clear");
	}else{
		printf("                          NIVEL 4\n");
		printf("los orcos ingresaran por la parte de abajo del tablero, en dos caminos, y las torres seran\n");
		printf("defendidas inicialmente por 8 defensores, 4 enanos y 4 elfos, los cuales seran posicionados por el\n");
		printf("jugador, donde primero se colocaran los enanos y despues los elfos. Cada 50 orcos ingresados en el camino, se tendra la posibilidad\n");
		printf("de agregar un elfo o un enano extra, a costa de restarle 50 puntos a la torre 1 en caso de ser un enano o 50 puntos a la torre 2 en caso de ser un elfo.\n");
		printf("El objetivo es defender las dos torres con exito de la invasion de orcos\n");
		printf("Presione una letra para continuar:\n");
		scanf(" %c", &respuesta);
		system("clear");
	}
}

/*
POST: devolvera true si las coodenadas estan dentro del rango valido, caso contrario,
	devolvera false.
*/
bool coodenadas_validas(int nivel_actual, coordenada_t posicion){
	if(nivel_actual == PRIMER_NIVEL || nivel_actual == SEGUNDO_NIVEL){
		if((posicion.fil >= INICIO_MAPA && posicion.fil < MAX_TABLERO_CHICO) && (posicion.col >= INICIO_MAPA && posicion.col < MAX_TABLERO_CHICO)){
			return true;
		}
	}
	if(nivel_actual == TERCER_NIVEL || nivel_actual == CUARTO_NIVEL){
		if((posicion.fil >= INICIO_MAPA && posicion.fil < MAX_TABLERO_GRANDE) && (posicion.col >= INICIO_MAPA && posicion.col < MAX_TABLERO_GRANDE)){
			return true;
		}
	}
return false;
}
/*
POST: se rellena el vector defensor con las coordenadas de cada defensor.
*/
void agregar_ayudantes(juego_t *juego){
	int resultado;
	int defensor_nuevo;
	coordenada_t posicion;
	defensor_nuevo = juego->nivel.tope_defensores;
	printf("los defensores son %i \n", juego->nivel.tope_defensores);
	printf("ingresar fila para poner el defensor %i \n", defensor_nuevo + 1);
	scanf(" %i", &posicion.fil);
	printf("ingresar columna para poner el defensor %i \n", defensor_nuevo + 1);
	scanf(" %i", &posicion.col);
	resultado = agregar_defensor(&(juego->nivel), posicion, juego->nivel.defensores[defensor_nuevo].tipo);
	system("clear");	
	mostrar_juego(*juego);
	while((resultado == ERROR) || (coodenadas_validas(juego->nivel_actual, posicion) == false)){
		printf("ERROR, fila o columna no valida, por favor:\n");
		printf("ingresar fila para poner el defensor %i \n", defensor_nuevo + 1);
		scanf(" %i", &posicion.fil);
		printf("ingresar columna para poner el defensor %i \n", defensor_nuevo + 1);
		scanf(" %i", &posicion.col);
		resultado = agregar_defensor(&(juego->nivel), posicion, juego->nivel.defensores[juego->nivel.tope_defensores].tipo);
		system("clear");	
		mostrar_juego(*juego);
	}
}
/*
PRE: deben ingresar los orcos por el camino.
POST: devolvera la cantidad de orcos que estan actualmente en el nivel.
*/		
int cantidad_orcos_en_nivel(nivel_t nivel){
	int contador = CONTADOR_INICIAL;
	for (int i = 0; i <  nivel.tope_enemigos;++i){
		if (nivel.enemigos[i].pos_en_camino >= INICIO_CAMINO){
			contador++;
		}
	}
return contador;
}

/*
POST: devuelve true si es que la letra corresponde a uno de los dos tipos de defensores
	validos, caso contrarip, devuelve false.
*/
bool tipo_valido(char tipo, int nivel_actual){
	if((nivel_actual == PRIMER_NIVEL) && (tipo == ENANOS)){
		return true;
	}else if((nivel_actual == SEGUNDO_NIVEL) && (tipo == ELFOS)){
		return true;
	}else if((nivel_actual == TERCER_NIVEL || nivel_actual == CUARTO_NIVEL) && (tipo == ENANOS || tipo == ELFOS)){
		return true;
	}else return false;

}
/*
PRE: deben haber ingresado los orcos al camino.
POST: agrega un defensor nuevo al vector defensor.
*/
void agregar_ayudante_extra(juego_t *juego, configuracion_t configuracion){
	char respuesta;
	int defensor_nuevo;
	printf("ATENCION!! han ingresado la cantidad minima de orcos para agregar un defensor\n");
	printf("¿Desea agregar un defensor? (se le restaran 50 puntos de vida a la torre correspondiente\n");
	printf("enano: torre 1, elfo: torre 2)\n");
	printf("Y / N\n");
	scanf(" %c", &respuesta);
	while(letra_valida(respuesta) == false){
		printf("ERROR!!\n");
		printf("letra no valida.... \n");
		printf("Y / N\n");
		scanf(" %c", &respuesta);
	}
	if ((respuesta == AFIRMATIVO_MAY) && (juego->torres.enanos_extra > CONTADOR_INICIAL || juego->torres.elfos_extra > CONTADOR_INICIAL)){
		defensor_nuevo = juego->nivel.tope_defensores;
		printf("ingresar tipo de defensor: (G: ENANO, L: ELFO)\n");
		scanf(" %c", &juego->nivel.defensores[defensor_nuevo].tipo);
		while(tipo_valido(juego->nivel.defensores[defensor_nuevo].tipo, juego->nivel_actual) == false){
			printf("ERROR!!\n");
			printf("Tipo no valido.... \n");
			printf("ingresar tipo de defensor: (G: ENANO, L: ELFO)\n");
			scanf(" %c", &juego->nivel.defensores[defensor_nuevo].tipo);
		}
		agregar_ayudantes(&(*juego));

		if(configuracion.configuracion_defecto){
			if (juego->nivel.defensores[defensor_nuevo].tipo == 'G'){
				juego->torres.resistencia_torre_1 -= CONSE_DEF_EXTRA;
				juego->torres.enanos_extra -= 1;
			} else if(juego->nivel.defensores[defensor_nuevo].tipo == 'L'){
				juego->torres.resistencia_torre_2 -= CONSE_DEF_EXTRA;
				juego->torres.elfos_extra -= 1;
			}
		}else{
			if (juego->nivel.defensores[defensor_nuevo].tipo == 'G'){
				if(configuracion.enanos_extras.costo_torre_1 != -1){
					juego->torres.resistencia_torre_1 -= configuracion.enanos_extras.costo_torre_1;
				}else juego->torres.resistencia_torre_1 -= CONSE_DEF_EXTRA;
				if(configuracion.enanos_extras.costo_torre_2 != -1){
					juego->torres.resistencia_torre_2 -= configuracion.enanos_extras.costo_torre_2;
				}
				juego->torres.enanos_extra -= 1;
			} else if(juego->nivel.defensores[defensor_nuevo].tipo == 'L'){
				if(configuracion.elfos_extras.costo_torre_1 != -1){
					juego->torres.resistencia_torre_1 -= configuracion.elfos_extras.costo_torre_1;
				}
				if(configuracion.enanos_extras.costo_torre_2 != -1){
					juego->torres.resistencia_torre_2 = configuracion.enanos_extras.costo_torre_2;
				}else juego->torres.resistencia_torre_2 -= CONSE_DEF_EXTRA;
				juego->torres.elfos_extra -= 1;
			}
		}
	}else if (juego->torres.enanos_extra == CONTADOR_INICIAL ){
		printf("No quedan mas enanos en las torres");
	}else if(juego->torres.elfos_extra == CONTADOR_INICIAL){
		printf("No quedan mas elfos en las torres\n");
	}	
	system("clear");	
	mostrar_juego(*juego);
}
/*
PRE: el struct juego debe haberse completado con datos validos y coherentes.
POST: completa el struct juego con los datos faltantes y necesarios para inciar el nivel.
*/
void iniciar_nivel_1 (juego_t *juego, configuracion_t configuracion){
	if(configuracion.configuracion_defecto){
		coordenada_t entrada_1;
		coordenada_t torre_1;
		torre_1.fil = FILA_TORRE_1_LVL_1;
		torre_1.col = COL_TORRE_1_LVL_1;

		entrada_1.fil = FILA_ENTRADA_LVL_1;
		entrada_1.col = COL_ENTRADA_LVL_1;
		obtener_camino(juego->nivel.camino_1, &(juego->nivel.tope_camino_1), entrada_1, torre_1);
		presentar_nivel(juego->nivel_actual);
		mostrar_juego(*juego);
		while(juego->nivel.tope_defensores < MAX_DEF_PRIMER_LVL){
		agregar_ayudantes(&(*juego));		
		}	
	}else{
		if(strcmp(configuracion.caminos.archivo, "-1") != -1){
			juego->nivel.tope_camino_1 = configuracion.caminos.tope_camino_1_lvl_1;
			for (int i = 0; i < juego->nivel.tope_camino_1; ++i){
				juego->nivel.camino_1[i].fil = configuracion.caminos.camino_1_lvl_1[i].fil;
				juego->nivel.camino_1[i].col = configuracion.caminos.camino_1_lvl_1[i].col;
			}			
		}else{
			coordenada_t entrada_1;
			coordenada_t torre_1;
			torre_1.fil = FILA_TORRE_1_LVL_1;
			torre_1.col = COL_TORRE_1_LVL_1;

			entrada_1.fil = FILA_ENTRADA_LVL_1;
			entrada_1.col = COL_ENTRADA_LVL_1;
			obtener_camino(juego->nivel.camino_1, &(juego->nivel.tope_camino_1), entrada_1, torre_1);
		}
		presentar_nivel(juego->nivel_actual);
		mostrar_juego(*juego);
		if(configuracion.cant_enanos[0] != -1){
			while(juego->nivel.tope_defensores < configuracion.cant_enanos[0]){
			agregar_ayudantes(&(*juego));		
			}
		}else{
			while(juego->nivel.tope_defensores < MAX_DEF_PRIMER_LVL){
			agregar_ayudantes(&(*juego));		
			}
		}
		if(configuracion.cant_elfos[0] != -1){
			while(juego->nivel.tope_defensores < (configuracion.cant_enanos[0] + configuracion.cant_elfos[0])){
				agregar_ayudantes(&(*juego));
			}
		}
	}
}
/*
PRE: tienen que haber ingresado orcos al camino.
POST: cuenta la cantidad de orcos muertos.
*/
void calcular_orcos_muertos(int *orcos_muertos, juego_t juego){
	int contador = 0;
	for (int i = 0; i < juego.nivel.tope_enemigos; ++i){
		if(juego.nivel.enemigos[i].vida <= MUERTE_DE_ORCO){
			contador++;
		}
	}
	(*orcos_muertos) += contador;
}

/*
POST: se juega el primer nivel.
*/
void jugar_nivel_1 (juego_t *juego, int *preguntar_defensor_extra, configuracion_t configuracion, int* orcos_muertos, bool grabar, FILE ** grabar_juego){
	
	while (estado_nivel(juego->nivel) == INCONCLUSO && estado_juego(*juego) == INCONCLUSO){
		jugar_turno(&(*juego));
		mostrar_juego(*juego);
			
		if(((cantidad_orcos_en_nivel(juego->nivel) % MIN_ORCOS_DEF_EXTRA_1) == NULO) && (*preguntar_defensor_extra > CONTADOR_INICIAL)){
			*preguntar_defensor_extra -= 1;
			printf("la cantidad de preguntas que quedan son: %i \n", *preguntar_defensor_extra);
			agregar_ayudante_extra(&(*juego), configuracion);
		}
		if(configuracion.configuracion_defecto){
			detener_el_tiempo(1);
		}else{
			if(configuracion.velocidad_juego != -1){
				detener_el_tiempo(configuracion.velocidad_juego);
			}else detener_el_tiempo(1);
		}
		if(grabar){
			fwrite(&(*juego), sizeof(juego_t), 1, *grabar_juego);
		}
	}
	calcular_orcos_muertos(&(*orcos_muertos), *juego);
}
/*
PRE: se debe haber completado con exito el primer nivel.
POST:se completa el struct juego con los datos faltantes y necesarios para inciar el nivel.
*/
void iniciar_nivel_2(juego_t *juego, nivel_t *nivel, int *preguntar_defensor_extra, configuracion_t configuracion){
	if(configuracion.configuracion_defecto){
		system("clear");
		coordenada_t entrada_2;
		coordenada_t torre_2;
		juego->nivel_actual = SEGUNDO_NIVEL;
		nivel->max_enemigos_nivel = MAX_ENEMIGOS_SEGUNDO_LVL;
		torre_2.fil = FILA_TORRE_2_LVL_2;
		torre_2.col = COL_TORRE_2_LVL_2;

		entrada_2.fil = FILA_ENTRADA_LVL_2;
		entrada_2.col = COL_ENTRADA_LVL_2;

		juego->nivel.tope_camino_1 = CONTADOR_INICIAL;

		obtener_camino(juego->nivel.camino_2, &(juego->nivel.tope_camino_2), entrada_2, torre_2);
		nivel->tope_defensores = CONTADOR_INICIAL;
		nivel->tope_enemigos = CONTADOR_INICIAL;
		*preguntar_defensor_extra = PREG_LVL_BAJOS;
		presentar_nivel(juego->nivel_actual);
		system("clear");
		mostrar_juego(*juego);
		while(juego->nivel.tope_defensores < MAX_DEF_SEGUNDO_LVL){
			nivel->defensores[nivel->tope_defensores].tipo = ELFOS;
			agregar_ayudantes(&(*juego));
		}
	}else{
		system("clear");
		if(strcmp(configuracion.caminos.archivo, "-1") != 0){
			juego->nivel.tope_camino_2 = configuracion.caminos.tope_camino_2_lvl_2;
			for (int i = 0; i < juego->nivel.tope_camino_2; ++i){
				juego->nivel.camino_2[i].fil = configuracion.caminos.camino_2_lvl_2[i].fil;
				juego->nivel.camino_2[i].col = configuracion.caminos.camino_2_lvl_2[i].col;
			}
		}else{
			coordenada_t entrada_2;
			coordenada_t torre_2;
			juego->nivel_actual = SEGUNDO_NIVEL;
			nivel->max_enemigos_nivel = MAX_ENEMIGOS_SEGUNDO_LVL;
			torre_2.fil = FILA_TORRE_2_LVL_2;
			torre_2.col = COL_TORRE_2_LVL_2;

			entrada_2.fil = FILA_ENTRADA_LVL_2;
			entrada_2.col = COL_ENTRADA_LVL_2;
			obtener_camino(juego->nivel.camino_2, &(juego->nivel.tope_camino_2), entrada_2, torre_2);
		}
		juego->nivel_actual = SEGUNDO_NIVEL;
		nivel->max_enemigos_nivel = MAX_ENEMIGOS_SEGUNDO_LVL;
		juego->nivel.tope_camino_1 = CONTADOR_INICIAL;
		nivel->tope_defensores = CONTADOR_INICIAL;
		nivel->tope_enemigos = CONTADOR_INICIAL;
		*preguntar_defensor_extra = PREG_LVL_BAJOS;
		presentar_nivel(juego->nivel_actual);
		system("clear");
		mostrar_juego(*juego);
		if(configuracion.cant_enanos[1] != -1){
			while(juego->nivel.tope_defensores < configuracion.cant_enanos[1]){
				nivel->defensores[nivel->tope_defensores].tipo = ENANOS;
				agregar_ayudantes(&(*juego));
			}
		}
		if(configuracion.cant_elfos[1] != -1){
			if(configuracion.cant_enanos[1] != -1){
				while(juego->nivel.tope_defensores < configuracion.cant_enanos[1] +  configuracion.cant_elfos[1]){
					nivel->defensores[nivel->tope_defensores].tipo = ELFOS;
					agregar_ayudantes(&(*juego));
				}
			}else{
				while(juego->nivel.tope_defensores < configuracion.cant_elfos[1]){
					nivel->defensores[nivel->tope_defensores].tipo = ELFOS;
					agregar_ayudantes(&(*juego));
				}
			}
		}else{
			while(juego->nivel.tope_defensores < MAX_DEF_SEGUNDO_LVL){
				nivel->defensores[nivel->tope_defensores].tipo = ELFOS;
				agregar_ayudantes(&(*juego));
			}
		}
	}
}

/*
POST: se juega el segundo nivel.
*/
void jugar_nivel_2(juego_t *juego, int *preguntar_defensor_extra, configuracion_t configuracion, int* orcos_muertos, bool grabar, FILE ** grabar_juego){
	
	while (estado_nivel(juego->nivel) == INCONCLUSO && estado_juego(*juego) == INCONCLUSO){
		mostrar_juego(*juego);
		jugar_turno(&(*juego));
			
		if((cantidad_orcos_en_nivel(juego->nivel) % MIN_ORCOS_DEF_EXTRA_2 == NULO) && (*preguntar_defensor_extra > CONTADOR_INICIAL)){
			*preguntar_defensor_extra -= 1;
			printf("la cantidad de preguntas que quedan son: %i \n", *preguntar_defensor_extra);
			agregar_ayudante_extra(&(*juego), configuracion);
		}
		if(configuracion.configuracion_defecto){
			detener_el_tiempo(1);
		}else{
			if(configuracion.velocidad_juego != -1){
				detener_el_tiempo(configuracion.velocidad_juego);
			}else detener_el_tiempo(1);
		}
		if(grabar){
			fwrite(&(*juego), sizeof(juego_t), 1, *grabar_juego);
		}
	}
	calcular_orcos_muertos(&(*orcos_muertos), *juego);
}
/*
PRE: se debe haber completado con exito el segundo nivel.
POST: se completa el struct juego con los datos faltantes y necesarios para inciar el nivel.
*/
void iniciar_nivel_3(juego_t *juego, nivel_t *nivel, int *preguntar_defensor_extra, configuracion_t configuracion){
	system("clear");
	int contador = MAX_DEF_TERCER_LVL / 2;
	if(configuracion.configuracion_defecto){
		coordenada_t entrada_1;
		coordenada_t torre_1;
		coordenada_t entrada_2;
		coordenada_t torre_2;
		juego->nivel_actual = TERCER_NIVEL;
		nivel->max_enemigos_nivel = MAX_ENEMIGOS_TERCER_LVL;

		torre_1.fil = FILA_TORRE_1_LVL_3;
		torre_1.col = COL_TORRE_1_LVL_3;

		entrada_1.fil = FILA_ENTRADA_1_LVL_3;
		entrada_1.col = COL_ENTRADA_1_LVL_3;

		torre_2.fil = FILA_TORRE_2_LVL_3;
		torre_2.col = COL_TORRE_2_LVL_3;

		entrada_2.fil = FILA_ENTRADA_2_LVL_3;
		entrada_2.col = COL_ENTRADA_2_LVL_3;

		obtener_camino(juego->nivel.camino_1, &(juego->nivel.tope_camino_1), entrada_1, torre_1);
		obtener_camino(juego->nivel.camino_2, &(juego->nivel.tope_camino_2), entrada_2, torre_2);

		nivel->tope_defensores = CONTADOR_INICIAL;
		nivel->tope_enemigos = CONTADOR_INICIAL;
		*preguntar_defensor_extra = PREG_LVL_3;
		presentar_nivel(juego->nivel_actual);
		system("clear");
		mostrar_juego(*juego);
		while(nivel->tope_defensores < MAX_DEF_TERCER_LVL){
			if (nivel->tope_defensores < MAX_DEF_TERCER_LVL / 2){
				nivel->defensores[nivel->tope_defensores].tipo = ENANOS;	
			}else {
				nivel->defensores[nivel->tope_defensores].tipo = ELFOS;
			}
			agregar_ayudantes(&(*juego));
		}		
	}else{
		if(strcmp(configuracion.caminos.archivo, "-1") != -1){
			juego->nivel.tope_camino_1 = configuracion.caminos.tope_camino_1_lvl_3;
			for (int i = 0; i < juego->nivel.tope_camino_1; ++i){
				juego->nivel.camino_1[i].fil = configuracion.caminos.camino_1_lvl_3[i].fil;
				juego->nivel.camino_1[i].col = configuracion.caminos.camino_1_lvl_3[i].col;
			}
			juego->nivel.tope_camino_2 = configuracion.caminos.tope_camino_2_lvl_3;
			for (int i = 0; i < juego->nivel.tope_camino_2; ++i){
				juego->nivel.camino_2[i].fil = configuracion.caminos.camino_2_lvl_3[i].fil;
				juego->nivel.camino_2[i].col = configuracion.caminos.camino_2_lvl_3[i].col;
			}
		}else{
			coordenada_t entrada_1;
			coordenada_t torre_1;
			coordenada_t entrada_2;
			coordenada_t torre_2;
			torre_1.fil = FILA_TORRE_1_LVL_3;
			torre_1.col = COL_TORRE_1_LVL_3;

			entrada_1.fil = FILA_ENTRADA_1_LVL_3;
			entrada_1.col = COL_ENTRADA_1_LVL_3;

			torre_2.fil = FILA_TORRE_2_LVL_3;
			torre_2.col = COL_TORRE_2_LVL_3;

			entrada_2.fil = FILA_ENTRADA_2_LVL_3;
			entrada_2.col = COL_ENTRADA_2_LVL_3;

			obtener_camino(juego->nivel.camino_1, &(juego->nivel.tope_camino_1), entrada_1, torre_1);
			obtener_camino(juego->nivel.camino_2, &(juego->nivel.tope_camino_2), entrada_2, torre_2);
		}
		juego->nivel_actual = TERCER_NIVEL;
		nivel->max_enemigos_nivel = MAX_ENEMIGOS_TERCER_LVL;
		nivel->tope_defensores = CONTADOR_INICIAL;
		nivel->tope_enemigos = CONTADOR_INICIAL;
		*preguntar_defensor_extra = PREG_LVL_3;
		presentar_nivel(juego->nivel_actual);
		system("clear");
		mostrar_juego(*juego);
		if(configuracion.cant_enanos[2] != -1){
			while(nivel->tope_defensores < configuracion.cant_enanos[2]){
				nivel->defensores[nivel->tope_defensores].tipo = ENANOS;
				agregar_ayudantes(&(*juego));
			}
		}else{
			while(nivel->tope_defensores < MAX_DEF_TERCER_LVL / 2){
				nivel->defensores[nivel->tope_defensores].tipo = ENANOS;
				agregar_ayudantes(&(*juego));
			}
		}
		if(configuracion.cant_elfos[2] != -1){
			if(configuracion.cant_enanos[2] != -1){
				while(nivel->tope_defensores < configuracion.cant_enanos[2] + configuracion.cant_elfos[2]){
					nivel->defensores[nivel->tope_defensores].tipo = ELFOS;
					agregar_ayudantes(&(*juego));
				}
			}else{
				while(nivel->tope_defensores < MAX_DEF_TERCER_LVL / 2 + configuracion.cant_elfos[2]){
					nivel->defensores[nivel->tope_defensores].tipo = ELFOS;
					agregar_ayudantes(&(*juego));
				}
			}
		}else{
			while(contador != 0){
				nivel->defensores[nivel->tope_defensores].tipo = ELFOS;
				agregar_ayudantes(&(*juego));
				contador--;
			}
		}
	}
}
/*
POST: se juega el tercer nivel.
*/
void jugar_nivel_3(juego_t *juego, int *preguntar_defensor_extra, configuracion_t configuracion, int* orcos_muertos, bool grabar, FILE ** grabar_juego){
	
	while((estado_nivel(juego->nivel) == INCONCLUSO) && (estado_juego(*juego) == INCONCLUSO)){
		mostrar_juego(*juego);
		jugar_turno(&(*juego));
		if((cantidad_orcos_en_nivel(juego->nivel) % MIN_ORCOS_DEF_EXTRA_2) == NULO && *preguntar_defensor_extra > CONTADOR_INICIAL){
			*preguntar_defensor_extra -= 1;
			printf("la cantidad de preguntas que quedan son: %i \n", *preguntar_defensor_extra);
			agregar_ayudante_extra(&(*juego), configuracion);
		}
		if(configuracion.configuracion_defecto){
			detener_el_tiempo(1);
		}else{
			if(configuracion.velocidad_juego != -1){
				detener_el_tiempo(configuracion.velocidad_juego);
			}else detener_el_tiempo(1);
		}
		if(grabar){
			fwrite(&(*juego), sizeof(juego_t), 1, *grabar_juego);
		}
	}
	calcular_orcos_muertos(&(*orcos_muertos), *juego);
}
/*
PRE: se debe haber completado con exito el tercer nivel.
POST: se completa el struct juego con los datos faltantes y necesarios para inciar el nivel.
*/
void iniciar_nivel_4(juego_t *juego, nivel_t *nivel, int *preguntar_defensor_extra, configuracion_t configuracion){
	system("clear");
	int contador = MAX_DEF_CUARTO_LVL / 2;
	if(configuracion.configuracion_defecto){
		coordenada_t entrada_1;
		coordenada_t torre_1;
		coordenada_t entrada_2;
		coordenada_t torre_2;
		juego->nivel_actual = CUARTO_NIVEL;
		nivel->max_enemigos_nivel = MAX_ENEMIGOS_CUARTO_LVL;

		torre_1.fil = FILA_TORRE_1_LVL_4;
		torre_1.col = COL_TORRE_1_LVL_4;

		entrada_1.fil = FILA_ENTRADA_1_LVL_4;
		entrada_1.col = COL_ENTRADA_1_LVL_4;

		torre_2.fil = FILA_TORRE_2_LVL_4;
		torre_2.col = COL_TORRE_2_LVL_4;

		entrada_2.fil = FILA_ENTRADA_2_LVL_4;
		entrada_2.col = COL_ENTRADA_2_LVL_4;

		obtener_camino(juego->nivel.camino_1, &(juego->nivel.tope_camino_1), entrada_1, torre_1);
		obtener_camino(juego->nivel.camino_2, &(juego->nivel.tope_camino_2), entrada_2, torre_2);

		nivel->tope_defensores = CONTADOR_INICIAL;
		nivel->tope_enemigos = CONTADOR_INICIAL;
		*preguntar_defensor_extra = PREG_LVL_4;
		presentar_nivel(juego->nivel_actual);
		system("clear");
		mostrar_juego(*juego);
		while(nivel->tope_defensores < MAX_DEF_CUARTO_LVL){
			if (nivel->tope_defensores < MAX_DEF_CUARTO_LVL / 2){
				nivel->defensores[nivel->tope_defensores].tipo = ENANOS;	
			}else {
				nivel->defensores[nivel->tope_defensores].tipo = ELFOS;
			}	
			agregar_ayudantes(&(*juego));
		}	
	}else{
		if(strcmp(configuracion.caminos.archivo, "-1") != 0){
			juego->nivel.tope_camino_1 = configuracion.caminos.tope_camino_1_lvl_4;
			for (int i = 0; i < juego->nivel.tope_camino_1; ++i){
				juego->nivel.camino_1[i].fil = configuracion.caminos.camino_1_lvl_4[i].fil;
				juego->nivel.camino_1[i].col = configuracion.caminos.camino_1_lvl_4[i].col;
			}
			juego->nivel.tope_camino_2 = configuracion.caminos.tope_camino_2_lvl_4;
			for (int i = 0; i < juego->nivel.tope_camino_2; ++i){
				juego->nivel.camino_2[i].fil = configuracion.caminos.camino_2_lvl_4[i].fil;
				juego->nivel.camino_2[i].col = configuracion.caminos.camino_2_lvl_4[i].col;
			}
		}else{
			coordenada_t entrada_1;
			coordenada_t torre_1;
			coordenada_t entrada_2;
			coordenada_t torre_2;

			torre_1.fil = FILA_TORRE_1_LVL_4;
			torre_1.col = COL_TORRE_1_LVL_4;

			entrada_1.fil = FILA_ENTRADA_1_LVL_4;
			entrada_1.col = COL_ENTRADA_1_LVL_4;

			torre_2.fil = FILA_TORRE_2_LVL_4;
			torre_2.col = COL_TORRE_2_LVL_4;

			entrada_2.fil = FILA_ENTRADA_2_LVL_4;
			entrada_2.col = COL_ENTRADA_2_LVL_4;

			obtener_camino(juego->nivel.camino_1, &(juego->nivel.tope_camino_1), entrada_1, torre_1);
			obtener_camino(juego->nivel.camino_2, &(juego->nivel.tope_camino_2), entrada_2, torre_2);
		}
		juego->nivel_actual = CUARTO_NIVEL;
		nivel->max_enemigos_nivel = MAX_ENEMIGOS_CUARTO_LVL;
		nivel->tope_defensores = CONTADOR_INICIAL;
		nivel->tope_enemigos = CONTADOR_INICIAL;
		*preguntar_defensor_extra = PREG_LVL_4;
		presentar_nivel(juego->nivel_actual);
		system("clear");
		mostrar_juego(*juego);
		if(configuracion.cant_enanos[3] != -1){
			while(nivel->tope_defensores < configuracion.cant_enanos[3]){
				nivel->defensores[nivel->tope_defensores].tipo = ENANOS;
				agregar_ayudantes(&(*juego));
			}
		}else{
			while(nivel->tope_defensores < MAX_DEF_CUARTO_LVL / 2){
				nivel->defensores[nivel->tope_defensores].tipo = ENANOS;
				agregar_ayudantes(&(*juego));
			}
		}
		if(configuracion.cant_elfos[3] != -1){
			if(configuracion.cant_enanos[3] != -1){
				while(nivel->tope_defensores < configuracion.cant_enanos[3] + configuracion.cant_elfos[3]){
					nivel->defensores[nivel->tope_defensores].tipo = ELFOS;
					agregar_ayudantes(&(*juego));
				}
			}else{
				while(nivel->tope_defensores < MAX_DEF_CUARTO_LVL + configuracion.cant_elfos[3]){
					nivel->defensores[nivel->tope_defensores].tipo = ELFOS;
					agregar_ayudantes(&(*juego));
				}
			}
		}else{
			while(contador != 0){
				nivel->defensores[nivel->tope_defensores].tipo = ELFOS;
				agregar_ayudantes(&(*juego));
				contador--;
			}
		}
	}
}
/*
POST: se juega el cuarto nivel.
*/
void jugar_nivel_4 (juego_t *juego, int *preguntar_defensor_extra, configuracion_t configuracion, int* orcos_muertos, bool grabar, FILE ** grabar_juego){
	
	while((estado_nivel(juego->nivel) == INCONCLUSO) && (estado_juego(*juego) == INCONCLUSO)){
		mostrar_juego(*juego);
		jugar_turno(&(*juego));
		if((cantidad_orcos_en_nivel(juego->nivel) % MIN_ORCOS_DEF_EXTRA_2) == NULO && *preguntar_defensor_extra > CONTADOR_INICIAL){
			*preguntar_defensor_extra -= 1;
			printf("la cantidad de preguntas que quedan son: %i \n", *preguntar_defensor_extra);
			agregar_ayudante_extra(&(*juego), configuracion);
		}
		if(configuracion.configuracion_defecto){
			detener_el_tiempo(1);
		}else{
			if(configuracion.velocidad_juego != -1){
				detener_el_tiempo(configuracion.velocidad_juego);
			}else detener_el_tiempo(1);
		}
		if(grabar){
			fwrite(&(*juego), sizeof(juego_t), 1, *grabar_juego);
		}
	}
	calcular_orcos_muertos(&(*orcos_muertos), *juego);
}
/*
PRE: se tuvo qur haber terminado el juego
POST: pide al usuario su nmbre para agregarlo al ranking
*/
void ingresar_nombre(char usuario[MAX_LETRAS]){
	printf("ingresar nombre para ranking:\n");
	scanf(" %s", usuario);
}

void jugar_normal(int* viento, int* humedad, char* animo_legolas, char* animo_gimli, juego_t* juego, int* preguntar_defensor_extra, configuracion_t configuracion, bool grabar, char archivos[MAX_CANT_ARCHIVOS][MAX_LETRAS]){
	int orcos_muertos = CONTADOR_INICIAL;
	char usuario[MAX_LETRAS];
	FILE * grabar_juego;
	if(grabar){
		grabar_juego = fopen(archivos[1], "w");
		if(!grabar_juego){
			printf("no se pudo abrir el archivo: %s\n", archivos[1]);
			return;
		}
	}
	if((configuracion.animo_enanos.fallo == -1) || (configuracion.animo_elfos.fallo == -1) || (configuracion.animo_enanos.critico == -1) || (configuracion.animo_elfos.critico == -1) || (configuracion.configuracion_defecto)){
		animos(&(*viento), &(*humedad), &(*animo_legolas), &(*animo_gimli));
		system("clear");
	}
	inicializar_juego(&(*juego), *viento, *humedad, *animo_legolas, *animo_gimli, configuracion);
	iniciar_nivel_1 (&(*juego), configuracion);
	jugar_nivel_1(&(*juego), &(*preguntar_defensor_extra), configuracion, &orcos_muertos, grabar, &grabar_juego);
	
	if (estado_juego(*juego) == INCONCLUSO){
		iniciar_nivel_2(&(*juego), &(juego->nivel), &(*preguntar_defensor_extra), configuracion);
		jugar_nivel_2(&(*juego), &(*preguntar_defensor_extra), configuracion, &orcos_muertos, grabar, &grabar_juego);				
	}
	if(estado_juego(*juego) == INCONCLUSO){
		iniciar_nivel_3(&(*juego), &(juego->nivel), &(*preguntar_defensor_extra), configuracion);
		jugar_nivel_3(&(*juego), &(*preguntar_defensor_extra), configuracion, &orcos_muertos, grabar, &grabar_juego);
	}
	if(estado_juego(*juego) == INCONCLUSO){
		iniciar_nivel_4(&(*juego), &(juego->nivel), &(*preguntar_defensor_extra), configuracion);
		jugar_nivel_4(&(*juego), &(*preguntar_defensor_extra), configuracion, &orcos_muertos, grabar, &grabar_juego);
	}
	if(grabar){
		fclose(grabar_juego);
	}
	if (estado_juego(*juego) == DERROTA){
		system("clear");
		printf("Una de las torres ah sido destruida, los orcos invadieron con exito.\n");
		printf("Mas suerte la proxima!!\n");
		ingresar_nombre(usuario);
	}
	if (estado_juego(*juego) == VICTORIA ){
		system("clear");
		printf("Has defendido con exito las torres de las oleadas de orcos.\n");
		printf("Felicidades por ganar el juego!!!!!\n");
		ingresar_nombre(usuario);
	}
	calcular_ranking(orcos_muertos, *juego, usuario, archivos[0], configuracion);
}