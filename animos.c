#include "animos.h"
static const char MANIANA = 'M';
static const char TARDE = 'T';
static const char NOCHE = 'N';
static const char IZQUIERDA = 'I';
static const char DERECHA ='D';
static const char ENSALADA = 'E';
static const char HAMBURGUESA = 'H';
static const char PIZZA = 'P';
static const char GUISO = 'G';
static const char ANIMO_MALO = 'M';
static const char ANIMO_REGULAR = 'R';
static const char ANIMO_BUENO = 'B';
static const int DIA_MIN = 1;
static const int DIA_MAX = 30;
static const int DIA_CAM_VIENTO_MAX = 11;
static const int DIA_CAM_VIENTO_MED = 21;
static const int SUENIO_MIN = 0;
static const int SUENIO_MAX = 12;
static const int HORA_CAM_SUENIO_MIN = 5;
static const int HORA_CAM_SUENIO_MED = 8;
static const int VIENTO_MAX = 75;
static const int VIENTO_MED = 50;
static const int VIENTO_MIN = 25;
static const int HUMADAD_MAX = 75;
static const int HUMEDAD_MED = 50;
static const int HUMEDAD_MIN = 25;
static const int PUNTOS_PIE_DER = 10;
static const int PUNTOS_ENSALADA = 20;
static const int PUNTOS_HAMBURGUESA = 15;
static const int PUNTOS_PIZZA = 10;
static const int PUNTOS_GUISO = 5;
static const int PUNTOS_SUENIO_MED = 10;
static const int PUNTOS_SUENIO_MAX = 20;
static const int CONTADOR_INICIAL = 0;
static const int PUNTOS_MIN_ANIMO = 5;
static const int PUNTOS_CAM_ANIMO_MALO = 21;
static const int PUNTOS_CAM_ANIMO_REG = 35;


/*post-condicion: devolvera true si el dia esta dentro del rango de dias validos
post-condicion: devolvera false si el dia no esta dentro del rango de dias validos*/
bool dia_valido (int dia_del_mes){
return (dia_del_mes >= DIA_MIN && dia_del_mes <= DIA_MAX);
}
/*post-condicion: salen numeros positivos
post-condicion: los numeros estan entre el rango valido*/
void preguntar_dia (int *dia_del_mes){
	printf("¿Que dia es hoy? (ingresar entre %i / %i)\n", DIA_MIN, DIA_MAX);
	scanf("%i", dia_del_mes);
	while (dia_valido (*dia_del_mes) == false){
		printf("numero ingresado no valido, por favor, ingresar que dia es hoy:\n");
		scanf(" %i", dia_del_mes);
	}
}

/*post-condicion: devolvera true si la hora coincide con los parametros dados
post-condicion: devolvera false si la hora no coincide con los parametros dados*/
bool hora_valida (char hora){
	return (hora == MANIANA || hora == TARDE || hora == NOCHE);
}
/*post-condicion: devolvera letras mayusculas
post-condicion: devolvera letras que coinciden con los parametros dados*/
void preguntar_hora (char *hora){
	printf("¿Que hora es? ('%c' para mañana, '%c' para tarde o '%c' para noche)\n", MANIANA, TARDE, NOCHE);
	scanf(" %c", hora);
	while (hora_valida (*hora) == false){
		printf("hora no valida, por favor, ingresar que hora es:\n");
		scanf(" %c", hora);
	}
}
/*post-condicion: imprime una frase*/
void presentar_legolas (){
	printf("comencemos con legolas!!\n");
}

