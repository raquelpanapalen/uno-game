// Este fichero se le da al alumno
#ifndef PREGUNTAS_H
#define PREGUNTAS_H

#include <stdio.h>

#define MAX_CAD	80
#define NUM_COLORES 4



int fuera_de_rango(int n, int min, int max);
int preguntar_n_en_rango(char *s, int min, int max);
int preguntar_si_o_no(char *s);
void preguntar_cadena(char *msg, char *cad);
int preguntar_color();
void esperar();


#endif // PREGUNTAS_H

