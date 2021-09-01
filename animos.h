#ifndef __ANIMOS_H__
#define __ANIMOS_H__
#include <stdio.h>
#include <stdbool.h>

/*pre-condiciones: numeros positivos y letras mayusculas
pre_condiciones: numeros dentro del rango valido
pre-condiciones: letras que coincidan con los parametros dados
post-condiciones: devolvera el estado de animo, humedad y viento*/
void animos (int *viento, int *humedad, char *animo_legolas, char *animo_gimli);
#endif /*__ANIMOS_H__*/