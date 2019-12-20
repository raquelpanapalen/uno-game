// Este fichero se le da al alumno
#ifndef PREGUNTAS_H
#define PREGUNTAS_H
#define MAX_CAD	80
#define MN 20
#define NUM_COLORES 4



int fuera_de_rango(int n, int min, int max);
int preguntar_n_en_rango(char s[MAX_CAD], int min, int max);
int preguntar_si_o_no(char s[MAX_CAD]);
void preguntar_cadena(char msg[MAX_CAD], char cad[MN]);
int preguntar_color();
void esperar();


#endif // PREGUNTAS_H

