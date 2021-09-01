#include "jugar.h"
#include "animos.h"
#include "utiles.h"
#include "comandos.h"
#include <string.h>

#define JUGAR "jugar"
#define RANKING "ranking"
#define CREAR_CAMINO "crear_camino"
#define CONFIGURACION "crear_configuracion"
#define REPETICION "poneme_la_repe"
#define ETIQUETA_LISTAR "listar="
#define ETIQUETA_CONFIG "config="
#define ETIQUETA_GRAB "grabacion="
#define ETIQUETA_VELOCIDAD "velocidad="
#define MAX_CANT_COMANDOS 10
#define MAX_LETRAS 50
#define MAX_CANT_ARCHIVOS 10
#define VERDE_CLARO "\033[0m\033[32m"
#define AMARILLO "\033[1m\033[33m"
#define FIN "\033[0m"
#define MAX_FILAS 30
#define MAX_COLUMNAS 30
#define LECTURA "r"
#define ESCRITURA "w"
#define CABECERA_RANK "ranking_"
#define EXTENCION_CSV ".csv"
#define LECTURA_RANKING "%[^;];%i\n"
#define ESCRITURA_RANKING "%s;%i\n" 
#define NOMBRE_RANK_DEFECTO "ranking.csv"
#define D_ARRIBA "W"
#define D_ABAJO "S"
#define D_DERECHA "D"
#define D_IZQUIERDA "A"
#define D_FINISH  "F"
#define ESCRITURA_CAMINOS "%i;%i\n" 
#define LECTURA_CAMINOS "%i;%i\n"
#define EXTENCION_TXT ".txt"
#define CAMINO_DEFEC "-1"
#define NOMBRE_CONFIG_DEFECTO "configuracion_defecto.txt"
#define LECTURA_ETIQUETA "%[^\n]\n"
#define RANKING_AUX "ranking_aux.csv"
const static int PRIMER_NIVEL = 1;
const static int SEGUNDO_NIVEL = 2;
const static int TERCER_NIVEL = 3;
const static int CUARTO_NIVEL = 4;
const static int DISTORCION_TABLERO = 10;
const static int MAX_TABLERO_CHICO = 15;
const static int MAX_TABLERO_GRANDE = 20;
const static int MIN_TABLERO = 0;
const static int PREG_LVL_BAJOS = 4;
const static int VIDA_MAX_TORRES = 600;
const static int DEFENSORES_EXTRA = 10;
const static size_t COINCIDEN = 0;
const static int CONTADOR_INICIAL = 0;
const static size_t LARGO_ETIQ_LISTAR = 7;
const static size_t LARGO_ETIQ_CONFIG = 7;
const static size_t LARGO_ETIQ_GRAB = 10;
const static size_t LARGO_ETIQ_VEL = 10;
const static int CONTADOR_INICIAL_2 = 1;
const static int COMANDO_JUGAR = 0;
const static int COMANDO_RANKING = 1;
const static int COMANDO_CREAR_CAMINO = 2;
const static int COMANDO_CREAR_CONFIG = 3;
const static int COMANDO_REPETICION = 4;
const static int COMANDO_ERRONEO = -1;
const static int NO_EXISTE = -1;
const static float F_NO_EXISTE = -1;
const static int LEIDOS_RANK = 2;
const static int POS_MIN = 2;
const static int CONFIG_DEFECTO = -1;
const static int PORCENTAJE_MAX = 100;
const static float VELOCIDAD_MIN = 0.25;
const static int EXISTE_AMBOS = 0;
const static int EXISTE_CONFIG = 1;
const static int EXISTE_GRAB = 2;
const static int NO_EXISTEN = 3;
const static int LEIDOS_CAMINOS = 2;
const static int ENANOS_INICIO_LVL1 = 5;
const static int ENANOS_INICIO_LVL3 = 3;
const static int ENANOS_INICIO_LVL4 = 4;
const static int ELFOS_INICIO_LVL2 = 5;
const static int ELFOS_INICIO_LVL3 = 3;
const static int ELFOS_INICIO_LVL4 = 4;
const static  char PASTO = '-';
const static  char CAMINO = 'c';
const static  char FIN_STRING = '\0';
const static char IGUAL = '=';
const static char ARRIBA = 'W';
const static char ABAJO = 'S';
const static char DERECHA = 'D';
const static char IZQUIERDA = 'A';
const static char FINISH = 'F';
const static char LETRA_X = 'X';
const static char PUNTO = '.';

