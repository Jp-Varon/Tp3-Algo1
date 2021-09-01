#include "comandos.h"
#define VERDE_CLARO "\033[0m\033[32m"
#define VERDE_OSCURO "\033[1m\033[32m"
#define AMARILLO "\033[1m\033[33m"
#define PLATA "\033[0m\033[37m"
#define MARRON "\033[0m\033[33m"
#define ROJO "\033[0m\033[31m"
#define AZUL "\033[1m\033[34m"
#define FIN "\033[0m"


const static int MAX_TABLERO_CHICO = 15;
const static int MAX_TABLERO_GRANDE = 20;
const static int VIDA_MAX_TORRES = 600;
const static int DEFENSORES_EXTRA = 10;
const static int CRITICO_NULO = 0;
const static int CRITICO_MEDIO = 10;
const static int CRITICO_MAX = 25; 
const static int PRIMER_NIVEL = 1;
const static int SEGUNDO_NIVEL = 2;
const static int TERCER_NIVEL = 3;
const static int CUARTO_NIVEL = 4;
const static int DEFENSORES_INICIALES = 5;
const static int ATAQUE_ENANO = 60;
const static int ATAQUE_ELFO = 30;
const static int MAX_ENEMIGOS_LVL_1 = 100;
const static int DISTORCION_TABLERO = 10;
const static int MUERTE_DE_ORCO = 0;
const static int TORRE_DESTRUIDA = 0;
const static int VICTORIA = 1;
const static int DERROTA = -1;
const static int INCONCLUSO = 0;
const static int ALCANCE_ENANOS = 1;
const static int ALCANCE_ELFOS = 3;
const static int POSICION_INCIAL = 0;
const static int CRITICO_ENANOS = 100;
const static int CRITICO_ELFOS = 70;
const static int PRIMER_CAMINO = 1;
const static int SEGUNDO_CAMINO = 2;
const static int VIDA_MIN_ORCO = 200;
const static int ERROR = -1;
const static int EXITO = 0;
const static int CONTADOR_INICIAL = 0;
const static char ANIMO_MALO = 'M';
const static char ANIMO_REGULAR = 'R';
const static char ENANOS = 'G';
const static char ELFOS = 'L';
const static char PASTO = '-';
const static char CAMINO = 'c';
const static char ENTRADA = 'E';
const static char TORRE = 'T';
const static char ORCOS = 'O';