/*post-condicion: imprime una frase*/
void presentar_gimli (){
	printf("Ahora vamos con Gimli!!\n");
}
/*post-condicion: devolvera true si las letras coinciden con los parametros dados
post-condicion: devolvera false si las letras no coinciden con los parametros dados*/
bool pie_valido (char pie){
	return (pie == IZQUIERDA || pie == DERECHA);
}
/*post-condicion: devolvera una letra mayuscula
post-condicion: la letra coincide con alguno de los parametros dados*/
void preguntar_pie (char *pie){
	printf("¿Con que pie se levanto? ('%c' para izquierda o '%c' para derecha) \n", IZQUIERDA, DERECHA);
	scanf(" %c", pie);
	while (pie_valido (*pie) == false){
		printf("pie no valido, por favor, ingresar pie: \n");
		scanf(" %c", pie);
	}
}
/*post-condicion: devolvera true si la letra coincide con los parametros dados
post-condicion: devolvera false si la letra no coincide con los parametros dados*/
bool cena_valida (char cena){
	return (cena == ENSALADA || cena == HAMBURGUESA || cena == PIZZA || cena == GUISO);
}
/*post-condicion: devolvera letra muyuscula 
post-condicion: la letra coincide con alguno de los parametros dados*/
void preguntar_cena (char *cena){
	printf("¿Que ceno anoche? ('%c' para ensalada, '%c' para HAMBURGUESA, '%c' para pizza o '%c' para guiso)\n", ENSALADA, HAMBURGUESA, PIZZA, GUISO);
	scanf(" %c", cena);
	while (cena_valida (*cena) == false){
		printf("cena no valida, por favor, ingresar que ceno anoche: \n");
		scanf(" %c", cena);
	}
}
/*post-condicion: devolvera true si el dia esta dentro del rango de horas validas
post-condicion: devolvera false si el dia no esta dentro del rango de horas validos*/
bool horas_validas (int suenio){
	return (suenio >= SUENIO_MIN && suenio <= SUENIO_MAX);
}
/*post-condicion: devolvera numero positivo
post-condicion: devolvera numero dentro del rango de horas validas*/
void cantidad_horas_de_suenio (int *suenio){
	printf("¿Cuantas horas durmio ayer? (entre %i y %i)\n", SUENIO_MIN, SUENIO_MAX);
	scanf(" %i", suenio);
	while (horas_validas (*suenio) == false){
		printf("horas de sueños no validas, por favor, ingresar cuantas horas durmio anoche:\n");
		scanf(" %i", suenio);
	}
}
/*post-condiciones: devolvera letras mayusculas y numeros positivos
post-condiciones: devolvera letras y numeros dentro del rango valido y/o que coinciden con los
parametros dados */
void preguntas_para_legolas (char *pie_legolas, char *cena_legolas, int *suenio_legolas){
	preguntar_pie (pie_legolas);
	preguntar_cena (cena_legolas);
	cantidad_horas_de_suenio (suenio_legolas);
}
/*post-condiciones: devolvera letras mayusculas y numeros positivos
post-condiciones: devolvera letras y numeros dentro del rango valido y/o que coinciden con los
parametros dados */
void preguntas_para_gimli (char *pie_gimli, char *cena_gimli, int *suenio_gimli){
	preguntar_pie (pie_gimli);
	preguntar_cena (cena_gimli);
	cantidad_horas_de_suenio (suenio_gimli);
}
/*pre-condiciones: numero positivo y dentro del rango valido
post-condiciones: devolvera la velocidad del viento*/
int viento_segun_dia_del_mes (int dia_del_mes){
	int viento = CONTADOR_INICIAL;
	if (dia_del_mes < DIA_CAM_VIENTO_MAX && dia_del_mes >= DIA_MIN){
		viento = VIENTO_MAX;
	} else if (dia_del_mes < DIA_CAM_VIENTO_MED && dia_del_mes >= DIA_CAM_VIENTO_MAX){
		viento = VIENTO_MED;
	} else viento = VIENTO_MIN;
return viento;
}
/*pre-condiciones: letra mayuscula y que coincida con los parametros dados
post-condiciones: devolvera la humedad presente*/
int humedad_segun_hora (char hora){
	int humedad = CONTADOR_INICIAL;
	if (hora == MANIANA){
		humedad = HUMADAD_MAX;
	} else if (hora == TARDE){
		humedad = HUMEDAD_MIN;
	} else humedad = HUMEDAD_MED;
return humedad;
}
/*pre-condiciones: numeros positivos y letras mayusculas
pre-condiciones: los numeros deben estar dentro del rango valido
pre-condiciones: las letras deben coincidir con los parametros dados
post-condiciones: devolvera los puntos de animo*/
void calcular_puntos_animo (int *puntos, char pie, char cena, int suenio){
	if (pie == DERECHA){
		*puntos = *puntos + PUNTOS_PIE_DER;
	} else *puntos = *puntos;
	if (cena == ENSALADA){
		*puntos = *puntos + PUNTOS_ENSALADA;
	} else if (cena == HAMBURGUESA){
		*puntos = *puntos + PUNTOS_HAMBURGUESA;
	}else if (cena == PIZZA){
		*puntos = *puntos + PUNTOS_PIZZA;
	} else *puntos = *puntos + PUNTOS_GUISO;
	if (suenio >= SUENIO_MIN && suenio < HORA_CAM_SUENIO_MIN){
		*puntos = *puntos;
	} else if (suenio >= HORA_CAM_SUENIO_MIN && suenio <= HORA_CAM_SUENIO_MED){
		*puntos = *puntos + PUNTOS_SUENIO_MED;
	} else *puntos = *puntos + PUNTOS_SUENIO_MAX;
}
/*pre-condiciones: numemos positivos y dentro del rango valido de puntos
post-condiciones: devolvera los puntos de animo*/
void calcular_animo (char *animo,int puntos){
	if (puntos < PUNTOS_CAM_ANIMO_MALO && puntos >= PUNTOS_MIN_ANIMO){
		*animo = ANIMO_MALO;
	} else if (puntos <= PUNTOS_CAM_ANIMO_REG && puntos >= PUNTOS_CAM_ANIMO_MALO){
		*animo = ANIMO_REGULAR;
	} else *animo = ANIMO_BUENO;
}