/*
POST: retorna true si el comando ingresado coincide con la orden "JUGAR", caso
	contrario, retorna false.
*/
bool es_comando_jugar(char comando_jugador[MAX_LETRAS]){
	if(strcmp(comando_jugador, JUGAR) == COINCIDEN){
		return true;
	}else return false;
}
/*
POST: retorna true si el comando ingresado coincide con la orden "RANKING", caso
	contrario, retorna false.
*/
bool es_comando_ranking(char comando_jugador[MAX_LETRAS]){
	if(strcmp(comando_jugador, RANKING) == COINCIDEN){
		return true;
	}else return false;
} 
/*
POST: retorna true si el comando ingresado coincide con la orden "CREAR_CAMINO", 
caso contrario, retorna false.
*/
bool es_comando_crear_camino(char comando_jugador[MAX_LETRAS]){
	if(strcmp(comando_jugador, CREAR_CAMINO) == COINCIDEN){
		return true;
	}else return false;
}
/*
POST: retorna true si el comando ingresado coincide con la orden 
	"CREAR_CONFIGURACION", caso contrario, retorna false.
*/
bool es_comando_crear_config(char comando_jugador[MAX_LETRAS]){
	if(strcmp(comando_jugador, CONFIGURACION) == COINCIDEN){
		return true;
	}else return false;
}
/*
POST: retorna true si el comando ingresado coincide con la orden "PONEME_LA_REPE", 
	caso contrario, retorna false.
*/
bool es_comando_repeticion(char comando_jugador[MAX_LETRAS]){
	if(strcmp(comando_jugador, REPETICION) == COINCIDEN){
		return true;
	}else return false;
}
/*
POST: retorna true si el comando ingresado coincide con la etiqueta "LISTAR=", caso
	contrario, retorna false.
*/
bool es_etiqueta_listar(char comandos_jugador[MAX_CANT_COMANDOS][MAX_LETRAS], int argc, int *posicion){
	int i = CONTADOR_INICIAL;
	bool encontro = false;
	while((i < argc) && (!encontro)){
		if(strncmp(comandos_jugador[i], ETIQUETA_LISTAR, LARGO_ETIQ_LISTAR) == COINCIDEN){
			encontro = true;
			*posicion = i;
		}
		i++;
	}
	return encontro;
}
/*
POST: retorna true si el comando ingresado coincide con la etiqueta "CONFIG=", caso
	contrario, retorna false.
*/
bool es_etiqueta_config(char comandos_jugador[MAX_CANT_COMANDOS][MAX_LETRAS], int argc, int *posicion){
	int i = CONTADOR_INICIAL;
	bool encontro = false;
	while((i < argc) && (!encontro)){
		if(strncmp(comandos_jugador[i], ETIQUETA_CONFIG, LARGO_ETIQ_CONFIG) == COINCIDEN){
			encontro = true;
			*posicion = i;
		}
		i++;
	}
	return encontro;
}
/*
PRE: se tienen que haber ingresado comandos.
POST: retornara el numero asociado al comando ingresado. 
*/
int leer_comandos(int argc, char* argv[], char comandos_jugador[MAX_CANT_COMANDOS][MAX_LETRAS]){
	for (int i = CONTADOR_INICIAL_2; i < argc; ++i){
		strcpy(comandos_jugador[i - 1], argv[i]);
	}
	if(es_comando_jugar(comandos_jugador[0])){
		return COMANDO_JUGAR;
	}else if(es_comando_ranking(comandos_jugador[0])){
		return COMANDO_RANKING;
	}else if(es_comando_crear_camino(comandos_jugador[0])){
		return COMANDO_CREAR_CAMINO;
	}else if(es_comando_crear_config(comandos_jugador[0])){
		return COMANDO_CREAR_CONFIG;
	}else if(es_comando_repeticion(comandos_jugador[0])){
		return COMANDO_REPETICION;
	}else return COMANDO_ERRONEO;
}
/*
PRE: se tuvo que ingresar la etiqueta LISTAR=.
POST: retorna la cantidad a mostrar del ranking.
*/
int obtener_cant_lista(char comandos_jugador[MAX_LETRAS]){
	char cant_lista[MAX_LETRAS];
	size_t tope = strlen(comandos_jugador);
	int resultado;
	for (size_t i = LARGO_ETIQ_LISTAR; i < tope; ++i){
		cant_lista[i - LARGO_ETIQ_LISTAR] = comandos_jugador[i];	
	}
	resultado = atoi(cant_lista);
	return resultado;
}
/*
POST: elimina la primera letra del string.
*/
void eliminar_ordenadamente(char vector[MAX_LETRAS], size_t* tope){
	for (int i = CONTADOR_INICIAL; i < *tope - 1; ++i){
		vector[i] = vector[i + 1];
	}
	(*tope)--;
	vector[*tope] = FIN_STRING;
}
/*
PRE: se tuvo que ingresar el comando RANKING y el archivo de configuracion 
	asociado al ranking.
POST: crea el nombre del ranking a mostrar. 
*/
void crear_nombre_ranking(char comandos_jugador[MAX_LETRAS], char archivos[MAX_LETRAS]){
	char nombre_archivo[MAX_LETRAS];
	strcpy(nombre_archivo, CABECERA_RANK);
	size_t tope = strlen(comandos_jugador);
	while(comandos_jugador[0] != IGUAL){
		eliminar_ordenadamente(comandos_jugador, &tope);
	}
	eliminar_ordenadamente(comandos_jugador, &tope);
	strncat(nombre_archivo, comandos_jugador, tope - 4);
	strcat(nombre_archivo, EXTENCION_CSV);
	strcpy(archivos, nombre_archivo);	

}
/*
PRE: se tuvo que ingresar el comando RANKING y el archivo de configuracion 
	asociado al ranking.
POST: imprime por pantalla el ranking para la configuracion ingresada.
*/
void mostrar_ranking(int cant_lista, bool hay_archivo, char archivos[MAX_LETRAS]){
	int leidos;
	int puntos;
	char jugador[MAX_LETRAS];
	int contador = cant_lista;
	if(hay_archivo){
		FILE* ranking = fopen(archivos, LECTURA);
		if(!ranking){
			printf("ERROR, el archivo ingresado por el usuario no existe!!\n");
			return;
		}
		if(cant_lista != NO_EXISTE){
			leidos = fscanf(ranking, LECTURA_RANKING, jugador, &puntos);
			while((leidos == LEIDOS_RANK) && (contador != CONTADOR_INICIAL)){
				printf("jugador: %s , puntaje: %i \n", jugador, puntos);
				leidos = fscanf(ranking, LECTURA_RANKING, jugador, &puntos);
				contador--;
			}
		} else{
			leidos = fscanf(ranking, LECTURA_RANKING, jugador, &puntos);
			while(leidos == LEIDOS_RANK){
				printf("jugador: %s , puntaje: %i \n", jugador, puntos);
				leidos = fscanf(ranking, LECTURA_RANKING, jugador, &puntos);
			}
		}
		fclose(ranking);
	}else{
		FILE * ranking_defecto = fopen(NOMBRE_RANK_DEFECTO, LECTURA);
		if(!ranking_defecto){
			printf("ERROR, el archivo ranking_defecto no existe!!\n");
			return;
		}
		if(cant_lista != NO_EXISTE){
			leidos = fscanf(ranking_defecto, LECTURA_RANKING, jugador, &puntos);
			while((leidos == LEIDOS_RANK) && (contador != CONTADOR_INICIAL)){
				printf("jugador: %s , puntaje: %i \n", jugador, puntos);
				leidos = fscanf(ranking_defecto, LECTURA_RANKING, jugador, &puntos);
				contador--;
			}
		}else{
			leidos = fscanf(ranking_defecto, LECTURA_RANKING, jugador, &puntos);
			while(leidos == LEIDOS_RANK){
				printf("jugador: %s , puntaje: %i \n", jugador, puntos);
				leidos = fscanf(ranking_defecto, LECTURA_RANKING, jugador, &puntos);
			}
		}
		fclose(ranking_defecto);
	}
}
/*
PRE: PRE: se tuvo que ingresar el comando RANKING y el archivo de configuracion 
	asociado al ranking.
POST: imprime por pantalla el ranking para la configuracion ingresada.
*/
void comandos_ranking(char comandos_jugador[MAX_CANT_COMANDOS][MAX_LETRAS], int argc, char archivos[MAX_CANT_ARCHIVOS][MAX_LETRAS]){
	int posicion_listar = NO_EXISTE;
	int posicion_config = NO_EXISTE;
	int cant_lista = NO_EXISTE;
	bool hay_archivo = false;
	if((es_etiqueta_listar(comandos_jugador, argc, &posicion_listar)) && (es_etiqueta_config(comandos_jugador, argc, &posicion_config))){
		cant_lista = obtener_cant_lista(comandos_jugador[posicion_listar]);
		crear_nombre_ranking(comandos_jugador[posicion_config], archivos[0]);
		hay_archivo = true;
	}else if(es_etiqueta_listar(comandos_jugador, argc, &posicion_listar)){
		cant_lista = obtener_cant_lista(comandos_jugador[posicion_listar]);
	}else if(es_etiqueta_config(comandos_jugador, argc, &posicion_config)){
		crear_nombre_ranking(comandos_jugador[posicion_config], archivos[0]);
		hay_archivo = true;
	}
	mostrar_ranking(cant_lista, hay_archivo, archivos[0]);
}

/*
PRE: el vector camino_1 y/o camino_2 debe estar rellenado con coordenadas logicas.
POST: inserta en el tablero el/los caminos.
*/

void poner_camino_en_mapa(char tablero[MAX_FILAS][MAX_COLUMNAS], int tope_camino1, coordenada_t camino_1[MAX_LONGITUD_CAMINO], int tope_camino2, coordenada_t camino_2[MAX_LONGITUD_CAMINO]){
	for (int i = 0; i < tope_camino1; ++i){
		tablero[camino_1[i].fil][camino_1[i].col] = CAMINO;
	}
	for (int i = 0; i < tope_camino2; ++i){
		tablero[camino_2[i].fil][camino_2[i].col] = CAMINO; 
	}	
}
/*
POST: rellena el tablero en su totalidad de pasto
*/
void llenar_tablero(char tablero[MAX_FILAS][MAX_COLUMNAS], int nivel_actual){
	if (nivel_actual == PRIMER_NIVEL || nivel_actual == SEGUNDO_NIVEL){
		for (int i = 0; i < MAX_TABLERO_CHICO; ++i){
			for (int j = 0; j < MAX_TABLERO_CHICO; ++j){
				tablero[i][j] = PASTO;								
			}
		}
	}
	if(nivel_actual == TERCER_NIVEL || nivel_actual == CUARTO_NIVEL){
		for (int i = 0; i < MAX_TABLERO_GRANDE; ++i){
			for (int j = 0; j < MAX_TABLERO_GRANDE; ++j){
				tablero[i][j] = PASTO;									
			}
		}
	}
}
/*
POST: imprime por pantalla el tablero del juego.
*/
void mostrar_camino(int nivel_actual, char tablero[MAX_FILAS][MAX_COLUMNAS]){

	if(nivel_actual == PRIMER_NIVEL || nivel_actual == SEGUNDO_NIVEL){	
		for (int i = 0; i < DISTORCION_TABLERO; ++i){
			printf("%i   ", i);
		}
		for (int i = DISTORCION_TABLERO; i < MAX_TABLERO_CHICO; ++i){
			printf("%i  ", i);
		}
		printf("\n");
		for (int i = 0; i < MAX_TABLERO_CHICO; ++i){
			for (int j = 0; j < MAX_TABLERO_CHICO; ++j){
				if(tablero[i][j] == PASTO){
					printf(VERDE_CLARO"%c   "FIN, tablero[i][j]);
				}else if(tablero[i][j] == CAMINO){
					printf(AMARILLO"%c   "FIN, tablero[i][j]);
				}
			}
			printf("%i\n", i);
		}
	}
	if (nivel_actual == TERCER_NIVEL || nivel_actual == CUARTO_NIVEL){
		for (int i = 0; i < DISTORCION_TABLERO; ++i){
			printf("%i   ", i);
		}
		for (int i = DISTORCION_TABLERO; i < MAX_TABLERO_GRANDE; ++i){
			printf("%i  ", i);
		}
		printf("\n");
		for (int i = 0; i < MAX_TABLERO_GRANDE; ++i){
			for (int j = 0; j < MAX_TABLERO_GRANDE; ++j){
				if(tablero[i][j] == PASTO){
					printf(VERDE_CLARO"%c   "FIN, tablero[i][j]);
				}else if(tablero[i][j] == CAMINO){
					printf(AMARILLO"%c   "FIN, tablero[i][j]);
				}
			}
			printf("%i\n", i);
		}
	}
}
/*
POST: imprime por pantalla las teclas que sirven para mover los caminos.
*/
void presentar_teclas(){
	printf("\t\t\t\t\t'W'\n");
	printf("\t\t\t\t\t ^\n");
	printf("\t\t\t\t\t |\n");
	printf("\t\t\t\t\tir hacia arriba\n");
	printf("'A' < ----- ir hacia la izquierda");
	printf("\t\t\tir hacia la derecha------> 'D'\n");
	printf("\t\t\t\t\tir hacia abajo\n");
	printf("\t\t\t\t\t |\n");
	printf("\t\t\t\t\t v\n");
	printf("\t\t\t\t\t'S'\n");
	printf("\n\n");
	printf("'F' para finalizar el camino\n");
	printf("el mensaje desaparecera el 5 segundos...\n");
	detener_el_tiempo(5);
	system("clear");
}

