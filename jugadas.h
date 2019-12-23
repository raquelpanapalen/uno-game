#ifndef JUGADAS_H
#define JUGADAS_H
#define MJUGADAS 108
#define TRUE 1
#define FALSE 0

typedef struct
{
   int njugadas;//guarda el número de jugadas posibles de la mano del jugador.
   tjugada jugs[MJUGADAS];//guarda las jugadas posibles del jugador en un vector de tjugada.
}tjugadas;

void mostrar_jugadas(tjugadas pj);
void calcular_jugadas_posibles(tjugadas *pj,int color,tcartas mano, tcarta um);
int hay_jugadas(tcartas mano, tcarta um, int color);
tcarta elegir_jugada(int tipo_jug, tjugadas pjugs);
int hay_color(int color, tcartas mano);


#endif