void resumen (int viento, int humedad, char animo_legolas, char animo_gimli){
	if (viento == VIENTO_MIN){
		printf("Poco viento, incapaz de volarle el peluquin a alguien, ");
	} else if (viento == VIENTO_MED){
		printf("Viento moderado, abrigate bro, que hace frio, ");
	} else printf("Mucho viento, mete la ropa del tender que se va a volar, ");

	if (humedad == HUMEDAD_MIN){
		printf("humedad baja, ");
	} else if (humedad == HUMEDAD_MED){
		printf("humedad media, ");
	} else printf("humedad alta, ");

	if (animo_legolas == ANIMO_MALO){
		printf("Legolas habra pisado una makumba porque no es un buen dia, ");
	} else if (animo_legolas == ANIMO_REGULAR){
		printf("Legolas no tiene un buen dia pero safa, ");
	} else printf("los dioses del olimpo se sonrien a Legolas porque tiene un buen dia, ");

	if (animo_gimli == ANIMO_MALO){
		printf("Gimli habra pisado una makumba porque no es un buen dia. \n");
	} else if (animo_gimli == ANIMO_REGULAR){
		printf("Gimli no tiene un buen dia pero safa. \n");
	} else printf("los dioses del olimpo se sonrien a Gimli porque tiene un buen dia. \n");
}





void animos (int *viento, int *humedad, char *animo_legolas, char *animo_gimli){

	int dia_del_mes;
	char hora;
	char pie_legolas, pie_gimli;
	char cena_legolas, cena_gimli;
	int suenio_legolas, suenio_gimli;
	int puntos_legolas = CONTADOR_INICIAL, puntos_gimli = CONTADOR_INICIAL;
	char animo_legolas_calculado, animo_gimli_calculado;
	
	

	preguntar_dia (&dia_del_mes);
	preguntar_hora (&hora);
	presentar_legolas ();
	preguntas_para_legolas (&pie_legolas, &cena_legolas, &suenio_legolas);
	presentar_gimli ();
	preguntas_para_gimli (&pie_gimli, &cena_gimli, &suenio_gimli);
	int viento_calculado = viento_segun_dia_del_mes (dia_del_mes);
	int humedad_calculada = humedad_segun_hora (hora);
	calcular_puntos_animo (&puntos_legolas, pie_legolas, cena_legolas, suenio_legolas);
	calcular_puntos_animo (&puntos_gimli, pie_gimli, cena_gimli, suenio_gimli);
	calcular_animo (&animo_legolas_calculado, puntos_legolas);
	calcular_animo (&animo_gimli_calculado, puntos_gimli);
	resumen (viento_calculado, humedad_calculada, animo_legolas_calculado, animo_gimli_calculado);

	*viento = viento_calculado;
	*humedad = humedad_calculada;
	*animo_legolas = animo_legolas_calculado;
	*animo_gimli = animo_gimli_calculado;
	
}