void inicializar_juego(juego_t* juego, int viento, int humedad, char animo_legolas, char animo_gimli, configuracion_t configuracion){

	if(configuracion.configuracion_defecto){
		juego->torres.resistencia_torre_1 = VIDA_MAX_TORRES;
		juego->torres.resistencia_torre_2 = VIDA_MAX_TORRES;
		juego->torres.enanos_extra = DEFENSORES_EXTRA;
		juego->torres.elfos_extra = DEFENSORES_EXTRA;
		juego->fallo_legolas = viento / 2;
		juego->fallo_gimli = humedad / 2;  
	
		if (animo_legolas == ANIMO_MALO){
			juego->critico_legolas = CRITICO_NULO;		
		}else if (animo_legolas == ANIMO_REGULAR){
			juego->critico_legolas = CRITICO_MEDIO;
		} else juego->critico_legolas = CRITICO_MAX;

		if (animo_gimli == ANIMO_MALO){
			juego->critico_gimli = CRITICO_NULO;	
		} else if (animo_gimli == ANIMO_REGULAR){
			juego->critico_gimli = CRITICO_MEDIO;
		} else juego->critico_gimli = CRITICO_MAX;

		juego->nivel.tope_defensores = DEFENSORES_INICIALES;
		for (int i = 0; i < juego->nivel.tope_defensores; ++i){
			juego->nivel.defensores[i].tipo = ENANOS;
		}
	}else{
		if(configuracion.torres.torre_uno != -1){
			juego->torres.resistencia_torre_1 = configuracion.torres.torre_uno;
		}else juego->torres.resistencia_torre_1 = VIDA_MAX_TORRES;

		if(configuracion.torres.torre_dos != -1){
			juego->torres.resistencia_torre_2 = configuracion.torres.torre_dos;
		}else juego->torres.resistencia_torre_2 = VIDA_MAX_TORRES;

		if(configuracion.enanos_extras.cant_extra != -1){
			juego->torres.enanos_extra = configuracion.enanos_extras.cant_extra;
		}else juego->torres.enanos_extra = DEFENSORES_EXTRA;

		if(configuracion.elfos_extras.cant_extra != -1){
			juego->torres.elfos_extra = configuracion.elfos_extras.cant_extra;
		}else juego->torres.elfos_extra = DEFENSORES_EXTRA;

		if(configuracion.animo_enanos.fallo != -1){
			juego->fallo_gimli = configuracion.animo_enanos.fallo;
		}else juego->fallo_gimli = humedad / 2;

		if(configuracion.animo_elfos.fallo != -1){
			juego->fallo_legolas = configuracion.animo_elfos.fallo;
		}else juego->fallo_legolas = viento / 2;

		if(configuracion.animo_enanos.critico != -1){
			juego->critico_gimli = configuracion.animo_enanos.critico;
		}else{
			if (animo_gimli == ANIMO_MALO){
				juego->critico_gimli = CRITICO_NULO;	
			} else if (animo_gimli == ANIMO_REGULAR){
				juego->critico_gimli = CRITICO_MEDIO;
			} else juego->critico_gimli = CRITICO_MAX;
		}

		if(configuracion.animo_elfos.critico != -1){
			juego->critico_legolas = configuracion.animo_elfos.critico;
		}else{
			if (animo_legolas == ANIMO_MALO){
				juego->critico_legolas = CRITICO_NULO;		
			}else if (animo_legolas == ANIMO_REGULAR){
				juego->critico_legolas = CRITICO_MEDIO;
			} else juego->critico_legolas = CRITICO_MAX;
		}
		if(configuracion.cant_enanos[0] != -1){
			juego->nivel.tope_defensores = configuracion.cant_enanos[0];
			for (int i = 0; i < juego->nivel.tope_defensores; ++i){
				juego->nivel.defensores[i].tipo = ENANOS;
			}
		}else {
			juego->nivel.tope_defensores = DEFENSORES_INICIALES;
			for (int i = 0; i < juego->nivel.tope_defensores; ++i){
				juego->nivel.defensores[i].tipo = ENANOS;
			}
		}
		if(configuracion.cant_elfos[0] != -1){
			juego->nivel.tope_defensores += configuracion.cant_elfos[0];
			for (int i = configuracion.cant_enanos[0]; i < juego->nivel.tope_defensores; ++i){
				juego->nivel.defensores[i].tipo = ELFOS;
			}
		}
	}
	juego->nivel_actual = PRIMER_NIVEL;
	juego->nivel.tope_defensores = CONTADOR_INICIAL;
	juego->nivel.tope_camino_2 = CONTADOR_INICIAL;
	juego->nivel.max_enemigos_nivel = MAX_ENEMIGOS_LVL_1;
	juego->nivel.tope_enemigos = CONTADOR_INICIAL;		
}
/*
POST: rellena el tablero en su totalidad de pasto
*/
void poner_pasto(char tablero[MAX_FILAS][MAX_COLUMNAS], int nivel_actual){
		
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
PRE: el vector camino_1 y/o camino_2 debe estar rellenado con coordenadas logicas.
POST: inserta en el tablero el/los caminos.

*/

void poner_camino(char tablero[MAX_FILAS][MAX_COLUMNAS], juego_t juego){

	for (int i = 0; i < juego.nivel.tope_camino_1; ++i){
		tablero[juego.nivel.camino_1[i].fil][juego.nivel.camino_1[i].col] = CAMINO;
	}
	for (int i = 0; i < juego.nivel.tope_camino_2; ++i){
		tablero[juego.nivel.camino_2[i].fil][juego.nivel.camino_2[i].col] = CAMINO; 
	}	
}
/*
POST: imprime por pantalla el tablero del juego.
*/
void mostrar_tablero(juego_t juego, char tablero[MAX_FILAS][MAX_COLUMNAS]){

	if(juego.nivel_actual == PRIMER_NIVEL || juego.nivel_actual == SEGUNDO_NIVEL){	
		for (int i = 0; i < DISTORCION_TABLERO; ++i){
			printf("%i   ", i);
		}
		for (int i = DISTORCION_TABLERO; i < MAX_TABLERO_CHICO; ++i){
			printf("%i  ", i);
		}printf("\n");

		for (int i = 0; i < MAX_TABLERO_CHICO; ++i){
			for (int j = 0; j < MAX_TABLERO_CHICO; ++j){
				if(tablero[i][j] == PASTO){
					printf(VERDE_CLARO"%c   "FIN, tablero[i][j]);
				}else if(tablero[i][j] == CAMINO){
					printf(AMARILLO"%c   "FIN, tablero[i][j]);
				}else if(tablero[i][j] == ORCOS){
					printf(ROJO"%c   "FIN, tablero[i][j]);
				}else if(tablero[i][j] == ENANOS){
					printf(MARRON"%c   "FIN, tablero[i][j]);
				}else if(tablero[i][j] == ELFOS){
					printf(PLATA"%c   "FIN, tablero[i][j]);
				}else if((tablero[i][j] == ENTRADA) ||(tablero[i][j] == TORRE)){
					printf(AZUL "%c   "FIN, tablero[i][j]);
				}

			}printf("%i \n", i);
		}
	}
	if (juego.nivel_actual == TERCER_NIVEL || juego.nivel_actual == CUARTO_NIVEL){
		for (int i = 0; i < DISTORCION_TABLERO; ++i){
			printf("%i   ", i);
		}
		for (int i = DISTORCION_TABLERO; i < MAX_TABLERO_GRANDE; ++i){
			printf("%i  ", i);
		}printf("\n");

		for (int i = 0; i < MAX_TABLERO_GRANDE; ++i){
			for (int j = 0; j < MAX_TABLERO_GRANDE; ++j){
				if(tablero[i][j] == PASTO){
					printf(VERDE_CLARO"%c   "FIN, tablero[i][j]);
				}else if(tablero[i][j] == CAMINO){
					printf(AMARILLO"%c   "FIN, tablero[i][j]);
				}else if(tablero[i][j] == ORCOS){
					printf(ROJO"%c   "FIN, tablero[i][j]);
				}else if(tablero[i][j] == ENANOS){
					printf(MARRON"%c   "FIN, tablero[i][j]);
				}else if(tablero[i][j] == ELFOS){
					printf(PLATA"%c   "FIN, tablero[i][j]);
				}else if((tablero[i][j] == ENTRADA) ||(tablero[i][j] == TORRE)){
					printf(AZUL "%c   "FIN, tablero[i][j]);
				}
			}printf("%i \n", i);
		}
	}
}
/*
PRE: el nivel debe ser 1 o 2 
POST: define el tablero en el cual se basa el nivel, junto con la torres y el camino.
*/

void obtener_tablero_chico(char tablero[MAX_FILAS][MAX_COLUMNAS], juego_t juego){
	
	if (juego.nivel_actual == PRIMER_NIVEL){
		poner_pasto(tablero, juego.nivel_actual);
		poner_camino(tablero, juego);
		tablero[juego.nivel.camino_1[0].fil][juego.nivel.camino_1[0].col] = ENTRADA;
		tablero[juego.nivel.camino_1[juego.nivel.tope_camino_1 - 1].fil][juego.nivel.camino_1[juego.nivel.tope_camino_1 - 1].col] = TORRE;		
		mostrar_tablero(juego, tablero);
	}
	if (juego.nivel_actual == SEGUNDO_NIVEL){
		poner_pasto(tablero, juego.nivel_actual);
		poner_camino(tablero, juego);
		tablero[juego.nivel.camino_2[0].fil][juego.nivel.camino_2[0].col] = ENTRADA;
		tablero[juego.nivel.camino_2[juego.nivel.tope_camino_2 - 1].fil][juego.nivel.camino_2[juego.nivel.tope_camino_2 - 1].col] = TORRE; 
		mostrar_tablero(juego, tablero);
	}
}
/*
PRE: el nivel debe ser 3 o 4.
POST: define el tablero donde se basa el nivel, junto con las torres y los caminos
*/
void obtener_tablero_grande(char tablero[MAX_FILAS][MAX_COLUMNAS], juego_t juego){

	if (juego.nivel_actual == TERCER_NIVEL){
		poner_pasto(tablero, juego.nivel_actual);
		poner_camino(tablero, juego);
		tablero[juego.nivel.camino_1[0].fil][juego.nivel.camino_1[0].col] = ENTRADA;
		tablero[juego.nivel.camino_2[0].fil][juego.nivel.camino_2[0].col] = ENTRADA;
		tablero[juego.nivel.camino_1[juego.nivel.tope_camino_1 - 1].fil][juego.nivel.camino_1[juego.nivel.tope_camino_1 - 1].col] = TORRE;
		tablero[juego.nivel.camino_2[juego.nivel.tope_camino_2 - 1].fil][juego.nivel.camino_2[juego.nivel.tope_camino_2 - 1].col] = TORRE;
		mostrar_tablero(juego, tablero);
	}

	if (juego.nivel_actual == CUARTO_NIVEL){
		poner_pasto(tablero, juego.nivel_actual);
		poner_camino(tablero, juego);
		tablero[juego.nivel.camino_1[0].fil][juego.nivel.camino_1[0].col] = ENTRADA;
		tablero[juego.nivel.camino_2[0].fil][juego.nivel.camino_2[0].col] = ENTRADA;
		tablero[juego.nivel.camino_1[juego.nivel.tope_camino_1 - 1].fil][juego.nivel.camino_1[juego.nivel.tope_camino_1 - 1].col] = TORRE;
		tablero[juego.nivel.camino_2[juego.nivel.tope_camino_2 - 1].fil][juego.nivel.camino_2[juego.nivel.tope_camino_2 - 1].col] = TORRE;
		mostrar_tablero(juego, tablero);
	}
}
/*
PRE: debe estar definido el tablero, junto con el camino. ademas el vector enemigos debe
	estar relllenado con datos validos.
POST: incluira en el tablero los orcos que esten vivos.
*/
void caminar_orcos ( char tablero[MAX_FILAS][MAX_COLUMNAS], juego_t juego){
	
	if(juego.nivel.tope_camino_1 != 0){	
		for (int i = 0; i < juego.nivel.tope_enemigos; ++i){
			if (juego.nivel.enemigos[i].vida > MUERTE_DE_ORCO && juego.nivel.enemigos[i].camino == PRIMER_CAMINO){
				system("clear");
				tablero[juego.nivel.camino_1[juego.nivel.enemigos[i].pos_en_camino].fil][juego.nivel.camino_1[juego.nivel.enemigos[i].pos_en_camino].col] = ORCOS;
				mostrar_tablero(juego, tablero); 
			}
		}
	}
	if(juego.nivel.tope_camino_2 != 0){
		for (int i = 0; i < juego.nivel.tope_enemigos; ++i){
			if (juego.nivel.enemigos[i].vida > MUERTE_DE_ORCO && juego.nivel.enemigos[i].camino == SEGUNDO_CAMINO){
				system("clear");			
				tablero[juego.nivel.camino_2[juego.nivel.enemigos[i].pos_en_camino].fil][juego.nivel.camino_2[juego.nivel.enemigos[i].pos_en_camino].col] = ORCOS;
				mostrar_tablero(juego, tablero);
			}
		}
	}	
}
void mostrar_juego(juego_t juego){
	char tablero[MAX_FILAS][MAX_COLUMNAS];

	if((juego.nivel_actual == PRIMER_NIVEL) || (juego.nivel_actual == SEGUNDO_NIVEL)){
		obtener_tablero_chico(tablero, juego);
	}
	if(juego.nivel_actual == TERCER_NIVEL || juego.nivel_actual == CUARTO_NIVEL){
		obtener_tablero_grande(tablero, juego);
	}
	for (int i = 0; i < juego.nivel.tope_defensores; ++i){
		tablero[juego.nivel.defensores[i].posicion.fil][juego.nivel.defensores[i].posicion.col] = juego.nivel.defensores[i].tipo;
	}
	caminar_orcos(tablero, juego);
	printf("la vida de las torres 1 es: %i y de la torres 2 es :%i\n", juego.torres.resistencia_torre_1, juego.torres.resistencia_torre_2);
	printf("la cantidad de elfos extras son: %i y la de enanos es: %i\n", juego.torres.elfos_extra, juego.torres.enanos_extra);
	printf("el fallo de los elfos es de %i por ciento y el de los enanos es %i por ciento \n",juego.fallo_legolas, juego.fallo_gimli);
	printf("el critico de los elfos es del %i por ciento y el de los enanos es de %i por ciento\n", juego.critico_legolas, juego.critico_gimli);
	printf("la cantidad de orcos a vencer: %i \n", juego.nivel.max_enemigos_nivel);
}
int estado_juego(juego_t juego){
	int contador = CONTADOR_INICIAL;
 	for (int i = 0; i < juego.nivel.tope_enemigos; ++i){
 		if (juego.nivel.enemigos[i].vida <= MUERTE_DE_ORCO){
 			contador++;
 		}
 	}

	if (juego.nivel_actual == CUARTO_NIVEL && contador == juego.nivel.max_enemigos_nivel && juego.torres.resistencia_torre_1 > TORRE_DESTRUIDA && juego.torres.resistencia_torre_2 > TORRE_DESTRUIDA){
		return VICTORIA;
	} else if(juego.torres.resistencia_torre_1 <= TORRE_DESTRUIDA || juego.torres.resistencia_torre_2 <= TORRE_DESTRUIDA){
		return DERROTA;
	} else return INCONCLUSO;
}			


int estado_nivel(nivel_t nivel){
	int contador = CONTADOR_INICIAL;
 	for (int i = 0; i < nivel.tope_enemigos; ++i){
 		if (nivel.enemigos[i].vida <= MUERTE_DE_ORCO){
 			contador++;
 		}
 	}
 	if (contador == nivel.max_enemigos_nivel){
 		return VICTORIA;
 	}else return INCONCLUSO;
}
/*
POST: devolvera true si es que el orco esta dentro del rango del enano, caso contrario, 
	devolvera false.
*/
bool esta_en_rango_enano (int fila_enano, int columna_enano, int fila_orco, int columna_orco){
	int resultado_fila;
	int resultado_columna;
	resultado_fila = (fila_enano - fila_orco);
	resultado_columna = (columna_enano - columna_orco);
	
	if((abs(resultado_fila) <= ALCANCE_ENANOS) && (abs(resultado_columna) <= ALCANCE_ENANOS)){
		return true;
	} else return false;
}
/*
POST: devolvera true si es que orco esta dentro del rango del elfo, caso contrario, 
	devolvera false. 
*/
bool esta_en_rango_elfo ( int fila_elfo, int columna_elfo, int fila_orco, int columna_orco){
	int resultado_fila;
	int resultado_columna;
	int resultado_final;
	resultado_fila = abs(fila_elfo - fila_orco);
	resultado_columna = abs(columna_elfo - columna_orco);
	resultado_final = (resultado_fila + resultado_columna);

	if (resultado_final <= ALCANCE_ELFOS){
		return true;
	} else return false;
}
/*
PRE: el vector defensores debe estar rellenado con datos validos.
POST: cada orco que este en rango de un defensor y sea golpeado, se le reducira la vida
*/
void atacan_defensores (juego_t *juego){
	int fila_defensor_actual;
	int columna_defensor_actual;
	int fila_camino;
	int columna_camino;
	int pos_orco_actual;
	int posibilidad_fallo;
	int posibilidad_critico;
	bool defensor_ataco [MAX_DEFENSORES];

	for (int i = 0; i < juego->nivel.tope_defensores; ++i){
		defensor_ataco[i] = false;
	}

	if(juego->nivel.tope_camino_1 != CONTADOR_INICIAL){
		for (int i = 0; i < juego->nivel.tope_defensores; ++i){	
			for (int j = 0; j < juego->nivel.tope_enemigos; ++j){
				if (juego->nivel.defensores[i].tipo == ENANOS && juego->nivel.enemigos[j].pos_en_camino >= POSICION_INCIAL && juego->nivel.enemigos[j].camino == PRIMER_CAMINO){
					fila_defensor_actual = juego->nivel.defensores[i].posicion.fil;
					columna_defensor_actual = juego->nivel.defensores[i].posicion.col;
					pos_orco_actual = juego->nivel.enemigos[j].pos_en_camino;
					fila_camino = juego->nivel.camino_1[pos_orco_actual].fil;
					columna_camino = juego->nivel.camino_1[pos_orco_actual].col;
					if (esta_en_rango_enano (fila_defensor_actual, columna_defensor_actual, fila_camino, columna_camino) == true && defensor_ataco[i] == false && juego->nivel.enemigos[j].vida > MUERTE_DE_ORCO){
						posibilidad_fallo = rand () % 100 + 1;
						defensor_ataco[i] = true;
						if (posibilidad_fallo > juego->fallo_gimli){
							posibilidad_critico = rand () % 100 + 1;
							if (posibilidad_critico <  juego->critico_gimli){
								juego->nivel.enemigos[j].vida -= CRITICO_ENANOS;
							} else juego->nivel.enemigos[j].vida -= juego->nivel.defensores[i].fuerza_ataque;
						}
					}
				}
				if (juego->nivel.defensores[i].tipo == ELFOS && juego->nivel.enemigos[j].pos_en_camino >= POSICION_INCIAL && juego->nivel.enemigos[j].camino == PRIMER_CAMINO){
					fila_defensor_actual = juego->nivel.defensores[i].posicion.fil;
					columna_defensor_actual = juego->nivel.defensores[i].posicion.col;
					pos_orco_actual = juego->nivel.enemigos[j].pos_en_camino;
					fila_camino = juego->nivel.camino_1[pos_orco_actual].fil;
					columna_camino = juego->nivel.camino_1[pos_orco_actual].col;
					if (esta_en_rango_elfo (fila_defensor_actual, columna_defensor_actual, fila_camino, columna_camino) == true  && juego->nivel.enemigos[j].vida > MUERTE_DE_ORCO){
						posibilidad_fallo = rand () % 100 + 1;
						if (posibilidad_fallo > juego->fallo_legolas){
							posibilidad_critico = rand () % 100 + 1;
							if (posibilidad_critico <  juego->critico_legolas){
								juego->nivel.enemigos[j].vida -= CRITICO_ELFOS;
							} else juego->nivel.enemigos[j].vida -= juego->nivel.defensores[i].fuerza_ataque;
						}
					}	
				}
			}
		}
	}
	if(juego->nivel.tope_camino_2 != CONTADOR_INICIAL){
		for (int i = 0; i < juego->nivel.tope_defensores; ++i){	
			for (int j = 0; j < juego->nivel.tope_enemigos; ++j){
				if (juego->nivel.defensores[i].tipo == ENANOS && juego->nivel.enemigos[j].pos_en_camino >= POSICION_INCIAL && juego->nivel.enemigos[j].camino == SEGUNDO_CAMINO){
					fila_defensor_actual = juego->nivel.defensores[i].posicion.fil;
					columna_defensor_actual = juego->nivel.defensores[i].posicion.col;
					pos_orco_actual = juego->nivel.enemigos[j].pos_en_camino;
					fila_camino = juego->nivel.camino_2[pos_orco_actual].fil;
					columna_camino = juego->nivel.camino_2[pos_orco_actual].col;
					if (esta_en_rango_enano (fila_defensor_actual, columna_defensor_actual, fila_camino, columna_camino) == true && defensor_ataco[i] == false && juego->nivel.enemigos[j].vida > MUERTE_DE_ORCO){
						posibilidad_fallo = rand () % 100 + 1;
						defensor_ataco[i] = true;
						if (posibilidad_fallo > juego->fallo_gimli){
							posibilidad_critico = rand () % 100 + 1;
							if (posibilidad_critico <  juego->critico_gimli){
								juego->nivel.enemigos[j].vida -= CRITICO_ENANOS;
							} else juego->nivel.enemigos[j].vida -= juego->nivel.defensores[i].fuerza_ataque;
						}
					}
				}
				if (juego->nivel.defensores[i].tipo == ELFOS && juego->nivel.enemigos[j].pos_en_camino >= POSICION_INCIAL && juego->nivel.enemigos[j].camino == SEGUNDO_CAMINO){
					fila_defensor_actual = juego->nivel.defensores[i].posicion.fil;
					columna_defensor_actual = juego->nivel.defensores[i].posicion.col;
					pos_orco_actual = juego->nivel.enemigos[j].pos_en_camino;
					fila_camino = juego->nivel.camino_2[pos_orco_actual].fil;
					columna_camino = juego->nivel.camino_2[pos_orco_actual].col;
					if (esta_en_rango_elfo (fila_defensor_actual, columna_defensor_actual, fila_camino, columna_camino) == true  && juego->nivel.enemigos[j].vida > MUERTE_DE_ORCO){
						posibilidad_fallo = rand () % 100 + 1;
						if (posibilidad_fallo > juego->fallo_legolas){
							posibilidad_critico = rand () % 100 + 1;
							if (posibilidad_critico <  juego->critico_legolas){
								juego->nivel.enemigos[j].vida -= CRITICO_ELFOS;
							} else juego->nivel.enemigos[j].vida -= juego->nivel.defensores[i].fuerza_ataque;
						}
					}	
				}
			}
		}
	}
}
/*
POST: cada orco que este vivo, se movera un lugar hacia adelante en el camino.

*/
void mover_orcos (juego_t *juego){
	int numero_aleatorio;
	for (int i = 0; i < juego->nivel.tope_enemigos; ++i){
		if(juego->nivel.tope_camino_1 != 0){
			if ((juego->nivel.enemigos[i].pos_en_camino >= POSICION_INCIAL) && (juego->nivel.enemigos[i].vida > MUERTE_DE_ORCO) && (juego->nivel.enemigos[i].camino == PRIMER_CAMINO)) {
				juego->nivel.enemigos[i].pos_en_camino += 1;			
			}
			
			if ((juego->nivel.enemigos[i].pos_en_camino == juego->nivel.tope_camino_1 - 1) &&(juego->nivel.enemigos[i].camino == PRIMER_CAMINO)){
				juego->torres.resistencia_torre_1 -= juego->nivel.enemigos[i].vida;
				juego->nivel.enemigos[i].vida = MUERTE_DE_ORCO;	
			}
		}
		if(juego->nivel.tope_camino_2 != 0){
			if ((juego->nivel.enemigos[i].pos_en_camino >= POSICION_INCIAL) && (juego->nivel.enemigos[i].vida > MUERTE_DE_ORCO) && (juego->nivel.enemigos[i].camino == SEGUNDO_CAMINO)) {
				juego->nivel.enemigos[i].pos_en_camino += 1;			
			}
			
			if ((juego->nivel.enemigos[i].pos_en_camino == juego->nivel.tope_camino_2 - 1) &&(juego->nivel.enemigos[i].camino == SEGUNDO_CAMINO)){
				juego->torres.resistencia_torre_2 -= juego->nivel.enemigos[i].vida;
				juego->nivel.enemigos[i].vida = MUERTE_DE_ORCO;	
			}

		}
	}
		
	if (juego->nivel.tope_enemigos < juego->nivel.max_enemigos_nivel && juego->nivel.tope_camino_1 != 0){
		juego->nivel.enemigos[juego->nivel.tope_enemigos].pos_en_camino = POSICION_INCIAL;
		numero_aleatorio = rand () % 100;
		juego->nivel.enemigos[juego->nivel.tope_enemigos].vida = VIDA_MIN_ORCO + numero_aleatorio;
		juego->nivel.enemigos[juego->nivel.tope_enemigos].camino = PRIMER_CAMINO;
		juego->nivel.tope_enemigos += 1;	
	}	

	if (juego->nivel.tope_enemigos < juego->nivel.max_enemigos_nivel && juego->nivel.tope_camino_2 != 0){
		juego->nivel.enemigos[juego->nivel.tope_enemigos].pos_en_camino = POSICION_INCIAL;
		numero_aleatorio = rand () % 100;
		juego->nivel.enemigos[juego->nivel.tope_enemigos].vida = VIDA_MIN_ORCO + numero_aleatorio;
		juego->nivel.enemigos[juego->nivel.tope_enemigos].camino = SEGUNDO_CAMINO;
		juego->nivel.tope_enemigos += 1;
	}	
}

void jugar_turno(juego_t* juego){
	atacan_defensores (&(*juego));
	mover_orcos (&(*juego));
}
/*
POST: devolvera true si es que las coordenadas no pertenecen a una parte del camino o a otro 
	defensor, caso contrario, devolvera false.
*/
bool coordenada_valida (nivel_t nivel, coordenada_t posicion){
	int error = CONTADOR_INICIAL;
	int i = 0;
	while((error == CONTADOR_INICIAL) && (i < nivel.tope_camino_1)){
		if((posicion.fil == nivel.camino_1[i].fil) && (posicion.col == nivel.camino_1[i].col)){
			error++;
		}
		i++;
	}
	i = 0;
	while((error == CONTADOR_INICIAL) && (i < nivel.tope_camino_2)){
		if((posicion.fil == nivel.camino_2[i].fil) && (posicion.col == nivel.camino_2[i].col)){
			error++;
		}
		i++;
	}
	i = 0;
	while((error == CONTADOR_INICIAL) && (i < nivel.tope_defensores)){
		if((posicion.fil == nivel.defensores[i].posicion.fil) && (posicion.col == nivel.defensores[i].posicion.col)){
			error++;
		}
		i++;
	}
	if (error != CONTADOR_INICIAL){
		return false;
	}	
return true;
}	
int agregar_defensor(nivel_t* nivel, coordenada_t posicion, char tipo){
	int defensor_nuevo;
	defensor_nuevo = nivel->tope_defensores;
	if (coordenada_valida(*nivel, posicion) == false){
		return ERROR;
	}else{
		nivel->defensores[defensor_nuevo].posicion.fil = posicion.fil;
		nivel->defensores[defensor_nuevo].posicion.col = posicion.col;
		nivel->defensores[defensor_nuevo].tipo = tipo;
		if(tipo == ENANOS){
			nivel->defensores[defensor_nuevo].fuerza_ataque = ATAQUE_ENANO;
		}else{
			nivel->defensores[defensor_nuevo].fuerza_ataque = ATAQUE_ELFO;
		}
	}
nivel->tope_defensores += 1;
return EXITO;
}