/*
POST: retorna true si las coordenadas estan dentro del rango valido, caso
	contrario, retorn false.
*/
bool posicion_valida( coordenada_t camino[MAX_LONGITUD_CAMINO], int posicion, int nivel_actual){
	if(nivel_actual == PRIMER_NIVEL || nivel_actual == SEGUNDO_NIVEL){
		if((camino[posicion].fil >= MIN_TABLERO) && (camino[posicion].fil < MAX_TABLERO_CHICO) && (camino[posicion].col >= MIN_TABLERO) && (camino[posicion].col < MAX_TABLERO_CHICO)){
			return true;
		}else return false;
	}else{
		if((camino[posicion].fil >= MIN_TABLERO) && (camino[posicion].fil < MAX_TABLERO_GRANDE) && (camino[posicion].col >= MIN_TABLERO) && (camino[posicion].col < MAX_TABLERO_GRANDE)){
			return true;
		}else return false;
	}
}
/*
POST: retorna true si alguna de las coordenadas es igual al limite del tablero,
	caso contrario, retorna false.
*/
bool llego_limite(coordenada_t camino[MAX_LONGITUD_CAMINO], int posicion, int nivel_actual){
	if(nivel_actual == PRIMER_NIVEL || nivel_actual == SEGUNDO_NIVEL){
		if(camino[posicion].fil == MAX_TABLERO_CHICO || camino[posicion].col == MAX_TABLERO_CHICO || camino[posicion].fil == MIN_TABLERO - 1 || camino[posicion].col == MIN_TABLERO - 1){
			return true;
		}else return false;
	}else{
		if(camino[posicion].fil == MAX_TABLERO_GRANDE || camino[posicion].col == MAX_TABLERO_GRANDE || camino[posicion].fil == MIN_TABLERO - 1 || camino[posicion].col == MIN_TABLERO - 1){
			return true;
		}else return false;
	}
}
/*
POST: retorna true si las coordenadas actuales son iguales a las coordenadas del
	paso antepenultimo, caso contrario, retorna false.
*/
bool retrocedio(coordenada_t camino[MAX_LONGITUD_CAMINO], int posicion){
	if(posicion < POS_MIN){
		return false;
	}else{
		int fila_antepenultima = camino[posicion - 2].fil;
		int col_antepenultima = camino[posicion - 2].col;
		int fila_actual = camino[posicion].fil;
		int col_actual = camino[posicion].col;
		if(fila_antepenultima == fila_actual && col_antepenultima == col_actual){
			return true;
		}else return false;
	}
}
/*
POST: verifica que la posicion ingresada sea valida y este dentro del limite aceptado.
*/
void verificar_inicio(coordenada_t camino[MAX_LONGITUD_CAMINO], int posicion, int nivel_actual){
	while(!posicion_valida(camino, posicion, nivel_actual)){
		printf("ERROR!!!\n");
		printf("fila o columna invalida\n");
		printf("ingresar fila del comienzo del camino :\n");
		scanf(" %i", &camino[posicion].fil);
		printf("ingresar columna del comienzo del camino 1:\n");
		scanf(" %i", &camino[posicion].col);
	}
}
/*
POST: retorna true si la letra ingresada coincide con alguna de las letras 
	validas, caso contrario, retorna false.
*/
void verificar_letra(char* letra){
	if(*letra == IZQUIERDA || *letra == ABAJO || *letra == DERECHA || *letra == ARRIBA || *letra == FINISH){
		return;
	}else{
		while(*letra != IZQUIERDA && *letra != ABAJO && *letra && DERECHA && *letra != ARRIBA && *letra && FINISH){
			printf("ERROR!!!\n");
			printf("letra no valida\n");
			printf("por favor, ingrese movimiento del camino:\n");
			scanf(" %c", &(*letra));			
		}	
	}
}
/*
PRE: las letras tienen que ser validas.
POST: implementara las coordenadas predeterminadas de acuerdo a la letra recibida.
*/
void mover_camino(coordenada_t camino[MAX_LONGITUD_CAMINO], int posicion, int nivel_actual, char letra){
	int fila_anterior = camino[posicion - 1]. fil;
	int col_anterior = camino[posicion - 1]. col;
	switch(letra){
		case 'W':
			camino[posicion].fil = fila_anterior - 1;
			camino[posicion].col = col_anterior;
		break;
		case 'A':
			camino[posicion].fil = fila_anterior;
			camino[posicion].col = col_anterior - 1;
		break;
		case 'S':
			camino[posicion].fil = fila_anterior + 1;
			camino[posicion].col = col_anterior;
		break;
		case 'D':
			camino[posicion].fil = fila_anterior;
			camino[posicion].col = col_anterior + 1;
		break;
		case 'F':
			return;
		break;
	}
}
/*
PRE: se tiene que haber ingresado el comando CREAR_CAMINO.
POST: se ingresa todo el camino del nivel 1.
*/
void ingresar_camino_lvl_1(int nivel_actual, int* tope_camino1, coordenada_t camino_1[MAX_LONGITUD_CAMINO], int tope_camino2, coordenada_t camino_2[MAX_LONGITUD_CAMINO], char archivo[MAX_LETRAS]){
	char tablero[MAX_FILAS][MAX_COLUMNAS];
	char letra;
	printf("============================================\n");
	printf("\t\tNIVEL 1:\n");
	printf("============================================\n");
	llenar_tablero(tablero, nivel_actual);
	poner_camino_en_mapa(tablero, *tope_camino1, camino_1, tope_camino2, camino_2);
	mostrar_camino(nivel_actual, tablero);
	while((*tope_camino1 < MAX_LONGITUD_CAMINO) && (letra != 'F')){
		if(*tope_camino1 == CONTADOR_INICIAL){
			printf("ingresar fila del comienzo del camino 1:\n");
			scanf(" %i", &camino_1[*tope_camino1].fil);
			printf("ingresar columna del comienzo del camino 1:\n");
			scanf(" %i", &camino_1[*tope_camino1].col);
			verificar_inicio(camino_1, *tope_camino1, nivel_actual);
		}else{
			printf("ingrese letra para mover el camino:\n");
			scanf(" %c", &letra);
			verificar_letra(&letra);
			mover_camino(camino_1, *tope_camino1, nivel_actual, letra);
			while(llego_limite(camino_1, *tope_camino1, nivel_actual) || retrocedio(camino_1, *tope_camino1)){
				printf("ERROR\n");
				printf("posicion no valida...\n");
				printf("ingrese letra para realizar movimiento:\n");
				scanf(" %c", &letra);
				verificar_letra(&letra);
				mover_camino(camino_1, *tope_camino1, nivel_actual, letra);
			}
		}
		if(letra != FINISH){
			(*tope_camino1)++;
		}
		system("clear");
		llenar_tablero(tablero, nivel_actual);
		poner_camino_en_mapa(tablero, *tope_camino1, camino_1, tope_camino2, camino_2);
		mostrar_camino(nivel_actual, tablero);
	}
}
/*
PRE: se tiene que haber ingresado correctamente el camino del nivel 1.
POST: se ingresa todo el camino del nivel 2.
*/
void ingresar_camino_lvl_2(int nivel_actual, int* tope_camino2, coordenada_t camino_2[MAX_LONGITUD_CAMINO], int tope_camino1, coordenada_t camino_1[MAX_LONGITUD_CAMINO], char archivo[MAX_LETRAS]){
	char tablero[MAX_FILAS][MAX_COLUMNAS];
	char letra = LETRA_X;
	printf("============================================\n");
	printf("\t\tNIVEL 2:\n");
	printf("============================================\n");
	llenar_tablero(tablero, nivel_actual);
	poner_camino_en_mapa(tablero, *tope_camino2, camino_2, tope_camino1, camino_1);
	mostrar_camino(nivel_actual, tablero);
	while((*tope_camino2 < MAX_LONGITUD_CAMINO) && (letra != 'F')){
		if(*tope_camino2 == CONTADOR_INICIAL){
			printf("ingresar fila del comienzo del camino 2:\n");
			scanf(" %i", &camino_2[*tope_camino2].fil);
			printf("ingresar columna del comienzo del camino 2:\n");
			scanf(" %i", &camino_2[*tope_camino2].col);
			verificar_inicio(camino_2, *tope_camino2, nivel_actual);
		}else{
			printf("ingrese letra para mover el camino:\n");
			scanf(" %c", &letra);
			verificar_letra(&letra);
			mover_camino(camino_2, *tope_camino2, nivel_actual, letra);
			while(llego_limite(camino_2, *tope_camino2, nivel_actual) || retrocedio(camino_2, *tope_camino2)){
				printf("ERROR\n");
				printf("posicion no valida...\n");
				printf("ingrese letra para realizar movimiento:\n");
				scanf(" %c", &letra);
				verificar_letra(&letra);
				mover_camino(camino_2, *tope_camino2, nivel_actual, letra);
			}
		}
		if(letra != FINISH){
			(*tope_camino2)++;
		}
		system("clear");
		llenar_tablero(tablero, nivel_actual);
		poner_camino_en_mapa(tablero, tope_camino1, camino_1, *tope_camino2, camino_2);
		mostrar_camino(nivel_actual, tablero);
	}
}
/*
PRE: se tiene que haber ingresado correctamente el caminoo del nivel 2.
POST: se ingresan todos los caminos del nivel 3 y 4.
*/
void ingresar_caminos(int nivel_actual, int* tope_camino1, coordenada_t camino_1[MAX_LONGITUD_CAMINO], int* tope_camino2, coordenada_t camino_2[MAX_LONGITUD_CAMINO], char archivo[MAX_LETRAS]){
	char tablero[MAX_FILAS][MAX_COLUMNAS];
	char letra = LETRA_X;
	if(nivel_actual == TERCER_NIVEL){
		printf("============================================\n");
	printf("\t\tNIVEL 3:\n");
	printf("============================================\n");
	}else{
		printf("============================================\n");
	printf("\t\tNIVEL 4:\n");
	printf("============================================\n");
	}
	llenar_tablero(tablero, nivel_actual);
	poner_camino_en_mapa(tablero, *tope_camino2, camino_2, *tope_camino1, camino_1);
	mostrar_camino(nivel_actual, tablero);
	while((*tope_camino1 < MAX_LONGITUD_CAMINO) && (letra != 'F')){
		if(*tope_camino1 == CONTADOR_INICIAL){
			printf("ingresar fila del comienzo del camino 1:\n");
			scanf(" %i", &camino_1[*tope_camino1].fil);
			printf("ingresar columna del comienzo del camino 1:\n");
			scanf(" %i", &camino_1[*tope_camino1].col);
			verificar_inicio(camino_1, *tope_camino1, nivel_actual);
		}else{
			printf("ingrese letra para mover el camino:\n");
			scanf(" %c", &letra);
			verificar_letra(&letra);
			mover_camino(camino_1, *tope_camino1, nivel_actual, letra);
			while(llego_limite(camino_1, *tope_camino1, nivel_actual) || retrocedio(camino_1, *tope_camino1)){
				printf("ERROR\n");
				printf("posicion no valida...\n");
				printf("ingrese letra para realizar movimiento:\n");
				scanf(" %c", &letra);
				verificar_letra(&letra);
				mover_camino(camino_1, *tope_camino1, nivel_actual, letra);
			}
		}
		if(letra != FINISH){
			(*tope_camino1)++;			
		}	
		system("clear");
		llenar_tablero(tablero, nivel_actual);
		poner_camino_en_mapa(tablero, *tope_camino1, camino_1, *tope_camino2, camino_2);
		mostrar_camino(nivel_actual, tablero);
	}
	system("clear");
	letra = LETRA_X;
	llenar_tablero(tablero, nivel_actual);
	poner_camino_en_mapa(tablero, *tope_camino2, camino_2, *tope_camino1, camino_1);
	mostrar_camino(nivel_actual, tablero);
	while((*tope_camino2 < MAX_LONGITUD_CAMINO) && (letra != 'F')){
		if(*tope_camino2 == CONTADOR_INICIAL){
			printf("ingresar fila del comienzo del camino 2:\n");
			scanf(" %i", &camino_2[*tope_camino2].fil);
			printf("ingresar columna del comienzo del camino 2:\n");
			scanf(" %i", &camino_2[*tope_camino2].col);
			verificar_inicio(camino_2, *tope_camino2, nivel_actual);
		}else{
			printf("ingrese letra para mover el camino:\n");
			scanf(" %c", &letra);
			verificar_letra(&letra);
			mover_camino(camino_2, *tope_camino2, nivel_actual, letra);
			while(llego_limite(camino_2, *tope_camino2, nivel_actual) || retrocedio(camino_2, *tope_camino2)){
				printf("ERROR\n");
				printf("posicion no valida...\n");
				printf("ingrese letra para realizar movimiento:\n");
				scanf(" %c", &letra);
				verificar_letra(&letra);
				mover_camino(camino_2, *tope_camino2, nivel_actual, letra);
			}
		}
		if(letra != FINISH){
			(*tope_camino2)++;
		}
		system("clear");
		llenar_tablero(tablero, nivel_actual);
		poner_camino_en_mapa(tablero, *tope_camino1, camino_1, *tope_camino2, camino_2);
		mostrar_camino(nivel_actual, tablero);
	}
}
/*
PRE: se tiene que haber ingresado todos los caminos de todos los niveles
	correctamente.
POST: guarda en un archivo de texto, todos los caminos ingresados.
*/
void guardar_caminos(caminos_t caminos, char archivo[MAX_LETRAS]){

	FILE * archivo_camino = fopen(archivo, ESCRITURA);
	if(!archivo_camino){
		printf("no se pudo abrir el archivo\n");
		return;
	}
	fprintf(archivo_camino, "NIVEL= 1\n");
	fprintf(archivo_camino, "CAMINO= 1\n");
	for (int i = 0; i < caminos.tope_camino_1_lvl_1; ++i){
		fprintf(archivo_camino, ESCRITURA_CAMINOS, caminos.camino_1_lvl_1[i].fil, caminos.camino_1_lvl_1[i].col);
	}
	fprintf(archivo_camino, "NIVEL= 2\n");
	fprintf(archivo_camino, "CAMINO= 2\n");
	for (int i = 0; i < caminos.tope_camino_2_lvl_2; ++i){
		fprintf(archivo_camino, ESCRITURA_CAMINOS, caminos.camino_2_lvl_2[i].fil, caminos.camino_2_lvl_2[i].col);
	}
	fprintf(archivo_camino, "NIVEL= 3\n");
	fprintf(archivo_camino, "CAMINO= 1\n");
	for (int i = 0; i < caminos.tope_camino_1_lvl_3; ++i){
		fprintf(archivo_camino, ESCRITURA_CAMINOS, caminos.camino_1_lvl_3[i].fil, caminos.camino_1_lvl_3[i].col);
	}
	fprintf(archivo_camino, "CAMINO= 2\n");
	for (int i = 0; i < caminos.tope_camino_2_lvl_3; ++i){
		fprintf(archivo_camino, ESCRITURA_CAMINOS, caminos.camino_2_lvl_3[i].fil, caminos.camino_2_lvl_3[i].col);
	}
	fprintf(archivo_camino, "NIVEL= 4\n");
	fprintf(archivo_camino, "CAMINO= 1\n");
	for (int i = 0; i < caminos.tope_camino_1_lvl_4; ++i){
		fprintf(archivo_camino, ESCRITURA_CAMINOS, caminos.camino_1_lvl_4[i].fil, caminos.camino_1_lvl_4[i].col);
	}
	fprintf(archivo_camino, "CAMINO= 2\n");
	for (int i = 0; i < caminos.tope_camino_2_lvl_4; ++i){
		fprintf(archivo_camino, ESCRITURA_CAMINOS, caminos.camino_2_lvl_4[i].fil, caminos.camino_2_lvl_4[i].col);
	}
	fclose(archivo_camino);
}
/*
PRE: se tiene que haber ingresado el comando CREAR_CAMINO.
POST: guarda en un archivo de texto, todos los caminos ingresados.
*/
void comando_crear_caminos(char comandos_jugador[MAX_CANT_COMANDOS][MAX_LETRAS], char archivos[MAX_CANT_ARCHIVOS][MAX_LETRAS]){
	int nivel_actual = PRIMER_NIVEL;
	caminos_t caminos;
	caminos.tope_camino_1_lvl_1 = CONTADOR_INICIAL;
	caminos.tope_camino_2_lvl_2 = CONTADOR_INICIAL;
	caminos.tope_camino_1_lvl_3 = CONTADOR_INICIAL;
	caminos.tope_camino_2_lvl_3 = CONTADOR_INICIAL;
	caminos.tope_camino_1_lvl_4 = CONTADOR_INICIAL;
	caminos.tope_camino_2_lvl_4 = CONTADOR_INICIAL;
	strcpy(archivos[0], comandos_jugador[1]);
	presentar_teclas();
	ingresar_camino_lvl_1(nivel_actual, &(caminos.tope_camino_1_lvl_1), caminos.camino_1_lvl_1, CONTADOR_INICIAL, caminos.camino_2_lvl_2, archivos[0]);
	system("clear");
	nivel_actual = SEGUNDO_NIVEL;
	ingresar_camino_lvl_2(nivel_actual, &(caminos.tope_camino_2_lvl_2), caminos.camino_2_lvl_2, CONTADOR_INICIAL, caminos.camino_1_lvl_1, archivos[0]);
	system("clear");
	nivel_actual = TERCER_NIVEL;
	ingresar_caminos(nivel_actual, &(caminos.tope_camino_1_lvl_3), caminos.camino_1_lvl_3, &(caminos.tope_camino_2_lvl_3), caminos.camino_2_lvl_3, archivos[0]);
	system("clear");
	nivel_actual = CUARTO_NIVEL;
	ingresar_caminos(nivel_actual, &(caminos.tope_camino_1_lvl_4), caminos.camino_1_lvl_4, &(caminos.tope_camino_2_lvl_4), caminos.camino_2_lvl_4, archivos[0]);
	guardar_caminos(caminos, archivos[0]);
}
/*
POST: retorna true si la vida es mayor o igual al minino valido, caso contrario
	devuelve false.
*/
bool vida_valida (int vida_torre_1){
	if(vida_torre_1 >= CONFIG_DEFECTO){
		return true;
	}else return false;
}
/*
POST: pide la vida de las torres del juego.
*/
void pedir_vida_torres(vida_torres_t* torres){
	printf("ingresar vida de torre 1:\n");
	scanf(" %i", &(torres->torre_uno));
	while(!vida_valida(torres->torre_uno)){
		printf("ERROR!!\n");
		printf("vida no valida...\n");
		printf("ingresar vida de torre 1:\n");
		scanf(" %i", &(torres->torre_uno));
	}
	printf("ingresar vida de torre 2:\n");
	scanf(" %i", &(torres->torre_dos));
	while(!vida_valida(torres->torre_dos)){
		printf("ERROR!!\n");
		printf("vida no valida...\n");
		printf("ingresar vida de torre 1:\n");
		scanf(" %i", &(torres->torre_dos));
	}	
}
/*
POST: retorna true si el valor ingresado es mayor o igual al minino valido, caso 
contrario devuelve false.
*/
bool cant_valida(int cant_ingresada){
	if(cant_ingresada >= CONFIG_DEFECTO){
		return true;
	}else return false;
}
/*
POST: pide la cantidad de enanos inciales por nivel.
*/
void pedir_enanos(int enanos[MAX_NIVELES]){
	for (int i = 0; i < MAX_NIVELES; ++i){
		printf("ingresar cantidad de enanos en el nivel %i:\n", i + 1);
		scanf(" %i", &(enanos[i]));
		while(!cant_valida(enanos[i])){
			printf("ERROR!!\n");
			printf("cantidad no valida...\n");
			printf("ingresar cantidad de enanos en el nivel %i:\n", i + 1);
			scanf(" %i", &(enanos[i]));
		}	
	}
}
/*
POST: pide la cantidad de elfos inciales por nivel.
*/
void pedir_elfos(int elfos[MAX_NIVELES]){
	for (int i = 0; i < MAX_NIVELES; ++i){
		printf("ingresar cantidad de elfos en el nivel %i:\n", i + 1);
		scanf(" %i", &(elfos[i]));
		while(!cant_valida(elfos[i])){
			printf("ERROR!!\n");
			printf("cantidad no valida...\n");
			printf("ingresar cantidad de elfos en el nivel %i:\n", i + 1);
			scanf(" %i", &(elfos[i]));
		}	
	}
}
/*
POST: pide la cantidad de enanos y elfos inciiales por nivel.
*/
void pedir_defensores(int enanos[MAX_NIVELES], int elfos[MAX_NIVELES]){
	pedir_enanos(enanos);
	system("clear");
	pedir_elfos(elfos);
}
/*
POST: pide la cantidad de enanos y elfos extras.
*/
void pedir_defensores_extra(defensor_extra_t* enanos, defensor_extra_t* elfos){
	printf("ingresar la cantidad de enanos extras que desea tener:\n");
	scanf(" %i", &(enanos->cant_extra));
	while(!cant_valida(enanos->cant_extra)){
		printf("ERROR!!\n");
		printf("cantidad no valida...\n");
		printf("ingresar la cantidad de enanos extras que desea tener:\n");
		scanf(" %i", &(enanos->cant_extra));
	}
	printf("ingresar costo de enanos extras a la torre 1:\n");
	scanf(" %i", &(enanos->costo_torre_1));
	while(!cant_valida(enanos->costo_torre_1)){
		printf("ERROR!!\n");
		printf("cantidad no valida...\n");
		printf("ingresar costo de enanos extras a la torre 1:\n");
		scanf(" %i", &(enanos->costo_torre_1));
	}
	printf("ingresar costo de enanos extras a la torre 2:\n");
	scanf(" %i", &(enanos->costo_torre_2));
	while(!cant_valida(enanos->costo_torre_2)){
		printf("ERROR!!\n");
		printf("cantidad no valida...\n");
		printf("ingresar costo de enanos extras a la torre 1:\n");
		scanf(" %i", &(enanos->costo_torre_2));
	}
	system("clear");

	printf("ingresar la cantidad de elfos extras que desea tener:\n");
	scanf(" %i", &(elfos->cant_extra));
	while(!cant_valida(elfos->cant_extra)){
		printf("ERROR!!\n");
		printf("cantidad no valida...\n");
		printf("ingresar la cantidad de elfos extras que desea tener:\n");
		scanf(" %i", &(elfos->cant_extra));
	}
	printf("ingresar costo de elfos extras a la torre 1:\n");
	scanf(" %i", &(elfos->costo_torre_1));
	while(!cant_valida(elfos->costo_torre_1)){
		printf("ERROR!!\n");
		printf("cantidad no valida...\n");
		printf("ingresar costo de elfos extras a la torre 1:\n");
		scanf(" %i", &(elfos->costo_torre_1));
	}
	printf("ingresar costo de elfos extras a la torre 2:\n");
	scanf(" %i", &(elfos->costo_torre_2));
	while(!cant_valida(elfos->costo_torre_2)){
		printf("ERROR!!\n");
		printf("cantidad no valida...\n");
		printf("ingresar costo de elfos extras a la torre 1:\n");
		scanf(" %i", &(elfos->costo_torre_2));
	}
}
/*
POST: retorna true si el porcentaje recibido es menor o igual al porcentaje 
	maximo, caso contrario retorna false.
*/
bool porcentaje_valido(int porcentaje_recibido){
	if((porcentaje_recibido >= CONFIG_DEFECTO) && (porcentaje_recibido <= PORCENTAJE_MAX)){
		return true;
	}else return false;
}
/*
POST: pide porcentaje de fallo de los enanos y elfos. 
*/
void pedir_fallo(int* fallo_enanos, int* fallo_elfos){
	printf("ingresar porcentaje de fallo de enanos:\n");
	scanf(" %i", &(*fallo_enanos));
	while(!porcentaje_valido(*fallo_enanos)){
		printf("ERROR!!\n");
		printf("porcentaje no valido...\n");
		printf("ingresar porcentaje de fallo de enanos:\n");
		scanf(" %i", &(*fallo_enanos));
	}
	printf("ingresar porcentaje de fallo de elfos:\n");
	scanf(" %i", &(*fallo_elfos));
	while(!porcentaje_valido(*fallo_elfos)){
		printf("ERROR!!\n");
		printf("porcentaje no valido...\n");
		printf("ingresar porcentaje de fallo de elfos:\n");
		scanf(" %i", &(*fallo_elfos));
	}
}
/*
POST: pide porcentaje de critico de los enanos y elfos. 
*/
void pedir_critico(int* critico_enanos, int* critico_elfos){
	printf("ingresar porcentaje de critico de enanos:\n");
	scanf(" %i", &(*critico_enanos));
	while(!porcentaje_valido(*critico_enanos)){
		printf("ERROR!!\n");
		printf("porcentaje no valido...\n");
		printf("ingresar porcentaje de critico de enanos:\n");
		scanf(" %i", &(*critico_enanos));
	}
	printf("ingresar porcentaje de critico de elfos:\n");
	scanf(" %i", &(*critico_elfos));
	while(!porcentaje_valido(*critico_elfos)){
		printf("ERROR!!\n");
		printf("porcentaje no valido...\n");
		printf("ingresar porcentaje de critico de elfos:\n");
		scanf(" %i", &(*critico_elfos));
	}
}
/*
POST: retorna true si la velocidad es mayor o igual a la velocidad minima, 
	caso contrario, retorna false.
*/
bool velocidad_valida(float velocidad_juego){
	if(velocidad_juego >= VELOCIDAD_MIN || velocidad_juego == CONFIG_DEFECTO){
		return true;
	}else return false;
}
/*
POST: pide la velocidad con el que correra el juego.
*/
void pedir_velocidad(float* velocidad_juego){
	printf("ingresar la velocidad del juego(en segundos):\n");
	printf("minimo = 0.25\n");
	scanf(" %f", &(*velocidad_juego));
	while(!velocidad_valida(*velocidad_juego)){
		printf("ERROR!!\n");
		printf("velocidad no valida...\n");
		printf("ingresar la velocidad del juego(en segundos):\n");
		printf("minimo = 0.25\n");
		scanf(" %f", &(*velocidad_juego));
	}
}
/*
PRE: se tuvo que haber ingresado un archivo.
POST: retorna true si el archivo se pudo abrir, significando que existe, 
	caso contrario, retorna false.
*/
bool leer_archivo(char ruta_recibida[MAX_LETRAS]){
	FILE * archivo= fopen(ruta_recibida, LECTURA);
	if(!archivo){
		return false;
	}else{
		fclose(archivo);
		return true;
	}
}
/*
PRE: se tuvo que haber ingresado un archivo.
POST: retorna true si el archivo es de extencion .TXT o si es el camino por 
	defecto, caso contrario, retorna false.
*/
bool ruta_valida(char ruta_recibida[MAX_LETRAS]){
	size_t tope = strlen(ruta_recibida);
	char extencion[MAX_LETRAS];
	strcpy(extencion, ruta_recibida);
	while(extencion[0] != PUNTO && (tope > POS_MIN)){
		eliminar_ordenadamente(extencion, &tope);
	}
	if((strcmp(extencion, EXTENCION_TXT)== COINCIDEN) || (strcmp(extencion, CAMINO_DEFEC) == COINCIDEN)){
		return true;
	}else return false;
}
/*
POST: pide la ruta del archivo caminos.
*/
void pedir_caminos(caminos_t* caminos){
	printf("ingresar ruta del archivo del camino:\n");
	scanf(" %s", caminos->archivo);
	while(!ruta_valida(caminos->archivo)){
		printf("ERROR!!\n");
		printf("ruta no valida...\n");
		printf("ingresar ruta del archivo del camino:\n");
		scanf(" %s", caminos->archivo);
	}
}
/*
PRE: se tuvieron qeu ingresar todos los datos pedidos anteriomente.
POST: guarda los datos ingresados en un archivo de texto.
*/
void guardar_configuracion(configuracion_t configuracion, char archivo[MAX_LETRAS]){
	FILE * config = fopen(archivo, ESCRITURA);
	if(!config){
		printf("no se pudo abrir el archivo %s \n", archivo);
		return;
	}
	fprintf(config, "RESISTENCIA_TORRES= %i,%i\n",configuracion.torres.torre_uno, configuracion.torres.torre_dos);
	fprintf(config, "ENANOS_INICIO= %i,%i,%i,%i\n", configuracion.cant_enanos[0],configuracion.cant_enanos[1], configuracion.cant_enanos[2], configuracion.cant_enanos[3]);
	fprintf(config, "ELFOS_INICIO= %i,%i,%i,%i\n", configuracion.cant_elfos[0],configuracion.cant_elfos[1], configuracion.cant_elfos[2], configuracion.cant_elfos[3]);
	fprintf(config, "ENANOS_EXTRAS= %i,%i,%i\n", configuracion.enanos_extras.cant_extra, configuracion.enanos_extras.costo_torre_1, configuracion.enanos_extras.costo_torre_2);
	fprintf(config, "ELFOS_EXTRAS= %i,%i,%i\n", configuracion.elfos_extras.cant_extra, configuracion.elfos_extras.costo_torre_1, configuracion.elfos_extras.costo_torre_2);
	fprintf(config, "ANIMO_ENANOS= %i,%i\n", configuracion.animo_enanos.fallo, configuracion.animo_enanos.critico);
	fprintf(config, "ANIMO_ELFOS= %i,%i\n", configuracion.animo_elfos.fallo, configuracion.animo_elfos.critico);
	fprintf(config, "VELOCIDAD= %f\n", configuracion.velocidad_juego);
	fprintf(config, "CAMINOS= %s\n", configuracion.caminos.archivo);
	fclose(config);
}
/*
POST: imprime por pantalla la informacion necesaria para que el usuario
	ingrese correctamente sus datos para la configuracion personalizada.
*/
void presentar_configuracion(){
	printf("A continuacion se le haran ciertas preguntas para armar el archivo\n");
	printf("de su configuracion personalizada.\n");
	printf("en caso de querer usar alguna de las configuraciones por defecto del\n");
	printf("juego, por favor, ingrese: '-1'\n");
	printf("(el mensaje desaparecera en 5 segundos)\n");
	detener_el_tiempo(5);
	system("clear");
}

/*
PRE: se tuvo que haber ingresado el comando CREAR_CONFIGURACION.
POST: guarda los datos ingresados en un archivo de texto.
*/
void comandos_configuracion(char comandos_jugador[MAX_CANT_COMANDOS][MAX_LETRAS], char archivos[MAX_CANT_ARCHIVOS][MAX_LETRAS], configuracion_t* configuracion){
	presentar_configuracion();
	pedir_vida_torres(&(configuracion->torres));
	system("clear");
	pedir_defensores(configuracion->cant_enanos, configuracion->cant_elfos);
	system("clear");
	pedir_defensores_extra(&(configuracion->enanos_extras), &(configuracion->elfos_extras));
	system("clear");
	pedir_fallo(&(configuracion->animo_enanos.fallo), &(configuracion->animo_elfos.fallo));
	system("clear");
	pedir_critico(&(configuracion->animo_enanos.critico), &(configuracion->animo_elfos.critico));
	system("clear");
	pedir_velocidad(&(configuracion->velocidad_juego));
	system("clear");
	pedir_caminos(&(configuracion->caminos));
	system("clear");
	strcpy(archivos[0], comandos_jugador[1]);
	guardar_configuracion(*configuracion, archivos[0]);
}
/*
POST: retorna true si el comando ingresado coincide con la etiqueta "GRABACION=", 
	caso contrario, retorna false.
*/
bool es_etiqueta_grabacion(char comandos_jugador[MAX_CANT_COMANDOS][MAX_LETRAS], int argc, int* posicion){
	int i = CONTADOR_INICIAL;
	bool encontro = false;
	while((i < argc) && (!encontro)){
		if(strncmp(comandos_jugador[i], ETIQUETA_GRAB, LARGO_ETIQ_GRAB) == COINCIDEN){
			encontro = true;
			*posicion = i;
		}
		i++;
	}
	return encontro;
}
/*
POST: copia el archivo ingresado a una lista de archivos, eliminando la etiqueta 
	en el proceso.
*/
void copiar_archivo(char comando_jugador[MAX_LETRAS], char archivo[MAX_LETRAS]){
	size_t tope = strlen(comando_jugador);
	while(comando_jugador[0] != IGUAL){
		eliminar_ordenadamente(comando_jugador, &tope);
	}
	eliminar_ordenadamente(comando_jugador, &tope);
	strcpy(archivo, comando_jugador);
}

/*
PRE: se tuvieron que haber ingresado varias lineas de comando.
POST: copia los archivos ingresados a una lista de archivos, eliminando la 
	etiqueta en el proceso.
*/
int comprobar_comandos(char comandos_jugador[MAX_CANT_ARCHIVOS][MAX_LETRAS], int argc, char archivos[MAX_CANT_ARCHIVOS][MAX_LETRAS]){
	int posicion_config = NO_EXISTE;
	int posicion_grabacion = NO_EXISTE;
	if((es_etiqueta_config(comandos_jugador, argc, &posicion_config)) && (es_etiqueta_grabacion(comandos_jugador, argc, &posicion_grabacion))){
		copiar_archivo(comandos_jugador[posicion_config], archivos[0]);
		copiar_archivo(comandos_jugador[posicion_grabacion], archivos[1]);
		return EXISTE_AMBOS;
	}else if(es_etiqueta_config(comandos_jugador, argc, &posicion_config)){
		copiar_archivo(comandos_jugador[posicion_config], archivos[0]);
		return EXISTE_CONFIG;
	}else if(es_etiqueta_grabacion(comandos_jugador, argc, &posicion_grabacion)){
		strcpy(archivos[0], NOMBRE_CONFIG_DEFECTO);
		copiar_archivo(comandos_jugador[posicion_grabacion], archivos[1]);
		return EXISTE_GRAB;
	}else{
		strcpy(archivos[0], NOMBRE_CONFIG_DEFECTO);
		return NO_EXISTEN;
	}
}
/*
PRE: la ruta del camino tiene que estar bien ingresada.
POST: copia el contenido del archivo de caminos al struct de configuracion.
*/
void copiar_caminos(caminos_t* caminos){
	char nivel[MAX_LETRAS];
	char camino[MAX_LETRAS];
	int tope= CONTADOR_INICIAL;
	FILE * archivo_camino = fopen(caminos->archivo, LECTURA);
	if(!archivo_camino){
		printf("no se pudo abrir el archivo %s \n", caminos->archivo);
		return;
	}
	fscanf(archivo_camino, LECTURA_ETIQUETA, nivel);
	fscanf(archivo_camino, LECTURA_ETIQUETA, camino);
	int leidos = fscanf(archivo_camino, LECTURA_CAMINOS, &(caminos->camino_1_lvl_1[tope].fil), &(caminos->camino_1_lvl_1[tope].col));
	while (leidos == LEIDOS_CAMINOS){
		tope++;
		leidos = fscanf(archivo_camino, LECTURA_CAMINOS, &(caminos->camino_1_lvl_1[tope].fil), &(caminos->camino_1_lvl_1[tope].col));
	}
	caminos->tope_camino_1_lvl_1 = tope;
	tope = CONTADOR_INICIAL;
	fscanf(archivo_camino, LECTURA_ETIQUETA, nivel);
	fscanf(archivo_camino, LECTURA_ETIQUETA, camino);
	leidos = fscanf(archivo_camino, LECTURA_CAMINOS, &(caminos->camino_2_lvl_2[tope].fil), &(caminos->camino_2_lvl_2[tope].col));
	while (leidos == LEIDOS_CAMINOS){
		tope++;
		leidos = fscanf(archivo_camino, LECTURA_CAMINOS, &(caminos->camino_2_lvl_2[tope].fil), &(caminos->camino_2_lvl_2[tope].col));
	}
	caminos->tope_camino_2_lvl_2 = tope;
	tope = CONTADOR_INICIAL;
	fscanf(archivo_camino, LECTURA_ETIQUETA, nivel);
	fscanf(archivo_camino, LECTURA_ETIQUETA, camino);
	leidos = fscanf(archivo_camino, LECTURA_CAMINOS, &(caminos->camino_1_lvl_3[tope].fil), &(caminos->camino_1_lvl_3[tope].col));
	while (leidos == LEIDOS_CAMINOS){
		tope++;
		leidos = fscanf(archivo_camino, LECTURA_CAMINOS, &(caminos->camino_1_lvl_3[tope].fil), &(caminos->camino_1_lvl_3[tope].col));
	}
	caminos->tope_camino_1_lvl_3 = tope;
	tope = CONTADOR_INICIAL;
	fscanf(archivo_camino, LECTURA_ETIQUETA, camino);
	leidos = fscanf(archivo_camino, LECTURA_CAMINOS, &(caminos->camino_2_lvl_3[tope].fil), &(caminos->camino_2_lvl_3[tope].col));
	while (leidos == LEIDOS_CAMINOS){
		tope++;
		leidos = fscanf(archivo_camino, LECTURA_CAMINOS, &(caminos->camino_2_lvl_3[tope].fil), &(caminos->camino_2_lvl_3[tope].col));
	}
	caminos->tope_camino_2_lvl_3 = tope;
	tope = CONTADOR_INICIAL;
	fscanf(archivo_camino, LECTURA_ETIQUETA, nivel);
	fscanf(archivo_camino, LECTURA_ETIQUETA, camino);
	leidos = fscanf(archivo_camino, LECTURA_CAMINOS, &(caminos->camino_1_lvl_4[tope].fil), &(caminos->camino_1_lvl_4[tope].col));
	while (leidos == LEIDOS_CAMINOS){
		tope++;
		leidos = fscanf(archivo_camino, LECTURA_CAMINOS, &(caminos->camino_1_lvl_4[tope].fil), &(caminos->camino_1_lvl_4[tope].col));
	}
	caminos->tope_camino_1_lvl_4 = tope;
	tope = CONTADOR_INICIAL;
	fscanf(archivo_camino, LECTURA_ETIQUETA, camino);
	leidos = fscanf(archivo_camino, LECTURA_CAMINOS, &(caminos->camino_2_lvl_4[tope].fil), &(caminos->camino_2_lvl_4[tope].col));
	while (leidos == LEIDOS_CAMINOS){
		tope++;
		leidos = fscanf(archivo_camino, LECTURA_CAMINOS, &(caminos->camino_2_lvl_4[tope].fil), &(caminos->camino_2_lvl_4[tope].col));
	}
	caminos->tope_camino_2_lvl_4 = tope;
	fclose(archivo_camino);
}
/*
PRE: se tuvo que hacer ingresado el comando JUGAR, junto con la etiqueta CONFIG=
	y el archivo ingresado debe existir.
POST: extrae los datos del archivo de configuracion al struct configuracion.
*/
void extraer_datos(char archivo[MAX_LETRAS], configuracion_t* configuracion){
	char etiqueta[MAX_LETRAS];
	FILE * archivo_config = fopen(archivo, LECTURA);
	if(!archivo_config){
		printf("no se pudo abrir eñ archivo %s para extraer archivos\n", archivo);
	}
	int leidos = fscanf(archivo_config, "%[^ ]", etiqueta);
	while(leidos == 1){
		if(strcmp(etiqueta, "RESISTENCIA_TORRES=") == COINCIDEN){
			fscanf(archivo_config, " %i,%i\n", &(configuracion->torres.torre_uno), &(configuracion->torres.torre_dos));
		}else if(strcmp(etiqueta, "ENANOS_INICIO=") == COINCIDEN){
			fscanf(archivo_config, " %i,%i,%i,%i\n", &(configuracion->cant_enanos[0]), &(configuracion->cant_enanos[1]), &(configuracion->cant_enanos[2]), &(configuracion->cant_enanos[3]));
		}else if(strcmp(etiqueta, "ELFOS_INICIO=") == COINCIDEN){
			fscanf(archivo_config, " %i,%i,%i,%i\n", &(configuracion->cant_elfos[0]), &(configuracion->cant_elfos[1]), &(configuracion->cant_elfos[2]), &(configuracion->cant_elfos[3]));
		}else if(strcmp(etiqueta, "ENANOS_EXTRAS=") == COINCIDEN){
			fscanf(archivo_config, " %i,%i,%i\n", &(configuracion->enanos_extras.cant_extra), &(configuracion->enanos_extras.costo_torre_1), &(configuracion->enanos_extras.costo_torre_2));
		}else if(strcmp(etiqueta, "ELFOS_EXTRAS=") == COINCIDEN){
			fscanf(archivo_config, " %i,%i,%i\n", &(configuracion->elfos_extras.cant_extra), &(configuracion->elfos_extras.costo_torre_1), &(configuracion->elfos_extras.costo_torre_2));
		}else if(strcmp(etiqueta, "ANIMO_ENANOS=") == COINCIDEN){
			fscanf(archivo_config, " %i,%i\n", &(configuracion->animo_enanos.fallo), &(configuracion->animo_enanos.critico));
		}else if(strcmp(etiqueta, "ANIMO_ELFOS=") == COINCIDEN){
			fscanf(archivo_config, " %i,%i\n", &(configuracion->animo_elfos.fallo), &(configuracion->animo_elfos.critico));
		}else if(strcmp(etiqueta, "VELOCIDAD=") == COINCIDEN){
			fscanf(archivo_config, " %f\n", &(configuracion->velocidad_juego));
		}else if(strcmp(etiqueta, "CAMINOS=") == COINCIDEN){
			fscanf(archivo_config, " %s\n", configuracion->caminos.archivo);
			if(strcmp(configuracion->caminos.archivo, CAMINO_DEFEC) != COINCIDEN){
				copiar_caminos(&(configuracion->caminos));
			}
		}
		leidos = fscanf(archivo_config, "%[^ ]", etiqueta);
	}	
	fclose(archivo_config);
	configuracion->configuracion_defecto = false;
}
/*
POST: calcula la cantidad de enanos iniciales por nivel.
*/
int calcular_enanos_inicio(configuracion_t configuracion){
	int enanos_inicio;
	if(configuracion.cant_enanos[0] != CONFIG_DEFECTO){
		enanos_inicio = configuracion.cant_enanos[0];
	}else enanos_inicio = ENANOS_INICIO_LVL1;
	if(configuracion.cant_enanos[1] != CONFIG_DEFECTO){
		enanos_inicio += configuracion.cant_enanos[1];
	}
	if(configuracion.cant_enanos[2] != CONFIG_DEFECTO){
		enanos_inicio += configuracion.cant_enanos[2];
	}else enanos_inicio += ENANOS_INICIO_LVL3;
	if(configuracion.cant_enanos[3] != CONFIG_DEFECTO){
		enanos_inicio += configuracion.cant_enanos[3];
	}else enanos_inicio += ENANOS_INICIO_LVL4;
	return enanos_inicio;
}
/*
POST: calcula la cantidad de elfos iniciales por nivel.
*/
int calcular_elfos_inicio(configuracion_t configuracion){
	int elfos_inicio;
	if(configuracion.cant_elfos[0] != CONFIG_DEFECTO){
		elfos_inicio = configuracion.cant_elfos[0];
	}
	if(configuracion.cant_elfos[1] != CONFIG_DEFECTO){
	elfos_inicio += configuracion.cant_elfos[1];
	}else elfos_inicio = ELFOS_INICIO_LVL2;
	if(configuracion.cant_elfos[2] != CONFIG_DEFECTO){
		elfos_inicio += configuracion.cant_elfos[2];
	}else elfos_inicio += ELFOS_INICIO_LVL3;
	if(configuracion.cant_elfos[3] != CONFIG_DEFECTO){
		elfos_inicio += configuracion.cant_elfos[3];
	}else elfos_inicio += ELFOS_INICIO_LVL4;
	return elfos_inicio;
}
/*
PRE: se tuvo que haber jugado al juego con anterioridad y haberlo finalizado.
POST: calcula el puntaje del jugador dependiendo de la configuracion usada.
*/
int calcular_puntaje(int orcos_muertos, juego_t juego, configuracion_t configuracion){
	int vida_torre_1;
	int vida_torre_2;
	int enanos_inicio;
	int elfos_inicio;
	int enanos_extras;
	int elfos_extras;
	int puntaje_final;
	if(configuracion.configuracion_defecto){
		vida_torre_1 = VIDA_MAX_TORRES;
		vida_torre_2 = VIDA_MAX_TORRES;
		enanos_inicio = (ENANOS_INICIO_LVL1 + ENANOS_INICIO_LVL3 + ENANOS_INICIO_LVL4);
		elfos_inicio = ( ELFOS_INICIO_LVL2 + ELFOS_INICIO_LVL3 + ELFOS_INICIO_LVL4);
		enanos_extras = DEFENSORES_EXTRA;
		elfos_extras = DEFENSORES_EXTRA;
		puntaje_final = ((orcos_muertos * 1000) / (vida_torre_1 + vida_torre_2 + enanos_inicio + elfos_inicio + enanos_extras + elfos_extras));
	}else{
		vida_torre_1 = configuracion.torres.torre_uno;
		vida_torre_2 = configuracion.torres.torre_dos;
		enanos_inicio = calcular_enanos_inicio(configuracion);
		elfos_inicio = calcular_elfos_inicio(configuracion);
		enanos_extras = configuracion.enanos_extras.cant_extra;
		elfos_extras = configuracion.elfos_extras.cant_extra;
		puntaje_final = ((orcos_muertos * 1000) / (vida_torre_1 + vida_torre_2 + enanos_inicio + elfos_inicio + enanos_extras + elfos_extras));
	}
	return puntaje_final;
}
/*
PRE: se tuvo que haber jugado al juego con anterioridad y haberlo finalizado.
POST: ingresa el nombre del usuario y su puntaje al ranking, dependiendo de su 
	configuracion, en caso de no existir el rankin, crea uno nuevo.
*/
void ingresar_ranking(int puntaje, char usuario[MAX_LETRAS], char archivo[MAX_LETRAS], configuracion_t configuracion){
	char nombre_ranking[MAX_LETRAS];
	char usuario_ranking[MAX_LETRAS];
	int puntaje_ranking;
	int puntaje_usuario = puntaje;
	if(configuracion.configuracion_defecto){
		strcpy(nombre_ranking, NOMBRE_RANK_DEFECTO);
	}else{
		char vector_aux[MAX_LETRAS];
		strcpy(vector_aux, CABECERA_RANK);
		strcat(vector_aux, archivo);
		size_t tope = strlen(vector_aux);
		strncpy(nombre_ranking, vector_aux, tope - 4);
		strcat(nombre_ranking, EXTENCION_CSV);
		printf("el archivo de ranking es: %s\n", nombre_ranking);
	}
	FILE * ranking = fopen(nombre_ranking, LECTURA);
	if(!ranking){
		FILE * nuevo_ranking = fopen(nombre_ranking, ESCRITURA);
		if(!nuevo_ranking){
			printf("no se pudo abrir el archivo %s \n", nombre_ranking);
			return;
		}
		fprintf(nuevo_ranking, ESCRITURA_RANKING, usuario, puntaje);
		fclose(nuevo_ranking);
		return;
	}else{
		FILE * ranking_aux = fopen(RANKING_AUX, ESCRITURA);
		if(!ranking_aux){
			printf("no se pudo abrir el ranking_aux\n");
			fclose(ranking);
		}
		int leidos =fscanf(ranking, LECTURA_RANKING, usuario_ranking, &puntaje_ranking);
		while(leidos == LEIDOS_RANK){
			if(puntaje_ranking < puntaje_usuario){
				fprintf(ranking_aux, ESCRITURA_RANKING, usuario, puntaje_usuario);
				strcpy(usuario, usuario_ranking);
				puntaje_usuario = puntaje_ranking;
			}else if(puntaje_ranking > puntaje_usuario){
				fprintf(ranking_aux, ESCRITURA_RANKING, usuario_ranking, puntaje_ranking);
			}else{
				if(strcmp(usuario, usuario_ranking) < COINCIDEN){
					fprintf(ranking_aux, ESCRITURA_RANKING, usuario, puntaje_usuario);
					strcpy(usuario, usuario_ranking);
					puntaje_usuario = puntaje_ranking;
				}else if(strcmp(usuario, usuario_ranking) > COINCIDEN){
					fprintf(ranking_aux, ESCRITURA_RANKING, usuario_ranking, puntaje_ranking);
				}else{
					fprintf(ranking_aux, ESCRITURA_RANKING, usuario, puntaje_usuario);
					strcpy(usuario, usuario_ranking);
					puntaje_usuario = puntaje_ranking;
				}
			}
			leidos =fscanf(ranking, LECTURA_RANKING, usuario_ranking, &puntaje_ranking);
		}
		fprintf(ranking_aux, ESCRITURA_RANKING, usuario, puntaje_usuario);
		fclose(ranking_aux);
	}
	fclose(ranking);
	rename(RANKING_AUX,nombre_ranking);
}
/*
PRE: se tuvo que haber jugado al juego con anterioridad y haberlo finalizado.
POST: ingresa el nombre del usuario y su puntaje al ranking, dependiendo de su 
	configuracion, en caso de no existir el rankin, crea uno nuevo.
*/
void calcular_ranking(int orcos_muertos, juego_t juego, char usuario[MAX_LETRAS], char archivo[MAX_LETRAS], configuracion_t configuracion){
	int puntaje = calcular_puntaje(orcos_muertos, juego, configuracion);
	ingresar_ranking(puntaje, usuario, archivo, configuracion);
}
/*
PRE: se tuvo que haber ingresado el comando JUGAR
POST: se juega el juego y se graba si se ingreso la etiqueta GRABACION=
*/
void comandos_jugar(char comandos_jugador[MAX_CANT_COMANDOS][MAX_LETRAS], int argc, char archivos[MAX_CANT_ARCHIVOS][MAX_LETRAS], configuracion_t configuracion){
	int orden;
	int viento;
	int humedad;
	char animo_legolas;
	char animo_gimli;
	juego_t juego;
	int preguntar_defensor_extra = PREG_LVL_BAJOS;
	bool grabar = false;
	orden = comprobar_comandos(comandos_jugador, argc, archivos);
	if(orden == EXISTE_AMBOS || orden == EXISTE_CONFIG){
		if(leer_archivo(archivos[0])){
			extraer_datos(archivos[0], &configuracion);
		}else configuracion.configuracion_defecto = true;
	} else configuracion.configuracion_defecto = true;
	if(orden == EXISTE_AMBOS || orden == EXISTE_GRAB){
		grabar = true;
	}
	jugar_normal(&viento, &humedad, &animo_legolas, &animo_gimli, &juego, &preguntar_defensor_extra, configuracion, grabar, archivos);
}
/*
PRE: se tuvo que ingresar la etiqueta GRABACION=.
POST: graba el juego actual.
*/
void iniciar_repeticion(char archivo[MAX_LETRAS], float velocidad){
	juego_t juego_repe;
	FILE * archivo_repe = fopen(archivo, LECTURA);
	if(!archivo_repe){
		printf("ERROR..\n");
		printf("No existe el archivo %s \n", archivo);
		return;
	}
	fread(&juego_repe, sizeof(juego_t), 1, archivo_repe);
	while(!feof(archivo_repe)){
		system("clear");
		mostrar_juego(juego_repe);
		detener_el_tiempo(velocidad);
		fread(&juego_repe, sizeof(juego_t), 1, archivo_repe);
	}
	fclose(archivo_repe);
}
/*
POST: retorna true si el comando ingresado coincide con la etiqueta "VELOCIDAD=", 
	caso contrario, retorna false.
*/
bool es_etiqueta_velocidad(char comandos_jugador[MAX_CANT_COMANDOS][MAX_LETRAS], int argc, int* posicion){
	int i = CONTADOR_INICIAL;
	bool encontro = false;
	while((i < argc) && (!encontro)){
		if(strncmp(comandos_jugador[i], ETIQUETA_VELOCIDAD, LARGO_ETIQ_VEL) == COINCIDEN){
			encontro = true;
			*posicion = i;
		}
		i++;
	}
	return encontro;
}
/*
PRE: se tuvo que ingresar el comando PONEME_LA_REPE.
POST: graba el juego actual.
*/
void comandos_repeticion(char comandos_jugador[MAX_CANT_COMANDOS][MAX_LETRAS], char archivos[MAX_CANT_ARCHIVOS][MAX_LETRAS], int argc){
	int pos_grabacion = NO_EXISTE;
	int pos_velocidad = NO_EXISTE;
	float velocidad = F_NO_EXISTE;
	if(es_etiqueta_grabacion(comandos_jugador, argc, &pos_grabacion)){
		copiar_archivo(comandos_jugador[pos_grabacion], archivos[0]);
		if(es_etiqueta_velocidad(comandos_jugador, argc, &pos_velocidad)){
			copiar_archivo(comandos_jugador[pos_velocidad], archivos[1]);
			velocidad = (float) atof(archivos[1]);
			iniciar_repeticion(archivos[0], velocidad);
		}else iniciar_repeticion(archivos[0], 1);
	}else{
		printf("ERROR\n");
		printf("no se ingreso la etiqueta 'grabacion='\n");
	}
}